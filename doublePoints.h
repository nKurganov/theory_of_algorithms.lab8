#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>


using namespace std;

struct doublePoints {
	char* key;//�������� ���� � ������������ ������
	doublePoints* next;//��������� �� ��������� �������
	doublePoints* pred;//��������� �� ���������� �������
	int n = 0;
};
doublePoints* make_point()
//�������� ������ ��������
{
	doublePoints* p = new(doublePoints);
	p->next = 0; p->pred = 0;//�������� ���������

	char s[50];
	cout << "������� ������: ";
	cin >> s;
	cout << "\n";
	p->key = new char[strlen(s) + 1];//��������� ������ ��� ������
	strcpy(p->key, s);

	return p;
}

doublePoints* makeTwo_list(int n)
//�������� ������
{
	doublePoints* p, * beg;
	beg = make_point();//������� ������ �������
	for (int i = 1; i < n; i++)
	{
		p = make_point();//������� ���� �������
		p->n = n;
		//���������� �������� � ������ ������
		p->next = beg;//��������� � � ������ ���������
		beg->pred = p;//��������� ������ ������� � p
		beg = p;// p ���������� ������ ��������� ������

	}
	return beg;
}
//������ ������
void print_list(doublePoints* beg)
{
	doublePoints* p = beg;//������ ������
	while (p != 0)
	{
		cout << p->key << "\t";
		p = p->next;//������� � ���������� ��������
	}
	cout << "\n";
}
doublePoints* add_ToList(doublePoints* beg, int pos)
{
	doublePoints* p = make_point();//������ ������� ������� ����� ��������
	if (pos <= 1||beg->n==0) 
	{
		//���� ��������� ������� ������ 1 ��� ����������� ������ ������ 0 ��
		//���������� �������� � ������ ������
		p->next = beg;//��������� � � ������ ���������
		beg->pred = p;//��������� ������ ������� � p
		beg = p;// p ���������� ������ ��������� ������
	}
	else if (pos > beg->n) {
		//���� ������� ������ ������� ������ �� ��������� ������� � ����� ������
		beg->next = p;//� ������ ������� �������� p
		p->pred = beg;//� ���������� ������� p ��������� ������� ������
		beg = p;//������� p � beg ��� p ����� �� ��������� �����
	}
	else {
		//���� ������� ����� �������� � �������� ������ ��
		doublePoints* p1 = beg;//�������� � p1 ������ �� beg
		for (int i = 0; i < pos - 2; i++)// ������� �� �������� beg[pos-1](���� ������� ��� � 1)
			p1 = p1->next;
		//������ ����� ��� �������� p
		doublePoints* p2 = p1->next;//������� ������ �� ��������� ������� � p2
		//������ ����� ����� ���������� ��������� � ��������� ��� ������������ ��������
		p1->next = p;// ��������� ������� beg[pos-1]��������� � p
		p2->pred = p;// ���������� ������� beg[pos] ��������� � p
		p->next = p2;// ��������� ������� p ��������� � p2
		p->pred = p1;// ���������� ������� p ��������� � p1
	}
	beg->n++;
	return beg;//���������� ������
}


