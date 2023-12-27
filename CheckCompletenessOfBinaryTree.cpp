/* Solution for Check Completeness of a Binary Tree problem in Leetcode
 * Runtime - complexity: O(n)
 * Space - complexity: O(n)
 */


//Linking external header files
#include <iostream>

class Solution {

    //Public methods
    public:

        //Wrapper method to determine whether provided binay tree is complete
        bool isCompleteTree(TreeNode* root) {
            
            //Calling the helper method with the initial index and total number of nodes
            return isCompleteTreeHelper(root, 1, numOfNodes(root));
        }
    
    private:

        //Helper method to determine number of nodes
        int numOfNodes(TreeNode* node) {

            //In the case of the node is null
            if(node == nullptr){

                //Return
                return 0;
            }
                
            //Counting the nnodes in left and right subtrees recursively
            return 1 + numOfNodes(node -> left) + numOfNodes(node -> right);
        }   

        //Helper method  to determine whether provided binay tree is complete
        bool isCompleteTreeHelper(TreeNode* node, const int& index, const int& totalNodes) {

            //In the case of the node is null 
            if(node == nullptr) {

                //Returning true since it contributes to completeness
                return true;
            }
                

            //In the case of the index exceeds the total number of nodes
            if(index > totalNodes) {

                //Returning false since it is not a complete tree
                return false;
            }        

            //Controlling left and right subtrees with updated indices recursively
            return isCompleteTreeHelper(node -> left, 2 * index, totalNodes) &&
                   isCompleteTreeHelper(node -> right, 2 * index + 1, totalNodes);
        }
};
