#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

struct Teacher
{
	string name_teacher;
	string	surname_teacher;
	double age;
	string email_teacher;
	char* subjects;
};

struct Schoolchildren
{
	string name_schoolchildren;
	string surname_schoolchildre;
	int Class;
	char number_parents[14];
	char number_schoolchildren[14];
	string email_schoolchildren;
};

struct Subjects
{
	string subjecst;
};

struct Data
{
	Teacher _teacher;
	Schoolchildren _schoolchildren;
	Subjects _subjects;
};

void AddSchoolchildren(Data* (&d), int& n);
void AddSubjects(Data* (&d), int& n);
void AddTeacher(Data* (&d), int& n);

void ShowTeacher(Data* d, int n);
void ShowSubjects(Data* d, int n);
void Showchoolchildren(Data* d, int n);

void ReadTeacher(Data* (&d), int n);

void Delete(Data* (&d), int& n);

void Copy(Data* (&d_n), Data* (&d_o), int n);
void CopyForSorting(Data& d_n, Data& d_o);

void SortingTeacherName(Data* d, int n);
void SortingStudentName(Data* d, int n);