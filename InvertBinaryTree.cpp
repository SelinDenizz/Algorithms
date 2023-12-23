/* Solution to Inver Binary Tree problem in Leetcode
 * Runtime - complexity: O(n), n = # of nodes
 * Space - complexity: O(h), h = height of tree (worst case, skewed tree, h == n)
 */

//Linking external header files
#include <iostream>

class Solution {

    //Public methods
    public:

        //Method to invert tree
        TreeNode* invertTree(TreeNode* root) {
            
            //In the case of a empty tree or leaf node
            if (root == nullptr) {

                //Returning nullptr
                return nullptr; 
            }

            //Swapping left and right subtrees
            swapSubtrees(root);

            //Inverting left and right subtrees recursively
            invertTree(root -> left);
            invertTree(root -> right);

            //Returning the root of subtrees 
            return root;
        }

        //Private methods
        private:

            //Method to swap subtrees
            void swapSubtrees(TreeNode* node) {

                //In the case of a empty tree or leaf node
                if (node == nullptr) {

                    //Termination
                    return;
                }

                //Swapping left and right subtrees
                TreeNode* temp = node -> left;
                node -> left = node -> right;
                node -> right = temp;
            }
};
