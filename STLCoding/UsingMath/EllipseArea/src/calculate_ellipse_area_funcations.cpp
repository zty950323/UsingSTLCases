/**
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sub license, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 1. You can modify and use this program at will.
 * 2. But it is suggested that it is more suitable for learning and teaching
 * purposes.
 *
 * @version 1.0
 * @brief This file provide some funcations about to calculate the ellipse area.
 * @file basic_config_service_test.h
 * @author Tom Zhao(18872770445@163.com)
 * @since 2023-09-06
 * @date Created: 2023-09-06
 * @date Last modified: 2023-09-06
 *
 * Github: @link https://github.com/zty950323/UsingSTLCases @endlink
 * Homepage: @link https://blog.csdn.net/zhaotianyu950323 @endlink
 * Blog: @link https://www.zhihu.com/people/Tom_Zhao @endlink
 */

#include "calculate_ellipse_area_funcations.h"

namespace Geometry
{
    /**
     * Calculate the area of an ellipse.
     *
     * @param a The semi-major axis of the ellipse.
     * @param b The semi-minor axis of the ellipse.
     * @param theta The rotation angle of the ellipse.
     * @return The area of the ellipse.
     */
    double calculateEllipseArea(double a, double b, double theta)
    {
        double area = 0;
        double x, y;

        for (double alpha = 0; alpha < 2 * M_PI; alpha += M_PI / 180)
        {
            x = a * cos(alpha) * cos(theta) - b * sin(alpha) * sin(theta);
            y = a * cos(alpha) * sin(theta) + b * sin(alpha) * cos(theta);
            area += sqrt(x * x + y * y);
        }

        return area;
    }
} // namespace Geometry
