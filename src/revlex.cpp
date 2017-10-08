/*
Написать пример с использованием этого класса строк и какого-либо контейнера STL. 
Программа должна принимать список строк, затем выдавать его в порядке, обратном
лексикографическому без учета регистра.

Программа-пример работает из командной строки.
*/

#include <iostream>
#include <list>
#include <clocale>
#include "custom_string.h"

int main(int argc, char *argv[])
{
	CustomString promptString;
	CustomString inputLine;
	CustomString locale;
	std::list<CustomString> inputLines;

	CustomString s;
    CustomString s2("sorter");
	s += "Lexicographic ";
	s = s + "order ";
	s = s + s2;
	s = s;
	std::cout << s << std::endl;

	// В коммандной строке можно задать локаль, которую будет использовать программа при регистронезависимом сравнении строк.
	// Если при работе в русскоязычной Windows-консоли установить значение локали в "Russian_Russia.866", то можно будет вводить строки интерактивно.
	if (argc >= 2) // в командной строке указана локаль
	{
		locale = argv[1];
		std::cout << "Locale from command line: '" << locale << "'" << std::endl;
	}
	CustomString currentLocale("Runtime locale set to '");
	currentLocale = currentLocale + std::setlocale(LC_ALL, locale.c_str()) + "'";
	std::cout << currentLocale << std::endl;

	// Считываем строки со стандартного ввода
	promptString = "Enter lines(end with Ctrl-Z or Ctrl-D)\n";
	std::cout << promptString;
	while (std::cin >> inputLine)
	{
		if (inputLine.getLength() > 0)
        {
			inputLines.push_back(inputLine);
        }
	};
	// Сортируем строки лексикографически без учёта регистра
	inputLines.sort(CustomString::stricmp);

	// Выводим строки в обратном порядке
	promptString = "Lexicographically descending lines:";
	std::cout << promptString << std::endl;
	for (std::list<CustomString>::reverse_iterator linesIter = inputLines.rbegin(); linesIter != inputLines.rend(); linesIter++)
	{
		std::cout << *linesIter << std::endl;
	};
	
	return 0;
};
