/* Solution for Merge Sorted Array problem of Leetcode
 * which merges two vectors.
 * Runtime - complexity: O(m + n), m and n are the size of the vectors
 * Space - complexity: O(1)
 */

//Linking external header files
#include <iostream>
#include <vector>

class Solution {

    //Public methods
    public:

        //Merge method
        void merge(vector <int>& nums1, int m, vector <int>& nums2, int n) {
            
            //Initializing indices to iterating through vectors from the end to embed shifting operation
            size_t idxNums1 = m - 1;
            size_t idxNums2 = n - 1;
            size_t idxMerged = m + n - 1;

            //Initializing a variable to hold current value to be replaced in merged array
            size_t currentVal = 0;

            //Traversing vectors until one of them reaches the beginning
            while(idxNums1 < m && idxNums2 < n) {

                //In the case of element in the nums1 is greater than one in the nums2
                if(nums1[idxNums1] > nums2[idxNums2]) {

                    //Assigning value to be placed, greater element 
                    currentVal = nums1[idxNums1];

                    //Decrementing nums1 index to check previous element later
                    idxNums1--;
                }

                //In the case of element in the nums2 is greater than one in the nums1, or equal
                else {

                    //Assigning value to be placed, greater element 
                    currentVal = nums2[idxNums2];

                    //Decrementing nums2 index to check previous element later
                    idxNums2--;
                }

                //Placing the greater element to nums1
                nums1[idxMerged] = currentVal;

                //Decrementing for placing to the one previous element of nums1
                idxMerged--;
            }

            //In the case of nums1 have remaining element
            while (idxNums1 < m) {

                //Assigning element remained in the nums1
                nums1[idxMerged] = nums1[idxNums1];

                //Decrementing for placing to the one previous element of nums1
                idxMerged--;
                
                //Decrementing nums1 index to check previous element later
                idxNums1--;
            }

            //In the case of nums2 have remaining element
            while (idxNums2 < n) {

                //Assigning element remained in the nums2
                nums1[idxMerged] = nums2[idxNums2];

                //Decrementing for placing to the one previous element of nums2
                idxMerged--;
                
                //Decrementing nums2 index to check previous element later
                idxNums2--;
            }
        }
};
