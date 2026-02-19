#include "product.h"
#include "library.h"
#include <iostream>
#include <algorithm>

// конструктор полного заполнения
Product::Product(std::string a, std::string b, double c, double d, std::string e, std::vector<ingr>& comp) {
    name = a;
    description = b;
    if (c < 0) {
        std::cout << "Ошибка: цена не может быть отрицательной" << std::endl;
        price = 0.0;
    }
    else {
        price = c;
    }
    if (d < 0) {
        std::cout << "Ошибка: срок годности не может быть отрицательным" << std::endl;
        expiration_date = 0.0;
    }
    else {
        expiration_date = d;
    }
    location = e;
    composition = comp;
}

// Конструктор по умолчанию
Product::Product() {
    name = "Не указано";
    description = "Нет описания";
    price = 0.0;
    expiration_date = 0.0;
    location = "Неизвестно";
    composition = {};  // пустой вектор ingr
}

// Конструктор копирования
Product::Product(const Product& other) {
    name = other.name;
    description = other.description;
    if (other.expiration_date >= 0) {
        expiration_date = other.expiration_date;
    }
    else {
        std::cerr << "Ошибка при копировании: отрицательный срок годности" << std::endl;
        expiration_date = 0.0;
    }
    location = other.location;
    if (other.price >= 0) {
        price = other.price;
    }
    else {
        std::cerr << "Ошибка при копировании: отрицательная цена" << std::endl;
        price = 0.0;
    }
    composition = other.composition;
}

// Деструктор
Product::~Product() {
    std::cout << "Объект Product с названием \"" << name << "\" уничтожен" << std::endl;
}

// Оператор присваивания
Product& Product::operator=(const Product& other) {
    if (this != &other) {
        name = other.name;
        description = other.description;
        if (other.expiration_date >= 0) {
            expiration_date = other.expiration_date;
        }
        else {
            std::cerr << "Ошибка при копировании" << std::endl;
            expiration_date = 0.0;
        }
        location = other.location;
        if (other.price >= 0) {
            price = other.price;
        }
        else {
            std::cerr << "Ошибка при копировании: отрицательная цена" << std::endl;
            price = 0.0;
        }
        composition = other.composition;
    }
    return *this;
}

// геттеры
std::string Product::getName() const {
    return name;
}

double Product::getPrice() const {
    return price;
}

std::string Product::getLocation() const {
    return location;
}

double Product::getExpiration_date() const {
    return expiration_date;
}

std::string Product::getDescription() const {
    return description;
}

std::vector<ingr> Product::getComposition() const {
    return composition;
}

// сеттеры
void Product::setPrice(double newPrice) {
    if (newPrice >= 0) {
        price = newPrice;
    }
    else {
        std::cout << "Некорректная цена" << std::endl;
    }
}

void Product::setName(const std::string& n) {
    name = n;
}

void Product::setExpiryDate(double exp) {
    if (exp >= 0) {
        expiration_date = exp;
    }
    else {
        std::cout << "Некорректный срок годности" << std::endl;
    }
}

void Product::setComposition(const std::vector<ingr>& comp) {
    composition = comp;
}

void Product::setLocation(const std::string& m) {
    location = m;
}

// вывод всей информации
void Product::displayInfo() const {
    std::cout << "=== Информация о продукте ===" << std::endl;
    std::cout << "Название: " << name << std::endl;
    std::cout << "Цена: " << price << " руб." << std::endl;
    std::cout << "Местоположение: " << location << std::endl;
    std::cout << "Описание: " << description << std::endl;
    std::cout << "Срок годности: " << expiration_date << " дней" << std::endl;
    std::cout << "Состав:" << std::endl;
    for (const auto& ing : composition) {
        std::cout << "  - " << ing.name << " (объем: " << ing.volume << ")" << std::endl;
    }
    std::cout << "=============================" << std::endl;
}

// вывод, где получить товар
void Product::locationInfo() {
    std::cout << "Товар можно получить по адресу: " << location << std::endl;
}

void Product::decreaseExpirationDate(double newExpirationDate) {
    if (newExpirationDate < 0) {
        std::cout << "Ошибка: дата не может быть отрицательной" << std::endl;
        return;
    }

    if (newExpirationDate > expiration_date) {
        std::cout << "Ошибка: новая дата не может быть больше текущей" << std::endl;
        return;
    }

    expiration_date = newExpirationDate;
    std::cout << "Срок хранения успешно изменен на " << expiration_date << " дней" << std::endl;
}

Product Product::operator+(const Product& other) const {
    Product result(*this);
    result.name = "Смесь " + this->name + " и " + other.name;
    result.price = (this->price + other.price) * 0.9;
    result.expiration_date = std::min(this->expiration_date, other.expiration_date);
    
    // Объединяем составы (без дубликатов по имени)
    result.composition = this->composition;
    for (const ingr& ingredient : other.composition) {
        bool found = false;
        for (const ingr& existing : result.composition) {
            if (existing.name == ingredient.name) {
                found = true;
                break;
            }
        }
        if (!found) {
            result.composition.push_back(ingredient);
        }
    }
    
    result.description = this->description + " + новые компоненты";
    result.location = this->location;

    return result;
}

Product Product::operator-(const Product& other) const {
    Product result(*this);
    result.name = "Выборка " + this->name + " без " + other.name;
    result.price = this->price * 0.9;
    result.expiration_date = this->expiration_date - 2;
    if (result.expiration_date < 0) result.expiration_date = 0;
    result.location = this->location;
    result.description = this->description + " (модифицированный состав)";
    
    // Оставляем только те ингредиенты, которых нет в other
    result.composition.clear();
    for (const ingr& ingredient : this->composition) {
        bool found = false;
        for (const ingr& otherIng : other.composition) {
            if (ingredient.name == otherIng.name) {
                found = true;
                break;
            }
        }
        if (!found) {
            result.composition.push_back(ingredient);
        }
    }
    
    // Добавляем консервант
    ingr conserv;
    conserv.name = "Консервант T1000";
    conserv.volume = 0.5;
    
    bool hasConserv = false;
    for (const ingr& ing : result.composition) {
        if (ing.name == conserv.name) {
            hasConserv = true;
            break;
        }
    }
    if (!hasConserv) {
        result.composition.push_back(conserv);
    }
    
    return result;
}

Product& Product::operator-=(const Product& other) {
    name = "Выборка " + name + " без " + other.name;
    price *= 0.9;
    expiration_date -= 2;
    if (expiration_date < 0) expiration_date = 0;
    description = description + " (модифицированный состав)";
    
    // Оставляем только те ингредиенты, которых нет в other
    std::vector<ingr> newComposition;
    for (const ingr& ingredient : composition) {
        bool found = false;
        for (const ingr& otherIng : other.composition) {
            if (ingredient.name == otherIng.name) {
                found = true;
                break;
            }
        }
        if (!found) {
            newComposition.push_back(ingredient);
        }
    }
    
    // Добавляем консервант
    ingr conserv;
    conserv.name = "Консервант T1000";
    conserv.volume = 0.5;
    
    bool hasConserv = false;
    for (const ingr& ing : newComposition) {
        if (ing.name == conserv.name) {
            hasConserv = true;
            break;
        }
    }
    if (!hasConserv) {
        newComposition.push_back(conserv);
    }
    
    composition = newComposition;
    return *this;
}

// Детальный анализ ингредиентов для комиссии
void Product::analyzeComposition(const std::vector<ingr>& ingredientity) {
    std::cout << "Детальный анализ ингредиентов:" << std::endl;
    for (const auto& ing : ingredientity) {
        std::cout << "  Ингредиент: " << ing.name << ", объем: " << ing.volume << std::endl;
    }
}
