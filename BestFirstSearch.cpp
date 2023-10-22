/*
 * Best First Search algorithm implementation by utilizing min-heap priority queue (sorted by cost)
 * which finds the shortest path to reach target element provided by user in the form of cost (Node(state,cost))
 * and prints each node visited with the accumulated path cost while heap up process (target element -> root)
 * O(k log n + k) 
 */

//Linking other header files
#include <iostream>
#include <vector>
#include <unordered_map>
#include <iomanip>

//Namespace definition
using namespace std;

//Class declaration for priority queue
class MinHeapPQ{

    //Public methods
    public:

        //Constructor to construct a priority queue with provided capacity
        MinHeapPQ(int capacity) : cap(capacity), size(0) {

            //Dynamically creating heap array with provided capacity
            list = new int[cap];
        }

        //Method to insert an element to priority queue
        void insert(int item) {

            //In the case of capacity excession
            if(size >= cap) {

                //Throwing exception
                throw overflow_error("Element insertion is not possible since queue is full.");
            }

            else {

                //Inserting item at the end of the heap's array
                list[size] = item;

                //Adjusting the heap for proceeding relational property of queue, where parent is less than its successors
                heapUp(size);

                //Increasing the size of the array
                size++;
            }
        }

        //Method to delete element that has highest priority
        int deleteMin() {

            //In the case of an empty or invalid queue
            if(size <= 0) {

                //Throwing exception
                throw overflow_error("Element removal is not possible since queue is empty");
            }

            //Initializing a variable to hold removed root element
            int removed = list[0];

            //Transferring last element of the queue to the empty root
            list[0] = list[size - 1];

            //Decreasing the size 
            size--;

            //Adjusting the heap for proceeding relational property of queue, where parent is less than its successors
            heapDown();

            //Returning removed element
            return removed;
        }
        
        //Wrapper method that traverses in the min heap priority queue ,which finds min cost path, from final element (provided cost) to root (FINAL -> MIN)
        vector<int> traverseMinHeap(int finalElement) {

            //Storing min elements (which refers to cost in BFS)
            vector<int> minElements;

            //Initializing a variable to hold index of root
            int startIndex = 0;

            //Determining whether start element (cost) is positive
            if(finalElement < 0) {

                //Throwing an exception
                throw out_of_range("Invalid starting element");
            }

            //Obtaining the index where list[index] equals startElement
            int finalIndex = -1;
            for (int idx = 0; idx < size; idx++) {

                //In the case of successful search
                if (list[idx] == finalElement) {

                    //Assigning current index to start index 
                    finalIndex = idx;
                    break;
                }
            }

            //Determining the starting element was found
            if (finalIndex == -1) {

                //Throwing an exception
                throw out_of_range("Index is out of bound");
            }

            //Adding the final element to the min list (necessary since search will start from this node)
            minElements.push_back(list[finalIndex]);

            //Commencing to traverse
            traverseMinHeapRecursive(startIndex, finalIndex, minElements);

            //Return statement
            return minElements;
        }

        //Destructor to restore dynamically reserved memory 
        ~MinHeapPQ() {

            //Restoring the memory reserved by array list of the heap
            delete[] list;
        }

    //Private attributes and methods
    private:

        //Size, capacity attributes of queue, and array of the heap
        int size;
        int cap;
        int* list;

        //Helper method to calculate heap index of parent node
        int parent(int currentIndex) {

            //Return statement 
            return (currentIndex - 1) / 2;
        }

        //Helper method to calculate heap index of left successor 
        int leftSuccessor(int currentIndex) {

            //Return statement 
            return 2 * currentIndex + 1;
        }

        //Helper method to calculate heap index of right successor 
        int rightSuccessor(int currentIndex) {

            //Return statement 
            return 2 * currentIndex + 2;
        }

        //Method that traverses in the min heap priority queue ,which finds min cost path, from final element (provided cost) to root (FINAL -> MIN)
        void traverseMinHeapRecursive(int minIndex, int finalIndex, vector<int>& minElements) {

            //In the case of reach to the root 
            if(finalIndex == minIndex) {

                //Adding to the min elements list
                minElements.push_back(list[0]);

                //Return statement
                return;
            }

            //Obtaining parent index
            int parentIndex = parent(finalIndex);

            //Adding the parent to the list of minimum elements
            minElements.push_back(list[parentIndex]);

            //Recursively traversing from the parent node to the root
            traverseMinHeapRecursive(minIndex, parentIndex, minElements);
        }

        //Method to adjust the heap up for proceeding relational property of queue, where parent is less than its successors, in insertion process
        void heapUp(int index) {

            //In the case of index greater than 0 and parent is greater than its successor
            while(index > 0 && list[parent(index)] > list[index]) {

                //Swapping current element with its parent
                swap(list[index], list[parent(index)]);

                //Updating index
                index = parent(index);
            }
        }

        //Method to adjust the heap down for proceeding relational property of queue, where parent is less than its successors, in deletion process
        void heapDown(int index = 0) {

            //Initializing a variable to hold min index value, which is initially root index (0)
            int minIndex = index;

            //Initializing variable to hold left and right successor of root index
            int left = leftSuccessor(index);
            int right = rightSuccessor(index);

            //In the case of left successor less than current node
            if(left < size && list[left] < list[minIndex]) {

                //Swapping min index with index of left successor
                minIndex = left;
            }

            //In the case of right successor less than current node
            if(right < size && list[right] < list[minIndex]) {

                //Swapping min index with index of right successor
                minIndex = right;
            }

            //In the case of change in minIndex variable during comparisons with successors
            if (index != minIndex) {

                //Swapping elements in the indices
                swap(list[index], list[minIndex]);

                //Recursively applying same operation for new element that will be compared with its successor 
                heapDown(minIndex);
            }
        }
};

//Node in a state space
typedef struct Node {

    //State of the node
    int state;

    //Cost of the node
    int cost;

    //Constructor
    Node(int s, int c) : state(s) , cost(c) {}

} Node;

//Class declaration for best first search algorithm
class BFS {

    //public methods
    public:

        //Constructor
        BFS(int capacity) : minHeap(capacity) {}

        //Method to insert a node and edge in the state space
        void insertNode(int state, int cost) {

            //Inserting the cost into the MinHeapPQ
            minHeap.insert(cost); 

            //Mapping the state to its cost
            stateToCost[state] = cost; 
        }

        //Method to obtain minimum cost path via best first search by starting from provided start state
        //Returns unordered map which includes current state and accumulated cost of the path 
        unordered_map <int, int> getMinCostPath(Node startNode) {

            //Initializing map to track path
            unordered_map <int, int> path;

            //Initializing a variable to track accumulated cost
            int accumulatedCost = 0;

            //Extracting min cost path from priority queue
            vector<int> costs = minHeap.traverseMinHeap(startNode.cost);

            //Iterating over cost list
            for(int cost : costs) {

                //Obtaining state of each cost
                int state = getState(cost);

                //Adding state and cost elements to unordered map
                path[state] = accumulatedCost;

                //Updating accumulated cost
                accumulatedCost += cost;
                
            }

            //Returning unordered map
            return path;
        }

        //Method to print min cost path 
        void printPath(const unordered_map <int, int>& path) {

            //Setting the width for the columns
            const int stateWidth = 7; 
            const int costWidth = 4; 

            //Printing the table headers
            cout << left << setw(stateWidth) << "State" << setw(costWidth) << "Accumulated Cost" << endl;

            //Iterating over the unordered map 
            for (const auto& element : path) {

                //Printing each state and accumulated cost
                cout << left << setw(stateWidth) << element.first << setw(costWidth) << element.second << endl;
            }
        }


    //private attributes and methods
    private:

        //Initializing instance of priority queue
        MinHeapPQ minHeap;

        //Initializing instance of unordered map for mapping from state to cost
        unordered_map <int, int> stateToCost; 

        //Method to obtain cost of a node of provided state
        int getCost(int state) {

            //Returning cost
            return stateToCost[state];
        }

        //Method to obtain state via cost
        int getState(int cost) {

            //Returning state by iterating over unordered map
            for(const auto& element : stateToCost) {
                
                //In the case of successfull search
                if(element.second == cost) {

                    //Return the state of the element
                    return element.first;
                }
            }

            //In the case of unsuccessful search
            throw logic_error("State with given cost not found");
        }
};

/*Driver test function
int main() {

    //Defining the capacity for the priority queue
    int capacity = 10;

    //Creating an instance of the BFS class
    BFS bfs(capacity);

    //Inserting nodes and their corresponding costs into the state space
    bfs.insertNode(1, 5);
    bfs.insertNode(2, 8);
    bfs.insertNode(3, 3);
    bfs.insertNode(4, 9);
    bfs.insertNode(5, 4);

    //Defining the start node
    Node startNode(1, 5);

    //Calculating the minimum cost path
    unordered_map<int, int> path = bfs.getMinCostPath(startNode);

    //Printing the minimum cost path (start node's accumulated cost will be printed as 0 )
    bfs.printPath(path);

    //Return statement
    return 0;
}
*/
