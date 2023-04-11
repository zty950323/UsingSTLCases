# C++ 重学之旅 —— 基础

## 第一章 - 什么是 C++

1. C++ 是一门独立发展的语言，但其源自于 C 语言；
2. C++ 应用广泛；
3. C++ 核心思想是面向对象；
4. C++ 有强大的模板和泛型编程能力；
5. C++ 多年发展，持续迭代，标准一直在更新。

C++是一种功能强大且用途广泛的编程语言，可用于各种用途，例如系统编程、应用程序开发、游戏设计等。C++由 Bjarne Stroustrup 于 1979 年创建，作为 C 语言的扩展，C 语言是世界上最古老、使用最广泛的编程语言之一。然而，C++不仅仅是具有一些额外功能的 C；它是一种独特的语言，具有自己的语法、语义学和范式。C++的主要特点之一是它支持面向对象的编程，它允许程序员使用类和对象创建可重用和模块化的代码。C++的另一个特点是它使程序员能够直接访问硬件组件和系统资源，这使他们能够编写高效和优化的代码。C++还支持其他编程范式，例如过程式、泛型和函数式编程。C++多年来不断发展，并更新了新的标准和功能。C++的最新版本是 C++20，于 2020 年发布。

C++受 ISOC++标准组织管辖。这里按时间顺序列出了多个 ISOC++标准：C++03、C++11、C++14、C++17、C++20 和即将到来的 C++23 标准。从 C++11 开始的每一个 C++标准都被称为“现代 C++”，现代 C++是我这次学习之旅将要重点回忆的内容。

## 第二章 - 第一个程序

### 2.1 main 函数入口

首先，我们想要认识 C++程序，自然得从它最重要的入口函数来入手认识，main 函数在 C++中举足轻重，可以说没有他，程序运行就找不到合适的入口，自然就后续的流程和顺利的运行就无从谈起了。那么我们首先先来认识一下 C++中的 main 函数吧， 具体参考我项目代码里的 Chapter2_1：

```C++
int main()
{
    return 1;
}
```

函数 main 是主程序切入点，是程序的开始。当我们运行可执行文件时，函数主体内的代码就会被执行。函数是 int 类型的（并向系统返回结果，但我们现在还不用过多操心这个）。保留名称 main 是函数名。它后面是括号（）内的参数列表，后面是用大括号{}标记的函数体。标记函数体开始和结束的大括号如我写的案例所示，最好是可以在单独的行上。

我们来分析上面这个这个简单的程序什么都不做，它没有括号内列出的参数，函数体内部除了返回必要的返回值也没有其他语句。理解这是主程序签名是必不可少的。当然，熟悉 C++的朋友肯定知道，还有另一个 main 函数签名接受两个不同的参数，用于操作命令行参数。目前，我们将只使用第一种形式，另外一种形式我们后续再介绍。

### 2.2 程序注释

我们可以在 C++的使用过程中，添加一些注释，让自己和更多的阅读你代码的人，理解你写这段代码的逻辑、原因和目标是什么，好的注释，有时候比快速写代码更重要哦。

1. C++中的单行注释以双斜杠 // 开头，编译器会忽略它们。我们使用它们来注释或记录代码或将它们用作注释。
2. C++中我们还可以使用多行注释，同理编译器依旧会忽略他们，他们可以用 // 分别在某一行开头，也可以用成对出现的 /**/ 来进行维护。

那么，接下来请看程序案例，具体参考我项目代码里的 Chapter2_2 ：

```C++
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
 * @brief This file provide an main funcation show case.
 * @file main.cpp
 * @author Tom Zhao(18872770445@163.com)
 * @since 2023-04-11
 * @date Created: 2023-04-11
 * @date Last modified: 2023-04-11
 *
 * Github: @link https://github.com/zty950323/UsingSTLCases @endlink
 * Homepage: @link https://blog.csdn.net/zhaotianyu950323 @endlink
 * Blog: @link https://www.zhihu.com/people/Tom_Zhao @endlink
 */

int main()  // This is a single line comment : this is a main function entry
{
    /*
     * Comments by Tom Zhao
     * @brief English
     * This is a multi-line annotation demo where you hopefully learn to enter a series of prompts.
     *
     * @brief Chinese
     * 这是一个多行注释的演示，希望你能在其中学习输入一系列提示性内容。
     */
    return 1;
    // This is the first line for multi lines comments.
    // This is another line for multi lines comments. So Can you write your own comments?
}
```

可见，在上述例子程序里面，我采用了大段的注释用来介绍自己，介绍自己的代码的愿景。这里用到的技巧就是多行注释，然后在第 25 行，我在 main 函数后面采用了单行注释进行了叙述说这是一个程序的入口。当然你理解了注释的使用技巧后，也可以尝试自己动手试试，例如可以自己动手实现下面作业练习的编码：

1. 习题 1：请编写一份自己的 main 函数程序，并且只使用单行注释给 main 函数后面写一句自我介绍；
2. 习题 2：请编写一份多行注释的 main 函数程序，并在多行注释里使用星号注释的方式写一段关于自己的学习目标的小故事；
3. 习题 3：请编写一份多行注释的 main 函数程序，并在多行注释里使用多行双 // 的注释的方式写几个自己为什么学习 C++；

上述习题都是在一个框架下，欢迎读者自行编写随意发散。

### 2.3 Hello world 程序案例

就是现在，我们已经准备好第一次看到我们的“Hello World”程序实例了，这将会是我们打开任何一门程序语言学习的大门，那么就让我们敲开 C++程序学习的大门吧。以下程序是最简单的“Hello World”示例。它打印出 Hello World 并在控制台窗口中输出：

```C++
#include <iostream>

int main() {
  std::cout << "Hello, World!";
  return 0;
}
```

"Hello, World!" 是一个经典的编程练习，通常用于向新程序员介绍编程语言的基础知识。该程序足够简单，即使是孩子也能理解，但它仍然教授一些关于编程如何工作的重要概念。

- 第 1 行中，`#include <iostream>`，告诉编译器包含 iostream 头文件。该文件包含`std::cout`对象的声明，该对象用于将文本打印到控制台。
- 第 3 行中，`int main()`，定义 `main()` 函数。
- 第 4 行中，`std::cout << "Hello， World！"`，将文本`"Hello，World！"`打印到控制台。
- `第五行中，return 0;`，告知编译器，本程序运行成功了。

这就是 `C++ hello world` 程序的全部内容！这是一个简单的程序，但它教授了一些关于编程如何工作的重要概念。所以下次你感到无聊的时候，为什么不尝试编写自己的 `hello world` 程序呢？"