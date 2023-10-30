/* Template selection sort class that provides special methods
 * to sort a templated data structure (array, vector, doubly linked list)
 * by utilizing selection sort algorithm and print sorted data structure
 * O(n^2)
 */

//Linking other header files
#include <iostream>
#include <vector>
#include <algorithm>
#include <type_traits>
#include <stdexcept>

//Class declaration for Selection Sort
template <typename T>
class SelectionSort {

    //Private attributes
    private:

        //Reference to data structure to be sorted
        T& data_;

        //Size of data structure
        size_t size_;

    //Public methods
    public:

        //Constructor that obtains data structure to be sorted as reference and assigns as a member variable
        SelectionSort(T& data, size_t size) : data_(data), size_(size) {}

        //Method to determine whether data type is compatible (array) with the method selectionSortArrAndVecImp()
        void selectionSortArr() {

            //Determining whether provided data type is array, otherwise throwing an exception by compile time assertion
            static_assert(std :: is_array <T> :: value, "Provided data type must be an array to call this method");

            //Calling the implementation method
            selectionSortArrAndVecImp();
        }

        //Method to determine whether data type is compatible (vector) with the method selectionSortArrAndVecImp()
        void selectionSortVec() {

            //Determining whether provided data type is vector, otherwise throwing an exception by compile time assertion
            static_assert(std :: is_same <T, std :: vector <typename T :: value_type> > :: value, "Provided data type must be a vector to call this method");

            //Calling the implementation method
            selectionSortArrAndVecImp();
        }

        //Method to determine whether data type is compatible (array) with the method minMaxSelectionSortArrAndVecImp()
        void minMaxSelectionSortArr() {

            //Determining whether provided data type is array, otherwise throwing an exception by compile time assertion
            static_assert(std :: is_array <T> :: value, "Provided data type must be an array to call this method");

            //Calling the implementation method
            minMaxSelectionSortArrAndVecImp();
        }

        //Method to determine whether data type is compatible (vector) with the method minMaxSelectionSortArrAndVecImp();
        void minMaxSelectionSortVec() {

            //Determining whether provided data type is vector, otherwise throwing an exception by compile time assertion
            static_assert(std :: is_same <T, std :: vector <typename T :: value_type> > :: value, "Provided data type must be a vector to call this method");

            //Calling the implementation method
            minMaxSelectionSortArrAndVecImp();
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
        void selectionSortArrAndVecImp() {

            //Initializing a variable to hold min element in the unordered part that will be swapped later
            int minElIdx = 0;

            //Traversing through list by starting to compare first element of the array/vector
            for(int elToSwapIdx = 0; elToSwapIdx < size_ - 1 ; elToSwapIdx++) {

                //Initializing minimum element index in the unordered part as element that will be swapped
                minElIdx = elToSwapIdx;

                //Traversing through unsorted (remaining after latest elToSwapIndx element) part to find min element
                for(int otherElIdx = elToSwapIdx + 1; otherElIdx < size_ ; otherElIdx++ ) {
                    
                    //Comparing elements after element that will be swapped
                    if(data_[otherElIdx] < data_[minElIdx]) {

                        //In the case of finding an element less than compared element, assigning its index as new min index
                        minElIdx = otherElIdx;
                    }
                }

                //In the case of an element less than compared one found
                if(minElIdx != elToSwapIdx) {

                    //Swapping elements
                    std :: swap(data_[minElIdx], data_[elToSwapIdx]);
                }
            }
        }

        //Variation of selection sort method for array and vectors 
        void minMaxSelectionSortArrAndVecImp() {

            //Initializing a variable to hold min element in the unordered part that will be swapped later
            int minElIdx = 0;

            //Initializing a variable to hold max element in the unordered part that will be swapped later
            int maxElIdx = 0;

            //Traversing through list by starting to compare first element and last of the array/vector
            for(int frontElToSwapIdx = 0, backElToSwapIdx = size_ - 1; frontElToSwapIdx < backElToSwapIdx ; frontElToSwapIdx++, backElToSwapIdx--) {

                //Initializing minimum element index in the unordered part as element that will be swapped
                minElIdx = frontElToSwapIdx;

                //Initializing maximum element index in the unordered part as element that will be swapped
                maxElIdx = frontElToSwapIdx;

                //Traversing through unsorted (middle part between front and back indices) part to find min and max element
                for(int otherElIdx = frontElToSwapIdx; otherElIdx <= backElToSwapIdx; otherElIdx++) {
                    
                    //In the case of finding an element greater than compared element
                    if(data_[otherElIdx] > data_[maxElIdx]) {

                        //Assigning its index as new max index
                        maxElIdx = otherElIdx;
                    }

                    //In the case of finding an element less than compared element
                    else if(data_[otherElIdx] < data_[minElIdx]) {

                        //Assigning its index as new min index
                        minElIdx = otherElIdx;
                    }
                }

                //Swapping the element with the minimum value (found during the current pass)
                std :: swap(data_[minElIdx], data_[frontElToSwapIdx]);

                //Determining whether the maximum value index coincides with the element that was just swapped
                if (maxElIdx == frontElToSwapIdx) {

                    //Updating the maximum value index to the new location of the previously swapped element
                    maxElIdx = minElIdx;
                }

                //Ensuring maximum element is swapped to the back of the unsorted portion
                std :: swap(data_[maxElIdx], data_[backElToSwapIdx]);
            }         
        }
};

/*Driver test code
int main() {

    //Sorting an array of integers using Selection Sort
    int arr[] = {64, 25, 12, 22, 11};
    size_t arrSize = sizeof(arr) / sizeof(arr[0]);
    SelectionSort<int[5]> selectionSortArrInstance(arr, arrSize);
    selectionSortArrInstance.selectionSortArr();  // Selection Sort for arrays
    selectionSortArrInstance.printSorted();  // Print the sorted array

    //Sorting a vector of doubles using Min-Max Selection Sort
    std::vector<double> vec = {1, 4, 7, 9, 10, 3, 22};
    SelectionSort<std::vector<double>> minMaxSelectionSortVecInstance(vec, vec.size());
    minMaxSelectionSortVecInstance.minMaxSelectionSortVec();  // Min-Max Selection Sort for vectors
    minMaxSelectionSortVecInstance.printSorted();  // Print the sorted vector


    return 0;
}
*/
