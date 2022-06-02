#include<iostream>
#include<fstream>
#include<string>
#include"Header.h"
using namespace std;
int main()
{
	cout << "Menu\n";
	int select;
	do
	{
		cout << "=========================\n";
		cout << "1-ADD Records \n";
		cout << "2-Search Records \n";
		cout << "3-Display all Records \n";
		cout << "4-Update Records \n";
		cout << "5-Delete Records \n";
		cout << "6-Exit And Save to Txt File  \n";
		cout << "========================== \n";
		cout << "Select Option >>";
		cin >> select;
		switch (select)
		{
		case 1:
			int x;
        	cout << "To Add Student press 1 \nTo Add Teacher press 2 \n";
			cin >> x;
			if (x == 1)
				Add_Student();
			else if (x == 2)
				Add_Teacher();
			else
				cout << "Please Enter Right Number \n ";
			break;

		case 2:
			int y;
			cout << "To Search For Student press 1 \nTo Search For Teacher press 2 \n";
			cin >> y;
			if (y == 1)
				Search_Student();
			else if (y == 2)
				Search_Teacher();
			else
				cout << "Please Enter Right Number \n ";
			break;

		case 3:
			int z;
			cout << "To Display All Student Information press 1 \nTo Display All Teacher Information press 2 \n";
			cin >> z;
			if (z == 1)
				Display_Student();
			else if (z == 2)
				Display_Teacher();
			else
				cout << "Please Enter Right Number \n ";
			break;

		case 4: 
			int q;
			cout << "To Update Student Information press 1 \nTo Update Teacher Information press 2 \n";
			cin >> q;
			if (q == 1)
				Update_Student();
			else if (q == 2)
				Update_Teacher();
			else
				cout << "Please Enter Right Number \n ";
			break;

		case 5:
			int r;
			cout << "To Delete Student Record press 1 \nTo Delete Teacher Record press 2 \n";
			cin >> r;
			if (r == 1)
				Delete_Student();
			else if (r == 2)
				Delete_Teacher();
			else
				cout << "Please Enter Right Number \n ";
			break;

		
			

			

		}
	} while (select!=6);
	cout << "Save Has Been Done \n ";
}