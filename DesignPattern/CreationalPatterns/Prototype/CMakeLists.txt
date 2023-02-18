#[================================================================[.rst:
    Copyright (c)2023, Tom Zhao personal. ("UsingSTLEx")
    This software is a personal tools project by Tom Zhao.
    Description:
#]================================================================]

set(TZ_MAIN_NAME PrototypeExample)

set(TZ_MAIN_INCLUDE

)

set(TZ_MAIN_INC
    inc/geom_defines.h
    inc/geom_line_seg.h
    inc/geom_line_type_prototype.h
    inc/geom_line.h
    inc/geom_prototype_base.h
    inc/geom_prototype_cases.h
    inc/geom_prototype_factory.h
    inc/geom_ray.h
)

set(TZ_MAIN_SRC
    main.cpp
    src/geom_line_seg.cpp
    src/geom_line_type_prototype.cpp
    src/geom_line.cpp
    src/geom_prototype_base.cpp
    src/geom_prototype_cases.cpp
    src/geom_prototype_factory.cpp
    src/geom_ray.cpp
)

set(TZ_INCLUDE_PREFIX
    inc
)

include_directories(${TZ_INCLUDE_PREFIX})

add_executable(${TZ_MAIN_NAME}
    ${TZ_MAIN_INCLUDE}
    ${TZ_MAIN_INC}
    ${TZ_MAIN_SRC}
)

set_property(TARGET ${TZ_MAIN_NAME} PROPERTY FOLDER "CreationalPatterns")