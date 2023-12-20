/* Solution for Get Equal Substring Within Budget problem in Leetcode
 * Runtime - complexity: O(n)
 * Space - complexity: O(1)
 */

//Linking external header files
#include <iostream>
#include <vector>

class Solution {

    //Public methods
    public:

        //Method to find maximum cost of changing a character in string str1 via calculating ASCII abs difference
        size_t equalSubstring(string str1, string str2, int maxCost) {

            //Obtaining lengths of strings
            size_t size1 = str1.length();
            size_t size2 = str2.length();

            //In the case length of strings is not equal
            if(size1 != size2) {

                //Termination 
                return 0;
            }

            //Initializing index variable to traverse str 1
            size_t left = 0;

            //Initializing a variable that indicates maximum length of substring that can be changed
            size_t maxLen = 0;

            //Initializing a variable to hold change cost of eachcharacter in str1
            size_t cost = 0;

            //Traversing strings by sliding window technique
            for(size_t right = 0; right < size1; right++) {

                //Calculating ASCII abs difference for current characters (|s[i] - t[i]|) and appending to the total cost
                cost += std :: abs(str1[right] - str2[right]);

                //Determining whether the current cost exceeds the maximum allowed cost
                while(cost > maxCost) {

                    //In the case of an excessive cost
                    cost -= std :: abs(str1[left] - str2[left]);

                    //Updating index of str1
                    left++;
                }

                //Updating max length
                maxLen = std :: max(maxLen, right - left + 1);
            }

            //Returning maximum length
            return maxLen;
        }      
};
