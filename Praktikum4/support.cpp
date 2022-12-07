//Implementation of convertToDouble
// Created by Johannes Harnisch on 01.12.22.
//

#include "support.h"


bool convertToDouble(char input[], double& out) {

    bool ok = true;
    int count = 0;

    int length = strlen(input);
    for (int i = 0; i < length; ++i) {
        if (input[i] != '.' && !(isdigit(input[i]))) {
            ok = false;
        }
        if (input[i] == '.') {
            count++;
        }
        if (count >= 2) {
            ok = false;
        }
    }

    out = atof(input);

    return ok;
}
