/* Solution for Balanced Binary Tree problem in Leetcode
 * Runtime - complexity: O(n), n = # of nodes
 * Space - complexity: O(h), h = height of tree (worst case, skewed tree, h == n)
 */

//Linking external header file
#include <iostream>

class Solution {

    //Public methods
    public:

        //Method to determine whether provided tree is balanced, a.k.a levels of subtrees differ at most by one
        bool isBalanced(TreeNode* root) {
            
            //In the case of helper method detected balanced tree
            if(controlBalance(root) == -1) {

                //Return
                return false;
            }

            //In the case of a balanced binary tree
            return true;
        }
    
    //Private methods
    private:

        //Helper method to determine balanced tree
        int controlBalance(TreeNode* root) {

            //In the case of an empty tree (balanced in that case)
            if (root == nullptr) {

                //Return
                return 0; 
            }

            //Iterating through left subtrees to determine whether they are balanced
            int heightL = controlBalance(root -> left);

            //Iterating through right subtrees to determine whether they are balanced
            int heightR = controlBalance(root -> right);

            //In the case of left subtrees are not balanced
            if (heightR == -1 || heightL == -1) {

                //Return
                return -1; 
            }

            //Determining whether current subtree is balanced
            int difBalance = abs(heightL - heightR);

            //In the case of difference between heights more than 1
            if (difBalance > 1) {

                //Return
                return -1; 
            }

            //Otherwise, returning the height of the current subtree
            return 1 + max(heightL, heightR);
    }
};
