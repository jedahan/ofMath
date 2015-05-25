# The Problem

About one week ago, [2bit](https://github.com/2bbb) proposed a small patch for the implementation of the random number generator for [openFrameworks](https://openframeworks.cc):

[pull request #3482](https://github.com/2bbb/openFrameworks/commit/24a300ad3fe6a6594b2e3754f76a4e96ea2086d9)

2bit had discovered that sometimes ofRandomuf returns 1.0, when the documentation says it should always return a positive number less than 1.0

Even more interesting than the issue of incorrect range, is the source of the problem.

On some platforms, like osx and linux, where RAND_MAX is very high, RAND_MAX is equal to RAND_MAX + 1.0f!

Let me repeat, because that sound should raise some alarm bells...

*   RAND_MAX == RAND_MAX + 1.0f

put another way

*   X == X+1

How could this even happen? I don't believe it, and neither should you! Let's see if your OS is susceptable, by compiling and running ofMath.cpp, which looks like this:

```c++
    #include <iostream>

    int main() {
      if(RAND_MAX == RAND_MAX + 1.0f) {
        printf("omg all of math is wrong\n");
      } else {
        printf("phew we are safe...for now\n");
      }
    }
```

In no sane world, would we ever see anything besides "phew we are safe...".

![omg all math is wrong](output.png)

So I guess my laptop is no sane world, and maybe yours is crazy too

If this is true, a whole bunch of stuff is broken. So let's talk about computer numbers to understand why this happens

# Next

To move onto the next step, do `git checkout floating-point-is-hard`

# Overview

This repository contains source code and commentary explored in [openFrameworks][1] [pull request #3842][2].

From the sidelines, it was really interesting to follow along the discussion about floating point numbers, and randomness.

I am trying to figure out the best way to expose the code for learning. If you have suggestions, please make an issue on github!

After cloning this repository, I recommend checking out the first commit `git checkout initial`, and then moving up one commit at a time.

This readme will change, explaining the different approaches taken on the quest for a ofRandom that works well.


[1]: http://openframeworks.cc
[2]: https://github.com/openframeworks/openFrameworks/pull/3842
