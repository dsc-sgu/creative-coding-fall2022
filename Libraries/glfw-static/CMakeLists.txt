cmake_minimum_required(VERSION 3.0)
project (glfw)

add_library(glfw STATIC IMPORTED GLOBAL)
set_target_properties(glfw PROPERTIES INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR}/include)
if(APPLE)
    set_target_properties(glfw PROPERTIES IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/lib/macos-arm64/libglfw3.a)
endif()

if(WIN32)
    set_target_properties(glfw PROPERTIES IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/lib/windows-amd64/glfw3.lib)
endif()

if (UNIX AND NOT APPLE)
    set_target_properties(glfw PROPERTIES IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/lib/linux-amd64/libglfw3.a)
endif()
