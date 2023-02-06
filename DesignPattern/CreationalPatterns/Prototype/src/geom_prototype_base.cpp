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
* @brief This file is an prototype base class for all Geom classes in this example.
* codec.
* @file geom_prototype_base.cpp
* @author Tom Zhao(18872770445@163.com)
* @since 2023-02-01
* @date Created: 2023-02-01
* @date Last modified: 2023-02-01
*
* Github: @link https://github.com/zty950323/UsingSTLCases @endlink
* Homepage: @link https://blog.csdn.net/zhaotianyu950323 @endlink
* Blog: @link https://www.zhihu.com/people/Tom_Zhao @endlink
*/

#include "geom_prototype_base.h"
#include "geom_defines.h"

#include <iostream>

using std::string;
using std::cout;
using std::endl;

namespace GeomPrototype
{
    GeomPrototypeBase::GeomPrototypeBase()
        : m_name(string()), m_geomType(GeomType::kBase)
    {
    }

    GeomPrototypeBase::GeomPrototypeBase(const string& name, GeomType type)
        : m_name(name), m_geomType(type)
    {
    }

    GeomPrototypeBase::~GeomPrototypeBase()
    {
    }

    void GeomPrototypeBase::showInfomation() const
    {
        cout << NAME_PRINT_STR << m_name <<
            TYPE_PRINT_STR << static_cast<unsigned int>(m_geomType) << endl;
    }

    const string& GeomPrototypeBase::name() const
    {
        return m_name;
    }

    bool GeomPrototypeBase::setName(const string& name)
    {
        if (name == m_name) {
            return false;
        }

        m_name = name;
        return true;
    }

    GeomType GeomPrototypeBase::type() const
    {
        return m_geomType;
    }

    bool GeomPrototypeBase::isValid() const
    {
        if (m_name.empty() ||
            m_geomType == GeomType::kBase ||
            m_geomType == GeomType::kNone) {
            return false;
        }

        return true;
    }
}  // namespace GeomPrototype
