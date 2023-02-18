#[================================================================[.rst:
    Copyright (c)2023, Tom Zhao personal. ("UsingSTLEx")
    This software is a personal tools project by Tom Zhao.
    Description:
#]================================================================]

set(TZ_MAIN_NAME SingletonExample)

set(TZ_MAIN_INCLUDE

)

set(TZ_MAIN_INC
    inc/basic_config_service_test.h
    inc/basic_config_service.h
    inc/basic_open_singleton.h
)

set(TZ_MAIN_SRC
    src/basic_config_service.cpp
    src/basic_config_service_test.cpp
    main.cpp
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
