
#include "stdafx.h" 
#include <iostream> 
#include <fstream> 
#include <cstdlib>
using namespace std;
struct ych
{
	char lastname[20];
	double sumBall;
	int kolBall;
};

void out(ych *a, int size)//����� �� ����� / � ���� 
{
	size = 3;
	cout << "1.�� �����\n2.� ����" << endl;
	int x;
	cin >> x;
	if (x == 1)
	{
		cout << "������� ����" << endl;
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
		cout << "������� ��� ����� ";
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

int openFile(char *name,ych  *a)//�������� ����� � ����������
{
	ifstream fin;
	fin.open(name);
	if (!fin.is_open())
	{
		cout << "error open";
		system("pause");
		exit(1);
	}


	int ball, i = 0;
	while (!fin.eof())
	{
		
		a = (ych*)realloc(a,((i+1)*sizeof(ych)));
		
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
	out(a, i);
	

}


int main()
{
	ych*a;
	a = (ych*)malloc(1);
	
	setlocale(LC_ALL, "rus");
	
	char namefile[20];
	cout << "������� ��� �����" << endl;
	cin >> namefile;
	int size;
	size = openFile(namefile, a);

	return 0;
}

