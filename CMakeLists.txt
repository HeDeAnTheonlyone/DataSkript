cmake_minimum_required(VERSION 3.10)
project(DataScript VERSION 1.0)

include_directories(${PROJECT_SOURCE_DIR}/headers)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "scr/*.c")

add_executable(DataScript ${SOURCES})