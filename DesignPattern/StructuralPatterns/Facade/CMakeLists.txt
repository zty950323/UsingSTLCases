#[================================================================[.rst:
    Copyright (c)2023, Tom Zhao personal. ("UsingSTLEx")
    This software is a personal tools project by Tom Zhao.
    Description:
#]================================================================]

set(TZ_MAIN_NAME FacadeExample)

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

set_property(TARGET ${TZ_MAIN_NAME} PROPERTY FOLDER "DesignPattern/StructuralPatterns")