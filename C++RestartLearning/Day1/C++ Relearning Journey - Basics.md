# C++ Relearning Journey - Basics

## Chapter 1 - What is C++

1. C++ is an independently developed language, but it is derived from the C language;
2. C++ widely used;
3. C++ core idea is Object Oriented.
4. C++ have strong template and generic programming skills;
5. C++ years of development, continuous iteration, standards are constantly updated.

C++ is a powerful and versatile programming language that can be used for a variety of purposes, such as system programming, application development, game design, and more. C++ was created in 1979 by Bjarne Stroustrup as an extension of C, one of the oldest and most widely used programming languages in the world. However, C++ is not just C with some extra features; it is a unique language with its own syntax, semantics, and paradigms. One of the main features of the C++ is its support for Object Oriented programming, which allows programmers to create reusable and Modularization code using classes and objects. Another feature of the C++ is that it gives programmers direct access to hardware components and system resources, which enables them to write efficient and optimized code. C++ also supports other programming paradigms such as procedural, generic, and function-based programming. C++ has evolved over the years and has been updated with new standards and features. The latest version of the C++ is C++ 20, released in 2020.

C++ is governed by the ISOC ++ standards organization. Here are several ISOC ++ standards listed in chronological order: C++ 03, C++ 11, C++ 14, C++ 17, C++ 20, and the upcoming C++ 23 standards. Each C++ standard since C++ 11 is called "Modern C++", and Modern C++ is what I will focus on on this learning journey.

## Chapter 2 - The First Procedure

### 2.1 main function entrance

First of all, we want to know C++ program, naturally have to start from its most important entry function to know, main function plays a pivotal role in the C++, it can be said that without him, the program can not find a suitable entry, naturally on the follow-up process and smooth operation There is no way to talk about it. So let's first get to know the main function in the C++, refer to the Chapter2_1 in my project code:

```C++
int main()
{
    return 1;
}
```

Function main is the entry point of the main program, the beginning of the program. When we run the executable, the code inside the function body is executed. Function is of type int (and returns the result to the system, but we don't have to worry too much about that yet). The reserved name main is the function name. It is followed by a list of parameters in parentheses (), followed by the function body marked with braces {}. The braces marking the beginning and end of the function body are shown in the case I wrote, preferably on separate lines.

Let's analyze the simple program above. It does nothing. It has no parameters listed in parentheses, and there are no other statements inside the function body except to return the necessary return value. Understanding that this is the main program signature is essential. Of course, friends familiar with C++ must know that there is another main function signature that accepts two different parameters for manipulating command line parameters. For now, we will only use the first form, and we will introduce the other form later.

### 2.2 Program Notes

We can use the C++ process, add some comments, let yourself and more people read your code, understand what you write this code logic, reason and goal, good comments, sometimes more important than writing code quickly.

1. Single-line comments in C++ start with a double slash//and the compiler ignores them. We use them to comment or record code or use them as comments.
2. C++ we can also use multi-line comments, and the compiler will still ignore them. They can be maintained with//at the beginning of a line, or with/**/in pairs.

Then, please look at the program case, specifically refer to the Chapter2_2 in my project code:

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

It can be seen that in the above example program, I used a large paragraph of comments to introduce myself and introduce the vision of my code. The trick used here is multi-line comments, and then on line 25, I used a single-line comment after the main function to describe that this is the entry point of a program. Of course, after you understand the use of comments, you can also try it yourself. For example, you can implement the coding of the following homework exercise by yourself:

1. Exercise 1: Please write your own main function program, and only use a single line of comments to write a self-introduction after the main function;
2. Exercise 2: Please write a main function program with multiple lines of comments, and write a short story about your learning goals in the multi-line comments using asterisk comments;
3. Exercise 3: Please write a main function program with multiple lines of comments, and use multiple lines of double//comments in the multi-line comments to write a few C++ why you learn;

The above exercises are all under a framework, and readers are welcome to write and diverge at will.

### 2.3 Hello world program case

Now, we are ready to see our "Hello World" program instance for the first time, which will open the door to learning any programming language, so let's knock on the door to learning C++ programs. The following program is the simplest "Hello World" example. It prints out Hello World and outputs it in the Console window:

```C++
#include <iostream>

int main() {
  std::cout << "Hello, World!";
  return 0;
}
```

"Hello, World!" is a classic programming exercise that is often used to introduce new programmers to the basics of a programming language. The program is simple enough for even a child to understand, but it still teaches some important concepts about how programming works.

The first line, `#include <iostream>`, tells the compiler to include the `iostream` header file. This file contains declarations for the `std::cout` object, which is used to print text to the console.

The second line, `int main()`, defines the `main()` function. This is the function that is called when the program starts running.

The third line, `std::cout << "Hello, World!"`, prints the text "Hello, World!" to the console.

The fourth line, `return 0;`, tells the compiler that the program has finished running successfully.

That's all there is to the C++ hello world program! It's a simple program, but it teaches some important concepts about how programming works. So next time you're feeling bored, why not try writing your own hello world program?"