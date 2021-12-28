#include <iostream>
#include <fstream>
#include <string>
#include "List.h"
#include "Note.h"
using namespace std;

void StringStream()
{
	/*
	С использованием файловых и строковых потоков написать программу,
которая считывает английский текст из файла и выводит его на экран,
заменив каждую первую букву слов, начинающихся с гласной буквы,
прописной
*/

	ifstream in("test.txt");
	if (!in.good()) return;
	string word;
	size_t words_vowel_count = 0;
	while (!in.eof())
	{
		getline(in, word);
		for (size_t i = 0; i < word.size() - 1; i++)
		{
			if (i==0 && (word[i] == 'A' || word[i] == 'E' ||
				word[i] == 'Y' || word[i] == 'U' ||
				word[i] == 'I' || word[i] == 'O')) {
				word[i] = tolower(word[i]);
			}
			else if (word[i] == ' ' && (word[i + 1] == 'A' || word[i + 1] == 'E' ||
				word[i + 1] == 'Y' || word[i + 1] == 'U' ||
				word[i + 1] == 'I' || word[i + 1] == 'O')) {
				word[i + 1] = tolower(word[i + 1]);
			}
		}
		cout << word << endl;
	}
}

int main()
{
	List list;
	int menu = 1;
	while (true) {
		cout << "menu" << endl;
		cout << "1. Add object" << endl;
		cout << "2. Print list" << endl;
		cout << "3. Search by month" << endl;
		cout << "4. Delete object" << endl;
		cout << "5. Sort by birthday" << endl;
		cout << "6. String stream task" << endl;
		cout << "0. Exit" << endl;
		cout << ">>> ";
		cin >> menu;

		while (menu < 0 || menu > 8 || cin.fail()) {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Incorrect entered, retry" << endl;
			cin >> menu;
		}

		try {

			switch (menu) {
			case 1: {
				++list;
				break; }
			case 2: {
				list.Print();
				break; }
			case 3: {
				list.SearchByPhone();
				break; }
			case 4: {
				--list;
				break; }
			case 5: {
				list.Sort();
				break; }
			case 6: {
				StringStream();
				break; }

			case 0: {
				return 0; }

			}
		}
		catch (int) {
			cout << "error" << endl;
			return 1;
		}
	}
}

/*

Определить класс с именем NОТЕ, содержащий следующие поля:
● фамилия, имя;
● номер телефона;
● день рождения (массив из трех чисел).
Определить методы доступа к этим полям и перегруженные операции
извлечения и вставки для объектов типа NОТЕ.
Заранее число объектов не известно.

Написать программу, выполняющую следующие действия:
● записи должны быть размещены по алфавиту;
● вывод на экран информации о людях, чьи дни рождения приходятся
на месяц, значение которого введено с клавиатуры;
● если таких нет, выдать на дисплей соответствующее сообщение.

2. Файловые и строковые потоки
С использованием файловых и строковых потоков написать программу,
которая считывает английский текст из файла и выводит его на экран,
заменив каждую первую букву слов, начинающихся с гласной буквы,
прописной

*/