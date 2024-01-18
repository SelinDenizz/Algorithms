/* Template merge sort class that provides special methods
 * to sort a templated data structure (array, vector)
 * by utilizing merge sort algorithm and print sorted data structure
 * Time complexity: O(nlogn)
 */

//Linking other header files
#include <iostream>
#include <vector>
#include <type_traits>
#include <stdexcept>

//Class declaration for MergeSort
template <typename T>
class MergeSort {

    //Private attributes
    private:

        //Reference to data structure to be sorted
        T& data_;

        //Size of data structure
        size_t size_;

    //Public methods
    public:

        //Constructor that obtains data structure to be sorted as reference and assigns as a member variable
        MergeSort(T& data, size_t size) : data_(data), size_(size) {}

        //Method to determine whether data type is compatible (array) with the method mergeSortArrAndVecImp
        void genericMergeSortArr() {

            //Determining whether provided data type is array, otherwise throwing an exception by compile time assertion
            static_assert(std :: is_array <T> :: value, "Provided data type must be an array to call this method");

            //Calling the implementation method
            genericMergeSortArrAndVecImp(0, size_ - 1);
        }

        //Method to determine whether data type is compatible (vector) with the method mergeSortArrAndVecImp
        void genericMergeSortVec() {

            //Determining whether provided data type is vector, otherwise throwing an exception by compile time assertion
            static_assert(std :: is_same <T, std :: vector <typename T :: value_type> > :: value, "Provided data type must be a vector to call this method");

            //Calling the implementation method
            genericMergeSortArrAndVecImp(0, size_ - 1);
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

        //Method to sort array and vectors by merge sort
        void genericMergeSortArrAndVecImp(size_t low, size_t high) {

            //Stopping condition
            if(low >= high) {

                //Return statement
                return;
            }

            //In the case of there are elements between low and high positions of array/vector
            else {

                //Obtaining mid element for seperation
                size_t mid = (low + high) / 2;

                //Dividing subarrays or partial vectors until one element remained
                genericMergeSortArrAndVecImp(low, mid);
                genericMergeSortArrAndVecImp(mid + 1, high);

                //Merging elements starting by last element remained
                genericMergeArrAndVec(low, mid, high);
            }
        }

        //Method to merge subarrays or partial vectors
        void genericMergeArrAndVec(size_t low, size_t mid, size_t high) {

            //Obtaining size of subarrays
            size_t const sizeLeftSub = mid - low + 1;
            size_t const sizeRightSub = high - mid;

            //Crating template arrays dynamically
            auto *leftSub = new size_t[sizeLeftSub];
            auto *rightSub = new size_t[sizeRightSub];

            //Copying data to template left subarray
            for(auto idx = 0; idx < sizeLeftSub; idx++) {

                //Transferring copies
                leftSub[idx] = data_[low + idx];
            }

            //Copying data to template right subarray
            for(auto idx = 0; idx < sizeRightSub; idx++) {

                //Transferring copies
                rightSub[idx] = data_[mid + 1 + idx];
            }

            //Initializing indices of subarrays to traverse
            auto idxLeftSub = 0;
            auto idxRightSub = 0;

            //Making a copy of low index that belongs to array/vector to be merged
            size_t idxMerged = low;

            //Merging the subarrays 
            while(idxLeftSub < sizeLeftSub && idxRightSub < sizeRightSub) {
                
                //In the case of element in the left subarray is lesser
                if(leftSub[idxLeftSub] <= rightSub[idxRightSub]) {
                    
                    //Transferring that element to the merged data array
                    data_[idxMerged] = leftSub[idxLeftSub];

                    //Updating left subarray index 
                    idxLeftSub++;
                }

                //In the case of element in the right subarray is lesser
                else {

                    //Transferring that element to the merged data array
                    data_[idxMerged] = rightSub[idxRightSub];

                    //Updating left subarray index 
                    idxRightSub++;
                }

                //Updating the index of the element that will be compared with left and right subarrays in the data_
                idxMerged++;
            }


            //In the case of any remaining element in the leftSub
            while (idxLeftSub < sizeLeftSub) {

                //Copying its elements to the merged array
                data_[idxMerged] = leftSub[idxLeftSub];

                //Updating indices
                idxLeftSub++;
                idxMerged++;
            }
        
            //In the case of any remaining element in the rightSub
            while (idxRightSub < sizeRightSub) {

                //Copying its elements to the merged array
                data_[idxMerged] = leftSub[idxRightSub];

                //Updating indices
                idxRightSub++;
                idxMerged++;
            }

            //Deallocating reserved memories
            delete[] leftSub;
            delete[] rightSub;
        }
};

/* Driver test code
int main() {
    // Test sorting an array
    int arr[] = {12, 11, 13, 5, 6, 7};
    size_t arrSize = sizeof(arr) / sizeof(arr[0]);

    MergeSort<int[6]> arrSorter(arr, arrSize);
    arrSorter.genericMergeSortArr();
    std::cout << "Sorted Array: ";
    arrSorter.printSorted();

    // Test sorting a vector
    std::vector<int> vec = {12, 11, 13, 5, 6, 7};
    size_t vecSize = vec.size();

    MergeSort<std::vector<int>> vecSorter(vec, vecSize);
    vecSorter.genericMergeSortVec();
    std::cout << "Sorted Vector: ";
    vecSorter.printSorted();

    return 0;
}
*/
