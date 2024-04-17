# Рубежный контроль 1 по предмету "Компьютерные сети"
## Задача 1 - Сжатие данных алгоритмом Шеннона-Фано
Реализован класс `Coder`, содержащий следующие публичные методы:
```cpp
[[nodiscard]] std::string encode(const std::string &plain_text, bool silent) noexcept;
```
Кодирует строку `plain_text` кодом Шеннона-Фано, возвращает кодовое слово. В поток вывода помещаются промежуточные вычисления, если флаг `silent` равен `false`. 
```cpp
[[nodiscard]] std::string encode(const std::string &plain_text) noexcept;
```
Кодирует строку `plain_text` кодом Шеннона-Фано, возвращает кодовое слово. В поток вывода помещаются промежуточные вычисления.
```cpp
void encode_file(const std::string &input_filename, const std::string &output_filename, bool silent) noexcept;
```
Получает содержимое файла `input_filename`, кодирует его кодом Шеннона-Фано, записывает кодовое слово в файл `output_filename`. В поток вывода помещаются промежуточные вычисления, если флаг `silent` равен `false`.
```cpp
void encode_file(const std::string &, const std::string &) noexcept;
```
Получает содержимое файла `input_filename`, кодирует его кодом Шеннона-Фано, записывает кодовое слово в файл `output_filename`.
```cpp
[[nodiscard]] std::string encode_file(const std::string &, bool) noexcept;
```
Получает содержимое файла `input_filename`, кодирует его кодом Шеннона-Фано, возвращает кодовое слово. В поток вывода помещаются промежуточные вычисления, если флаг `silent` равен `false`.
```cpp
[[nodiscard]] std::string encode_file(const std::string &) noexcept;
```
Получает содержимое файла `input_filename`, кодирует его кодом Шеннона-Фано, возвращает кодовое слово.

## Задача 2 - Сжатие данных алгоритмом Хаффмана
## Задача 3
## Задача 4
