// PhonebookRedux.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <conio.h>
using namespace std;

class phoneBook {
	char name[20], phno[15], mobphno[15];
public:
	void getdata();
	void showdata();
	char *getname() { return name; }
	char *getphno() { return phno; }
	char *getmobphno() { return mobphno; }
	void update(char *nm, char *telno, char *mobno) {
		strcpy_s(name, nm);
		strcpy_s(phno, telno);
		strcpy_s(mobphno, mobno);
	}
};

void phoneBook::getdata() {
	cout << "\nEnter Name : ";
	cin >> name;
	cout << "Enter Home Phone Number : ";
	cin >> phno;
	cout << "ENter Mobile Phone Number :";
	cin >> mobphno;
}

void phoneBook::showdata() {
	cout << "\n";
	cout << char(20) << name;
	cout << char(15) << phno;
	cout << char(15) << mobphno;
}


void main() {
	phoneBook rec;
	fstream file;
	file.open("phonebook.dat", ios::ate | ios::in | ios::out | ios::binary);
	char ch, nm[20], telno[15], mobno[15];
	int choice, found = 0;
	while (1) {
		cout << "\n_____PhoneBook______\n";
		cout << "1) Add New Record\n";
		cout << "2) Display All Records\n";
		cout << "3) Search Home Phone Number.\n";
		cout << "4) Search Mobile Phone Number\n";
		cout << "5) Exit\n";
		cout << "Choose your choice : ";
		cin >> choice;
		switch (choice) {
		case 1: //New Record
			rec.getdata();
			cin.get(ch);
			file.write((char *)&rec, sizeof(rec));
			break;

		case 2: //Display All Records
			file.seekg(0, ios::beg);
			cout << "\n\nAll Records in Phone Book\n";
			while (file) {
				file.read((char *)&rec, sizeof(rec));
				if (!file.eof())
					rec.showdata();
			}
			file.clear();
			break;

		case 3: //Search name on basis of tel. no
			cout << "\n\nEnter Home Telephone No : ";
			cin >> telno;
			file.seekg(0, ios::beg);
			found = 0;
			while (file.read((char *)&rec, sizeof(rec)))
			{
				if (strcmp(telno, rec.getphno()) == 0)
				{
					found = 1;
					rec.showdata();
				}
			}
			file.clear();
			if (found == 0)
				cout << "\n\n---Record Not found---\n";
			break;

		case 4: //Search name on basis of tel. no
			cout << "\n\nEnter Mobile Telephone No : ";
			cin >> telno;
			file.seekg(0, ios::beg);
			found = 0;
			while (file.read((char *)&rec, sizeof(rec)))
			{
				if (strcmp(telno, rec.getphno()) == 0)
				{
					found = 1;
					rec.showdata();
				}
			}
			file.clear();
			if (found == 0)
				cout << "\n\n---Record Not found---\n";
			break;

		
		case 5: abort();
		}
	}
out:
	file.close();
}


