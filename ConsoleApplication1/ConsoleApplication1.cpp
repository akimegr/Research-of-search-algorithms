#include <iostream>

using namespace std;

void inicMas(int* mas, int size) {
	
	srand(time(0));
	int m = sizeof(mas);

	for (int i = 0; i < size; i++) {
		mas[i] = rand() % 100 - rand() % 100;
	}

}

void printMas(int* mas, int size) {
	for (int i = 0; i < size; i++) {
		cout << mas[i] << endl;
	}
}

void sort(int* mas, int size) {
	int swaps = 0;
	int eq = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size-1; j++) {
			if (mas[j] > mas[j + 1])
			{
				int temp = mas[j];
				mas[j] = mas[j + 1];
				mas[j + 1] = temp;
				swaps++;
			}
			eq++;
		}
	}
	cout << "Меняем: "  << swaps<< endl;
	cout << "Сравниваем: " << eq<< endl;

}

void searchLine(int *mas, int size) {
	cout << "Введите искомое значение: " << endl;
	int s;
	cin >> s;
	bool check = true;
	int eq = 0;
	for (int i = 0; i < size; i++) {
		eq++;
		if (s == mas[i])
		{
			check = false;
			break;
		}
	}
	cout << "Сравнений в поиске линейном: " << eq << endl;
	if (check)
		cout << "Элемент не найден" << endl;
	else
		cout << "Число " << s << " найдено" << endl;
}

void binsearch(int* mas, int size) {
	int left = 0;
	int right = size-1;
	int mid;
	cout << "Введите искомое значение: " << endl;
	int s;
	cin >> s;
	bool check = true;
	int eq = 0;
	while (left <= right) {
		mid = (left + right) / 2;
		eq++;
		if (mas[mid] == s) {
			check = false;
			break;
		}
		else if (mas[mid] > s) {
			right = mid-1;
		}
		else {
			left = mid+1;
		}
	}
	cout << "Сравнений в поиске бинарном: " << eq << endl;
	if (check) {
		cout << "Элемент не найден" << endl;
	}
	else
		cout << "Число " << s << " найдено" << endl;

}

int main() {
	setlocale(LC_ALL, "rus");
	cout << "Введите размер: " << endl;
	int size;
	cin >> size;
	int *mas = new int[size];
	inicMas(mas, size);
	sort(mas, size);
	while (1) {
		cout << "Продолжить 1/0?" << endl;
		int* mas = new int[size];
		inicMas(mas, size);
		sort(mas, size);
		int next;
		cin >> next;
		if (next == 0)
			break;
		printMas(mas, size);
		searchLine(mas, size);
		binsearch(mas, size);
	}
}