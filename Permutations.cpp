/* Solution for Permutation problem in Leetcode
 * Runtime - complexity: O(n.n!)
 * Space - complexity: O(n.n!)
 */

//Linking external header files
#include <iostream>
#include <vector>

class Solution {

    //Public methods
    public:

        //Method to return all the possible permutation  of provided distinct integers
        vector<vector<int>> permute(vector<int>& nums) {
            
            //Initializing vector to store permutations
            std :: vector<std :: vector<int>> permutations;

            //Calling helper method to obtain possible permutations
            permuteHelper(nums, 0, permutations);

            //Returning permutation results
            return permutations;
        }

    //Private methods
    private:

        //Helper method
        void permuteHelper(std :: vector<int>& nums, int start, std :: vector<std :: vector<int>>& generatedPerms) {

            //In the case of exhaustion of array
            if (start == nums.size()) {

                //Updating permutation list wih generated permutations
                generatedPerms.push_back(nums);

                //Termination
                return;
            }

            //Traversing the array starting from the current index
            for (int rep = start; rep < nums.size(); rep++) {

                //Swapping 'start' and 'rep' indexed elements
                std :: swap(nums[start], nums[rep]);

                //Calling the helper method for the next index
                permuteHelper(nums, start + 1, generatedPerms);

                //Undo the swap to backtrack and explore other possibilities
                std :: swap(nums[start], nums[rep]);
            }
        }
};
