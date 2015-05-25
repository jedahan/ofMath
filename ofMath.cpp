#include <stdlib.h>
#include <iostream>
#include <sys/time.h>
#include <unistd.h>

#define MAX(x,y) (((x) > (y)) ? (x) : (y))
#define MIN(x,y) (((x) < (y)) ? (x) : (y))

void ofSeedRandom() {
  struct timeval tv;
  gettimeofday(&tv, 0);
  long int n = (tv.tv_sec ^ tv.tv_usec) ^ getpid();
  srand(n);
}

float ofRandom(float x, float y) {
  if (x == y) return x;
  float high = MAX(x,y);
  float low = MIN(x,y);
  return low + ((high - low) * rand() / (RAND_MAX + 1.0f));
}

int main() {
  ofSeedRandom();
  for(int i=0; i<10; i++) {
    printf("%f\n", ofRandom(1,10));
  }
}
