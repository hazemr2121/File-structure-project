#pragma once
#include<iostream>
#include<fstream>
using namespace std;
struct Student
{
	int id;
	char name[20];
	char country[15];
	float gpa;
};
struct Teacher {
	int id;
	char name[20];
	char subject[15];
	char country[15];
};
void Add_Student()
{
	fstream myfile;
	Student s1;
	cout << "Enter Student Id : ";  cin >> s1.id;
	cin.ignore();
	cout << "Enter Student Name : ";  cin.getline(s1.name, 20);
	cout << "Enter Student Country : ";  cin.getline(s1.country, 15);
	cout << "Enter Student GPA : ";  cin >> s1.gpa;
	myfile.open("Student.txt", ios::binary | ios::app);
	if (myfile.is_open())
	{
		myfile.write((char*)&s1.id, sizeof(s1.id));
		myfile.put('|');
		myfile.write(s1.name, strlen(s1.name));
		myfile.put('|');
		myfile.write(s1.country, strlen(s1.country));
		myfile.put('|');
		myfile.write((char*)&s1.gpa, sizeof(s1.gpa));
		myfile.put('#');
		myfile.close();
	}
	else
	{
		cout << "ERROR!! Couldnt Open The File \n ";
	}
}
void Add_Teacher()
{
	fstream myfile;
	Teacher t1;
	cout << "Enter Teacher Id : ";  cin >> t1.id;
	cin.ignore();
	cout << "Enter Teacher Name : ";  cin.getline(t1.name, 20);
	cout << "Enter Teacher Subject : ";  cin.getline(t1.subject, 15);
	cout << "Enter Teacher Country : ";  cin.getline(t1.country, 15);
	myfile.open("Teacher.txt", ios::binary | ios::app);
	if (myfile.is_open())
	{
		myfile.write((char*)&t1.id, sizeof(t1.id));
		myfile.put('|');
		myfile.write(t1.name, strlen(t1.name));
		myfile.put('|');
		myfile.write(t1.subject, strlen(t1.subject));
		myfile.put('|');
		myfile.write(t1.country, strlen(t1.country));
		myfile.put('#');
		myfile.close();
	}
	else
	{
		cout << "ERROR!! Couldnt Open The File \n ";
	}
}
void Update_Student()
{
	fstream file;
	file.open("Student.txt", ios::binary | ios::in | ios::out);
	int srch_id, pos;
	Student st;
	bool found = false;
	cout << "Please enter Student's ID to updated: ";
	cin >> srch_id;
	if (file.is_open())
	{

		while (!file.eof())
		{
			file.read((char*)&st.id, sizeof(st.id));
			pos = (file.tellg());
			file.get();

			if (st.id == srch_id)
			{
				found = true;
				file.seekg(pos);
				file.put('*');
				break;
			}
			else
			{
				file.getline(st.name, 20, '|');
				file.getline(st.country, 15, '|');
				file.read((char*)&st.gpa, sizeof(st.gpa));
				file.get();

			}
		}
		if (!found)
			cout << "\n Student not found. \n";
		else
		{
			Add_Student();
			cout << "\n updated seccessfully. \n";

		}
		file.close();

	}
	else
		cout << "\n Error while openning the file. \n";
}
void Update_Teacher()
{
	fstream file;
	file.open("Teacher.txt", ios::binary | ios::in | ios::out);
	int srch_id, pos;
	Teacher t1;;
	bool found = false;
	cout << "Please enter Teacher ID to be updated: ";
	cin >> srch_id;
	if (file.is_open())
	{

		while (!file.eof())
		{
			file.read((char*)&t1.id, sizeof(t1.id));
			pos = (file.tellg());
			file.get();

			if (t1.id == srch_id)
			{
				found = true;
				file.seekg(pos);
				file.put('*');
				break;
			}
			else
			{
				file.getline(t1.name, 20, '|');
				file.getline(t1.subject, 15, '|');
				file.getline(t1.country, 15, '#');
			}
		}
		if (!found)
			cout << "\n Teacher not found. \n";
		else
		{
			Add_Teacher();
			cout << "\n updated seccessfully. \n";

		}
		file.close();

	}
	else
		cout << "\n Error while openning the file. \n";
}
void Delete_Student()
{
	fstream file;
	file.open("Student.txt", ios::binary | ios::in | ios::out);
	int srch_id, len, rec_len, pos;
	Student st;
	bool found = false;
	cout << "Please enter Student's ID to delete: ";
	cin >> srch_id;
	if (file.is_open())
	{

		while (!file.eof())
		{
			file.read((char*)&st.id, sizeof(st.id));
			pos = (file.tellg());
			file.get();

			if (st.id == srch_id)
			{
				found = true;
				file.seekg(pos);
				file.put('*');
				break;
			}
			else
			{
				file.getline(st.name, 20, '|');
				file.getline(st.country, 15, '|');
				file.read((char*)&st.gpa, sizeof(st.gpa));
				file.get();

			}
		}
		if (!found)
			cout << "\n Student not found. \n";
		else
			cout << "\n Deleted seccessfully. \n";
		file.close();

	}
	else
		cout << "\n Error while openning the file. \n";
}
void Delete_Teacher()
{
	fstream file;
	file.open("Teacher.txt", ios::binary | ios::in | ios::out);
	int srch_id, len, rec_len, pos;
	Teacher t1;
	bool found = false;
	cout << "Please enter Teacher ID to delete: ";
	cin >> srch_id;
	if (file.is_open())
	{

		while (!file.eof())
		{
			file.read((char*)&t1.id, sizeof(t1.id));
			pos = (file.tellg());
			file.get();

			if (t1.id == srch_id)
			{
				found = true;
				file.seekg(pos);
				file.put('*');
				break;
			}
			else
			{
				file.getline(t1.name, 20, '|');
				file.getline(t1.subject, 15, '|');
				file.getline(t1.country, 15, '#');
				

			}
		}
		if (!found)
			cout << "\n Teacher not found. \n";
		else
			cout << "\n Deleted seccessfully. \n";
		file.close();

	}
	else
		cout << "\n Error while openning the file. \n";

}
void Display_Student()
{
	Student s1;
	ifstream myfile;
	char x = ' ';
	myfile.open("Student.txt", ios::binary);
	cout << "\n Id \t Name \t country \t gpa \n ";
	if (myfile.is_open())
	{
		while (!myfile.eof())
		{
			myfile.read((char*)&s1.id, sizeof(s1.id));
			myfile.read(&x, 1);
			if (x == '*')
			{
				myfile.getline(s1.name, 20, '|');
				myfile.getline(s1.country, 15, '|');
				myfile.read((char*)&s1.gpa, sizeof(s1.gpa));
				myfile.get();
			}
			else if (x == '|')
			{
				myfile.getline(s1.name, 20, '|');
				myfile.getline(s1.country, 15, '|');
				myfile.read((char*)&s1.gpa, sizeof(s1.gpa));
				myfile.get();
				cout << "\n" << s1.id << "\t" << s1.name << "\t" << s1.country << "\t" << s1.gpa << endl;

			}
		}
		myfile.close();
	}

}
void Display_Teacher()
{
	Teacher t1;
	ifstream myfile;
	char x = ' ';
	myfile.open("Teacher.txt", ios::binary);
	cout << "\nId \t Name\t\tSubject country \n ";
	if (myfile.is_open())
	{
		while (!myfile.eof())
		{
			myfile.read((char*)&t1.id, sizeof(t1.id));
			myfile.read(&x, 1);
			if (x == '*')
			{
				myfile.getline(t1.name, 20, '|');
				myfile.getline(t1.subject, 15, '|');
				myfile.getline(t1.country, 15, '#');
			}
			else if (x == '|')
			{
				myfile.getline(t1.name, 20, '|');
				myfile.getline(t1.subject, 15, '|');
				myfile.getline(t1.country, 15, '#');
				cout << "\n" << t1.id << "\t" << t1.name << "\t" << t1.subject << "\t" << t1.country << endl;

			}
		}
		myfile.close();
	}

}
void Search_Student()
{
	int search_id;
	int x = 0;
	char y = ' ';
	Student s1;
	fstream myfile;
	myfile.open("Student.txt", ios::binary | ios::in);
	cout << "Please Insert Student Id To search for : ";
	cin >> search_id;
	if (myfile.is_open())
	{
		while (!myfile.eof())
		{
			myfile.read((char*)&s1.id, sizeof(s1.id));
			myfile.read(&y, 1);
			myfile.getline(s1.name, 20, '|');
			myfile.getline(s1.country, 15, '|');
			myfile.read((char*)&s1.gpa, sizeof(s1.gpa));
			myfile.get();
			if (s1.id == search_id)
			{
				if (y == '*')
				{
					cout << "Field has been deleted already.";
					break;
				}
				cout << "Student Id : " << s1.id << endl;
				cout << "Student name : " << s1.name << endl;
				cout << "Student Country : " << s1.country << endl;
				cout << "Student GPA : " << s1.gpa << endl;
				x = 1;
				break;
				myfile.close();
			}

		}
		if (x == 0)
		{
			cout << "Not Found That Item \n ";
		}
		else
			cout << "Item Founded \n ";
	}
	else
	{
		cout << "Couldnt Open The File \n ";
	}
}
void Search_Teacher()
{
	int search_id;
	int x = 0;
	char y = ' ';
	Teacher t1;
	fstream myfile;
	myfile.open("Teacher.txt", ios::binary | ios::in);
	cout << "Please Insert teacher's Id To search for : ";
	cin >> search_id;
	if (myfile.is_open())
	{
		while (!myfile.eof())
		{
			myfile.read((char*)&t1.id, sizeof(t1.id));
			myfile.read(&y, 1);
			myfile.getline(t1.name, 20, '|');
			myfile.getline(t1.subject, 15, '|');
			myfile.getline(t1.country, 15, '#');
			if (t1.id == search_id)
			{
				if (y == '*')
				{
					cout << "Field has been deleted already.";
					break;
				}
				cout << "teacher's Id : " << t1.id << endl;
				cout << "teacher's Name : " << t1.name << endl;
				cout << "teacher's Subject : " << t1.subject << endl;
				cout << "teacher's Country : " << t1.country << endl;
				x = 1;
				break;
				myfile.close();
			}

		}
		if (x == 0)
		{
			cout << "Not Found That Item \n ";
		}
		else
			cout << "Item Founded \n ";
	}
	else
	{
		cout << "Couldnt Open The File \n ";
	}
}