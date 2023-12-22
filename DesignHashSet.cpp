/* Solution to Design HashSet problem in Leetcode
 * by utilizing universal hashing function and linked lists for collision resilience
 */

//Linking external header files
#include <iostream>
#include <unordered_map>
#include <list>
#include <cstdlib>
#include <cmath>

class MyHashSet {

    //Private attributes
    private:

        //Size (buckets) of hash table
        int numBuckets;

        //Hash table for storing linked list for each bucket
        std :: unordered_map<int, std :: list<int>> table;

        //Coefficients for universal hash function
        int x, y, z;

        //Universal hash function to determine index of the bucket
        int uniHash(const int& key) {

            //((x * key + y) % z) % numBuckets
            return ((x * key + y) % z) % numBuckets;
        }

    //Public methods
    public:

        //Constructor
        MyHashSet(const int& bucketNumber = 2000) : numBuckets(bucketNumber) {

            //Choosing random values for x, y, z, where x ∈ [1, bucketNumber - 1]
            x = rand() % (numBuckets - 1) + 1;  
            y = rand() % numBuckets;
            z = getPrime(numBuckets);    
        }
        
        //Inserting a new key to hash table
        void add(const int& key) {

            //Hashing key to obtain index 
            int index = uniHash(key);

            //Determining whether key already exists in the bucket
            for (int val : table[index]) {

                //In the case of the key is already existed in hash table
                if (val == key) {

                    //Termination
                    return; 
                }
            }

            //In the key is not found, adding it 
            table[index].push_back(key);              
        }
        
        //Removing key
        void remove(int key) {

            //Hashing key to obtain index 
            int index = uniHash(key);

            //Finding key by iterating through table
            for (int val : table[index]) {

                //In the case of founded key
                if (val == key) {

                    //Removing key
                    table[index].remove(val);

                    //Terminate
                    return;
                }  
            }
        }
        
        //Looking up for a key
        bool contains(int key) {

            //Hashing key to obtain index 
            int index = uniHash(key);

            //Finding key by iterating through table
            for (int val : table[index]) {

                //In the case of founded key
                if (val == key) {

                    //Terminate
                    return true;
                }  
            }  

            //In the case of the key is not found
            return false;  
        }

    //Private methods
    private:

        //Private method to find the smallest prime number greater than or equal to n
        int getPrime(int n) {

            //Obtaining prime number 
            while (!isPrime(n)) {

                //In the case n is not prime, incrementing by one
                n++;
            }

            //Returning the closest prime number
            return n;
        }

        //Helper method to determine whether a number is prime
        bool isPrime(int num) {

            //In the case of number less than 1
            if (num <= 1) {

                //Return
                return false;
            }

            //Determining primeness
            for (int i = 2; i <= sqrt(num); i++) {

                //In the case of there is an divisor of the number
                if (num % i == 0) {

                    //Return
                    return false;
                }
            }

            //Return
            return true;
        }

};
