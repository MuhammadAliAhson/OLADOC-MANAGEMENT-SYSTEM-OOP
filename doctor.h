#pragma once
#ifndef doctor_h
#define doctor_h
#include <iostream>
#include <fstream>
#include "string"
#include "Payment.h"



//#include "Speciality.h"
//#include "patient.h"
#include "user.h"
#include "admin.h"

using namespace std;
/*---------------------------------------------------------------------------------*/


bool checkPassword(string password) {
	if (!((password.length() >= 8) &&
		(password.length() <= 15)))
		return false;

	// To check space
	if (password.find(" ") !=
		std::string::npos)
		return false;

	if (true)
	{
		int count = 0;

		// Check digits from 0 to 9
		for (int i = 0; i <= 9; i++)
		{

			// To convert int to string
			string str1 = to_string(i);

			if (password.find(str1) !=
				std::string::npos)
				count = 1;
		}
		if (count == 0)
			return false;
	}

	// For special characters
	if (!((password.find("@") != std::string::npos) ||
		(password.find("#") != std::string::npos) ||
		(password.find("!") != std::string::npos) ||
		(password.find("~") != std::string::npos) ||
		(password.find("$") != std::string::npos) ||
		(password.find("%") != std::string::npos) ||
		(password.find("^") != std::string::npos) ||
		(password.find("&") != std::string::npos) ||
		(password.find("*") != std::string::npos) ||
		(password.find("(") != std::string::npos) ||
		(password.find(")") != std::string::npos) ||
		(password.find("-") != std::string::npos) ||
		(password.find("+") != std::string::npos) ||
		(password.find("/") != std::string::npos) ||
		(password.find(":") != std::string::npos) ||
		(password.find(".") != std::string::npos) ||
		(password.find(",") != std::string::npos) ||
		(password.find("<") != std::string::npos) ||
		(password.find(">") != std::string::npos) ||
		(password.find("?") != std::string::npos) ||
		(password.find("|") != std::string::npos)))
		return false;

	if (true)
	{
		int count = 0;

		// Checking capital letters
		for (int i = 65; i <= 90; i++)
		{

			// Type casting
			char c = (char)i;
			string str1(1, c);

			if (password.find(str1) !=
				std::string::npos)
				count = 1;
		}
		if (count == 0)
			return false;
	}

	if (true)
	{
		int count = 0;

		// Checking small letters
		for (int i = 97; i <= 122; i++)
		{

			// Type casting
			char c = (char)i;
			string str1(1, c);

			if (password.find(str1) !=
				std::string::npos)
				count = 1;
		}
		if (count == 0)
			return false;
	}

	// If all conditions fails
	return true;


}
/*public Gynecologist, public Orthopedic,public Cardiologist,public Oncologist,public Dermatologist*/


class  doctor{
	char firstName[20];
	char lastName[20];
	char Address[20];
	char cnic[20];
	char hospitalName[20];
	char feedback[150];
	char password[15];
	char phoneNumber[15];
	char clock[5];
	int startTime;
	int endTime;
	bool availible[8];
	int fee;
public:
	//---------------------------------------Constructors-----------------------------------------------------
	doctor() {
		
		for (int i = 0; i < 20; i++) {
			this->firstName[i] = '\0';
			this->lastName[i] = '\0';
			this->Address[i] = '\0';
			this->cnic[i] = '\0';
			this->hospitalName[i] = '\0';
		}
		for (int i = 0; i < 150; i++) {
			this->feedback[i] = '\0';
		}
		for (int i = 0; i < 15; i++) {
			this->password[i] = '\0';
			this->phoneNumber[i] = '\0';
		}
		for (int i = 0; i < 8; i++) {
			this->availible[i] = true;
		}
		for (int i = 0; i < 5; i++) {
			this->clock[i] = '\0';
		}
		
		
		this->startTime = 0;
		this->endTime = 0;

		this->fee = 0;
	
	}
	doctor(string first, string last, string addres, string cnic_1, string hospital, string feed, string num, string pass, bool avail,string clk,int start,int end, int fee_1) {
		strcpy_s(this->firstName, first.c_str());
		strcpy_s(this->lastName, last.c_str());
		strcpy_s(this->Address, addres.c_str());
		strcpy_s(this->cnic, cnic_1.c_str());
		strcpy_s(this->hospitalName, hospital.c_str());
		strcpy_s(this->feedback, feed.c_str());
		strcpy_s(this->password, pass.c_str());
		strcpy_s(this->phoneNumber, num.c_str());
		for (int i = 0; i < 8; i++) {
			this->availible[i] = avail;
		}
		strcpy_s(this->clock, clk.c_str());
		this->fee = fee_1;
		this->startTime = start;
		this->endTime = end;
	}
	//----------------------------------------Setters-----------------------------------------------------
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
	void sethospitalName(string h) {
		strcpy_s(this->hospitalName, h.c_str());
	}
	void setphoneNumber(string num) {
		strcpy_s(this->phoneNumber, num.c_str());
	}
	void setfeedback(string feed) {
		strcpy_s(this->feedback, feed.c_str());
	}
	void setpassword(string pass) {
		strcpy_s(this->password, pass.c_str());
	}
	void setStartTime(int  time) {
		this->startTime = time;
	}
	void setEndTime(int  time) {
		this->endTime = time;
	}
	void setClock(string clk) {
		strcpy_s(this->clock, clk.c_str());
	}
	void setavailibility(bool choice,int index) {
		this->availible[index] = choice;
	}
	void setfee(int fee_1) {
		this->fee = fee_1;
	}

	//----------------------------------------Getters-----------------------------------------------------
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
	string gethospitalName() {
		return this->hospitalName;
	}
	string getphoneNumber() {
		return this->phoneNumber;
	}
	string getfeedback() {
		return this->feedback;
	}
	string getpassword() {
		return this->password;
	}
	string getClock() {
		return this->clock;
	}
	int getstartTime() {
		return this->startTime;
	}
	int getendTime() {
		return this->endTime;
	}
	bool getavailibility(int index) {
		return this->availible[index];
	}
	int getfee() {
		return this->fee;
	}
	//----------------------------------------Functions-----------------------------------------------------


	void updateAvailiblity(bool a,int index) {
		setavailibility(a, index);

	}
	void delProfile() {
		string a;
		cout << "Please Enter the Cnic of the Doctor " << endl;
		cin >> a;
		fstream myFile("doc.bin", ios::in | ios::out | ios::binary);
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
		remove("doc.bin");
		rename("temp.bin", "doc.bin");

	}

	void editAppointmentdoc() {
	
	}
	void Editprofile() {
			string a, name;
			int choice = 0, mol = 0;
			cout << "Please Enter Doctor's CNIC to Edit Data  " << endl;
			cin >> a;
			fstream myFile("doc.bin", ios::in | ios::out | ios::binary);
			while (myFile.read((char*)&(*this), sizeof(doctor))) {

				if (this->getcnic() == a) {
					do {
						cout << "Please Enter What Would Yu Like to Edit" << endl;
						cout << "Press 1 to change the Name" << endl;
						cout << "Press 2 to change the Phone Number" << endl;
						cout << "Press 3 to change the Hospital" << endl;
						cout << "Press 4 to change the Availibility" << endl;
						cin >> choice;
						if (choice == 1) {
							cout << "Please enter Doctor's First name " << endl;
							cin >> name;
							this->setfirstName(name);
							cout << "Please enter Doctor's Last name " << endl;
							cin >> name;
							this->setlastName(name);
						}
						else if (choice == 2) {
							cout << "Please enter Doctor's Phone Number " << endl;
							cin >> name;
							this->setphoneNumber(name);
						}
						else if (choice == 3) {
							cout << "Please enter  Hospital name  " << endl;
							cin >> name;
							this->sethospitalName(name);

						}
						else if (choice == 4) {
							cout << "  Please Press 1 for Availibilty and 0 for the Not Availibity" << endl;
							for (int i = 0; i < this->getendTime() - this->getstartTime(); i++) {
								cout << this->getstartTime() + i << " " << clock << endl;
								cin >> mol;
								if (mol == 0) {
									this->setavailibility(false, i);
								}
								else {
									this->setavailibility(true, i);
								}

							}
						}
						else {
							cout << "You Have Entered the wrong Input Value Try again" << endl << endl;
						}
					} while (choice > 4 || choice < 1);

					int current = myFile.tellg();
					int oneblock = sizeof(this);
					myFile.seekg(current - oneblock);
					myFile.write((char*)&*this, sizeof(doctor));
					cout << "Success!  Updated." << endl;
					myFile.close();
				}
			} 

	}

	void viewpatientAppointment() {
		

	}
	void cancelAppointmentdoc() {

	}
	void commisondeduction() {

	}
	void offeredservices() {

	}

	void write() {
		ofstream fout("doc.bin", ios::binary | ios::app);
		fout.write((char*) & (*this), sizeof(doctor));
		fout.close();

	}
	void displaydoc() {
		int count = this->endTime - this->startTime;
		cout << "(-----------------------------------)" << endl;
		cout << "Doctor Name   " << getfirstNAme() << " " << getlastName() << endl;
		cout << "Hospital Name " << gethospitalName() << "  Hospital" << endl;
		cout << "Phone Number  " << getphoneNumber() << endl;
		cout << "CNIC-Number   " << getcnic() << endl;
		cout << "Address       " << getaddress() << endl;
		cout << "Time :      " << "		Availibility" << endl;
		for (int i = 0; i < count; i++) {
			
			if (getavailibility(i)) {
		cout << getstartTime()+i <<" "<<getClock() <<"			Availible" << endl;
				
			}
			else {
				cout << getstartTime() + i << " " << getClock() << "			Not Availible" << endl;
			}
		}
		cout << "(-----------------------------------)" << endl;
		cout << endl;
	}
	void displayAvail() {
		cout << "(-----------------------------------)" << endl;
		for (int i = 0; i < getendTime() - getstartTime(); i++) {
			if (getavailibility(i)) {
				cout << getstartTime() + i << " " << getClock() << "			Availible" << endl;

			}
			else {
				cout << getstartTime() + i << " " << getClock() << "			Not Availible" << endl;
			}
		}
		cout << "(-----------------------------------)" << endl;
		cout << endl;
	}
	void search() {


	}
	/*-----------------------------------------------------------------------------------------------------------------*/
	void docRegister() {
		string name,clock;
		int st = 0,et=0,avail=0;
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
		cout << "Please enter your hospital name  " << endl;
		cin >> name;
		sethospitalName(name);
		setfeedback("");
		cout << "------------------------------------------" << endl;
		cout << "  You will be availible at AM or PM" << endl;
		cin >> clock;
		this->setClock(clock);
		cout << endl;
		cout << "Please enter your Starting Time  " << endl;
		cin >> st;
		this->setStartTime(st);
		cout << "Please enter your Ending Time  " << endl;
		cin >> et;
		this->setEndTime(et);
		cout << "------------------------------------------" << endl;
		cout << "  Please Fill out the availiblity slots per hour " << endl;
		cout << endl;
		cout << "------------------------------------------" << endl;
		cout << "  Please Press 1 for Availibilty and 0 for the Not Availibity" << endl;
		for (int i = 0; i < et - st; i++) {
			cout << st + i << " " << clock << endl;
			cin >> avail;
			if (avail == 0) {
			this->setavailibility(false, i);
			}
			else {
				this->setavailibility(true, i);
			}
			
		}
		cout << " We have Five Speciality so Please enter your Speacialty accordingly " << endl;
		cout << endl << endl;
		cout << "--------------------------------------------------------------------------------" << endl;
		cout << " Gynecologist  \ \n Orthopedic \ \n Cardiologist \ \n Oncologist \ \n Dermatologist" << endl;
		cout << "Please enter your Speaciality   " << endl;
		cin >> name;
		//Polymorphism...........
		write();
	}










};

#endif