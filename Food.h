#pragma once
#include <iostream>
using namespace std;

class Food{
public:
    Food(short no, string& name, short price){

        this->no = no;
        this->name = name;
        this->price = price;
    }

    short no;
    string name;
    short price;
};
