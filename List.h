#pragma once
#include <iostream>
#include <vector>
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

void List::addFood(const Food &food) {
    foods.push_back(food);
}

void List::removeFood(const string &foodname) {
    for(auto it=foods.begin(); it != foods.end(); ++it){
        if(it->name == foodname){
            foods.erase(it);
            cout<<"(i) Food Removed"<< endl;
        }
    }
}

void List::removeAll() {
    foods.clear();
    cout << "(i) All Foods Removed" << endl;
}

void List::showList() {
    system("clear");
    cout << "::::: MENU :::::" << endl;
    cout << "|  No  |" << endl;
    for(const Food& food : foods){
        cout << "|  " << food.no << "  | " << food.name << " | " << food.price << " $ |" << endl;
    }
}

void List::addCart(short no, short num) {
    bool found = false;
    for(const Food& food : foods){
        if(food.no == no){
            amount += (food.price * num);
            cartName.push_back(food.name);
            cartNum.push_back(num);
            cout << "(i) Food added to cartName. Total Amount: " << amount << endl;
            found = true;
        }
    }
    if(!found)
        cout <<"ERROR: Invalid Number" << endl;
}

void List::pay(){
    system("clear");
    cout << "::::: CART :::::" << endl;
    for(size_t i=0; i < cartName.size(); i++){
        cout << cartNum[i] << " x " << cartName[i] << endl;
    }
    cout << "\nTOTAL AMOUNT: $" << amount << endl;
}

