#include <iostream>
#include "widerstand.h"

int main(void)
{
    //TODO
    widerstand ds;           //ein Widerstandsdatensatz zum späteren Speichern in dataArray
    char chr, puffer[10];
    bool exit = false;

    while(true){
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

                /*TODO*/
                cout << "\n\n Eingabe eines neuen Datensatzes. ";
                //Widerstands-Bauform
                cout << "\n Widerstands-Bauform: ";
                cin >> /*TODO*/
                //Widerstands-Wert
                do {
                    cout << "\n Widerstands-Wert ";
                    cout << "(Dezimaltrennzeichen ist der Punkt!): ";
                    cin >> puffer;
                    /*TODO: ggf. eigene support.h inkludieren und Funktion convertToInt() verwenden*/
                }
                while( /*TODO*/ );

                /*TODO*/
                if( /*TODO*/){
                    ausgabe(dataArrayFeld);
                    break;
                }
            case 'a':
            /*TODO*/
                break;
            case 's':
                system("cls");
            /*TODO*/
                break;
            case 'b': exit = true;
                break;
        }//switch
        if(exit) break;
    }//while
    return EXIT_SUCCESS;
}



