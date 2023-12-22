/* Solution for Valid Anagram problem in Leetcode
 * Runtime - complexity: O(n)
 * Space - complexity: O(1)
 */

//Linking external header files
#include <iostream>
#include <unordered_map>
#include <string>

class Solution {

    //Public methods
    public:

        //Method to determine whether provided strings are anagrams
        bool isAnagram(const string& s, const string& t) {
            
            //Determining lengths of both strings
            int sizeS = s.length();
            int sizeT = t.length();
            
            //Determining whether the length of arrays are same
            if(sizeS != sizeT) {

                //Termination
                return false;
            }

            //Initializing a hash table to store frequency of characters
            std :: unordered_map <char, int> occurence;

            //Obtaining occurences of each character in string s
            for(char ch : s) {

                //Incrementing occurence of related character
                occurence[ch]++;
            }

            //Decreasing occurence to detect extra or non-existent characters in string t
            for (char ch : t) {

                //Decrementing occurence
                occurence[ch]--;

                //In the case of t does not have a character that present in s or has extra occurence for same character
                if (occurence[ch] < 0) {

                    //Returning false
                    return false;
                }
            }

            //In the case of all characters are identical in both strings
            return true;
        }
};
