#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>


using namespace std;

struct doublePoints {
	char* key;//адресное поле – динамическая строка
	doublePoints* next;//указатель на следующий элемент
	doublePoints* pred;//указатель на предыдущий элемент
	int n = 0;
};
doublePoints* make_point()
//создание одного элемента
{
	doublePoints* p = new(doublePoints);
	p->next = 0; p->pred = 0;//обнуляем указатели

	char s[50];
	cout << "Введите строку: ";
	cin >> s;
	cout << "\n";
	p->key = new char[strlen(s) + 1];//выделение памяти под строку
	strcpy(p->key, s);

	return p;
}

doublePoints* makeTwo_list(int n)
//создание списка
{
	doublePoints* p, * beg;
	beg = make_point();//создаем первый элемент
	for (int i = 1; i < n; i++)
	{
		p = make_point();//создаем один элемент
		p->n = n;
		//добавление элемента в начало списка
		p->next = beg;//связываем р с первым элементом
		beg->pred = p;//связываем первый элемент с p
		beg = p;// p становится первым элементом списка

	}
	return beg;
}
//печать списка
void print_list(doublePoints* beg)
{
	doublePoints* p = beg;//начало списка
	while (p != 0)
	{
		cout << p->key << "\t";
		p = p->next;//переход к следующему элементу
	}
	cout << "\n";
}
doublePoints* add_ToList(doublePoints* beg, int pos)
{
	doublePoints* p = make_point();//создаём элемент который нужно добавить
	if (pos <= 1||beg->n==0) 
	{
		//если выбранная позиция меньше 1 или размерность списка больше 0 то
		//добавление элемента в начало списка
		p->next = beg;//связываем р с первым элементом
		beg->pred = p;//связываем первый элемент с p
		beg = p;// p становится первым элементом списка
	}
	else if (pos > beg->n) {
		//если позиция больше размера списка то добавляем элемент в конец списка
		beg->next = p;//в первый элемент передаем p
		p->pred = beg;//в предыдущий элемент p вставляем текущий список
		beg = p;//передаём p в beg где p стоит на последнем месте
	}
	else {
		//если элемент нужно добавить в середину списка то
		doublePoints* p1 = beg;//передаем в p1 ссылку на beg
		for (int i = 0; i < pos - 2; i++)// доходим до элемента beg[pos-1](если подсчёт идёт с 1)
			p1 = p1->next;
		//создаём место для элемента p
		doublePoints* p2 = p1->next;//передаём ссылку на следующий элемент в p2
		//создаём связь между предыдущим элементом и следующим для вставляемого значения
		p1->next = p;// следующий элемент beg[pos-1]связываем с p
		p2->pred = p;// предыдущий элемент beg[pos] связываем с p
		p->next = p2;// следующий элемент p связываем с p2
		p->pred = p1;// предыдущий элемент p связываем с p1
	}
	beg->n++;
	return beg;//возвращаем список
}


