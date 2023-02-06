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
* @brief This file is an example for Prototype design pattern.
* codec.
* @file main.cpp
* @author Tom Zhao(18872770445@163.com)
* @since 2023-01-31
* @date Created: 2023-01-31
* @date Last modified: 2023-01-31
*
* Github: @link https://github.com/zty950323/UsingSTLCases @endlink
* Homepage: @link https://blog.csdn.net/zhaotianyu950323 @endlink
* Blog: @link https://www.zhihu.com/people/Tom_Zhao @endlink
*/

#include "geom_prototype_cases.h"

#include <iostream>
#include <string>
#include <unordered_map>

using std::cout;
using std::endl;
using std::string;
using std::unordered_map;
using std::hash;

/* Prototype Design Pattern
 *
 * Intent: Lets you copy existing objects without making your code dependent on
 * their classes.
 */

enum Type
{
    PROTOTYPE_1 = 0,
    PROTOTYPE_2
};

class Prototype
{
protected:
    string m_name;
    float m_field;

public:
    Prototype()
        : m_name(string()), m_field(0.0) {}
    Prototype(const string& prototypeName)
        : m_name(prototypeName), m_field(0.0) {
    }

    virtual ~Prototype() {}
    virtual Prototype* Clone() const = 0;
    virtual void updateFieldAndPrint(float prototypeField) {
        m_field = prototypeField;
        cout << "Call Method from " << m_name << " with field : " << m_field << endl;
    }
};

/**
 * ConcretePrototype1 is a Sub-Class of Prototype and implement the Clone Method
 * In this example all data members of Prototype Class are in the Stack. If you
 * have pointers in your properties for ex: String* name_ , you will need to
 * implement the Copy-Constructor to make sure you have a deep copy from the
 * clone method.
 */

class ConcretePrototype1 final : public Prototype
{
private:
    float m_concreteField;
    double m_specialNum;

public:
    ConcretePrototype1(const string& prototypeName, float concretePrototypeField, double specialNum)
        : Prototype(prototypeName), m_concreteField(concretePrototypeField), m_specialNum(specialNum) {
    }

    /**
     * Notice that Clone method return a Pointer to a new ConcretePrototype1
     * replica. so, the client (who call the clone method) has the responsability
     * to free that memory. I you have smart pointer knowledge you may prefer to
     * use unique_pointer here.
     */
    virtual Prototype* Clone() const override {
        return new ConcretePrototype1(*this);
    }

    virtual void updateFieldAndPrint(float prototypeField) override {
        m_field = prototypeField;
        m_concreteField = prototypeField * 2.0f;
        cout << "Call Method from " << m_name << " with field : "
            << m_field << " with speical num:" << m_specialNum
            << " with concrete field:" << m_concreteField << endl;
    }
};

/**
* ConcretePrototype2 is an another Sub-Class of Prototype and implement the Clone Method
* In this example this class have different datas in it.
*/
class ConcretePrototype2 final : public Prototype {
private:
    float m_concreteField;
    string m_concreteName;

public:
    ConcretePrototype2(const string& prototypeName, float concretePrototypeField, const string& concreteName)
        : Prototype(prototypeName), m_concreteField(concretePrototypeField), m_concreteName(concreteName) {
    }

    virtual Prototype* Clone() const override {
        return new ConcretePrototype2(*this);
    }

    virtual void updateFieldAndPrint(float prototypeField) override {
        m_field = prototypeField;
        m_concreteField = prototypeField * 3.0f;
        cout << "Call Method from " << m_name << " with field : "
            << m_field << " with concrete name:" << m_concreteName
            << " with concrete field:" << m_concreteField << endl;
    }
};

/**
 * In PrototypeFactory you have two concrete prototypes, one for each concrete
 * prototype class, so each time you want to create a bullet , you can use the
 * existing ones and clone those.
 */
class PrototypeFactory final
{
private:
    unordered_map<Type, Prototype*, hash<int>> m_prototypes;

public:
    PrototypeFactory() {
        m_prototypes[Type::PROTOTYPE_1] = new ConcretePrototype1("PROTOTYPE_1 ", 50.f, 50.0);
        m_prototypes[Type::PROTOTYPE_2] = new ConcretePrototype2("PROTOTYPE_2 ", 60.f, string("ProtoType Test Class"));
    }

    /**
     * Be carefull of free all memory allocated. Again, if you have smart pointers
     * knowelege will be better to use it here.
     */

    ~PrototypeFactory() {
        delete m_prototypes[Type::PROTOTYPE_1];
        delete m_prototypes[Type::PROTOTYPE_2];
    }

    /**
     * Notice here that you just need to specify the type of the prototype you
     * want and the method will create from the object with this type.
     */
    Prototype* CreatePrototype(Type type) {
        return m_prototypes[type]->Clone();
    }
};

void Client(PrototypeFactory& prototypeFactory) {
    std::cout << "Let's create a Prototype 1\n";

    Prototype* pPrototype = prototypeFactory.CreatePrototype(Type::PROTOTYPE_1);
    if (pPrototype) {
        pPrototype->updateFieldAndPrint(90.f);
        delete pPrototype;
    }

    cout << "\n";
    cout << "Let's create a Prototype 2 \n";

    pPrototype = prototypeFactory.CreatePrototype(Type::PROTOTYPE_2);
    if (pPrototype) {
        pPrototype->updateFieldAndPrint(10.f);
        delete pPrototype;
    }
}

int main()
{
    PrototypeFactory* pPrototypeFactory = new PrototypeFactory();
    Client(*pPrototypeFactory);
    delete pPrototypeFactory;

    GeomPrototype::GeomPrototypeTestCases::testAllGeomPrototype();

    system("pause");
    return 0;
}
