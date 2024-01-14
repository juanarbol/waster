#include <stdlib.h>
#include <string.h>
#include "tcp-server.h"
#include "quickjs.h"
#include "tcp-server.h"
#include "utils.h"
#include "uv.h"

// I hate this, very much
static uv_tcp_t server;

// JavaScript object with a "write" method
JSValue jsWriteFunction(JSContext *ctx, JSValue this_val, int argc, JSValueConst *argv) {
  uv_stream_t* client = (uv_stream_t*)JS_GetOpaque(this_val, 1);
  // Check if the argument is a string
  if (JS_IsString(argv[0])) {
    const char* message = JS_ToCString(ctx, argv[0]);
    const char* response = "HTTP/1.1 200 OK\r\n"
                          "Content-Type: text/plain\r\n"
                          "Content-Length: 11\r\n"
                          "\r\n"
                          "Hola mundo\n";
    uv_buf_t buf = uv_buf_init((char *)response, strlen(response));
    uv_write_t* write_req = (uv_write_t *)malloc(sizeof(uv_write_t));

    // Assuming you have a uv_write function, replace it with the appropriate call
    uv_write(write_req, client, &buf, 1, NULL);
  }

  return JS_UNDEFINED;
}

void uv__alloc_buffer(uv_handle_t* handle, size_t suggested_size, uv_buf_t* buf) {
  buf->base = malloc(suggested_size);
  buf->len = suggested_size;
}

void echo_write(uv_write_t* req, int status) {
  // Nothing but free
  if (status) {
    return;
  }
  free(req);
}

void uv__on_read(uv_stream_t* client, ssize_t nread, const uv_buf_t* buf) {
  if (nread > 0) {
    // Assuming you have the QuickJS runtime and context initialized
    WasteRuntime* wrt = client->data;

    JSValue global = JS_GetGlobalObject(wrt->ctx);
    JSValue jsObject = JS_NewObject(wrt->ctx);

    // Add the "write" method to the object
    JS_SetPropertyStr(wrt->ctx, jsObject, "write", JS_NewCFunction(wrt->ctx, jsWriteFunction, "write", 1));

    // Set the object as a property of the global object
    JS_SetPropertyStr(wrt->ctx, global, "Response", jsObject);
 
    // Hide the client for later write
    JS_SetOpaque(jsObject, client);

    // Write to stream by eval the script
    const char* script = "Response.write(\"Hola desde JS\");";
    JSValue result = JS_Eval(wrt->ctx, script, strlen(script), "<script>", JS_EVAL_TYPE_GLOBAL);
    // Handle the result as needed
    if (JS_IsException(result)) {
      JSValue exception = JS_GetException(wrt->ctx);
      JSValue stack_trace = JS_GetPropertyStr(wrt->ctx, exception, "message");
      const char *stack_trace_str = JS_ToCString(wrt->ctx, stack_trace);
      fprintf(stderr, "Exception: %s\n", stack_trace_str);
      JS_FreeCString(wrt->ctx, stack_trace_str);
      JS_FreeValue(wrt->ctx, stack_trace);
      JS_FreeValue(wrt->ctx, exception);
    }

    JS_FreeValue(wrt->ctx, result);
    JS_FreeValue(wrt->ctx, jsObject);
    JS_FreeValue(wrt->ctx, global);

    // TODO(juan): Parse HTTP request
    // The buffer is the actual request made by user
    char* request = buf->base;
    fprintf(stdout, "Request: \n%s", request);
  }

  uv_close((uv_handle_t *)client, NULL);
  // TODO(@juan): this may has resource leaking, please clean everything before exiting
  exit(0);
}

void uv__on_connection(uv_stream_t* server, int status) {
  if (status < 0) {
    return;
  }

  // Create the stream for the client
  // CREATE A JS LAND OBJECT WIT THE WRITE CALLBACK ASSOCIATED
  uv_tcp_t* client = malloc(sizeof(uv_tcp_t));
  client->data = server->data;
  uv_tcp_init(server->loop, client);
  if (uv_accept(server, (uv_stream_t*)client) == 0) {
    uv_read_start((uv_stream_t*)client, uv__alloc_buffer, uv__on_read);
  } else {
    uv_close((uv_handle_t*)client, NULL);
  }
}

int start_server(WasteRuntime* wrt) {
  struct sockaddr_in addr;
  const uint32_t PORT = 3000;

  int r = uv_ip4_addr("0.0.0.0", PORT, &addr);
  if (r) {
    fprintf(stderr, "uv_ip4_addr error %s\n", uv_strerror(r));
    return r;
  }

  r = uv_tcp_init(wrt->loop, &server);
  if (r) {
    fprintf(stderr, "uv_tcp_init error %s\n", uv_strerror(r));
    return r;
  }

  // We are gonna need this for later
  server.data = wrt;

  r = uv_tcp_bind(&server, (const struct sockaddr*)&addr, 0);
  if (r) {
    fprintf(stderr, "uv_tcp_bind error %s\n", uv_strerror(r));
    return r;
  }

  r = uv_listen((uv_stream_t*)&server, SOMAXCONN, uv__on_connection);
  if (r) {
    fprintf(stderr, "uv_listen error %s\n", uv_strerror(r));
    return r;
  }

  printf("Listening on port %d\n", PORT);

  if (r) {
    printf("Run error %s\n", uv_strerror(r));
    return r;
  }

  return r;
}
