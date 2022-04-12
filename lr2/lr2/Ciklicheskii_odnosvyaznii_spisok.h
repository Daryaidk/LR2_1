#ifndef Ciklicheskii_odnosvyaznii_spisok_h
#define Ciklicheskii_odnosvyaznii_spisok_h
#include <iostream>


class Ciklicheskii_odnosvyaznii_spisok                      //Класс Список
{
    friend Ciklicheskii_odnosvyaznii_spisok& operator-- ( Ciklicheskii_odnosvyaznii_spisok& a); //Перегрузка оператора -- как дружественная ф-я для сообщения пользователю
    friend Ciklicheskii_odnosvyaznii_spisok& operator-- ( Ciklicheskii_odnosvyaznii_spisok& a, int); //Перегрузка оператора -- как дружественная ф-я для сообщения пользователю
private:
    int x;                         //Инфополе. значения из x будут передаваться в список

public:
    Ciklicheskii_odnosvyaznii_spisok* Next;                         //Указатель на следующий элемент списка
    Ciklicheskii_odnosvyaznii_spisok* Side;
    Ciklicheskii_odnosvyaznii_spisok* Head, * Tail;                 //Указатель на последний активный элемент или просто голова списка

public:
    Ciklicheskii_odnosvyaznii_spisok() { Head = NULL; Tail = NULL; }           //Конструктор и инициализация указателя пустым значением
    ~Ciklicheskii_odnosvyaznii_spisok();                       //Деструктор
    Ciklicheskii_odnosvyaznii_spisok& operator++();            //Перегрузка оператора ++ как метод добавления значения в список
    Ciklicheskii_odnosvyaznii_spisok& operator++(int);         //Перегрузка оператора ++ как метод добавления 2 значений в список
    void getShow();                   //Функция для отображения списка на экране
    void getRemove();                 //Функция удаление элемента из списка
    void getDelete();
};


#endif