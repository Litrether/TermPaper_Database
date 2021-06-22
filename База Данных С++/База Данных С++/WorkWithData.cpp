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
	cout << "[���������� �� ����]" << endl;
	cout << "[1] � ������ ��������" << endl;
	cout << "[2] � ����� ��������" << endl;
	cout << "[9] ��������� �����" << endl;
	cout << "�������� �������" << endl;
	while (true) {//�������� �� ���������� ����
		cin >> state;
		if (!cin) {
			system("cls");
			cout << "[���������� �� ����]" << endl;
			cout << "[1] � ������ ��������" << endl;
			cout << "[2] � ����� ��������" << endl;
			cout << "[9] ��������� �����" << endl;
			cout << "�������� �������" << endl;
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
	cout << "[���������� �� ��������]" << endl;
	cout << "[1] � ������ ��������" << endl;
	cout << "[2] � ����� ��������" << endl;
	cout << "[9] ��������� �����" << endl;


	while (true) {//�������� �� ���������� ����
		cin >> state;
		if (!cin) {
			system("cls");
			cout << "[���������� �� ��������]" << endl;
			cout << "1. � ������ ��������" << endl;
			cout << "2. � ����� ��������" << endl;
			cout << "9 ��������� �����" << endl;
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
	cout << "[���������� �� ���������������]" << endl;
	cout << "[1] � ������ ��������" << endl;
	cout << "[2] � ����� ��������" << endl;
	cout << "[9] ��������� �����" << endl;


	while (true) {//�������� �� ���������� ����
		cin >> state;
		if (!cin) {
			system("cls");
			cout << "[���������� �� ���������������]" << endl;
			cout << "[1] � ������ ��������" << endl;
			cout << "[2] � ����� ��������" << endl;
			cout << "[9] ��������� �����" << endl;
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
	cout << "[���������� �� ��������� ������]" << endl;
	cout << "[1] �� �����������" << endl;
	cout << "[2] �� ��������" << endl;
	cout << "[9] ��������� �����" << endl;


	while (true) {//�������� �� ���������� ����
		cin >> state;
		if (!cin) {
			system("cls");
			cout << "[���������� �� ��������� ������]" << endl;
			cout << "[1] �� �����������" << endl;
			cout << "[2] �� ��������" << endl;
			cout << "[9] ��������� �����" << endl;
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
	cout << "[���������� �� ����]" << endl;
	cout << "[1] �� �����������" << endl;
	cout << "[2] �� ��������" << endl;
	cout << "[9] ��������� �����" << endl;


	while (true) {//�������� �� ���������� ����
		cin >> state;
		if (!cin) {
			system("cls");
			cout << "[���������� �� ����]" << endl;
			cout << "[1] �� �����������" << endl;
			cout << "[2] �� ��������" << endl;
			cout << "[9] ��������� �����" << endl;
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