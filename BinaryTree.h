#pragma once
#include <iostream>

using namespace std;

struct binnaryTree
{
	char key;
	binnaryTree* left;
	binnaryTree* right;
};
binnaryTree* first(char d,binnaryTree* p)//������������ ������� �������� ������
{
	//������� � ���� �������� d
	p->key =d;
	//����� � ������ ����� 
	p->left = 0;
	p->right = 0;
	return p;

}
void print_Tree(binnaryTree* root)
{
	if (root)
	{
		cout<<root->key;//�������� �������
		cout << ("\n");
		print_Tree(root->left);//������� � ������ ���������
		print_Tree(root->right);//������� � ������� ���������
	}
}
binnaryTree* BinaryTree(binnaryTree* root, char d)
{
	binnaryTree* p = root;//������ ������
	binnaryTree* r; //������ ����� ��������� ������ ���������
		//���� ��� �������� ������������� �������� d � ������
	bool ok = false;
	while (p && !ok)
	{
		r = p;
		if (d == p->key)ok = true;//������� ��� ����������
		else
			if (d < p->key)p = p->left;//����� � ����� ���������
			else p = p->right;//����� � ������ ���������
	}
	if (ok) return p;//�������, �� ���������
	//������� ����
	binnaryTree* New_point = new binnaryTree;//�������� ������
	New_point->key = d;
	New_point->left = 0;
	New_point->right = 0;
	// ���� d<r->key, �� ��������� ��� � ����� ���������
	if (d < r->key)r->left = New_point;
	// ���� d>r->key, �� ��������� ��� � ������ ���������
	else r->right = New_point;
	return New_point;
}
//������� ������ ������
binnaryTree* createBT(binnaryTree* result, binnaryTree* root, bool firstElm = true)
{
	if (root)
	{
		if (firstElm) //���� ������ �������
		{
			result = first(root->key, result);//������� ������ �������� ���� � ������ ������
		}
		else {
			result = BinaryTree(result, root->key);//��������� � ������ ��� ������ ����� ������� �������� root 
		}
		createBT(result, root->left, false);//������� � ������ ���������
		createBT(result, root->right, false);//������� � ������� ���������
	}
	return result;
}

//������� ��������� ������
binnaryTree* Tree(int n, binnaryTree* p)
{
	binnaryTree* r;
	int nl, nr;
	//���������� ��������
	if (n <= 0) { p = NULL; return p; }//���� n ������ ���� ����� 0 �� ���������� ������ ������
	nl = n / 2;//��� ������ �������� �������� �� ��������� �����
	nr = n - nl - 1;//��� ������� ������ ��������� n-nl �, �������� ������ ��������, �������� �������
	//������� ������� 
	r = new binnaryTree;
	cout << "������� ������ ";
	cin >> r->key;
	//�������� � ����� ����� ��������� ��������
	r->left = Tree(nl, r->left);
	//����� ��������� �������� �� ����� ����� �������� � ������ ����� ��������� ��������
	r->right = Tree(nr, r->right);
	p = r;//�������� � ������ ������ �� r
	return p;//���������� ��������� �������

}
//����� � ������ ���������� ���������
int find_in_Tree(binnaryTree* root, char key, int number = 0)
{
	if (root)
	{
		if (root->key == key)
			//���� ����� ���� ����������� number
			number++;
		number = find_in_Tree(root->left, key, number);//������� � ������ ���������
		number = find_in_Tree(root->right, key, number);//������� � ������� ���������
	}
	return number;
}
