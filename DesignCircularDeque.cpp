/* Solution for Design Circular Deque problem in Leetcode
 * 
 * Runtime Complexity:
 *
 *   - Constructor (MyCircularDeque): O(1)
 *   - Copy Constructor: O(n) where n is the capacity of the deque
 *   - Assignment Operator Overload: O(n) where n is the capacity of the deque
 *   - Move Constructor: O(1)
 *   - Move Assignment Operator Overload: O(1)
 *   - insertFront: O(1)
 *   - insertLast: O(1)
 *   - deleteFront: O(1)
 *   - deleteLast: O(1)
 *   - getFront: O(1)
 *   - getRear: O(1)
 *   - isEmpty: O(1)
 *   - isFull: O(1)
 * 
 * Space Complexity:
 *
 *   - Constructor (MyCircularDeque): O(k) where k is the capacity of the deque
 *   - Copy Constructor: O(n) where n is the capacity of the deque
 *   - Assignment Operator Overload: O(n) where n is the capacity of the deque
 *   - Move Constructor: O(1)
 *   - Move Assignment Operator Overload: O(1)
 *   - insertFront: O(1)
 *   - insertLast: O(1)
 *   - deleteFront: O(1)
 *   - deleteLast: O(1)
 *   - getFront: O(1)
 *   - getRear: O(1)
 *   - isEmpty: O(1)
 *   - isFull: O(1)
 */

//Linking external header file
#include <iostream>
#include <algorithm> 

class MyCircularDeque {

    //Private attributes
    private:

        //Defining a pointer to dynamically allocate an array for storing elements
        int* elements; 

        //Defining front element's index
        int front;     
        
        //Defining rear element's index
        int rear;        

        //Defining queue's size
        int size;       

        //Defining maximum capacity of the circular deque
        int capacity;    

    public:

        //Constructor to initialize the circular deque
        MyCircularDeque(const int& k) : 
            elements(new int[k]), 
            front(-1), 
            rear(-1), 
            size(0), 
            capacity(k) { }
        
        //Copy constructor
        MyCircularDeque(const MyCircularDeque& other) : 
            front(other.front),    
            rear(other.rear),     
            size(other.size),      
            capacity(other.capacity) {  

                //Allocating memory for the circular deque
                elements = new int[capacity];  

                //Copying elements from the other object's elements array to this object's elements array
                std :: copy(other.elements, other.elements + capacity, elements);  
        }

        //Assignment operator overload
        MyCircularDeque& operator=(const MyCircularDeque& other) {

            //Checking self-assignment
            if(this != &other) { 

                //Deallocating existing memory
                delete[] elements;  

                //Copying attributes of other object to the this object
                front = other.front;    
                rear = other.rear;      
                size = other.size;     
                capacity = other.capacity;  

                //Allocating memory for the circular queue
                elements = new int[capacity]; 

                //Copying elements from the other object's elements array to this object's elements array
                std :: copy(other.elements, other.elements + capacity, elements);  
            }

            //Returning a reference to the this object
            return *this;  
        }

        //Move constructor
        MyCircularDeque(MyCircularDeque&& other) noexcept
            : elements(other.elements), 
            front(other.front), 
            rear(other.rear), 
            size(other.size), 
            capacity(other.capacity) {
                
            //Resetting the source object
            other.elements = nullptr;
            other.front = -1;
            other.rear = -1;
            other.size = 0;
            other.capacity = 0;
        }

        //Move assignment operator overload
        MyCircularDeque& operator=(MyCircularDeque&& other) noexcept {

            if(this != &other) {

                //Releasing current resources
                delete[] elements;

                //Transferring ownership
                elements = other.elements;
                front = other.front;
                rear = other.rear;
                size = other.size;
                capacity = other.capacity;

                //Resetting the source object
                other.elements = nullptr;
                other.front = -1;
                other.rear = -1;
                other.size = 0;
                other.capacity = 0;
            }

            //Returning a reference to the this object
            return *this;
        }

        //Method to insert an element at the front of the deque
        bool insertFront(int value) {

            //In the case of a full deque
            if(isFull()) {

                //Termination
                return false; 
            }

            //In the case of a empty deque
            if(isEmpty()) {

                //Updating front and rear indices
                front = 0;  
                rear = 0;
            } 
            
            //Otherwise
            else {

                //Updating front index
                front = (front - 1 + capacity) % capacity;
            }

            //Transferring element to front
            elements[front] = value;   

            //Updating size of the deque
            size++;        

            //In the case of a successfull enqueue                
            return true;  
        }

        //Method to insert an element at the rear of the deque
        bool insertLast(int value) {

            //In the case of a full deque
            if(isFull()) {

                //Termination
                return false; 
            }

            //In the case of a empty deque
            if(isEmpty()) {

                //Updating front and rear indices
                front = 0;  
                rear = 0;
            } 

            //Otherwise
            else {

                //Updating rear index
                rear = (rear + 1) % capacity;
            }

            //Transferring element to rear
            elements[rear] = value;  

            //Updating size of the deque
            size++;        

            //In the case of a successfull enqueue                
            return true;  
        }

        //Method to delete an element from the front of the deque
        bool deleteFront() {

            //In the case of a empty deque
            if(isEmpty()) {

                //Termination
                return false; 
            }

            //In the case of there is a single element in the deque
            if(front == rear) {

                //Updating front and rear indices
                front = -1;  
                rear = -1;
            } 

            //Otherwise
            else {

                //Updating front element
                front = (front + 1) % capacity;
            }

            //Updating size of the deque
            size--;        

            //In the case of a successfull enqueue                
            return true;  
        }

        //Method to delete an element from the rear of the deque
        bool deleteLast() {

            //In the case of a empty deque
            if(isEmpty()) {

                //Termination
                return false; 
            }

            //In the case of there is a single element in the deque
            if(front == rear) {

                //Updating front and rear indices
                front = -1;  
                rear = -1;
            } 
            
            //Otherwise
            else {

                //Updating rear index
                rear = (rear - 1 + capacity) % capacity;
            }

            //Updating size of the deque
            size--;        

            //In the case of a successfull enqueue                
            return true;  
        }

        //Method to obtain the front element of the deque
        int getFront() {

            //In the case of an empty list, returning -1
            return isEmpty() ? -1 : elements[front];  
        }

        //Method to obtain the rear element of the deque
        int getRear() {

            //In the case of an empty list, returning -1
            return isEmpty() ? -1 : elements[rear];  
        }

        //Method to determine whether the deque is empty
        bool isEmpty() {

            //In the case of an empty deque
            return size == 0;  
        }

        //Method to determine whether the deque is full
        bool isFull() {

            //In the case of current size equal to the capacity
            return size == capacity;  
        }

        //Virtual Destructor to deallocate reserved memory
        ~MyCircularDeque() {

            delete[] elements;
        }
};
