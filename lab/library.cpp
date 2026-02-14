#include "library.h"
#include "product.h"
#include <iostream>
#include <vector>
#include <string>

        //конструктор по-умолчанию
        Comission::Comission(){
            error_ingr = {};
            term = 0.0;
            address = "Не известно";
        }
        //конструктор копирования
        Comission::Comission(const Comission& other){
            error_ingr = other.error_ingr;
            term = other.term;
            address = other.address;
        }
        //конструктор полного заполнения
        Comission::Comission(std::vector<std::string> a,double b,std::string e){
            error_ingr = a;
            term = b;
            address = e;
        }
        //геттеры
        std::vector<std::string> Comission::getIngr() const{
            return error_ingr;
        }
        double Comission::getTerm() const{
            return term;
        }
        std::string Comission::getAddress() const{
            return address;
        }
        //сеттеры
        void Comission::setIngr(std::vector<std::string> newIngr){
            error_ingr = newIngr;
        }

        void Comission::setTerm(double newTerm){
            term = newTerm;
        }
        void Comission::setAddress(std::string newAddress){
            address = newAddress;
        }
        //оператор копирования
        Comission& Comission::operator=(const Comission& other){
            if (this != &other){
                error_ingr = other.error_ingr;
                term = other.term;
                address = other.address;
            }
            return (*this);
        }
        //метод проверки товара на легальность
        void checkLegal(std::vector<std::string> zappresh,double exp_date,std::vector<std::string> compo){
            if (exp_date <= 0){
                std::cout<<"Товар просрочен"<<std::endl;
                return;
            }
            for (const std::string& ingred : compo){
                for (const std::string& zap : zappresh){
                    if (ingred == zap){
                        std::cout<<"Найден запрещённый элемент"<<std::endl;
                    }
                }
            }
        }

