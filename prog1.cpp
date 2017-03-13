#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string>
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	string a, b;
	unsigned int n = 0;
	bool t = true;
	char stroka[64], stroka2[64];
	FILE *F1;
	fopen_s(&F1, "C:\\Users\\Max\\Desktop\\Visual\\MyBook1.txt", "r");
	FILE *F2;
	fopen_s(&F2, "C:\\Users\\Max\\Desktop\\Visual\\MyBook2.txt", "r");
	if (F1 == 0)
	{
		cout << "Error, file not found" << endl;
		return 1;
	}
	while (true)
	{
		n++;
		fscanf(F1, "%s\n", stroka);
		while (t)
		{
			fscanf(F2, "%s\n", stroka2);
			a = stroka;
			b = stroka2;
			if (a == b)
				break;
			if (feof(F2) != 0)
			{
				t = false;
				cout << "File1 " << n << " " << stroka << endl;
			}
		}
		t = true;
		rewind(F2);
		if (feof(F1) != 0)
			break;
	}
	rewind(F1);
	t = true;
	n = 0;
	while (true)
	{
		n++;
		fscanf(F2, "%s\n", stroka2);
		while (t)
		{
			fscanf(F1, "%s\n", stroka);
			a = stroka;
			b = stroka2;
			if (b == a)
				break;
			if (feof(F1) != 0)
			{
				t = false;
				cout << "File2 " << n << " " << stroka2 << endl;
			}
		}
		t = true;
		rewind(F1);
		if (feof(F2) != 0)
			break;
	}
	fclose(F1);
	fclose(F2);
	_getch();
	return 0;
}
