cmake_minimum_required(VERSION 3.0)
project (raylib-ext)
set (CMAKE_CXX_STANDARD 17)

add_library (raylib-ext STATIC src/raylib-ext.cpp)
target_include_directories (raylib-ext PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries (raylib-ext LINK_PUBLIC raylib)
target_link_libraries (raylib-ext LINK_PUBLIC raygui)

