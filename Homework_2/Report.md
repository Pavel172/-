**<h1 align="center">Homework #2 report**</a>
<h2 align="center">Калькулятор</h2>
<h3 align="center">Блок-схема</h3>


![Alt-block diagram](https://github.com/Pavel172/-/blob/main/Homework_2/Блок%20схема.png)




<h3 align="center">Объяснение кода</h3>
Калькулятор создан на основе стеков, и в нём присутствуют математические операции, поэтому подключаем соответствующие заголовочные файлы

```
#include <iostream>
#include <stack>
#include <math.h>
using namespace std;
```
Для удобства и обхода проблем мы разделяем каждый элемент (операцию, число) с помощью структуры sort на:
1) type, который определяет, чем является элемент (операция или число), у чисел тип = 0, у операций он соответствует операции (например: у + тип "+" и тд.).
2) value, который определяет значение элемента, у чисел оно соответствует их значению ( например: у 5 значение "5" и тд.), а у операций значение = 0.

```
struct sort
{
	char type;
	double value;
};
```

Для правильной работы калькулятора мы должны разделять все операции по приоритету. Делаем мы это с помощью функции priority. В неё мы передаём операцию h, и в зависимости от её приоритета функция возвращает какое-либо значение. В программе это значение сравнивается с значением другой операции для того, чтобы узнать очередность их выполнения.

```
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
```

Главная часть кода. Сначала мы инициализируем переменную типа char h, с её помощью мы сможем просматривать элементы выражения (при помощи h = cin.peek();) и определять, операцией или числом они являются, а в дальнейшем при помощи cin присваивать их переменной value.  Далее мы инициализируем стеки с числами (stack <sort> numbers) и операциями (stack <sort> operations), их типом ставим sort, чтобы каждый элемент имел тип(type) и значение(value). Инициализируем переменную elem типа sort, с её помощью мы будем присваивать числам и операциям значение и тип (value и type). Переменная value нужна, чтобы в неё мы по очереди помещали числа и операции для последующей работы с ними ( это будет делаться при помощи cin >> value;)

```
int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "Введите выражение: ";
	char h;
	stack <sort> numbers;
	stack <sort> operations;
	sort elem;
	double value;
```
Здесь мы инициализируем флаг minus, придаём ему значение 1, в дальнейшем он поможет определить отрицательные числа. Далее начинается цикл, при помощи которого мы по очереди просматриваем элементы через h = cin.peek(); до конца выражения и если встречается пробел, то игнорируем его.

```
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
```
Если просматриваемый элемент выражения является числом, то он помещается в переменную value, ему присваивается тип "0" (elem.type = '0';) , т.к. это число. А его значением станет само же число (elem.value = value;), после чего мы помещаем его в стек с числами и продолжаем цикл. Также, так как флаг мы установили равным 1 (bool minus = 1;), мы проверяем, есть ли минус перед числом и если он есть, то число мы записываем как отрицательное (это работает только с первым числом всего выражения, так как перед ним минус может быть лишь частью числа, а не операцией, и с первым числом после открытия скобок "("). Если же перед числом минуса нет, то мы записываем его как положительное. И перед концом ставим значение флага minus = 0, дальше любой минус программа будет считать операцией (но если встретятся скобки "()", то перед ними мы снова ставим значение флага minus = 1, так как первое число в них также может быть отрицательным).
```
		if (h >= '0' && h <= '9' or h == '-' && minus == 1)
		{
			cin >> value;
			elem.type = '0';
			elem.value = value;
			numbers.push(elem);
			minus = 0;
			continue;
		}

```

Если же элемент является операцией, и стек с операциями пуст, то мы помещаем операцию в этот стек, присваивая ей тип, равный самой операции, а также значение = 0, так как операция - это не число. Но если в стеке с операциями уже есть операция, то мы сравниваем их приоритеты и у нас есть два варианта:
1) Приоритет нашей операции больше приоритета операции, которая лежит в стеке. Тогда мы просто кладём нашу операцию в стек.
2) Приоритет операции, уже лежащей в стеке, больше или равен приоритету нашей операции. Тогда мы не кладём нашу операцию в стек, а продолжаем цикл.

Также, в конце части кода заканчивается первый цикл (он начинался с while(true)).

```
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
```
Далее мы проверяем, является ли элемент скобкой. Если он является "(" скобкой, то мы ставим значение флага minus = 1, так как сразу за скобкой может быть отрицательное число. И присваиваем тип и значение элементу так же, как присваивали их операциям и числам. Так как у скобки большой приоритет, то программа начнет решать именно выражения в скобках, пока не встретит скобку ")".

```
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
```
Здесь мы вызываем функцию solve для решения выражения из чисел и операций, проверяя, не пуст ли стек с операциями. И если он пуст, то единственное число, находящееся в стеке с числами и есть ответ на наше выражение.

```
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
```


Здесь реализована функция solve, в нее мы передаём числа и операции из стеков и их значения (value) и типы (type). Сама функция выбирает из перечня нужную операцию, заранее присвоив значения чисел из стека переменным num1 и num2. После каждой операции числа и операции, которые мы использовали, удаляются, а их результату присваивается тип и значение, после чего он записывается в стек с числами.

```
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
```
