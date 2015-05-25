# OpenFrameworks is beta

So arturo proposes another, complete fix: changing the return type from float to double, like so

```c++
double ofRandomuf() {
    return rand() / double(RAND_MAX + 1.0);
}
```

Seems logical. But Kyle defeats this idea with a crafty test case that implies that arturo's fix really 
just will push the bug onto the users when they try and access the double as a float (**ofMath.cpp**):

```c++
#include <iostream>
int main() {
  double asDouble = RAND_MAX / double(RAND_MAX + 1.0);
  if(asDouble==1.0) printf("double equals 1.0\n");
  if(asDouble==1.0f) printf("double equals 1.0f\n");
  // lets make it a float!
  float asSingle = asDouble;
  if(asSingle==1.0) printf("float equals 1.0\n");
  if(asSingle==1.0f) printf("float equals 1.0f\n");
}
```

Testing this with `g++ ofMath.cpp -o double && ./double` exposes the fragility of floating point, once again.

![double](double.png)

A smaller issue is that changing the api is not very nice, even for a pre-1.0 system like openFrameworks. So a new approach needs to be taken.

# Next

To move onto the next step, do `git checkout adventures-with-epsilon`

# Overview

This repository contains source code and commentary explored in [openFrameworks][1] [pull request #3842][2].

From the sidelines, it was really interesting to follow along the discussion about floating point numbers, and randomness.

I am trying to figure out the best way to expose the code for learning. If you have suggestions, please make an issue on github!

After cloning this repository, I recommend checking out the first commit `git checkout initial`, and then moving up one commit at a time.

This readme will change, explaining the different approaches taken on the quest for a ofRandom that works well.


[1]: http://openframeworks.cc
[2]: https://github.com/openframeworks/openFrameworks/pull/3842
[3]: https://github.com/openframeworks/openFrameworks/pull/3842#issuecomment-103756747
