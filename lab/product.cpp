#include "product.h"
#include "library.h"
#include <iostream>
#include <algorithm>

struct ingr;

 
//конструктор полного заполнения
    Product::Product(std::string a, std::string b, double c, double d, std::string e,std::vector<std::string>& comp) {
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
            std::cout << "Ошибка" << std::endl;
            d = 0.0;
        }
        else {
            expiration_date = d;
        }
        location = e;
        composition = comp;
    }
    //Конструктор по умолчанию
    Product::Product() {
        name = "Не указано";
        description = "Нет описания";
        price = 0.0;
        expiration_date = 0.0;
        location = "Неизвестно";
        std::vector<ingr> composition = {};
    }
    // Конструктор копирования
    Product::Product(const Product& other) {
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
    // Деструктор
    Product::~Product() {
        std::cout << "Объект Product с названием " << name << " уничтожен" << std::endl;
    }
    //Оператор присваивания
    Product& Product::operator=(const Product& other){
        if (this!= &other){
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
    //геттеры
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
    std::string Product::getDesription() const {
        return description;
    }
    std::vector<std::string> Product::getComposition() const{
        return composition;
    }
    //сеттеры
    void Product::setPrice(double newPrice) {
        if (newPrice >= 0) {
            price = newPrice;
        }
        else {
            std::cout << "Неккоректная цена" << std::endl;
        }
    }
    void Product::setName(const std::string& n){
        name = n;
    }

    void Product::setExpiryDate(int exp){
        expiration_date = exp;
    }
    void Product::setComposition(const std::vector<std::string>& comp){
        composition = comp;
    }

    void Product::setLocation(const std::string& m){
        location = m;
    }
    //вывод всей информации
    void Product::displayInfo() const{
        std::cout << name << std::endl;
        std::cout << price << std::endl;
        std::cout << location << std::endl;
        std::cout << description << std::endl;
        std::cout << expiration_date << std::endl;
        for (const auto& ing : composition){
            std::cout<<ing;
        }
        std::cout<<std::endl;
    }
    //вывод,где получить товар
    void Product::locationInfo() {
        std::cout << location << std::endl;
    }
    void Product::decreaseExpirationDate(double newExpirationDate) {
        if (newExpirationDate < 0) {
            std::cout << "Ошибка: дата не может быть отрицательной" << std::endl;
            return;
        }

        if (newExpirationDate > expiration_date) {
            std::cout << "Ошибка" << std::endl;
            return;
        }

        expiration_date = newExpirationDate;
        std::cout << "Срок хранения успешно изменен" << std::endl;
    }
        Product Product::operator+(const Product& other) const{
        Product result(*this);
        result.name = "смесь" + this->name + "и" + other.name;
        result.price = (this->price + other.price) * 0.9;
        result.expiration_date = std::min(this->expiration_date, other.expiration_date);
        result.composition = this->composition;
        for (const std::string& ingredient: other.composition){
            if (std::find(result.composition.begin(),result.composition.end(),ingredient) == result.composition.end()){
                result.composition.push_back(ingredient);
            }
        }
        result.description = this->description + "Новые компоненты";
        result.location = this->location;

        return result;

    }
    Product Product::operator-(const Product& other) const{
        Product result(*this);
        result.name = "Выбор" + this->name + "без" + other.name;
        result.price = this->price*0.9;
        result.expiration_date = this->expiration_date - 2;
        if (result.expiration_date < 0) result.expiration_date = 0;
        result.location = this->location;
        result.description = this->description + "Новые космпоненты";
        for (const std::string& ingredient : this->composition){
            if (std::find(other.composition.begin(),other.composition.end(),ingredient) == other.composition.end()){
                result.composition.push_back(ingredient);
            }
        }
        std::string conserv = "консервант T1000";
        if (std::find(result.composition.begin(),result.composition.end(),conserv) == result.composition.end()){
            result.composition.push_back(conserv);
        }
        return result;
    }
    Product& Product::operator-=(const Product& other){
        name = "Выбор" + name + "без" + other.name;
        price *= 0.9;
        expiration_date -= 2;
        if (expiration_date < 0) expiration_date = 0;
        location = location;
        description = description + "новые элементы";
        std::vector<std::string> newComposition;
        for (const std::string& ingredient : composition){
            if (std::find(other.composition.begin(),other.composition.end(),ingredient) == other.composition.end()){
                newComposition.push_back(ingredient);
            }
        }
        std::string conserv = "консервант T1000";
        if (std::find(newComposition.begin(),newComposition.end(),conserv) == newComposition.end()){
            newComposition.push_back(conserv);
        }
        
        composition = newComposition;
        return *this;

    }
    //Детальный анализ ингредиентов для комиссии
    void Product::analizecomposition(const std::vector<ingr>& ingredientity){
        for (const auto& ing : ingredientity){
            std::cout<<ing.name<<ing.volume;
        }
    }