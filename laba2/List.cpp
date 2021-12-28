#include "List.h"

List::List() {
    Head = Tail = NULL;
    count = 0;
}

List::~List() {
    while (Head != 0)
    {
        Element* temp = this->Head;
        Head = this->Head->pNext;
    }
    this->count = 0;
}

void List::Sort() {
    if (this->IsEmpty()) throw -1;
    Element* p = this->Head;
    Note* tmp;
    while (p->pNext != NULL) {
        for (int i = 0; i < this->count - 1; i++) {
            for (int j = i + 1; j < this->count; j++) {
                if ((*this)[i]->data->GetName() > (*this)[j]->data->GetName()) {
                    tmp = (*this)[j]->data;
                    if (i == 0) {
                        (*this)[j]->data = &(*(*this).Head->data);
                        (*this).Head->data = tmp;
                    }
                    else {
                        (*this)[j]->data = &(*(*this)[i - 1]->pNext->data);
                        (*this)[i]->data = tmp;
                    }
                }
            }
            p = p->pNext;
        }
    }
}

bool List::IsEmpty() {
    return !count;
}

void List::Print() {
    if (this->IsEmpty()) throw -1;
    Element* temp = this->Head;
    int cnt = count;
    cout << "Note" << endl;
    while (cnt != 0) {
        cout << "Name: " << temp->data->GetName() << endl << "Phone: " << temp->data->GetPhone() << endl << "Birth date: " << temp->data->GetBday()[0]
            << "/" << temp->data->GetBday()[1] << "/" << temp->data->GetBday()[2] << endl;
        temp = temp->pNext;
        cnt--;
        cout << "==============" << endl;
    }
}

int List::GetCount() {
    return this->count;
}

List& List::operator--() {
    if (this->IsEmpty()) throw -1;
    else if (count == 1) {
        this->~List();
        cout << "Now this list is empty" << endl;
        return *this;
    }
    else {
        List reserve;
        int cnt = 0;
        Element* temp = Head;
        cout << "Want to remove?" << endl;
        while (cnt != count) {
            cout << ++cnt << ". " << temp->data->GetName() << endl;
            temp = temp->pNext;
        }
        cout << ">>> ";
        cin >> cnt;
        if (cnt<1 || cnt>count) throw -1;
        cnt -= 1;
        temp = Head;

        for (int i = 0; i < cnt - 1; i++) {
            reserve.AddElem(temp);
            temp = temp->pNext;
        }
        Element* tmp = temp;
        if (this->count == 2) {
            if (cnt == 0) {
                reserve.AddElem(temp->pNext);
            }
            else reserve.AddElem(temp);
            *this = reserve;
            return *this;
        }
        temp->pNext = temp->pNext->pNext;
        reserve.AddElem(temp);
        temp = tmp->pNext;

        for (int i = cnt; i < count - 1; i++) {
            reserve.AddElem(temp);
            temp = temp->pNext;
        }
        reserve.AddElem(temp);

        this->Head = reserve.Head;
        this->Tail = reserve.Tail;
        this->count--;
    }
    return *this;
}

List& List::operator++() {
    string name, phone;
    int bday[3];
    cout << " Add object " << endl;
    cout << "Enter name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter phone number: " << endl;
    cin >> phone;
    cout << endl << "Enter birth date: " << endl;
    cin >> bday[0];
    cin >> bday[1];
    cin >> bday[2];
    Note* memb = new Note(name, phone, bday);
    Element* temp = new Element;
    temp->data = memb;
    temp->pNext = NULL;

    if (this->IsEmpty()) {
        temp->pNext = nullptr;
        Head = Tail = temp;
    }
    else {
        Element* p = Head;
        while (p->pNext != NULL) p = p->pNext;
        p->pNext = temp;
        this->Tail = temp;
    }
    count++;
    return *this;
}

Element* List::operator[](const int index) {
    if (index < 0 || index >= this->count) throw -1;

    if (index == 0) return (*this).Head;
    else if (index == this->count - 1) return (*this).Tail;
    else {
        Element* p = Head;
        for (int i = 0; i < index; i++) {
            p = p->pNext;
        }
        return p;
    }
}




List& List::Del(int cnt) {
    system("cls");
    if (this->IsEmpty()||cnt<0 || cnt>count) throw -1;
    List reserve;
    Element* temp = Head;
    for (int i = 0; i < cnt; i++) {
        reserve.AddElem(temp);
        temp = temp->pNext;
    }
    temp = temp->pNext;
    for (int i = cnt + 1; i < count; i++) {
        reserve.AddElem(temp);
        temp = temp->pNext;
    }
    this->Head = reserve.Head;
    count--;
    return *this;
}


void List::AddElem(Element* elem) {
    if (this->IsEmpty()) {
        Head = Tail = elem;
    }
    else {
        Element* p = Head;
        while (p->pNext != NULL) p = p->pNext;
        this->Tail = elem;
    }

    this->count++;
}


Element* List::GetHead() {
    return Head;
}
void List::SetHead(Element* elem) {
    this->Head = elem;
}

Element* List::GetTail() {
    return Tail;
}
void List::SetTail(Element* elem) {
    this->Tail = elem;
}

void List::SearchByPhone() {
    if (this->IsEmpty()) throw -1;
    int month;
    int flag = 0;
    cout << "Month: " << endl;
    cin >> month ;
    cout << endl;
    Element* p = this->Head;
    while (p != NULL) {
        if (p->data->GetBday()[1] == month) {
            flag = 1;
            cout << "Name: " << p->data->GetName() << endl << "Phone: " << p->data->GetPhone() << endl << "Birth date: " << p->data->GetBday()[0]
                << "/" << p->data->GetBday()[1] << "/" << p->data->GetBday()[2] << endl << endl;
            
        } 
       p = p->pNext;
    }

    if (flag == 0) cout << "Data not found";
}
