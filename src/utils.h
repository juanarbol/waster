#ifndef UTILS_H
#define UTILS_H

#include "uv.h"
#include "quickjs.h"

struct WasteRuntime {
  JSRuntime* rt;
  JSContext* ctx;
  uv_loop_t* loop;
  uv_tcp_t*  server;
};

typedef struct WasteRuntime WasteRuntime;

#endif
