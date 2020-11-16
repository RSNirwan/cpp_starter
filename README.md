# C++ starter

[![Build Status macOS](https://github.com/rsnirwan/cpp_starter/workflows/build_macOS/badge.svg)](https://github.com/rsnirwan/cpp_starter/actions)
[![Build Status ubuntu](https://github.com/rsnirwan/cpp_starter/workflows/build_ubuntu/badge.svg)](https://github.com/rsnirwan/cpp_starter/actions)

### Table of Contents
* [Getting started](#getting-started) 
* [Structure of CMakeLists.txt](#structure-of-cmakelists.txt)

___

A starter for writing a module in C++ and testing with googletest. Github actions are used to build and test the module on every push and pull request. We use cmake to generate the makefiles.

The repository includes a module (`src/module1.h, src/module1.cpp`) that is being tested with googletest (linked as submodule in `lib/googletest`). Tests are in `tests/Module1Tests.cpp`. The `src` directory also contains a `main.cpp` file that is being build. The `src/main.cpp` file can be removed if only a library is build and tested. When deleting `src/main.cpp` make sure to also delete the corresponding lines in `src/CMakeLists.txt` as well.


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

After cloning we can generate the makefiles with cmake. Therefore, we make a build directory and run cmake in that folder. Make sure you are in the root folder (cpp_starter).
```shell
mkdir build
cd build 
cmake ..
```

Know we can use `make` to build executables and link the libraries. In `build` folder we do
```shell
make
```
The two steps above are similar to `mkdir build; cmake -S . -B build; cmake --build build`. 

The executables are in the build folder and have the same structer as the root folder. 
the main-executable is in `build/src/main` and the test-executable is in `build/tests/m1test`. We can execute them form the root folder by
```shell
cd ..
build/src/main
build/tests/m1test
```
The names `main` and `m1test` are set in the `CMakeLists.txt`-files. How that works is explained in the next section.


___
## Structure of CMakeLists.txt

The basic setup is defined in the top level [CMakeLists.txt](CMakeLists.txt).
It defines the minimum required version of cmake,
sets the name of the project and the c++ standard to c++17. Because we want to test the library we are building we enable testing with `enable_testing` (later tests are added with `add_test`). At the end we include all subdirectories with the code we want to use. Those are the gtest framework in `lib/googletest`, our library code in `src` and the tests we want to run in `tests`. 
All these subdirectories have their own CMakeLists.txt files that are run sequentially in the order they are included in the top level CMakelists.txt.
This is important since we will set variables in one file that are used in subsequent files.

The first subdirectory we add is googletest. By adding that subdirectory the `lib/googletest/CMakeLists.txt` is called. Here, a library called `gtest_main` is build that we link later in the test cmake-file to our test-executable.

The second subdirectory we add is `src`. This directory contains the library we are building and want to test. It also contains a cmake-file [src/CMakeLists.txt](src/CMakeLists.txt). The `set` command define two variablels `Headers` and `Sources`. We can put more files in their if we want. The important command in this file is the `add_library`. That line is responsable for building our library. The first argument is the name (in our case `m1`), which we use to link the library to an executable. To support relative include path we use `target_include_directories`. Executables using the library can now use it by `#include<Module1.h>`.
The first executable build in the process is from the `src/main.cpp` file. The command `add_executable` is responsable for building the executable that we name `main`. `target_link_libraries` links the `m1` library to the `main` executable, which will be located at `build/src/main`.

The final subdirectory we add in the top level cmake-file is `tests`. In `tests` we have another [tests/CMakeLists.txt](tests/CMakeLists.txt). Here we define a variable called `Projname` refering to the string `m1test`. We do that, because we need the name on several places. The tests are an executable that is linked to gtest (called `gtest_main`) and our library (called `m1`).
To do that, we first build the executable with `add_executable` and use `target_link_libraries` to link the executable with libraries. The last line (`add_test`) adds tests. We can run the tests using `make test` or `ctest`. The test-executable is located in `build/tests/m1test`. We can also call the executable directly to run the tests.