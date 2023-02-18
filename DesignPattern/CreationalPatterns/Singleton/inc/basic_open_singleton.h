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
 * @brief This file provide a base template singleton class for other classes use.
 * @file basic_open_singleton.h
 * @author Tom Zhao(18872770445@163.com)
 * @since 2023-02-13
 * @date Created: 2023-02-13
 * @date Last modified: 2023-02-13
 *
 * Github: @link https://github.com/zty950323/UsingSTLCases @endlink
 * Homepage: @link https://blog.csdn.net/zhaotianyu950323 @endlink
 * Blog: @link https://www.zhihu.com/people/Tom_Zhao @endlink
 */

#ifndef _BASIC_OPEN_SIGLETON_H_H_
#define _BASIC_OPEN_SIGLETON_H_H_

#include <utility>

namespace Basic
{
    template <class T>
    class TemplateSingletonBase
    {
    public:
        inline static T *getPointer()
        {
            static T *pInstance = new T;
            return pInstance;
        }

        inline static T &getInstance()
        {
            static T ref;
            return ref;
        }

        TemplateSingletonBase(T &&) = delete;
        TemplateSingletonBase(const TemplateSingletonBase &) = delete;
        TemplateSingletonBase &operator=(const TemplateSingletonBase &) = delete;

    protected:
        TemplateSingletonBase() = default;
        virtual ~TemplateSingletonBase() = default;
    };
} // namespace Basic

#endif // _BASIC_OPEN_SIGLETON_H_H_
