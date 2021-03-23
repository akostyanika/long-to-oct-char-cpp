void ltoao (long num, char** s) {
  // 8 байт (64 двоичных бита) позволяют записать максимум 22 разряда восьмеричного числа
  // +1 символ нужен для символа конца строки (терминальный символ): '\0', его целочисленный код - 0
  (*s) = new char[23];
  (*s)[22] = '\0';

  // 64 двоичных разряда позволяют представить восьмеричное число из 21-го разряда с полным диапазоном и неполный диапазон для 22-х восьмеричных разрядов
  // будем вставлять с младших разрядов
  for (int i = 21; i >= 0; i--) {
    // для представления одного восьмеричного разряда нужно три двоичных
    // current_digit - это результат применения маски, которая берёт три младших бита из двоичного представления num
    char current_digit = num & 0b00000111;
    // мы получили целочисленное представление числа от 0 до 7, но в char-представлении (ASCII) символы имеют свои коды, поэтому нужно взять код ASCII для символа, который соответствует символьному представлению цифры current_digit
    current_digit = '0' + current_digit;
    (*s)[i] = current_digit;
    // сдвигаем num на три бита вправо, таким образом мы убираем три только что обработанных двоичных разряда
    num = num >> 3;
    // дальше делаем то же самое, пока не обработаем 21 группу по три разряда
  }
}