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
* @brief This file defines a test cases class for this example.
* @file geom_prototype_cases.cpp
* @author Tom Zhao(18872770445@163.com)
* @since 2023-02-01
* @date Created: 2023-02-01
* @date Last modified: 2023-02-01
*
* Github: @link https://github.com/zty950323/UsingSTLCases @endlink
* Homepage: @link https://blog.csdn.net/zhaotianyu950323 @endlink
* Blog: @link https://www.zhihu.com/people/Tom_Zhao @endlink
*/

#include "geom_prototype_cases.h"
#include "geom_prototype_factory.h"
#include "geom_line_seg.h"

#include <iostream>

using std::cout;
using std::endl;

namespace GeomPrototype
{
    void GeomPrototypeTestCases::testAllGeomPrototype()
    {
        cout << "Let's create some geometry prototype by factory: " << endl;

        GeomPrototypeFactory* pFactory = new GeomPrototypeFactory();
        GeomPrototypeBase* pPrototype = pFactory->createGeomPrototype(GeomType::kLineBase);
        if (pPrototype && pPrototype->isValid()) {
            pPrototype->showInfomation();
            delete pPrototype;
            pPrototype = nullptr;
        }

        pPrototype = pFactory->createGeomPrototype(GeomType::kLine);
        if (pPrototype && pPrototype->isValid()) {
            pPrototype->showInfomation();
            delete pPrototype;
            pPrototype = nullptr;
        }

        pPrototype = pFactory->createGeomPrototype(GeomType::kLineSeg);
        if (pPrototype && pPrototype->isValid()) {
            pPrototype->showInfomation();
            delete pPrototype;
            pPrototype = nullptr;
        }

        pPrototype = pFactory->createGeomPrototype(GeomType::kRay);
        if (pPrototype && pPrototype->isValid()) {
            pPrototype->showInfomation();
            delete pPrototype;
            pPrototype = nullptr;
        }

        pPrototype = pFactory->createGeomPrototype(GeomType::kLineSeg);
        if (pPrototype && pPrototype->isValid()) {
            pPrototype->setName("TestNewLineSegName");
            GeomLineSeg* pLineSeg = static_cast<GeomLineSeg*>(pPrototype);
            if (pLineSeg) {
                pLineSeg->setEndPoint(GeomPoint3d(20.0, 20.0, 20.0));
            }
            pPrototype->showInfomation();
            delete pPrototype;
            pPrototype = nullptr;
        }

        if (pFactory) {
            delete pFactory;
            pFactory = nullptr;
        }

        cout << "The End of the geom factory test case." << endl;
    }
}  // namespace GeomPrototype
