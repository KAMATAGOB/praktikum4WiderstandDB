#include <iostream>
#include "widerstand.h"
#include "support.h"

int main()
{

    widerstand ds;           //ein Widerstandsdatensatz zum späteren Speichern in dataArray
    char chr, puffer[10];
    bool exit = false;

    vector<widerstand> dataArray(0);



    while(true){
        cout << "\n\n Was wollen Sie tun?";
        cout << "\n Neuen Widerstand eingeben        (n/N)";
        cout << "\n Widerstands-Datensaetze ausgeben (a/A)";
        cout << "\n Datensaetze speichern            (s/S)";
        cout << "\n Programm beenden                 (b/B)" << endl;
        cout << "\n\n ? ";
        cin >> chr;

        switch (tolower(chr)) {
            case 'n':// IMP format output correctly
                system("cls");

                /*TODO: dunno what comes here*/
                cout << "\n\n Eingabe eines neuen Datensatzes. ";
                //Widerstands-Bauform
                cout << "\n Widerstands-Bauform: ";
                cin >> ds.design;
                //Widerstands-Wert
                do {
                    cout << "\n Widerstands-Wert ";
                    cout << "(Dezimaltrennzeichen ist der Punkt!): ";
                    cin >> puffer;
                    ds.value = convertToDouble(puffer);
                }
                while(ds.value <= 0);

                do {
                    cout << "\n Widerstands-dimension ";
                    cout << "(mΩ --> 0, Ω --> 1, kΩ --> 2, MΩ -->3): ";
                    cin >> puffer;
                    ds.dim = convertToInt(puffer);
                }
                while(!(ds.dim == 0 || ds.dim == 1 || ds.dim==2 || ds.dim==3));


                if(importToVector(dataArray, ds)){
                    printData(ds);
                    break;
                }
                //later after now only optimization
            case 'a':
                if(dataArray.empty()){
                   cout << "Bitte erst Daten hinterlegen!\n";
                }else{
                    printData(dataArray);
                }
                break;
            case 's':
                system("cls");
                if (writeToFile(dataArray)){
                    cout << "Speichern erfolgreich!\n";
                }else{
                    cout << "Speichern fehlgeschlagen\n";
                }
                break;
            case 'b':
                exit = true;
                break;
        }
        if(exit) break;
    }
    return EXIT_SUCCESS;
}



