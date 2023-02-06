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
* @file geom_line_prototype.h
* @author Tom Zhao(18872770445@163.com)
* @since 2023-02-01
* @date Created: 2023-02-01
* @date Last modified: 2023-02-01
*
* Github: @link https://github.com/zty950323/UsingSTLCases @endlink
* Homepage: @link https://blog.csdn.net/zhaotianyu950323 @endlink
* Blog: @link https://www.zhihu.com/people/Tom_Zhao @endlink
*/

#ifndef _GEOM_LINE_PROTOTYPE_H_H_
#define _GEOM_LINE_PROTOTYPE_H_H_

#include "geom_prototype_base.h"
#include "geom_defines.h"

namespace GeomPrototype
{
    class GeomLinePrototype : public GeomPrototypeBase
    {
    public:
        GeomLinePrototype();
        GeomLinePrototype(const std::string& name, GeomType type = GeomType::kLineBase);

        ~GeomLinePrototype() override;

        GeomPrototypeBase* clone() const override;
        void showInfomation() const override;

        bool isClosed() const;
        bool is3DLineEnt() const;

        const GeomPoint3d& startPoint() const;
        bool moveTo(const GeomPoint3d& aimPoint);

    protected:
        bool m_bClosed;
        bool m_b3DLine;
        GeomPoint3d m_startPoint;
    };
}  // namespace GeomPrototype

#endif  // _GEOM_LINE_PROTOTYPE_H_H_
