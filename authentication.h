#pragma once
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cctype>

using namespace std;

class Authentication{
public:
    static bool accAuthen(const string& nickname, const string& password);
    static int setNamePass(const string& nickname, const string& password);
};