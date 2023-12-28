/* Solution to Swap Nodes in Pairs problem in Leetcode
 * Runtime - complexity: O(n)
 * Space - complexity: O(n)
 */

//Importing external header files
#include <iostream>

class Solution {

    //Public methods
    public:

        //Method to swap adjacent pairs of the provided linked list
        ListNode* swapPairs(ListNode* head) {
            
            //In the case of the list is empty or has only one node
            if (head == nullptr || head -> next == nullptr) {

                //No swapping needed
                return head;
            }

            //Saving the first node of the next pair for further processing
            ListNode* nextPairFirstNode = head -> next -> next;

            //Saving the second node of the current pair as the new head
            ListNode* headNew = head -> next;

            //Swapping the first and second elements in the current pair positions
            headNew -> next = head;

            //Swapping the remaining part of the linked list recursively
            head -> next = swapPairs(nextPairFirstNode);

            //Returning the new head of the swapped pairs
            return headNew;
        }
};
