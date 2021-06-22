#include "Menu.h"
#include "Workio.h"

void InputInfo() { // ЗАПОЛНЕНИЕ СТРУКТУРЫ 
	cout << "=-=Заполнение структуры=-=" << endl;
	cout << "Сколько вы хотите добавить элементов?" << endl;
	int n;
	while (true) {//проверка на корректный ввод
		cin >> n;
		if (!cin) {
			system("cls");
			cout << "Некорректный ввод, введите число(0 - Выход): " << endl;
			cin.clear();
			while (getchar() != '\n');
		}
		else break;
	}
	for (int i = 0; i < n; i++) {
		cout << "Элемент номер: " << i + 1 << ", в общем списке: " << item.size() + 1 << endl;
		item.push_back(PRODUCT());
	}
	system("pause");
	system("cls");
}

void OutputItems() { //КЛАССИЧЕСКИЙ ВЫВОД СТРУКТУРЫ
	cout << "[Вывод структуры]" << endl;

	for (int i = 0; i < item.size(); i++) {
		cout << "Товар №" << i + 1 << endl;
		item[i].PrintItem();
	}

	system("pause");
	system("cls");
}

void OutputItemsTable() { //ТАБЛИЧНЫЙ ВЫВОД СТРУКТУР
	cout << "                       [Вывод структур в табличном виде]" << endl;
	cout << "___________________________________________________________________________________" << endl;
	cout << "|Номер |Тип       |Описание       |Характеристика      |Серийный номер |Цена      |" << endl;
	cout << "|______|__________|_______________|____________________|_______________|__________|" << endl;
	for (int i = 0; i < item.size(); i++) {
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
		item[i].PrintTableItem();
	}
	cout << "|______|__________|_______________|____________________|_______________|__________|" << endl;
	system("pause");
	system("cls");
}

void DeleteItem() {
	cout << "[Удаление объекта]" << endl;
	cout << "Введите номер объекта который хотите удалить (Всего на складе " << item.size() << "): " <<  endl;
	int num;
	while (true) {//проверка на корректный ввод
		cin >> num;
		if (!cin) {
			system("cls");
			cout << "Некорректный ввод номера объекта, введите число." << endl;
			cin.clear();
			while (getchar() != '\n');
		}
		else break;
	}
	if (num - 1 >= item.size()) {
		system("cls");
		cout << "Вы ввели не существующий номер" << endl;
	}
	else {
		system("cls");
		item.erase(item.begin() + num - 1);
		cout << "Объект номер " << num << " успешно удалён." << endl;
	}
	system("pause");
	system("cls");
}

void ClearItems() {
	item.clear();
	cout << "База данных в памяти успешно очищена." << endl;
	system("pause");
	system("cls");
}
