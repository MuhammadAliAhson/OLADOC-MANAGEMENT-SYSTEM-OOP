
#pragma once
#ifndef patient_h
#define patient_h
#include <iostream>
#include <fstream>
#include "doctor.h"
#include "user.h"
#include "admin.h"
#include "appointment.h"
#include "Payment.h"


//#include "Speciality.h"


using namespace std;





//--------------------------------------Feedback----------------------------------------------

class feedBack {
	char feedback[200];
	int rating;
public:
	//--------------------------------------Constructors----------------------------------------------
	feedBack() {
		for (int i = 0; i < 200; i++) {
			this->feedback[i] = '\0';
		}
		this->rating = 0;
	}
	feedBack(string feed, int rating) {
		strcpy_s(this->feedback, feed.c_str());	 
		this->rating = rating;
	}
	//--------------------------------------Setters----------------------------------------------
	void setfeedback(string feed) {
		strcpy_s(this->feedback, feed.c_str());
	}
	void setrating(int rating) {
		this->rating = rating;
	}
	//--------------------------------------Getters----------------------------------------------
	string getfeedback() {
		return this->feedback;
	}
	int getrating() {
		return this->rating;
	}
	//--------------------------------------Fuctions----------------------------------------------
	void udpatefeedback(string feed) {
		setfeedback(feed);
	}
	void getcalRating() {
		

	}
};




class patient {
	char firstName[20];
	char lastName[20];
	char Address[20];
	char cnic[20];
	char password[15];
	char healthCondition[15];
	char phoneNumber[15];
	appointment app;
	Account pay;
	feedBack f;
public:

	//--------------------------------------Constructors----------------------------------------------
	patient() {
		for (int i = 0; i < 20; i++) {
			this->firstName[i] = '\0';
			this->lastName[i] = '\0';
			this->Address[i] = '\0';
			this->cnic[i] = '\0';
		}
		for (int i = 0; i < 15; i++) {
			this->password[i] = '\0';
			this->healthCondition[i] = '\0';
			this->phoneNumber[i] = '\0';
		}


	}
	patient(string first, string last, string addres, string cnic_1, string healthCondition_1, string num, string pass) {
		strcpy_s(this->firstName, first.c_str());
		strcpy_s(this->lastName, last.c_str());
		strcpy_s(this->Address, addres.c_str());
		strcpy_s(this->cnic, cnic_1.c_str());
		strcpy_s(this->healthCondition, healthCondition_1.c_str());
		strcpy_s(this->password, pass.c_str());
		strcpy_s(this->phoneNumber, num.c_str());
	}

	//--------------------------------------Setters----------------------------------------------
	void setfirstName(string first) {
		strcpy_s(this->firstName, first.c_str());
	}
	void setlastName(string last) {
		strcpy_s(this->lastName, last.c_str());
	}
	void setaddress(string add) {
		strcpy_s(this->Address, add.c_str());
	}
	void setphoneNumber(string num) {
		strcpy_s(this->phoneNumber, num.c_str());
	}
	void setcnic(string c) {
		strcpy_s(this->cnic, c.c_str());
	}
	void sethealthCondition(string health) {
		strcpy_s(this->healthCondition, health.c_str());
	}
	void setpassword(string pass) {
		strcpy_s(this->password, pass.c_str());
	}
	//--------------------------------------Getters----------------------------------------------
	string getfirstNAme() {
		return this->firstName;
	}
	string getlastName() {
		return this->lastName;
	}
	string getaddress() {
		return this->Address;
	}
	string getphoneNumber() {
		return this->phoneNumber;
	}
	string getcnic() {
		return this->cnic;
	}
	string gethealthCondition() {
		return this->healthCondition;
	}
	string getpassword() {
		return this->password;
	}
	//--------------------------------------Functions----------------------------------------------
	void bookAppointment() {
		string str;
		int rat=0;
		searchDoctor();
		app.setAppointment();
		cout << "Please Enter your feedback " << endl;
		cin >> str;
		f.setfeedback(str);
		cout << "Please Enter your Rating " << endl;
		cin >> rat;
		f.setrating(rat);
		write();
	}
	void delProfile() {
		string a;
		cout << "Please Enter the Cnic of the Patient " << endl;
		cin >> a;
		fstream myFile("pat.bin", ios::in | ios::out | ios::binary);
		ofstream myFile_temp("temp.bin", ios::app | ios::binary);
		while (myFile.read((char*)&(*this), sizeof(this))) {
			if (getcnic() == a) {
				myFile_temp.write((char*)&(*this), sizeof(this));
			}
			else {
				cout << "Success!  Deleted." << endl;
			}
		}
		myFile.close();
		myFile_temp.close();
		remove("pat.bin");
		rename("temp.bin", "pat.bin");
	}
	void displayAppointment() {
		app.displayAppointment();
	}
	void cancelAppointmentpat() {
		app.cancelAppointment();
	}
	void searchDoctor() {
		doctor temp;
		string a;
		cout << "Please Enter the Hospital Name to Search the Doctor  " << endl;
		cin >> a;
		ifstream file("doc.bin", ios::out | ios::in | ios::binary);
		while (file.read((char*)&temp, sizeof(doctor)))
		{
			
			if (temp.gethospitalName() == a)
			{

				
				temp.displaydoc();

			}

		}
		file.close();
	}
	void displayPat() {
		cout << "(-----------------------------------)" << endl;
		cout << "Paient Name   " << getfirstNAme() << " " << getlastName() << endl;
		cout << "Phone Number  " << getphoneNumber() << endl;
		cout << "CNIC-Number   " << getcnic() << endl;
		cout << "Address       " << getaddress() << endl;
		cout << "Health Status " << gethealthCondition() << endl;
		cout << "(-----------------------------------)" << endl;
		cout << endl;


	}

	/*---------------------------------------------------------------------------------------------------------*/
	void write() {
		ofstream fout("pat.bin", ios::binary | ios::app);
		fout.write((char*) & (*this), sizeof(doctor));
		fout.close();
	}
	/*---------------------------------------------------------------------------------------------------------*/
	void patRegister() {
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
		cout << " Heath Status \ \n \nFor Example Good, Normal ,Bad " << endl << endl;
		cout << "Please enter your Heath Status" << endl;
		cin >> name;
		this->sethealthCondition(name);
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


		write();
	}
};


#endif