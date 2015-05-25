#include <stdlib.h>
#include <iostream>
#include <sys/time.h>
#include <unistd.h>

#define MAX(x,y) (((x) > (y)) ? (x) : (y))
#define MIN(x,y) (((x) < (y)) ? (x) : (y))

float ofRandom(float x, float y) {
    // if there is no range, return the value
    if (x == y) return x;
    float high = MAX(x,y);
    float low = MIN(x,y);
    float range = high - low;
    float denominator = RAND_MAX / range;
    float result = rand() / denominator;
    result -= low;
    if(result == high) {
        return ofRandom(x, y);
    } else {
        return result;
    }
}

float ofRandom(float max) {
    return ofRandom(0, max);
}

float ofRandomuf() {
    return ofRandom(+1);
}

void ofRandomufTest() {
  int n = 0;
  while(true){
    for(int i = 0; i < 100000000; i++) {
      float x = ofRandomuf();
      // x is supposed to always be < 1.0
      if(x == 1.0f) {
        printf("ofRandomuf() returned %f after %d calls\n", x, n);
        n = 0;
      } else {
        n++;
      }
    }
  }
}

void ofSeedRandom() {
  struct timeval tv;
  gettimeofday(&tv, 0);
  long int n = (tv.tv_sec ^ tv.tv_usec) ^ getpid();
  srand(n);
}

int main() {
  ofSeedRandom();
  ofRandomufTest();
}
