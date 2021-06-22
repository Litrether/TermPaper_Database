#include "WorkWithData.h"
#include "Menu.h"
#include <string>

bool CmpType(PRODUCT a, PRODUCT b) {
	string astr = a.type, bstr = b.type;
	return astr < bstr;
}

bool CmpInfo(PRODUCT a, PRODUCT b) {
	string astr = a.info, bstr = b.info;
	return astr < bstr;
}

bool CmpCharact(PRODUCT a, PRODUCT b) {
	string astr = a.charact, bstr = b.charact;
	return astr < bstr;
}

bool CmpNomer(PRODUCT a, PRODUCT b) {
	return a.nomer < b.nomer;
}

bool CmpCost(PRODUCT a, PRODUCT b) {
	return a.cost < b.cost;
}

void SortByType() {
	int state;
	cout << "[Сортировка по типу]" << endl;
	cout << "[1] С начала алфавита" << endl;
	cout << "[2] С конца алфавита" << endl;
	cout << "[9] Вернуться назад" << endl;
	cout << "Выберите функцию" << endl;
	while (true) {//проверка на корректный ввод
		cin >> state;
		if (!cin) {
			system("cls");
			cout << "[Сортировка по типу]" << endl;
			cout << "[1] С начала алфавита" << endl;
			cout << "[2] С конца алфавита" << endl;
			cout << "[9] Вернуться назад" << endl;
			cout << "Выберите функцию" << endl;
			cin.clear();
			while (getchar() != '\n');
		}
		else break;
	}
	system("cls");

	switch (state) {
	case 1: {
		sort(item.begin(), item.end(), CmpType);
		break;
	}
	case 2: {
		sort(item.begin(), item.end(), CmpType);
		reverse(item.begin(), item.end());
		break;
	}
	case 9: {
		system("cls");
		break;
	}
	default: {
		system("cls");
		break;
	}
	}
}

void SortByInfo() {
	int state;
	cout << "[Сортировка по описанию]" << endl;
	cout << "[1] С начала алфавита" << endl;
	cout << "[2] С конца алфавита" << endl;
	cout << "[9] Вернуться назад" << endl;


	while (true) {//проверка на корректный ввод
		cin >> state;
		if (!cin) {
			system("cls");
			cout << "[Сортировка по описанию]" << endl;
			cout << "1. С начала алфавита" << endl;
			cout << "2. С конца алфавита" << endl;
			cout << "9 Вернуться назад" << endl;
			cin.clear();
			while (getchar() != '\n');
		}
		else break;
	}
	system("cls");

	switch (state) {
	case 1: {
		sort(item.begin(), item.end(), CmpInfo);
		break;
	}
	case 2: {
		sort(item.begin(), item.end(), CmpInfo);
		reverse(item.begin(), item.end());
		break;
	}
	case 9: {
		system("cls");
		break;
	}
	default: {;
		system("cls");
		break;
	}
	}
}

void SortByCharact() {
	int state;
	cout << "[Сортировка по характеристикам]" << endl;
	cout << "[1] С начала алфавита" << endl;
	cout << "[2] С конца алфавита" << endl;
	cout << "[9] Вернуться назад" << endl;


	while (true) {//проверка на корректный ввод
		cin >> state;
		if (!cin) {
			system("cls");
			cout << "[Сортировка по характеристикам]" << endl;
			cout << "[1] С начала алфавита" << endl;
			cout << "[2] С конца алфавита" << endl;
			cout << "[9] Вернуться назад" << endl;
			cin.clear();
			while (getchar() != '\n');
		}
		else break;
	}
	system("cls");

	switch (state) {
	case 1: {
		sort(item.begin(), item.end(), CmpCharact);
		break;
	}
	case 2: {
		sort(item.begin(), item.end(), CmpCharact);
		reverse(item.begin(), item.end());
		break;
	}
	case 9: {
		system("cls");
		break;
	}
	default: {
		system("cls");
		break;
	}
	}
}

void SortByNomer() {
	int state;
	cout << "[Сортировка по серийному номеру]" << endl;
	cout << "[1] По возрастанию" << endl;
	cout << "[2] По убыванию" << endl;
	cout << "[9] Вернуться назад" << endl;


	while (true) {//проверка на корректный ввод
		cin >> state;
		if (!cin) {
			system("cls");
			cout << "[Сортировка по серийному номеру]" << endl;
			cout << "[1] По возрастанию" << endl;
			cout << "[2] По убыванию" << endl;
			cout << "[9] Вернуться назад" << endl;
			cin.clear();
			while (getchar() != '\n');
		}
		else break;
	}
	system("cls");

	switch (state) {
	case 1: {
		sort(item.begin(), item.end(), CmpNomer);
		break;
	}
	case 2: {
		sort(item.begin(), item.end(), CmpNomer);
		reverse(item.begin(), item.end());
		break;
	}
	case 9: {
		system("cls");
		break;
	}
	default: {
		system("cls");
		break;
	}
	}
}

void SortByCost() {
	int state;
	cout << "[Сортировка по цене]" << endl;
	cout << "[1] По возрастанию" << endl;
	cout << "[2] По убыванию" << endl;
	cout << "[9] Вернуться назад" << endl;


	while (true) {//проверка на корректный ввод
		cin >> state;
		if (!cin) {
			system("cls");
			cout << "[Сортировка по цене]" << endl;
			cout << "[1] По возрастанию" << endl;
			cout << "[2] По убыванию" << endl;
			cout << "[9] Вернуться назад" << endl;
			cin.clear();
			while (getchar() != '\n');
		}
		else break;
	}
	system("cls");

	switch (state) {
	case 1: {
		sort(item.begin(), item.end(), CmpCost);
		break;
	}
	case 2: {
		sort(item.begin(), item.end(), CmpCost);
		reverse(item.begin(), item.end());
		break;
	}
	case 9: {
		system("cls");
		break;
	}
	default: {
		system("cls");
		break;
	}
	}
}