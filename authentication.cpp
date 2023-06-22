#include "authentication.h"

bool Authentication::accAuthen(const std::string &nickname, const string& password) {
    ifstream accountFile;
    accountFile.open("../account.txt");
    if(!accountFile.is_open()){
    cout << "ERROR: The file could not be opened" << endl;
    return false;
    }

string nicknameF, passwordF;
getline(accountFile, nicknameF);
getline(accountFile, passwordF);

accountFile.close();

nicknameF.erase(remove_if(nicknameF.begin(), nicknameF.end(), [](unsigned char c){return isspace(c);}), nicknameF.end());
passwordF.erase(remove_if(passwordF.begin(), passwordF.end(), [](unsigned char c){return isspace(c);}), passwordF.end());

if(nickname == nicknameF && password == passwordF )
    return true;
else
    return false;
}

int Authentication::setNamePass(const std::string &nickname, const std::string &password) {
    ofstream accountFile;
    accountFile.open("../account.txt");
    if(!accountFile.is_open()){
        cout << "ERROR: The file could not be opened" << endl;
        return 1;
    }

    accountFile << nickname << "\n";
    accountFile << password << "\n";

    accountFile.close();

    return 0;
}