# Hack to ofRandom()

OK, so kyle suggests [it is not floating point accuracy, but the accuracy of the division][3], and proposes a simple fix, mainly that we check if the result returned is equal to max, and if it is, return a new random number. The likelihood of two random numbers in a row both 1.0 (in the case of ofRandomuf()) is super low, so we probably only will recurse one level.

Relevant change is:

```c++
if(result == high) {
    return ofRandom(x, y);
} else {
    return result;
}
```

and you can run and observe this in **ofMathHack.cpp** `g++ ofMathHack.cpp -o hack && ./hack`.

![recursion solves everything](recurse.png)

This time, you will have to press control+c to kill the program - it works!

Case solved, right?

Maybe... but 2bit is not satisfied. It is a band-aid fix. In his heart, he knows there should be a correct way to always return a random floating point value between min and max, excluding max, without having to re-run ofRandom(min, max). Maybe there are other reasons not to go with the recursive solution (if you can think of any, please comment!).

So the saga continues, as arturoc enters the scene...

# Next

To move onto the next step, do `git checkout openframeworks-is-beta`

# Overview

This repository contains source code and commentary explored in [openFrameworks][1] [pull request #3842][2].

From the sidelines, it was really interesting to follow along the discussion about floating point numbers, and randomness.

I am trying to figure out the best way to expose the code for learning. If you have suggestions, please make an issue on github!

After cloning this repository, I recommend checking out the first commit `git checkout initial`, and then moving up one commit at a time.

This readme will change, explaining the different approaches taken on the quest for a ofRandom that works well.


[1]: http://openframeworks.cc
[2]: https://github.com/openframeworks/openFrameworks/pull/3842
[3]: https://github.com/openframeworks/openFrameworks/pull/3842#issuecomment-103756747
