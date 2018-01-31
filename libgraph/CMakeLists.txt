cmake_minimum_required(VERSION 3.9)

project(libgraph VERSION 1.0 DESCRIPTION "A library for graph manipulations")

add_library(graph SHARED vertex.cpp
                        edge.cpp
                        graph.cpp
                        gio.cpp)

set_target_properties(graph PROPERTIES 
    VERSION ${PROJECT_VERSION}
    SOVERSION 1.0)

target_include_directories(graph PRIVATE ${CMAKE_SOURCE_DIR}/include)

