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
* @brief This file is an prototype for line type class for all Geom classes in this example.
* codec.
* @file geom_line_prototype.cpp
* @author Tom Zhao(18872770445@163.com)
* @since 2023-02-01
* @date Created: 2023-02-01
* @date Last modified: 2023-02-01
*
* Github: @link https://github.com/zty950323/UsingSTLCases @endlink
* Homepage: @link https://blog.csdn.net/zhaotianyu950323 @endlink
* Blog: @link https://www.zhihu.com/people/Tom_Zhao @endlink
*/

#include "geom_line_type_prototype.h"

#include <iostream>

using std::string;
using std::cout;
using std::endl;

namespace GeomPrototype
{
    GeomLinePrototype::GeomLinePrototype()
        : GeomPrototypeBase(),
        m_bClosed(false),
        m_b3DLine(false)
    {
    }

    GeomLinePrototype::GeomLinePrototype(const string& name, GeomType type)
        : GeomPrototypeBase(name, type),
        m_bClosed(false),
        m_b3DLine(false)
    {
    }

    GeomLinePrototype::~GeomLinePrototype()
    {
    }

    GeomPrototypeBase* GeomLinePrototype::clone() const
    {
        return new GeomLinePrototype(*this);
    }

    bool GeomLinePrototype::isClosed() const
    {
        return m_bClosed;
    }

    bool GeomLinePrototype::is3DLineEnt() const
    {
        return m_b3DLine;
    }

    const GeomPoint3d& GeomLinePrototype::startPoint() const
    {
        return m_startPoint;
    }

    void GeomLinePrototype::showInfomation() const
    {
        cout << NAME_PRINT_STR << m_name <<
            TYPE_PRINT_STR << static_cast<unsigned int>(m_geomType)
            << START_POINT_STR << '\t' << m_startPoint.x << ','
            << m_startPoint.y << ','  << m_startPoint.z << endl;
    }

    bool GeomLinePrototype::moveTo(const GeomPoint3d& aimPoint)
    {
        if (m_startPoint == aimPoint) {
            return false;
        }

        m_startPoint = aimPoint;
        return true;
    }
}  // namespace GeomPrototype
