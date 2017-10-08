/*
Написать класс динамических строк, который:

1. Имеет конструктор копирования, оператор присваивания и "внешний" оператор сложения двух строк.
2. Поддерживает строки произвольного размера, используя операции работы с динамическим хипом.
3. Не использует в своей основе какую-либо другую реализацию динамических строк (std::string no-no!).
*/

#ifndef CUSTOM_STRING_H
#define CUSTOM_STRING_H

#include <iostream>

class CustomString
{
    friend CustomString operator + (CustomString left, const CustomString& right);
    friend std::ostream& operator << (std::ostream& out, const CustomString& str);
    friend std::istream& operator >> (std::istream& in, CustomString& str);
	friend void swap(CustomString& first, CustomString& second);
public:
	CustomString() : _size(0), _chars(nullptr) { };
    CustomString(const CustomString& s);
    CustomString(const char* str);
    ~CustomString();

    const CustomString& operator = (const CustomString s);
	const CustomString& operator += (const CustomString& s);

	static bool stricmp(const CustomString& a, const CustomString& b); /// Функция регистронезависимого сравнения двух CustomString

    size_t getLength() const { return _size == 0 ? 0 : _size - 1; }; /// Длина строки (терминирующий '\0' не считается)
    const char* c_str() const; /// Возвращает const char* на строку
	/** Возвращает строку в HEX-представлении.
	* @param[out] dst Буфер, в который должна быть записана сформированная HEX-строка
	* @param[in] addSpace Если этот параметр 'true', то метод добавит пробелы между каждым байтом
	* @param[in] n Размер буфера назначения. Метод запишет в буфер не более 'n' байт.
	*/
	void hexlify(char* dst, bool addSpace, size_t n) const;
private:
    size_t _size; // Размер _chars, включая завершающий 0x00
    char* _chars; // Хранилище символов строки
};

#endif // CUSTOM_STRING_H
