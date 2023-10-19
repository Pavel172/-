#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include <Windows.h>
using namespace std;


void Task1()
{
	setlocale(LC_ALL, "Rus");
	cout << "\n\nЗадание 1" << endl;
	cout << "\nВведите количество элементов массива: ";
	int N = 0, l = 0;
	double h = 0;
	cin >> N;
	double* arr;
	arr = new double[N];
	cout << "\nВведите каждый элемент массива: ";

	for (int j1 = 0; j1 < N; j1++)
	{
		cin >> arr[j1];
		l++;
	}
	cout << endl;
	cout << "Элементы массива, увеличенные в 2 раза: ";
	for (int j2 = 0; j2 < l; j2++)
	{
		cout << arr[j2] * 2 << " ";
	}
	cout << endl;
	cout << "\nВведите число, на которое нужно уменьшить каждый элемент массива: ";
	cin >> h;
	cout << "\nЭлементы массива, уменьшенные на " << h << ": ";
	for (int j3 = 0; j3 < l; j3++)
	{
		cout << arr[j3] - h << " ";
	}
	cout << endl;
	cout << "\nЭлементы массива, разделенные на первый элемент массива(" << arr[0] << "): ";
	for (int j4 = 0; j4 < l; j4++)
	{
		cout << arr[j4] / arr[0] << " ";
	}
	cout << endl << endl;
	delete[] arr;
}


void Task2()
{
	setlocale(LC_ALL, "Rus");
	cout << "\n\nЗадание 2" << endl;
	cout << "\nВведите количество элементов массива: ";
	int N = 0, l = 0, k1 = 0, k2 = 0, s1 = 0, s2 = 0, m = 0, N1 = 0, q = 0;
	double v = 0, p = 0, f2 = 0, f3 = 0, f = 0, f4 = 0;
	cin >> N;
	double* arr;
	arr = new double[N];
	cout << "\nВведите каждый элемент массива: ";
	for (int j1 = 0; j1 < N; j1++)
	{
		cin >> arr[j1];
		l++;
	}
	cout << "\nСумма всех элементов массива: ";
	for (int j5 = 0; j5 < l; j5++)
	{
		v = v + arr[j5];
	}
	cout << v << " " << endl;
	cout << "\nСумма квадратов всех элементов массива: ";
	for (int j6 = 0; j6 < l; j6++)
	{
		p = p + pow(arr[j6], 2);
	}
	cout << p << " " << endl;
	cout << "\nСумма первых 6 элементов массива: ";
	for (int j7 = 0; j7 < 6; j7++)
	{
		f = f + arr[j7];
	}
	cout << f << " " << endl;
	cout << "\nВведите k1 и k2 элементы массива: ";
	cin >> k1 >> k2;
	cout << "\nСумма элементов массива c k1(" << k1 << ")-го по k2(" << k2 << ")-й элемент массива: ";
	k2--, k1--;
	for (; k1 <= k2; k1++)
	{
		f2 = f2 + arr[k1];
	}
	cout << f2 << " " << endl;
	cout << "\nСреднее арифметическое всех элементов массива: ";
	for (int j8 = 0; j8 < N; j8++)
	{
		f3 = f3 + arr[j8];
	}
	cout << f3 / N << " " << endl;
	cout << "\nВведите s1 и s2 элементы массива: ";
	cin >> s1 >> s2;
	cout << "\nСреднее арифметическое всех элементов массива c s1(" << s1 << ")-го по s2(" << s2 << ")-й элемент массива: ";
	s2--, s1--;
	for (; s1 <= s2; s1++)
	{
		f4 = f4 + arr[s1];
		m++;
	}
	delete[] arr;
	cout << f4 / m << " " << endl;
}


void Task3()
{
	int N2 = 20, l2 = 0;
	setlocale(LC_ALL, "Rus");
	cout << "\n\nЗадание 3" << endl;
	double* arr2;
	arr2 = new double[N2];
	cout << "\nВведите каждый элемент массива(20 элементов): ";

	for (int j1 = 0; j1 < N2; j1++)
	{
		cin >> arr2[j1];
		l2++;
	}
	cout << "\nМассив, в котором первые три и последние три элемента переставлены местами: " << endl << endl;
	swap(arr2[0], arr2[17]);
	swap(arr2[1], arr2[18]);
	swap(arr2[2], arr2[19]);
	for (int i = 0; i < 20; i++)
	{
		cout << "arr3[" << i << "] = " << arr2[i] << endl;
	}
	cout << endl;
	delete[] arr2;
}


void Task4()
{
	setlocale(LC_ALL, "Rus");
	int N = 0, t = 0, x = -1, y = 0, z = -1, m = 0;
	cout << "\n\nЗадание 4" << endl;
	cout << "\nВведите количество элементов массива: ";
	cin >> N;
	cout << "\nВведите каждый элемент массива: ";
	vector <int> vec1;
	for (int i = 0; i < N; i++)
	{
		cin >> m;
		vec1.push_back(m);
	}
	cout << "\nМассив без первого отрицательного и без последнего чётного элементов: ";
	for (int n = 0; n < N; n++)
	{
		if (vec1[n] < 0 && t == 0)
		{
			x = n;
			t++;
		}
		if (vec1[N - n - 1] % 2 == 0 && y == 0)
		{
			z = N - n - 1;
			y++;
		}
	}
	if (x >= 0) 
	{
		vec1.erase(vec1.begin() + x);
	}
	if (z >= 0 && x >= 0 && z > x) 
	{
		vec1.erase(vec1.begin() + z - 1);
	}
	if (z >= 0 && x >= 0 && z < x) 
	{
		vec1.erase(vec1.begin() + z);
	}
	if (z > -1 && x == -1) 
	{
		vec1.erase(vec1.begin() + z);
	}
	if (t == 1) 
	{
		N--;
	}
	if (y == 1) 
	{
		N--;
	}
	for (int n = 0; n < N; n++)
	{
		cout << vec1[n] << " ";
	}
	cout << endl << endl;
}


void Task5()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "\n\nЗадание 5" << endl;
	cout << "\nВведите название города: ";
	int k4 = 0;
	string str1;
	cin >> str1;
	int k3 = str1.size();
	if (k3 % 2 == 0)
	{
		cout << "\nКоличество символов чётное";
	}
	else
	{
		cout << "\nКоличество символов нечётное";
	}
	cout << endl << endl;
}


void Task6()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "\n\nЗадание 6" << endl;
	cout << "\nВведите первую фамилию: ";
	int k7 = 0;
	string str2;
	cin >> str2;
	cout << "\nВведите вторую фамилию: ";
	string str3;
	cin >> str3;
	int k5 = str2.size(), k6 = str3.size();
	if (k5 > k6)
	{
		cout << "\ntrue";
	}
	else
	{
		cout << "\nfalse";
	}
	cout << endl << endl;
}


void Task7()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "\n\nЗадание 7" << endl;
	cout << "\nВведите название первого города: ";
	int k8 = 0;
	string stri1;
	cin >> stri1;
	cout << "\nВведите название второго города: ";
	string stri2;
	cin >> stri2;
	cout << "\nВведите название третьего города: ";
	string stri3;
	cin >> stri3;
	string the_longest;
	string the_shortest;
	for (int st1 = stri1.size(), st2 = stri2.size(), st3 = stri3.size(); k8 < 1; k8++)
	{
		if ((st1 > st2) && (st1 > st3))
		{
			the_longest = stri1;
		}
		if ((st2 > st1) && (st2 > st3))
		{
			the_longest = stri2;
		}
		if ((st3 > st1) && (st3 > st2))
		{
			the_longest = stri3;
		}
		if ((st1 < st2) && (st1 < st3))
		{
			the_shortest = stri1;
		}
		if ((st2 < st1) && (st2 < st3))
		{
			the_shortest = stri2;
		}
		if ((st3 < st1) && (st3 < st2))
		{
			the_shortest = stri3;
		}
		cout << "\nthe_longest: " << the_longest << endl;
		cout << "\nthe_shortest: " << the_shortest;
	}
	cout << endl << endl;
}


void Task8()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "\n\nЗадание 8" << endl;
	cout << "\nВведите слово: ";
	int k9 = 0;
	string slovo;
	cin >> slovo;
	int k10 = slovo.size();
	slovo.insert(slovo.begin(), k10, '*');
	slovo.insert(slovo.end(), k10, '*');
	cout << "\nСлово: " << slovo;
	cout << endl << endl;
}


void Task9()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "\n\nЗадание 9" << endl;
	cout << "\nВведите предложение: ";
	string predl1;
	cin.ignore();
	getline(cin, predl1);
	cout << "\nВведите букву, долю (в %) которой нужно определить в предложении: ";
	int k12 = 0, colvo1 = 0;
	char byk;
	cin >> byk;
	int k13 = predl1.length();
	for (int k11 = predl1.length(); k11 >= 0; k11--)
	{
		if (predl1[k11] == byk)
		{
			colvo1++;
		}
		if (predl1[k11] == ' ')
		{
			k13--;
		}
	}
	cout << "\nДоля буквы " << byk << " в введённом предложении = " << ((double)colvo1 / k13) * 100 << "%" << endl;
	cout << endl << endl;
}


void Task10()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "\n\nЗадание 10" << endl;
	string predl2("Can you can a can as a canner can can a can ?");
	string can = "can ";
	string Can = "Can ";
	string nw = "new_word ";
	size_t pos1;
	size_t pos2;
	while ((pos1 = predl2.find(can)) != -1)
	{
		predl2.erase(pos1, can.size());
		predl2.insert(pos1, nw);
	}
	if ((pos2 = predl2.find(Can)) != -1)
	{
	    predl2.erase(pos2, Can.size());
	    predl2.insert(pos2, nw);
	}
	cout << endl;
	cout << predl2 << endl << endl;
}


int main()
{
Met1:
	cout << "Please enter task number " << endl;
	int task_number = 0;
	cin >> task_number;
	switch (task_number)
	{
	case 1:
		Task1();
		goto Met1;
	case 2:
		Task2();
		goto Met1;
	case 3:
		Task3();
		goto Met1;
	case 4:
		Task4();
		goto Met1;
	case 5:
		Task5();
		goto Met1;
	case 6:
		Task6();
		goto Met1;
	case 7:
		Task7();
		goto Met1;
	case 8:
		Task8();
		goto Met1;
	case 9:
		Task9();
		goto Met1;
	case 10:
		Task10();
		goto Met1;
	}
	return 0;
}