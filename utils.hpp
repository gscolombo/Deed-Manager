#ifndef UTILS_HPP_INCLUDED
#define UTILS_HPP_INCLUDED

#include <string>
#include <vector>
#include <math.h>
using namespace std;

/**
 * @namespace utils
 * Utility functions to be used in other parts of the code.
*/

namespace utils
{
    /**
     * @fn string trim(string& str, bool l = true, bool r = true)
     * Trims the input string by removing leading and/or trailing whitespace characters.
     *
     * @param str The input string to be trimmed.
     * @param l (optional) A boolean flag indicating whether to trim leading whitespace characters. Default is true.
     * @param r (optional) A boolean flag indicating whether to trim trailing whitespace characters. Default is true.
     *
     * @return The trimmed string.
     */
    string trim(string& str, bool l = true, bool r = true);

    /**
     * @fn vector<string> split(string str, string del = " ")
     * Split a string based on a delimiter string.
     *
     * @param str The input string to be split.
     * @param del (optional) The delimiter string to split the input string. Default is " " (whitespace).
     *
     * @return A vector of substrings of the input string splitted with the given delimiter.
     */
    vector<string> split(string str, string del = " ");

    /**
     * @fn double toPrecision(double d, int precision)
     * Calculates the value of a given double to a specified precision.
     *
     * @param d The double value to be converted.
     * @param precision The number of decimal places to round the double to.
     *
     * @return The input value rounded to the specified precision.
     */
    double toPrecision(double d, int precision);
}

#endif // UTILS_HPP_INCLUDED
