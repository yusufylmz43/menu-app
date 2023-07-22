#include "List.h"

void List::addFood(const Food &food) {
    ofstream listF;
    listF.open("../list.txt", ios::app);
    if(!listF.is_open())
        cout << "ERROR: The file could not be opened" << endl;
    else{
        listF << food.no << "," << food.name << "," << food.price << "\n";
        listF.close();
        foods.push_back(food);
    }
}

void List::removeFood(const int no) {
    ifstream listF("../list.txt");
    string fileName = "../list.txt";
    ofstream tempF("../temp.txt");
    string line;
    int currentLine = 1;

    while(getline(listF, line)){
        if(currentLine != no){
            tempF << line << endl;
        }
        currentLine++;
    }

    listF.close();
    tempF.close();

    remove(fileName.c_str());
    rename("../temp.txt", fileName.c_str());

    for(auto it=foods.begin(); it != foods.end(); ++it){
        if(it->no == no){
            foods.erase(it);
            cout<<"(i) Food Removed"<< endl;
        }
    }
}

void List::removeAll() {
    ofstream listF("../list.txt", ofstream::trunc);
    listF.close();
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
    cout<<"\n" << "::::: DRINKS :::::" << "\n" << "|  No  |" << endl;
    for(const Drink& drink : drinks){
        cout << "|  " << drink.no << "  | " << drink.name << " | " << drink.price << " $ |" << endl;
    }
}

void List::addCart(short no, short num) {
    bool found = false;
    for(const Food& food : foods){
        if(food.no == no){
            amount += (food.price * num);
            cartName.push_back(food.name);
            cartNum.push_back(num);
            cout << "(i) Food added to Cart. Total Amount: " << amount << endl;
            found = true;
        }
        else if(no == 0){ //To skip the food process
            found = true;
        }
    }
    for(const Drink& drink : drinks){
        if(drink.no == no){
            amount += (drink.price * num);
            cartName.push_back(drink.name);
            cartNum.push_back(num);
            cout << "(i) Drink added to Cart. Total Amount: " << amount << endl;
            found = true;
        }
        else if(no == 0){ //To skip the food process
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
    amount=0;
    cartName.clear();
    cartNum.clear();
}