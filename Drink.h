#pragma once
#include <iostream>
using namespace std;

class Drink{
public:
    Drink(int no, string& name, int price){
        this->no = no;
        this->name = name;
        this->price = price;
    }

    int no;
    string name;
    int price;
};