#include "List.h"
//#include <iostream>
//#include "clear_screen.h"
//#include "Food.h"
//using namespace std;

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
    clearScreen();
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
    clearScreen();
    cout << "::::: CART :::::" << endl;
    for(size_t i=0; i < cartName.size(); i++){
        cout << cartNum[i] << " x " << cartName[i] << endl;
    }
    cout << "\nTOTAL AMOUNT: $" << amount << endl;
}