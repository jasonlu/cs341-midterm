//
//  Utility.cpp
//  CS431-assignment02
//
//  Created by Jason Lu on 9/23/13.
//  Copyright (c) 2013 Lu Jason. All rights reserved.
//

#include "Utility.h"
using namespace std;

const string QUIT_STR = "quit";
long Utility::readAsLong(string promt = "") {
    long res = 0;
    string cmd = "";
    cout << promt;
    try {
        cin >> cmd;
        if(cmd == ::QUIT_STR) {
            exit(EXIT_SUCCESS);
            //return false;
        }
        res = stol(cmd);
    } catch(exception e){
        cout << "Input error, not a int, retry:\n";
        res = readAsLong();
    }
    return res;
}

int Utility::readAsInt(string promt = "") {
    return (int)readAsLong(promt);
}

double Utility::readAsDouble(string promt = "") {
    double res = 0.0;
    string cmd = "";
    cout << promt;
    try {
        cin >> cmd;
        if(cmd == ::QUIT_STR) {
            exit(EXIT_SUCCESS);
        }
        res = stod(cmd);
    } catch(exception e){
        cout << "Input error, not a float, retry:\n";
        res = readAsDouble();
    }
    return res;
}

float Utility::readAsFloat(string promt = "") {
    return (float)readAsDouble(promt);
}



string Utility::readAsString(string promt = "") {
    string res = "";
    string cmd = "";
    cout << promt;
    try {
        cin >> cmd;
        if(cmd == ::QUIT_STR) {
            exit(EXIT_SUCCESS);
        }
        res = cmd;
    } catch(exception e){
        cout << "Input error, not a string, retry:\n";
        res = readAsString();
    }
    return res;
}



bool Utility::readAsBool(string promt = "") {
    bool res = false;
    string cmd = "";
    cout << promt;
    try {
        cin >> cmd;
        transform(cmd.begin(), cmd.end(), cmd.begin(), ::tolower);
        if(cmd == ::QUIT_STR) {
            exit(EXIT_SUCCESS);
        }
        if(cmd == "yes" || cmd == "y") {
            res = true;
        } else {
            res = false;
        }
        
    } catch(exception e){
        cout << "Input error, not a string, retry:\n";
        res = readAsBool();
    }
    return res;
}

int randInt(int limit, int notThisOne = -1) {
    int res = rand() % limit;
    if(res == notThisOne) {
        return randInt(limit, notThisOne);
    } else {
        return res;
    }
}

int randInt(int limit) {
    return rand() % limit;
}