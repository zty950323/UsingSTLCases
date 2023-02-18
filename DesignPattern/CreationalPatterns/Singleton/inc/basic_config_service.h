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

#ifndef _BASIC_CONFIG_SERVICE_H_H_
#define _BASIC_CONFIG_SERVICE_H_H_

#include "basic_open_singleTon.h"

#include <string>
#include <map>

namespace Basic
{
    class ConfigService final : public TemplateSingletonBase<ConfigService>
    {
    public:
        ~ConfigService();

        const std::string& configPath() const;
        std::string& configPath();
        bool updateConfigPath(const std::string& newPath);

        const std::string& findConfig(const std::string& key) const;

        bool isValidConfig() const;
        bool modifyConfigValue(const std::string& key, const std::string& value);
        bool insertConfigValue(const std::string& key, const std::string& value);
        bool removeConfigValueByKey(const std::string& key);
        bool removeFirstConfigValueByValue(const std::string& value);

        void printConfigMapValues() const;

    private:
        friend TemplateSingletonBase<ConfigService>;
        ConfigService();
        std::string m_configPath;
        std::map<std::string, std::string> m_configValueMap;
    };
} // namespace Baisc

#endif // _BASIC_CONFIG_SERVICE_H_H_
