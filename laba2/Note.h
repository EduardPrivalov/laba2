#pragma once
#include <iostream>
#include <string>
using namespace std;

class Note {
private:
	string name;
	string phone;
	int bDay[3]{ 0,0,0 };
public:
	Note() {};
	Note(string name, string phone, int* bday);
	void SetName(string);
	string GetName();

	void SetPhone(string);
	string GetPhone();

	void SetBday(int*);
	int* GetBday();

};

