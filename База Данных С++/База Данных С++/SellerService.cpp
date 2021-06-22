#include "SellerService.h"

vector <PRODUCT> solditem;//������ ��� ��������� �������.

void SellItem(){
	cout << "[������� ������]" << endl;
	cout << "������� ����� �������� ������� ������ ������� (�� ������ " << item.size() << ")?" << endl;
	int num;
	while (true) {//�������� �� ���������� ����
		cin >> num;
		if (!cin) {
			system("cls");
			cout << "������������ ����, ������� �����" << endl;
			cin.clear();
			while (getchar() != '\n');
		}
		else break;
	}
	if (num - 1 >= item.size()) {
		system("cls");
		cout << "�� ����� �� ������������ �����" << endl;
		system("pause");
		system("cls");
	}
	else {
		solditem.push_back(item.at(num - 1));
		solditem[solditem.size() - 1].InputDate();
		item.erase(item.begin() + num - 1);
		cout << "����� ����� " << num << " ������� ������." << endl;
		system("pause");
		system("cls");
	}
}

void OutputSoldItem() {
	cout << "[����� ��������� �������]" << endl;
	for (int i = 0; i < solditem.size(); i++) {
		cout << "����� �" << i + 1 << endl;
		solditem[i].PrintSoldItem();
	}

	system("pause");
	system("cls");
}

void PrintOneItem(){
	cout << "������� ����� ������(����� " << solditem.size() << "): " << endl;
	int num;
	while (true) {//�������� �� ���������� ����
		cin >> num;
		if (!cin) {
			system("cls");
			cout << "������������ ���� ������ ���������� ������, ������� �����: ";
			cin.clear();
			while (getchar() != '\n');
		}
		else break;
	}
	if (num - 1 >= solditem.size()) {
		system("cls");
		cout << "�� ����� �� ������������ �����" << endl;
	}
	else {
		system("cls");
		cout << "����� �" << num << endl;
		solditem[num - 1].PrintSoldItem();
	}

	system("pause");
	system("cls");
}

void OutputSoldItemTable() {

	cout << "					[����� ��������� �������]" << endl;
	cout << "_________________________________________________________________________________________________" << endl;
	cout << "|����� |���       |��������       |��������������      |�������� ����� |����      |���� ������� |" << endl;
	cout << "|______|__________|_______________|____________________|_______________|__________|_____________|" << endl;
		for (int i = 0; i < solditem.size(); i++) {
		cout << '|';
		int count = 0, j = i + 1;
		while ((j /= 10) > 0) count++;
		cout << i + 1;
		if (count < 4) {
			for (int i = 0; i < 5 - count; i++) {
				cout << ' ';
			}
		}
		cout << '|';
		solditem[i].PrintTableSoldItem();
	}
	cout << "|______|__________|_______________|____________________|_______________|__________|_____________|" << endl;
	system("pause");
	system("cls");
}

void SaveInNewFileSoldItem() {
	cout << "[���������� � ����]" << endl;
	cout << "�������� �������� ��� ������ �����(��� ����������)?" << endl;
	string FileName;
	cin >> FileName;
	ofstream fout(FileName+".txt");
	for (int i = 0; i < solditem.size(); i++) {
		solditem[i].SaveInFileSold(fout);
	}
	fout.close();
	cout << "���� ������� ������." << endl;
	system("pause");
	system("cls");
}

void SaveInFileSoldItem() {
	cout << "[���������� � ����]" << endl;
	cout << "�������� �������� �����(��� ����������):" << endl;
	string FileName;
	cin >> FileName;
	ofstream fout(FileName + ".txt", ios::app);
	if (!fout.is_open()) {
		cout << "������ �������� �����!" << endl;
	}
	else {
		for (int i = 0; i < solditem.size(); i++) {
			solditem[i].SaveInFileSold(fout);
		}
		cout << "������� ���������." << endl;
	}
	fout.close();
	system("pause");
	system("cls");
}

void LoadFromFileSoldItem() {
	cout << "[���������� � �����]" << endl;
	cout << "������� �������� � ���������� ����� � �������� ������ ������� ������" << endl
		<< "����� ������� ���������� ���� ������ ������� \"Solditem.txt\"" << endl;
	string FileName;
	cin >> FileName;
	ifstream fin(FileName);
	if (!fin.is_open()) {
		cout << "������ �������� �����!" << endl;
		system("pause");
		system("cls");
	}
	else {
		while (fin.good()) {
			solditem.push_back(PRODUCT(fin, "sold"));
		}

		if (fin.eof()) {
			cout << "������� �������!" << endl;
			solditem.pop_back();
			system("pause");
			system("cls");
		}
		else if (fin.fail()) {
			cout << "���������� � ����� �� �������� ��� ����������" << endl;
			solditem.clear();//������� �� ������
			system("pause");
			system("cls");
		}
		else {// ���� ��������� �� ����������� �������
			cout << "����������� ������" << endl;
			system("pause");
			system("cls");
		}
		fin.close();
	}
}

void ReportSales() {
	int DailyEarnings = 0;
	cout << "[����� � ��������]" << endl;
	int ReportDay, ReportMonth, ReportYear;
	cout << "������� ���� �������: " << endl;
	while (true) {//�������� �� ���������� ����
		cin >> ReportDay; //���� ���
		if (!cin) {
			cout << "������������ ���� ��� �������, ������� �����." << endl;
			cin.clear();
			while (getchar() != '\n');
		}
		else if (ReportDay <= 31 && ReportDay >= 1) {
			break;
		}
		else {
			cout << "������������ ���� ���." << endl;
		}
	}
	cout << "������� ����� �������:" << endl;
	while (true) {
		cin >> ReportMonth; //���� ������
		if (!cin) {
			cout << "������������ ���� ������ �������, ������� �����." << endl;
			cin.clear();
			while (getchar() != '\n');
		}
		else if (ReportMonth <= 12 && ReportMonth >= 1) {
			break;
		}
		else {
			cout << "������������ ���� ������." << endl;
		}
	}
	cout << "������� ��� �������(1900 - 2100 ��.): " << endl;
	while (true) {
		cin >> ReportYear; //���� ���
		if (!cin) {
			cout << "������������ ���� ���� ����, ������� �����." << endl;
			cin.clear();
			while (getchar() != '\n');
		}
		else if (ReportYear <= 2100 && ReportYear >= 1900) {
			break;
		}
		else {
			cout << "������������ ���� ����." << endl;
		}
	}

	system("cls");
	cout << "[����� � ��������]" << endl;
	for (int i = 0; i < solditem.size(); i++) {
		DailyEarnings += solditem[i].ReportSale(ReportDay, ReportMonth, ReportYear);
	}

	cout << "������� �� ���� ���������: " << DailyEarnings << '$' << endl;

	system("pause");
	system("cls");
}

