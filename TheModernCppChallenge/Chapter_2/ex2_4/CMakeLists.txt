#[================================================================[.rst:
    Copyright (c)2021, Tom Zhao personal. ("UsingSTLEx")
    This software is a personal tools project by Tom Zhao.
    Description:
#]================================================================]

set(TZ_MAIN_NAME MinimumFunctionWithAnyNumberOfArguments)

set(TZ_MAIN_INCLUDE

)

set(TZ_MAIN_INC

)

set(TZ_MAIN_SRC
	main.cpp
)

add_executable(${TZ_MAIN_NAME}
	${TZ_MAIN_INCLUDE}
	${TZ_MAIN_INC}
	${TZ_MAIN_SRC}
)

set_property(TARGET ${TZ_MAIN_NAME} PROPERTY FOLDER "TheModernCppChallenge/Chapter_2")