# GlTutorial - OpenGL C++ tutorial

## Features:

* Logging with spdlog

## How to build project

### Using Visual Studio Code

Open the project folder in Visual Studio Code, install the recommended extensions, open the command palette and type "CMake: Build".

### From terminal

```bash
cd /path/to/tutorial
mkdir build
cmake -B "build" -S . -G "preferred generator, I recommend Ninja"
cmake --build "build"
```

## Project structure

* .vscode/ - recommended extensions for Visual Studio Code
* docs/ - documentation generated with doxygen
* * src/ - Doxyfile and resources for html
* deps/ - project dependencies
* * glad/ - OpenGL loader (loader bundled with glfw is slightly outdated)
* * glfw/ - handles user input and windowing
* * spdlog/ - logging library
* src/ - tutorial source code
* * samples/ - executable code
* * lib/ - renderer code
