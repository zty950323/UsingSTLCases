#[================================================================[.rst:
    Copyright (c)2023, Tom Zhao personal. ("UsingSTLEx")
    This software is a personal tools project by Tom Zhao.
    Description: Hello Google Test.
#]================================================================]

set(TZ_MAIN_NAME HelloTest)

set(TZ_MAIN_INCLUDE
)

set(TZ_MAIN_INC
)

set(TZ_MAIN_SRC
	  hello_test.cc
)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    add_compile_options(
        /MT
    )
endif()

add_executable(${TZ_MAIN_NAME}
	${TZ_MAIN_INCLUDE}
	${TZ_MAIN_INC}
	${TZ_MAIN_SRC}
)

target_link_libraries(
  ${TZ_MAIN_NAME}
  gtest
  gtest_main
)

set_property(TARGET ${TZ_MAIN_NAME} PROPERTY FOLDER "CppLearningBase")
