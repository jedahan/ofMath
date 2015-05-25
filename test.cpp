#include <iostream>

int main() {
  float max = RAND_MAX;
  double double_max = static_cast<double>(RAND_MAX);
  float max_plus_one = max + 1;
  double double_max_plus_one = double_max + 1;
  double double_max_plus_two = double_max_plus_one + 1;
  printf("%f\n", max);
  printf("%f\n", max_plus_one);
  printf("\n");
  printf("%lf\n", double_max);
  printf("%lf\n", double_max_plus_one);
  printf("%lf\n", double_max_plus_two);
}
