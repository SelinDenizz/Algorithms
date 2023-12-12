/* Template radix sort class that provides special methods
 * to sort a templated data structure (array, vector)
 * by utilizing radix sort algorithm and print sorted data structure.
 * Time complexity: O(d * (n + b)), where
 * d is the number of digits, n is the number of elements, 
 * and b is the base of the number system
 */

//Linking other header files
#include <iostream>
#include <vector>
#include <type_traits>
#include <stdexcept>

//Class declaration for MergeSort
template <typename T>
class RadixSort {

    //Private attributes
    private:

        //Reference to data structure to be sorted
        T& data_;

        //Size of data structure
        size_t size_;

        //Reference to base system of elements in the data structure, default is decimal
        size_t base_;

    //Public methods
    public:

        //Constructor that obtains data structure to be sorted as reference and assigns as a member variable
        RadixSort(T& data, size_t size, size_t base = 10) : data_(data), size_(size), base_(base) {}

        //Method to determine whether data type is compatible (array) with the method radixSortArrAndVecImp
        void radixSortArr() {

            //Determining whether provided data type is array, otherwise throwing an exception by compile time assertion
            static_assert(std :: is_array <T> :: value, "Provided data type must be an array to call this method");

            //Calling the implementation method
            radixSortArrAndVecImp();
        }

        //Method to determine whether data type is compatible (vector) with the method radixSortArrAndVecImp
        void radixSortVec() {

            //Determining whether provided data type is vector, otherwise throwing an exception by compile time assertion
            static_assert(std :: is_same <T, std :: vector <typename T :: value_type> > :: value, "Provided data type must be a vector to call this method");

            //Calling the implementation method
            radixSortArrAndVecImp();
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

        //Method to apply radix sort to array and vectors
        void radixSortArrAndVecImp() {

            //Obtaining largest element in the data structure to specify the number of iteration
            size_t maxEl = obtainMaxEl();

            //Applying counting sort algorithm for every digit place for any base
            for (size_t exp = 1; maxEl / exp > 0; exp *= base_) {
                countingSort(exp);
            }
        }

        //Method to apply counting sort algorithm to arrays and vectors
        void countingSortArrAndVecImp(size_t exponent) {

            //Obtaining maximum element in the list
            size_t maxEl = obtainMaxEl();

            //Creating count array/vector that has the range 0 - max element to track occurences of each element
            T count(maxEl + 1, 0);

            //Obtaining and storing occurences of each element in the provided data structure 
            countOccurences(count, exponent);

            //Obtaining cumulative sums of each element in the count list
            calculateCumSums(count);

            //Creating output list from count list with the same size of original list
            T final(size_);

            //Placing elements to the final list 
            placeElements(final, count);

            //Assigning the final list to data_ list of the object
            std :: copy(final.begin(), final.end(), data_.begin());
        }

        //Method to obtain maximum element in the provided list
        size_t obtainMaxEl() const {

            //Obtaining the greatest element in the array/vector
            size_t maxEl = 0;
            for(const auto& element : data_) {
                
                //In the case of greater element has found
                if(element > maxEl) {

                    //Tracking the greatest element
                    maxEl = element;
                }
            }

            //Returning max element
            return maxEl;
        }

        //Method to track number of occurence each element and record in the 'count' list
        void countOccurences(T& count, size_t exponent) {

            //Initializing digit
            size_t digit;

            //Obtaining and storing occurences of each element in the provided data structure 
            for(const auto& element : data_) {

                //Declaring digit
                digit = (element / exponent) % base_;
                
                //By mapping each element of data_ list as an index of count list
                count[digit]++;
            }
        }

        //Method to calculate cumulative sum of each element in the count list to place the correct indices of elements to output data structure later
        void calculateCumSums(T& count) {
            
            //Traversing through count list which holds number of occurences
            for(size_t rep = 0; rep < count.size(); rep++) {
                count[rep] += count[rep - 1];
            }
        }

        //Method to place elements to the final list
        void placeElements(T& final, T& count) {

            //Declaring variables which refer element to be placed, cumulative sum of the element, and index of the element in the final list consecutively
            size_t elToPlace, cumSumOfEl, idxElToPlace;

            //Traversing from end of the list which helps stability
            for(size_t rep = size_ - 1; rep >= 0; rep--) {

                //Initializing element to place in final list
                elToPlace = data_[rep];

                //Initializing cumulative sum of element to be placed to the final array by searching in count list
                cumSumOfEl = count[elToPlace];

                //Initializing the final list index where element will be placed
                idxElToPlace = cumSumOfEl - 1;

                //Placing the element
                final[idxElToPlace] = elToPlace;

                //Decrementing cumulative sum for stability
                cumSumOfEl--;
            }
        }
};

