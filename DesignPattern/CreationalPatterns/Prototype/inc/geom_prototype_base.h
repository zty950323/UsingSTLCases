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
* @file geom_prototype_base.h
* @author Tom Zhao(18872770445@163.com)
* @since 2023-02-01
* @date Created: 2023-02-01
* @date Last modified: 2023-02-01
*
* Github: @link https://github.com/zty950323/UsingSTLCases @endlink
* Homepage: @link https://blog.csdn.net/zhaotianyu950323 @endlink
* Blog: @link https://www.zhihu.com/people/Tom_Zhao @endlink
*/

#ifndef _GEOM_PROTOTYPE_BASE_H_H_
#define _GEOM_PROTOTYPE_BASE_H_H_

#include <string>

namespace GeomPrototype
{
    enum GeomType
    {
        kNone,
        kBase,
        kLineBase,
        kLineSeg,
        kLine,
        kRay,
    };

    class GeomPrototypeBase
    {
    public:
        GeomPrototypeBase();
        GeomPrototypeBase(const std::string& name, GeomType type = GeomType::kBase);

        virtual ~GeomPrototypeBase();
        virtual GeomPrototypeBase* clone() const = 0;
        virtual void showInfomation() const;

        GeomType type() const;
        const std::string& name() const;
        bool isValid() const;
        bool setName(const std::string& name);

    protected:
        std::string m_name;
        GeomType m_geomType;
    };
}  // namespace GeomPrototype

#endif  // _GEOM_PROTOTYPE_BASE_H_H_
