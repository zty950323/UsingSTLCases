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
 * @brief This file provide some test about the class GePoint2D in this project.
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

#include "geom_template_point2d.hpp"

#include <gtest/gtest.h>

using namespace Geometry;

TEST(GePoint2DTest, Constructor)
{
    GePoint2D<double> point(1, 2);
    EXPECT_EQ(1, point.x());
    EXPECT_EQ(2, point.y());
}

TEST(GePoint2DTest, Setter)
{
    GePoint2D<double> point(1, 2);
    point.setX(3);
    point.setY(4);
    EXPECT_EQ(3, point.x());
    EXPECT_EQ(4, point.y());
}

TEST(GePoint2DTest, Getter)
{
    GePoint2D<double> point(1, 2);
    EXPECT_EQ(1, point.x());
    EXPECT_EQ(2, point.y());
}

TEST(GePoint2DTest, DistanceTo)
{
    GePoint2D<double> point(1, 2);
    GePoint2D<double> p2(3, 4);
    EXPECT_DOUBLE_EQ(sqrt(8), point.distanceTo(p2));
    EXPECT_DOUBLE_EQ(sqrt(4), point.distanceTo(1, 4));
}

TEST(GePoint2DTest, Addition)
{
    GePoint2D<double> point(1, 2);
    GePoint2D<double> p2(3, 4);
    GePoint2D<double> result = point + p2;
    EXPECT_EQ(4, result.x());
    EXPECT_EQ(6, result.y());
}

TEST(GePoint2DTest, Subtraction)
{
    GePoint2D<double> point(1, 2);
    GePoint2D<double> p2(3, 4);
    GePoint2D<double> result = point - p2;
    EXPECT_EQ(-2, result.x());
    EXPECT_EQ(-2, result.y());
}

TEST(GePoint2DTest, Multiplication)
{
    GePoint2D<double> point(1, 2);
    GePoint2D<double> p2(3, 4);
    GePoint2D<double> result = point * p2;
    EXPECT_EQ(3, result.x());
    EXPECT_EQ(8, result.y());
}

TEST(GePoint2DTest, Division)
{
    GePoint2D<double> point(1, 2);
    GePoint2D<double> p2(3, 4);
    GePoint2D<double> result = point / p2;
    EXPECT_NEAR(result.x(), 0.333, 1e-3);
    EXPECT_DOUBLE_EQ(0.50, result.y());
}
