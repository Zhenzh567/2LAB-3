#ifndef PRODUCT_HPP
#define PRODUCT_HPP
#include "library.h"
#include <string>
#include <vector>

struct ingr;

class Product {
private:
    std::string name;
    double price;
    std::string location;
protected:
    std::string description;
    double expiration_date;
    std::vector<std::string> composition;
public:
    //конструктор полного заполнения
    Product(std::string a, std::string b, double c, double d, std::string e,std::vector<std::string>& comp);
    //Конструктор по умолчанию
    Product();
    // Конструктор копирования
    Product(const Product& other);
    // Деструктор
    ~Product();
    //геттеры
    std::string getName() const;

    double getPrice() const;

    std::string getLocation() const;

    double getExpiration_date() const;

    std::string getDesription() const;
    
    std::vector<std::string> getComposition() const;

    //сеттеры
    void setPrice(double newPrice);
    void setName(const std::string& n);
    void setExpiryDate(int exp);
    void setComposition(const std::vector<std::string>& comp);
    void setLocation(const std::string& m);
    //вывод всей информации
    void displayInfo() const;
    //вывод,где получить товар
    void locationInfo();
    void decreaseExpirationDate(double newExpirationDate);
    //Арифметические операторы
    Product operator+(const Product& other) const;
    Product operator-(const Product& other) const;
    Product& operator-=(const Product& other);
    //оператор присваивания
    Product& operator=(const Product& other);
    //Детальный анализ ингредиетов для комиссии
    void analizecomposition(const std::vector<ingr>& ingredientity);


};



#endif;
