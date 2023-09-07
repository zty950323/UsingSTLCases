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
 * @brief This file provide some test about calculate ellipse area funcations.
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

#include <gtest/gtest.h>

using namespace Geometry;

constexpr auto nearTol = 1e-9;
constexpr auto nearFloatTol = 1e-2;
constexpr auto nearIntTol = 1;

// Define some Test for functions.

TEST(CalculateEllipseAreaTest, CalculateEllipseArea)
{
    EXPECT_NEAR(calculateEllipseArea(1, 2, 0), 556.10719306841565, nearTol);
    EXPECT_NEAR(calculateEllipseArea(3, 4, M_PI / 2), 1269.4368133091564, nearTol);
    EXPECT_NEAR(calculateEllipseArea(5, 10, 0), 2780.535965342076, nearTol);
    EXPECT_NEAR(calculateEllipseArea(10, 20, M_PI / 2), 5561.071930684152, nearTol);
}

TEST(CalculateEllipseAreaTest, CalculateEllipseAreaTempalte)
{
    // Some Double template case.
    EXPECT_NEAR(calculateEllipseAreaTemplate<double>(1, 2, 0), 556.10719306841565, nearTol);
    EXPECT_NEAR(calculateEllipseAreaTemplate<double>(3, 4, M_PI / 2), 1269.4368133091564, nearTol);
    EXPECT_NEAR(calculateEllipseAreaTemplate<double>(5, 10, 0), 2780.535965342076, nearTol);
    EXPECT_NEAR(calculateEllipseAreaTemplate<double>(10, 20, M_PI / 2), 5561.071930684152, nearTol);

    // Some Float template case.
    EXPECT_NEAR(calculateEllipseAreaTemplate<float>(1, 2, 0), 556.107193068415653f, nearFloatTol);
    EXPECT_NEAR(calculateEllipseAreaTemplate<float>(3, 4, M_PI / 2), 1269.4368133091564f, nearFloatTol);
    EXPECT_NEAR(calculateEllipseAreaTemplate<float>(5, 10, 0), 2780.535965342076f, nearFloatTol);
    EXPECT_NEAR(calculateEllipseAreaTemplate<float>(10, 20, M_PI / 2), 5561.071930684152f, nearFloatTol);

    // Some Int template case.
    EXPECT_NEAR(calculateEllipseAreaTemplate<int>(1, 2, 0), 556, nearIntTol);
    EXPECT_NEAR(calculateEllipseAreaTemplate<int>(3, 4, M_PI / 2), 1269, nearIntTol);
    EXPECT_NEAR(calculateEllipseAreaTemplate<int>(5, 10, 0), 2780, nearIntTol);
    EXPECT_NEAR(calculateEllipseAreaTemplate<int>(10, 20, M_PI / 2), 5561, nearIntTol);
}