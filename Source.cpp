#include "Header.h"
#include <conio.h>
#include<iostream>
using namespace std;
int thebest1()
{
	setlocale(LC_ALL, "Russian");

	double total = 0;
	double eps;
	cout << "eps= ";
	cin >> eps;

	for (long i = 0;; i++)
	{
		double a = 1.0;
		if (i != 0)
		{
			long k = i;
			while (k >= 1) { a = -2 * a; k--; }
		}
		else(a = 1.0);
		double b = 1.0;
		for (long j = i; ; j++)
		{
			if (j != 0)
			{
				long e = j;
				while (e >= 1) { b = b * e; e--; }
			}break;
			if (j == 0) { b = 1; }break;
		}

		double sum = 0;
		sum = a / b;
		if (abs(sum) > eps) { total = total + sum; }
		else if (abs(sum) <= eps) { break; }
	}
	cout << "Сумма= " << total << endl;
	int code;
	cout << "Если хотите вернуться в меню, нажмите ПРОБЕЛ";
	code = _getch();
	if (code == 32) { main(); }
	else return 0;
}

double fact(int i)
{
	if (i == 0) return 1;
	else return i * fact(i - 1);
}

double sum(double eps)
{
	double rez = 0, cur = 0;
	bool flag = true;
	int i = 0;
	while (flag) {
		cur = (pow((-2), i) / fact(i));
		if (abs(cur) <= eps)break;
		rez += cur;
		++i;
	}
	return rez;
}
int m1() {
	setlocale(LC_ALL, "Russian");
	double eps;
	do {
		cout << "Введите эпсилон: ";
		cin >> eps;
	} while (eps < 0);
	cout << "Результат: ";
	cout << sum(eps);
	cout << endl;
	int code;
	cout << "Если хотите вернуться в меню, нажмите ПРОБЕЛ";
	code = _getch();
	if (code == 32) { main(); }
	else return 0;
}
int m3()
{

	int k;
	setlocale(LC_ALL, "Russian");
	cout << "`````````````WARNING!!!!!```````````" << endl;
	cout << "Работает только с английским языком" << endl;
	char s1[256];
	cout << "Введите первую строку" << endl;
	cin.getline(s1, 256);
	char s2[256];
	cout << "Введите вторую строку" << endl;
	cin.getline(s2, 256);
	cout << "Введите порядковый номер символа в строке 1, который искать во второй строке ";
	cin >> k;
	while (k<1 && k>strlen(s1))
	{
		cout << "Ну нема символа с таким порядковым номером. Попробу еще";
		cin >> k;
	}
	for (int i = 0; i < strlen(s2); i++) {
		if (s2[i] == s1[k - 1]) { cout << i + 1 << " - номер первого вхождения сивола из первой строки во вторую"; break; }
	}
	int code;
	cout << "Если хотите вернуться в меню, нажмите ПРОБЕЛ";
	code = _getch();
	if (code == 32) { main(); }
	else return 0;
}
int m4()
{
	setlocale(LC_ALL, "Russian");
	char s[256];
	cout << "Введите строку" << endl;
	cin.getline(s, 256);
	for (int i = 0; i < strlen(s); i++)
	{
		if (s[strlen(s) - 1] == s[i]) {
			for (int j = i - 1; j >= 0; j--)
			{
				s[strlen(s)] = s[j];
				s[strlen(s) + 1] = '\0';
			}
		}break;
		if (s[strlen(s) - 2] != s[strlen(s) - 1]) {
			for (int j = i - 1; j >= 0; j--)
			{
				s[strlen(s)] = s[j];
				s[strlen(s) + 1] = '\0';
			}
		}break;
	}
	int code;
	cout << "Если хотите вернуться в меню, нажмите ПРОБЕЛ";
	code = _getch();
	if (code == 32) { main(); }
	else return 0;
}
int m5()
{
	setlocale(LC_ALL, "Russian");
	cout << "Введите размеры матрицы" << endl;
	int n, m;
	cin >> m;
	cin >> n;
	int** mas = new int* [m];
	for (int i = 0; i < m; ++i)
		mas[i] = new int[n];

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "Заполните матрицу ";
			cin >> mas[i][j];
		}
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << mas[i][j] << " \t";
		}
		cout << "\n";
	}
	int* s = new int[n];
	for (int j = 0; j < n; ++j)
	{
		s[j] = 0;
	}
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < m; i++)
		{
			if (mas[i][j] % 2 != 0 && mas[i][j] < 0)
			{
				s[j] += abs(mas[i][j]);
			}
		}
	}

	int min = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = n-1; j  >=0; j--)
		{
			min = s[j];
			for (int k = j; k < n; ++k)
			{
				if (s[k] < min)
				{
					int temp = mas[i][k];
					mas[i][k] = mas[i][j];
					mas[i][j] = temp;
				}
			}
		}
	}
	cout << "~~~~~Сортируем~~~~" << endl;

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << mas[i][j] << " \t";
		}
		cout << endl;
	}
	cout << endl;
	delete[] s;



	for (int i = 0; i < m; i++)
	{
		delete[] mas[i];
	}
	delete[] mas;

	int code;
	cout << "Если хотите вернуться в меню, нажмите ПРОБЕЛ";
	code = _getch();
	if (code == 32) { main(); }
	else return 0;
}