#pragma once
#include <iostream>

using namespace std;

struct point
{
	int data; //информационное поле
	point* next; //адресное поле

	int length;//
	
};

//создание списка
point* makeOne_list(int n)
{
	point* beg;//указатель на первый элемент
	point* p, * r;//вспомогательные указатели
	beg = new(point);//выделяем память под первый элемент
	cout << "Введите число";
	cin >> beg->data;//вводим значение информационного поля
	cout << "\n";
	beg->next = 0;//обнуляем адресное поле
	//ставим на этот элемент указатель p (последний элемент)
	p = beg;
	beg->length = n;
	for (int i = 0; i < n - 1; i++)
	{
		r = new(point);//создаем новый элемент
		cout << "Введите число";
		cin >> r->data;
		cout << "\n";
		r->length = n;
		r->next = 0;
		p->next = r;//связываем p и r
		//ставим на r указатель p (последний элемент)
		p = r;

	}
	return beg;//возвращаем beg как результат функции
}

//удаляем чётные значения из списка
point* del_even_data(point* beg) 
{
	if ((beg != NULL)) // если по этому номеру что-то лежит и этот элемент внутри списка
	{
		point* curNode = beg;//передаём ссылку на beg
		point* prevNode = NULL;//переменная для сохранения предыдущей ветви
		int n = beg->length;
		while (curNode)//пока не последний список
		{
			if (curNode->data % 2 == 0) //если элемент чётный
			{
				if (curNode->next != 0) //если следующий элемент существует
				{
					//переставляем элемент на следующий
					curNode->data = curNode->next->data;
					curNode->next = curNode->next->next;
					n--;
					continue;
				}
				else {
					//если следующий элемент не существует удаляем последний элемент
					if (prevNode) prevNode->next = NULL;
					delete curNode;
					n--;
					break;
				}
			}
			prevNode = curNode;
			curNode = curNode->next;
		}
		//если удалили все элементы то beg присваеваем Null
		if (n == 0) {
			beg = NULL;
		}
	}
	return beg;
}

//печать списка
void print_list(point* beg)
{
	point* p = beg;//начало списка
	while (p != 0)
	{
		cout << p->data << "\t";
		p = p->next;//переход к следующему элементу
	}
	cout << "\n";
}