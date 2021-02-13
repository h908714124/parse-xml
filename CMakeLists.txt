cmake_minimum_required(VERSION 3.0)

project(parse_xml LANGUAGES CXX)

add_executable(parse_xml main.cpp)

install(TARGETS parse_xml RUNTIME DESTINATION bin)
