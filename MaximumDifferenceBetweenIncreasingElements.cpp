/* Solution for Maximum Difference Between Increasing Elements in Leetcode
 * Runtime - complexity: O(n)
 * Space - complexity: O(1)
 */

//Linking external header files
#include <iostream>
#include <vector>

class Solution {

    //Public methods
    public:

        //MMethod to find nums[i] < nums[j] where 0 <= i < j < n
        int maximumDifference(const vector<int>& nums) {
            
            //Initializing a variable that indicates the size of the vector
            int size = nums.size();

            //In the case of size of the vector less than 2
            if(size < 2) {

                //Return
                return -1;
            }

            //Initializing variables to hold minimum element and maximum difference
            int minEl = nums[0];
            int maxDif = 0;

            //Iterating through vector    
            for(int rep = 0; rep < size; rep++) {

                //Updating maximum difference 
                maxDif = std :: max(maxDif, nums[rep] - minEl);

                //Updating minimum element
                minEl = std :: min(minEl, nums[rep]);
            }

            //Returning max difference
            return (maxDif != 0) ? maxDif: -1;
        }
};
