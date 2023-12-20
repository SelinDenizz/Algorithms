/* Solution to Palindrome Number problem in Leetcode by two pointers approach
 * to embed modification of original number
 * Runtime - complexity: O(log10(x))
 * Space - complexity: O(log10(x))
 */

//Linking external header files
#include <iostream>

class Solution {

    //Public methods
    public:

        //Method to determine whether provided number is palindrome
        bool isPalindrome(const size_t& num) {
            
            //In the case of x is negative or ends with 0 (except the case of x == 0)
            if((num < 0) || (num % 10 == 0 && num != 0)) {

                //Return
                return false;
            }

            //Converting number to string
            std :: string str = std :: to_string(num);

            //Initializing pointers which indicates to the end and beginning of the string
            int left = 0;
            int right = str.length() - 1;

            //Determining whether corresponding characters in the left and right are identical
            while (left < right) {

                //In the case of a mismatch
                if (str[left] != str[right]) {

                    //Return
                    return false; 
                }

                //Updating pointers 
                left++;
                right--;
            }

        //In the case of succesfull control
        return true; 
    }
};
