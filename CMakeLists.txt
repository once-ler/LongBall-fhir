cmake_minimum_required(VERSION 3.2)

project(LongBall-fhir VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_CXX_FLAGS "-fno-stack-protector")

find_package(Threads)

MESSAGE( STATUS "PROJECT_SOURCE_DIR: " ${PROJECT_SOURCE_DIR} )
MESSAGE( STATUS "CMAKE_CURRENT_SOURCE_DIR: " ${CMAKE_CURRENT_SOURCE_DIR} )

set(JSON ${PROJECT_SOURCE_DIR}/../json/src)

include_directories(
    /usr/local/include
    "${PROJECT_SOURCE_DIR}/src"
    "${JSON}"
)

set(CPP_SOURCES
    "${PROJECT_SOURCE_DIR}/src/LongBall-fhir.hpp"
)

add_library(LongBall-fhir SHARED ${CPP_SOURCES})
SET_TARGET_PROPERTIES(LongBall-fhir PROPERTIES LINKER_LANGUAGE CXX)

target_link_libraries(
    LongBall-fhir
    Threads::Threads
    libasync++.so
)

