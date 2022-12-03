//
// Created by Johannes Harnisch on 29.11.22.
//

#ifndef PRAKTIKUM4_WIDERSTAND_H
#define PRAKTIKUM4_WIDERSTAND_H

#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

struct widerstand {
    int dim;            //mΩ --> 0, Ω --> 1, kΩ --> 2, MΩ -->3
    string design;      //Kohleschicht, Metalloxid etc.
    double value;       //positive Wert größer Null
};

void printData(vector<widerstand> dataArray);

void printData(widerstand dataArray);

bool writeToFile(vector<widerstand> dataArray);

#endif //PRAKTIKUM4_WIDERSTAND_H
