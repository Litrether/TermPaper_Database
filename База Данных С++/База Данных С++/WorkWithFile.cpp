#include "Menu.h"
#include "WorkWithFile.h"

void SaveInFileNew() {
	cout << "Напишите название и расщирение для нового файла?" << endl;
	string FileName;
	cin >> FileName;
	ofstream fout(FileName);
	for (int i = 0; i < item.size(); i++) {
		item[i].SaveInFile(fout);
	}
	fout.close();
	cout << "Файл успешно создан." << endl;
	system("pause");
	system("cls");
}

void SaveInFile() {
	cout << "Напишите название и расширение файла:" << endl;
	string FileName;
	cin >> FileName;
	ofstream fout(FileName, ios::app);
	if (!fout.is_open()) {
		cout << "Ошибка открытия файла!" << endl;
	}
	else {
		for (int i = 0; i < item.size(); i++) {
			item[i].SaveInFile(fout);
		}
		cout << "Успешно сохранено." << endl;
	}

	fout.close();
	system("pause");
	system("cls");
}

void RemoveFile() {
	cout << "[Удаление файла]" << endl;
	cout << "Напишите название удаляемого файла" << endl;
	while (getchar() != '\n');
	char name[20];
	cin.getline(name, 20);
	if (remove(name) == 0) {
		cout << "Удаление прошло успешно" << endl;
	}
	else {
		cout << "Указаный файл не существует." << endl;
	}
	system("pause");
	system("cls");
}

void LoadFromFile() {
	cout << "[Считывание с файла]" << endl;
	cout << "Введите название и расширение файла с которого хотите считать объекты" << endl
		<< "Чтобы считать заполненную базу данных введите \"Database.txt\"" << endl;
	string FileName;
	cin >> FileName;
	ifstream fin(FileName);
	if (!fin.is_open()) {
		cout << "Ошибка открытия файла!" << endl;
		system("pause");
		system("cls");
	}
	else {
		while (fin.good()) {
			item.push_back(PRODUCT(fin));
		}

		if (fin.eof()) {
			cout << "Успешно считано!" << endl;
			item.pop_back();
			system("pause");
			system("cls");
		}
		else if (fin.fail()) {
			cout << "Информация в файле не подходит для заполнения" << endl;
			item.clear();//Очищаем от мусора
			system("pause");
			system("cls");
		}
		else {// Ввод прекращен по неизвестной причине
			cout << "Неизвестная ошибка" << endl;
			system("pause");
			system("cls");
		}
		fin.close();
	}
}