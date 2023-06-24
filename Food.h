#pragma once
#include <iostream>
using namespace std;

class Food{
public:
    Food(int no, string& name, int price){

        this->no = no;
        this->name = name;
        this->price = price;
    }

    int no;
    string name;
    int price;
};
