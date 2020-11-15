# C++ starter

[![Build Status macOS](https://github.com/rsnirwan/cpp_starter/workflows/build_macOS/badge.svg)](https://github.com/rsnirwan/cpp_starter/actions)
[![Build Status ubuntu](https://github.com/rsnirwan/cpp_starter/workflows/build_ubuntu/badge.svg)](https://github.com/rsnirwan/cpp_starter/actions)

### Table of Contents
* [Getting started](#getting-started) 
* [Structure of CMakeLists.txt](#structure-of-cmakelists.txt)

___

A starter for writing a module in C++ and testing it with googletest. Github actions are used to build and test the module on every push and pull request. We use cmake to generate the makefiles.

The repository includes a module (`src/module1.h, src/module1.cpp`) that is being tested with googletest (linked as submodule in `lib/googletest`). Tests are in `tests/Module1Tests.cpp`. The `src` directory also contains a `main.cpp` file that is being build. The `src/main.cpp` file can be removed if only a library is build and tested. When deleting `src/main.cpp` make sure to also delete the corresponding lines in `src/CMakeLists.txt`.


___
## Getting started

Clone the repository including googletest submodule with `--recurse-submodules` flag. googletest is included as a submodule because its not directly a part of the module/library we are writing.
```shell
git clone --recurse-submodules https://github.com/RSNirwan/cpp_starter.git
```
alternatively do
```shell
git clone https://github.com/RSNirwan/cpp_starter.git
cd cpp_starter
git submodule init
git submodule update
```

After cloning we can gernate the makefiles with cmake. Therefore we make a build directory and run cmake in that folder. Make sure you are in the root folder (cpp_starter).
```shell
mkdir build
cd build 
cmake ..
```

Know we can use `make` to build executables and link the libraries. In `build` folder we do
```shell
make
```
The two stepts above are similar to `mkdir build; cmake -S . -B build; cmake --build build`. 

The executables are in build folder and have the same structer as the root folder. 
the main-executable is in `build/src/main` and the test-executable is in `build/tests/m1test`. We can execute them form the root folder by
```shell
cd ..
build/src/main
build/tests/m1test
```
The names `main` and `m1test` are set in the `CMakeLists.txt`-files. How that works is explained in the next section.


___
## Structure of CMakeLists.txt

@todo
