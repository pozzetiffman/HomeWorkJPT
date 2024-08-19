#include <iostream>  // Подключение библиотеки для ввода/вывода данных
#include <cstdlib>   // Подключение библиотеки для использования функций rand() и srand()
#include <ctime>     // Подключение библиотеки для использования функции time()

using namespace std;  // Использование пространства имен std для упрощения синтаксиса

// Функция для выделения памяти под массив заданного размера
int* newSizeAbb(int size) {
    int* memory = new int[size];  // Выделение памяти для массива
    return memory;  // Возврат указателя на выделенную память
}

// Функция для заполнения массива нулями
void replacement(int* mas, int size) {
    for (int i{}; i < size; i++) {
        mas[i] = 0;  // Заполнение каждого элемента массива нулем
    }
}

// Функция для заполнения массива случайными числами в диапазоне от min до max
void randCisloAbb(int* mas, int size, int& max, int& min) {
    for (int i{}; i < size; i++) {
        mas[i] = rand() % (max - min + 1) + min;  // Генерация случайного числа в заданном диапазоне
    }
}

// Функция для вывода массива на экран
void print(int* mas, int size) {
    for (int i{}; i < size; i++) {
        cout << mas[i] << " ";  // Вывод каждого элемента массива с пробелом между ними
    }
}

// Функция для замены всех вхождений заданного числа на новое значение
void canceCisl(int* mas, int size, int target, int newValue) {
    for (int i{}; i < size; i++) {
        if (mas[i] == target) {  // Проверка, соответствует ли текущий элемент целевому числу
            mas[i] = newValue;  // Замена элемента на новое значение
        }
    }
}

// Функция для поиска дубликатов в массиве и подсчета их количества
void colDuble(int* mas, int* masTwo, int* counts, int size, int& col) {
    bool found = false;  // Флаг для проверки, был ли найден дубликат
    for (int i{}; i < size; i++) {
        found = false;
        for (int j = i + 1; j < size; j++) {
            if (mas[i] == mas[j]) {  // Проверка на совпадение текущего элемента с остальными
                if (!found) {  // Если дубликат еще не найден
                    col++;  // Увеличение счетчика дубликатов
                    masTwo[col - 1] = mas[i];  // Сохранение дубликата в дополнительный массив
                    counts[col - 1] = 1;  // Инициализация счетчика для текущего дубликата
                    found = true;  // Пометка, что дубликат был найден
                }
                counts[col - 1]++;  // Увеличение счетчика для найденного дубликата
            }
        }
    }
    // Вывод результатов поиска дубликатов
    if (col == 0) {
        cout << "\nдубликатов нет \n";
    } else {
        cout << "\nколичество дублей: " << col << "\n";
        cout << "числа дублей:\n";
        for (int i{}; i < col; i++) {
            cout << "число " << masTwo[i] << " (" << counts[i] << ") дубликата\n";
        }
    }
}

int main(int argc, const char* argv[]) {
    srand(static_cast<unsigned>(time(0)));  // Инициализация генератора случайных чисел

    // Инициализация переменных
    int size{}, maxValue{100}, minValue{-100}, findPiple{}, canceCislo{}, coldub{};
    cout << "введите размер массива: ";
    cin >> size;

    // Создание и инициализация массивов
    int* abb = newSizeAbb(size);
    replacement(abb, size);

    // Заполнение массива случайными числами и вывод на экран
    randCisloAbb(abb, size, maxValue, minValue);
    cout << "массив до изменений: ";
    print(abb, size);

    // Создание массивов для хранения дубликатов и их счетчиков
    int* abbTwo = newSizeAbb(size);
    int* counts = newSizeAbb(size);

    // Инициализация массивов нулями
    replacement(abbTwo, size);
    replacement(counts, size);

    // Поиск дубликатов и их вывод
    colDuble(abb, abbTwo, counts, size, coldub);

    // Замена числа в массиве и вывод результата
    cout << "введите число под замену: ";
    cin >> findPiple;
    cout << "введите число на которое нужно заменить: ";
    cin >> canceCislo;

    canceCisl(abb, size, findPiple, canceCislo);
    cout << "массив после изменений: ";
    print(abb, size);
    cout << "\n\n\n";

    // Освобождение памяти
    delete[] abb;
    delete[] abbTwo;
    delete[] counts;

    return 0;
}
