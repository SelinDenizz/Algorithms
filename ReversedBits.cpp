/* 
 * Reversing provided 32-bit unsigned integer
*/

#include<iostream>

class Solution {
    public:

        //Method to reverse 32-bit unsigned integer
        uint32_t reverseBits(uint32_t number) {

            //Initializing the reversed number 
            uint32_t reversedNum = 0;

            //Initializing extracted bit variable
            uint32_t currentBit = 0;

            //Iterating through each bit
            for(size_t rep = 0; rep < 32; rep++) {

                //Obtaining current bit by masking via bitwise AND
                currentBit = (number & 1);

                //Shifting left reversedNum to open a space for extracted digit and appending extracted bit with bitwise OR operation
                reversedNum = (reversedNum << 1) | currentBit;

                //Shifting right to number to be reversed for proceeding with next bit
                number = number >> 1;
            } 

            //Returning reversed number
            return reversedNum;   
        }
};
