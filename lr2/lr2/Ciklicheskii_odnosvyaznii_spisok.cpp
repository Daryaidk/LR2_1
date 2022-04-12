#include <cstddef>
#include <iostream>
#include "Ciklicheskii_odnosvyaznii_spisok.h"
using namespace std;

int qq;

//Деструктор
Ciklicheskii_odnosvyaznii_spisok::~Ciklicheskii_odnosvyaznii_spisok()
{
    while (Head != NULL)                      //Пока по адресу не пусто
    {
        Ciklicheskii_odnosvyaznii_spisok* temp = Head->Next;       //Временная переменная для хранения адреса следующего элемента
        delete Head;                      //Освобождаем адрес обозначающий начало
        Head = temp;                      //Меняем адрес на следующий
    }

}

//Функция отображения списка на экране
void Ciklicheskii_odnosvyaznii_spisok::getShow()               
{
    Ciklicheskii_odnosvyaznii_spisok* temp = Head;                 //Определяем указатель, который изначально равен адресу начала списка

    while (temp != NULL)                   //До тех пор пока не встретит пустое значение
    {
        cout << temp->x << " ";               //Выведет элемент x из списка
        temp = temp->Next;                    //Указываем, что далее нам нужен следующий элемент
    }
}

//функция удаления элемента из списка
void Ciklicheskii_odnosvyaznii_spisok::getRemove()
{
    if (Head != NULL) //Если список не пустой
    {
        Ciklicheskii_odnosvyaznii_spisok* temp = Head; //Обращаемся к началу списка с помощью вспомогательного указателя
        cout << "Элемент " << Head->x << " удален" << endl;
        Head = Head->Next;
        delete temp; //Освобождение памяти от предыдущего звена списка    
    }
}

//префиксный оператор инкрементирования 
Ciklicheskii_odnosvyaznii_spisok& Ciklicheskii_odnosvyaznii_spisok::operator++() { 
    cin >> x;
    Ciklicheskii_odnosvyaznii_spisok* temp = new Ciklicheskii_odnosvyaznii_spisok;            //При каждом вызове выделяется память
    temp->x = x;                            ///Временное запоминание принятого параметра x
    temp->Next = NULL;                      //Указание, что следующее звено пока пустое
    if (Head != NULL)                       //Если список не пуст
    {
        Tail->Next = temp;
         Tail = temp;                       //Указываем, что последний активный элемент это последний введенный
    }
    else Head = Tail = temp;              //Если список не пуст, добавление первого элемента
    
    return *this;
}

//постфиксный оператор инкрементирования 
Ciklicheskii_odnosvyaznii_spisok& Ciklicheskii_odnosvyaznii_spisok::operator++(int) {  
    cin >> x;
    Ciklicheskii_odnosvyaznii_spisok* temp = new Ciklicheskii_odnosvyaznii_spisok;            //При каждом вызове выделяется память
    temp->x = x;                            ///Временное запоминание принятого параметра x
    temp->Next = NULL;                      //Указание, что следующее звено пока пустое
    if (Head != NULL)                       //Если список не пуст
    {
        Tail->Next = temp;
        Tail = temp;                       //Указываем, что последний активный элемент это последний введенный
    }
    else Head = Tail = temp;              //Если список не пуст, добавление первого элемента

    return *this;
}

//префиксный оператор декрементирования
Ciklicheskii_odnosvyaznii_spisok& operator-- ( Ciklicheskii_odnosvyaznii_spisok&  a) {
    int y,q,i=1;
    cout << "Выберите позицию: ";
    cin >> y;
    Ciklicheskii_odnosvyaznii_spisok* temp = a.Head;                 //Определяем указатель, который изначально равен адресу начала списка
    Ciklicheskii_odnosvyaznii_spisok* tempp = a.Head;

    while (temp != NULL)                   //До тех пор пока не встретит пустое значение
    {
        if (i == y) {
            cout << "Элемент позиции: " << temp->x << " ";           //Выведет элемент x из списка
            q = temp->x;
            cout << "\nЭлемент данной позиции удалён";
            
        }
        temp = temp->Next;                    //Указываем, что далее нам нужен следующий элемент
        i = i + 1;
    }


    Ciklicheskii_odnosvyaznii_spisok* slow = a.Head;
    Ciklicheskii_odnosvyaznii_spisok* fast = a.Head->Next;
    while (fast && fast->x != q) {
        fast = fast->Next;
        slow = slow->Next;
    }
    if (!fast) {
        cout << "This element does not exist" << endl;
        
    }
    slow->Next = fast->Next;
    delete fast;

    return a;
}

//постфиксный оператор декрементирования
Ciklicheskii_odnosvyaznii_spisok& operator-- (Ciklicheskii_odnosvyaznii_spisok& a, int) {
    int y, q, i = 1;
    cout << "Выберите позицию: ";
    cin >> y;
    Ciklicheskii_odnosvyaznii_spisok* temp = a.Head;                 //Определяем указатель, который изначально равен адресу начала списка
    Ciklicheskii_odnosvyaznii_spisok* tempp = a.Head;

    while (temp != NULL)                   //До тех пор пока не встретит пустое значение
    {
        if (i == y) {
            cout << "Элемент позиции: " << temp->x << " ";           //Выведет элемент x из списка
            q = temp->x;
            cout << "\nЭлемент данной позиции удалён";
            temp = temp->Next;
            qq = temp->x;
            cout << "\nЭлемент следующей позиции: " << temp->x << " ";
            cout << "\nЭлемент следующей позиции удалён";
        }
        temp = temp->Next;                    //Указываем, что далее нам нужен следующий элемент
        i = i + 1;
    }


    Ciklicheskii_odnosvyaznii_spisok* slow = a.Head;
    Ciklicheskii_odnosvyaznii_spisok* fast = a.Head->Next;
    while (fast && fast->x != q) {
        fast = fast->Next;
        slow = slow->Next;
    }
    if (!fast) {
        cout << "This element does not exist" << endl;

    }
    slow->Next = fast->Next;
    delete fast;

    return a;
}

void Ciklicheskii_odnosvyaznii_spisok::getDelete()
{
    Ciklicheskii_odnosvyaznii_spisok* slow = Head;
    Ciklicheskii_odnosvyaznii_spisok* fast = Head->Next;
    while (fast && fast->x != qq) {
        fast = fast->Next;
        slow = slow->Next;
    }
    if (!fast) {
        cout << "This element does not exist" << endl;

    }
    slow->Next = fast->Next;
    delete fast;
}