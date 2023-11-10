#include <iostream>
using namespace std;

struct Matrix
{
	int** matrix = nullptr;
	size_t sto_ = 0u;
	size_t str_ = 0u;
};

void Construct(Matrix& out, size_t sto, size_t str)
{
	out.sto_ = sto;
	out.str_ = str;
	out.matrix = new int*[sto];
	for (int i = 0; i < sto; ++i)
	{
		out.matrix[i] = new int[sto];
	}
	for (int i = 0; i < sto; ++i)
	{
		for (int j = 0; j < str; ++j)
		{
			out.matrix[i][j] = 0;
		}
	}
};

void Destruct(Matrix& out, size_t sto, size_t str)
{
	out.sto_ = sto;
	out.str_ = str;
	for (int i = 0; i < sto; ++i)
	{
		delete[] out.matrix[i];
	}
};

Matrix Copy(Matrix& out, int sto, int str)
{
	Matrix copy;
	Construct(copy, sto, str);
	out.sto_ = sto;
	out.str_ = str;
	
	for (int i = 0; i < sto; ++i)
	{
		for (int j = 0; j < str; ++j)
		{
			copy.matrix[i][j] = out.matrix[i][j];
		}
	}
	return copy;
}

Matrix Add(Matrix& mat1, Matrix& mat2, int sto, int str)
{
	Matrix add;
	Construct(add, sto, str);
	mat1.sto_ = sto;
	mat1.str_ = str;
	mat2.sto_ = sto;
	mat2.str_ = str;
	for (int i = 0; i < sto; ++i)
	{
		for (int j = 0; j < str; ++j)
		{
			add.matrix[i][j] = mat1.matrix[i][j] + mat2.matrix[i][j];
		}
	}
	return add;
};

Matrix Sub(Matrix& mat1, Matrix& mat2, int sto, int str)
{
	Matrix sub;
	Construct(sub, sto, str);
	mat1.sto_ = sto;
	mat1.str_ = str;
	mat2.sto_ = sto;
	mat2.str_ = str;
	for (int i = 0; i < sto; ++i)
	{
		for (int j = 0; j < str; ++j)
		{
			sub.matrix[i][j] = mat1.matrix[i][j] - mat2.matrix[i][j];
		}
	}
	return sub;
};

Matrix Mult(Matrix& mat1, Matrix& mat2, int sto, int str)
{
	Matrix mult;
	Construct(mult, sto, str);
	mat1.sto_ = sto;
	mat1.str_ = str;
	mat2.sto_ = sto;
	mat2.str_ = str;
	for (int i = 0; i < sto; ++i)
	{
		for (int j = 0; j < str; ++j)
		{
			mult.matrix[i][j] = mat1.matrix[i][j] * mat2.matrix[i][j];
		}
	}
	return mult;
};

Matrix Transposition(Matrix& out, int sto, int str)
{
	Matrix transpos;
	out.sto_ = sto;
	out.str_ = str;
	Construct(transpos, str , sto);
	for (int i = 0; i < sto; ++i)
	{
		for (int j = 0; j < str; ++j)
		{
			transpos.matrix[j][i] = out.matrix[i][j];
		}
	}
	return transpos;
};

void Constructrandom(Matrix& out, size_t sto, size_t str)
{
	out.sto_ = sto;
	out.str_ = str;
	out.matrix = new int* [sto];
	for (int i = 0; i < sto; ++i)
	{
		out.matrix[i] = new int[sto];
	}
	for (int i = 0; i < sto; ++i)
	{
		for (int j = 0; j < str; ++j)
		{
			out.matrix[i][j] = rand() % 10;
		}
	}
};

void print(Matrix& out, size_t sto, size_t str)
{
	out.sto_ = sto;
	out.str_ = str;
	for (int i = 0; i < sto; ++i)
	{
		for (int j = 0; j < str; ++j)
		{
			cout << out.matrix[i][j] << " ";
		}
		cout << endl;
	}
};


int main()
{
	setlocale(LC_ALL, "Rus");
	Matrix a, b, copy, add, sub, add, mult, transpos_a, transpos_b, empty;
	int sto, str, sto1, str1;
	cout << "Введите число столбцов и число строк первой матрицы: ";
	cin >> sto >> str;
	cout << "Введите число столбцов и число строк второй матрицы: ";
	cin >> sto1 >> str1;
	cout << endl;
	Constructrandom(a, sto, str);
	Constructrandom(b, sto1, str1);
	cout << "Первая матрица: " << endl;
	print(a, sto, str);
	cout << endl;
	cout << "Вторая матрица: " << endl;
	print(b, sto1, str1);
	cout << endl;
	if (sto != sto1 or str != str1)
	{
		cout << "Ошибка! Матрицы разной размерности, их нельзя складывать, вычитать и умножать." << endl;
		Construct(empty, sto, str);
		cout << "Возвращается пустая матрица: " << endl;
		print(empty, sto, str);
		cout << endl;
	}
	else
	{
		add = Add(a, b, sto, str);
		cout << "Сумма двух матриц: " << endl;
		print(add, sto, str);
		cout << endl;
		sub = Sub(a, b, sto, str);
		cout << "Разница двух матриц: " << endl;
		print(sub, sto, str);
		cout << endl;
		mult = Mult(a, b, sto, str);
		cout << "Произведение двух матриц: " << endl;
		print(mult, sto, str);
		cout << endl;
	}
	cout << "Транспонированная первая матрица: " << endl;
	transpos_a = Transposition(a, sto, str);
	print(transpos_a, str, sto);
	cout << endl;
	cout << "Транспонированная вторая матрица: " << endl;
	transpos_b = Transposition(b, sto1, str1);
	print(transpos_b, str1, sto1);
	cout << endl;
	//Destruct(a, sto, str);
	return 0;
}