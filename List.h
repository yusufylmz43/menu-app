#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "clear_screen.h"
#include "Food.h"
#include "Drink.h"
using namespace std;

class List{
public:
    List() {
        ifstream listF("../list.txt");
        if(listF.is_open()){
            string line;
            while(getline(listF, line)){
                istringstream iss(line);
                string token;
                int no=0,price=0;
                string name;
                if(getline(iss,token,','))
                    no = stoi(token);
                if(getline(iss,token,','))
                    name = token;
                if(getline(iss,token,','))
                    price = stoi(token);
                Food food(no,name,price);
                foods.push_back(food);
            }
            listF.close();
        }
        else{
            int x;
            cout << "ERROR: The file could not be opened" << endl;
            cout << "The program cannot run without the file. Check the file path.\nFile Name: list.txt" << endl;
            cin >> x;
        }

        ifstream listDrinkF("../drinklist.txt");
        if(listDrinkF.is_open()){
            string line;
            while(getline(listDrinkF, line)){
                istringstream iss(line);
                string token;
                int no=0,price=0;
                string name;
                if(getline(iss,token,','))
                    no = stoi(token);
                if(getline(iss,token,','))
                    name = token;
                if(getline(iss,token,','))
                    price = stoi(token);
                Drink drink(no,name,price);
                drinks.push_back(drink);
            }
            listF.close();
        }
        else{
            int x;
            cout << "ERROR: The file could not be opened" << endl;
            cout << "The program cannot run without the file. Check the file path.\nFile Name: drinklist.txt" << endl;
            cin >> x;
        }
    };

    vector<Food> foods;
    vector<string> cartName;
    vector<short> cartNum;

    vector<Drink> drinks;


    int amount=0;

    void addFood(const Food& food);

    void removeFood(const int no);

    void removeAll();

    void showList();

    void addCart(short no, short num);

    void pay();
};

