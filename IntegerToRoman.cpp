/* Solution for integer to Roman numeral problem in Leetcode
 * Runtime - complexity: O(1),
 * Space - complexity: O(1).
 */

//Including external header files
#include <string>

class Solution {

    //Public methods
    public:

        //Conversion method for Roman numeral string representation of integers
        string intToRoman(size_t num) {
            
        //Initializing arrays for Roman numeral symbols and their corresponding values
        string romSymbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        size_t romVals[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

        //Initializing a variable to hold Roman Numeral form
        string romRep = "";

        //Initializing variable to hold number of occurence each Roman symbol 
        size_t countOcc = 0;

        //Inspecting each Roman numeral symbol
        for(size_t rep = 0; rep < 13; rep++) {

            //Counting the number of occurence by division where remainder is # of occurence
            countOcc = num / romVals[rep];

            //Appending the symbol to the roman representation string count times
            for (size_t repIn = 0; repIn < countOcc; repIn++) {
                romRep += romSymbols[rep];
            }

            //Updating the remaining number
            num %= romVals[rep];
        }

        //Returning roman form
        return romRep;
    }
};
