#include "Note.h"

Note::Note(string name, string phone, int* bday) {
	this->SetName(name);
	this->SetPhone(phone);
	this->SetBday(bday);
}

void Note::SetName(string name) {
	this->name = name;
}
string Note::GetName() {
	return this->name;
}

void Note::SetPhone(string phone) {
	this->phone = phone;
}
string Note::GetPhone() {
	return this->phone;
}

void Note::SetBday(int* bday) {
	for (int i = 0; i < 3; i++)
		this->bDay[i] = bday[i];
}
int* Note::GetBday() {
	return this->bDay;
}
