#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include "library.h"  // ingr определен здесь
#include <string>
#include <vector>

class Product {
private:
    std::string name;
    double price;
    std::string location;
protected:
    std::string description;
    double expiration_date;
    std::vector<ingr> composition;  // ИЗМЕНЕНО: теперь вектор ingr
public:
    // конструктор полного заполнения
    Product(std::string a, std::string b, double c, double d, std::string e, std::vector<ingr>& comp);
    // Конструктор по умолчанию
    Product();
    // Конструктор копирования
    Product(const Product& other);
    // Деструктор
    ~Product();
    
    // геттеры
    std::string getName() const;
    double getPrice() const;
    std::string getLocation() const;
    double getExpiration_date() const;
    std::string getDescription() const;  // ИСПРАВЛЕНО: опечатка
    std::vector<ingr> getComposition() const;  // ИЗМЕНЕНО: возвращаем vector<ingr>

    // сеттеры
    void setPrice(double newPrice);
    void setName(const std::string& n);
    void setExpiryDate(double exp);  // ИСПРАВЛЕНО: double вместо int
    void setComposition(const std::vector<ingr>& comp);  // ИЗМЕНЕНО: принимает vector<ingr>
    void setLocation(const std::string& m);
    
    // вывод информации
    void displayInfo() const;
    void locationInfo();
    void decreaseExpirationDate(double newExpirationDate);
    
    // Арифметические операторы
    Product operator+(const Product& other) const;
    Product operator-(const Product& other) const;
    Product& operator-=(const Product& other);
    
    // оператор присваивания
    Product& operator=(const Product& other);
    
    // Детальный анализ ингредиентов для комиссии
    void analyzeComposition(const std::vector<ingr>& ingredientity);  // ИСПРАВЛЕНО: название метода
};

#endif
