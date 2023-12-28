/* Solution to Binary Tree Pruning problem in Leetcode
 * Runtime - complexity: O(n)
 * Space - complexity: O(n)
 */

//Linking external header files
#include <iostream>

class Solution {

    //Public methods
    public:

        //Recursive method to prune all the 0 nodes (can be either 1 or 0) in BST except the ones 
        //that have descendant 1
        TreeNode* pruneTree(TreeNode* root) {

            //In the case the root is null
            if(root == nullptr) {

                //Returning null
                return nullptr;
            }

            //Pruning left and right subtrees
            root -> left = pruneTree(root -> left);
            root -> right = pruneTree(root -> right);

            //In the case of the current node is a leaf with value 0
            if (root -> left == nullptr && root -> right == nullptr && root -> val == 0) {

                //Pruning it
                return nullptr;
            }

            //Returning root
            return root;
        }
};
