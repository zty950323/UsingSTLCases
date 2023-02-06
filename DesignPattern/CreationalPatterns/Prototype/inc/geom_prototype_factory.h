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
* @file geom_prototype_factory.h
* @author Tom Zhao(18872770445@163.com)
* @since 2023-02-01
* @date Created: 2023-02-01
* @date Last modified: 2023-02-01
*
* Github: @link https://github.com/zty950323/UsingSTLCases @endlink
* Homepage: @link https://blog.csdn.net/zhaotianyu950323 @endlink
* Blog: @link https://www.zhihu.com/people/Tom_Zhao @endlink
*/

#ifndef _GEOM_PROTOTYPE_FACTORY_H_H_
#define _GEOM_PROTOTYPE_FACTORY_H_H_

#include "geom_prototype_base.h"

#include <unordered_map>

namespace GeomPrototype
{
    class GeomPrototypeFactory final
    {
    public:
        GeomPrototypeFactory();
        ~GeomPrototypeFactory();

        GeomPrototypeBase* createGeomPrototype(GeomType type);

    private:
        std::unordered_map<GeomType,
            GeomPrototypeBase*, std::hash<int>> m_geomPrototypes;
    };
}  // namespace GeomPrototype

#endif  // _GEOM_PROTOTYPE_FACTORY_H_H_
