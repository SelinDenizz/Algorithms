/* Template Trie class that provides
 * Insertion method to insert a string word into the trie,
 * Searching method to returns true if the string word is in the trie (i.e., was inserted before),
 * Another searching method to return true if there is a previously inserted string word that has the prefix prefix,
 * And deletion method to delete a specified word from a Trie data structure, 
 * addressing cases where the word is a prefix of others, shares a common prefix, or has no common prefix.
 */

//Linking other header files
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

//Template class of Trie Node
template <typename T>
class TrieNode {

    //Public attributes
    public:

        //Initializing an unordered map to store child nodes with their types as key
        std :: unordered_map <T, TrieNode<T>*> children;

        //Flag to track end of a word
        bool completeWord;

        //Constructor
        TrieNode() : completeWord(false) {}
};

//Template class of Trie
template <typename T>
class Trie {

    //Private attributes
    private:

        //Root of the Trie
        TrieNode <T>* root = nullptr;

    //Public methods
    public:

        //Constructor
        Trie() {

            //Dynamically allocating memory for root node
            root = new TrieNode <T>;
        }

        //Insertion method 
        void insert(const std :: basic_string <T>& word) {

            //Declaring current node as the root node
            TrieNode <T>* currentNode = root;

            //Iterating across the length of the string to be inserted
            for(const T& ch : word) {

                //Determining whether current character exists as a node, if not
                if(currentNode -> children.find(ch) == currentNode -> children.end()) {

                    //Creating a new node
                    currentNode -> children[ch] = new TrieNode <T>;
                }

                //Moving to the next node (could be newly created node)
                currentNode = currentNode -> children[ch];
            }

            //Incrementing complete word variable which tracks number of words
            currentNode -> completeWord = true;
        }

        //Word searching method
        const bool search(const std :: basic_string <T>& word) {

            //Initializing current node pointer as root node
            TrieNode <T>* currentNode = root;

            //Iterating across the length of the string 
            for (const T& ch : word) {

                //In the case a character can not be found
                if (currentNode -> children.find(ch) == currentNode -> children.end()) {

                    //Returning false 
                    return false;
                }

                //Moving to the next node
                currentNode = currentNode -> children[ch];
            } 

            //In the case of a successful search
            return (currentNode -> completeWord > 0);
        }

        //Prefix searching method 
        const bool startsWith(const std :: basic_string <T>& prefix) {

            //Initializing current node pointer as root node
            TrieNode <T>* currentNode = root;

            //Iterating across the length of the string 
            for (const T& ch : prefix) {

                //In the case a character can not be found
                if (currentNode -> children.find(ch) == currentNode -> children.end()) {

                    //Returning false 
                    return false;
                }

                //Moving to the next node
                currentNode = currentNode -> children[ch];
            } 

            //In the case of a successful search
            return true;
        } 

        //Wrapper method for initiating recursive removal
        void removeWrapper(const std :: basic_string<T>& word) {

            //Calling helper remove method with the depth 0
            removeRecursive(root, word, 0);
        }

        //Destructor
        ~Trie() {

            //Deallocating reserved memory
            deleteTrie(root);
        }

        //Private methods
        private: 

            //Removing method to delete a word from Trie
            void removeRecursive(TrieNode<T>* currentNode, const std :: basic_string<T>& word, int depth) {

                //End of the word
                if(depth == word.length()) {

                    //In the case of found pattern is a completed word
                    if(currentNode -> completeWord) {

                        //Removing that word from Trie by indicating it's not a word anymore
                        currentNode -> completeWord = false;
                    }

                    //Return stateemnt
                    return;
                }

                //Proceeding with the next character
                T ch = word[depth];

                //Initializing iterator as 
                auto it = currentNode -> children.find(ch);

                //In the case of specified character couldn't be found 
                if(it == currentNode -> children.end()) {

                    //Return statement
                    return;
                }

                //Recursively calling for the next node
                removeRecursive(it -> second, word, depth + 1);

                //Removing the child node
                if(it->second->children.empty() && !it->second->completeWord) {

                    //Deleting iterator
                    delete it -> second;
                    currentNode -> children.erase(it);
                }
            }

            //Method for recursive deletion
            void deleteTrie(TrieNode<T>* node) {

                //Reallocating memory for each child node of the Trie
                for (auto& child : node -> children) {
                    deleteTrie(child.second);
                }

                //Deleting the current node
                delete node;
            }
};

//Driver test function
int main() {
    
    //Creating a Trie
    Trie<char> trie;

    //Inserting "apple"
    trie.insert("apple");

    //Searching "apple" and print the result (expected: true)
    std::cout << (trie.search("apple") ? "true" : "false") << std::endl;

    //Searching "app" and print the result (expected: false)
    std::cout << (trie.search("app") ? "true" : "false") << std::endl;

    //Determining whether Trie starts with "app" and print the result (expected: true)
    std::cout << (trie.startsWith("app") ? "true" : "false") << std::endl;

    //Inserting "app"
    trie.insert("app");

    //Searching "app" again and print the result (expected: true)
    std::cout << (trie.search("app") ? "true" : "false") << std::endl;

    return 0;
}
