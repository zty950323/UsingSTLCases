#[================================================================[.rst:
    Copyright (c)2021, Tom Zhao personal. ("UsingSTLEx")
    This software is a personal tools project by Tom Zhao.
    Description:
#]================================================================]

cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)

set(TZ_USING_STL_NAME UsingSTLProject)

set(TZ_USING_STL_INCLUDE
    include
)

set(TZ_ROOT_DIR ${CMAKE_SOURCE_DIR})
set(TZ_SDK_INCLUDE_DIR ${TZ_ROOT_DIR}/include)
set(TZ_THIRD_PARTY_DIR ${TZ_ROOT_DIR}/ThirdParty)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

project(${TZ_USING_STL_NAME})

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    add_definitions(
        -wd4819
    )

    add_compile_options(
        /std:c++latest
    )
endif()

enable_testing()
add_subdirectory(${TZ_THIRD_PARTY_DIR}/googletest)
include_directories(${TZ_THIRD_PARTY_DIR}/googletest/googletest/include)

add_subdirectory(STLCoding)
add_subdirectory(CppLearningBase)
add_subdirectory(TheModernCppChallenge)
add_subdirectory(TemplateSamples)
add_subdirectory(DesignPattern)
add_subdirectory(C++RestartLearning)