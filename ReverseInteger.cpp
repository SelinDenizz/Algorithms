/* Solution to Reverse Integer problem in Leetcode
 * Runtime - complexity: O(logn) where n is the number
 * Space - complexity: O(1) where n is the number
 */

//Linking other header files
#include <iostream>
#include <limits>

class Solution {

    //Public methods
    public:

        //Method to reverse an integer number while doing bound checking
        int reverse(int x) {

            //Initializing variables to hold upper and lower bounds of int type
            const int boundMax = std :: numeric_limits<int> :: max();
            const int boundMin = std :: numeric_limits<int> :: min();

            //Initializing a variable to hold resulted reversed number
            int reversedNum = 0;

            //Initializing a varible to hold extracted last digit
            int lastDigit = 0;

            //Itrating through number 
            while(x != 0) {

                //Determining whether there is an overflow before multiplication
                if(reversedNum > boundMax / 10 || reversedNum < boundMin / 10) {

                    //Termination
                    return 0;
                }

                //Updating last digit
                lastDigit = x % 10;

                //Updating the resulted reversed number by adding the last digit of x
                reversedNum = reversedNum * 10 + lastDigit ;

                //Updating number and moving into next digit
                x /= 10;
            }

            //Returning resulted reversed number
            return reversedNum;
        }     
};
