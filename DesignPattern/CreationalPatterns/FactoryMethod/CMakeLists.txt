#[================================================================[.rst:
    Copyright (c)2023, Tom Zhao personal. ("UsingSTLEx")
    This software is a personal tools project by Tom Zhao.
    Description:
#]================================================================]

set(TZ_MAIN_NAME FactoryMethodExample)

set(TZ_MAIN_INCLUDE

)

set(CI_DIR inc/Creators)
set(SI_DIR inc/Subjects)

set(TZ_CREATOR_INC
    ${CI_DIR}/fd_subject_creator.h
)

set(TZ_SUBJECTS_INC
    ${SI_DIR}/fd_subject_base.h
    ${SI_DIR}/fd_chinese_subject.h
    ${SI_DIR}/fd_math_subject.h
    ${SI_DIR}/fd_english_subject.h
)

set(TZ_MAIN_INC
    ${TZ_CREATOR_INC}
    ${TZ_SUBJECTS_INC}
    inc/fd_subject_client.h
)

set(CC_DIR src/Creators)
set(SC_DIR src/Subjects)

set(TZ_CREATOR_SRC
    ${CC_DIR}/fd_subject_creator.cpp
)

set(TZ_SUBJECTS_SRC
    ${SC_DIR}/fd_subject_base.cpp
    ${SC_DIR}/fd_chinese_subject.cpp
    ${SC_DIR}/fd_math_subject.cpp
    ${SC_DIR}/fd_english_subject.cpp
)

set(TZ_MAIN_SRC
    ${TZ_CREATOR_SRC}
    ${TZ_SUBJECTS_SRC}
    main.cpp
)

add_executable(
    ${TZ_MAIN_NAME}
    ${TZ_MAIN_INCLUDE}
    ${TZ_MAIN_INC}
    ${TZ_MAIN_SRC}
)

set_property(TARGET ${TZ_MAIN_NAME} PROPERTY FOLDER "DesignPattern/CreationalPatterns")

source_group(
    "inc"
    FILES
    inc/fd_subject_client.h
)

source_group(
    ${CI_DIR}
    FILES
    ${TZ_CREATOR_INC}
)

source_group(
    ${SI_DIR}
    FILES
    ${TZ_SUBJECTS_INC}
)

source_group(
    "src"
    FILES
    src/fd_subject_client.cpp

    main.cpp
)

source_group(
    ${CC_DIR}
    FILES
    ${TZ_CREATOR_SRC}
)

source_group(
    ${SC_DIR}
    FILES
    ${TZ_SUBJECTS_SRC}
)
