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
 * @brief This file provide a singleton config service as an example for singleton.
 * @file basic_config_service.h
 * @author Tom Zhao(18872770445@163.com)
 * @since 2023-02-13
 * @date Created: 2023-02-13
 * @date Last modified: 2023-02-13
 *
 * Github: @link https://github.com/zty950323/UsingSTLCases @endlink
 * Homepage: @link https://blog.csdn.net/zhaotianyu950323 @endlink
 * Blog: @link https://www.zhihu.com/people/Tom_Zhao @endlink
 */

#include "basic_config_service.h"

#include <iostream>

using std::string;
using std::map;
using std::cout;
using std::endl;

namespace Basic
{
    ConfigService::ConfigService()
        : m_configPath(string())
        , m_configValueMap(map<string, string>())
    {
    }

    ConfigService::~ConfigService()
    {
    }

    const string& ConfigService::configPath() const
    {
        return m_configPath;
    }

    string& ConfigService::configPath()
    {
        return m_configPath;
    }

    bool ConfigService::updateConfigPath(const string& newPath)
    {
        if (m_configPath != newPath) {
            m_configPath = newPath;
            return true;
        }

        return false;
    }

    const string& ConfigService::findConfig(const string& key) const
    {
        return m_configValueMap.at(key);
    }

    bool ConfigService::modifyConfigValue(const string& key, const string& value)
    {
        if (m_configValueMap.contains(key)) {
            m_configValueMap.at(key) = value;
            return true;
        }

        return false;
    }

    bool ConfigService::insertConfigValue(const string& key, const string& value)
    {
        if (!m_configValueMap.contains(key)) {
            m_configValueMap[key] = value;
            return true;
        }

        string& innerValueAtKey = m_configValueMap[key];
        if (innerValueAtKey != value) {
            innerValueAtKey = value;
            return true;
        }

        return false;
    }

    bool ConfigService::removeConfigValueByKey(const string& key)
    {
        if (m_configValueMap.contains(key)) {
            m_configValueMap.erase(key);
            return true;
        }

        return false;
    }

    bool ConfigService::removeFirstConfigValueByValue(const string& value)
    {
        auto findKey = m_configValueMap.find(value);
        if (findKey != m_configValueMap.end()) {
            m_configValueMap.erase(findKey);
            return true;
        }

        return false;
    }

    void ConfigService::printConfigMapValues() const
    {
        for (const auto& obj : m_configValueMap) {
            cout << obj.first << ',' << obj.second << endl;
        }
    }

    bool ConfigService::isValidConfig() const
    {
        return !m_configPath.empty() && !m_configValueMap.empty();
    }
}  // namespace Basic
