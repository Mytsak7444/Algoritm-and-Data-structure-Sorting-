#include <iostream>
#include <string.h>
#include <iomanip>
#include <ctime>
#include <stdlib.h>
using namespace std;

const int size=10;
int first, last;

struct INF
	{
	int key;
	char info[64];
	};

INF str[size];

void Create()
	{
	srand(1);
	for (int i=0; i<size; i++)
		{
		cout << "Enter key:" << endl;
		cin >> str[i].key;
		cin.ignore();
		cout << "Enter info: " <<endl;
		gets(str[i].info);
		}
	}

void Print()
	{
	for (int i=0; i<size; i++)
		{
		cout << str[i].key << ". ";
		cout << str[i].info << endl;
		}
	}

void Sort(int first, int last)
	{
	int mid;
	INF temp;
	int f=first, l=last;
	mid=str[(f+l) / 2].key;
	do
		{
		while (str[f].key<mid) f++;
		while (str[l].key>mid) l--;
		if (f<=l)
			{
			temp.key=str[f].key;
			*temp.info=*str[f].info;
			str[f].key=str[l].key;
			*str[f].info=*str[l].info;
			str[l].key=temp.key;
			*str[l].info=*temp.info;
			f++;
			l--;
			}
		}
	while (f<l);
	if (first<l) Sort(first, l);
	if (f<last) Sort(f, last);
	}

int main()
	{
	first=0;
	last=size-1;
	Create();
	system("cls");
	cout << "Youre struct:" << endl;
	Print();
	cout << "Sorted struct:" << endl;
	Sort(first, last);
	Print();
	}

