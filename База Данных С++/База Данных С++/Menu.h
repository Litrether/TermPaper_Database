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
	char type[11];   //Тип 
	char info[16];   //Описание
	char charact[21];//Характеристика
	int  nomer;      //Серийный номер
	int  cost;       //Цена
	int  day;        //День продажи
	int  month;      //Месяц продажи
	int  year;       //Год продажи

	PRODUCT() {
		string newString;

		while (getchar() != '\n');
		cout << "Введите тип: " << endl;
		while (true) {
			getline(cin, newString);
			if (newString.length() > 10) {
				cout << "Значение типа не может превышать 10 символов!" << endl;
			}
			else {
				for (int i = 0; i < newString.length(); i++) {
					type[i] = newString[i];
				}
				type[newString.length()] = '\0';
				break;
			}
		}
		cout << "Введите описание: " << endl;
		while (true) {
			getline(cin, newString);
			if (newString.length() > 15) {
				cout << "Значение описания не может превышать 15 символов!" << endl;
			}
			else {
				for (int i = 0; i < newString.length(); i++) {
					info[i] = newString[i];
				}
				info[newString.length()] = '\0';
				break;
			}
		}
		cout << "Введите характеристики: " << endl;
		while (true) {
			getline(cin, newString);
			if (newString.length() > 20) {
				cout << "Значение описания не может превышать 20 символов!" << endl;
			}
			else {
				for (int i = 0; i < newString.length(); i++) {
					charact[i] = newString[i];
				}
				charact[newString.length()] = '\0';
				break;
			}
		}
		cout << "Введите серийный номер: " << endl;
		while (true) {
			while (true) {//проверка на корректный ввод
				cin >> nomer; //Серийный номер
				if (!cin) {
					cout << "Некорректный ввод серийного номера, введите шестизначное число." << endl;
					cin.clear();
					while (getchar() != '\n');
				}
				else break;
			}
			if (nomer >= 100000 && nomer <= 999999)
				break;
			else
				cout << "Некорректный ввод серийного номера, введите шестизначное число." << endl;
		}
		cout << "Введите цену(В долларах): " << endl;
		while (true) {
			while (true) {
				cin >> cost; //Цена
				if (!cin) {
					cout << "Некорректный ввод цены, введите число не больше 10000$." << endl;
					cin.clear();
					while (getchar() != '\n');
				}
				else break;
			}
			if (cost > 10000) {
				cout << "Не правда! У нас нет настолько дорогих товаров(не больше 10000$)." << endl;
				cin.clear();
				while (getchar() != '\n');
			}
			else break;
		}
	}

	PRODUCT(ifstream& fin) {
		char ints[7];//Характеристика

		fin.getline(type, 11);
		fin.getline(info, 16);
		fin.getline(charact, 21);
		fin.getline(ints, 7);
		nomer = atoi(ints);
		fin.getline(ints, 7);
		cost = atoi(ints);
	}

	PRODUCT(ifstream& fin, string sold) {
		char ints[7];//Характеристика

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
		cout << "Введите день продажи: " << endl;
		while (true) {//проверка на корректный ввод
			cin >> day; //Ввод дня
			if (!cin) {
				cout << "Некорректный ввод дня продажи, введите число." << endl;
				cin.clear();
				while (getchar() != '\n');
			}
			else if (day <= 31 && day >= 1) {
				break;
			}
			else {
				cout << "Некорректный ввод дня." << endl;
			}
		}
		cout << "Введите месяц продажи:" << endl;
		while (true) {
			cin >> month; //Ввод месяца
			if (!cin) {
				cout << "Некорректный ввод месяца продажи, введите число." << endl;
				cin.clear();
				while (getchar() != '\n');
			}
			else if (month <= 12 && month >= 1) {
				break;
			}
			else {
				cout << "Некорректный ввод месяца." << endl;
			}
		}
		cout << "Введите год продажи(1900 - 2100 гг.) " << endl;
		while (true) {
			cin >> year; //Ввод год
			if (!cin) {
				cout << "Некорректный ввод года года, введите число." << endl;
				cin.clear();
				while (getchar() != '\n');
			}
			else if (year <= 2100 && year >= 1900) {
				break;
			}
			else {
				cout << "Некорректный ввод года." << endl;
			}
		}
	}

	void PrintItem() {
		cout << "Тип: " << type << endl
			<< "Описание: " << info << endl
			<< "Характеристика: " << charact << endl
			<< "Серийный номер: " << nomer << endl
			<< "Цена: " << cost << '$' << endl << endl;
		cout << "====================================" << endl;
	}

	void PrintSoldItem() {
		cout << "Тип: " << type << endl
			<< "Описание: " << info << endl
			<< "Характеристика: " << charact << endl
			<< "Серийный номер: " << nomer << endl
			<< "Цена: " << cost << '$' << endl
			<< "Дата продажи: ";
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
		cout << "Выберите часть объекта: " << endl;
		cout << "1. Редактировать тип" << endl;
		cout << "2. Редактировать описание" << endl;
		cout << "3. Редактировать характеристику" << endl;
		cout << "4. Редактировать серийный номер" << endl;
		cout << "5. Редактировать цену" << endl;
		cout << "9. Вернуться назад" << endl;
		cout << "Выберите функцию: " << endl;
		while (true) {//проверка на корректный ввод
			cin >> state;
			if (!cin) {
				system("cls");
				cout << "Выберите часть объекта: " << endl;
				cout << "1. Редактировать тип" << endl;
				cout << "2. Редактировать описание" << endl;
				cout << "3. Редактировать характеристику" << endl;
				cout << "4. Редактировать серийный номер" << endl;
				cout << "5. Редактировать цену" << endl;
				cout << "9. Вернуться назад" << endl;
				cout << "Выберите функцию: " << endl;
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
			cout << "Введите новый тип: " << endl;
			while (true) {
				getline(cin, newString);
				if (newString.length() > 10) {
					cout << "Значение типа не может превышать 10 символов!" << endl;
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
			cout << "Введите новое описание: " << endl;
			while (true) {
				getline(cin, newString);
				if (newString.length() > 15) {
					cout << "Значение описания не может превышать 15 символов!" << endl;
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
			cout << "Введите новые характеристики: " << endl;
			while (true) {
				getline(cin, newString);
				if (newString.length() > 20) {
					cout << "Значение описания не может превышать 20 символов!" << endl;
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
			cout << "Введите новый серийный номер: " << endl;
			while (true) {
				while (true) {//проверка на корректный ввод
					cin >> nomer; //Серийный номер
					if (!cin) {
						cout << "Некорректный ввод серийного номера, введите шестизначное число." << endl;
						cin.clear();
						while (getchar() != '\n');
					}
					else break;
				}
				if (nomer >= 100000 && nomer <= 999999)
					break;
				else
					cout << "Некорректный ввод серийного номера, введите шестизначное число." << endl;
			}
			break;
		}
		case 5: {
			cout << "Введите новую цену(В долларах): " << endl;
			while (true) {
				while (true) {
					cin >> cost; //Цена
					if (!cin) {
						cout << "Некорректный ввод цены, введите число не больше 10000$." << endl;
						cin.clear();
						while (getchar() != '\n');
					}
					else break;
				}
				if (cost > 10000) {
					cout << "Не правда! У нас нет настолько дорогих товаров(не больше 10000$)." << endl;
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
		cout << "Введите тип: " << endl;
		while (true) {
			getline(cin, newString);
			if (newString.length() > 10) {
				cout << "Значение типа не может превышать 10 символов!" << endl;
			}
			else {
				for (int i = 0; i < newString.length(); i++) {
					type[i] = newString[i];
				}
				type[newString.length()] = '\0';
				break;
			}
		}
		cout << "Введите описание: " << endl;
		while (true) {
			getline(cin, newString);
			if (newString.length() > 15) {
				cout << "Значение описания не может превышать 15 символов!" << endl;
			}
			else {
				for (int i = 0; i < newString.length(); i++) {
					info[i] = newString[i];
				}
				info[newString.length()] = '\0';
				break;
			}
		}
		cout << "Введите характеристики: " << endl;
		while (true) {
			getline(cin, newString);
			if (newString.length() > 20) {
				cout << "Значение описания не может превышать 20 символов!" << endl;
			}
			else {
				for (int i = 0; i < newString.length(); i++) {
					charact[i] = newString[i];
				}
				charact[newString.length()] = '\0';
				break;
			}
		}
		cout << "Введите серийный номер: " << endl;
		while (true) {
			while (true) {//проверка на корректный ввод
				cin >> nomer; //Серийный номер
				if (!cin) {
					cout << "Некорректный ввод серийного номера, введите шестизначное число." << endl;
					cin.clear();
					while (getchar() != '\n');
				}
				else break;
			}
			if (nomer >= 100000 && nomer <= 999999)
				break;
			else
				cout << "Некорректный ввод серийного номера, введите шестизначное число." << endl;
		}
		cout << "Введите цену(В долларах): " << endl;
		while (true) {
			while (true) {
				cin >> cost; //Цена
				if (!cin) {
					cout << "Некорректный ввод цены, введите число не больше 10000$." << endl;
					cin.clear();
					while (getchar() != '\n');
				}
				else break;
			}
			if (cost > 10000) {
				cout << "Не правда! У нас нет настолько дорогих товаров(не больше 10000$)." << endl;
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
		size_t pos = sType.find(SearchType);//size_t целочисленный без знака, указывает размер элемента.
		if (pos != string::npos) {
			cout << "Объект номер: " << i << endl;
			PrintItem();
			return 1;
		}
		else
			return 0;
	}

	int InfoSearch(string SearchInfo, int i) {
		string sInfo = info;
		size_t pos = sInfo.find(SearchInfo);//size_t целочисленный без знака, указывает размер элемента.
		if (pos != string::npos) {
			cout << "Объект номер: " << i << endl;
			PrintItem();
			return 1;
		}
		else
			return 0;
	}

	int CharactSearch(string SearchCharact, int i) {
		string sCharact = charact;
		size_t pos = sCharact.find(SearchCharact);//size_t целочисленный без знака, указывает размер элемента.
		if (pos != string::npos) {
			cout << "Объект номер: " << i << endl;
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
		size_t pos = sNomer.find(SearchNomer);//size_t целочисленный без знака, указывает размер элемента.
		if (pos != string::npos) {
			cout << "Объект номер: " << i << endl;
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
		size_t pos = sCost.find(SearchCost);//size_t целочисленный без знака, указывает размер элемента.
		if (pos != string::npos) {
			cout << "Объект номер: " << i << endl;
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
