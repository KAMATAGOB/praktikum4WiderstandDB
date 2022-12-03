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

    vector<widerstand> dataArray(0);


    while (true) {
        cout << "\n\n Was wollen Sie tun?";
        cout << "\n Neuen Widerstand eingeben        (n/N)";
        cout << "\n Widerstands-Datensaetze ausgeben (a/A)";
        cout << "\n Datensaetze speichern            (s/S)";
        cout << "\n Programm beenden                 (b/B)" << endl;
        cout << "\n\n ? ";
        cin >> chr;

        switch (tolower(chr)) {
            case 'n':
                system("cls");

                /*TODO: dunno what comes here*/
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
                    break;
                } else {
                    count--;
                    cout << "\nFehler bei der Eingabe! Kein Wert gespeichert!";
                    break;
                }

            case 'a':
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
                } else {
                    cout << "\nSpeichern fehlgeschlagen!";
                }
                break;
            case 'b':
                exit = true;
                break;
        }
        if (exit) break;
    }
    return EXIT_SUCCESS;
}



