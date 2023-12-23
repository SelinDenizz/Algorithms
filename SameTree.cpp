/* Solution for Same problem in Leetcode
 * Runtime - complexity: O(n), n = # of nodes
 * Space - complexity: O(h), h = height of tree (worst case, skewed tree, h == n)
 */

//Linking external header file
#include <iostream>

class Solution {

    //Public methods
    public:

        //Method to determine whether provided trees are identical
        bool isSameTree(TreeNode* p, TreeNode* q) {
            
            //In the case of both nodes are nullptr, they're identical
            if (p == nullptr && q == nullptr) {

                //Return
                return true;
            }

            //In the case one of the nodes is nullptr and the other is not, they're not identical
            if (p == nullptr ^ q == nullptr) {

                //Return
                return false;
            }

            //Determining values of both nodes
            auto valP = p -> val;
            auto valQ = q -> val;

            //In the case of the values are identical
            if (valP == valQ) {

                //Recursively controlling left and right subtrees
                return isSameTree(p -> left, q -> left) && isSameTree(p -> right, q -> right);
            } 
            
            //Otherwise
            else {

                //Trees are not identical
                return false;
            }
        }
};
