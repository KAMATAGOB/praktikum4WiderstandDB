//
// Created by Johannes Harnisch on 29.11.22.
//
#include "widerstand.h"

void printData(vector<widerstand> dataArray) {

}

void printData(widerstand dataArray) {
    cout << endl << endl;
    cout << setw(14) << right << "Widerstands-Bauform";
    cout << setw(7) << right << "Wid.-Wert";
    cout << setw(7) << right << "Einheit" << endl << endl;

    cout << setw(14) << right << dataArray.design;
    cout << setw(7) << right << dataArray.value;
    cout << setw(7) << right << dataArray.dim << endl << endl;

}

bool writeToFile(vector<widerstand> dataArray) {
    bool done = false;


    return done;
}

bool importToVector(vector<widerstand> dataArray, widerstand input) {
    dataArray.push_back(input);
    return true;
}



