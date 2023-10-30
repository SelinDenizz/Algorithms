/* Template insertion sort class that provides special methods
 * to sort a templated data structure (array, vector)
 * by utilizing bubble sort algorithm adnd print sorted data structure
 * Time complexity: O(n^2)
 */

//Linking other header files
#include <iostream>
#include <vector>
#include <type_traits>
#include <stdexcept>

//Class declaration for Inserion Sort
template <typename T>
class InsertionSort {

    //Private attributes
    private:

        //Reference to data structure to be sorted
        T& data_;

        //Size of data structure
        size_t size_;
    
    //Public methods
    public:

        //Constructor that obtains data structure to be sorted as reference and assigns as a member variable
        InsertionSort(T& data, size_t size) : data_(data), size_(size) {}

        //Method to determine whether data type is compatible (array) with the method InsertionSortArrAndVecImp
        void insertionSortArr() {

            //Determining whether provided data type is array, otherwise throwing an exception by compile time assertion
            static_assert(std :: is_array <T> :: value, "Provided data type must be an array to call this method");

            //Calling the implementation method
            insertionSortArrAndVecImp();
        }

        //Method to determine whether data type is compatible (vector) with the method insertionSortArrAndVecImp
        void insertionSortVec() {

            //Determining whether provided data type is vector, otherwise throwing an exception by compile time assertion
            static_assert(std :: is_same <T, std :: vector <typename T :: value_type> > :: value, "Provided data type must be a vector to call this method");

            //Calling the implementation method
            insertionSortArrAndVecImp();
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

        //Method to apply insertion sort on vectors and arrays
        void insertionSortArrAndVecImp() {
            
            //Iterating through the list provided starting by index 1 (second element)
            for(size_t elToInsert = 1; elToInsert < size_; elToInsert++) {

                //Storing the current element to be inserted into the sorted part of the array or vector
                auto dataToInsert = data_[elToInsert];
                size_t currentIdx = elToInsert;

                //Shifting elements of the sorted part of the array or vector to make space for the current element
                while(currentIdx > 0 && data_[currentIdx - 1] > dataToInsert) {

                    //Shifting the current element to the right
                    data_[currentIdx] = data_[currentIdx - 1];

                    //Updating current index
                    currentIdx--;
                }

                //Inserting the current element into its correct position in the sorted part of the array or vector
                data_[currentIdx] = dataToInsert;
            }
        }
};

/*Driver test code
int main() {
    int arr[] = {5, 3, 1, 4, 2};
    size_t arrSize = sizeof(arr) / sizeof(arr[0]);
    InsertionSort<int[5]> arrSorter(arr, arrSize);
    arrSorter.insertionSortArr();
    std::cout << "Sorted Array: ";
    arrSorter.printSorted();

    std::vector<int> vec = {5, 3, 1, 4, 2};
    InsertionSort<std::vector<int>> vecSorter(vec, vec.size());
    vecSorter.insertionSortVec();
    std::cout << "Sorted Vector: ";
    vecSorter.printSorted();

    return 0;
}
*/