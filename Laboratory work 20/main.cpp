#include <iostream>
#include <fstream>

struct Tree
{
	int data;
	Tree* left;
	Tree* right;
	Tree* parent;
};

//Создание
Tree* Make(int data, Tree* p)
{
	Tree* q = new Tree;
	q->data = data;
	q->left = nullptr;
	q->right = nullptr;
	q->parent = p;
	return q;
}

//Добавление
void Add(int data, Tree*& root)
{
	if (root == nullptr)
	{
		root = Make(data, nullptr);
		return;
	}
	Tree* v = root;
	while ((data < v->data && v->left != nullptr) || (data > v->data && v->right != nullptr))
		if (data < v->data)
			v = v->left;
		else
			v = v->right;
	if (data == v->data)
		return;
	Tree* u = Make(data, v);
		if (data < v->data)
			v->left = u;
		else
			v->right = u;
}

//Вывод
void Output(Tree* v)
{
	if (v == nullptr)
		return;
	Output(v->left);
		std::cout << v->data << std::endl;
	Output(v->right);
}

//Поиск
Tree* Search(int data, Tree* v)
{
	if (v == nullptr)
		return v;
	if (v->data == data)
		return v;
	if (data < v->data)
		return  Search(data, v->left);
	else
		return Search(data, v->right);
}

//Удаление
void Delete(int data, Tree*& root)
{
	Tree* u = Search(data, root);
	if (u == nullptr)
		return;
	if (u->left == nullptr && u->right == nullptr && u == root)
	{
		delete root;
		root = nullptr;
		return;
	}
	if (u->left == nullptr && u->right != nullptr && u == root)
	{
		Tree* t = u->right;
		while (t -> left != nullptr)
			t = t->left;
		u->data = t->data;
		u = t;
	}
	if (u->left != nullptr && u->right == nullptr && u == root)
	{
		Tree* t = u->left;
		while (t->right != nullptr)
			t = t->right;
		u->data = t->data;
		u = t;
	}
	if (u->left != nullptr && u->right != nullptr)
	{
		Tree* t = u->right;
		while (t->left != nullptr)
			t = t->left;
		u->data = t->data;
		u = t;
	}
	Tree* t;
	if (u->left == nullptr)
		t = u->right;
	else
		t = u->left;
	if (u->parent->left == u)
		u->parent->left = t;
	else
		u->parent->right = t;
	if (t != nullptr)
		t->parent = u->parent;
	delete u;
}

int main()
{
	std::ifstream file;
	file.open("input.txt");
	if (!file.is_open())
		std::cout << "ERROR" << std::endl;
	else
	{
		std::cout << "File is open" << std::endl;
		char ch;
		while (file.get(ch))
		{
			std::cout << ch;
		}
	}

	file.close();
	return 0;
}