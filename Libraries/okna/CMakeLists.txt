cmake_minimum_required(VERSION 3.0)
project (okna)
set (CMAKE_CXX_STANDARD 17)

add_library (okna STATIC src/okna.cpp)
target_include_directories (okna PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries (okna PRIVATE glad)
target_link_libraries (okna PRIVATE glfw)
target_link_libraries (okna PRIVATE raylib-ext)
