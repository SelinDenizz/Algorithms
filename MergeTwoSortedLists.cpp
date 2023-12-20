/* Solution for Merge Two Sorted List problem in Leetcode
 * Runtime - complexity: O(a + b), a and b are the lengths of lists
 * Space - complexity: O(1)
 */

//Linking external header files
#include <iostream>

class Solution {

    //Public methods
    public:

        //Singly Lists merging method
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
            
            //In the case of list1 is empty
            if(list1 == nullptr) {

                //Returning other list (if list2 is also empty, it returns empty list)
                return list2;
            }

            //In the case of list2 is empty
            else if(list2 == nullptr) {

                //Returning other list (if list1 is also empty, it returns empty list)
                return list1;
            }

            //Initializing head node of the merged list
            ListNode* headMerged = (list1 -> val < list2 -> val) ? list1 : list2;

            //Initializing pointers to iterate through lists
            ListNode* node1 = headMerged;
            ListNode* node2 = (headMerged == list1) ? list2 : list1;

            //Iterating through both lists
            while (node1 != nullptr && node2 != nullptr) {

                //Controls the insertion of node2 between node1 and its next node in a sorted linked list
                if (node2 -> val >= node1 -> val && (node1 -> next == nullptr || node2 -> val < node1 -> next -> val)) {

                    //Inserting node2 between node1 and node1's next node
                    ListNode* temp = node1 -> next;
                    node1 -> next = node2;
                    node2 = node2 -> next; 
                    node1 -> next -> next = temp;  
                }
                
                //Updating node1 as one next node
                node1 =  node1 -> next;
            }

            //In the case of one list is longer 
            while(node2 != nullptr) {

                //Appending the remaining nodes
                node1 -> next = node2;
                node1 = node1 -> next;
                node2 = node2 -> next;
            }

            //Returning merged list head (list1 or list2)
            return headMerged;
        }
};
