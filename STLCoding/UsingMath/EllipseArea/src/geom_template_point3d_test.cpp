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

#include "geom_template_point3d.hpp"

#include <gtest/gtest.h>

using namespace Geometry;

constexpr auto nearTol = 1e-3;

TEST(GePoint3DTest, Constructor)
{
    GePoint3D<double> point(1, 2, 3);
    EXPECT_EQ(1, point.x());
    EXPECT_EQ(2, point.y());
    EXPECT_EQ(3, point.z());
}

TEST(GePoint3DTest, Setter)
{
    GePoint3D<double> point(1, 2, 3);
    point.setX(3);
    point.setY(4);
    point.setZ(5);
    EXPECT_EQ(3, point.x());
    EXPECT_EQ(4, point.y());
    EXPECT_EQ(5, point.z());
}

TEST(GePoint3DTest, Getter)
{
    GePoint3D<double> point(1, 2, 3);
    EXPECT_EQ(1, point.x());
    EXPECT_EQ(2, point.y());
    EXPECT_EQ(3, point.z());
}

TEST(GePoint3DTest, DistanceTo)
{
    GePoint3D<double> point(1, 2, 3);
    GePoint3D<double> p2(3, 4, 5);
    EXPECT_DOUBLE_EQ(sqrt(12), point.distanceTo(p2));
    EXPECT_DOUBLE_EQ(sqrt(12), point.distanceTo(3, 4, 5));
}

TEST(GePoint3DTest, Addition)
{
    GePoint3D<double> point(1, 2, 3);
    GePoint3D<double> p2(3, 4, 5);
    GePoint3D<double> result = point + p2;
    EXPECT_EQ(4, result.x());
    EXPECT_EQ(6, result.y());
    EXPECT_EQ(8, result.z());
}

TEST(GePoint3DTest, Subtraction)
{
    GePoint3D<double> point(1, 2, 3);
    GePoint3D<double> p2(3, 4, 5);
    GePoint3D<double> result = point - p2;
    EXPECT_EQ(-2, result.x());
    EXPECT_EQ(-2, result.y());
    EXPECT_EQ(-2, result.z());
}

TEST(GePoint3DTest, Multiplication)
{
    GePoint3D<double> point(1, 2, 3);
    GePoint3D<double> p2(3, 4, 5);
    GePoint3D<double> result = point * p2;
    EXPECT_EQ(3, result.x());
    EXPECT_EQ(8, result.y());
    EXPECT_EQ(15, result.z());
}

TEST(GePoint3DTest, Division)
{
    GePoint3D<double> point(1, 2, 3);
    GePoint3D<double> p2(3, 4, 5);
    GePoint3D<double> result = point / p2;
    EXPECT_NEAR(result.x(), 0.333, nearTol);
    EXPECT_NEAR(result.y(), 0.500, nearTol);
    EXPECT_NEAR(result.z(), 0.600, nearTol);
}
