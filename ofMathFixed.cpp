#include <stdlib.h>
#include <iostream>
#include <sys/time.h>
#include <unistd.h>

float ofRandomuf(){
  return rand() / static_cast<double>(RAND_MAX) + 1.0;
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
