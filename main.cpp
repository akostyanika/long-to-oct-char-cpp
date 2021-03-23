#include <algorithm>
#include <bitset>
#include <cstdlib>
#include <iostream>
#include <vector>
#include "lab.h"

void positive_test() {
  // внутри функция ltoao сама выделит нужное количество памяти под строку, понять количество символов можно по специальному терминальному символу \0, который должен быть в конце корректной строки
  char* as_string;
  long numbers[6] = {
    0,    1,    7,
    8,    16,   129,

  };

  for (int i = 0; i < 6; i++) {
    ltoao(numbers[i], &as_string);
    printf("%22ld\n%s\n", numbers[i], as_string);
  }
}

void negative_test() {
  char* as_string;

  unsigned long l1 = 0b1111111111111111111111111111111111111111111111111111111111111111;
  long l2 = 0b1000000000000000000000000000000000000000000000000000000000000000;
  long l3 = 0b1111000111000111000111000111000111000111000111000111000111000111;

  ltoao(l1, &as_string);
  printf("%22lu\n%s\n", l1, as_string);

  ltoao(l2, &as_string);
  printf("%22ld\n%s\n", l2, as_string);

  ltoao(l3, &as_string);
  printf("%22ld\n%s\n", l3, as_string);
}

void longs_example() {
  long l1 = 0b1111111111111111111111111111111111111111111111111111111111111111;
  long l2 = 0b1000000000000000000000000000000000000000000000000000000000000000;
  unsigned long ul1 =  0b1111111111111111111111111111111111111111111111111111111111111111;
  unsigned long ul2 = 0b1000000000000000000000000000000000000000000000000000000000000000;

  std::cout << l1 << std::endl;
  std::cout << l2 << std::endl;
  std::cout << ul1 << std::endl;
  std::cout << ul2  << std::endl;
}

void negative_long_shifting() {
  long l1 = 0b1000000000000000000000000000000000000000000000000000000000000000;
  std::bitset<64> bit_representation_l1(l1);
  long l2 = l1 >> 3;
  std::bitset<64> bit_representation_l2(l2);

  printf("%ld\n%s\n", l1, bit_representation_l1.to_string().c_str());
  printf("%ld\n%s\n", l2, bit_representation_l2.to_string().c_str());
}

int main() {
  printf("");
  printf("Сдвиг отрицательного long\n");
  negative_long_shifting();
}