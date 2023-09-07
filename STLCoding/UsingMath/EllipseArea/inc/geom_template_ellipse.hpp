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
 * @brief This file provide a class for a template class with 2D point.
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

#ifndef _GEOM_TEMPLATE_ELLIPSE_HPP_
#define _GEOM_TEMPLATE_ELLIPSE_HPP_

#include <cmath>

using std::cos;
using std::sin;
using std::sqrt;

#define M_PI 3.14159265358979323846

namespace Geometry
{
    /**
     * @brief This class is a template class with 2D point.
     * @tparam T The type of the point.
     */
    template <typename T>
    class Ellipse
    {
    public:
        Ellipse() : m_a(0), m_b(0), m_theta(0) {}
        Ellipse(T a, T b, T theta)
            : m_a(a), m_b(b), m_theta(theta) {}

        T a() const { return m_a; }
        T b() const { return m_b; }
        T theta() const { return m_theta; }

        void setA(T a) { m_a = a; }
        void setB(T b) { m_b = b; }
        void setTheTa(T theta) { m_theta = theta; }

        void setParameters(double a, double b, double theta)
        {
            m_a = a;
            m_b = b;
            m_theta = theta;
        }

        /**
         * @brief Calculate the area of the circle.
         *
         * @return double The area of the circle.
         */
        double area() const
        {
            double area = 0;
            double x, y;

            for (double alpha = 0; alpha < 2 * M_PI; alpha += M_PI / 180)
            {
                x = m_a * cos(alpha) * cos(m_theta) - m_b * sin(alpha) * sin(m_theta);
                y = m_a * cos(alpha) * sin(m_theta) + m_b * sin(alpha) * cos(m_theta);
                area += sqrt(x * x + y * y);
            }

            return area;
        }

        /**
         * @brief Calculate the perimeter of the circle.
         *
         * @return double The perimeter of the circle.
         */
        double perimeter() const
        {
            double perimeter = 0;
            double dtheta = M_PI / 180;

            for (int i = 0; i < 360; i++)
            {
                double x = m_a * cos(i * dtheta) * cos(m_theta) - m_b * sin(i * dtheta) * sin(m_theta);
                double y = m_a * cos(i * dtheta) * sin(m_theta) + m_b * sin(i * dtheta) * cos(m_theta);
                perimeter += sqrt(x * x + y * y);
            }

            return perimeter;
        }

    private:
        T m_a;
        T m_b;
        T m_theta;
    };
} // namespace Geometry

#endif //_GEOM_TEMPLATE_ELLIPSE_HPP_
