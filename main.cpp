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
    printf("%23ld\n%s\n", numbers[i], as_string);
  }
}

void negative_test() {
  char* as_string;

  unsigned long l1 = 0b1111111111111111111111111111111111111111111111111111111111111111;
  long l2 = 0b1000000000000000000000000000000000000000000000000000000000000000;
  long l3 = 0b1111000111000111000111000111000111000111000111000111000111000111;

  ltoao(l1, &as_string);
  printf("unsigned\n");
  printf("%23lu\n%s\n", l1, as_string);

  ltoao(l2, &as_string);
  printf("signed negative\n");
  printf("%23ld\n%s\n", l2, as_string);

  ltoao(l3, &as_string);
  printf("signed negative\n");
  printf("%23ld\n%s\n", l3, as_string);
}

void signed_vs_unsigned_long_representation() {
  long l1 = 0b1111111111111111111111111111111111111111111111111111111111111111;
  unsigned long ul1 = 0b1111111111111111111111111111111111111111111111111111111111111111;
  long l2 = 0b1000000000000000000000000000000000000000000000000000000000000000;
  unsigned long ul2 = 0b1000000000000000000000000000000000000000000000000000000000000000;
  long l3 = 0b1000000000000000000000000000000000000000000000000000000000000001;
  unsigned long ul3 = 0b1000000000000000000000000000000000000000000000000000000000000001;
  long l4 = 0b0111111111111111111111111111111111111111111111111111111111111111;
  unsigned long ul4 = 0b0111111111111111111111111111111111111111111111111111111111111111;

  std::bitset<64> l1_as_bits(l1);
  std::bitset<64> l2_as_bits(l2);
  std::bitset<64> l3_as_bits(l3);
  std::bitset<64> l4_as_bits(l4);
  // для long и unsigned long битовое представление одинаковое

  printf("%ld\n%lu\n%s\n", l1, ul1, l1_as_bits.to_string().c_str());
  printf("%ld\n%lu\n%s\n", l2, ul2, l2_as_bits.to_string().c_str());
  printf("%ld\n%lu\n%s\n", l3, ul3, l3_as_bits.to_string().c_str());
  printf("%ld\n%lu\n%s\n", l4, ul4, l4_as_bits.to_string().c_str());
}

void negative_long_shifting() {
  long l1 = 0b1000000000000000000000000000000000000000000000000000000000000000;
  std::bitset<64> l1_bit_representation(l1);
  long l2 = l1 >> 3;
  std::bitset<64> l2_bit_representation(l2);

  printf("%ld\n%s\n", l1, l1_bit_representation.to_string().c_str());
  printf("%ld\n%s\n", l2, l2_bit_representation.to_string().c_str());
}

void examples() {
  printf("Обработка long со знаком и без знака\n");
  signed_vs_unsigned_long_representation();
  printf("\n");

  printf("Побитовый сдвиг отрицательного long\n");
  negative_long_shifting();
  printf("\n");
}

int main() {
  examples();

  printf("Negative test\n");
  negative_test();
  printf("\n");
}