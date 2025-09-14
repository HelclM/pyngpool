cmake_minimum_required(VERSION 3.15)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_custom_target(copy-compile-commands ALL
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
            ${CMAKE_BINARY_DIR}/compile_commands.json
            ${CMAKE_SOURCE_DIR}/compile_commands.json
    DEPENDS ${CMAKE_BINARY_DIR}/compile_commands.json
)

project(libngpool)

set(CMAKE_CXX_STANDARD 17)

add_library(libngpool STATIC src/test.cpp)
target_include_directories(libngpool PUBLIC include)

find_package(pybind11 REQUIRED)

pybind11_add_module(pyngpool MODULE bindings/bindings.cpp)
set_target_properties(pyngpool PROPERTIES OUTPUT_NAME "_pyngpool")
target_link_libraries(pyngpool PRIVATE libngpool)
install(TARGETS pyngpool DESTINATION pyngpool)
