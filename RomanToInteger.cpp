/* Solution for roman to integer problem in Leetcode
 * Runtime - complexity: O(n)
 * Space - complexity: O(1)
 */

//Linking other header files
#include <string>

class Solution {

    //Public methods
    public:

        //Roman to integer conversion method
        int romanToInt(string romanStr) {

            //Initializing array to hold roman values by utilizing their ASCII character values
            //to set indices via subtraction from A 
            size_t romaNumeral[26] = {0};

            romaNumeral['I' - 'A'] = 1;
            romaNumeral['V' - 'A'] = 5;
            romaNumeral['X' - 'A'] = 10;
            romaNumeral['L' - 'A'] = 50;
            romaNumeral['C' - 'A'] = 100;
            romaNumeral['D' - 'A'] = 500;
            romaNumeral['M' - 'A'] = 1000;

            //Initializing a variable to store the decimal equivalent
            size_t decVal = 0;

            //Initializing a variable to hold lenght of the Roman numeral string
            size_t length = romanStr.length();

            //Initializing a variable to hold decimal value of each roman numeral
            size_t currentDecVal = 0;

            //Inspecting each chracter in the string
            for(size_t rep = 0; rep < length; rep++) {

                //Obtaining integer equivalent of the current Roman numeral
                currentDecVal = romaNumeral[ romanStr[rep] - 'A' ];

                //In the case of special subtraction representations by checking two contigous Roman numerals
                if(rep < length - 1 && romaNumeral[ romanStr[rep + 1] - 'A'] > currentDecVal) {

                    //Subtracting the current value from the next value and adding to decimal equivalent
                    decVal += romaNumeral[ romanStr[rep + 1] - 'A'] - currentDecVal;

                    //Moving on with the two next character (by incrementing rep two times)
                    rep++;  
                }

                //In the case of non-special combinations
                else {

                    //Adding current decimal value 
                    decVal += currentDecVal;
                }
            }

            //Returning decimal equivalent
            return decVal;         
        }
};
