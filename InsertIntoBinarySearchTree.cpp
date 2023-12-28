/* Solution to  Insert into a Binary Search Tree problem in Leetcode
 * Runtime - complexity: O(n)
 * Space - complexity: O(n)
 */

class Solution {

    //Public methods
    public:

        //Wrapper method to insert a value into the BST
        TreeNode* insertIntoBST(TreeNode* root, const int& val) {

            //Initiating insertion by calling helper methods
            return insertIntoHelper(root, val);
        }

    //Private methods
    private:

        //Helper method to insert a value into the BST
        TreeNode* insertIntoHelper(TreeNode* node, const int& val) {

            //In the case of the current node is null
            if(node == nullptr) {

                //Creating a new node with the given value
                return new TreeNode(val);
            }

            //In the case of provided value is less than the current node's value
            if(val < node -> val) {

                //Inserting into the left subtree 
                node -> left = insertIntoHelper(node -> left, val);
            }

            //In the case of provided value is greater than or equal to the current node's value
            else {

                //Inserting into the right subtree
                node -> right = insertIntoHelper(node -> right, val);
            }

            //Returning the modified current node
            return node;
        }
};
