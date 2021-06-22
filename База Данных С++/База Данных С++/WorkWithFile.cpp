#include "Menu.h"
#include "WorkWithFile.h"

void SaveInFileNew() {
	cout << "�������� �������� � ���������� ��� ������ �����?" << endl;
	string FileName;
	cin >> FileName;
	ofstream fout(FileName);
	for (int i = 0; i < item.size(); i++) {
		item[i].SaveInFile(fout);
	}
	fout.close();
	cout << "���� ������� ������." << endl;
	system("pause");
	system("cls");
}

void SaveInFile() {
	cout << "�������� �������� � ���������� �����:" << endl;
	string FileName;
	cin >> FileName;
	ofstream fout(FileName, ios::app);
	if (!fout.is_open()) {
		cout << "������ �������� �����!" << endl;
	}
	else {
		for (int i = 0; i < item.size(); i++) {
			item[i].SaveInFile(fout);
		}
		cout << "������� ���������." << endl;
	}

	fout.close();
	system("pause");
	system("cls");
}

void RemoveFile() {
	cout << "[�������� �����]" << endl;
	cout << "�������� �������� ���������� �����" << endl;
	while (getchar() != '\n');
	char name[20];
	cin.getline(name, 20);
	if (remove(name) == 0) {
		cout << "�������� ������ �������" << endl;
	}
	else {
		cout << "�������� ���� �� ����������." << endl;
	}
	system("pause");
	system("cls");
}

void LoadFromFile() {
	cout << "[���������� � �����]" << endl;
	cout << "������� �������� � ���������� ����� � �������� ������ ������� �������" << endl
		<< "����� ������� ����������� ���� ������ ������� \"Database.txt\"" << endl;
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
			item.push_back(PRODUCT(fin));
		}

		if (fin.eof()) {
			cout << "������� �������!" << endl;
			item.pop_back();
			system("pause");
			system("cls");
		}
		else if (fin.fail()) {
			cout << "���������� � ����� �� �������� ��� ����������" << endl;
			item.clear();//������� �� ������
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