#pragma once
#ifndef admin_h
#define admin_h
#include <iostream>
#include <fstream>
#include "user.h"
#include "doctor.h"
#include "patient.h"
#include "appointment.h"
using namespace std;








class admin {
	char firstName[20];
	char lastName[20];
	char Address[20];
	char cnic[20];
	char password[15];
	char phoneNumber[15];
	doctor d;
	appointment app;
	patient p;
public:
	//--------------------------------------Constructors----------------------------------------------

	admin() {
		for (int i = 0; i < 20; i++) {
			this->firstName[i] = '\0';
			this->lastName[i] = '\0';
			this->Address[i] = '\0';
			this->cnic[i] = '\0';
		}
		for (int i = 0; i < 15; i++) {
			this->password[i] = '\0';
			this->phoneNumber[i] = '\0';
		}
	}
	admin(string first, string last, string addres, string cnic_1,  string num, string pass) {
		strcpy_s(this->firstName, first.c_str());
		strcpy_s(this->lastName, last.c_str());
		strcpy_s(this->Address, addres.c_str());
		strcpy_s(this->cnic, cnic_1.c_str());
		strcpy_s(this->password, pass.c_str());
		strcpy_s(this->phoneNumber, num.c_str());
	}
	//--------------------------------------Setter----------------------------------------------

	void setfirstName(string first) {
		strcpy_s(this->firstName, first.c_str());
	}
	void setlastName(string last) {
		strcpy_s(this->lastName, last.c_str());
	}
	void setaddress(string add) {
		strcpy_s(this->Address, add.c_str());
	}
	void setcnic(string c) {
		strcpy_s(this->cnic, c.c_str());
	}
	void setphoneNumber(string num) {
		strcpy_s(this->phoneNumber, num.c_str());
	}
	void setpassword(string pass) {
		strcpy_s(this->password, pass.c_str());
	}
	//-----------------------------------Getter------------------------------------------------
	string getfirstNAme() {
		return this->firstName;
	}
	string getlastName() {
		return this->lastName;
	}
	string getaddress() {
		return this->Address;
	}
	string getcnic() {
		return this->cnic;
	}
	string getphoneNumber() {
		return this->phoneNumber;
	}
	string getpassword() {
		return this->password;
	}

	//------------------------------------Function------------------------------------------------
	void displayadmin() {
		cout << "(-----------------------------------)" << endl;
		cout << "Doctor Name   " << getfirstNAme() << " " << getlastName() << endl;
		cout << "Phone Number  " << getphoneNumber() << endl;
		cout << "CNIC-Number   " << getcnic() << endl;
		cout << "Address       " << getaddress() << endl;
		cout << "(-----------------------------------)" << endl;
		cout << endl;
	}
	void write() {
		ofstream fout("admin.bin", ios::binary | ios::app);
		fout.write((char*) & (*this), sizeof(doctor));
		fout.close();

	}
	void adminRegister() {
		string name;
		cout << "Please enter your First name " << endl;
		cin >> name;
		this->setfirstName(name);
		cout << "Please enter your Last name " << endl;
		cin >> name;
		this->setlastName(name);
		cout << "------------------------------------------" << endl;
		cout << "Please enter your Address " << endl;
		cin >> name;
		this->setaddress(name);
		cout << "Please enter your Phone Number " << endl;
		cin >> name;
		this->setphoneNumber(name);
		cout << "------------------------------------------" << endl;
		cout << "Please enter your cnic  " << endl;
		cin >> name;
		this->setcnic(name);

		do {
			cout << "Please enter your password " << endl;
			cin >> name;
			if (checkPassword(name)) {
				this->setpassword(name);
			}
			else {
				cout << " Please Enter the password which contain8\ \n characters that contains at least one lowercase letter,\ \n one uppercase letter, one number, and one special character" << endl;
				cout << "------------------------------------------" << endl << endl;

			}
		} while (!(checkPassword(name)));
		cout << "------------------------------------------" << endl;
		cout << " We have Five Speciality so Please enter your Speacialty accordingly " << endl;
		cout << endl << endl;
		cout << "--------------------------------------------------------------------------------" << endl;
		write();
	}
	///////////////////////////////////////////////////////////////////////////
	void searchdoc() {
		string a;
		cout << "Please Enter the Doctor's Cnic to Search the Doctor  " << endl;
		cin >> a;
		ifstream file("doc.bin", ios::out | ios::in | ios::binary);
		while (file.read((char*)&d, sizeof(doctor)))
		{

			if (d.getcnic() == a)
			{

				file.close();
				d.displaydoc();
				break;
			}

		}
	}
	void displaypat() {
		string a;
		cout << "Please Enter Patient's CNIC to Search the Patient  " << endl;
		cin >> a;
		ifstream file("doc.bin", ios::out | ios::in | ios::binary);
		while (file.read((char*)&p, sizeof(patient)))
		{

			if (p.getcnic() == a)
			{

				file.close();
				p.displayPat();
				break;
			}

		}
	}
	void viewAppointment() {
		string a;
		cout << "Please Enter Doctor's CNIC to Search the Appointment  " << endl;
		cin >> a;
		ifstream file("doc.bin", ios::out | ios::in | ios::binary);
		while (file.read((char*)&p, sizeof(patient)))
		{

			if (app.getdocCnic() == a)
			{

				file.close();
				app.displayAppointment();
				break;
			}

		}

	}
	void addDoctor() {
		d.docRegister();
	}
	void delDoctor() {
		d.delProfile();
	}
	void editDoctor() {
		d.Editprofile();
	}
	virtual void editAppointment() {
		app.editAppointment();
	}





	//--------------------------------------destructor----------------------------------------------

	~admin() {
		
	}
};

#endif