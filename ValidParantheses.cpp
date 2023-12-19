/* Solution for Valid Parantheses problem in Leetcode
 * which determines whether provided string includes
 * same type open-close parantheses forms.
 * Runtime - complexity: O(n)
 * Space - compexity: O(n)
 */

//Linking external header files
#include <iostream>

class Solution {

    //Public methods
    public:

        //Balanced and matched brackets checking  method
        bool isValid(const std :: string& str) {

            //Initializing variable to track open paranthesis
            std :: string openPs = "";
            
            //Iterating through each character of the string
            for (char ch : str) {

                //In the case of extracted character is an open bracket
                if (ch == '(' || ch == '{' || ch == '[') {

                    //Updating open parantheses list
                    openPs.push_back(ch);
                } 
                
                //Otherwise
                else {

                    //In the case of number of open brackets become 0 or case of unmatching brackets
                    if (openPs.empty() || !isMatchingPair(ch, openPs.back())) {

                        //Termination
                        return false;
                    }

                    //Removing the last open parantheses since a closed parantheses obtained
                    openPs.pop_back();
                }
            }

            //In the case of balanced string
            return openPs.empty();
        }
    
    //Private methods
    private:

        //Matching controlling method for the forms (),[],{}
        bool isMatchingPair(const char& close, const char& open) {

            //Determining whether the last open parenthesis matches the current closing parenthesis
            return (close == ')' && open == '(') ||
                   (close == '}' && open == '{') ||
                   (close == ']' && open == '[');
        }
};
