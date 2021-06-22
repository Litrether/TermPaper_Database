#include "SellerService.h"

vector <PRODUCT> solditem;//Вектор для проданных товаров.

void SellItem(){
	cout << "[Продажа товара]" << endl;
	cout << "Введите номер предмета который хотите продать (На складе " << item.size() << ")?" << endl;
	int num;
	while (true) {//проверка на корректный ввод
		cin >> num;
		if (!cin) {
			system("cls");
			cout << "Некорректный ввод, введите число" << endl;
			cin.clear();
			while (getchar() != '\n');
		}
		else break;
	}
	if (num - 1 >= item.size()) {
		system("cls");
		cout << "Вы ввели не существующий номер" << endl;
		system("pause");
		system("cls");
	}
	else {
		solditem.push_back(item.at(num - 1));
		solditem[solditem.size() - 1].InputDate();
		item.erase(item.begin() + num - 1);
		cout << "Товар номер " << num << " успешно продан." << endl;
		system("pause");
		system("cls");
	}
}

void OutputSoldItem() {
	cout << "[Вывод проданных товаров]" << endl;
	for (int i = 0; i < solditem.size(); i++) {
		cout << "Товар №" << i + 1 << endl;
		solditem[i].PrintSoldItem();
	}

	system("pause");
	system("cls");
}

void PrintOneItem(){
	cout << "Введите номер товара(Всего " << solditem.size() << "): " << endl;
	int num;
	while (true) {//проверка на корректный ввод
		cin >> num;
		if (!cin) {
			system("cls");
			cout << "Некорректный ввод номера выводимого товара, введите число: ";
			cin.clear();
			while (getchar() != '\n');
		}
		else break;
	}
	if (num - 1 >= solditem.size()) {
		system("cls");
		cout << "Вы ввели не существующий номер" << endl;
	}
	else {
		system("cls");
		cout << "Товар №" << num << endl;
		solditem[num - 1].PrintSoldItem();
	}

	system("pause");
	system("cls");
}

void OutputSoldItemTable() {

	cout << "					[Вывод проданных товаров]" << endl;
	cout << "_________________________________________________________________________________________________" << endl;
	cout << "|Номер |Тип       |Описание       |Характеристика      |Серийный номер |Цена      |Дата Продажи |" << endl;
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
	cout << "[Сохранение в файл]" << endl;
	cout << "Напишите название для нового файла(Без расширения)?" << endl;
	string FileName;
	cin >> FileName;
	ofstream fout(FileName+".txt");
	for (int i = 0; i < solditem.size(); i++) {
		solditem[i].SaveInFileSold(fout);
	}
	fout.close();
	cout << "Файл успешно создан." << endl;
	system("pause");
	system("cls");
}

void SaveInFileSoldItem() {
	cout << "[Сохранение в файл]" << endl;
	cout << "Напишите название файла(Без расширения):" << endl;
	string FileName;
	cin >> FileName;
	ofstream fout(FileName + ".txt", ios::app);
	if (!fout.is_open()) {
		cout << "Ошибка открытия файла!" << endl;
	}
	else {
		for (int i = 0; i < solditem.size(); i++) {
			solditem[i].SaveInFileSold(fout);
		}
		cout << "Успешно сохранено." << endl;
	}
	fout.close();
	system("pause");
	system("cls");
}

void LoadFromFileSoldItem() {
	cout << "[Считывание с файла]" << endl;
	cout << "Введите название и расширение файла с которого хотите считать данные" << endl
		<< "Чтобы считать заполненую базу данных введите \"Solditem.txt\"" << endl;
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
			solditem.push_back(PRODUCT(fin, "sold"));
		}

		if (fin.eof()) {
			cout << "Успешно считано!" << endl;
			solditem.pop_back();
			system("pause");
			system("cls");
		}
		else if (fin.fail()) {
			cout << "Информация в файле не подходит для заполнения" << endl;
			solditem.clear();//Очищаем от мусора
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

void ReportSales() {
	int DailyEarnings = 0;
	cout << "[Отчет о продажах]" << endl;
	int ReportDay, ReportMonth, ReportYear;
	cout << "Введите день продажи: " << endl;
	while (true) {//проверка на корректный ввод
		cin >> ReportDay; //Ввод дня
		if (!cin) {
			cout << "Некорректный ввод дня продажи, введите число." << endl;
			cin.clear();
			while (getchar() != '\n');
		}
		else if (ReportDay <= 31 && ReportDay >= 1) {
			break;
		}
		else {
			cout << "Некорректный ввод дня." << endl;
		}
	}
	cout << "Введите месяц продажи:" << endl;
	while (true) {
		cin >> ReportMonth; //Ввод месяца
		if (!cin) {
			cout << "Некорректный ввод месяца продажи, введите число." << endl;
			cin.clear();
			while (getchar() != '\n');
		}
		else if (ReportMonth <= 12 && ReportMonth >= 1) {
			break;
		}
		else {
			cout << "Некорректный ввод месяца." << endl;
		}
	}
	cout << "Введите год продажи(1900 - 2100 гг.): " << endl;
	while (true) {
		cin >> ReportYear; //Ввод год
		if (!cin) {
			cout << "Некорректный ввод года года, введите число." << endl;
			cin.clear();
			while (getchar() != '\n');
		}
		else if (ReportYear <= 2100 && ReportYear >= 1900) {
			break;
		}
		else {
			cout << "Некорректный ввод года." << endl;
		}
	}

	system("cls");
	cout << "[Отчет о продажах]" << endl;
	for (int i = 0; i < solditem.size(); i++) {
		DailyEarnings += solditem[i].ReportSale(ReportDay, ReportMonth, ReportYear);
	}

	cout << "Выручка за день составила: " << DailyEarnings << '$' << endl;

	system("pause");
	system("cls");
}

