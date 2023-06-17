#pragma once
#include <iostream>
#include <vector>
#include "clear_screen.h"
#include "Food.h"
using namespace std;

class List{
public:
    List() = default;

    vector<Food> foods;
    vector<string> cartName;
    vector<short> cartNum;


    int amount=0;

    void addFood(const Food& food);

    void removeFood(const string& foodname);

    void removeAll();

    void showList();

    void addCart(short no, short num);

    void pay();
};

