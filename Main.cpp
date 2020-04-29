#include <iostream>
#include "Teacher.h"
#include"Funchions.h"

using namespace std;

int menu;

void MainMenu()
{
	cout << "0-Exit\n";
	cout << "1-Teacher\n";
	cout << "2-subjects\n";
	cout << "3-schoolchildren\n";
	cin >> menu;
} 

int main()
{
	string password = "admin", login = "admin", fileName;
	int a = 0, n = 0, teacher, subjects, schoolchildren, size = 0, _actions, addtechers = 0;

	while (a < 1)
	{
		cout << "login:";
		cin >> login;
		cout << "password:";
		cin >> password;
		if (login == "admin")
		{
			if (password == "admin")
			{
				system("cls");

				cout << "Welcome " << login << "\n" << endl;

				MainMenu();	
				Data* d = new Data[size];
	
				while (menu != 0)
				{
					system("cls");
					switch (menu)
					{
					case 1:
					{
					cout << "1-Pobachtu vsih vukladachiv\n";
					cout << "2-Add teacher\n";
					cout << "3-Delete teacher\n";
					cout << "4-read techer\n";
					cout << "5-sorting\n";
					cin >> teacher;
					switch (teacher)
					{
						case 1:
						{
							ShowTeacher(d, size);
	
							system("pause");
							system("cls");
							MainMenu();
							break;
						}
						case 2:
						{
							cout << "1-zchutatu vukladachiv iz faily\n";
							cout << "2-vvestu vukladachiv\n";
							cin >> addtechers;
							switch (addtechers)
							{
								case 1:
								{
									ReadingInput(d, size, "Input.txt");
									break;
								}
								case 2:
								{
									AddTeacher(d, size);
									break;
								}
								default:
									cout << "Error\n";

							}
							system("pause");
							system("cls");
							MainMenu();
							break;
						}
						case 3:
						{
							if (size != 0)
							{
								Delete(d, size);
							}
				
							system("pause");
							system("cls");
							MainMenu();
							break;
						}
						case 4:
						{
							ReadTeacher(d, size);
					
							system("pause");
							system("cls");
							MainMenu();
							break;
						}
						case 5:
						{
							SortingTeacherName(d, size);

							system("pause");
							system("cls");
							MainMenu();
							break;
						}
						default:
						{
							cout << "data incorrect\n";
							system("pause");
							system("cls");
							MainMenu();
							break;
						}
					}
					break;
				}
					case 2:
					{
					cout << "1-see all items\n";
					cout << "2-add a new item\n";
					cout << "3-delete already existing\n";
					cout << "4-item sort item by nameand select item\n";
					cin >> subjects;
					switch (subjects)
					{
					case 1:
					{
						ShowSubjects(d, size);

						system("pause");
						system("cls");
						MainMenu();
						break;
					}
					case 2:
					{
						AddSubjects(d, size);

						system("pause");
						system("cls");
						MainMenu();
						break;
					}
					case 3:
					{
						Delete(d, size);

						system("pause");
						system("cls");
						MainMenu();
						break;
					}
					default:
					{
						cout << "Data incorrect\n";
						system("pause");
						system("cls");
						MainMenu();
						break;
					}
					}
					break;
				}
					case 3:
					{
					cout << "1-see all students, see students only in the specified class\n";
					cout << "2-add a new student, remove an existing student\n";
					cout << "3-sort all the students edit the student's name\n";
					cin >> schoolchildren;
					switch (schoolchildren)
					{
					case 1:
					{
						Showchoolchildren(d, size);

						system("pause");
						system("cls");
						MainMenu();
						break;
					}
					case 2:
					{
						AddSchoolchildren(d, size);

						system("pause");
						system("cls");
						MainMenu();
						break;
					}
					case 3:
					{
						SortingStudentName(d, size);
						break;
					}
					default:
					{
						cout << "Data incorrect\n";
						break;
					}
					}
					break;
				}
					}
				}
				break;
			}
			else
			{
				cout << "login true, password false\n";
				n++;
			}
		}
		else
		{
			cout << "login false or password false\n";
			n++;
		}
		if (n == 3) 
		{
			cout << "Try again later)";
			break;
		}
	}
	return 0;
	system("pasue");
}