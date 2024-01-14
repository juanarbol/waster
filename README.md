# Waster

This is my own "_whatever_ Functions" implementation.

_What a waste of time, but amazing pet project_

## Build

__Note:__ For now, just tested in macOS Ventura

Instructions for compile and run

```sh
mkdir -p build
cd build
cmake ..
# For debug mode
# cmake -DCMAKE_BUILD_TYPE=Debug ..
cmake --build . -j32
./waster
```
Doing the request with curl:

`curl localhost:3000`

### Note:

This has a resource leak, I'm not releasing everything of libuv nor QuickJS resources,
this is purely experimental.
