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
* @brief This file is an class for example for prototype case line seg.
* @file geom_line_seg.h
* @author Tom Zhao(18872770445@163.com)
* @since 2023-02-01
* @date Created: 2023-02-01
* @date Last modified: 2023-02-01
*
* Github: @link https://github.com/zty950323/UsingSTLCases @endlink
* Homepage: @link https://blog.csdn.net/zhaotianyu950323 @endlink
* Blog: @link https://www.zhihu.com/people/Tom_Zhao @endlink
*/

#ifndef _GEOM_LINE_SEG_H_H_
#define _GEOM_LINE_SEG_H_H_

#include "geom_line_type_prototype.h"

namespace GeomPrototype
{
    class GeomLineSeg final : public GeomLinePrototype
    {
    public:
        GeomLineSeg();
        GeomLineSeg(const std::string& name, GeomType type = GeomType::kLineSeg);

        ~GeomLineSeg() override;
        GeomPrototypeBase* clone() const override;
        void showInfomation() const override;

        const GeomPoint3d& endPoint() const;
        bool setEndPoint(const GeomPoint3d& aimEnd);

    private:
        GeomPoint3d m_endPoint;
    };
}  // namespace GeomPrototype

#endif  // _GEOM_LINE_SEG_H_H_
