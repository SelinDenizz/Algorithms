/* Solution for Valid Parantheses problem in Leetcode
 * which determines whether provided string includes
 * same type open-close parantheses forms recursively.
 * Runtime - complexity: O(n)
 * Space - compexity: O(n)
 */

//Linking external header files
#include <iostream>

class Solution {

    //Public methods
    public:

        //Balanced brackets checking wrapper method
        bool isValid(const std :: string& str) {

            //Initializing a variable which indicates first character (start point)
            size_t startIdx = 0; 

            //Initializing a variable which indicates length of the string
            size_t size = str.length();

            //Calling the helper method
            return isValidHelper(str, size, startIdx);
        }
    
    //Private methods
    private:

        //Balanced brackets checking method
        bool isValidHelper(const std :: string& str, size_t& size, size_t& idx) {

            //In the case of reaching string's end
            if (idx == size) {

                //Return statement
                return true;
            }

            //In the case of obtained open bracket is (
            if (str[idx] == '(') {
                
                //In the case of next closing parantheses does not match
                if(str[idx + 1] != ')') {

                    //Termination
                    return false;
                }

                //In the case of next closing parantheses matches
                else {

                    //Updating index variable
                    idx += 2;

                    //Recursive call to control next two contigous characters b
                    return isValidHelper(str, size, idx);
                }
            }

            //In the case of obtained open bracket is {
            else if(str[idx] == '{') {
                
                //In the case of next closing parantheses does not match
                if(str[idx + 1] != '}') {

                    //Termination
                    return false;
                }

                //In the case of next closing parantheses matches
                else {

                    //Updating index variable
                    idx += 2;

                    //Recursive call to control next two contigous characters b
                    return isValidHelper(str, size, idx);
                }
            }
            
            //In the case of obtained open bracket is [
            else if(str[idx] == '[') {
                
                //In the case of next closing parantheses does not match
                if(str[idx + 1] != ']') {

                    //Termination
                    return false;
                }

                //In the case of next closing parantheses matches
                else {

                    //Updating index variable
                    idx += 2;

                    //Recursive call to control next two contigous characters b
                    return isValidHelper(str, size, idx);
                }
            }
            
            //In the case of invalid character
            else {

                //Termination
                return false;
            }
        }
};
