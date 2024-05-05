# Рубежный контроль 1 по предмету "Компьютерные сети"
## Задача 1 - Сжатие данных алгоритмом Шеннона-Фано
Реализован класс `Shannon_Fano`, содержащий следующие публичные методы:
```cpp
[[nodiscard]] std::string encode(const std::string &plain_text, bool silent) noexcept;
```
Кодирует строку `plain_text` кодом Шеннона-Фано, возвращает закодированную строку. В поток вывода помещаются промежуточные вычисления, если флаг `silent` равен `false`. 
```cpp
[[nodiscard]] std::string encode(const std::string &plain_text) noexcept;
```
Кодирует строку `plain_text` кодом Шеннона-Фано, возвращает закодированную строку. В поток вывода помещаются промежуточные вычисления.
```cpp
void encode_file(const std::string &input_filename, const std::string &output_filename, bool silent) noexcept;
```
Получает содержимое файла `input_filename`, кодирует его кодом Шеннона-Фано, записывает закодированную строку в файл `output_filename`. В поток вывода помещаются промежуточные вычисления, если флаг `silent` равен `false`.
```cpp
void encode_file(const std::string &, const std::string &) noexcept;
```
Получает содержимое файла `input_filename`, кодирует его кодом Шеннона-Фано, записывает закодированную строку в файл `output_filename`.
```cpp
[[nodiscard]] std::string encode_file(const std::string &, bool) noexcept;
```
Получает содержимое файла `input_filename`, кодирует его кодом Шеннона-Фано, возвращает закодированную строку. В поток вывода помещаются промежуточные вычисления, если флаг `silent` равен `false`.
```cpp
[[nodiscard]] std::string encode_file(const std::string &) noexcept;
```
Получает содержимое файла `input_filename`, кодирует его кодом Шеннона-Фано, возвращает закодированную строку.

## Задача 2 - Сжатие данных алгоритмом Хаффмана
Реализован класс `Haffman`, содержащий следующие публичные методы:
```cpp
[[nodiscard]] std::string compress(const std::string &plain_text, bool silent) noexcept;
```
Кодирует строку `plain_text` кодом Хаффмана, возвращает закодированную строку. В поток вывода помещаются промежуточные вычисления, если флаг `silent` равен `false`.
```cpp
[[nodiscard]] std::string compress(const std::string &plain_text) noexcept;
```
Кодирует строку `plain_text` кодом Хаффмана, возвращает закодированную строку. В поток вывода помещаются промежуточные вычисления.
```cpp
void compress_file(const std::string &input_filename, const std::string &output_filename, bool silent) noexcept;
```
Получает содержимое файла `input_filename`, кодирует его кодом Хаффмана, записывает закодированную строку в файл `output_filename`. В поток вывода помещаются промежуточные вычисления, если флаг `silent` равен `false`.
```cpp
void compress_file(const std::string &, const std::string &) noexcept;
```
Получает содержимое файла `input_filename`, кодирует его кодом Хаффмана, записывает закодированную строку в файл `output_filename`.
```cpp
[[nodiscard]] std::string compress_file(const std::string &, bool) noexcept;
```
Получает содержимое файла `input_filename`, кодирует его кодом Хаффмана, возвращает закодированную строку. В поток вывода помещаются промежуточные вычисления, если флаг `silent` равен `false`.
```cpp
[[nodiscard]] std::string compress_file(const std::string &) noexcept;
```
Получает содержимое файла `input_filename`, кодирует его кодом Хаффмана, возвращает закодированную строку.

## Результат решения задачи 1 и 2
Было проведено сравнение времени и эффективности сжатия текстов разной длины алгоритмом Шеннона-Фано и алгоритмом Хаффмана.<br>
Результаты сравнения приведены далее в таблице.

| Длина исходного текста | Длина текста сжатого алгоритмом ШФ | Время сжатия алгоритмом ШФ, мс | Длина текста сжатого алгоритмом Хаффмана | Время сжатия алгоритмом Хаффмана, мс |
|------------------------|------------------------------------|--------------------------------|------------------------------------------|--------------------------------------|
| 10                     | 32                                 | 0.2037                         | 32                                       | 0.0672                               |
| 100                    | 563                                | 0.3292                         | 558                                      | 0.552                                |
| 1000                   | 6102                               | 0.5469                         | 6024                                     | 1.0901                               |
| 10000                  | 62088                              | 5.2989                         | 60528                                    | 12.7557                              |
| 100000                 | 622120                             | 46.4445                        | 605805                                   | 86.1461                              |
| 1000000                | 6225272                            | 297.613                        | 6059714                                  | 711.966                              |
| 10000000               | 62265941                           | 2813.65                        | 60602712                                 | 7109.95                              |
| 100000000              | 622701917                          | 40385.5                        | 606049094                                | 83576.17                             |

## Задача 3
## Задача 4
