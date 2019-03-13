/*
3. Написать программу, которая определяет, является ли введённая скобочная последовательность правильной.
Примеры правильных скобочных выражений – (), ([])(), {}(), ([{}]), неправильных – )(, ())({), (, ])}), ([(]), для скобок – [, (, {.
Например: (2+(2*2)) или [2/{5*(4+7)}].
5. Реализовать алгоритм перевода из инфиксной записи арифметического выражения в постфиксную.
*/

#include <iostream>
#include <string>
using namespace std;

#define T int

struct TNode
{
	T value;                  // Данные
	struct TNode *next;       // Указатель на следующий элемент списка
};
typedef TNode Node;
Node* head = NULL;

void Push(T value)
{
	Node *temp;
	temp = (Node*)malloc(sizeof(Node));
	temp->value = value;
	temp->next = head;
	head = temp;
}

T Pull()
{
	Node* temp = NULL;
	T value = head->value;
	temp = head;
	head = head->next;
	free(temp);
	return value;
}

int CheckExpression(string str)
{
	int error_flag = 0;

	for (int i = 0; i < str.length(); i++)
	{
		switch (str[i])
		{
		case '[':
		case '{':
		case '(':
			Push(str[i]);
			break;
		case ']':
			if (head == NULL || Pull() != '[') error_flag++;
			break;
		case '}':
			if (head == NULL || Pull() != '{') error_flag++;
			break;
		case ')':
			if (head == NULL || Pull() != '(') error_flag++;
			break;
		}
	}

	if (head != NULL) error_flag++;

	return error_flag;
}

bool isOperator(char c)
{
	return (c == '+' || c == '-' || c == '/' || c == '*');
}
int getPriority(char c)
{
	if (c == '-' || c == '+') return 1;
	else if (c == '*' || c == '/') return 2;
	else return 0;
}

void ConvertToPostfix(string str)
{
	string postfix_string;
	char tmp;

	str = '[' + str + ']';  //внешние скобки, чтобы не вылетать в исключение при первом появившемся знаке

	for (int i = 0; i < str.length(); i++)
	{
		if (isdigit(str[i]))
		{
			postfix_string += str[i];
			if (!isdigit(str[i+1])) postfix_string += ' ';
		}
				
		else if (str[i] == '(') Push(str[i]);
		else if (str[i] == ')')
		{
			tmp = Pull();
			while (tmp != '(')
			{
				postfix_string += tmp;
				postfix_string += ' ';
				tmp = Pull();
			}
		}
		else if (str[i] == '{') Push(str[i]);
		else if (str[i] == '}')
		{
			tmp = Pull();
			while (tmp != '{')
			{
				postfix_string += tmp;
				postfix_string += ' ';
				tmp = Pull();
			}
		}
		else if (str[i] == '[') Push(str[i]);
		else if (str[i] == ']')
		{
			tmp = Pull();
			while (tmp != '[')
			{
				postfix_string += tmp;
				postfix_string += ' ';
				tmp = Pull();
			}
		}
		else if (isOperator(str[i]))
		{
			tmp = Pull();
			if (isOperator(tmp))
			{
				if (getPriority(tmp) >= getPriority(str[i]))
				{
					Push(str[i]);
					postfix_string += tmp;
					postfix_string += ' ';
				}
				else
				{
					Push(tmp);
					Push(str[i]);
				}				
			}
			else
			{
				Push(tmp);
				Push(str[i]);
			}			
		}
	}


	std::cout << endl << "Введенная строка в постфиксном виде:" << endl;
	std::cout << postfix_string << endl;
}

int main(int argc, char** args)
{
	string Input;

	setlocale(LC_CTYPE, "Russian");

	std::cout << "Введите выражение в инфиксном виде:" << endl;
	getline(cin, Input);


	if (CheckExpression(Input)) std::cout << "Проверьте правильность скобок в введенном выражении!" << endl;
	else ConvertToPostfix(Input);

	system("Pause");
	return 1;
}