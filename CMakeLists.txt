cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
project(GlTutorial LANGUAGES C CXX VERSION 0.0.2 DESCRIPTION "OpenGL tutorial")

option(TUTORIAL_GENERATE_DOCS "Generate documentation from comments" ON)

add_subdirectory(deps)
add_subdirectory(src)
add_subdirectory(docs)