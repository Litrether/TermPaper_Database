#include "Menu.h"
#include "Workio.h"
#include "WorkWithFile.h"

vector <PRODUCT> item;

void MenuSave() {
	int state = -1;
	while (state != 9) {
		cout << "[Сохранение данных]" << endl;
		cout << "[1] Сохранить в новый файл" << endl;
		cout << "[2] Добавить в существуюший файл" << endl;
		cout << "[9] Вернуться назад" << endl;
		cout << "Выберите функцию: " << endl;

		while (true) {//проверка на корректный ввод
			cin >> state;
			if (!cin) {
				system("cls");
				cout << "[Сохранение данных]" << endl;
				cout << "[1] Сохранить в новый файл" << endl;
				cout << "[2] Добавить в существуюший файл" << endl;
				cout << "[9] Вернуться назад" << endl;
				cout << "Выберите функцию: " << endl;
				cin.clear();
				while (getchar() != '\n');
			}
			else break;
		}
		system("cls");
		switch (state) {
		case 1: {
			SaveInFileNew();
			break;
		}
		case 2: {
			SaveInFile();
			break;
		}
		case 9: {
			state = 9;
			break;
		}
		default: {
			system("cls");
			break;
		}
		}
	}
}

void MenuSaveSoldItem() {
	int state = -1;
	while (state != 9) {
		cout << "[Сохранение данных о проданных товарах]" << endl;
		cout << "[1] Сохранить в новый файл" << endl;
		cout << "[2] Добавить в существуюший файл" << endl;
		cout << "[9] Вернуться назад" << endl;
		cout << "Выберите функцию: " << endl;

		while (true) {//проверка на корректный ввод
			cin >> state;
			if (!cin) {
				system("cls");
				cout << "[Сохранение данных о проданных товарах]" << endl;
				cout << "[1] Сохранить в новый файл" << endl;
				cout << "[2] Добавить в существуюший файл" << endl;
				cout << "[9] Вернуться назад" << endl;
				cout << "Выберите функцию: " << endl;
				cin.clear();
				while (getchar() != '\n');
			}
			else break;
		}
		system("cls");
		switch (state) {
		case 1: {
			SaveInNewFileSoldItem();
			break;
		}
		case 2: {
			SaveInFileSoldItem();
			break;
		}
		case 9: {
			state = 9;
			break;
		}
		default: 
			system("cls");
			break;
		}
		}
	
}

void MenuClear() {
	int state = -1;
	while (state != 9) {
		cout << "[Очистка]" << endl;
		cout << "[1] Удалить объект" << endl;
		cout << "[2] Очистить память" << endl;
		cout << "[3] Удалить файл" << endl;
		cout << "[4] Посмотреть весь список" << endl;
		cout << "[9] Вернуться назад" << endl;
		cout << "Выберите функцию: " << endl;

		while (true) {//проверка на корректный ввод
			cin >> state;
			if (!cin) {
				system("cls");
				cout << "[Очистка]" << endl;
				cout << "[1] Удалить объект" << endl;
				cout << "[2] Очистить память" << endl;
				cout << "[3] Удалить файл" << endl;
				cout << "[4] Посмотреть весь список" << endl;
				cout << "[9] Вернуться назад" << endl;
				cout << "Выберите функцию: " << endl;
				cin.clear();
				while (getchar() != '\n');
			}
			else break;
		}
		system("cls");

		switch (state) {
		case 1: {
			DeleteItem();
			break;
		}
		case 2: {
			ClearItems();
			break;
		}
		case 3: {
			RemoveFile();
			break;
		}
		case 4: {
			OutputItemsTable();
			system("cls");
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
}

void MenuEdit() {
	int state = -1;
	while (state != 9) {
		cout << "[Изменение объекта]" << endl;
		cout << "[1] Редактировать часть объекта" << endl;
		cout << "[2] Переписать полностью объект" << endl;
		cout << "[3] Показать весь список" << endl;
		cout << "[9] Вернуться назад" << endl;
		cout << "Выберите функцию: " << endl;
		while (true) {//проверка на корректный ввод
			cin >> state;
			if (!cin) {
				system("cls");
				cout << "[Изменение объекта]" << endl;
				cout << "[1] Редактировать часть объекта" << endl;
				cout << "[2] Переписать полностью объект" << endl;
				cout << "[3] Показать весь список" << endl;
				cout << "[9] Вернуться назад" << endl;
				cout << "Выберите функцию: " << endl;
				cin.clear();
				while (getchar() != '\n');
			}
			else break;
		}
		system("cls");
		switch (state) {
		case 1: {
			cout << "Введите номер товара(Всего " << item.size() << "): " << endl;
			int num;
			while (true) {//проверка на корректный ввод
				cout << "Товар номер: ";
				cin >> num;
				if (!cin) {
					system("cls");
					cout << "Некорректный ввод номера товара, введите число." << endl;
					cin.clear();
					while (getchar() != '\n');
				}
				else break;
			}

			if (num - 1 >= item.size()) {
				cout << "Вы ввели не существующий номер" << endl;
				system("pause");
				system("cls");
			}
			else {
				item[num - 1].PrintItem();
				item[num - 1].EditPart();
			}
			system("cls");
			break;
		}
		case 2: {
			cout << "Введите номер товара(Всего " << item.size() << "): " << endl;
			int num;
			while (true) {//проверка на корректный ввод
				cin >> num;
				if (!cin) {
					system("cls");
					cout << "Некорректный ввод номера товара, введите число." << endl;
					cin.clear();
					while (getchar() != '\n');
				}
				else break;
			}

			if (num - 1 >= item.size()) {
				cout << "Вы ввели не существующий номер" << endl;
				system("pause");
				system("cls");
			}
			else {
				item[num - 1].PrintItem();
				item[num - 1].EditFull();
			}
			system("cls");
			break;
		}
		case 3: {
			OutputItemsTable();
			system("cls");
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
}

void MenuOutput() {
	int state = -1;
	while (state != 9) {
		cout << "[Вывод данных]" << endl;
		cout << "[1] Вывод струтуры" << endl;
		cout << "[2] Вывод струтуры в табличном виде" << endl;
		cout << "[3] Вывод товара по номеру" << endl;
		cout << "[9] Вернуться назад" << endl;
		cout << "Выберите функцию: " << endl;

		while (true) {//проверка на корректный ввод
			cin >> state;
			if (!cin) {
				system("cls");
				cout << "[Вывод данных]" << endl;
				cout << "[1] Вывод струтуры" << endl;
				cout << "[2] Вывод струтуры в табличном виде" << endl;
				cout << "[3] Вывод товара по номеру" << endl;
				cout << "[9] Вернуться назад" << endl;
				cout << "Выберите функцию: " << endl;
				cin.clear();
				while (getchar() != '\n');
			}
			else break;
		}
		system("cls");
		switch (state) {
		case 1: {
			OutputItems();
			break;
		}
		case 2: {
			OutputItemsTable();
			break;
		}
		case 3: {
			cout << "Введите номер товара(Всего " << item.size() << "): " << endl;
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
			if (num - 1 >= item.size()) {
				system("cls");
				cout << "Вы ввели не существующий номер" << endl;
			}
			else {
				system("cls");
				cout << "Товар №" << num << endl;
				item[num - 1].PrintItem();
			}

			system("pause");
			system("cls");
			break;
		}
		case 9: {
			state = 9;
			break;
		}
		default: {
			system("cls");
			break;
		}
		}
	}
}

void MenuOutputSold() {
	int state = -1;
	while (state != 9) {
		cout << "[Вывод проданных товаров]" << endl;
		cout << "[1] Вывод данных" << endl;
		cout << "[2] Вывод данных в табличном виде" << endl;
		cout << "[3] Вывод товара по номеру" << endl;
		cout << "[9] Вернуться назад" << endl;
		cout << "Выберите функцию: " << endl;

		while (true) {//проверка на корректный ввод
			cin >> state;
			if (!cin) {
				system("cls");
				cout << "[Вывод проданных товаров]" << endl;
				cout << "[1] Вывод данных" << endl;
				cout << "[2] Вывод данных в табличном виде" << endl;
				cout << "[3] Вывод товара по номеру" << endl;
				cout << "[9] Вернуться назад" << endl;
				cout << "Выберите функцию: " << endl;
				cin.clear();
				while (getchar() != '\n');
			}
			else break;
		}
		system("cls");
		switch (state) {
		case 1: {
			OutputSoldItem();
			break;
		}
		case 2: {
			OutputSoldItemTable();
			break;
		}
		case 3: {
			PrintOneItem();
		}
		case 9: {
			state = 9;
			break;
		}
		default: {
			system("cls");
			break;
		}
		}
	}
}

void MenuSearchItem() {
	int state;
	cout << "[Поиск по полю]" << endl;
	cout << "По какому полю вы будете искать?" << endl;
	cout << "[1] Поиск по типу" << endl;
	cout << "[2] Поиск по описанию" << endl;
	cout << "[3] Поиск по характеристикам" << endl;
	cout << "[4] Поиск по серийному номеру" << endl;
	cout << "[5] Поиск по цене" << endl;
	cout << "[9] Вернуться назад" << endl;
	cout << "Выберите функцию: " << endl;
	while (true) {//проверка на корректный ввод
		cin >> state;
		if (!cin) {
			system("cls");
			cout << "[Поиск по полю]" << endl;
			cout << "По какому полю вы будете искать?" << endl;
			cout << "[1] Поиск по типу" << endl;
			cout << "[2] Поиск по описанию" << endl;
			cout << "[3] Поиск по характеристикам" << endl;
			cout << "[4] Поиск по серийному номеру" << endl;
			cout << "[5] Поиск по цене" << endl;
			cout << "[9] Вернуться назад" << endl;
			cout << "Выберите функцию: " << endl;
			cin.clear();
			while (getchar() != '\n');
		}
		else break;
	}
	system("cls");

	switch (state) {

	case 1: {
		int k = 0;
		string SearchType;

		cout << "[Поиск по типу]" << endl;
		cout << "Введите слова для поиска" << endl;

		while (getchar() != '\n');
		while (true) {
			getline(cin, SearchType);
			if (SearchType.length() > 10) {
				cout << "Длина слова не может превышать 10 символов!" << endl;
			}
			else {
				break;
			}
		}

		for (int i = 0; i < item.size(); i++) {
			k += item[i].TypeSearch(SearchType, i + 1);
		}
		if (k == 0) {
			cout << "По вашему запросу ничего не найдено." << endl;
		}

		system("pause");
		system("cls");
		break;
	}

	case 2: {
		cout << "[Поиск по описанию]" << endl;
		cout << "Введите слова для поиска" << endl;
		int k = 0;
		string SearchInfo;

		while (getchar() != '\n');
		while (true) {
			getline(cin, SearchInfo);
			if (SearchInfo.length() > 15) {
				cout << "Значение описания не может превышать 15 символов!" << endl;
			}
			else {
				break;
			}
		}

		for (int i = 0; i < item.size(); i++) {
			k += item[i].InfoSearch(SearchInfo, i + 1);
		}
		if (k == 0) {
			cout << "По вашему запросу ничего не найдено." << endl;
		}
		system("pause");
		system("cls");
		break;
	}

	case 3: {
		cout << "[Поиск по характеристикам]" << endl;
		cout << "Введите характеристику" << endl;
		int k = 0;
		string SearchCharact;

		while (getchar() != '\n');
		while (true) {
			getline(cin, SearchCharact);
			if (SearchCharact.length() > 20) {
				cout << "Значение описания не может превышать 20 символов!" << endl;
			}
			else {
				break;
			}
		}
		for (int i = 0; i < item.size(); i++) {
			k += item[i].CharactSearch(SearchCharact, i + 1);
		}
		if (k == 0) {
			cout << "По вашему запросу ничего не найдено." << endl;
		}
		system("pause");
		system("cls");
		break;
	}

	case 4: {
		cout << "[Поиск по серийному номеру]" << endl;
		cout << "Введите число для поиска" << endl;
		int k = 0;
		string SearchNomer;
		while (getchar() != '\n');
		while (true) {
			getline(cin, SearchNomer);
			if (SearchNomer.length() > 6) {
				cout << "Значение числа не может превышать 6 символов!" << endl;
			}
			else {
				break;
			}
		}
		for (int i = 0; i < item.size(); i++) {
			k += item[i].NomerSearch(SearchNomer, i + 1);
		}
		if (k == 0) {
			cout << "По вашему запросу ничего не найдено." << endl;
		}
		system("pause");
		system("cls");

		break;
	}

	case 5: {
		cout << "[Поиск по цене]" << endl;
		cout << "Введите число для поиска" << endl;
		int k = 0;
		string SearchCost;
		while (getchar() != '\n');
		while (true) {
			getline(cin, SearchCost);
			if (SearchCost.length() > 20) {
				cout << "Значение цены не может превышать 10000!" << endl;
			}
			else {
				break;
			}
		}
		for (int i = 0; i < item.size(); i++) {
			k += item[i].CostSearch(SearchCost, i + 1);
		}
		if (k == 0) {
			cout << "По вашему запросу ничего не найдено." << endl;
		}
		system("pause");
		system("cls");
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

void MenuSortItem() {
	int state;
	cout << "[Сортировка по полю]" << endl;
	cout << "По какому полю вы будете сортировать?" << endl;
	cout << "[1] Сортировка по типу" << endl;
	cout << "[2] Сортировка по описанию" << endl;
	cout << "[3] Сортировка по характеристикам" << endl;
	cout << "[4] Сортировка по серийному номеру" << endl;
	cout << "[5] Сортировка по цене" << endl;
	cout << "[9] Вернуться назад" << endl;
	cout << "Выберите функцию: " << endl;
	while (true) {//проверка на корректный ввод
		cin >> state;
		if (!cin) {
			system("cls");
			cout << "[Сортировка по полю]" << endl;
			cout << "По какому полю вы будете сортировать?" << endl;
			cout << "[1] Сортировка по типу" << endl;
			cout << "[2] Сортировка по описанию" << endl;
			cout << "[3] Сортировка по характеристикам" << endl;
			cout << "[4] Сортировка по серийному номеру" << endl;
			cout << "[5] Сортировка по цене" << endl;
			cout << "[9] Вернуться назад" << endl;
			cout << "Выберите функцию: " << endl;;
			cin.clear();
			while (getchar() != '\n');
		}
		else break;
	}
	system("cls");

	switch (state) {
	case 1: {
		SortByType();
		cout << "Сортировка прошла успешно" << endl;
		system("pause");
		system("cls");
		break;
	}
	case 2: {
		SortByInfo();
		cout << "Сортировка прошла успешно" << endl;
		system("pause");
		system("cls");
		break;
	}
	case 3: {
		SortByCharact();
		cout << "Сортировка прошла успешно" << endl;
		system("pause");
		system("cls");
		break;
	}
	case 4: {
		SortByNomer();
		cout << "Сортировка прошла успешно" << endl;
		system("pause");
		system("cls");
		break;
	}
	case 5: {
		SortByCost();
		cout << "Сортировка прошла успешно" << endl;
		system("pause");
		system("cls");
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

void MenuFilterItem() {
	int state;
	cout << "[Фильтрация по полю]" << endl;
	cout << "По какому полю вы будете фильтровать?" << endl;
	cout << "[1] Фильтрация по типу" << endl;
	cout << "[2] Фильтрация по описанию" << endl;
	cout << "[3] Фильтрация по характеристикам" << endl;
	cout << "[4] Фильтрация по серийному номеру" << endl;
	cout << "[5] Фильтрация по цене" << endl;
	cout << "[9] Вернуться назад" << endl;
	cout << "Выберите функцию: " << endl;
	while (true) {//проверка на корректный ввод
		cin >> state;
		if (!cin) {
			system("cls");
			cout << "[Фильтрация по полю]" << endl;
			cout << "По какому полю вы будете фильтровать?" << endl;
			cout << "[1] Фильтрация по типу" << endl;
			cout << "[2] Фильтрация по описанию" << endl;
			cout << "[3] Фильтрация по характеристикам" << endl;
			cout << "[4] Фильтрация по серийному номеру" << endl;
			cout << "[5] Фильтрация по цене" << endl;
			cout << "[9] Вернуться назад" << endl;
			cout << "Выберите функцию: " << endl;
			cin.clear();
			while (getchar() != '\n');
		}
		else break;
	}
	system("cls");

	switch (state) {
	case 1: {
		cout << "[Фильтрация по типу]" << endl;
		cout << "Введите тип" << endl;
		char FilterType[11];
		while (getchar() != '\n');
		cin.getline(FilterType, 11);
		for (int i = 0; i < item.size(); i++) {
			item[i].TypeFilter(FilterType);
		}
		system("pause");
		system("cls");
		break;
	}
	case 2: {
		cout << "[Фильтрация по описанию]" << endl;
		cout << "Введите описание" << endl;
		char FilterInfo[16];
		while (getchar() != '\n');
		cin.getline(FilterInfo, 16);
		for (int i = 0; i < item.size(); i++) {
			item[i].InfoFilter(FilterInfo);
		}
		system("pause");
		system("cls");
		break;
	}
	case 3: {
		cout << "[Фильтрация по характеристикам]" << endl;
		cout << "Введите характеристику" << endl;
		char FilterCharact[21];
		while (getchar() != '\n');
		cin.getline(FilterCharact, 21);
		for (int i = 0; i < item.size(); i++) {
			item[i].CharactFilter(FilterCharact);
		}
		system("pause");
		system("cls");
		break;
	}
	case 4: {
		cout << "[Фильтрация по серийному номеру]" << endl;
		cout << "Введите минимальное значение серийного номера:" << endl;
		int FilterNomerMin;
		while (true) {//проверка на корректный ввод
			cin >> FilterNomerMin;
			if (!cin) {
				system("cls");
				cout << "Некорректный ввод минимального значения серийного номера, введите число." << endl;
				cin.clear();
				while (getchar() != '\n');
			}
			else break;
		}

		cout << "Введите максимальное значение серийного номера:" << endl;
		int FilterNomerMax;
		while (true) {//проверка на корректный ввод
			cin >> FilterNomerMax;
			if (!cin) {
				system("cls");
				cout << "Некорректный ввод максимальное значения серийного номера, введите число." << endl;
				cin.clear();
				while (getchar() != '\n');
			}
			else break;
		}

		for (int i = 0; i < item.size(); i++) {
			item[i].NomerFilter(FilterNomerMin, FilterNomerMax);
		}
		system("pause");
		system("cls");

		break;
	}
	case 5: {
		cout << "[Фильтрация по цене]" << endl;
		cout << "Введите минимальное значение цены:" << endl;

		int FilterCostMin;
		while (true) {//проверка на корректный ввод
			cin >> FilterCostMin;
			if (!cin) {
				system("cls");
				cout << "Некорректный ввод минимального значения цены, введите число." << endl;
				cin.clear();
				while (getchar() != '\n');
			}
			else break;
		}

		cout << "Введите максимальное значение цены:" << endl;
		int FilterCostMax;
		while (true) {//проверка на корректный ввод
			cin >> FilterCostMax;
			if (!cin) {
				system("cls");
				cout << "Некорректный ввод максимальное значения цены, введите число." << endl;
				cin.clear();
				while (getchar() != '\n');
			}
			else break;
		}

		for (int i = 0; i < item.size(); i++) {
			item[i].CostFilter(FilterCostMin, FilterCostMax);
		}
		system("pause");
		system("cls");

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

void MenuWorkWithData() {
	int state = -1;
	while (state != 9) {
		cout << "[Работа с данными]" << endl;
		cout << "[1] Поиск по полю" << endl;
		cout << "[2] Сортировка по полю" << endl;
		cout << "[3] Фильтрация по полю" << endl;
		cout << "[4] Посмотреть весь список" << endl;
		cout << "[9] Вернуться назад" << endl;
		cout << "Выберите функцию: " << endl;

		while (true) {//проверка на корректный ввод
			cin >> state;
			if (!cin) {
				system("cls");
				cout << "[Работа с данными]" << endl;
				cout << "[1] Поиск по полю" << endl;
				cout << "[2] Сортировка по полю" << endl;
				cout << "[3] Фильтрация по полю" << endl;
				cout << "[4] Посмотреть весь список" << endl;
				cout << "[9] Вернуться назад" << endl;
				cout << "Выберите функцию: " << endl;
				cin.clear();
				while (getchar() != '\n');
			}
			else break;
		}
		system("cls");

		switch (state) {
		case 1: {
			MenuSearchItem();
			break;
		}
		case 2: {
			MenuSortItem();
			break;
		}
		case 3: {
			MenuFilterItem();
			break;
		}
		case 4: {
			OutputItemsTable();
			system("cls");
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
}

void MenuSellerService() {
	int state = -1;
	while (state != 9) {
		cout << "[Сервис продажи]" << endl;
		cout << "[1] Продать комплектующее" << endl;
		cout << "[2] Вывести список проданных товаров" << endl;
		cout << "[3] Сохранить в файл" << endl;
		cout << "[4] Считать список из файла" << endl;
		cout << "[5] Удалить файл со списком" << endl;
		cout << "[6] Отчет о продажах за определенный день" << endl;
		cout << "[9] Вернуться назад" << endl;
		cout << "Выберите функцию: " << endl;

		while (true) {//проверка на корректный ввод
			cin >> state;
			if (!cin) {
				system("cls");
				cout << "[Сервис продажи]" << endl;
				cout << "[1] Продать комплектующее" << endl;
				cout << "[2] Вывести список проданных товаров" << endl;
				cout << "[4] Сохранить список в новый файл" << endl;
				cout << "[5] Сохранить список в существующий файл" << endl;
				cout << "[6] Считать список из файла" << endl;
				cout << "[7] Удалить файл со списком" << endl;
				cout << "[8] Отчет о продажах за определенный день" << endl;
				cout << "[9] Вернуться назад" << endl;
				cout << "Выберите функцию: " << endl;
				cin.clear();
				while (getchar() != '\n');
			}
			else break;
		}
		system("cls");

		switch (state) {
		case 1: {
			SellItem();
			break;
		}
		case 2: {
			MenuOutputSold();
			break;
		}
		case 3: {
			MenuSaveSoldItem();
			break;
		}
		case 4: {
			LoadFromFileSoldItem();
			break;
		}
		case 5: {
			RemoveFile();
			break;
		}
		case 6: {
			ReportSales();
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
}

void MenuMain() {
	int state = -1;
	while (true) {
		cout << "[Главное меню]" << endl;
		cout << "[1] Добавить элементы" << endl;
		cout << "[2] Вывести данные" << endl;
		cout << "[3] Редактировать данные" << endl;
		cout << "[4] Удалить" << endl;
		cout << "[5] Сохранить в файл" << endl;
		cout << "[6] Обработка данных" << endl;
		cout << "[7] Сервис продажи" << endl;
		cout << "[8] Справка" << endl;
		cout << "[0] Выход" << endl;
		cout << "Выберите функцию: " << endl;
		while (true) {//проверка на корректный ввод
			cin >> state;
			if (!cin) {
				system("cls");
				cout << "[Главное меню]" << endl;
				cout << "[1] Добавить элементы" << endl;
				cout << "[2] Вывести данные" << endl;
				cout << "[3] Редактировать данные" << endl;
				cout << "[4] Удалить" << endl;
				cout << "[5] Сохранить в файл" << endl;
				cout << "[6] Обработка данных" << endl;
				cout << "[7] Сервис продажи" << endl;
				cout << "[8] Справка" << endl;
				cout << "[0] Выход" << endl;
				cout << "Выберите функцию: " << endl;
				cin.clear();
				while (getchar() != '\n');
			}
			else break;
		}
		system("cls");

		switch (state) {
		case 1: 
		{
			int state;
			cout << "[Добавление элементов]" << endl;
			cout << "[1] Ввести элементы" << endl;
			cout << "[2] Считывание данных из файла" << endl;
			cout << "[9] Вернуться назад" << endl;


			while (true) {//проверка на корректный ввод
				cin >> state;
				if (!cin) {
					system("cls");
					cout << "[Добавление элементов]" << endl;
					cout << "[1] Ввести элементы" << endl;
					cout << "[2] Считывание данных из файла" << endl;
					cout << "[9] Вернуться назад" << endl;
					cin.clear();
					while (getchar() != '\n');
				}
				else break;
			}
			system("cls");

			switch (state) {
			case 1: {
				InputInfo();
				break;
			}
			case 2: {
				LoadFromFile();
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
			break;
		}
		case 2:
		{
			MenuOutput();
			break;
		}
		case 3:
		{
			MenuEdit();
			break;
		}
		case 4:
		{
			MenuClear();
			break;
		}
		case 5:
		{
			MenuSave();
			break;
		}
		case 6:
		{
			MenuWorkWithData();
			break;
		}
		case 7:
		{
			MenuSellerService();
			break;
		}
		case 8: {
			cout << "[Справка]" << endl
				<< "  База данных создана для хранения, обработки и удобного обращения с информацией о комплектующих товарах на складе." << endl
				<< "  В этой базе данных есть такие функции как: считывание информации с клавиатуры, считывание информации с документа," << endl
				<< "удаление объектов,  очищение динамической  памяти,  редактирование элементов,  вывод информации, вывод информации в  " << endl
				<< "табличном виде,  запись информации в новый документ, добавление информации в существующий документ,  удаление доку-" << endl
				<< "мента, сортировка по полю, поиск по полю и фильтрация по полю." << endl
				<< "  Так же в базе данных присутствует сервис продаж в котором можно продавать товар. Так же при необходимости можно  " << endl
				<< "посмотреть список всех проданных товаров за определённую дату." << endl;

			_getch();
			system("cls");
			break;
		}
		case 0:
		{
			exit(0);
		}
		default: {
			system("cls");
			break;
		}
		}
	}
}