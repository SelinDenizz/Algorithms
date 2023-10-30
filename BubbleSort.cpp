/* Template bubble sort class that provides special methods
 * to sort a templated data structure (array, vector, linked list, doubly linked list)
 * by utilizing bubble sort algorithm and print sorted data structure
 * Time complexity: O(n^2)
 */

//Linking other header files
#include <iostream>
#include <vector>
#include <type_traits>
#include <list>
#include <forward_list>
#include <stdexcept>

//Class declaration for BubbleSort
template <typename T>
class BubbleSort {

    //Private attributes
    private:

        //Reference to data structure to be sorted
        T& data_;

        //Size of data structure
        size_t size_;
    
    //Public methods
    public:

        //Constructor that obtains data structure to be sorted as reference and assigns as a member variable
        BubbleSort(T& data, size_t size) : data_(data), size_(size) {}

        //Method to determine whether data type is compatible (array) with the method bubbleSortArrAndVecImp
        void bubbleSortArr() {

            //Determining whether provided data type is array, otherwise throwing an exception by compile time assertion
            static_assert(std :: is_array <T> :: value, "Provided data type must be an array to call this method");

            //Calling the implementation method
            bubbleSortArrAndVecImp();
        }

        //Method to determine whether data type is compatible (vector) with the method bubbleSortArrAndVecImp
        void bubbleSortVec() {

            //Determining whether provided data type is vector, otherwise throwing an exception by compile time assertion
            static_assert(std :: is_same <T, std :: vector <typename T :: value_type> > :: value, "Provided data type must be a vector to call this method");

            //Calling the implementation method
            bubbleSortArrAndVecImp();
        }

        //Method to determine whether data type is compatible (linked list) with the method bubbleSortLinkedList
        void bubbleSortDoublyLinkedList() {

            //Creating alias for node of linked list
            using NodeT = typename T::value_type;

            //Ensuring the provided data type is a doubly linked list
            static_assert( std :: is_same <T, std :: list<NodeT> > :: value, "Provided data type must be a linked list to call this method");

            //Calling the implementation method for doubly linked list
            bubbleSortDoublyLinkedListImp();
        }

        //Method to determine whether data type is compatible (forward list) with the method bubbleSortForwardListImp
        void bubbleSortForwardList() {

            //Ensuring the provided data type is a linked list
            static_assert(std :: is_same <T, std :: forward_list <typename T :: value_type> > :: value, "Provided data type must be a forward list to call this method");

            //Calling the implementation method for linked list
            bubbleSortForwardListImp();
        }

        //Method to print sorted data structure
        void printSorted() {

            //Iterating over each element
            for (const auto& element : data_) {

                //Printing each element
                std :: cout << element << " ";
            }

            //Adding a break line
            std :: cout << std :: endl;
        }

    //Private methods
    private:

        //Sorting method for array and vectors 
        void bubbleSortArrAndVecImp() {

            //Tracking variable to break earlier if array or vector already sorted by checking any swap made
            bool anySwap;

            //Traversing through data structure 
            for(int rep = size_; rep > 0; rep-- ) {

                //Setting tracking variable for earlier termination in the case of no swap remaining part of the data structure
                anySwap = false;

                //Iteratively comparing sequenced elements
                for(int firstEl = 0; firstEl <= size_ - 2; firstEl++) {

                    //Variable to track next element to be compared with first element
                    int nextEl = firstEl + 1;

                    //Comparing first and next element
                    if(data_[firstEl] > data_[nextEl]) {

                        //Swapping elements
                        std :: swap(data_[firstEl], data_[nextEl]);

                        //Setting tracking variable as True
                        anySwap = true;
                    }
                }

                //If no swap made in the remaining part of the data structure
                if(anySwap == false) {

                    //Terminating sort operation
                    break;
                }
            }
        }

        //Sorting method for doubly linked list
        void bubbleSortDoublyLinkedListImp() {

            //Creating alias for node of linked list
            using NodeT = typename T :: value_type;

            //Tracking variable to break earlier if array or vector already sorted by checking any swap made
            bool anySwap;

            //Determining whether list is empty or only has one element
            if(size_ == 0 || size_ == 1) {

                //Informing user
                std :: cout << "List is already sorted." << std :: endl;
            }

            //Proceeding traverse until no swap made in an iteration
            do {

                //Setting swap flag as none
                anySwap = false;

                //Commencing to traverse from first node of linked list
                auto iterator = data_.begin();

                //Initializing a variable to point next element
                auto nextIterator = std :: next(iterator);

                //Traversing the list
                while (nextIterator != data_.end()) {

                    //In the case of element is bigger than next element
                    if(*iterator > *nextIterator) {

                        //Swapping current node's data with next node's data
                        std :: swap(*iterator, *nextIterator);

                        //Setting the swap flag to true, indicating a swap was made
                        anySwap = true;
                    }

                    //Moving to the next element
                    iterator++;
                    nextIterator++;
                }
                
            } while(anySwap);
        }

        //Sorting method for linked list (forward list)
        void bubbleSortForwardListImp() {
            
            //Tracking variable to break earlier if array or vector already sorted by checking any swap made
            bool anySwap;

            //Determining whether list is empty or only has one element
            if(size_ == 0 || size_ == 1) {

                //Informing user
                std :: cout << "List is already sorted." << std :: endl;
            }

            //Proceeding traverse until no swap made in an iteration
            do {

                //Setting swap flag as none
                anySwap = false;

                //Commencing to traverse from first node of linked list
                auto current = data_.begin();

                //Initializing a variable to point next element
                auto next = std :: next(current);

                //Initializing a variable to hold previous element
                auto prev = data_.before_begin();

                //Traversing the list
                while (next != data_.end()) {

                    //In the case of element is bigger than next element
                    if(*current > *next) {

                        //Swapping current node's data with next node's data
                        std :: swap(*current, *next);

                        //Setting the swap flag to true, indicating a swap was made
                        anySwap = true;
                    }

                    //Moving to the next element
                    ++current; 
                    ++next;
                    ++prev; 
                }

            } while(anySwap);
        }
};

//Test Driver code
//int main() {

    //Example with an array
    //int arr[] = {64, 34, 25, 12, 22, 11, 90};
    //BubbleSort<int[7]> arrSorter(arr, 7);

    //Sort the array
    //arrSorter.bubbleSortArr();

    //Print the sorted array
    //std::cout << "Sorted Array: ";
    //arrSorter.printSorted();

    //Example with a vector
    //std::vector<int> vec = {64, 34, 25, 12, 22, 11, 90};
    //BubbleSort<std::vector<int> > vecSorter(vec, vec.size());

    //Sort the vector
    //vecSorter.bubbleSortVec();

    //Print the sorted vector
    //std::cout << "Sorted Vector: ";
    //vecSorter.printSorted();

    //Example with a linked list (std::list)
    //std::list<int> myList = {64, 34, 25, 12, 22, 11, 90};
    //BubbleSort<std::list<int> > listSorter(myList, myList.size());

    //Sort the linked list
    //listSorter.bubbleSortDoublyLinkedList();

    //Print the sorted linked list
    //std::cout << "Sorted Linked List: ";
    //listSorter.printSorted();

    //Example with a forward list (std::forward_list)
    //std::forward_list<int> forwardList = {64, 34, 25, 12, 22, 11, 90};
    //BubbleSort<std::forward_list<int>> forwardListSorter(forwardList, std::distance(forwardList.begin(), forwardList.end()));
    
    //Sort the forward list
    //forwardListSorter.bubbleSortForwardList();
    
    //Print the sorted forward list
    //std::cout << "Sorted Forward List: ";
    //forwardListSorter.printSorted();

    //Return statement
    //return 0;
//}

