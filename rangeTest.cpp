#include <iostream>

void large_range_check(float low, float high) {
    float range = high - low;
    float epsilon = std::numeric_limits<float>::epsilon();
    float little_bit_small_range = (high - low) - epsilon;

    printf("%x\n", *(reinterpret_cast<int *>(&range)));
    printf("%x\n", *(reinterpret_cast<int *>(&little_bit_small_range)));
}

int main(){
  large_range_check(0.0f, std::numeric_limits<float>::max());
  large_range_check(0.0f, 3.0f);
}
