#pragma once
#ifndef appointment_h
#define appointment_h
#include <iostream>
#include <fstream>
#include "string"
#include "doctor.h"
#include "admin.h"
#include "patient.h"
#include "Payment.h"
using namespace std;




class VideoConsultation {
	int charges;
public:
	//--------------------------------------Constructors----------------------------------------------
	VideoConsultation() {
		this->charges = 0;
	}
	VideoConsultation(int g) {
		this->charges = g;
	}
	//--------------------------------------Setters----------------------------------------------
	void setcharges(int g) {
		this->charges = g;
	}

	//--------------------------------------Getters----------------------------------------------
	int getcharges(int g) {
		return this->charges;
	}
	//--------------------------------------Functions----------------------------------------------
	void deductionMoney_video() {

	}


};
class Inperson {
	int charges;
public:
	//--------------------------------------Constructors----------------------------------------------
	Inperson() {
		this->charges = 0;
	}
	Inperson(int h) {
		this->charges = h;
	}
	//--------------------------------------Setters----------------------------------------------

	void setcharges() {
		this->charges;
	}

	//--------------------------------------Getters----------------------------------------------
	int getcharges() {
		return this->charges;
	}
	//--------------------------------------Functions----------------------------------------------
	void deductionMoney_person() {

	}
};


class Date {
	char date[20];
	char time[10];
	char day[10];
public:
	//--------------------------------------Constructor----------------------------------------------
	Date() {
		for (int i = 0; i < 10; i++) {
			this->time[i] = '\0';
			this->day[i] = '\0';
		}
		for (int i = 0; i < 20; i++) {
			this->date[i] = '\0';
		}
	}
	Date(string dat, string tim, string da) {
		strcpy_s(this->date, dat.c_str());
		strcpy_s(this->time, tim.c_str());
		strcpy_s(this->day, da.c_str());
	}
	//--------------------------------------Setters----------------------------------------------
	void setdate(string dat) {
		strcpy_s(this->date, dat.c_str());

	}
	void settime(string tim) {
		strcpy_s(this->time, tim.c_str());
	}
	void setday(string da) {
		strcpy_s(this->day, da.c_str());
	}
	//--------------------------------------Getters----------------------------------------------

	string getdate() {
		return this->date;
	}
	string gettime() {
		return this->time;
	}
	string getday() {
		return this->day;
	}

	//--------------------------------------Functions----------------------------------------------
	void dateofAppointment() {
		string name;
		cout << "	Please Enter the Day of Appointment" << endl;
		cin >> name;
		this->setday(name);
		cout << "   Please Enter the Date of Appointment in day/month/year Format" << endl;
		cin >> name;
		this->setdate(name);
		cout << "	Please Enter the Time of Appointment" << endl;
		cin >> name;
		this->settime(name);


	}
	void cancelDate() {

	}
	void updateDate() {

	}
	void displayDate() {
		cout << "Appointment Day  " << this->getday() << endl;
		cout << "Appointment Date  " << this->getdate() << endl;
		cout << "Appointment Time  " << this->gettime() << endl;
	}

};



 class  appointment :public VideoConsultation, public Inperson {
	char doctorfirstName[20];
	char doctorlastName[20];
	char patientfirstName[20];
	char patientlastName[20];
	char phoneNumber[15];
	char doctorCnic[15];
	char patientCnic[15];
	char status[20];
	char mode[20];
	Date d;
	Account acc;
public:
	//--------------------------------------Constructors----------------------------------------------
	appointment() {
		for (int i = 0; i < 20; i++) {
			this->doctorfirstName[i] = '\0';
			this->doctorlastName[i] = '\0';
			this->patientfirstName[i] = '\0';
			this->patientlastName[i] = '\0';
			this->status[i] = '\0';
			this->mode[i] = '\0';
		}
		for (int i = 0; i < 15; i++) {
			this->doctorCnic[i] = '\0';
			this->patientCnic[i] = '\0';
			this->phoneNumber[i] = '\0';
		}
	}
	appointment(string docfirstname, string doclastname, string patfirstname, string patlastname, string docnic, string patcnic,string num,string mod,string sta) {
		strcpy_s(this->doctorfirstName, docfirstname.c_str());
		strcpy_s(this->doctorlastName, doclastname.c_str());
		strcpy_s(this->patientfirstName, patfirstname.c_str());
		strcpy_s(this->patientlastName, patlastname.c_str());
		strcpy_s(this->doctorCnic, docnic.c_str());
		strcpy_s(this->patientCnic, patcnic.c_str());
		strcpy_s(this->phoneNumber, num.c_str());
		strcpy_s(this->status, sta.c_str());
		strcpy_s(this->mode, mod.c_str());
		
	}
	//--------------------------------------Setters----------------------------------------------
	void setdoctorfirstName(string doc) {
		strcpy_s(this->doctorfirstName, doc.c_str());
	}
	void setdoctorlastName(string doc) {
		strcpy_s(this->doctorlastName, doc.c_str());
	}
	void setpatientfirstName(string pat) {
		strcpy_s(this->patientfirstName, pat.c_str());
		
	}
	void setpatientlastName(string pat) {
		strcpy_s(this->patientlastName, pat.c_str());
	}
	void setdocCnic(string cnic) {
		strcpy_s(this->doctorCnic, cnic.c_str());
	}
	void setpatCnic(string cnic) {
		strcpy_s(this->patientCnic, cnic.c_str());
	}
	void setphoneNumber(string num) {
		strcpy_s(this->phoneNumber, num.c_str());
	}
	void setMode(string mod) {
		strcpy_s(this->mode, mod.c_str());
	}
	void setstatus(string sat) {
		strcpy_s(this->status, sat.c_str());
	}
	//--------------------------------------Getters----------------------------------------------
	string getdoctorfirstName() {
		return this->doctorfirstName;
	}
	string getdoctorlastName() {
		return this->doctorlastName;
	}
	string getpatientfirstName() {
		return this->patientfirstName;
	}
	string getpatientllastName() {
		return this->patientlastName;
	}
	string getdocCnic() {
		return this->doctorCnic;
	}
	string getpatCnic() {
		return this->patientCnic;
	}
	string getphoneNumber() {
		return this->phoneNumber;
	}
	string getMode() {
		return this->mode;
	}
	string getstatus() {
		return this->status;
	}
	//--------------------------------------Functions----------------------------------------------
	void write() {
		ofstream fout("appointment.bin", ios::binary | ios::app);
		fout.write((char*)&(*this), sizeof(doctor));
		fout.close();
	}
	void searchAppointment() {
		string name;
		cout << "Please enter your Doctor's CNIC " << endl;
		cin >> name;
		fstream myFile("appointment.bin", ios::in | ios::out | ios::binary);
		while (myFile.read((char*)&(*this), sizeof(this))) {
			if (getdocCnic() == name) {
				myFile.close();
				cout << "Polo ki shirt" << endl;
				displayAppointment();
			}
			else {
				cout << "No Appointments on this Cnic" << endl;

			}

		}
	}

	void setAppointment() {
		cout << endl << endl;
		string name;
		cout << "Please enter your Doctor's First name " << endl;
		cin >> name;
		this->setdoctorfirstName(name);
		cout << "Please enter your Doctor's Last name " << endl;
		cin >> name;
		this->setdoctorlastName(name);
		cout << "------------------------------------------" << endl;
		cout << "Please enter your Patient's First name " << endl;
		cin >> name;
		this->setpatientfirstName(name);
		cout << "Please enter your Patient's Last name " << endl;
		cin >> name;
		this->setpatientlastName(name);
		cout << "------------------------------------------" << endl;
		cout << "Please enter your Doctor's CNIC " << endl;
		cin >> name;
		this->setdocCnic(name);
		cout << "Please enter your Patient CNIC" << endl;
		cin >> name;
		this->setpatCnic(name);
		cout << "Please enter your Phone Number " << endl;
		cin >> name;
		this->setphoneNumber(name);
		cout << "------------------------------------------" << endl;
		this->setstatus("Pending");
		d.dateofAppointment();
		cout << "Please enter Mode of Appoinment \ \nIt casn be Online or Physical" << endl;
		cin >> name;
		this->setMode(name);
		acc.payMoney();
		this->write();
		cout << "Please Wait for the Response \ \nYou wll get a confirmation message to your number" << endl;
	}
	void editAppointment() {
		string name;
		int choice = 0;
		cout << "Please enter your Doctor's CNIC " << endl;
		cin >> name;
		fstream myFile("appointment.bin", ios::in | ios::out | ios::binary);
		while (myFile.read((char*)&(*this), sizeof(this))) {
			if (getdocCnic() == name) {
				do {
					cout << "Please Enter What Would You Like to Edit" << endl;
					cout << "Press 1 to change the Date - Day - Time of Appointment" << endl;
					cout << "Press 2 to change the Phone Number" << endl;
					cout << "Press 3 to change the Status of Appointment" << endl;
					if (choice == 1) {
						d.dateofAppointment();
					}
					else if (choice == 2) {
						cout << "Please enter your Phone Number " << endl;
						cin >> name;
						this->setphoneNumber(name);
					}
					else if (choice == 3) {
						cout << " Please Enter the Status of the Appointment " << endl;
						cin >> name;
						this->setstatus(name);
					}
					else {
						cout << endl;
						cout << "Wrong Input" << endl;
					}
				} while (choice > 3 || choice < 1);

				int current = myFile.tellg();
				int oneblock = sizeof(this);
				myFile.seekg(current - oneblock);
				myFile.write((char*)&*this, sizeof(this));
				cout << "Success! Updated." << endl;
				myFile.close();
			}
		
		}
	}
	void cancelAppointment() {
		string a;
		cout << "Please Enter the Cnic of the Doctor " << endl;
		cin >> a;
		fstream myFile("appointment.bin", ios::in | ios::out | ios::binary);
		ofstream myFile_temp("temp.bin", ios::app | ios::binary);
		while (myFile.read((char*)&(*this), sizeof(this))) {
			if (getdocCnic()==a) {
				myFile_temp.write((char*)&(*this), sizeof(this));
			}
			else {
				cout << "Success!  Deleted." << endl;
			}
		}
		myFile.close();
		myFile_temp.close();
		remove("appointment.bin");
		rename("temp.bin", "appointment.bin");
	}





	void displayAppointment() {
		cout << "(-----------------------------------)" << endl;
		cout << "Doctor Name			 " << getdoctorfirstName() << " " << getdoctorlastName() << endl;
		cout << "Patient Name			 " << getpatientfirstName() << " " << getpatientllastName() << endl;
		cout << "Patient's Phone Number  " << getphoneNumber() << endl;
		cout << "Doctor's CNIC-Number    " <<getdocCnic() << endl;
		cout << "Patient's CNIC-Number   " << getpatCnic() << endl;
		d.displayDate();
		cout << "Appointment Status      " << getstatus() << endl;


	}
	

};

#endif