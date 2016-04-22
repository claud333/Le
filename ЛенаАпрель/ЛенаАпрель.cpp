
#include "stdafx.h" 
#include <iostream> 
#include <fstream> 
#include <cstdlib>
#include <vector>
using namespace std;
struct ych
{
	char lastname[20];
	double sumBall;
	int kolBall;
};


int openFile(char *name,ych  *a)//открытие фаила и считывание
{
	ifstream fin;
	fin.open(name);
	if (!fin.is_open())
	{
		cout << "error open";
		system("pause");
		return 0;
	}


	int ball, i = 0, l = 0;
	while (!fin.eof())
	{
		l+=10;
		a = (ych*)realloc(a, l*sizeof(ych*));
		
		a[i].sumBall = 0;
		a[i].kolBall = 0;
		fin >> a[i].lastname;
		

		while (fin.peek() != '\n' && !fin.eof())
		{
			fin >> ball;
			a[i].sumBall += ball; a[i].kolBall++;
		}
		a[i].sumBall = a[i].sumBall / a[i].kolBall;
		
		i++;
	}
	fin.close();
	 return i;

}
void out(ych *a,int size)//вывод на экран / в фаил 
{
	size = 3;
	cout << "1.На экран\n2.В фаил" << endl;
	int x;
	cin >> x;
	if (x == 1)
	{
		cout << "Средний балл" << endl;
		for (int j = 0;j < size;j++)
		{
			int maxi;
			int max = 0;
			for (int i = 0;i < size;i++)
			{
				if (max < a[i].sumBall) { maxi = i; max = a[i].sumBall; }
			}
			cout << a[maxi].lastname << " " << a[maxi].sumBall << endl;
			a[maxi].sumBall = 0;
		}
	}
	else
	{
		char nameFile[20];
		cout << "Введите имя фаила ";
		cin >> nameFile;
		ofstream fout(nameFile);
		for (int j = 0;j < size;j++)
		{
			int maxi;
			double max = 0;

			for (int i = 0;i < size;i++)
			{
				if (max < a[i].sumBall) { maxi = i; max = a[i].sumBall; }
			}
			fout << a[maxi].lastname << " " << a[maxi].sumBall << endl;
			a[maxi].sumBall = 0;
		}
		fout.close();
	}

	system("pause");
}

int main()
{
	ych*a;
	a = (ych*)malloc(1);
	//a = (ych*) realloc (a, 2 * sizeof(ych));
	setlocale(LC_ALL, "rus");
	//vector<ych> a;
	char namefile[20];
	cout << "Введите имя фаила" << endl;
	cin >> namefile;
	int size;
	if (size=openFile(namefile,a)==0) { return 0; }
	out(a,size);
	return 0;
}

