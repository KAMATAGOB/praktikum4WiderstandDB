//contains libraries and funktionprototypes 
// funktions to display data and save the data on a txt file
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

/// <summary>
/// Prints the data from the vector into the console
/// </summary>
/// <param name="dataArray">the vector to print, vector, c.b.r.</param>
void printData(vector<widerstand> dataArray);

/// <summary>
/// overload from printData
/// prints o entry from the db
/// </summary>
/// <param name="dataArray">the entry to print, struct widerstand, c.b.v. </param>
void printData(widerstand dataArray);

/// <summary>
/// saces the vector to a txt file
/// </summary>
/// <param name="dataArray">the vector to save, vector, c.b.r. </param>
/// <returns>true if savin completed, bool, c.b.v. </returns>
bool writeToFile(vector<widerstand> dataArray);


/// <summary>reads saved values from tmp.txt and appends to the array</summary>
/// <param name="dataArray">the array to which to print, struct widerstand, c.b.r. </param>
/// <returns>was reading suksessful, bool, c.b.v.</returns>
bool readFromFile(vector<widerstand> &dataArray);


bool suchen(vector<widerstand> dataArray,string searchWord, vector<widerstand> &result);


void sortiere(vector<widerstand> &dataArray);


#endif //PRAKTIKUM4_WIDERSTAND_H


