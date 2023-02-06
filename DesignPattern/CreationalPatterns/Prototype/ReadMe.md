# 原型模式(Prototype)

## 概述(Overview)

&#x20;   本文主要用来记录从网上找到的设计模式中，关于原型模式的一个学习和构建业务示例的代码的流程，供各位交流。

&#x20;   This article is mainly used to record the design patterns found on the Internet, a study of the prototype pattern and the process of building the code of the business example, for your exchange.

## 参考链接(reference linking)

[原型设计模式 (refactoringguru.cn)](https://refactoringguru.cn/design-patterns/prototype)

[Prototype (refactoring.guru)](https://refactoring.guru/design-patterns/prototype)

[UsingSTLCases/DesignPattern/CreationalPatterns/Prototype at main · zty950323/UsingSTLCases (github.com)](https://github.com/zty950323/UsingSTLCases/tree/main/DesignPattern/CreationalPatterns/Prototype)

## 代码实现(code implementation)

### 伪代码(pseudocode)

```cpp
// 基础原型。
// Base prototype.
abstract class Shape is
    field X: int	// 基本字段(Base type)
    field Y: int	// 基本字段(Base type)
    field color: string 	// 基本字段(Base type)

    // 常规构造函数。
	// A regular constructor.
    constructor Shape() is
        // ……

    // 原型构造函数。使用已有对象的数值来初始化一个新对象。
    // The prototype constructor. A fresh object is initialized
    // with values from the existing object.
    constructor Shape(source : Shape) is
        this()
        this.X = source.X
        this.Y = source.Y
        this.color = source.color
	// 上述过程整体类似 cpp 的拷贝构造函数需要达到的功能。
	// All of this is similar to what the copy constructor of cpp needs to do.

    // clone（克隆）操作会返回一个形状子类。
	// The clone operation returns one of the Shape subclasses.
    abstract method clone() : Shape


// 具体原型。克隆方法会创建一个新对象并将其传递给构造函数。直到构造函数运
// 行完成前，它都拥有指向新克隆对象的引用。因此，任何人都无法访问未完全生
// 成的克隆对象。这可以保持克隆结果的一致。
// Concrete prototype. The cloning method creates a new object
// in one go by calling the constructor of the current class and
// passing the current object as the constructor's argument.
// Performing all the actual copying in the constructor helps to
// keep the result consistent: the constructor will not return a
// result until the new object is fully built; thus, no object
// can have a reference to a partially-built clone.
class Rectangle extends Shape is
    field width: int
    field height: int

    constructor Rectangle(source: Rectangle) is
        // 需要调用父构造函数来复制父类中定义的私有成员变量。
        // A parent constructor call is needed to copy private
        // fields defined in the parent class.
        super(source)
        this.width = source.width
        this.height = source.height

    method clone():Shape is
        return new Rectangle(this)


class Circle extends Shape is
    field radius: int

    constructor Circle(source: Circle) is
        super(source)
        this.radius = source.radius

    method clone():Shape is
        return new Circle(this)


// 客户端代码中的某个位置。
// Somewhere in the client code.
class Application is
    field shapes: array of Shape

    constructor Application() is
        Circle circle = new Circle()
        circle.X = 10
        circle.Y = 10
        circle.radius = 20
        shapes.add(circle)

        Circle anotherCircle = circle.clone()
        shapes.add(anotherCircle)
        // 变量 `anotherCircle（另一个圆）`与 `circle（圆）`对象的内
        // 容完全一样。
        // The `anotherCircle` variable contains an exact copy
        // of the `circle` object.

        Rectangle rectangle = new Rectangle()
        rectangle.width = 10
        rectangle.height = 20
        shapes.add(rectangle)

    method businessLogic() is
        // 原型是很强大的东西，因为它能在不知晓对象类型的情况下生成一个与
        // 其完全相同的复制品。
        // Prototype rocks because it lets you produce a copy of
        // an object without knowing anything about its type.
        Array shapesCopy = new Array of Shapes.

        // 例如，我们不知晓形状数组中元素的具体类型，只知道它们都是形状。
        // 但在多态机制的帮助下，当我们在某个形状上调用 `clone（克隆）`
        // 方法时，程序会检查其所属的类并调用其中所定义的克隆方法。这样，
        // 我们将获得一个正确的复制品，而不是一组简单的形状对象。
        // For instance, we don't know the exact elements in the
        // shapes array. All we know is that they are all
        // shapes. But thanks to polymorphism, when we call the
        // `clone` method on a shape the program checks its real
        // class and runs the appropriate clone method defined
        // in that class. That's why we get proper clones
        // instead of a set of simple Shape objects.
        foreach (s in shapes) do
            shapesCopy.add(s.clone())

        // `shapesCopy（形状副本）`数组中包含 `shape（形状）`数组所有
        // 子元素的复制品。
        // The `shapesCopy` array contains exact copies of the
        // `shape` array's children.
```

接下来的代码示例，说明了**原型**设计模式的结构并重点回答了下面的问题：

*   它由哪些类组成？
*   这些类扮演了哪些角色？
*   模式中的各个元素会以何种方式相互关联？

This example illustrates the structure of the **Prototype** design pattern. It focuses on answering these questions:

*   What classes does it consist of?
*   What roles do these classes play?
*   In what way the elements of the pattern are related?

### 概要示例 (Summary Example)

```cpp
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
* @file gui_core_object.cpp
* @author Tom Zhao(18872770445@163.com)
* @since 2023-01-31
* @date Created: 2023-01-31
* @date Last modified: 2023-01-31
*
* Github: @link https://github.com/zty950323/UsingSTLCases @endlink
* Homepage: @link https://blog.csdn.net/zhaotianyu950323 @endlink
* Blog: @link https://www.zhihu.com/people/Tom_Zhao @endlink
*/

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
    system("pause");
    return 0;
}

```

### 简单业务示例 (Simple business Example)

&#x20;   首先，整体的项目结构图如下：

&#x20;   First, the overall project structure diagram is as follows:

![image](https://note.youdao.com/yws/public/resource/35f4a0030887f160ac7ed57f02828a5e/xmlnote/WEBRESOURCEedbbf102c4a5ddfe9aa8425294887486/37256)

&#x20;   上述主要是一个业务的实例，用一个几何仓库的设计案例来表现原型模式设计的理念，具体代码可以参考如下的网址：

&#x20;   The above is mainly a business example, using a geometric warehouse design case to show the concept of prototype pattern design, the specific code can refer to the following website:

[UsingSTLCases/DesignPattern/CreationalPatterns/Prototype at main · zty950323/UsingSTLCases (github.com)](https://github.com/zty950323/UsingSTLCases/tree/main/DesignPattern/CreationalPatterns/Prototype)

#### CMakeLists.txt

```cmake
#[================================================================[.rst:
    Copyright (c)2023, Tom Zhao personal. ("UsingSTLEx")
    This software is a personal tools project by Tom Zhao.
    Description:
#]================================================================]

set(TZ_MAIN_NAME PrototypeExample)

set(TZ_MAIN_INCLUDE

)

set(TZ_MAIN_INC
    inc/geom_defines.h
    inc/geom_line_seg.h
    inc/geom_line_type_prototype.h
    inc/geom_line.h
    inc/geom_prototype_base.h
	inc/geom_prototype_cases.h
	inc/geom_prototype_factory.h
    inc/geom_ray.h
)

set(TZ_MAIN_SRC
    main.cpp
    src/geom_line_seg.cpp
    src/geom_line_type_prototype.cpp
    src/geom_line.cpp
    src/geom_prototype_base.cpp
	src/geom_prototype_cases.cpp
	src/geom_prototype_factory.cpp
    src/geom_ray.cpp
)

set(TZ_INCLUDE_PREFIX
    inc
)

include_directories(${TZ_INCLUDE_PREFIX})

add_executable(${TZ_MAIN_NAME}
    ${TZ_MAIN_INCLUDE}
    ${TZ_MAIN_INC}
    ${TZ_MAIN_SRC}
)

set_property(TARGET ${TZ_MAIN_NAME} PROPERTY FOLDER "CreationalPatterns")
```

#### geom\_defines.h

```cpp
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
* @brief This file records some defines data struct about this project.
* @file geom_defines.h
* @author Tom Zhao(18872770445@163.com)
* @since 2023-02-01
* @date Created: 2023-02-01
* @date Last modified: 2023-02-01
*
* Github: @link https://github.com/zty950323/UsingSTLCases @endlink
* Homepage: @link https://blog.csdn.net/zhaotianyu950323 @endlink
* Blog: @link https://www.zhihu.com/people/Tom_Zhao @endlink
*/

#ifndef _GEOM_DEFINES_H_H_
#define _GEOM_DEFINES_H_H_

#include <string>

namespace GeomPrototype
{
    const std::string NAME_PRINT_STR = std::string("The name is : ");
    const std::string TYPE_PRINT_STR = std::string(" And the Type value is : ");
    const std::string START_POINT_STR = std::string(" And the start point is : ");
    const std::string DIRECTION_POINT_STR = std::string(" And The direction point is :");
    const std::string END_POINT_STR = std::string(" And The end point is :");

    struct GeomPoint3d
    {
        double x = 0.0;
        double y = 0.0;
        double z = 0.0;

        inline bool operator == (const GeomPoint3d& other) {
            return x == other.x && y == other.y && z == other.z;
        }
    };
}  // namespace GeomPrototype

#endif  // _GEOM_DEFINES_H_H_

```

#### geom\_prototype\_base.h

```cpp
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

```

#### geom\_prototype\_base.cpp

```cpp
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
* @file geom_prototype_base.cpp
* @author Tom Zhao(18872770445@163.com)
* @since 2023-02-01
* @date Created: 2023-02-01
* @date Last modified: 2023-02-01
*
* Github: @link https://github.com/zty950323/UsingSTLCases @endlink
* Homepage: @link https://blog.csdn.net/zhaotianyu950323 @endlink
* Blog: @link https://www.zhihu.com/people/Tom_Zhao @endlink
*/

#include "geom_prototype_base.h"
#include "geom_defines.h"

#include <iostream>

using std::string;
using std::cout;
using std::endl;

namespace GeomPrototype
{
    GeomPrototypeBase::GeomPrototypeBase()
        : m_name(string()), m_geomType(GeomType::kBase)
    {
    }

    GeomPrototypeBase::GeomPrototypeBase(const string& name, GeomType type)
        : m_name(name), m_geomType(type)
    {
    }

    GeomPrototypeBase::~GeomPrototypeBase()
    {
    }

    void GeomPrototypeBase::showInfomation() const
    {
        cout << NAME_PRINT_STR << m_name <<
            TYPE_PRINT_STR << static_cast<unsigned int>(m_geomType) << endl;
    }

    const string& GeomPrototypeBase::name() const
    {
        return m_name;
    }

    bool GeomPrototypeBase::setName(const string& name)
    {
        if (name == m_name) {
            return false;
        }

        m_name = name;
        return true;
    }

    GeomType GeomPrototypeBase::type() const
    {
        return m_geomType;
    }

    bool GeomPrototypeBase::isValid() const
    {
        if (m_name.empty() ||
            m_geomType == GeomType::kBase ||
            m_geomType == GeomType::kNone) {
            return false;
        }

        return true;
    }
}  // namespace GeomPrototype

```

#### geom\_line\_prototype.h

```cpp
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

```

#### geom\_line\_prototype.cpp

```cpp
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
* @file geom_line_prototype.cpp
* @author Tom Zhao(18872770445@163.com)
* @since 2023-02-01
* @date Created: 2023-02-01
* @date Last modified: 2023-02-01
*
* Github: @link https://github.com/zty950323/UsingSTLCases @endlink
* Homepage: @link https://blog.csdn.net/zhaotianyu950323 @endlink
* Blog: @link https://www.zhihu.com/people/Tom_Zhao @endlink
*/

#include "geom_line_type_prototype.h"

#include <iostream>

using std::string;
using std::cout;
using std::endl;

namespace GeomPrototype
{
    GeomLinePrototype::GeomLinePrototype()
        : GeomPrototypeBase(),
        m_bClosed(false),
        m_b3DLine(false)
    {
    }

    GeomLinePrototype::GeomLinePrototype(const string& name, GeomType type)
        : GeomPrototypeBase(name, type),
        m_bClosed(false),
        m_b3DLine(false)
    {
    }

    GeomLinePrototype::~GeomLinePrototype()
    {
    }

    GeomPrototypeBase* GeomLinePrototype::clone() const
    {
        return new GeomLinePrototype(*this);
    }

    bool GeomLinePrototype::isClosed() const
    {
        return m_bClosed;
    }

    bool GeomLinePrototype::is3DLineEnt() const
    {
        return m_b3DLine;
    }

    const GeomPoint3d& GeomLinePrototype::startPoint() const
    {
        return m_startPoint;
    }

    void GeomLinePrototype::showInfomation() const
    {
        cout << NAME_PRINT_STR << m_name <<
            TYPE_PRINT_STR << static_cast<unsigned int>(m_geomType)
            << START_POINT_STR << '\t' << m_startPoint.x << ','
            << m_startPoint.y << ','  << m_startPoint.z << endl;
    }

    bool GeomLinePrototype::moveTo(const GeomPoint3d& aimPoint)
    {
        if (m_startPoint == aimPoint) {
            return false;
        }

        m_startPoint = aimPoint;
        return true;
    }
}  // namespace GeomPrototype

```

#### geom\_line.h

```cpp
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
* @brief This file is an class for example for prototype case line.
* @file geom_line.h
* @author Tom Zhao(18872770445@163.com)
* @since 2023-02-01
* @date Created: 2023-02-01
* @date Last modified: 2023-02-01
*
* Github: @link https://github.com/zty950323/UsingSTLCases @endlink
* Homepage: @link https://blog.csdn.net/zhaotianyu950323 @endlink
* Blog: @link https://www.zhihu.com/people/Tom_Zhao @endlink
*/

#ifndef _GEOM_LINE_H_H_
#define _GEOM_LINE_H_H_

#include "geom_line_type_prototype.h"

namespace GeomPrototype
{
    class GeomLine final : public GeomLinePrototype
    {
    public:
        GeomLine();
        GeomLine(const std::string& name, GeomType type = GeomType::kLine);

        ~GeomLine() override;
        GeomPrototypeBase* clone() const override;
        void showInfomation() const override;

        const GeomPoint3d& directionPoint() const;
        bool setDirectionPoint(const GeomPoint3d& aimDirection);

    private:
        GeomPoint3d m_directionPoint;
    };
}  // namespace GeomPrototype

#endif  // _GEOM_LINE_H_H_

```

#### geom\_line.cpp

```cpp
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
* @brief This file is an class for example for prototype case line.
* @file geom_line.cpp
* @author Tom Zhao(18872770445@163.com)
* @since 2023-02-01
* @date Created: 2023-02-01
* @date Last modified: 2023-02-01
*
* Github: @link https://github.com/zty950323/UsingSTLCases @endlink
* Homepage: @link https://blog.csdn.net/zhaotianyu950323 @endlink
* Blog: @link https://www.zhihu.com/people/Tom_Zhao @endlink
*/

#include "geom_line.h"

#include <iostream>

using std::cout;
using std::endl;

namespace GeomPrototype
{
    GeomLine::GeomLine()
        : GeomLinePrototype()
    {
        m_b3DLine = true;
    }

    GeomLine::GeomLine(const std::string& name, GeomType type)
        : GeomLinePrototype(name, type)
    {
        m_b3DLine = true;
    }

    GeomLine::~GeomLine()
    {
    }

    GeomPrototypeBase* GeomLine::clone() const
    {
        return new GeomLine(*this);
    }

    const GeomPoint3d& GeomLine::directionPoint() const
    {
        return m_directionPoint;
    }

    bool GeomLine::setDirectionPoint(const GeomPoint3d& aimDirection)
    {
        if (m_directionPoint == aimDirection) {
            return false;
        }

        m_directionPoint = aimDirection;
        return true;
    }

    void GeomLine::showInfomation() const
    {
        cout << NAME_PRINT_STR << m_name <<
            TYPE_PRINT_STR << static_cast<unsigned int>(m_geomType)
            << START_POINT_STR << '\t' << m_startPoint.x << ','
            << m_startPoint.y << ','  << m_startPoint.z
            << DIRECTION_POINT_STR << '\t' << m_directionPoint.x
            << ',' << m_directionPoint.y << ',' << m_directionPoint.z << endl;
    }
}  // namespace GeomPrototype

```

#### geom\_ray.h

```cpp
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
* @brief This file is an class for example for prototype case ray.
* @file geom_ray.h
* @author Tom Zhao(18872770445@163.com)
* @since 2023-02-01
* @date Created: 2023-02-01
* @date Last modified: 2023-02-01
*
* Github: @link https://github.com/zty950323/UsingSTLCases @endlink
* Homepage: @link https://blog.csdn.net/zhaotianyu950323 @endlink
* Blog: @link https://www.zhihu.com/people/Tom_Zhao @endlink
*/

#ifndef _GEOM_RAY_H_H_
#define _GEOM_RAY_H_H_

#include "geom_line_type_prototype.h"

namespace GeomPrototype
{
    class GeomRay final : public GeomLinePrototype
    {
    public:
        GeomRay();
        GeomRay(const std::string& name, GeomType type = GeomType::kRay);

        ~GeomRay() override;
        GeomPrototypeBase* clone() const override;
        void showInfomation() const override;

        const GeomPoint3d& directionPoint() const;
        bool setDirectionPoint(const GeomPoint3d& aimDirection);

    private:
        GeomPoint3d m_directionPoint;
    };
}  // namespace GeomPrototype

#endif  // _GEOM_LINE_H_H_

```

#### geom\_ray.cpp

```cpp
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
* @brief This file is an class for example for prototype case ray.
* @file geom_ray.cpp
* @author Tom Zhao(18872770445@163.com)
* @since 2023-02-01
* @date Created: 2023-02-01
* @date Last modified: 2023-02-01
*
* Github: @link https://github.com/zty950323/UsingSTLCases @endlink
* Homepage: @link https://blog.csdn.net/zhaotianyu950323 @endlink
* Blog: @link https://www.zhihu.com/people/Tom_Zhao @endlink
*/

#include "geom_ray.h"

#include <iostream>

using std::cout;
using std::endl;

namespace GeomPrototype
{
    GeomRay::GeomRay()
        : GeomLinePrototype()
    {
        m_b3DLine = true;
    }

    GeomRay::GeomRay(const std::string& name, GeomType type)
        : GeomLinePrototype(name, type)
    {
        m_b3DLine = true;
    }

    GeomRay::~GeomRay()
    {
    }

    GeomPrototypeBase* GeomRay::clone() const
    {
        return new GeomRay(*this);
    }

    const GeomPoint3d& GeomRay::directionPoint() const
    {
        return m_directionPoint;
    }

    bool GeomRay::setDirectionPoint(const GeomPoint3d& aimDirection)
    {
        if (m_directionPoint == aimDirection) {
            return false;
        }

        m_directionPoint = aimDirection;
        return true;
    }

    void GeomRay::showInfomation() const
    {
        cout << NAME_PRINT_STR << m_name <<
            TYPE_PRINT_STR << static_cast<unsigned int>(m_geomType)
            << START_POINT_STR << '\t' << m_startPoint.x << ','
            << m_startPoint.y << ','  << m_startPoint.z
            << DIRECTION_POINT_STR << '\t' << m_directionPoint.x
            << ',' << m_directionPoint.y << ',' << m_directionPoint.z << endl;
    }
}  // namespace GeomPrototype

```

#### geom\_line\_seg.h

```cpp
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

```

#### geom\_line\_seg.cpp

```cpp
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
* @brief This file is an class for example for prototype case line.
* @file geom_line.cpp
* @author Tom Zhao(18872770445@163.com)
* @since 2023-02-01
* @date Created: 2023-02-01
* @date Last modified: 2023-02-01
*
* Github: @link https://github.com/zty950323/UsingSTLCases @endlink
* Homepage: @link https://blog.csdn.net/zhaotianyu950323 @endlink
* Blog: @link https://www.zhihu.com/people/Tom_Zhao @endlink
*/

#include "geom_line_seg.h"

#include <iostream>

using std::cout;
using std::endl;

namespace GeomPrototype
{
    GeomLineSeg::GeomLineSeg()
        : GeomLinePrototype()
    {
        m_b3DLine = true;
        m_bClosed = true;
    }

    GeomLineSeg::GeomLineSeg(const std::string& name, GeomType type)
        : GeomLinePrototype(name, type)
    {
        m_b3DLine = true;
        m_bClosed = true;
    }

    GeomLineSeg::~GeomLineSeg()
    {
    }

    GeomPrototypeBase* GeomLineSeg::clone() const
    {
        return new GeomLineSeg(*this);
    }

    const GeomPoint3d& GeomLineSeg::endPoint() const
    {
        return m_endPoint;
    }

    bool GeomLineSeg::setEndPoint(const GeomPoint3d& aimEnd)
    {
        if (m_endPoint == aimEnd) {
            return false;
        }

        m_endPoint = aimEnd;
        return true;
    }

    void GeomLineSeg::showInfomation() const
    {
        cout << NAME_PRINT_STR << m_name <<
            TYPE_PRINT_STR << static_cast<unsigned int>(m_geomType)
            << START_POINT_STR << '\t' << m_startPoint.x << ','
            << m_startPoint.y << ','  << m_startPoint.z
            << END_POINT_STR << '\t' << m_endPoint.x
            << ',' << m_endPoint.y << ',' << m_endPoint.z << endl;
        cout << "This is a closed segment." << endl;
    }
}  // namespace GeomPrototype

```

#### geom\_prototype\_factory.h

```cpp
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
* @brief This file defines a factory for create geom type classes.
* @file geom_prototype_factory.h
* @author Tom Zhao(18872770445@163.com)
* @since 2023-02-01
* @date Created: 2023-02-01
* @date Last modified: 2023-02-01
*
* Github: @link https://github.com/zty950323/UsingSTLCases @endlink
* Homepage: @link https://blog.csdn.net/zhaotianyu950323 @endlink
* Blog: @link https://www.zhihu.com/people/Tom_Zhao @endlink
*/

#ifndef _GEOM_PROTOTYPE_FACTORY_H_H_
#define _GEOM_PROTOTYPE_FACTORY_H_H_

#include "geom_prototype_base.h"

#include <unordered_map>

namespace GeomPrototype
{
    class GeomPrototypeFactory final
    {
    public:
        GeomPrototypeFactory();
        ~GeomPrototypeFactory();

        GeomPrototypeBase* createGeomPrototype(GeomType type);

    private:
        std::unordered_map<GeomType,
            GeomPrototypeBase*, std::hash<int>> m_geomPrototypes;
    };
}  // namespace GeomPrototype

#endif  // _GEOM_PROTOTYPE_FACTORY_H_H_

```

#### geom\_prototype\_factory.cpp

```cpp
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
* @brief This file defines a factory for create geom type classes.
* @file geom_prototype_factory.cpp
* @author Tom Zhao(18872770445@163.com)
* @since 2023-02-01
* @date Created: 2023-02-01
* @date Last modified: 2023-02-01
*
* Github: @link https://github.com/zty950323/UsingSTLCases @endlink
* Homepage: @link https://blog.csdn.net/zhaotianyu950323 @endlink
* Blog: @link https://www.zhihu.com/people/Tom_Zhao @endlink
*/

#include "geom_prototype_factory.h"
#include "geom_line.h"
#include "geom_line_seg.h"
#include "geom_ray.h"

namespace GeomPrototype
{
    GeomPrototypeFactory::GeomPrototypeFactory()
    {
        m_geomPrototypes[GeomType::kLineBase] = new GeomLinePrototype("GeomLinePrototype");
        m_geomPrototypes[GeomType::kLine] = new GeomLine("GeomLine");
        m_geomPrototypes[GeomType::kLineSeg] = new GeomLineSeg("GeomLineSeg");
        m_geomPrototypes[GeomType::kRay] = new GeomRay("GeomRay");
    }

    GeomPrototypeFactory::~GeomPrototypeFactory()
    {
        for (auto& geomPrototype : m_geomPrototypes) {
            auto pPrototype = geomPrototype.second;
            if (pPrototype) {
                delete pPrototype;
                pPrototype = nullptr;
            }
        }
    }

    GeomPrototypeBase* GeomPrototypeFactory::createGeomPrototype(GeomType type)
    {
        auto pPrototype = m_geomPrototypes[type];
        if (pPrototype) {
            return pPrototype->clone();
        }
        return nullptr;
    }
}  // namespace GeomPrototype

```

#### geom\_prototype\_cases.h

```cpp
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
* @brief This file defines a test cases class for this example.
* @file geom_prototype_cases.h
* @author Tom Zhao(18872770445@163.com)
* @since 2023-02-01
* @date Created: 2023-02-01
* @date Last modified: 2023-02-01
*
* Github: @link https://github.com/zty950323/UsingSTLCases @endlink
* Homepage: @link https://blog.csdn.net/zhaotianyu950323 @endlink
* Blog: @link https://www.zhihu.com/people/Tom_Zhao @endlink
*/

#ifndef _GEOM_PROTOTYPE_CASES_H_H_
#define _GEOM_PROTOTYPE_CASES_H_H_

namespace GeomPrototype
{
    class GeomPrototypeTestCases final
    {
    public:
        static void testAllGeomPrototype();
    };
}  // namespace GeomPrototype

#endif  // _GEOM_PROTOTYPE_CASES_H_H_

```

#### geom\_prototype\_cases.cpp

```cpp
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
* @brief This file defines a test cases class for this example.
* @file geom_prototype_cases.cpp
* @author Tom Zhao(18872770445@163.com)
* @since 2023-02-01
* @date Created: 2023-02-01
* @date Last modified: 2023-02-01
*
* Github: @link https://github.com/zty950323/UsingSTLCases @endlink
* Homepage: @link https://blog.csdn.net/zhaotianyu950323 @endlink
* Blog: @link https://www.zhihu.com/people/Tom_Zhao @endlink
*/

#include "geom_prototype_cases.h"
#include "geom_prototype_factory.h"
#include "geom_line_seg.h"

#include <iostream>

using std::cout;
using std::endl;

namespace GeomPrototype
{
    void GeomPrototypeTestCases::testAllGeomPrototype()
    {
        cout << "Let's create some geometry prototype by factory: " << endl;

        GeomPrototypeFactory* pFactory = new GeomPrototypeFactory();
        GeomPrototypeBase* pPrototype = pFactory->createGeomPrototype(GeomType::kLineBase);
        if (pPrototype && pPrototype->isValid()) {
            pPrototype->showInfomation();
            delete pPrototype;
            pPrototype = nullptr;
        }

        pPrototype = pFactory->createGeomPrototype(GeomType::kLine);
        if (pPrototype && pPrototype->isValid()) {
            pPrototype->showInfomation();
            delete pPrototype;
            pPrototype = nullptr;
        }

        pPrototype = pFactory->createGeomPrototype(GeomType::kLineSeg);
        if (pPrototype && pPrototype->isValid()) {
            pPrototype->showInfomation();
            delete pPrototype;
            pPrototype = nullptr;
        }

        pPrototype = pFactory->createGeomPrototype(GeomType::kRay);
        if (pPrototype && pPrototype->isValid()) {
            pPrototype->showInfomation();
            delete pPrototype;
            pPrototype = nullptr;
        }

        pPrototype = pFactory->createGeomPrototype(GeomType::kLineSeg);
        if (pPrototype && pPrototype->isValid()) {
            pPrototype->setName("TestNewLineSegName");
            GeomLineSeg* pLineSeg = static_cast<GeomLineSeg*>(pPrototype);
            if (pLineSeg) {
                pLineSeg->setEndPoint(GeomPoint3d(20.0, 20.0, 20.0));
            }
            pPrototype->showInfomation();
            delete pPrototype;
            pPrototype = nullptr;
        }

        if (pFactory) {
            delete pFactory;
            pFactory = nullptr;
        }

        cout << "The End of the geom factory test case." << endl;
    }
}  // namespace GeomPrototype

```

#### main.cpp

```cpp
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

int main()
{
    GeomPrototype::GeomPrototypeTestCases::testAllGeomPrototype();
    system("pause");
    return 0;
}

```

