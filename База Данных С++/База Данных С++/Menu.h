#pragma once
#include "Workio.h"
#include "WorkWithFile.h"
#include "SellerService.h"
#include "WorkWithData.h"
#include <iostream>
#include <string>
#include <sstream>
#include <conio.h>
#include <vector>
#include <cstdio>

using namespace std;

struct PRODUCT {
	char type[11];   //��� 
	char info[16];   //��������
	char charact[21];//��������������
	int  nomer;      //�������� �����
	int  cost;       //����
	int  day;        //���� �������
	int  month;      //����� �������
	int  year;       //��� �������

	PRODUCT() {
		string newString;

		while (getchar() != '\n');
		cout << "������� ���: " << endl;
		while (true) {
			getline(cin, newString);
			if (newString.length() > 10) {
				cout << "�������� ���� �� ����� ��������� 10 ��������!" << endl;
			}
			else {
				for (int i = 0; i < newString.length(); i++) {
					type[i] = newString[i];
				}
				type[newString.length()] = '\0';
				break;
			}
		}
		cout << "������� ��������: " << endl;
		while (true) {
			getline(cin, newString);
			if (newString.length() > 15) {
				cout << "�������� �������� �� ����� ��������� 15 ��������!" << endl;
			}
			else {
				for (int i = 0; i < newString.length(); i++) {
					info[i] = newString[i];
				}
				info[newString.length()] = '\0';
				break;
			}
		}
		cout << "������� ��������������: " << endl;
		while (true) {
			getline(cin, newString);
			if (newString.length() > 20) {
				cout << "�������� �������� �� ����� ��������� 20 ��������!" << endl;
			}
			else {
				for (int i = 0; i < newString.length(); i++) {
					charact[i] = newString[i];
				}
				charact[newString.length()] = '\0';
				break;
			}
		}
		cout << "������� �������� �����: " << endl;
		while (true) {
			while (true) {//�������� �� ���������� ����
				cin >> nomer; //�������� �����
				if (!cin) {
					cout << "������������ ���� ��������� ������, ������� ������������ �����." << endl;
					cin.clear();
					while (getchar() != '\n');
				}
				else break;
			}
			if (nomer >= 100000 && nomer <= 999999)
				break;
			else
				cout << "������������ ���� ��������� ������, ������� ������������ �����." << endl;
		}
		cout << "������� ����(� ��������): " << endl;
		while (true) {
			while (true) {
				cin >> cost; //����
				if (!cin) {
					cout << "������������ ���� ����, ������� ����� �� ������ 10000$." << endl;
					cin.clear();
					while (getchar() != '\n');
				}
				else break;
			}
			if (cost > 10000) {
				cout << "�� ������! � ��� ��� ��������� ������� �������(�� ������ 10000$)." << endl;
				cin.clear();
				while (getchar() != '\n');
			}
			else break;
		}
	}

	PRODUCT(ifstream& fin) {
		char ints[7];//��������������

		fin.getline(type, 11);
		fin.getline(info, 16);
		fin.getline(charact, 21);
		fin.getline(ints, 7);
		nomer = atoi(ints);
		fin.getline(ints, 7);
		cost = atoi(ints);
	}

	PRODUCT(ifstream& fin, string sold) {
		char ints[7];//��������������

		fin.getline(type, 11);
		fin.getline(info, 16);
		fin.getline(charact, 21);
		fin.getline(ints, 7);
		nomer = atoi(ints);
		fin.getline(ints, 7);
		cost = atoi(ints);
		fin.getline(ints, 7);
		day = atoi(ints);
		fin.getline(ints, 7);
		month = atoi(ints);
		fin.getline(ints, 7);
		year = atoi(ints);
	}

	void InputDate() {
		cout << "������� ���� �������: " << endl;
		while (true) {//�������� �� ���������� ����
			cin >> day; //���� ���
			if (!cin) {
				cout << "������������ ���� ��� �������, ������� �����." << endl;
				cin.clear();
				while (getchar() != '\n');
			}
			else if (day <= 31 && day >= 1) {
				break;
			}
			else {
				cout << "������������ ���� ���." << endl;
			}
		}
		cout << "������� ����� �������:" << endl;
		while (true) {
			cin >> month; //���� ������
			if (!cin) {
				cout << "������������ ���� ������ �������, ������� �����." << endl;
				cin.clear();
				while (getchar() != '\n');
			}
			else if (month <= 12 && month >= 1) {
				break;
			}
			else {
				cout << "������������ ���� ������." << endl;
			}
		}
		cout << "������� ��� �������(1900 - 2100 ��.) " << endl;
		while (true) {
			cin >> year; //���� ���
			if (!cin) {
				cout << "������������ ���� ���� ����, ������� �����." << endl;
				cin.clear();
				while (getchar() != '\n');
			}
			else if (year <= 2100 && year >= 1900) {
				break;
			}
			else {
				cout << "������������ ���� ����." << endl;
			}
		}
	}

	void PrintItem() {
		cout << "���: " << type << endl
			<< "��������: " << info << endl
			<< "��������������: " << charact << endl
			<< "�������� �����: " << nomer << endl
			<< "����: " << cost << '$' << endl << endl;
		cout << "====================================" << endl;
	}

	void PrintSoldItem() {
		cout << "���: " << type << endl
			<< "��������: " << info << endl
			<< "��������������: " << charact << endl
			<< "�������� �����: " << nomer << endl
			<< "����: " << cost << '$' << endl
			<< "���� �������: ";
		if (day / 10 == 0) { cout << '0'; }
		cout << day << '.';
		if (month / 10 == 0) { cout << '0'; }
		cout << month << '.' << year << endl << endl;
		cout << "====================================" << endl;
	}

	void PrintTableItem() {
		cout << type;
		if (strlen(type) < 10) {
			for (int i = 0; i < 10 - strlen(type); i++) {
				cout << ' ';
			}
		}
		cout << '|';
		cout << info;
		if (strlen(info) < 15) {
			for (int i = 0; i < 15 - strlen(info); i++) {
				cout << ' ';
			}
		}
		cout << '|';
		cout << charact;
		if (strlen(charact) < 20) {
			for (int i = 0; i < 20 - strlen(charact); i++) {
				cout << ' ';
			}
		}
		cout << '|';
		cout << nomer;
		for (int i = 0; i < 9; i++) {
			cout << ' ';
		}
		cout << '|';
		cout << cost << '$';
		int count = 0, j = cost + 1;
		while ((j /= 10) > 0) count++;
		for (int i = 0; i < 8 - count; i++) {			
			cout << ' ';
		}

		cout << '|' << endl;
	}

	void PrintTableSoldItem() {
		cout << type;
		if (strlen(type) < 10) {
			for (int i = 0; i < 10 - strlen(type); i++) {
				cout << ' ';
			}
		}
		cout << '|';
		cout << info;
		if (strlen(info) < 15) {
			for (int i = 0; i < 15 - strlen(info); i++) {
				cout << ' ';
			}
		}
		cout << '|';
		cout << charact;
		if (strlen(charact) < 20) {
			for (int i = 0; i < 20 - strlen(charact); i++) {
				cout << ' ';
			}
		}
		cout << '|';
		cout << nomer;
		for (int i = 0; i < 9; i++) {
			cout << ' ';
		}
		cout << '|';
		cout << cost << '$';
		int count = 0, j = cost + 1;
		while ((j /= 10) > 0) count++;
		for (int i = 0; i < 8 - count; i++) {
			cout << ' ';
		}
		cout << '|';
		if (day / 10 == 0) { cout << '0'; }
		cout << day << '.';
		if (month / 10 == 0) { cout << '0'; }
		cout << month << '.' << year;
		for (int i = 0; i < 3; i++) {
			cout << ' ';
		}
		cout << '|' << endl;
	}

	void EditPart() {
		int state;
		cout << "�������� ����� �������: " << endl;
		cout << "1. ������������� ���" << endl;
		cout << "2. ������������� ��������" << endl;
		cout << "3. ������������� ��������������" << endl;
		cout << "4. ������������� �������� �����" << endl;
		cout << "5. ������������� ����" << endl;
		cout << "9. ��������� �����" << endl;
		cout << "�������� �������: " << endl;
		while (true) {//�������� �� ���������� ����
			cin >> state;
			if (!cin) {
				system("cls");
				cout << "�������� ����� �������: " << endl;
				cout << "1. ������������� ���" << endl;
				cout << "2. ������������� ��������" << endl;
				cout << "3. ������������� ��������������" << endl;
				cout << "4. ������������� �������� �����" << endl;
				cout << "5. ������������� ����" << endl;
				cout << "9. ��������� �����" << endl;
				cout << "�������� �������: " << endl;
				cin.clear();
				while (getchar() != '\n');
			}
			else break;
		}
		system("cls");
		switch (state) {
		case 1: {
			string newString;

			while (getchar() != '\n');
			cout << "������� ����� ���: " << endl;
			while (true) {
				getline(cin, newString);
				if (newString.length() > 10) {
					cout << "�������� ���� �� ����� ��������� 10 ��������!" << endl;
				}
				else {
					for (int i = 0; i < newString.length(); i++) {
						type[i] = newString[i];
					}
					type[newString.length()] = '\0';
					break;
				}
			}
			break;
		}
		case 2: {
			string newString;

			while (getchar() != '\n');
			cout << "������� ����� ��������: " << endl;
			while (true) {
				getline(cin, newString);
				if (newString.length() > 15) {
					cout << "�������� �������� �� ����� ��������� 15 ��������!" << endl;
				}
				else {
					for (int i = 0; i < newString.length(); i++) {
						info[i] = newString[i];
					}
					info[newString.length()] = '\0';
					break;
				}
			}
			break;
		}
		case 3: {
			string newString;

			while (getchar() != '\n');
			cout << "������� ����� ��������������: " << endl;
			while (true) {
				getline(cin, newString);
				if (newString.length() > 20) {
					cout << "�������� �������� �� ����� ��������� 20 ��������!" << endl;
				}
				else {
					for (int i = 0; i < newString.length(); i++) {
						charact[i] = newString[i];
					}
					charact[newString.length()] = '\0';
					break;
				}
			}
			break;
		}
		case 4: {
			cout << "������� ����� �������� �����: " << endl;
			while (true) {
				while (true) {//�������� �� ���������� ����
					cin >> nomer; //�������� �����
					if (!cin) {
						cout << "������������ ���� ��������� ������, ������� ������������ �����." << endl;
						cin.clear();
						while (getchar() != '\n');
					}
					else break;
				}
				if (nomer >= 100000 && nomer <= 999999)
					break;
				else
					cout << "������������ ���� ��������� ������, ������� ������������ �����." << endl;
			}
			break;
		}
		case 5: {
			cout << "������� ����� ����(� ��������): " << endl;
			while (true) {
				while (true) {
					cin >> cost; //����
					if (!cin) {
						cout << "������������ ���� ����, ������� ����� �� ������ 10000$." << endl;
						cin.clear();
						while (getchar() != '\n');
					}
					else break;
				}
				if (cost > 10000) {
					cout << "�� ������! � ��� ��� ��������� ������� �������(�� ������ 10000$)." << endl;
					cin.clear();
					while (getchar() != '\n');
				}
				else break;
			}
			break;
		}
		case 9: {
			break;
		}
		}
	}

	void EditFull() {
		string newString;

		while (getchar() != '\n');
		cout << "������� ���: " << endl;
		while (true) {
			getline(cin, newString);
			if (newString.length() > 10) {
				cout << "�������� ���� �� ����� ��������� 10 ��������!" << endl;
			}
			else {
				for (int i = 0; i < newString.length(); i++) {
					type[i] = newString[i];
				}
				type[newString.length()] = '\0';
				break;
			}
		}
		cout << "������� ��������: " << endl;
		while (true) {
			getline(cin, newString);
			if (newString.length() > 15) {
				cout << "�������� �������� �� ����� ��������� 15 ��������!" << endl;
			}
			else {
				for (int i = 0; i < newString.length(); i++) {
					info[i] = newString[i];
				}
				info[newString.length()] = '\0';
				break;
			}
		}
		cout << "������� ��������������: " << endl;
		while (true) {
			getline(cin, newString);
			if (newString.length() > 20) {
				cout << "�������� �������� �� ����� ��������� 20 ��������!" << endl;
			}
			else {
				for (int i = 0; i < newString.length(); i++) {
					charact[i] = newString[i];
				}
				charact[newString.length()] = '\0';
				break;
			}
		}
		cout << "������� �������� �����: " << endl;
		while (true) {
			while (true) {//�������� �� ���������� ����
				cin >> nomer; //�������� �����
				if (!cin) {
					cout << "������������ ���� ��������� ������, ������� ������������ �����." << endl;
					cin.clear();
					while (getchar() != '\n');
				}
				else break;
			}
			if (nomer >= 100000 && nomer <= 999999)
				break;
			else
				cout << "������������ ���� ��������� ������, ������� ������������ �����." << endl;
		}
		cout << "������� ����(� ��������): " << endl;
		while (true) {
			while (true) {
				cin >> cost; //����
				if (!cin) {
					cout << "������������ ���� ����, ������� ����� �� ������ 10000$." << endl;
					cin.clear();
					while (getchar() != '\n');
				}
				else break;
			}
			if (cost > 10000) {
				cout << "�� ������! � ��� ��� ��������� ������� �������(�� ������ 10000$)." << endl;
				cin.clear();
				while (getchar() != '\n');
			}
			else break;
		}
	}

	void SaveInFile(ofstream& fout) {
		fout << type << endl
			<< info << endl
			<< charact << endl
			<< nomer << endl
			<< cost << endl;
	}

	void SaveInFileSold(ofstream& fout) {
		fout << type << endl
			<< info << endl
			<< charact << endl
			<< nomer << endl
			<< cost << endl
			<< day << endl
			<< month << endl
			<< year << endl;
	}

	int TypeSearch(string SearchType, int i) {
		string sType = type;
		size_t pos = sType.find(SearchType);//size_t ������������� ��� �����, ��������� ������ ��������.
		if (pos != string::npos) {
			cout << "������ �����: " << i << endl;
			PrintItem();
			return 1;
		}
		else
			return 0;
	}

	int InfoSearch(string SearchInfo, int i) {
		string sInfo = info;
		size_t pos = sInfo.find(SearchInfo);//size_t ������������� ��� �����, ��������� ������ ��������.
		if (pos != string::npos) {
			cout << "������ �����: " << i << endl;
			PrintItem();
			return 1;
		}
		else
			return 0;
	}

	int CharactSearch(string SearchCharact, int i) {
		string sCharact = charact;
		size_t pos = sCharact.find(SearchCharact);//size_t ������������� ��� �����, ��������� ������ ��������.
		if (pos != string::npos) {
			cout << "������ �����: " << i << endl;
			PrintItem();
			return 1;
		}
		else
			return 0;
	}

	int NomerSearch(string SearchNomer, int i) {
		string sNomer;
		stringstream ss;
		ss << nomer;
		ss >> sNomer;
		size_t pos = sNomer.find(SearchNomer);//size_t ������������� ��� �����, ��������� ������ ��������.
		if (pos != string::npos) {
			cout << "������ �����: " << i << endl;
			PrintItem();
			return 1;
		}
		else
			return 0;
	}

	int CostSearch(string SearchCost, int i) {
		string sCost;
		stringstream ss;
		ss << cost;
		ss >> sCost;
		size_t pos = sCost.find(SearchCost);//size_t ������������� ��� �����, ��������� ������ ��������.
		if (pos != string::npos) {
			cout << "������ �����: " << i << endl;
			PrintItem();
			return 1;
		}
		else
			return 0;
	}
	
	void TypeFilter(char* FilterType) {
		if (!(strcmp(FilterType, type)))
			PrintItem();
	}

	void InfoFilter(char* FilterInfo) {
		if (!(strcmp(FilterInfo, info)))
			PrintItem();
	}

	void CharactFilter(char* FilterCharact) {
		if (!(strcmp(FilterCharact, charact)))
			PrintItem();
	}

	void NomerFilter(int FilterNomerMin, int FilterNomerMax) {
		if (nomer >= FilterNomerMin && nomer <= FilterNomerMax)
			PrintItem();
	}

	void CostFilter(int FilterCostMin, int FilterCostMax) {
		if (cost >= FilterCostMin && cost <= FilterCostMax)
			PrintItem();
	}

	int ReportSale(int ReportDay, int ReportMonth, int ReportYear) {
		if ((day == ReportDay) && (month == ReportMonth) && (year == ReportYear)) {
			PrintSoldItem();
			return cost;
		}
		return 0;
	}

};

extern vector <PRODUCT> item;

void MenuSave();

void MenuSaveSoldItem();

void MenuClear();

void MenuEdit();

void MenuOutput();

void MenuSearchItem();

void MenuSortItem();

void MenuFilterItem();

void MenuWorkWithData();

void MenuSellerService();

void MenuMain();
