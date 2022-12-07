//Implementation of PrintData and writeToFile
// Created by Johannes Harnisch on 29.11.22.
//
#include "widerstand.h"

void printData(vector<widerstand> dataArray) {
    int size = dataArray.size();
    string dim;

    if (size < 1) {
        cout << "Keine Daten vorhanden!";
        return;
    }
    system("cls");
    cout << endl << endl;
    cout << setw(30) << right << "Widerstands-Bauform";
    cout << setw(15) << right << "Wid.-Wert";
    cout << setw(20) << left << "  Einheit" << endl << endl;

    for (int i = 0; i < size; i++) {
        cout << setw(30) << right << dataArray[i].design;
        cout << setw(15) << right << fixed << setprecision(3) << dataArray[i].value << "  ";

        switch (dataArray[i].dim) {
            case 1:
                dim = "Milli-Ohm";
                break;
            case 2:
                dim = "Ohm";
                break;
            case 3:
                dim = "Kilo-Ohm";
                break;
            case 4:
                dim = "Mega-Ohm";
                break;
        }

        cout << setw(20) << left << dim << endl << endl;
    }
}

void printData(widerstand dataArray) {
    string dim;

    cout << endl << endl;
    cout << setw(30) << right << "Widerstands-Bauform";
    cout << setw(15) << right << "Wid.-Wert";
    cout << setw(20) << left << "  Einheit" << endl << endl;

    cout << setw(30) << right << dataArray.design;
    cout << setw(15) << right << fixed << setprecision(3) << dataArray.value << "  ";

    switch (dataArray.dim) {
        case 1:
            dim = "Milli-Ohm";
            break;
        case 2:
            dim = "Ohm";
            break;
        case 3:
            dim = "Kilo-Ohm";
            break;
        case 4:
            dim = "Mega-Ohm";
            break;
    }
    cout << setw(20) << left << dim << endl << endl;
}

bool writeToFile(vector<widerstand> dataArray) {
    bool done = false;

    ofstream target;
    target.open("tmp.txt");

    if (target.is_open()) {

        for (int i = 0; i < dataArray.size(); i++) {
            target << setw(30) << dataArray[i].design << "   ";
            target << setw(15) << dataArray[i].value << "   ";
            target << setw(20) << dataArray[i].dim << "   ";
            target << endl;
        }

        target.close();
        done = true;
    }

    return done;
}

bool readFromFile(vector<widerstand> &dataArray) {
    bool done = true;
    ifstream quelle;
    int i = 0;


    quelle.open("tmp.txt", ios::in);

    if (quelle.is_open()) {

        while (!quelle.eof()) {
            dataArray.resize(i + 1);
            quelle >> dataArray[i].design;
            quelle >> dataArray[i].value;
            quelle >> dataArray[i].dim;
            i++;
            if (!(dataArray[i].dim == (1) || dataArray[i].dim == (2) ||
                    dataArray[i].dim == (3) || dataArray[i].dim == (4))) {

                dataArray.resize(i + 1);
            }
        }
    } else {
        done = false;
    }

    quelle.close();


    return done;
}

bool suchen(vector<widerstand> dataArray, string searchWord, vector<widerstand> &result) {
    bool foundSome = false;
    int length = dataArray.size();

    for (int i = 0; i < length; i++) {
        if (dataArray[i].design == searchWord) {
            foundSome = true;
            result.push_back(dataArray[i]);
        }
    }
    return foundSome;
}

void sortiere(vector<widerstand> &dataArray) {
    bool change;
    int length = dataArray.size();

    do {
       change = false;
        for (int i = 0; i < (length-1); ++i) {
            if (dataArray[i].value > dataArray[(i+1)].value){
                widerstand tmp = dataArray[i];
                dataArray[i] = dataArray[(i+1)];
                dataArray[(i+1)] =tmp;
                change = true;
            }
        }
    }while(change);
}




