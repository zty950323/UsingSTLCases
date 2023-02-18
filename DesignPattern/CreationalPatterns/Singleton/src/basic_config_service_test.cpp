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
 * @brief This file provide test class for ConfigService.
 * @file basic_config_service_test.h
 * @author Tom Zhao(18872770445@163.com)
 * @since 2023-02-13
 * @date Created: 2023-02-13
 * @date Last modified: 2023-02-13
 *
 * Github: @link https://github.com/zty950323/UsingSTLCases @endlink
 * Homepage: @link https://blog.csdn.net/zhaotianyu950323 @endlink
 * Blog: @link https://www.zhihu.com/people/Tom_Zhao @endlink
 */

#include "basic_config_service_test.h"
#include "basic_config_service.h"

#include <iostream>

using std::string;
using std::cout;
using std::endl;

namespace Basic
{
    void ConfigServiceTest::testConfigSingleton()
    {
        auto& cInstance = ConfigService::getInstance();
        auto& cPath = cInstance.configPath();
        cPath = string("TestSinglePath/FirstTestCases/");
        cout << "ConfigService Paht is :" << cInstance.configPath() << endl;
        cInstance.insertConfigValue("Bob", "Reading books.");
        cInstance.insertConfigValue("Tom", "Playing games.");
        cInstance.insertConfigValue("Tom", "Playing games.");  // This will not add into it.
        cInstance.insertConfigValue("Lara", "Making cooks.");
        if (cInstance.isValidConfig()) {
            cout << "This is a valid config!" << endl;
        }

        cout << "After add some data : " << endl;
        cInstance.printConfigMapValues();
        cInstance.modifyConfigValue("Tom", "Walking on the streat.");
        cout << "After modify the \"Tom\" value : " << endl;
        cInstance.printConfigMapValues();
        cInstance.removeConfigValueByKey("Aka");
        cout << "After remove the \"Aka\" value : " << endl;
        cInstance.printConfigMapValues();
        cInstance.removeConfigValueByKey("Tom");
        cout << "After remove the \"Tom\" value : " << endl;
        cInstance.printConfigMapValues();
        cInstance.removeFirstConfigValueByValue("Reading books.");
        cout << "After remove the \"Reading books.\" value : " << endl;
        cInstance.printConfigMapValues();
    }
}
