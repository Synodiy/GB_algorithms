/*
2. Переписать программу, реализующее двоичное дерево поиска.
а) Добавить в него обход дерева различными способами;
б) Реализовать поиск в двоичном дереве поиска;
в) *Добавить в программу обработку командной строки с помощью которой можно указывать
из какого файла считывать данные, каким образом обходить дерево.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <locale.h>
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string>
using namespace std;

typedef int T;
typedef struct Node {
	T data;
	struct Node *left;
	struct Node *right;
	struct Node *parent;
} Node;

void PrintTree(Node *root)
{
	if (root)
	{
		printf("%d", root->data);
		if (root->left || root->right)
		{
			printf("(");

			if (root->left)	PrintTree(root->left);
			else printf("NULL");
			printf(",");

			if (root->right) PrintTree(root->right);
			else printf("NULL");
			printf(")");
		}
	}
}

Node* GetFreeNode(T val, Node *par)
{
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->left = temp->right = NULL;
	temp->data = val;
	temp->parent = par;
	return temp;
}

void InsertNode(Node **head, int value)
{
	Node *temp = NULL;
	if (*head == NULL)
	{
		*head = GetFreeNode(value, NULL);
		return;
	}

	temp = *head;
	while (temp)
	{
		if (value > temp->data)
		{
			if (temp->right)
			{
				temp = temp->right;
				continue;
			}
			else
			{
				temp->right = GetFreeNode(value, temp);
				return;
			}
		}
		else if (value < temp->data)
		{
			if (temp->left)
			{
				temp = temp->left;
				continue;
			}
			else
			{
				temp->left = GetFreeNode(value, temp);
				return;
			}
		}
		else
		{
			exit(2);
		}
	}
}

void RootLeftRight(Node* root)
{
	if (root)
	{
		printf("%d ", root->data);
		RootLeftRight(root->left);
		RootLeftRight(root->right);
	}
}
void LeftRootRight(Node* root)
{
	if (root)
	{
		LeftRootRight(root->left);
		printf("%d ", root->data);
		LeftRootRight(root->right);
	}
}
void LeftRightRoot(Node* root)
{
	if (root)
	{
		LeftRightRoot(root->left);
		LeftRightRoot(root->right);
		printf("%d ", root->data);
	}
}

Node *FindNodeInTree(Node *root, T value)
{
	while (root)
	{
		if (root->data > value)
		{
			root = root->left;
			continue;
		}
		else if (root->data < value)
		{
			root = root->right;
			continue;
		}
		else
		{
			return root;
		}
	}
	return NULL;
}

int main(int argc, char** args)
{
	Node *Tree = NULL;
	FILE *file;
	int count, value, input;
	string dataFileName;

	setlocale(LC_ALL, "Rus");

	//задание 2.в
	cout << "Введите название файла с данными для создания двоичного дерева поиска: " << endl;
	getline(cin, dataFileName);
	cout << endl;

	file = fopen(dataFileName.c_str(), "r");
	if (file == NULL)
	{
		cout << "Невозможно открыть файл " << dataFileName << endl;
		system("Pause");
		return 0;
	}
	fscanf(file, "%d", &count);
	cout << "Содержание файла: " << endl;
	for (int i = 0; i < count; i++)
	{
		fscanf(file, "%d", &value);
		printf("%d ", value);
		InsertNode(&Tree, value);
	}
	fclose(file);
	cout << endl;

	cout << "Двоичное дерево поиска: " << endl;
	PrintTree(Tree);
	cout << endl;
	cout << endl;

	//задание 2.в
	cout << "Методы обхода дерева: \n" << "1) Корень - левый - правый; \n" << "2) Левый - корень - правый; \n"
		<< "3) Левый - правый - корень. \n" << "Введите номер метода для обхода дерева: ";
	cin >> input;

	//задание 2.а
	switch (input)
	{
	case 1:
		cout << "Обход дерева по методу 'корень - левый - правый': " << endl;
		RootLeftRight(Tree);
		cout << endl;
		break;
	case 2:
		cout << "Обход дерева по методу 'левый - корень - правый': " << endl;
		LeftRootRight(Tree);
		cout << endl;
		break;
	case 3:
		cout << "Обход дерева по методу 'левый - правый - корень': " << endl;
		LeftRightRoot(Tree);
		cout << endl;
		break;
	default:
		cout << "Вы ввели некорретный номер метода!" << endl;
		break;
	}	
	cout << endl;

	//задание 2.б
	cout << "Введите число для поиска в дереве: ";
	cin >> input;
	Node *temp_root = FindNodeInTree(Tree, input);
	if (temp_root == NULL) cout << "Не найдено такого элемента." << endl;
	else
	{
		cout << "Такой элемент есть:\t";
		cout << temp_root->data << "(";
		if (temp_root->left == NULL) cout << "NULL";
		else cout << temp_root->left->data;
		cout << ", ";
		if (temp_root->right == NULL) cout << "NULL";
		else cout << temp_root->right->data;
		cout << ")" << endl;
	}

	system("Pause");
	return 1;
}