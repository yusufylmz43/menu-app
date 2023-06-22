#pragma once
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cctype>

using namespace std;

class Authentication{
public:
    bool accAuthen(const string& nickname, const string& password);
    int setNamePass(const string& nickname, const string& password);
};