#include <iostream>
#include "widerstand.h"

int main(void)
{
    //TODO
    widerstand ds;           //ein Widerstandsdatensatz zum späteren Speichern in dataArray
    char chr, puffer[10];
    bool exit = false;
    vector<widerstand> dataArray(0);

    //imp here vector import

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

                /*TODO: dunno what comes here*/
                cout << "\n\n Eingabe eines neuen Datensatzes. ";
                //Widerstands-Bauform
                cout << "\n Widerstands-Bauform: ";
                cin >> ds.design;
                /*later: should be done. maybe cin.getline*/
                //Widerstands-Wert
                do {
                    cout << "\n Widerstands-Wert ";
                    cout << "(Dezimaltrennzeichen ist der Punkt!): ";
                    cin >> puffer;
                    /*imp: ggf. eigene support.h inkludieren und Funktion convertToInt() verwenden*/
                }
                while( /*TODO: until correct value given. convertToInt() returns true*/ );
                /*TODO: here, get dimensions of R*/

                //imp write everything in ds

                if( /*TODO: DUNNO! if everything is written? // import() returns true? */){
                    printData(ds);//imp  new funktion to give out ds //hack overload?
                    break;
                }
                //later after now only optimization
            case 'a':
                printData(dataArray);
                break;
            case 's':
                system("cls");
                if (writeToFile(dataArray)==true){
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



