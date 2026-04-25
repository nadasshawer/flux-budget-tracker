# Bridging

## Challenges

### 1. Refactoring the code

- After creating the basic structure of my backened logic in C++ and my classes, I found out that I need to "re-structure" my
  code to make it bridge-ready
- Currently, my classes use `std::string` and internal validation
- To make them work with a Node.js server, I need to add a **wrapper**
- I figured out that I don't need to change my class logic, but I need to create a "public entrance" (the `extern "C"` part) that the web server can call

#### Why `extern "C"`?

- C++ "mangles" function names to support features like overloading
- A web server looking for `addExpense` won't find it if the compiler renamed it to something like`_Z10addExpensePKci`
- `extern "C"` transforms our C++ (which JS doesn't understand) into C code (which JS understands)
- It tells the compiler: "keep the name simple so the outside world can find it"

#### Why `const char*`?

- Web browsers and servers speak in simple character arrays, this is because C is the universal language of systems
- They don't know what a C++ `std::string` object is
- We accept a `const char*` at the door, then immediately turn it into a `std::string` once we're safely inside the C++ logic

## Strategy

- To allow these 2 languages (JS & C++) to talk to each other, I created bridging files inside the `native/bridge` directory
- These files are **wrapper** files
  - They include the existing files (headers)
  - They sit "on top" of the existing code
  - They translate the web browser's language (e.g. `char*`) into the C++ language (e.g. `std::string`)
- **All functions** should be wrapped in `extern "C"` even if no internal conversion happens
  - This is because the web browser still can't see "inside" my C++ files to find these function
  - I still need to build the "door" (`extern "C"`), but these functions just walk straight through it without conversion

#### How it works?

- The existing files (classes.cpp, validation.cpp, etc..) are the _engine_ under the hood
  - They do the heavy lifting
- The bridging files (ending with `_bridge.cpp`) are the dashboard
  - They _don't replace the engine_
  - They just give the driver (the web browser) a _way to talk_ to the engine
