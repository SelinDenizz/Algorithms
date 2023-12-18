/* 
 * Solution for Best Time to Buy and Sell Stock Problem in Leetcode
 * by utilizing single-pass approach.
 * Time - complexity: O(n)
 * Space - complexity: O(1)
 */

//Linking other header files
#include <iostream>
#include <vector>

//Solution class
class Solution {

    //Public methods
    public:

        //Method to 
        int maxProfit(vector<int>& priceList) {

            //Exception blocks to determine whether price list is empty
            try {

                //In the case of empty list
                if(priceList.empty()) {

                    //Throwing runtime error
                    throw std :: runtime_error("Empty vector");
                }

                //Initializing variables to hold minimum price and maximum profit values 
                auto minPrc = priceList[0];
                auto maxPrf = 0;

                //Iterating through price list
                for(size_t rep = 0; rep < priceList.size(); rep++) {

                    //Updating minimum price value
                    minPrc = std :: min(minPrc, priceList[rep]);

                    //Updating the maximum profit if selling at the current price gives a better profit
                    maxPrf = std :: max(maxPrf, priceList[rep] - minPrc);
                }

                //Returning maximum profit value
                return maxPrf;
            }

            //Exception blocks to determine whether price list is empty
            catch(const std :: exception& err) {

                //Throwing and printing related error 
                std :: cerr << "Error: " << err.what() 
                            << std :: endl;
                
                //Terminating program 
                return 0;

            }  
        }
};
