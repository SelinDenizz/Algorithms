/* Solution to Add Two Numbers problem in Leetcode
 * Runtime - complexity: O(max(a,b)) where a and b are size of the lists
 * Space - complexity: O(max(a,b)) where a and b are size of the lists
 */
class Solution {

    //Public methods
    public:

        //Method to sum elements of two linked list
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            
            //Initializing the final linked list's head to nullptr
            ListNode* final = nullptr; 

            //Initializing a pointer to a pointer for iterating through final list
            ListNode** current = &final;   

            //Initializing a variable to hold carry
            int carry = 0;   

            //Initializing a variable to hold sum
            int sum = 0;               

            //In the case of there are digits in either l1, l2, or there is a carry
            while(l1 || l2 || carry) {  

                //Assigning carry to the sum
                sum = carry;  

                //In the case of there is an element in the linked list 1
                if(l1) {

                    //Adding the value in the l1 to the sum
                    sum += l1 -> val;  

                    //Moving to next digit
                    l1 = l1 -> next;             
                }

                //In the case of there is an element in the linked list 2
                if(l2) {

                    //Adding the value in the l2 to the sum
                    sum += l2 -> val;    
                    
                    //Moving to next digit        
                    l2 = l2 -> next;              
                }

                //Updating the carry for the next iteration
                carry = sum / 10;      

                //Creating a new node with the result of the addition
                *current = new ListNode(sum % 10);  

                //Moving the pointer in the final linked list
                current = &((*current) -> next); 
            }

            //Returning final linked list
            return final;                      
        }
};
