/* Solution to Binary Tree Level Order Traversal problem in Leetcode
 * Runtime - complexity: O(n)
 * Space - complexity: O(n)
 */

//Linking external header files
#include <iostream>

class Solution {

    //Public methods
    public:

        //Wrapper method to initiate the level order traversal
        std :: vector<std :: vector<int>> levelOrder(TreeNode* root) {

            //Initializing a vector to hold extracted nodes
            std :: vector<std :: vector<int>> extractedNodes;

            //Calling the recursive helper method
            levelOrderHelper(root, 0, extractedNodes); 

            //Returning extracted ndoes 
            return extractedNodes;
        }

    //Private methods
    private:

        //Recursive helper method for level order traversal
        void levelOrderHelper(TreeNode* root, const int& level, std :: vector<std :: vector<int>>& extractedNodes) {

            //In the case of the extracted node is nullptr
            if(root == nullptr) {

                //Termination
                return;  
            }

            //In the case extracted nodes vector size is not enough for the current level
            if(extractedNodes.size() <= level) {

                //Expanding size of the extracted nodes vector
                extractedNodes.push_back(std :: vector<int>());
            }

            //Adding the current node's value to the extracted nodes vector
            extractedNodes[level].push_back(root -> val);

            //Searching for the left and right subtrees recursively, with the next level 
            levelOrderHelper(root -> left, level + 1, extractedNodes);
            levelOrderHelper(root -> right, level + 1, extractedNodes);
        }
};
