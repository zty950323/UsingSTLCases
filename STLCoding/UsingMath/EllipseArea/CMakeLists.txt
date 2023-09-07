#[================================================================[.rst:
    Copyright (c)2023, Tom Zhao personal. ("UsingSTLEx")
    This software is a personal tools project by Tom Zhao.
    Description : This is a project about to define some geometry class and using them.
#]================================================================]

set(TZ_MAIN_NAME EllipseArea)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    add_compile_options(
        /MT
    )
endif()

set(TZ_MAIN_INC
    inc/calculate_ellipse_area_funcations.h
	inc/geom_template_ellipse.hpp
	inc/geom_template_point2d.hpp
	inc/geom_template_point3d.hpp
)

set(TZ_MAIN_SRC
	src/calculate_ellipse_area_funcations_test.cpp
    src/calculate_ellipse_area_funcations.cpp
    src/geom_template_ellipse_test.cpp
    src/geom_template_point2d_test.cpp
    src/geom_template_point3d_test.cpp
)

add_executable(${TZ_MAIN_NAME}
	${TZ_MAIN_INCLUDE}
	${TZ_MAIN_INC}
	${TZ_MAIN_SRC}
)

target_include_directories(${TZ_MAIN_NAME} PUBLIC
 	${TZ_SDK_INCLUDE_DIR}
	inc
)

target_link_libraries(
  ${TZ_MAIN_NAME}
  gtest
  gtest_main
)

set_property(TARGET ${TZ_MAIN_NAME} PROPERTY FOLDER "STL/UsingMath")
