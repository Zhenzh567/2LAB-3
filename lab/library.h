#ifndef LIBRARY_HPP
#define LIBRARY_HPP

#include <string>
#include <vector>

// Предварительное объявление класса Product
class Product;

struct ingr {
    std::string name;
    double volume;
};

class Comission {
private:
    std::vector<std::string> error_ingr;
protected:
    double term;
public:
    std::string address;
    
    // конструкторы
    Comission();
    Comission(const Comission& other);
    Comission(std::vector<std::string> a, double b, std::string e);
    
    // геттеры
    std::vector<std::string> getIngr() const;
    double getTerm() const;
    std::string getAddress() const;
    
    // сеттеры
    void setIngr(std::vector<std::string> newIngr);
    void setTerm(double newTerm);
    void setAddress(std::string newAddress);
    
    // оператор присваивания
    Comission& operator=(const Comission& other);
    
    // деструктор
    ~Comission();
    
    // метод проверки товара на легальность
    void checkLegal(const Product& product);  // ИЗМЕНЕНО: принимает Product
};

#endif
