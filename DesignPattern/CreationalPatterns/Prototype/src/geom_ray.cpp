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
* @brief This file is an class for example for prototype case ray.
* @file geom_ray.cpp
* @author Tom Zhao(18872770445@163.com)
* @since 2023-02-01
* @date Created: 2023-02-01
* @date Last modified: 2023-02-01
*
* Github: @link https://github.com/zty950323/UsingSTLCases @endlink
* Homepage: @link https://blog.csdn.net/zhaotianyu950323 @endlink
* Blog: @link https://www.zhihu.com/people/Tom_Zhao @endlink
*/

#include "geom_ray.h"

#include <iostream>

using std::cout;
using std::endl;

namespace GeomPrototype
{
    GeomRay::GeomRay()
        : GeomLinePrototype()
    {
        m_b3DLine = true;
    }

    GeomRay::GeomRay(const std::string& name, GeomType type)
        : GeomLinePrototype(name, type)
    {
        m_b3DLine = true;
    }

    GeomRay::~GeomRay()
    {
    }

    GeomPrototypeBase* GeomRay::clone() const
    {
        return new GeomRay(*this);
    }

    const GeomPoint3d& GeomRay::directionPoint() const
    {
        return m_directionPoint;
    }

    bool GeomRay::setDirectionPoint(const GeomPoint3d& aimDirection)
    {
        if (m_directionPoint == aimDirection) {
            return false;
        }

        m_directionPoint = aimDirection;
        return true;
    }

    void GeomRay::showInfomation() const
    {
        cout << NAME_PRINT_STR << m_name <<
            TYPE_PRINT_STR << static_cast<unsigned int>(m_geomType)
            << START_POINT_STR << '\t' << m_startPoint.x << ','
            << m_startPoint.y << ','  << m_startPoint.z
            << DIRECTION_POINT_STR << '\t' << m_directionPoint.x
            << ',' << m_directionPoint.y << ',' << m_directionPoint.z << endl;
    }
}  // namespace GeomPrototype
