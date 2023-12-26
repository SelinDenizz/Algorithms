/* Solution for Design Circular Queue problem in Leetcode
 * 
 * Runtime Complexity:
 *
 *   - Constructor (MyCircularQueue): O(1)
 *   - Copy Constructor: O(n) where n is the capacity of the queue
 *   - Assignment Operator Overload: O(n) where n is the capacity of the queue
 *   - isEmpty: O(1)
 *   - isFull: O(1)
 *   - enQueue: O(1)
 *   - deQueue: O(1)
 *   - Front: O(1)
 *   - Rear: O(1)
 *   - Destructor: O(1)
 * 
 * Space Complexity:
 *
 *   - Constructor (MyCircularQueue): O(k) where k is the capacity of the queue
 *   - Copy Constructor: O(n) where n is the capacity of the queue
 *   - Assignment Operator Overload: O(n) where n is the capacity of the queue
 *   - isEmpty: O(1)
 *   - isFull: O(1)
 *   - enQueue: O(1)
 *   - deQueue: O(1)
 *   - Front: O(1)
 *   - Rear: O(1)
 *   - Destructor: O(1)
 */

//Linking external header file
#include <iostream>
#include <algorithm> 

class MyCircularQueue {

    //Private attributes
    private:

        //Defining a pointer to dynamically allocate an array for storing queue elements
        int* elements; 

        //Defining front element's index
        int front;     
        
        //Defining rear element's index
        int rear;        

        //Defining queue's size
        int size;       

        //Defining maximum capacity of the queue
        int capacity;    

    //Public methods
    public:

        //Constructor to initialize the circular queue
        MyCircularQueue(const int& k) : 
            elements(new int[k]), 
            front(-1), 
            rear(-1), 
            size(0), 
            capacity(k) { }

        //Copy constructor
        MyCircularQueue(const MyCircularQueue& other) : 
            front(other.front),    
            rear(other.rear),     
            size(other.size),      
            capacity(other.capacity) {  

                //Allocating memory for the circular queue
                elements = new int[capacity];  

                //Copying elements from the other object's elements array to this object's elements array
                std :: copy(other.elements, other.elements + capacity, elements);  
        }
        
        //Assignment operator overload
        MyCircularQueue& operator=(const MyCircularQueue& other) {

            //Checking self-assignment
            if (this != &other) { 

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

        //Method to determine whether the circular queue is empty
        bool isEmpty() {

            //In the case of the size is 0 (default value), returning 1
            return size == 0;  
        }

        //Method to determine whether the circular queue is full
        bool isFull() {

            //In the case of the size equal to the maximum capacity, returning 1
            return size == capacity;  
        }

        //Method to enqueue an element 
        bool enQueue(int value) {
            
            //In the case of the queue is full
            if (isFull()) {

                //Termination
                return false; 
            }

            //In the case of the queue is empty
            if (isEmpty()) {

                //Setting the front index as 0
                front = 0;  
            }

            //Incrementing rear index 
            rear = (rear + 1) % capacity;

            //Inserting the value at the rear index
            elements[rear] = value;   

            //Incrementing the size of the queue
            size++;                        

            //In the case of the enqueue operation was successful
            return true;  
        }
        
        //Method to dequeue an element from queue
        bool deQueue() {
            
            //In the case of the queue is empty
            if (isEmpty()) {

                //Dequeue operation is not possible
                return false;
            }

            //In the case of only one element is in the queue
            if (front == rear) {

                //Resetting front and rear indices
                front = -1;  
                rear = -1;
            } 
            
            //Otherwise
            else {

                //Incrementing front index 
                front = (front + 1) % capacity;  
            }

            //Decrementing the size of the queue
            size--;  

            //In the case of the dequeue operation was successful
            return true;  
        }
        
        //Method to obtain front element of the circular queue
        int Front() {
            
            //In the case of the queue is empty
            if (isEmpty()) {

                //Return
                return -1;  
            }

            //Returning the front element
            return elements[front];  
        }
        
        //Method to obtain rear element of the circular queue
        int Rear() {
            
            //In the case of the queue is empty
            if (isEmpty()) {

                //Return
                return -1;  
            }

            //Returning the front element
            return elements[rear];  
        }

        //Destructor to deallocate reserved memory
        ~MyCircularQueue() {

            //DDeleting queue
            delete[] elements;
        }
};
