#ifndef LIBRARY_HPP
#define LIBRARY_HPP
#include "product.h"

#include <string>
#include <vector>



struct ingr{
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
        //конструктор по-умолчанию
        Comission();
        //конструктор копирования
        Comission(const Comission& other);
        //конструктор полного заполнения
        Comission(std::vector<std::string> a,double b,std::string e);
        //геттеры
        std::vector<std::string> getIngr() const;
        double getTerm() const;
        std::string getAddress() const;
        //сеттеры
        void setIngr(std::vector<std::string> newIngr);
        void setTerm(double newTerm);
        void setAddress(std::string newAddress);
        //оператор копирования
        Comission& operator=(const Comission& other);
        //деструктор
        ~Comission();
        //метод проверки товара на легальность
        void checkLegal(std::vector<std::string> z,double exp_date);


};





#endif