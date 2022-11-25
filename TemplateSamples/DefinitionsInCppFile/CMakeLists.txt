#[================================================================[.rst:
    Copyright (c)2021, Tom Zhao personal. ("UsingSTLEx")
    This software is a personal tools project by Tom Zhao.
    Description:
#]================================================================]

set(TZ_MAIN_NAME DefinitionsInCppFile)

set(TZ_MAIN_INCLUDE

)

set(TZ_MAIN_INC
    template_case_one.h
    template_case_two.h
)

set(TZ_MAIN_SRC
    template_case_one.cpp
    template_case_two.cpp
	main.cpp
)

add_executable(${TZ_MAIN_NAME}
	${TZ_MAIN_INCLUDE}
	${TZ_MAIN_INC}
	${TZ_MAIN_SRC}
)

set_property(TARGET ${TZ_MAIN_NAME} PROPERTY FOLDER "TemplateSamples")