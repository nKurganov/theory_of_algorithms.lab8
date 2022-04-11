#pragma once
#include <iostream>

using namespace std;

struct point
{
	int data; //�������������� ����
	point* next; //�������� ����

	int length;//
	
};

//�������� ������
point* makeOne_list(int n)
{
	point* beg;//��������� �� ������ �������
	point* p, * r;//��������������� ���������
	beg = new(point);//�������� ������ ��� ������ �������
	cout << "������� �����";
	cin >> beg->data;//������ �������� ��������������� ����
	cout << "\n";
	beg->next = 0;//�������� �������� ����
	//������ �� ���� ������� ��������� p (��������� �������)
	p = beg;
	beg->length = n;
	for (int i = 0; i < n - 1; i++)
	{
		r = new(point);//������� ����� �������
		cout << "������� �����";
		cin >> r->data;
		cout << "\n";
		r->length = n;
		r->next = 0;
		p->next = r;//��������� p � r
		//������ �� r ��������� p (��������� �������)
		p = r;

	}
	return beg;//���������� beg ��� ��������� �������
}

//������� ������ �������� �� ������
point* del_even_data(point* beg) 
{
	if ((beg != NULL)) // ���� �� ����� ������ ���-�� ����� � ���� ������� ������ ������
	{
		point* curNode = beg;//������� ������ �� beg
		point* prevNode = NULL;//���������� ��� ���������� ���������� �����
		int n = beg->length;
		while (curNode)//���� �� ��������� ������
		{
			if (curNode->data % 2 == 0) //���� ������� ������
			{
				if (curNode->next != 0) //���� ��������� ������� ����������
				{
					//������������ ������� �� ���������
					curNode->data = curNode->next->data;
					curNode->next = curNode->next->next;
					n--;
					continue;
				}
				else {
					//���� ��������� ������� �� ���������� ������� ��������� �������
					if (prevNode) prevNode->next = NULL;
					delete curNode;
					n--;
					break;
				}
			}
			prevNode = curNode;
			curNode = curNode->next;
		}
		//���� ������� ��� �������� �� beg ����������� Null
		if (n == 0) {
			beg = NULL;
		}
	}
	return beg;
}

//������ ������
void print_list(point* beg)
{
	point* p = beg;//������ ������
	while (p != 0)
	{
		cout << p->data << "\t";
		p = p->next;//������� � ���������� ��������
	}
	cout << "\n";
}