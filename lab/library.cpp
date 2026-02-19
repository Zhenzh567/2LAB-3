#include "library.h"
#include "product.h"
#include <iostream>
#include <vector>
#include <string>

// конструктор по-умолчанию
Comission::Comission() {
    error_ingr = {};
    term = 0.0;
    address = "Не известно";
}

// конструктор копирования
Comission::Comission(const Comission& other) {
    error_ingr = other.error_ingr;
    term = other.term;
    address = other.address;
}

// конструктор полного заполнения
Comission::Comission(std::vector<std::string> a, double b, std::string e) {
    error_ingr = a;
    term = b;
    address = e;
}

// деструктор
Comission::~Comission() {
    std::cout << "Объект Comission уничтожен" << std::endl;
}

// геттеры
std::vector<std::string> Comission::getIngr() const {
    return error_ingr;
}

double Comission::getTerm() const {
    return term;
}

std::string Comission::getAddress() const {
    return address;
}

// сеттеры
void Comission::setIngr(std::vector<std::string> newIngr) {
    error_ingr = newIngr;
}

void Comission::setTerm(double newTerm) {
    term = newTerm;
}

void Comission::setAddress(std::string newAddress) {
    address = newAddress;
}

// оператор присваивания
Comission& Comission::operator=(const Comission& other) {
    if (this != &other) {
        error_ingr = other.error_ingr;
        term = other.term;
        address = other.address;
    }
    return *this;
}

// метод проверки товара на легальность
void Comission::checkLegal(const Product& product) {
    std::cout << "\n=== Проверка товара комиссией ===" << std::endl;
    std::cout << "Адрес комиссии: " << address << std::endl;
    std::cout << "Проверяемый продукт: " << product.getName() << std::endl;
    
    // Проверка срока годности
    if (product.getExpiration_date() <= 0) {
        std::cout << "РЕЗУЛЬТАТ: Товар просрочен!" << std::endl;
        return;
    }
    else {
        std::cout << "Срок годности: OK (" << product.getExpiration_date() << " дней)" << std::endl;
    }
    
    // Проверка запрещенных ингредиентов
    bool hasForbidden = false;
    std::vector<ingr> comp = product.getComposition();
    
    for (const ingr& ingredient : comp) {
        for (const std::string& forbidden : error_ingr) {
            if (ingredient.name == forbidden) {
                std::cout << "РЕЗУЛЬТАТ: Найден запрещённый элемент: " 
                          << ingredient.name << " (объем: " << ingredient.volume << ")" << std::endl;
                hasForbidden = true;
            }
        }
    }
    
    if (!hasForbidden) {
        std::cout << "РЕЗУЛЬТАТ: Запрещенных ингредиентов не найдено" << std::endl;
    }
    std::cout << "=================================" << std::endl;
}
