/* Solution for Intersection of Two Linked List problem in Leetcode
 * which returns intersection node of two linked lists if there is any,
 * otherwise zero by utilizing two pointer approach.
 * Runtime - complexity: O(a + b), a and b are the lengths of lists
 * Space - complexity:
 */

//Linking external header files
#include <iostream>

class Solution {

    //Public methods
    public:

        //Method to find and return intersection node of two linked list
        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
            
            //Initializing two pointers that indicates heads of linked lists initially
            ListNode* ptrA = headA;
            ListNode* ptrB = headB;

            //Iterating through lists until pointers met
            while (ptrA != ptrB) {

                //In the case listA's pointer reached to the end
                if(ptrA == nullptr) {

                    //Moving it to the head of the other list to ensure that pointers covers a + b length of lists
                    //In the case of different sized lists
                    ptrA = headB;
                }

                //Otherwise
                else {
                    
                    //Preceeding to search with next node
                    ptrA = ptrA -> next;
                }

                //In the case listB's pointer reached to the end
                if(ptrB == nullptr) {

                    //Moving it to the head of the other list
                    ptrB = headA;
                }

                //Otherwise
                else {
                    
                    //Preceeding to search with next node
                    ptrB = ptrB -> next;
                }
            }

            //Returning one of the pointers since each points same node
            if(ptrA != nullptr) {
                return ptrA;
            }

            //In the case of no instercetion is found
            else {
                return 0;
            }   
        }
};
