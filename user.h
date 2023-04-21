#pragma once
#ifndef user_h
#define user_h
#include <iostream>
#include <fstream>
#include "string"
//#include "account.h"
//#include "Speciality.h"


#include "admin.h"
#include "patient.h"
#include "doctor.h"
using namespace std;

void searchPAt() {
	patient temp;
	string a;
	cout << "Please Enter PAtiient's Cnic to Search the Patient  " << endl;
	cin >> a;
	ifstream file("pat.bin", ios::out | ios::in | ios::binary);
	while (file.read((char*)&temp, sizeof(patient)))
	{

		if (temp.getcnic() == a)
		{

			file.close();
			temp.displayPat();
			break;

		}
	}
}
void editAppointment() {
	appointment a;
	a.editAppointment();
}
void dispApp() {
	appointment a;
	a.searchAppointment();
}



















class user :public doctor, public admin, public patient {
	string userName;
public:
	//----------------------------------------Constructors-----------------------------------------------------
	user() {
		this->userName = "";

	}
	user(string user, string pass) {
		this->userName = user;

	}
	//----------------------------------------Setters-----------------------------------------------------
	void setusername(string a) {
		this->userName = a;
	}
	//----------------------------------------Getters-----------------------------------------------------
	string getusername() {
		return this->userName;
	}
	//----------------------------------------Functions-----------------------------------------------------
	void Menu() {
		cout << "-------------------------------------------------------------------------------------------------" << endl;
		cout << "|                   Do not worry, it will be a purification                                      |" << endl;
		cout << "|                        (for you), Allah willing                                                |" << endl;
		cout << "|                                                                                                |" << endl;
		cout << "--------------------------------------------------------------------------------------------------" << endl;

		cout << endl << endl;
		cout << "                                     Welcome to OLADOC                                                " << endl;
		cout << "                                   We Welcome You On Board                                            " << endl;

		cout << endl;
		int solp = 0, choice = 0;
		do {
			cout << "			  Please Enter your choice                                           " << endl;
			cout << endl;
			cout << "		Please Press 1 if you want to Login \ \n\n		Press 2 if you want to Register \ \n\n		Press 3 if you want to search doctors\ \n\n		Press 4 to view the OLADOC Details" << endl;
			cout << endl;
			cin >> solp;
			switch (solp) {
			case 1:
				login();
				Menu();
				break;
			case 2:
				Register();
				Menu();
				break;
			case 3:
				searchDoctor();
				Menu();
				break;
			case 4:
				cout << "		OLADOC brings 'Health at Your Fingertips' in Pakistan. You can search,\ \n		Select and book specialist doctors near you in a convenient and hassle-free manner.\ \n		With oladoc, you get INSTANT doctor appointment confirmations as well as reminders." << endl;
				cout << endl << endl;

				do {
					cout << "		Please Press 1 if you want to go the main Menu\ \n\n		Press 0 to terminate the Program	" << endl;
					cout << endl;
					cin >> choice;
					switch (choice) {
					case 1:
						Menu();
						break;
					case 2:
						break;
					default:
						cout << "		You have entered the Wrong Input		" << endl << endl;
						cout << "		Please ReEnter the Values				" << endl << endl;
					}
				} while (choice != 1 && choice != 0);

				break;
			default:
				cout << "		You have entered the Wrong Input		" << endl << endl;
				cout << "		Please ReEnter the Values				" << endl << endl;
			}
		} while (solp > 4 || solp < 1);

	}










	/*=======================================================================================================================*/
	void login() {
		int count = 0;


		cout << "-------------------------------------------------------------------------------------------------" << endl;
		cout << "|                        Welcome to the Login Portal                                             |" << endl;
		cout << "|                                                                                                |" << endl;
		cout << "--------------------------------------------------------------------------------------------------" << endl;

		cout << endl << endl;
		cout << " There are three types of catogories  " << endl;
		cout << " Admin \ \n Doctor \ \n Patient" << endl;
		cout << endl;
		cout << "Please enter your catagory " << endl;
		cin >> this->userName;
		if (this->userName == "doctor" || this->userName == "Doctor") {
			doctor temp;
			string a, p;
			cout << "Please enter your Cnic number to login " << endl;
			cin >> a;
			cout << "Please enter your Password to login " << endl;
			cin >> p;
			ifstream file("doc.bin", ios::out | ios::in | ios::binary);
			while (file.read((char*)&temp, sizeof(doctor)))
			{
				if ((temp.getcnic() == a) && (temp.getpassword() == p))
				{

					file.close();
					temp.displaydoc();
					cout << "Welcome Back to Oladoc Mr\\Miss. " << temp.getfirstNAme() << " " << temp.getlastName() << endl;
					cout << endl;
					cout << "------------------------------------------" << endl;
					cout << endl;
					cout << "You have been Successfuly Login  Mr\\Miss. " << temp.getfirstNAme() << " " << temp.getlastName() << endl;
					break;
				}
				else {
					do {
						cout << " You have put Invalid Credential \ \n OR \ \n You havn't Register yourself " << endl;
						cout << "------------------------------------------" << endl;
						cout << "If you havn't register yourself then press 1 \ \n OR \ \n Press 2 for goto login portal again " << endl;
						cin >> count;
						if (count == 1) {
							Register();
						}
						else if (count == 2) {
							login();
						}
						else {
							cout << "Wrong Input " << endl;
						}
					} while ((count != 1) || (count != 2));

				}

			}
			int docChoice = 0;
			do {
				cout << "Welcome Back to Oladoc Mr\\Miss. " << temp.getfirstNAme() << " " << temp.getlastName() << endl;
				cout << endl;
				cout << "Please Enter What Would You Like to Do" << endl;
				cout << "Press 1 to Edit Your Profile      " << endl;
				cout << "Press 2 to Display your Data" << endl;
				cout << "Press 3 to Display Appointments" << endl;
				cout << "Press 4 to Display Patient Data " << endl;
				cout << "Press 5 to Edit Appointment     " << endl;
				cout << "Press 6 to Delete Profile     " << endl;
				cout << "Press 7 to Go to the Menu     " << endl;
				cout << "Press 8 to Again use Doctor's Panel     " << endl;
				cin >> docChoice;
				if (docChoice == 1) {
					temp.Editprofile();
				}
				else if (docChoice == 2) {
					temp.displaydoc();
				}
				else if (docChoice == 3) {
					dispApp();
				}
				else if (docChoice == 4) {
					searchPAt();
				}
				else if (docChoice == 5) {
					editAppointment();
				}
				else if (docChoice == 6) {
					temp.delProfile();
				}
				else if (docChoice == 7) {
					Menu();
				}
				else {
					cout << "Wrong Input" << endl;
				}
			} while (docChoice > 6 || docChoice < 1 || docChoice==8);


		}
	
		/*-----------------------------*/


		if (this->userName == "patient" || this->userName == "Patient") {

			patient temp;
			string a, p;
			cout << "Please enter your Cnic number to login " << endl;
			cin >> a;
			cout << "Please enter your Password to login " << endl;
			cin >> p;
			ifstream file("pat.bin", ios::out | ios::in | ios::binary);
			while (file.read((char*)&temp, sizeof(patient)))
			{
				if ((temp.getcnic() == a) && (temp.getpassword() == p))
				{

					file.close();
					temp.displayPat();
					cout << "Welcome Back to Oladoc Mr\\Miss. " << temp.getfirstNAme() << " " << temp.getlastName() << endl;
					cout << endl;
					cout << "------------------------------------------" << endl;
					cout << endl;
					cout << "You have been Successfuly Login  Mr\\Miss. " << temp.getfirstNAme() << " " << temp.getlastName() << endl;
					break;
				}
				else {
					do {
						cout << " You have put Invalid Credential \ \n OR \ \n You havn't Register yourself " << endl;
						cout << "------------------------------------------" << endl;
						cout << "If you havn't register yourself then press 1 \ \n OR \ \n Press 2 for goto login portal again " << endl;
						cin >> count;
						if (count == 1) {
							Register();
						}
						else if (count == 2) {
							login();
						}
						else {
							cout << "Wrong Input " << endl;
						}
					} while ((count != 1) || (count != 2));

				}

			}

			int docChoice = 0;
			do {
				cout << "Welcome Back to Oladoc Mr\\Miss. " << temp.getfirstNAme() << " " << temp.getlastName() << endl;
				cout << endl;
				cout << "Please Enter What Would You Like to Do" << endl;
				cout << "Press 1 to Book Appointment      " << endl;
				cout << "Press 2 to Display Appointment" << endl;
				cout << "Press 3 to Cancel Appointments" << endl;
				cout << "Press 4 to Search Doctor " << endl;
				cout << "Press 5 to Display Profile     " << endl;
				cout << "Press 6 to Delete Profile     " << endl;
				cout << "Press 7 to Go to the Menu     " << endl;
				cout << "Press 8 to Reuse Patient Panel     " << endl;
				cin >> docChoice;
				if (docChoice == 1) {
					temp.bookAppointment();
				}
				else if (docChoice == 2) {
					temp.displayAppointment();
				}
				else if (docChoice == 3) {
					temp.cancelAppointmentpat();
				}
				else if (docChoice == 4) {
					temp.searchDoctor();
				}
				else if (docChoice == 5) {
					temp.displayPat();
				}
				else if (docChoice == 6) {
					temp.delProfile();
				}
				else if (docChoice == 7) {
					Menu();
				}
				else {
					cout << "Wrong Input" << endl;
				}
			} while (docChoice > 7 || docChoice < 1 || docChoice==8);




		}


		if (this->userName == "Admin" || this->userName == "admin") {

			admin temp;
			string a, p;
			cout << "Please enter your Cnic number to login " << endl;
			cin >> a;
			cout << "Please enter your Password to login " << endl;
			cin >> p;
			ifstream file("admin.bin", ios::out | ios::in | ios::binary);
			while (file.read((char*)&temp, sizeof(patient)))
			{
				if ((temp.getcnic() == a) && (temp.getpassword() == p))
				{

					file.close();
					temp.displayadmin();
					cout << "Welcome Back to Oladoc Mr\\Miss. " << temp.getfirstNAme() << " " << temp.getlastName() << endl;
					cout << endl;
					cout << "------------------------------------------" << endl;
					cout << endl;
					cout << "You have been Successfuly Login  Mr\\Miss. " << temp.getfirstNAme() << " " << temp.getlastName() << endl;
					break;
				}
				else {
					do {
						cout << " You have put Invalid Credential \ \n OR \ \n You havn't Register yourself " << endl;
						cout << "------------------------------------------" << endl;
						cout << "If you havn't register yourself then press 1 \ \n OR \ \n Press 2 for goto login portal again " << endl;
						cin >> count;
						if (count == 1) {
							Register();
						}
						else if (count == 2) {
							login();
						}
						else {
							cout << "Wrong Input " << endl;
						}
					} while ((count != 1) || (count != 2));

				}

			}
			int docChoice = 0;
			do {
				cout << "Welcome Back to Oladoc Mr\\Miss. " << temp.getfirstNAme() << " " << temp.getlastName() << endl;
				cout << endl;
				cout << "Please Enter What Would You Like to Do" << endl;
				cout << "Press 1 to Display Doctor's Profile      " << endl;
				cout << "Press 2 to Display your Data" << endl;
				cout << "Press 3 to Display Appointments" << endl;
				cout << "Press 4 to Display Patient Data " << endl;
				cout << "Press 5 to Edit Appointment     " << endl;
				cout << "Press 6 to Delete Doctor's Profile     " << endl;
				cout << "Press 7 to Add Doctor     " << endl;
				cout << "Press 8 to Go to the Menu     " << endl;
				cout << "Press 9 to Reuse Admin Panel     " << endl;
				cin >> docChoice;
				if (docChoice == 1) {
					temp.searchdoc();
				}
				else if (docChoice == 2) {
					temp.displayadmin();
				}
				else if (docChoice == 3) {
					temp.viewAppointment();
				}
				else if (docChoice == 4) {
					temp.displaypat();
				}
				else if (docChoice == 5) {
					temp.editAppointment();
				}
				else if (docChoice == 6) {
					temp.delDoctor();
				}
				else if (docChoice == 7) {
					temp.addDoctor();
				}
				else if (docChoice == 8) {
					Menu();
				}
				else {
					cout << "Wrong Input" << endl;
				}
			} while (docChoice > 6 || docChoice < 1 || docChoice==9);
		}
		cout << endl << endl;
		cout << "             Press 1 if Want to go to the Main Menu  " << endl;
	int	hop = 0;
		do {
			cin >> hop;
			if (hop == 1) {
				Menu();
			}
			else {
				cout << "           Wrong Input" << endl;
			}
		} while (hop != 1);
	}
	/*--------------------------------Register--------------------------------------*/
	void Register() {
		string cnic, name, hospital;
		cout << "-------------------------------------------------------------------------------------------------" << endl;
		cout << "|                               Welcome to the Registeration Portal                              |" << endl;
		cout << "|                                                                                                |" << endl;
		cout << "--------------------------------------------------------------------------------------------------" << endl;
		cout << endl;
		cout << " There are three types of catogories  " << endl;
		cout << " Admin  \ \n Doctor \ \n Patient" << endl;
		cout << "---------------------------------------" << endl;
		cout << "Please your catagory " << endl;
		cin >> this->userName;
		if (this->userName == "doctor" || this->userName == "Doctor") {
			docRegister();
			Menu();
		}
		else if (this->userName == "patient" || this->userName == "Patient") {
			patRegister();
			Menu();
		}
		else if (this->userName == "Admin" || this->userName == "admin") {
			adminRegister();
			Menu();
		}
		else {
			
		cout << "You Havn't Put the right value " << endl;
		Register();
		}

	}

	void reset() {
		remove("appointment.bin");
		remove("doc.bin");
		remove("pat.bin");
		remove("payment.bin");
		remove("admin.bin");
		ofstream myFile("doc.bin", ios::app | ios::binary);
		myFile.close();
		ofstream myFile_("pat.bin", ios::app | ios::binary);
		myFile_.close();
		ofstream myFile_temp("admin.bin", ios::app | ios::binary);
		myFile_temp.close();
		ofstream myFile_te("payment.bin", ios::app | ios::binary);
		myFile_te.close();
		ofstream myFile_tem("appointment.bin", ios::app | ios::binary);
		myFile_tem.close();
	}

};
#endif