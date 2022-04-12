#include <cstddef>
#include <iostream>
#include "Ciklicheskii_odnosvyaznii_spisok.h"
using namespace std;

int qq;

//����������
Ciklicheskii_odnosvyaznii_spisok::~Ciklicheskii_odnosvyaznii_spisok()
{
    while (Head != NULL)                      //���� �� ������ �� �����
    {
        Ciklicheskii_odnosvyaznii_spisok* temp = Head->Next;       //��������� ���������� ��� �������� ������ ���������� ��������
        delete Head;                      //����������� ����� ������������ ������
        Head = temp;                      //������ ����� �� ���������
    }

}

//������� ����������� ������ �� ������
void Ciklicheskii_odnosvyaznii_spisok::getShow()               
{
    Ciklicheskii_odnosvyaznii_spisok* temp = Head;                 //���������� ���������, ������� ���������� ����� ������ ������ ������

    while (temp != NULL)                   //�� ��� ��� ���� �� �������� ������ ��������
    {
        cout << temp->x << " ";               //������� ������� x �� ������
        temp = temp->Next;                    //���������, ��� ����� ��� ����� ��������� �������
    }
}

//������� �������� �������� �� ������
void Ciklicheskii_odnosvyaznii_spisok::getRemove()
{
    if (Head != NULL) //���� ������ �� ������
    {
        Ciklicheskii_odnosvyaznii_spisok* temp = Head; //���������� � ������ ������ � ������� ���������������� ���������
        cout << "������� " << Head->x << " ������" << endl;
        Head = Head->Next;
        delete temp; //������������ ������ �� ����������� ����� ������    
    }
}

//���������� �������� ����������������� 
Ciklicheskii_odnosvyaznii_spisok& Ciklicheskii_odnosvyaznii_spisok::operator++() { 
    cin >> x;
    Ciklicheskii_odnosvyaznii_spisok* temp = new Ciklicheskii_odnosvyaznii_spisok;            //��� ������ ������ ���������� ������
    temp->x = x;                            ///��������� ����������� ��������� ��������� x
    temp->Next = NULL;                      //��������, ��� ��������� ����� ���� ������
    if (Head != NULL)                       //���� ������ �� ����
    {
        Tail->Next = temp;
         Tail = temp;                       //���������, ��� ��������� �������� ������� ��� ��������� ���������
    }
    else Head = Tail = temp;              //���� ������ �� ����, ���������� ������� ��������
    
    return *this;
}

//����������� �������� ����������������� 
Ciklicheskii_odnosvyaznii_spisok& Ciklicheskii_odnosvyaznii_spisok::operator++(int) {  
    cin >> x;
    Ciklicheskii_odnosvyaznii_spisok* temp = new Ciklicheskii_odnosvyaznii_spisok;            //��� ������ ������ ���������� ������
    temp->x = x;                            ///��������� ����������� ��������� ��������� x
    temp->Next = NULL;                      //��������, ��� ��������� ����� ���� ������
    if (Head != NULL)                       //���� ������ �� ����
    {
        Tail->Next = temp;
        Tail = temp;                       //���������, ��� ��������� �������� ������� ��� ��������� ���������
    }
    else Head = Tail = temp;              //���� ������ �� ����, ���������� ������� ��������

    return *this;
}

//���������� �������� �����������������
Ciklicheskii_odnosvyaznii_spisok& operator-- ( Ciklicheskii_odnosvyaznii_spisok&  a) {
    int y,q,i=1;
    cout << "�������� �������: ";
    cin >> y;
    Ciklicheskii_odnosvyaznii_spisok* temp = a.Head;                 //���������� ���������, ������� ���������� ����� ������ ������ ������
    Ciklicheskii_odnosvyaznii_spisok* tempp = a.Head;

    while (temp != NULL)                   //�� ��� ��� ���� �� �������� ������ ��������
    {
        if (i == y) {
            cout << "������� �������: " << temp->x << " ";           //������� ������� x �� ������
            q = temp->x;
            cout << "\n������� ������ ������� �����";
            
        }
        temp = temp->Next;                    //���������, ��� ����� ��� ����� ��������� �������
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

//����������� �������� �����������������
Ciklicheskii_odnosvyaznii_spisok& operator-- (Ciklicheskii_odnosvyaznii_spisok& a, int) {
    int y, q, i = 1;
    cout << "�������� �������: ";
    cin >> y;
    Ciklicheskii_odnosvyaznii_spisok* temp = a.Head;                 //���������� ���������, ������� ���������� ����� ������ ������ ������
    Ciklicheskii_odnosvyaznii_spisok* tempp = a.Head;

    while (temp != NULL)                   //�� ��� ��� ���� �� �������� ������ ��������
    {
        if (i == y) {
            cout << "������� �������: " << temp->x << " ";           //������� ������� x �� ������
            q = temp->x;
            cout << "\n������� ������ ������� �����";
            temp = temp->Next;
            qq = temp->x;
            cout << "\n������� ��������� �������: " << temp->x << " ";
            cout << "\n������� ��������� ������� �����";
        }
        temp = temp->Next;                    //���������, ��� ����� ��� ����� ��������� �������
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