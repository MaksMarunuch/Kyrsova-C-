#pragma once

#include "Teacher.h"

void AddSchoolchildren(Data* (&d), int& n)
{
	cout << "How many schoolchildren you want to add\n";
	cin >> n;

	d = new Data[n];

	for (int i = 0; i < n; i++)
	{
		cout << "Enter name schoolchildren\n ";
		cin >> d[i]._schoolchildren.name_schoolchildren;
		cout << "Enter surname\n ";
		cin >> d[i]._schoolchildren.surname_schoolchildre;
		cout << "Enter class\n ";
		cin >> d[i]._schoolchildren.Class;
		cout << "Enter number parents\n ";
		cin >> d[i]._schoolchildren.number_parents;
		cout << "Enter numbers schoolchildren\n ";
		cin >> d[i]._schoolchildren.number_schoolchildren;
		cout << "Enter email schoolchildren\n ";
		cin >> d[i]._schoolchildren.email_schoolchildren;
	}
}

void AddSubjects(Data* (&d), int& n)
{
	cout << "How many subjects you want to add\n";
	cin >> n;

	d = new Data[n];

	for (int i = 0; i < n; i++)
	{
		cout << "Enter name subject\n";
		cin >> d[i]._subjects.subjecst;
	}

}

void AddTeacher(Data* (&d), int& n)
{
	cout << "How many teachers you want to add\n";
	cin >> n;

	d = new Data[n];

	for (int i = 0; i < n; i++)
	{
		cout << "Enter the teacher's name\n";
		cin >> d[i]._teacher.name_teacher;
		cout << "Enter first name\n";
		cin >> d[i]._teacher.surname_teacher;
		cout << "Enter ade\n";
		cin >> d[i]._teacher.age;
		cout << "Enter email\n";
		cin >> d[i]._teacher.email_teacher;
	}
}

void ShowTeacher(Data* d, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Data - " << n + 1 << endl;
		cout << "Name:" <<d[i]._teacher.name_teacher << " " << d[i]._teacher.surname_teacher << endl;
		cout << "Age:" << d[i]._teacher.age << endl;
		cout << "Email:" << d[i]._teacher.email_teacher << endl;
	}
}

void ShowSubjects(Data* d, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Subjects:" << d[i]._subjects.subjecst << endl;
	}
}

void Showchoolchildren(Data* d, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Data ¹" << n + 1 << endl;
		cout << "Name:" << d[i]._schoolchildren.name_schoolchildren << " " << d[i]._schoolchildren.surname_schoolchildre << endl;
		cout << "Class:" << d[i]._schoolchildren.Class << endl;
		cout << "Number parents:" << d[i]._schoolchildren.number_parents << endl;
		cout << "Number schoolchildren:" << d[i]._schoolchildren.number_schoolchildren << endl;
		cout << "Email:" << d[i]._schoolchildren.email_schoolchildren << endl;
	}
}

void ReadTeacher(Data* (&d), int n)
{
	int _n;
	cout << "Enter number elements (1-" << n + 1 << "):";
	cin >> _n;
	_n--;
	
	if (_n >= 0 && _n < n)
	{
		cout << "Enter the teacher's name, first name, age and age email\n";
		cin >> d[_n]._teacher.name_teacher;
		cin >> d[_n]._teacher.surname_teacher;
		cin >> d[_n]._teacher.age;
		cin >> d[_n]._teacher.email_teacher;
	}
}

void Delete(Data* (&d), int& n)
{
	int _n;
	cout << "Enter number elements (1-" << n + 1 << "):";
	cin >> _n;
	_n--;

	if (_n >= 0 && _n < n)
	{
		Data* buf = new Data[n];

		Copy(buf, d, n);

		--n;
		d = new Data[n];

		int q = 0;

		for (int i = 0; i <= n; i++)
		{
			if (i != _n)
			{
				d[q] = buf[i];
				++q;
			}
		}
		delete[]buf;
		cout << "Data delete succes\n";
	}
	else
		cout << "Error,number incorect\n";
}

void Copy(Data* (&d_n), Data* (&d_o), int n)
{
	for (int i = 0; i < n; i++)
	{
		d_n[i] = d_o[i];
	}
}

void CopyForSorting(Data&d_n,Data& d_o)
{
	d_n._teacher.name_teacher = d_o._teacher.name_teacher;
	d_n._teacher.surname_teacher= d_o._teacher.surname_teacher;
	d_n._teacher.age = d_o._teacher.age;
	d_n._teacher.email_teacher = d_o._teacher.email_teacher;
}

void SortingTeacherName(Data* d, int n)
{
	Data buf;

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (d[i]._teacher.name_teacher > d[j]._teacher.name_teacher)
			{
				CopyForSorting(buf, d[j]);
				CopyForSorting(d[j], d[i]);
				CopyForSorting(d[i], buf);
			}
		}
	}
	cout << "Sorrting succes\n";
} 

void SortingStudentName(Data* d, int n)
{
	Data buf;

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (d[i]._schoolchildren.name_schoolchildren > d[j]._schoolchildren.name_schoolchildren)
			{
				CopyForSorting(buf, d[j]);
				CopyForSorting(d[j], d[i]);
				CopyForSorting(d[i], buf);
			}
		}
	}
	cout << "Sorrting succes\n";
}

void ReadingInput(Data* (&d), int& n, string file)
{
	ifstream reading(file);
	{
		if (reading)
		{
			cout << "How many teachers you want to add\n";
			cin >> n;

			d = new Data[n];

			for (int i = 0; i < n; i++)
			{
				reading >> d[i]._teacher.name_teacher;
				reading >> d[i]._teacher.surname_teacher;
				reading >> d[i]._teacher.age;
				reading >> d[i]._teacher.email_teacher;
			}
		}
		else
			cout << "Error\n";
		reading.close();
	}
}