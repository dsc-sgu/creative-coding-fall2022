cmake_minimum_required(VERSION 3.0)
project(glad LANGUAGES C)
add_library (glad src/glad-part.c)
target_include_directories (glad PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_link_libraries (glad PUBLIC raylib-ext)

