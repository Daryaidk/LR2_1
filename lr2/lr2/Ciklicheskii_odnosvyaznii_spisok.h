#ifndef Ciklicheskii_odnosvyaznii_spisok_h
#define Ciklicheskii_odnosvyaznii_spisok_h
#include <iostream>


class Ciklicheskii_odnosvyaznii_spisok                      //����� ������
{
    friend Ciklicheskii_odnosvyaznii_spisok& operator-- ( Ciklicheskii_odnosvyaznii_spisok& a); //���������� ��������� -- ��� ������������� �-� ��� ��������� ������������
    friend Ciklicheskii_odnosvyaznii_spisok& operator-- ( Ciklicheskii_odnosvyaznii_spisok& a, int); //���������� ��������� -- ��� ������������� �-� ��� ��������� ������������
private:
    int x;                         //��������. �������� �� x ����� ������������ � ������

public:
    Ciklicheskii_odnosvyaznii_spisok* Next;                         //��������� �� ��������� ������� ������
    Ciklicheskii_odnosvyaznii_spisok* Side;
    Ciklicheskii_odnosvyaznii_spisok* Head, * Tail;                 //��������� �� ��������� �������� ������� ��� ������ ������ ������

public:
    Ciklicheskii_odnosvyaznii_spisok() { Head = NULL; Tail = NULL; }           //����������� � ������������� ��������� ������ ���������
    ~Ciklicheskii_odnosvyaznii_spisok();                       //����������
    Ciklicheskii_odnosvyaznii_spisok& operator++();            //���������� ��������� ++ ��� ����� ���������� �������� � ������
    Ciklicheskii_odnosvyaznii_spisok& operator++(int);         //���������� ��������� ++ ��� ����� ���������� 2 �������� � ������
    void getShow();                   //������� ��� ����������� ������ �� ������
    void getRemove();                 //������� �������� �������� �� ������
    void getDelete();
};


#endif