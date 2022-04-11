#pragma once
#include <iostream>

using namespace std;

struct binnaryTree
{
	char key;
	binnaryTree* left;
	binnaryTree* right;
};
binnaryTree* first(char d,binnaryTree* p)//формирование первого элемента дерева
{
	//передаём в ключ значение d
	p->key =d;
	//левую и правую ветвь 
	p->left = 0;
	p->right = 0;
	return p;

}
void print_Tree(binnaryTree* root)
{
	if (root)
	{
		cout<<root->key;//печатаем элемент
		cout << ("\n");
		print_Tree(root->left);//переход к левому поддереву
		print_Tree(root->right);//переход к правому поддереву
	}
}
binnaryTree* BinaryTree(binnaryTree* root, char d)
{
	binnaryTree* p = root;//корень дерева
	binnaryTree* r; //Корень Левое поддерево Правое поддерево
		//флаг для проверки существования элемента d в дереве
	bool ok = false;
	while (p && !ok)
	{
		r = p;
		if (d == p->key)ok = true;//элемент уже существует
		else
			if (d < p->key)p = p->left;//пойти в левое поддерево
			else p = p->right;//пойти в правое поддерево
	}
	if (ok) return p;//найдено, не добавляем
	//создаем узел
	binnaryTree* New_point = new binnaryTree;//выделили память
	New_point->key = d;
	New_point->left = 0;
	New_point->right = 0;
	// если d<r->key, то добавляем его в левое поддерево
	if (d < r->key)r->left = New_point;
	// если d>r->key, то добавляем его в правое поддерево
	else r->right = New_point;
	return New_point;
}
//создаем дерево поиска
binnaryTree* createBT(binnaryTree* result, binnaryTree* root, bool firstElm = true)
{
	if (root)
	{
		if (firstElm) //если первый элемент
		{
			result = first(root->key, result);//передаём первое значение поля в дерево поиска
		}
		else {
			result = BinaryTree(result, root->key);//вставляем в первую или правую ветвь текущее значение root 
		}
		createBT(result, root->left, false);//переход к левому поддереву
		createBT(result, root->right, false);//переход к правому поддереву
	}
	return result;
}

//создаем идеальное дерево
binnaryTree* Tree(int n, binnaryTree* p)
{
	binnaryTree* r;
	int nl, nr;
	//прерывание рекурсии
	if (n <= 0) { p = NULL; return p; }//если n меньше либо равен 0 то возвращаем пустой список
	nl = n / 2;//для левого выделяем половину от указанной длины
	nr = n - nl - 1;//для правого списка оставляем n-nl и, учитывая первое значение, вычитаем единицу
	//создаем элемент 
	r = new binnaryTree;
	cout << "Введите символ ";
	cin >> r->key;
	//передаем в левую ветвь следующие значение
	r->left = Tree(nl, r->left);
	//после окончания рекурсии по левой ветви передаем в правую ветвь следующие значение
	r->right = Tree(nr, r->right);
	p = r;//передаем в список ссылку на r
	return p;//возвращаем созданный элемент

}
//поиск в дереве количества элементов
int find_in_Tree(binnaryTree* root, char key, int number = 0)
{
	if (root)
	{
		if (root->key == key)
			//если нашли ключ увеличиваем number
			number++;
		number = find_in_Tree(root->left, key, number);//переход к левому поддереву
		number = find_in_Tree(root->right, key, number);//переход к правому поддереву
	}
	return number;
}
