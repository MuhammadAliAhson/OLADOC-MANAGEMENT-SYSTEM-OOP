#pragma once
#ifndef account_h
#define account_h
#include <iostream>
#include <fstream>



using namespace std;


class Bank {
	char bankName[20];
	char accountNumber[20];
	int balance;
public:
	//--------------------------------------Constructors----------------------------------------------
	Bank() {
		for (int i = 0; i < 20; i++) {
			this->bankName[i] = '\0';
			this->accountNumber[i] = '\0';
		}
		balance = 3500;
	}
	Bank(string bank, string acc,int y) {
		strcpy_s(this->bankName, bank.c_str()); 
		strcpy_s(this->accountNumber, acc.c_str()); 
		this->balance = y;
	}
	//--------------------------------------Setters----------------------------------------------
	void setbankName(string bak) {
		strcpy_s(this->bankName, bak.c_str());
	}
	void setaccountNumber(string acc) {
		strcpy_s(this->accountNumber, acc.c_str());
	}
	void setBalance(int y) {
		this->balance = y;
	}
	//--------------------------------------Getters----------------------------------------------
	string getbankName() {
		return this->bankName;
	}
	string grtaccountNumber() {
		return this->accountNumber;
	}
	int getBbalance() {
		return this->balance;
	}
	//--------------------------------------Functions----------------------------------------------
	void makeBpayment() {
		string alo;
		cout << "		Please Enter Bank Name (United , Mezan , Allied) 		" << endl;
		cin >> alo;
		setbankName(alo);
		cout << "		Please Enter your Account Number		" << endl;
		cin >> alo;
		setaccountNumber(alo);

	}
	void addMoney() {
		cout << "		Please Enter Bank Name (EasyPaisa , Nayapay , Sadapay) 		" << endl;
		string alo;
		cin >> alo;
		setbankName(alo);
		cout << "		Please Enter your Account Number		" << endl;
		cin >> alo;
		setaccountNumber(alo);
		cout << "			Please Enter the Amount to add in Account" << endl;
		int h = 0;
		cin >> h;
		h += getBbalance();
		setBalance(h);
	}

};

class E_transaction {
	char companyName[20];
	char phonenumber[20];
	int balance;
public:
	//--------------------------------------Constructor----------------------------------------------
	E_transaction() {
		for (int i = 0; i < 20; i++) {
			this->companyName[i] = '\0';
			this->phonenumber[i] = '\0';
		}
		this->balance=3500;
	}
	E_transaction(string com, string phone,int y) {
		strcpy_s(this->companyName, com.c_str());
		strcpy_s(this->phonenumber, phone.c_str());  
		this->balance=y;
	}
	//--------------------------------------Setter----------------------------------------------
	void setcompanyName(string com) {
		strcpy_s(this->companyName, com.c_str());
	}
	void setphoneNumber(string phone) {
		strcpy_s(this->phonenumber, phone.c_str());
	}
	void setBalance(int y) {
		this->balance = y;
	}
	//--------------------------------------Getter----------------------------------------------
	string getcompanyName() {
		return this->companyName;
	}
	string getphoneNumber() {
		return this->phonenumber;
	}
	int getEbalance() {
		return this->balance;
	}
	//--------------------------------------Functions----------------------------------------------
	void makeEpayment() {
		cout << "		Please Enter Company Name (EasyPaisa , Nayapay , Sadapay) 		" << endl;
		string alo;
		cin >> alo;
		setcompanyName(alo);
		cout << "		Please Enter your Phone Number		" << endl;
		cin >> alo;
		setphoneNumber(alo);
	}
	void addEMoney() {
		cout << "		Please Enter Company Name (EasyPaisa , Nayapay , Sadapay) 		" << endl;
		string alo;
		cin >> alo;
		setcompanyName(alo);
		cout << "		Please Enter your Phone Number		" << endl;
		cin >> alo;
		setphoneNumber(alo);
		cout << "			Please Enter the Amount to add in Account" << endl;
		int h = 0;
		cin >> h;
		h += getEbalance();
		setBalance(h);
	}


};





class Account : public E_transaction, public Bank {
	int balance;
	char accountNumber[30];
	char paymentType[30];
public:
	//--------------------------------------Constructors-------------------------------------------
	Account() {
		this->balance = 3500;
		for (int i = 0; i < 30; i++) {
			this->accountNumber[i] = '\0';
			this->paymentType[i] = '\0';
		}
	}

	Account(int bal, string acc, string pay) {
		this->balance = bal;
		strcpy_s(this->accountNumber,acc.c_str());	 
		strcpy_s(this->paymentType, pay.c_str()); 
	}

	//--------------------------------------Setters------------------------------------------------
	void setbalance(int bal) {
		this->balance = bal;
	}
	void setaccountNumber(string acc) {
		strcpy_s(this->accountNumber, acc.c_str());
	}
	void setpayment(string pay) {
		strcpy_s(this->paymentType, pay.c_str());
	}



	//--------------------------------------Getters------------------------------------------------
	int getbalance() {
		return this->balance;
	}
	string getaccountNumber() {
		return this->accountNumber;
	}
	string getpayment() {
		return this->paymentType;
	}



	//--------------------------------------Function-----------------------------------------------
	void write() {
		ofstream fout("payment.bin", ios::binary | ios::app);
		fout.write((char*)&(*this), sizeof(Account));
		fout.close();
	}
	
	
	void payMoney() {
		int kop = 0;
		cout << "						Pay Money							" << endl << endl;
		cout << "		Please	Enter your Payment Mode " << endl << endl;
	do{
		cout << "			Press 1 for the Bank System and 2 for E-Gateway" << endl;
		cin >> kop;
		if (kop == 1) {
			makeBpayment();
			setaccountNumber(getaccountNumber());
		}
		else if (kop == 2) {
			makeEpayment();
			setaccountNumber(getphoneNumber());
		}
		else {
			cout << endl;
			cout << "Wrong Input" << endl;
		}
	}while (kop > 2 || kop < 1);

		
	
	}

	void addMoney() {
		int kop = 0;
		cout << "						Add Money							" << endl << endl;
		cout << "		Please	Enter your Payment Mode " << endl << endl;
		do {
			cout << "			Press 1 for the Bank System and 2 for E-Gateway" << endl;
			cin >> kop;
			if (kop == 1) {
				makeBpayment();
				setaccountNumber(getaccountNumber());
				this->setbalance(getBbalance());
			}
			else if (kop == 2) {
				makeEpayment();
				setaccountNumber(getphoneNumber());
				this->setbalance(getEbalance());
			}
			else {
				cout << endl;
				cout << "Wrong Input" << endl;
			}
		} while (kop > 2 || kop < 1);


		

	}

	void displaybalance() {


	}

	void displayaccountDetails() {

	}




};

#endif