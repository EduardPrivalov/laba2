#pragma once
#include <iostream>
#include <string>
#include "Note.h"
using namespace std;

typedef struct Element {
	Note* data{};
	Element* pNext = 0;
} Element;

class List : public Note {
private:
	Element* Head;
	Element* Tail;
	int count;

public:
	List();
	~List();

	bool IsEmpty();
	void Sort();
	void Print();
	int GetCount();

	List& operator--();//удаление
	List& operator++();//добавление

	Element* operator[](const int index);


	List& Del(int cnt);
	void AddElem(Element* elem);

	Element* GetHead();
	void SetHead(Element*);
	Element* GetTail();
	void SetTail(Element*);


	void SearchByPhone();

};

