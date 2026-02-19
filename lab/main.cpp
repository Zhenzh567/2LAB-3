#include "product.h"
#include "library.h"
#include <iostream>
#include <vector>

using namespace std;

// Вспомогательная функция для создания ингредиента
ingr createIngredient(string name, double volume) {
    ingr ingredient;
    ingredient.name = name;
    ingredient.volume = volume;
    return ingredient;
}

// Вспомогательная функция для вывода разделителя
void printSeparator() {
    cout << "\n" << string(60, '=') << "\n" << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    cout << "ТЕСТИРОВАНИЕ КЛАССОВ Product И Comission" << endl;
    cout << "=========================================" << endl;

    // ТЕСТ 1: Создание ингредиентов и продукта через полный конструктор
    printSeparator();
    cout << "ТЕСТ 1: Создание продукта через полный конструктор" << endl;
    
    vector<ingr> comp1;
    comp1.push_back(createIngredient("Мука", 500));
    comp1.push_back(createIngredient("Сахар", 200));
    comp1.push_back(createIngredient("Яйца", 3));
    
    Product p1("Торт", "Вкусный домашний торт", 450.0, 14, "Склад №1", comp1);
    p1.displayInfo();

    // ТЕСТ 2: Конструктор по умолчанию
    printSeparator();
    cout << "ТЕСТ 2: Конструктор по умолчанию" << endl;
    
    Product p2;
    p2.displayInfo();

    // ТЕСТ 3: Конструктор копирования
    printSeparator();
    cout << "ТЕСТ 3: Конструктор копирования" << endl;
    
    Product p3 = p1;
    cout << "Копия продукта p1:" << endl;
    p3.displayInfo();

    // ТЕСТ 4: Оператор присваивания
    printSeparator();
    cout << "ТЕСТ 4: Оператор присваивания" << endl;
    
    Product p4;
    p4 = p1;
    cout << "Результат присваивания p4 = p1:" << endl;
    p4.displayInfo();

    // ТЕСТ 5: Сеттеры и геттеры
    printSeparator();
    cout << "ТЕСТ 5: Сеттеры и геттеры" << endl;
    
    p3.setName("Новый торт");
    p3.setPrice(550.0);
    p3.setLocation("Склад №2");
    p3.setExpiryDate(21.5);
    
    vector<ingr> newComp;
    newComp.push_back(createIngredient("Мука", 600));
    newComp.push_back(createIngredient("Масло", 250));
    newComp.push_back(createIngredient("Шоколад", 150));
    p3.setComposition(newComp);
    
    cout << "Название: " << p3.getName() << endl;
    cout << "Цена: " << p3.getPrice() << endl;
    cout << "Местоположение: " << p3.getLocation() << endl;
    cout << "Срок годности: " << p3.getExpiration_date() << endl;
    cout << "Описание: " << p3.getDescription() << endl;
    
    cout << "Новый состав:" << endl;
    vector<ingr> comp = p3.getComposition();
    for (const auto& ing : comp) {
        cout << "  - " << ing.name << " (" << ing.volume << ")" << endl;
    }

    // ТЕСТ 6: Метод locationInfo
    printSeparator();
    cout << "ТЕСТ 6: Метод locationInfo" << endl;
    p1.locationInfo();

    // ТЕСТ 7: Метод decreaseExpirationDate
    printSeparator();
    cout << "ТЕСТ 7: Метод decreaseExpirationDate" << endl;
    
    cout << "Текущий срок годности p1: " << p1.getExpiration_date() << endl;
    p1.decreaseExpirationDate(10);
    cout << "После decreaseExpirationDate(10): " << p1.getExpiration_date() << endl;
    
    // Тест ошибок
    cout << "\nПопытка уменьшить до большего значения:" << endl;
    p1.decreaseExpirationDate(20);
    cout << "Попытка установить отрицательное значение:" << endl;
    p1.decreaseExpirationDate(-5);

    // ТЕСТ 8: Оператор +
    printSeparator();
    cout << "ТЕСТ 8: Оператор + (объединение продуктов)" << endl;
    
    vector<ingr> comp2;
    comp2.push_back(createIngredient("Мука", 300));
    comp2.push_back(createIngredient("Дрожжи", 50));
    comp2.push_back(createIngredient("Соль", 20));
    
    Product p5("Хлеб", "Свежий хлеб", 120.0, 7, "Склад №3", comp2);
    
    cout << "Продукт 1:" << endl;
    p1.displayInfo();
    cout << "Продукт 2:" << endl;
    p5.displayInfo();
    
    Product p6 = p1 + p5;
    cout << "РЕЗУЛЬТАТ p1 + p5:" << endl;
    p6.displayInfo();

    // ТЕСТ 9: Оператор -
    printSeparator();
    cout << "ТЕСТ 9: Оператор - (исключение ингредиентов)" << endl;
    
    vector<ingr> comp3;
    comp3.push_back(createIngredient("Сахар", 100));
    comp3.push_back(createIngredient("Ванилин", 5));
    
    Product p7("Сахарная смесь", "Сладкая добавка", 80.0, 30, "Склад №4", comp3);
    
    Product p8 = p1 - p7;
    cout << "РЕЗУЛЬТАТ p1 - p7 (исключаем сахар и ванилин):" << endl;
    p8.displayInfo();

    // ТЕСТ 10: Оператор -=
    printSeparator();
    cout << "ТЕСТ 10: Оператор -= (модификация продукта)" << endl;
    
    cout << "Продукт p1 до операции -=:" << endl;
    p1.displayInfo();
    
    p1 -= p7;
    cout << "Продукт p1 после p1 -= p7:" << endl;
    p1.displayInfo();

    // ТЕСТ 11: Класс Comission и метод checkLegal
    printSeparator();
    cout << "ТЕСТ 11: Класс Comission и проверка легальности" << endl;
    
    vector<string> forbidden;
    forbidden.push_back("Консервант T1000");
    forbidden.push_back("Яйца");
    forbidden.push_back("Краситель");
    
    Comission c1(forbidden, 30.0, "г. Москва, ул. Правды, 15");
    
    cout << "Информация о комиссии:" << endl;
    cout << "  Адрес: " << c1.getAddress() << endl;
    cout << "  Срок проверки: " << c1.getTerm() << " дней" << endl;
    cout << "  Запрещенные ингредиенты:" << endl;
    for (const auto& ing : c1.getIngr()) {
        cout << "    - " << ing << endl;
    }
    
    // Проверка продукта с запрещенным ингредиентом
    cout << "\nПроверка продукта p8 (должен содержать консервант T1000):" << endl;
    c1.checkLegal(p8);
    
    // Проверка продукта без запрещенных ингредиентов
    cout << "\nПроверка продукта p5 (хлеб):" << endl;
    c1.checkLegal(p5);

    // ТЕСТ 12: Метод analyzeComposition
    printSeparator();
    cout << "ТЕСТ 12: Метод analyzeComposition" << endl;
    
    p1.analyzeComposition(p1.getComposition());

    // ТЕСТ 13: Проверка некорректных данных
    printSeparator();
    cout << "ТЕСТ 13: Проверка обработки некорректных данных" << endl;
    
    cout << "Попытка создать продукт с отрицательной ценой:" << endl;
    vector<ingr> emptyComp;
    Product p9("Тест", "Описание", -100, 10, "Склад", emptyComp);
    
    cout << "\nПопытка установить отрицательную цену:" << endl;
    p9.setPrice(-50);
    
    cout << "\nПопытка установить отрицательный срок годности:" << endl;
    p9.setExpiryDate(-30);

    // ТЕСТ 14: Копирование и присваивание с проверкой самоприсваивания
    printSeparator();
    cout << "ТЕСТ 14: Проверка операторов копирования и присваивания" << endl;
    
    Product p10 = p5;  // копирование
    cout << "Копия продукта p5:" << endl;
    p10.displayInfo();
    
    p10 = p10;  // самоприсваивание
    cout << "После самоприсваивания:" << endl;
    p10.displayInfo();

    printSeparator();
    cout << "ТЕСТИРОВАНИЕ ЗАВЕРШЕНО" << endl;
    cout << "Все объекты будут уничтожены автоматически" << endl;
    printSeparator();

    return 0;
}
