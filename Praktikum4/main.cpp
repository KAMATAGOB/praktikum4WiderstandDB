/*
    
    This programm creates and administers an DB for resistors
    the supporting libraries are widerstand.h and support.h
    Created by Johannes Harnisch on 01.12.22.

*/

#include <iostream>
#include <vector>

#include "widerstand.h"
#include "support.h"

int main() {

    widerstand ds;           //ein Widerstandsdatensatz zum späteren Speichern in dataArray
    char chr, puffer[10];
    bool exit = false;
    int count = 0;
    bool saved = true;
    string searchWord;

    vector<widerstand> resultOfSearch(0);
    vector<widerstand> dataArray(0);

    if (!readFromFile(dataArray))
    {
        cout << "\nKeine Daten vorhanden!";
    }

    while (true) {
        cout << "\n\n Was wollen Sie tun?";
        cout << "\n Neuen Widerstand eingeben        (n/N)";
        cout << "\n Widerstands-Datensaetze ausgeben (a/A)";
        cout << "\n Datensaetze speichern            (s/S)";
        cout << "\n Widerstandstypen suchen          (f/F)";
        cout << "\n Datensätze sortieren             (o/O)";
        cout << "\n Programm beenden                 (b/B)" << endl;
        cout << "\n\n ? ";
        cin >> chr;

        switch (tolower(chr)) {
            case 'n':
                system("cls");


                cout << "\n\n Eingabe eines neuen Datensatzes. ";

                //Widerstands-Bauform
                cout << "\n Widerstands-Bauform (Kohleschicht, Metallschicht, LDR etc.)\n: ";
                cin >> ds.design;

                //Widerstands-Wert
                do {
                    cout << "\n Widerstands-Wert ";
                    cout << "(Dezimaltrennzeichen ist der Punkt!): ";
                    cin >> puffer;

                } while (!convertToDouble(puffer, ds.value));

                do {
                    cout << "\n Widerstandsdimension ";
                    cout << "\n\t MiliOhm --> 1"
                            "\n\t Ohm     --> 2"
                            "\n\t KiloOhm --> 2"
                            "\n\t MegaOhm --> 4"
                            "\n\n\t --> ";
                    cin >> puffer;
                    ds.dim = atoi(puffer);
                } while (!(ds.dim == 4 || ds.dim == 1 || ds.dim == 2 || ds.dim == 3));

                dataArray.push_back(ds);
                count++;
                if (count == dataArray.size()) {
                    printData(ds);
                    saved = false;
                    break;
                } else {
                    count--;
                    cout << "\nFehler bei der Eingabe! Kein Wert gespeichert!";
                    break;
                }

            case 'a':
                system("cls");
                if (dataArray.empty()) {
                    cout << "\nKeine Daten vorhanden";
                } else {
                    printData(dataArray);
                }
                break;
            case 's':
                system("cls");
                if (writeToFile(dataArray)) {
                    cout << "\nSpeichern erfolgreich!";
                    saved = true;
                } else {
                    cout << "\nSpeichern fehlgeschlagen!";
                }
                break;
            case 'f':
                if(dataArray.size() < 2){
                    cout << "\nDB ist kleiner 2! Suche sinnlos!";
                    break;
                }
                cout << "\nWelchen Typ wollen sie suchen?"
                     << "\n(Wort eingeben)!"
                     << "\n --> ";
                cin >> searchWord;

                if (!suchen(dataArray, searchWord, resultOfSearch)){
                    cout << "Keine Uebereistimmungen";
                    break;
                }
                printData(resultOfSearch);
                break;
            case 'o':
                sortiere(dataArray);
                break;
            case 'b':
                bool tmp = true;
                if(saved){
                    exit = true;
                }else{
                do {

                        cout << "Daten noch nicht gespeichert! Weiter?\n[y]es or [n]o:";
                        cin >> chr;
                        switch (chr) {
                            case 'y':
                                exit = true;
                                tmp = false;
                                break;
                            case 'n':
                                tmp = false;
                                break;
                        }
                    }while(tmp);

                break;
            }
        }
        if (exit) break;
    }
    return EXIT_SUCCESS;
}



