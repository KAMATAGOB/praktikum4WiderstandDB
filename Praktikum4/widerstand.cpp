//
// Created by Johannes Harnisch on 29.11.22.
//
#include "widerstand.h"

void printData(vector<widerstand> dataArray) {
    string dim;

    system("cls");
    cout << endl << endl;
    cout << setw(30) << right << "Widerstands-Bauform";
    cout << setw(20) << right << "Wid.-Wert";
    cout << setw(20) << left << "  Einheit" << endl << endl;

    for(int i = 0; i < dataArray.size();i++){
        cout << setw(30) << right << dataArray[i].design;
        cout << setw(20) << right << dataArray[i].value << "  ";

        switch( dataArray[i].dim )
        {
            case 1: dim = "Milli-Ohm"; break;
            case 2: dim = "Ohm"; break;
            case 3: dim = "Kilo-Ohm"; break;
            case 4: dim = "Mega-Ohm"; break;
        }

        cout << setw(20) << left << dim << endl << endl;
    }
}

void printData(widerstand dataArray) {
    string dim;

    cout << endl << endl;
    cout << setw(30) << right << "Widerstands-Bauform";
    cout << setw(20) << right << "Wid.-Wert";
    cout << setw(20) << left << "  Einheit" << endl << endl;

    cout << setw(30) << right << dataArray.design;
    cout << setw(20) << right << dataArray.value << "  ";

    switch( dataArray.dim )
    {
        case 1: dim = "Milli-Ohm"; break;
        case 2: dim = "Ohm"; break;
        case 3: dim = "Kilo-Ohm"; break;
        case 4: dim = "Mega-Ohm"; break;
    }
    cout << setw(20) << left << dim << endl << endl;
}

bool writeToFile(vector<widerstand> dataArray) {
    bool done = false;

    ofstream target;
    target.open("tmp.txt");

    if(target.is_open()){

        for(int i = 0; i < dataArray.size(); i++){
            target << setw(20) << dataArray[i].design << "   ";
            target << setw(10) << dataArray[i].value << "   ";
            target << setw(10) << dataArray[i].dim << "   ";
        }

        target.close();
        done = true;
    }

    return done;
}





