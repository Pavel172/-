#include <iostream>
#include <stack>
#include <math.h>
using namespace std;

struct sort
{
	char type;
	double value;
};

bool solve(stack <sort> & numbers, stack <sort> & operations, sort & elem)
{
	double num1, num2, resh;
	num1 = numbers.top().value;
	numbers.pop();
	switch(operations.top().type)
	{
	case '+':
		num2 = numbers.top().value;
		numbers.pop();
		resh = num1 + num2;
		elem.type = '0';
		elem.value = resh;
		numbers.push(elem);
		operations.pop();
		break;

	case '-':
		num2 = numbers.top().value;
		numbers.pop();
		resh = num2 - num1;
		elem.type = '0';
		elem.value = resh;
		numbers.push(elem);
		operations.pop();
		break;

	case '*':
		num2 = numbers.top().value;
		numbers.pop();
		resh = num1 * num2;
		elem.type = '0';
		elem.value = resh;
		numbers.push(elem);
		operations.pop();
		break;

	case '/':
		num2 = numbers.top().value;
		if ( num1 == 0)
		{
			cerr << "\nОшибка. Делить на 0 нельзя.\n";

			return false;
		}
		else
		{
			numbers.pop();
			resh = num2 / num1;
			elem.type = '0';
			elem.value = resh;
			numbers.push(elem);
			operations.pop();
			break;
		}
	case '^':
		num2 = numbers.top().value;
		numbers.pop();
		resh = pow(num2, num1);
		elem.type = '0';
		elem.value = resh;
		numbers.push(elem);
		operations.pop();
		break;
	default:
		cerr << "\nОшибка!\n";
		return false;
		break;
	}
	return true;
}

int priority(char h)
{
	if (h == '^')
	{
		return 3;
	}
	if (h == '+' or h == '-')
	{
		return 1;
	}
	if (h == '*' or h == '/')
	{
		return 2;
	}
	else
	{
		return 0;
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "Введите выражение: ";
	char h;
	stack <sort> numbers;
	stack <sort> operations;
	sort elem;
	double value;
	bool minus = 1;
	while(true)
	{
		h = cin.peek();
		if (h == '\n'){break;}
		if (h == ' ')
		{
			cin.ignore();
			continue;
		}
		if (h >= '0' && h <= '9' or h == '-' && minus == 1)
		{
			cin >> value;
			elem.type = '0';
			elem.value = value;
			numbers.push(elem);
			minus = 0;
			continue;
		}
		if (h == '+' or h == '-' && minus == 0 or h == '*' or h == '/' or h == '^')
		{
			if (operations.size() == 0)
			{
				elem.type = h;
				elem.value = 0;
				operations.push(elem);
				cin.ignore();
				continue;
			}
			if (operations.size() != 0 && priority(h) > priority(operations.top().type))
			{
				elem.type = h;
				elem.value = 0;
				operations.push(elem);
				cin.ignore();
				continue;
			}
			if (operations.size() != 0 && priority(h) <= priority(operations.top().type))
			{
				if (solve(numbers, operations, elem) == false)
				{
					system("pause");
					return 0;
				}
				continue;
			}
		}
		if (h == '(')
		{
			minus = 1;
			elem.type = h;
			elem.value = 0;
			operations.push(elem);
			cin.ignore();
			continue;
		}
		if (h == ')')
		{
			while(operations.top().type != '(')
			{
				if (solve(numbers, operations, elem) == false)
				{
					system("pause");
					return 0;
				}
				else
				{
					continue;
				}
			}
			operations.pop();
			cin.ignore();
			continue;
		}
		else
		{
			cout << "\nНеверно введено выражение\n";
			system("pause");
			return 0;
		}
	}
	while(operations.size() != 0)
	{
		if (solve(numbers, operations, elem) == false)
		{
			system("pause");
			return 0;
		}
		else
		{
			continue;
		}
	}
	cout << "\nОтвет: " << numbers.top().value;
	cout << endl;
	return 0;
}
