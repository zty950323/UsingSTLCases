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
* @brief This file defines a factory for create geom type classes.
* @file geom_prototype_factory.cpp
* @author Tom Zhao(18872770445@163.com)
* @since 2023-02-01
* @date Created: 2023-02-01
* @date Last modified: 2023-02-01
*
* Github: @link https://github.com/zty950323/UsingSTLCases @endlink
* Homepage: @link https://blog.csdn.net/zhaotianyu950323 @endlink
* Blog: @link https://www.zhihu.com/people/Tom_Zhao @endlink
*/

#include "geom_prototype_factory.h"
#include "geom_line.h"
#include "geom_line_seg.h"
#include "geom_ray.h"

namespace GeomPrototype
{
    GeomPrototypeFactory::GeomPrototypeFactory()
    {
        m_geomPrototypes[GeomType::kLineBase] = new GeomLinePrototype("GeomLinePrototype");
        m_geomPrototypes[GeomType::kLine] = new GeomLine("GeomLine");
        m_geomPrototypes[GeomType::kLineSeg] = new GeomLineSeg("GeomLineSeg");
        m_geomPrototypes[GeomType::kRay] = new GeomRay("GeomRay");
    }

    GeomPrototypeFactory::~GeomPrototypeFactory()
    {
        for (auto& geomPrototype : m_geomPrototypes) {
            auto pPrototype = geomPrototype.second;
            if (pPrototype) {
                delete pPrototype;
                pPrototype = nullptr;
            }
        }
    }

    GeomPrototypeBase* GeomPrototypeFactory::createGeomPrototype(GeomType type)
    {
        auto pPrototype = m_geomPrototypes[type];
        if (pPrototype) {
            return pPrototype->clone();
        }
        return nullptr;
    }
}  // namespace GeomPrototype
