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

#ifndef _GEOM_TEMPLATE_POINT2D_HPP_
#define _GEOM_TEMPLATE_POINT2D_HPP_

#include <cmath>

namespace Geometry
{
    /**
     * This is a C++ template class called GePoint2D that represents a 2D point with template type parameter T.
     * The class has public members x and y, which store the coordinates of the point,
     * and public methods to access and modify these coordinates.
     * It also provides methods to calculate the distance between the point and another point or a coordinate system.
     */
    template <typename T>
    class GePoint2D
    {
    public:
        GePoint2D() : m_x(0), m_y(0) {}
        GePoint2D(T x, T y) : m_x(x), m_y(y) {}

        T x() const { return m_x; }
        T y() const { return m_y; }

        void setX(T x) { m_x = x; }
        void setY(T y) { m_y = y; }

        T distanceTo(const GePoint2D<T> &p) const
        {
            return sqrt((m_x - p.x()) * (m_x - p.x()) + (m_x - p.y()) * (m_x - p.y()));
        }

        T distanceTo(T x, T y) const
        {
            return sqrt((m_x - x) * (m_x - x) + (m_y - y) * (m_y - y));
        }

        GePoint2D<T> &operator+=(const GePoint2D<T> &p)
        {
            m_x += p.x();
            m_y += p.y();
            return *this;
        }

        GePoint2D<T> &operator-=(const GePoint2D<T> &p)
        {
            m_x -= p.x();
            m_y -= p.y();
            return *this;
        }

        GePoint2D<T> &operator*=(const GePoint2D<T> &p)
        {
            m_x *= p.x();
            m_y *= p.y();
            return *this;
        }

        GePoint2D<T> &operator/=(const GePoint2D<T> &p)
        {
            if (checkIsValidDevidePoint(p))
            {
                m_x /= p.x();
                m_y /= p.y();
            }
            return *this;
        }

        GePoint2D<T> operator+(const GePoint2D<T> &p) const
        {
            return GePoint2D<T>(m_x + p.x(), m_y + p.y());
        }

        GePoint2D<T> operator-(const GePoint2D<T> &p) const
        {
            return GePoint2D<T>(m_x - p.x(), m_y - p.y());
        }

        GePoint2D<T> operator*(const GePoint2D<T> &p) const
        {
            return GePoint2D<T>(m_x * p.x(), m_y * p.y());
        }

        GePoint2D<T> operator/(const GePoint2D<T> &p) const
        {
            if (checkIsValidDevidePoint(p))
            {
                return GePoint2D<T>(m_x / p.x(), m_y / p.y());
            }
            return GePoint2D<T>();
        }

    private:
        bool checkIsValidDevidePoint(const GePoint2D<T> &p) const
        {
            return (p.x() != 0 && p.y() != 0);
        }

    private:
        T m_x;
        T m_y;
    };
}

#endif // _GEOM_TEMPLATE_POINT2D_HPP_
