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
