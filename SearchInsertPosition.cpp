/* Solution for Search Insert Position Leetcode problem
 * which outputs the index of place that target element would be nserted in the provided sorted array
 * Runtime-complexity: O(logn)
 * Space-complexity: O(logn)
 */

//Linking external header files
#include <iostream>

class Solution {

    //Public methods
    public:

        //Insertion index finder method's wrapper
        int searchInsert(const vector <int>& nums, const int& target) {
            
            //Calling helper method
            return searchInsertRec(nums, target, 0, nums.size() - 1);
        }
    
    //Private methods
    private:

        //Insertion index finder method
        int searchInsertRec(const std :: vector<int>& nums, const int& target, int left, int right) {

            //In the case of left index is not less than or equal to the right index
            if (left > right) {

                //Termination
                return left;
            }

            //Calculating mid index
            int mid = (right + left) / 2;

            //In the case of middle element is equal to the target
            if (nums[mid] == target) {

                //Returning mid index as position
                return mid;
            } 
            
            //In the case of mid element is less than target
            else if (nums[mid] < target) {

                //Recursive call for right sub
                return searchInsertRec(nums, target, mid + 1, right);
            } 
            
            //In the case of mid element is greater than target
            else {

                //Recursive call for left sub
                return searchInsertRec(nums, target, left, mid - 1);
            }
        }
};
