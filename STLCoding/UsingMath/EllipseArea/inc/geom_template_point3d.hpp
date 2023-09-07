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
 * @brief This file provide a class for a template class with 3D point.
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

#ifndef _GEOM_TEMPLATE_POINT3D_HPP_
#define _GEOM_TEMPLATE_POINT3D_HPP_

#include <cmath>

using std::pow;
using std::sqrt;

namespace Geometry
{
    /**
     * This is a C++ template class called GePoint2D that represents a 3D point with template type parameter T.
     * The class has public members x, y and z, which store the coordinates of the point,
     * and public methods to access and modify these coordinates.
     * It also provides methods to calculate the distance between the point and another point or a coordinate system.
     */
    template <typename T>
    class GePoint3D
    {
    public:
        GePoint3D() : m_x(0), m_y(0), m_z(0) {}
        GePoint3D(T x, T y, T z) : m_x(x), m_y(y), m_z(z) {}

        T x() const { return m_x; }
        T y() const { return m_y; }
        T z() const { return m_z; }

        void setX(T x) { m_x = x; }
        void setY(T y) { m_y = y; }
        void setZ(T z) { m_z = z; }

        T distanceTo(const GePoint3D<T> &p) const
        {
            return sqrt(pow(m_x - p.x(), 2) + pow(m_y - p.y(), 2) + pow(m_z - p.z(), 2));
        }

        T distanceTo(T x, T y, T z) const
        {
            return sqrt(pow(m_x - x, 2) + pow(m_y - y, 2) + pow(m_z - z, 2));
        }

        GePoint3D<T> &operator+=(const GePoint3D<T> &p)
        {
            m_x += p.x();
            m_y += p.y();
            m_z += p.z();
            return *this;
        }

        GePoint3D<T> &operator-=(const GePoint3D<T> &p)
        {
            m_x -= p.x();
            m_y -= p.y();
            m_z -= p.z();
            return *this;
        }

        GePoint3D<T> &operator*=(const GePoint3D<T> &p)
        {
            m_x *= p.x();
            m_y *= p.y();
            m_z *= p.z();
            return *this;
        }

        GePoint3D<T> &operator/=(const GePoint3D<T> &p)
        {
            m_x /= p.x();
            m_y /= p.y();
            m_z /= p.z();
            return *this;
        }

        GePoint3D<T> operator+(const GePoint3D<T> &p) const
        {
            return GePoint3D<T>(m_x + p.x(), m_y + p.y(), m_z + p.z());
        }

        GePoint3D<T> operator-(const GePoint3D<T> &p) const
        {
            return GePoint3D<T>(m_x - p.x(), m_y - p.y(), m_z - p.z());
        }

        GePoint3D<T> operator*(const GePoint3D<T> &p) const
        {
            return GePoint3D<T>(m_x * p.x(), m_y * p.y(), m_z * p.z());
        }

        GePoint3D<T> operator/(const GePoint3D<T> &p) const
        {
            return GePoint3D<T>(m_x / p.x(), m_y / p.y(), m_z / p.z());
        }

    private:
        bool checkIsValidDevidePoint(const GePoint3D<T> &p) const
        {
            return (p.x() != 0 && p.y() != 0 && p.z() != 0);
        }

    private:
        T m_x;
        T m_y;
        T m_z;
    };
}

#endif // _GEOM_TEMPLATE_POINT2D_HPP_
