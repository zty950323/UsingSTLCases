/**
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
* 1. You can modify and use this program at will.
* 2. But it is suggested that it is more suitable for learning and teaching
* purposes.
*
* @version 1.0
* @brief This file records some defines data struct about this project.
* @file geom_defines.h
* @author Tom Zhao(18872770445@163.com)
* @since 2023-02-01
* @date Created: 2023-02-01
* @date Last modified: 2023-02-01
*
* Github: @link https://github.com/zty950323/UsingSTLCases @endlink
* Homepage: @link https://blog.csdn.net/zhaotianyu950323 @endlink
* Blog: @link https://www.zhihu.com/people/Tom_Zhao @endlink
*/

#ifndef _GEOM_DEFINES_H_H_
#define _GEOM_DEFINES_H_H_

#include <string>

namespace GeomPrototype
{
    const std::string NAME_PRINT_STR = std::string("The name is : ");
    const std::string TYPE_PRINT_STR = std::string(" And the Type value is : ");
    const std::string START_POINT_STR = std::string(" And the start point is : ");
    const std::string DIRECTION_POINT_STR = std::string(" And The direction point is :");
    const std::string END_POINT_STR = std::string(" And The end point is :");

    struct GeomPoint3d
    {
        double x = 0.0;
        double y = 0.0;
        double z = 0.0;

        inline bool operator == (const GeomPoint3d& other) {
            return x == other.x && y == other.y && z == other.z;
        }
    };
}  // namespace GeomPrototype

#endif  // _GEOM_DEFINES_H_H_
