# s21_string+ using macros



Здесь я использую глобальную переменную чтобы обеспечить доступ к структуре флагов из любого места программы(что запрещено по заданию школы, но это мой гит, так что оставлю как есть).
```
extern Flags flag;
Flags flag = {'\0'};
```

Уменьшила дублирования похожих по логике функций использованием макросов.

Без макроса:
```
void s21_int_to_str(int64_t val, int base, char* dest) {
    s21_adjust_int64_t(val);                    
  char str[EIGHT_KB] = {'0'};                     
  int iter = EIGHT_KB - 2;                         
  int64_t val_abs = (int64_t)(val);                      
  int neg = ((int)val < 0) ? S21_TRUE : S21_FALSE; 
  val_abs = neg ? -(val_abs) : val_abs;            
  if (val_abs == 0) {                              
    dest[0] = '0';                                 
  }                                                
  REBASE(val_abs, base, iter, str);                
  for (int j = 0; str[iter]; iter++, j++) {        
    if (neg && j == 0) {                           
      dest[j++] = '-';                             
    }                                              
    dest[j] = str[iter];                           
  } 
}

void s21_uint_to_str(uint64_t val, int base, char* dest) {
    s21_adjust_uint64_t(val);                    
  char str[EIGHT_KB] = {'0'};                     
  int iter = EIGHT_KB - 2;                         
  uint64_t val_abs = (uint64_t)(val);                      
  int neg = ((int)val < 0) ? S21_TRUE : S21_FALSE; 
  val_abs = neg ? -(val_abs) : val_abs;            
  if (val_abs == 0) {                              
    dest[0] = '0';                                 
  }                                                
  REBASE(val_abs, base, iter, str);                
  for (int j = 0; str[iter]; iter++, j++) {        
    if (neg && j == 0) {                           
      dest[j++] = '-';                             
    }                                              
    dest[j] = str[iter];                           
  } 
}
```
Та же функция с макросом:
```
#define S21_TO_STR(val, base, dest, type)            \
  do {                                               \
    s21_adjust_##type(val, type);                    \
    char str[EIGHT_KB] = {'\0'};                     \
    int iter = EIGHT_KB - 2;                         \
    type val_abs = (type)(val);                      \
    int neg = ((int)val < 0) ? S21_TRUE : S21_FALSE; \
    val_abs = neg ? -(val_abs) : val_abs;            \
    if (val_abs == 0) {                              \
      dest[0] = '0';                                 \
    }                                                \
    REBASE(val_abs, base, iter, str);                \
    for (int j = 0; str[iter]; iter++, j++) {        \
      if (neg && j == 0) {                           \
        dest[j++] = '-';                             \
      }                                              \
      dest[j] = str[iter];                           \
    }                                                \
  } while (0)
```

При компиляции макросы заменяют типы и ваша функция становится более гибкой, их можно использовать как вне функции:
```
S21_CONVERT_CHAR(char);
S21_CONVERT_CHAR(wchar_t);
```
так и в внутри функции:
```
void s21_int_logic(char *temp, va_list va) {
  int64_t val = va_arg(va, int64_t);
  S21_TO_STR(val, 10, temp, int64_t);
  s21_adjust_precision(temp);
  s21_adjust_flags(temp);
}
```


По ходу написания программы пришлось столкнуться с тем, что в макросах должны исполняться разные подфункции в зависимости от типа данных, поэтому в этом месте я решила, что могу заметить макрос вызывающий макрос (Ну а что, проект-то учебный).

```
#define s21_adjust_uint64_t(val, type) \
  do {                                 \
    switch (flag.length) {             \
      case 'h':                        \
        val = (uint16_t)val;           \
        break;                         \
      case 'l':                        \
        val = (uint64_t)val;           \
        break;                         \
      case 0:                          \
        val = (uint32_t)val;           \
        break;                         \
    }                                  \
  } while (0)

#define S21_TO_STR(val, base, dest, type)            \
  do {                                               \
    s21_adjust_##type(val, type);                    \
    char str[EIGHT_KB] = {'\0'};                     \
    int iter = EIGHT_KB - 2;                         \
    type val_abs = (type)(val);                      \
    int neg = ((int)val < 0) ? S21_TRUE : S21_FALSE; \
    val_abs = neg ? -(val_abs) : val_abs;            \
    if (val_abs == 0) {                              \
      dest[0] = '0';                                 \
    }                                                \
    REBASE(val_abs, base, iter, str);                \
    for (int j = 0; str[iter]; iter++, j++) {        \
      if (neg && j == 0) {                           \
        dest[j++] = '-';                             \
      }                                              \
      dest[j] = str[iter];                           \
    }                                                \
  } while (0)

```

Я долгое время не знала как решить это задание, потому что до него не занималась программированием от слова совсем, но этот подход с изучением макросов позволил мне по своему заинтересоваться и довести все до конца, надеюсь и вы сможете найти что-то интересное для себя в таких учебно-монотонных задачах!

П.С. Я конечно сейчас без слез взглянуть на код не могу, изменила бы многое и многое добавила, я все еще вижу недостатки - лишние дублирования, конструкции и выход за пределы массива местами, но ошибки это вроде как не стыдно, поэтому выложила, буду рада любым комментариям не выходящим за рамки приличий!



## Information

The C language has a set of functions that implement operations on strings (character strings and byte strings) in its standard library. Various operations such as copy, concatenate, tokenize, and search are supported. For strings, the standard library uses the convention that strings are null-terminated: a string of n characters is represented as an array of n + 1 elements, the last of which is a "NULL" character. 

The only support for strings in the actual programming language is that the compiler translates quoted string constants to null-terminated strings.

### string.h Types

| No. | Variable | Description |
| ------ | ------ | ------ |
| 1 | size_t | This is the unsigned integral type and is the result of the sizeof keyword. |
	
### string.h Macro

| No. | Macro | Description |
| ------ | ------ | ------ |
| 1 | NULL | This macro is the value of a null pointer constant. |

### string.h Functions

| No. | Function | Description |
| ------ | ------ | ------ |
| 1 | void *memchr(const void *str, int c, size_t n) | Searches for the first occurrence of the character c (an unsigned char) in the first n bytes of the string pointed to, by the argument str. |
| 2 | int memcmp(const void *str1, const void *str2, size_t n) | Compares the first n bytes of str1 and str2. |
| 3 | void *memcpy(void *dest, const void *src, size_t n) | Copies n characters from src to dest. |
| 4 | void *memset(void *str, int c, size_t n) | Copies the character c (an unsigned char) to the first n characters of the string pointed to, by the argument str. |
| 5 | char *strncat(char *dest, const char *src, size_t n) | Appends the string pointed to, by src to the end of the string pointed to, by dest up to n characters long. |
| 6	| char *strchr(const char *str, int c) | Searches for the first occurrence of the character c (an unsigned char) in the string pointed to, by the argument str. |
| 7 | int strncmp(const char *str1, const char *str2, size_t n) | Compares at most the first n bytes of str1 and str2. |
| 8 | char *strncpy(char *dest, const char *src, size_t n) | Copies up to n characters from the string pointed to, by src to dest. |
| 9 | size_t strcspn(const char *str1, const char *str2) | Calculates the length of the initial segment of str1 which consists entirely of characters not in str2. |
| 10 | char *strerror(int errnum) | Searches an internal array for the error number errnum and returns a pointer to an error message string. You need to declare macros containing arrays of error messages for mac and linux operating systems. Error descriptions are available in the original library. Checking the current OS is carried out using directives. |
| 11 | size_t strlen(const char *str) | Computes the length of the string str up to but not including the terminating null character. |
| 12 | char *strpbrk(const char *str1, const char *str2) | Finds the first character in the string str1 that matches any character specified in str2. |
| 13 | char *strrchr(const char *str, int c) | Searches for the last occurrence of the character c (an unsigned char) in the string pointed to by the argument str. |
| 14 | char *strstr(const char *haystack, const char *needle) | Finds the first occurrence of the entire string needle (not including the terminating null character) which appears in the string haystack. |
| 15 | char *strtok(char *str, const char *delim) | Breaks string str into a series of tokens separated by delim. |

### sprintf 

- int sprintf(char *str, const char *format, ...) — sends formatted output to a string pointed to, by str.

where:
- str — This is the C string that the function processes as its source to retrieve the data;
- format — This is the C string that contains one or more of the following items: Whitespace character, Non-whitespace character and Format specifiers. A format specifier for print functions follows this prototype: %[flags][width][.precision][length]specifier. A format specifier for scan functions follows this prototype: %[*][width][length]specifier.

### sprintf Specifiers

| No. | Specifier | sprintf output |
| --- | --- | --- |
| 1 | c | Character |
| 2 | d | Signed decimal integer |
| 3 | i | Signed decimal integer | 
| 4 | e | Scientific notation (mantissa/exponent) using e character (the output of the numbers must match up to e-6) |
| 5 | E | Scientific notation (mantissa/exponent) using E character |
| 6 | f | Decimal floating point | 
| 7 | g | Uses the shortest representation of decimal floating point |
| 8 | G | Uses the shortest representation of decimal floating point | 
| 9 | o | Unsigned octal | 
| 10 | s | String of characters |
| 11 | u | Unsigned decimal integer |
| 12 | x | Unsigned hexadecimal integer | 
| 13 | X | Unsigned hexadecimal integer (capital letters) | 
| 14 | p | Pointer address | 
| 15 | n | Number of characters printed until %n occurs | 
| 16 | % | Character % | 

### sprintf Flags

| No. | Flags | Description |
| --- | --- | --- |
| 1 | - | Left-justify within the given field width; Right justification is the default (see width sub-specifier). |
| 2 | + | Forces to precede the result with a plus or minus sign (+ or -) even for positive numbers. By default, only negative numbers are preceded with a -ve sign. |
| 3 | (space) | If no sign is going to be written, a blank space is inserted before the value. |
| 4 | # | Used with o, x or X specifiers the value is preceded with 0, 0x or 0X respectively for values different than zero. Used with e, E and f, it forces the written output to contain a decimal point even if no digits would follow. By default, if no digits follow, no decimal point is written. Used with g or G the result is the same as with e or E but trailing zeros are not removed. |
| 5 | 0 | Left-pads the number with zeroes (0) instead of spaces, where padding is specified (see width sub-specifier). |

### sprintf Width Description

| No. |	Width | Description |
| --- | --- | --- |
| 1	| (number) | Minimum number of characters to be printed. If the value to be printed is shorter than this number, the result is padded with blank spaces. The value is not truncated even if the result is larger. |
| 2 | * | In sprintf the * sign means, that the width is not specified in the format string, but as an additional integer value argument preceding the argument that has to be formatted.
### sprintf Precision Description

| No. |	.precision | Description |
| --- | --- | --- |
| 1	| .number | For integer specifiers (d, i, o, u, x, X) — precision specifies the minimum number of digits to be written. If the value to be written is shorter than this number, the result is padded with leading zeros. The value is not truncated even if the result is longer. A precision of 0 means that no character is written for the value 0. For e, E and f specifiers — this is the number of digits to be printed after the decimal point. For g and G specifiers — This is the maximum number of significant digits to be printed. For s — this is the maximum number of characters to be printed. By default all characters are printed until the ending null character is encountered. For c type — it has no effect. When no precision is specified for specifiers e, E, f, g and G, the default one is 6. When no precision is specified for all other kind of specifiers, the default is 1. If the period is specified without an explicit value for precision, 0 is assumed. |
| 2	| .* | The precision is not specified in the format string, but as an additional integer value argument preceding the argument that has to be formatted. |

### sprintf Length Description

| No. |	Length | Description |
| --- | --- | --- |
| 1 | h | The argument is interpreted as a short int or unsigned short int (only applies to integer specifiers: i, d, o, u, x and X). |
| 2 | l | The argument is interpreted as a long int or unsigned long int for integer specifiers (i, d, o, u, x and X), and as a wide character or wide character string for specifiers c and s. |
| 3 | L | The argument is interpreted as a long double (only applies to floating point specifiers — e, E, f, g and G). |

### Special string processing functions (from the String class in C#)

| No. | Function | Description |
| ------ | ------ | ------ |
| 1 | void *to_upper(const char *str) | Returns a copy of string (str) converted to uppercase. In case of any error, return NULL. |
| 2 | void *to_lower(const char *str) | Returns a copy of string (str) converted to lowercase. In case of any error, return NULL. |
| 3 | void *insert(const char *src, const char *str, size_t start_index) | Returns a new string in which a specified string (str) is inserted at a specified index position (start_index) in the given string (src). In case of any error, return NULL. |
| 4 | void *trim(const char *src, const char *trim_chars) | Returns a new string in which all leading and trailing occurrences of a set of specified characters (trim_chars) from the given string (src) are removed. In case of any error, return NULL. |

