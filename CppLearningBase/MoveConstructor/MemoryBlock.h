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
 * @brief This is a file for learning Micosoft's Templates (C++)
 * @link https://docs.microsoft.com/zh-cn/cpp/cpp/move-constructors-and-move-assignment-operators-cpp @endlink
 * @file main.cpp
 * @author Tom Zhao(18872770445@163.com)
 * @since 2022-07-04
 * @date Created: 2022-07-04
 * @date Last modified: 2022-07-04
 *
 * Github: @link https://github.com/zty950323/UsingSTLCases.git @endlink
 * Gitee: @link https://gitee.com/zhaotianyuCoding/using-stlex.git @endlink
 * Homepage: @link https://blog.csdn.net/zhaotianyu950323 @endlink
 * Blog: @link https://www.zhihu.com/people/Tom_Zhao @endlink
 */

#ifndef __MEMORYBLOCK__H__
#define __MEMORYBLOCK__H__

#include <iostream>
#include <algorithm>

namespace TzSoft
{
    class MemoryBlock
    {
    public:
        // Simple constructor that allocates a block of memory of the given size.
        MemoryBlock(size_t size)
            : m_size(size), m_data(new char[size])
        {
            std::fill_n(m_data, size, 0);
            std::cout << "In MemoryBlock(size_t). length = "
                      << m_size << "." << std::endl;
        }

        // Destructor that deallocates the memory block.
        ~MemoryBlock()
        {
            std::cout << "In ~MemoryBlock(). length = "
                      << m_size << ".";
            if (m_data)
            {
                std::cout << " Deleting resource.";
                // Delete the resource.
                delete[] m_data;
                m_data = nullptr;
            }
            std::cout << std::endl;
        }

        // Copy constructor.
        MemoryBlock(const MemoryBlock &other)
            : m_size(other.m_size), m_data(new char[other.m_size])
        {
            std::cout << "In MemoryBlock(const MemoryBlock&). length = "
                      << other.m_size << ". Copying resource." << std::endl;
            std::copy(other.m_data, other.m_data + m_size, m_data);
        }

        // Move constructor.
        MemoryBlock(MemoryBlock &&other)
            : m_size(other.m_size), m_data(other.m_data)
        {
            std::cout << "In MemoryBlock(MemoryBlock&&). length = "
                      << other.m_size << ". Moving resource." << std::endl;
            other.m_size = 0;
            other.m_data = nullptr;
        }

        // Copy assignment operator.
        MemoryBlock &operator=(const MemoryBlock &other)
        {
            std::cout << "In operator=(const MemoryBlock&). length = "
                      << other.m_size << ". Copying resource." << std::endl;
            if (this != &other)
            {
                // Free the existing resource.
                m_size = other.m_size;
                delete[] m_data;
                m_data = new char[other.m_size];
                std::copy(other.m_data, other.m_data + m_size, m_data);
            }
            return *this;
        }

        // Move assignment operator.
        MemoryBlock &operator=(MemoryBlock &&other)
        {
            std::cout << "In operator=(MemoryBlock&&). length = "
                      << other.m_size << "." << std::endl;
            if (this != &other)
            {
                // Free the existing resource.
                delete[] m_data;

                // Copy the other resource.
                m_size = other.m_size;
                m_data = other.m_data;

                // Release the data pointer from the source object so that
                // the destructor does not free the memory multiple times.
                other.m_data = nullptr;
                other.m_size = 0;
            }
            return *this;
        }

        friend std::ostream &operator<<(std::ostream &os, const MemoryBlock &block)
        {
            os << "MemoryBlock: " << block.m_size << " bytes" << std::endl;
            return os;
        }

        // Retrieves the length of the data resource.
        size_t Length() const
        {
            return m_size;
        }

    private:
        size_t m_size; // The length of the resource.
        char *m_data;  // The resource.
    };
} // namespace TzSoft

#endif //!__MEMORYBLOCK__H__
