#include <stdlib.h>
#include <iostream>
#include <sys/time.h>
#include <unistd.h>

#define MAX(x,y) (((x) > (y)) ? (x) : (y))
#define MIN(x,y) (((x) < (y)) ? (x) : (y))

float ofRandom(float x, float y) {
  if (x == y) return x;
  float high = MAX(x, y);
  float low = MIN(x, y);
  float range = high - low;
  range -= std::numeric_limits<float>::epsilon();
  float denominator = RAND_MAX / range;
  float result = rand() / denominator;
  result += low;
  return result;
}

float ofRandom(float max) {
  return ofRandom(0.0f, max);
}

float ofRandomf() {
  return ofRandom(-1.0f, 1.0f);
}

float ofRandomuf() {
  return ofRandom(1.0f);
}

void ofRandomufTest() {
  int n = 0;
  while(true){
    for(int i = 0; i < 100000000; i++) {
      float x = ofRandomuf();
      // x is supposed to always be <
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
