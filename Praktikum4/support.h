//supports the main funktion contains a converter funktion
// Created by Johannes Harnisch on 01.12.22.
//

#pragma once

#include "cstdlib"
#include <cstring>
#include <cctype>

/// <summary>
/// take an array of char and checks if conversion to double is possible and converts to double
/// </summary>
/// <param name="input">input to be converted, array of char, c.b.r.</param>
/// <param name="out">the var in which the value is written, double, c.b.r. </param>
/// <returns>is it possible to convert the input to double, bool, c.b.v. </returns>
bool convertToDouble(char input[], double& out);

