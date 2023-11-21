/* Template quicksort class that provides special methods
 * to sort a templated data structure (array, vector)
 * by utilizing  Hoare's quicksort algorithm and print sorted data structure
 * Time complexity: O(nlogn)
 */

//Linking other header files
#include <iostream>
#include <vector>
#include <type_traits>
#include <stdexcept>

//Class declaration for QuickSort
template <typename T>
class QuickSort {

    //Private attributes
    private:

        //Reference to data structure to be sorted
        T& data_;

        //Size of data structure
        size_t size_;

    //Public methods
    public:

        //Constructor that obtains data structure to be sorted as reference and assigns as a member variable
        QuickSort(T& data, size_t size) : data_(data), size_(size) {}

        //Method to determine whether data type is compatible (array) with the method quickSortArrAndVecImp
        void quickSortArr() {

            //Determining whether provided data type is array, otherwise throwing an exception by compile time assertion
            static_assert(std :: is_array <T> :: value, "Provided data type must be an array to call this method");

            //Calling the implementation method
            quickSortArrAndVecImp();
        }

        //Method to determine whether data type is compatible (vector) with the method quickSortArrAndVecImp
        void quickSortVec() {

            //Determining whether provided data type is vector, otherwise throwing an exception by compile time assertion
            static_assert(std :: is_same <T, std :: vector <typename T :: value_type> > :: value, "Provided data type must be a vector to call this method");

            //Calling the implementation method
            quickSortArrAndVecImp();
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

        //Method to apply quick sort algorithm to arrays and vectors
        void quickSortArrAndVecImp(size_t startIdx = -1, size_t endIdx = -1) {

            //In the case of empty start and end indices
            if(startIdx == -1) {
                 
                //Initializing start index
                startIdx = 0;
            }

            if(endIdx == -1) {

                //Initializing end index
                endIdx = size_ - 1;
            }

            //Base case, where partitioned list has one or fewer element
            if(startIdx >= endIdx) {
                return;
            }

            //Partitioning array/vector which returns new pivot index
            size_t pivotIdx = partition(startIdx, endIdx);

            //Sorting leftsub
            quickSortArrAndVecImp(startIdx, pivotIdx);

            //Sorting rightsub
            quickSortArrAndVecImp(pivotIdx + 1, endIdx);
        }

        //Method to partitionate array/vector 
        size_t partition(size_t low, size_t high) {

            //Initializing pivot element as the first element of the data array
            size_t pivot = data_[low];

            //Initializing pointers to point both subpart of the array
            int lowIdx = low + 1;
            int highIdx = high;

            while(true) {

                //Obtaining index of the leftmost element greater than or equal to pivot element
                while(data_[lowIdx] <= pivot) {

                    //Moving low pointer next element
                    lowIdx++;        
                }

                //Obtaining index of the rightmost element less than pivot element
                while(data_[highIdx] > pivot) {
                    
                    //Moving the high pointer previous element
                    highIdx--;
                }

                //In the case pointers intersected
                if(lowIdx >= highIdx) {

                    //Swapping pivot element with the high index element which holds rightmost element less than pivot element
                    std :: swap(data_[low], data_[highIdx]);

                    //Returning the high index for new partition
                    return highIdx;
                }

                //Swapping pivot element with the high index element which holds rightmost element less than pivot element
                std :: swap(data_[lowIdx], data_[highIdx]);
            }
        }
};

/*Driver Test function
    int main() {
    int arr[] = {5, 3, 1, 4, 2};
    size_t arrSize = sizeof(arr) / sizeof(arr[0]);
    QuickSort<int[5]> arrSorter(arr, arrSize);
    arrSorter.quickSortArr();
    std::cout << "Sorted Array: ";
    arrSorter.printSorted();
    std::vector<int> vec = {5, 3, 1, 4, 2};
    QuickSort<std::vector<int>> vecSorter(vec, vec.size());
    vecSorter.quickSortVec();
    std::cout << "Sorted Vector: ";
    vecSorter.printSorted();
    return 0;
}
*/