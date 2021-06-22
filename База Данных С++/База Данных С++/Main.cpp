#include "Menu.h"
#include <clocale>
#include <Windows.h>


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_CTYPE, "rus");
	
	MenuMain();

	return 0;
}