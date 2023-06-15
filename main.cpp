#include <iostream>
#include <thread>
#include "clear_screen.h"
#include "Food.h"
#include "List.h"
using namespace std;

List list;
const string nickname = "admin";
string password = "123";

void showMenu();
void addCart();
void editMenu();
void addFood();
void removeFood();

int main() {
    bool loop=true;
    while(loop) {
        clearScreen();
        short choice;
        string nname,pass;

        cout << "::::: Select Mode :::::" << endl;
        cout << "1 | Edit Mode\n2 | Order Mode\n3 | Exit\n>>Enter Number:" << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Nickname = admin Password = 123" << endl; //You can delete this line.
                cout << "Nickname: ";
                cin >> nname;
                cout << "\n";
                cout << "Password: ";
                cin >> pass;
                if(nname==nickname && pass==password)
                    editMenu();
                break;
            case 2:
                showMenu();
                addCart();
                break;
            case 3:
                loop=false;
                break;
            default:
                cout << "ERROR: Invalid Number" << endl;
                this_thread::sleep_for(chrono::seconds(2));
        }
    }

    list.removeAll();
    return 0;
}

void showMenu(){
    clearScreen();
    list.showList();
}

void addCart(){
    bool loop=true;
    while(loop) {
        short no = 0, num = 0, choice;
        cout << ">>Enter food number:" << endl;
        cin >> no;
        cout << ">>Enter quantity:" << endl;
        cin >> num;
        list.addCart(no, num);
        this_thread::sleep_for(chrono::seconds(3));

        cout << "\nWill you choose food again?\n1 | Yes\n2 | No\n>>Enter Number:"<<endl;
        cin >> choice;
        if(choice==2){
                loop = false;
                list.pay();
                this_thread::sleep_for(chrono::seconds(3));
        }
    }
}

void editMenu(){
    bool loop=true;
    short mExit;
    while(loop) {
        clearScreen();
        short choice;

        cout << "::::: Edit Panel :::::" << endl;
        cout << "1 | Add Food\n2 | Remove Food\n3 | Show Menu\n4 | Set Password\n5 | Exit\n>>Enter Number:" << endl;
        cin >> choice;
        switch (choice) {
            case 1:
                addFood();
                break;
            case 2:
                removeFood();
                break;
            case 3:
                showMenu();
                cout << "\n4 | Exit\n>>Enter Number:" << endl;
                cin >> mExit;
                break;
            case 4:
                clearScreen();
                cout << ">>Enter New Password:"<< endl;
                cin >> password;
                break;
            case 5:
                loop = false;
                break;
            default:
                cout << "ERROR: Invalid Number" << endl;
        }
    }
}

void addFood(){
    clearScreen();
    cout << "::::: Add Food :::::" << endl;
    bool loop = true;
    while(loop){
        string name;
        short price, no, loopAddFood=1;

        cout << ">>Enter Food Number" << endl;
        cin >> no;
        cout << ">>Enter Food Name" << endl;
        cin >> name;
        cout << ">>Enter Food Price" << endl;
        cin >> price;

        Food food(no, name, price);
        list.addFood(food);
        cout << "Food Added" << endl;

        cout << "Will you add food again?\n1 | Yes\n0 | No\n>>Enter Number:" << endl;
        cin >> loopAddFood;
        switch(loopAddFood){
            case 0:
                loop = false;
            case 1:
                cout << "Add Food Again" << endl;
                break;
            default:
                cout << "ERROR: Invalid Number" << endl;
                loop = false;
        }
    }
}

void removeFood(){
    bool loop = true;
    while(loop) {
        clearScreen();
        short choice;
        string name;

        cout << "1 | Delete a Food\n2 | Delete All Foods\n3 | Exit\n>>Enter Number:" << endl;
        cin >> choice;
        switch (choice) {
            case 1:
                if(list.foods.size() > 1){
                    showMenu();
                    cout << ">>Enter Food Name" << endl;
                    cin >> name;
                    list.removeFood(name);
                    this_thread::sleep_for(chrono::seconds(3));
                }
                else{
                    list.removeAll();
                    this_thread::sleep_for(chrono::seconds(3));
                }
                break;
            case 2:
                list.removeAll();
                this_thread::sleep_for(chrono::seconds(3));
                break;
            case 3:
                loop = false;
                break;
            default:
                cout << "ERROR: Invalid Number" << endl;

        }
    }


}

