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
 * @brief This file provide some test about the class Ellipse in this project.
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

#include "geom_template_ellipse.hpp"

#include <gtest/gtest.h>

using namespace Geometry;

constexpr auto nearTol = 1e-9;

TEST(EllipseTest, Constructor)
{
    Ellipse<double> ellipse;
    EXPECT_EQ(0, ellipse.a());
    EXPECT_EQ(0, ellipse.b());
    EXPECT_EQ(0, ellipse.theta());
}

TEST(EllipseTest, Setter)
{
    Ellipse<double> ellipse(1, 2, 3);
    ellipse.setA(3);
    ellipse.setB(4);
    ellipse.setTheTa(5);
    EXPECT_EQ(3, ellipse.a());
    EXPECT_EQ(4, ellipse.b());
    EXPECT_EQ(5, ellipse.theta());
}

TEST(EllipseTest, Getter)
{
    Ellipse<double> ellipse(1, 2, 3);
    EXPECT_EQ(1, ellipse.a());
    EXPECT_EQ(2, ellipse.b());
    EXPECT_EQ(3, ellipse.theta());
}

TEST(EllipseTest, SetParameters)
{
    Ellipse<double> ellipse;
    ellipse.setParameters(1, 2, 3);
    EXPECT_EQ(1, ellipse.a());
    EXPECT_EQ(2, ellipse.b());
    EXPECT_EQ(3, ellipse.theta());
}

TEST(EllipseTest, Area)
{
    Ellipse<double> ellipse(1, 2, 3);
    EXPECT_NEAR(ellipse.area(), 556.10719306841565, nearTol);
}

TEST(EllipseTest, Perimeter)
{
    Ellipse<double> ellipse(1, 2, 3);
    EXPECT_NEAR(ellipse.perimeter(), 555.1071930684144, nearTol);
}
