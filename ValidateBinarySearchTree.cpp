/* Solution for Validate Binary Search Tree problem in Leetcode
 * Runtime - complexity: O(n), n = # of nodes
 * Space - complexity: O(h), h = height of tree (worst case, skewed tree, h == n)
 */

//Importing external header files
#include <iostream>

class Solution {

    //Public methods
    public:

        //Wrapper method to determine whether provided BST is valid
        bool isValidBST(TreeNode* root) {

            //Initiating with default values for the limits via helper method
            return isValidBSTHelper(root, LONG_MIN, LONG_MAX);
        }

    //Private methods
    private:

        //Recursive method to determine whether provided BST is valid
        bool isValidBSTHelper(TreeNode* root, long long limitLow, long long limitUp) {

            //In the case of the provided node is null
            if(root == nullptr) {

                //Valid BST (empty subtree)
                return true;
            }

            //Determining whether the current node's value is within the valid range
            if(root -> val <= limitLow || root -> val >= limitUp) {
                
                //Nonvalid BST
                return false;
            }

            //Checking the left and right subtrees recursively
            return isValidBSTHelper(root -> left, limitLow, root -> val) &&
                   isValidBSTHelper(root -> right, root -> val, limitUp);
        }
};
