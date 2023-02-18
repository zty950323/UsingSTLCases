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
* @brief This file is an example for Singleton design pattern.
* codec.
* @file main.cpp
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

#include <iostream>
#include <string>
#include <thread>
#include <mutex>

using std::cout;
using std::endl;
using std::string;
using std::this_thread::sleep_for;
using std::chrono::milliseconds;
using std::thread;
using std::mutex;
using std::lock_guard;

/**
 * The Singleton class defines the `GetInstance` method that serves as an
 * alternative to constructor and lets clients access the same instance of this
 * class over and over.
 */
class Singleton
{
    /**
     * The Singleton's constructor should always be private to prevent direct
     * construction calls with the `new` operator.
     */
protected:
    Singleton(const std::string value)
        : m_value(value)
    {
    }

    /**
     * Singletons should not be cloneable.
     */
    Singleton(Singleton& other) = delete;

    /**
     * Singletons should not be assignable.
     */
    void operator=(const Singleton&) = delete;

protected:
    static Singleton* m_pInstance;

    std::string m_value;

public:
    /**
     * This is the static method that controls the access to the pSingleton
     * instance. On the first run, it creates a pSingleton object and places it
     * into the static field. On subsequent runs, it returns the client existing
     * object stored in the static field.
     */

    static Singleton* getInstance(const string& value);

    /**
     * Finally, any pSingleton should define some business logic, which can be
     * executed on its instance.
     */
    void someBusinessLogic() {
        // Do some business in here.
        cout << "Singleton Business Function!" << endl;
    }

    const string& value() const {
        return m_value;
    }
};

Singleton* Singleton::m_pInstance = nullptr;

/**
 * Static methods should be defined outside the class.
 */
Singleton* Singleton::getInstance(const string& value)
{
    /**
     * This is a safer way to create an instance. instance = new Singleton is
     * dangeruous in case two instance threads wants to access at the same time
     */
    if (m_pInstance == nullptr) {
        m_pInstance = new Singleton(value);
    }

    return m_pInstance;
}

void threadTestForFoo() {
    // Following code emulates slow initialization.
    sleep_for(milliseconds(1000));
    Singleton* pSingleton = Singleton::getInstance("FOO");
    cout << pSingleton->value() << endl;
}

void threadTestForBar() {
    // Following code emulates slow initialization.
    sleep_for(milliseconds(1000));
    Singleton* pSingleton = Singleton::getInstance("BAR");
    cout << pSingleton->value() << endl;
}

void noThreadSafeTest() {
    cout << "If you see the same value, then pSingleton was reused (yay!\n" <<
        "If you see different values, then 2 singletons were created (booo!!)\n\n" <<
        "RESULT:\n";
    thread t1(threadTestForFoo);
    thread t2(threadTestForBar);
    t1.join();
    t2.join();
}

// The thread safe case:
class ThreadSafeSingleton
{
    /**
     * The Singleton's constructor/destructor should always be private to
     * prevent direct construction/desctruction calls with the `new`/`delete`
     * operator.
     */
private:
    static ThreadSafeSingleton* m_pInstance;
    static mutex m_mutex;

protected:
    ThreadSafeSingleton(const string& value)
        : m_value(value)
    {
    }

    ~ThreadSafeSingleton() {}

    /**
     * Singletons should not be cloneable.
     */
    ThreadSafeSingleton(ThreadSafeSingleton& other) = delete;

    /**
     * Singletons should not be assignable.
     */
    void operator=(const ThreadSafeSingleton&) = delete;

    string m_value;

public:
    /**
     * This is the static method that controls the access to the pSingleton
     * instance. On the first run, it creates a pSingleton object and places it
     * into the static field. On subsequent runs, it returns the client existing
     * object stored in the static field.
     */

    static ThreadSafeSingleton* getInstance(const string& value);

    /**
     * Finally, any pSingleton should define some business logic, which can be
     * executed on its instance.
     */
    void someBusinessLogic() {
        // Do some business in here.
        cout << "Singleton Business Function!" << endl;
    }

    const string& value() const {
        return m_value;
    }
};

ThreadSafeSingleton* ThreadSafeSingleton::m_pInstance{nullptr};
mutex ThreadSafeSingleton::m_mutex;

/**
 * The first time we call getInstance we will lock the storage location
 * and then we make sure again that the variable is null and then we
 * set the value. RU:
 */
ThreadSafeSingleton* ThreadSafeSingleton::getInstance(const string& value)
{
    lock_guard<mutex> lock(m_mutex);
    if (m_pInstance == nullptr) {
        m_pInstance = new ThreadSafeSingleton(value);
    }

    return m_pInstance;
}

void threadSafeTestForFoo() {
    // Following code emulates slow initialization.
    sleep_for(milliseconds(1000));
    Singleton* pSingleton = Singleton::getInstance("FOO");
    cout << pSingleton->value() << endl;
}

void threadSafeTestForBar() {
    // Following code emulates slow initialization.
    sleep_for(milliseconds(1000));
    Singleton* pSingleton = Singleton::getInstance("BAR");
    cout << pSingleton->value() << endl;
}

void threadSafeTest() {
    cout << "If you see the same value, then pSingleton was reused (yay!\n" <<
        "If you see different values, then 2 singletons were created (booo!!)\n\n" <<
        "RESULT:\n";
    thread t1(threadSafeTestForFoo);
    thread t2(threadSafeTestForBar);
    t1.join();
    t2.join();
}

int main()
{
    noThreadSafeTest();
    threadSafeTest();
    Basic::ConfigServiceTest::getInstance().testConfigSingleton();
    system("pause");
    return 0;
}
