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
 * @brief This file is an example for FactoryMethod design pattern.
 * codec.
 * @file main.cpp
 * @author Tom Zhao(18872770445@163.com)
 * @since 2023-04-18
 * @date Created: 2023-04-18
 * @date Last modified: 2023-04-18
 *
 * Github: @link https://github.com/zty950323/UsingSTLCases @endlink
 * Homepage: @link https://blog.csdn.net/zhaotianyu950323 @endlink
 * Blog: @link https://www.zhihu.com/people/Tom_Zhao @endlink
 * Related and Source link : @link https://refactoringguru.cn/design-patterns/factory-method/cpp/example @endlink
 * Notes : This code is just form the website and as a example for someone just like me to read.
 */

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

/**
 * The Product interface declares the operations that all concrete products must
 * implement.
 */

class Product
{
public:
    virtual ~Product() {}
    virtual string Operation() const = 0;
};

/**
 * Concrete Products provide various implementations of the Product interface.
 */
class ConcreteProduct1 : public Product
{
public:
    string Operation() const override
    {
        return "{Result of the ConcreteProduct1}";
    }
};
class ConcreteProduct2 : public Product
{
public:
    string Operation() const override
    {
        return "{Result of the ConcreteProduct2}";
    }
};

/**
 * The Creator class declares the factory method that is supposed to return an
 * object of a Product class. The Creator's subclasses usually provide the
 * implementation of this method.
 */
class Creator
{
    /**
     * Note that the Creator may also provide some default implementation of the
     * factory method.
     */
public:
    virtual ~Creator() {};
    virtual Product* FactoryMethod() const = 0;

    /**
     * Also note that, despite its name, the Creator's primary responsibility is
     * not creating products. Usually, it contains some core business logic that
     * relies on Product objects, returned by the factory method. Subclasses can
     * indirectly change that business logic by overriding the factory method and
     * returning a different type of product from it.
     */

    string SomeOperation() const
    {
        // Call the factory method to create a Product object.
        Product* product = this->FactoryMethod();
        // Now, use the product.
        string result = "Creator: The same creator's code has just worked with " + product->Operation();
        delete product;
        return result;
    }
};

/**
 * Concrete Creators override the factory method in order to change the
 * resulting product's type.
 */
class ConcreteCreator1 : public Creator
{
    /**
     * Note that the signature of the method still uses the abstract product type,
     * even though the concrete product is actually returned from the method. This
     * way the Creator can stay independent of concrete product classes.
     */
public:
    Product* FactoryMethod() const override
    {
        return new ConcreteProduct1();
    }
};

class ConcreteCreator2 : public Creator
{
public:
    Product* FactoryMethod() const override
    {
        return new ConcreteProduct2();
    }
};

/**
 * The client code works with an instance of a concrete creator, albeit through
 * its base interface. As long as the client keeps working with the creator via
 * the base interface, you can pass it any creator's subclass.
 */
void ClientCode(const Creator& creator)
{
    // ...
    cout << "Client: I'm not aware of the creator's class, but it still works.\n"
        << creator.SomeOperation() << endl;
    // ...
}

/**
 * The Application picks a creator's type depending on the configuration or
 * environment.
 */
void websiteOfficalExample()
{
    cout << "App: Launched with the ConcreteCreator1.\n";
    Creator* creator = new ConcreteCreator1();
    ClientCode(*creator);
    cout << endl;
    cout << "App: Launched with the ConcreteCreator2.\n";
    Creator* creator2 = new ConcreteCreator2();
    ClientCode(*creator2);

    delete creator;
    delete creator2;
}

int main()
{
    websiteOfficalExample();
    return 0;
}
