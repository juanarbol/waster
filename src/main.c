#include <stdlib.h>

#include "quickjs.h"
#include "uv.h"
#include "utils.h"
#include "tcp-server.h"

int main(int argc, char** argv) {
  WasteRuntime* wrt = calloc(1, sizeof(*wrt));
  // Create QuickJS runtime and context, and event loop
  wrt->rt = JS_NewRuntime();
  wrt->ctx = JS_NewContext(wrt->rt);
  wrt->loop = uv_default_loop();

  // We need that for later
  JS_SetRuntimeOpaque(wrt->rt, wrt);
  JS_SetContextOpaque(wrt->ctx, wrt);

  // Run the TCP server
  start_server(wrt);

  return uv_run(wrt->loop, UV_RUN_DEFAULT);
}
