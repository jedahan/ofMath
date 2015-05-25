# Numbers and Computers

Integers are the whole numbers we know and love - 0, 1, 2, 3, 4.... these numbers are easy to represent in computer memory. Most computers these days are '64 bit' so we can count in a single int from 0 all the way up to 2^64 -1, and every whole number between.

However, we would be really limited in expression if we could only use integers when programming.

Another set of numbers that are super useful are [Real Numbers "](https://en.wikipedia.org/wiki/Real_number). Real numbers let us represent fractional distances, which are especially useful in a creative coding framework like openFrameworks. Numbers between 0 and 1 ( 0.5, 0.99, 0.1415161718...) are beautiful, and very useful for scaling, animation, reasoning about behaviour, and a whole bunch of other things.

However, there is a problem with representing and range of real numbers - real numbers can be infinitely long! And our computer only has 64 bits to work with!

So, what to do? There is a standard, [IEEE754: Floating point for Modern Computers](https://en.wikipedia.org/wiki/Floating_point) , that defines how to map 2^64 different numbers to a RANGE of real numbers. The smaller the range, the more precise we can be. The larger the range, the more "holes" in what numbers we can represent. A fun bit of code to show when this hole gives an issue:

```c++
#include <iostream>

int main() {
  float a = 0.1;
  float b = 0.2;
  if(a + b == 0.3){
    printf("nothing to see here...\n");
  } else {
    printf("what. is. going. on. whyyyyyyyy.\n");
  }
}
```

You can guess what the output is:

![math is hard](output.png)


## Learning Floating Point with GDB

Inspired by Alan O'Donnell's [Learning C with GDB](https://www.recurse.com/blog/5-learning-c-with-gdb#footnote_p5f1),
(thank you so much Alan!), let's look at what a and b REALLY are :)

Note: if you are on osx, you may have to do a silly dance to get gdb working. After installing via `brew install gdb`, I followed the
steps [outlined here](http://wiki.lazarus.freepascal.org/GDB_on_OS_X_Mavericks_and_Xcode_5#Codesigning_gdb)

    g++ -g ofMath.cpp && gdb a.out
    GNU gdb (GDB) 7.9
    ...snip...
    (gdb) break main
    Breakpoint 1 at 0x100000ec7: file ofMath.cpp, line 4
    (gdb) run
    ...snip...
    Breakpoint 1, main () at ofMath.cpp:4
    4      float a = 0.1;
    (gdb) next
    5      float b = 0.2;
    (gdb) print a
    $1 = 0.100000001
    (gdb) next
    6      if(a + b == 0.3){
    (gdb) print b
    $2 = 0.200000003
    (gdb) print 0.1 + 0.2
    $3 = 0.29999999999999993


Welp! That was fun! I recommend looking at the byte representation and learning about IEEE754, and if there is something neat or informative please send a pull request!

So now that we know maybe why x can equal x + 1, let's get back to the original pull request : making it so that ofRandomuf() returns floating point numbers over and including 0 but less than 1.

# Next

To move onto the next step, do `git checkout first-fix`

# Overview

This repository contains source code and commentary explored in [openFrameworks][1] [pull request #3842][2].

From the sidelines, it was really interesting to follow along the discussion about floating point numbers, and randomness.

I am trying to figure out the best way to expose the code for learning. If you have suggestions, please make an issue on github!

After cloning this repository, I recommend checking out the first commit `git checkout initial`, and then moving up one commit at a time.

This readme will change, explaining the different approaches taken on the quest for a ofRandom that works well.


[1]: http://openframeworks.cc
[2]: https://github.com/openframeworks/openFrameworks/pull/3842
