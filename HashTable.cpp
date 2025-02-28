#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

// Node class representing an element in the Hash Table (Linked List for Collision Handling)
class Node {
public:
    int value;   // Stores the value of the node
    string key;  // Stores the key
    Node* next;  // Pointer to the next node in the linked list

    // Constructor to initialize a node with a key-value pair
    Node(string key, int value) {
        this->value = value;
        this->key = key;
        next = nullptr;
    }
};

class HashTable {
private:
    static const int SIZE = 7;  // Hash Table size
    Node* dataMap[SIZE];  // Array of pointers to linked list nodes

public:
    // Constructor to initialize Hash Table with nullptr values
    HashTable() {
        for (int i = 0; i < SIZE; i++) {
            dataMap[i] = nullptr;
        }
    }

    // Destructor to free allocated memory
    ~HashTable() {
        for (int i = 0; i < SIZE; i++) {
            Node* temp = dataMap[i];
            while (temp) {
                Node* toDelete = temp;
                temp = temp->next;
                delete toDelete;
            }
        }
    }

    // Hash function to generate an index for a given key
    int hash(string key) {
        int hash = 0;
        for (char ch : key) {
            hash = (hash + int(ch) * 23) % SIZE;  // Using 23 as a multiplier for better distribution
        }
        return hash;
    }

    // Insert a key-value pair into the Hash Table
    void set(string key, int value) {
        int index = hash(key);
        Node* newNode = new Node(key, value);

        if (dataMap[index] == nullptr) {
            dataMap[index] = newNode;  // Insert if no collision
        } else {
            Node* temp = dataMap[index];
            while (temp->next) {
                temp = temp->next;  // Traverse to end of list
            }
            temp->next = newNode;  // Append new node at the end
        }
    }

    // Get value associated with a key
    int get(string key) {
        int index = hash(key);
        Node* temp = dataMap[index];
        while (temp) {
            if (temp->key == key) {
                return temp->value;
            }
            temp = temp->next;
        }
        return -1; // Not found
    }

    // Retrieve all keys in the hash table
    vector<string> keys() {
        vector<string> allKeys;
        for (int i = 0; i < SIZE; i++) {
            Node* temp = dataMap[i];
            while (temp) {
                allKeys.push_back(temp->key);
                temp = temp->next;
            }
        }
        return allKeys;
    }

    // Print the Hash Table
    void printTable() {
        for (int i = 0; i < SIZE; i++) {
            cout << i << ": \n";
            if (dataMap[i]) {
                Node* temp = dataMap[i];
                while (temp) {
                    cout << " {" << temp->key << ", " << temp->value << "} \n";
                    temp = temp->next;
                }
            }
        }
    }
};

///////////////////////////// ( ** Interview Questions**)//////////////////////////////////////////////////////////////////////////////

// Function to check if two vectors have a common element( ** Interview Question)
bool itemInCommon(vector<int> vect1, vector<int> vect2) {
    unordered_map<int, bool> hashTable;
    for (int key : vect1) {
        hashTable[key] = true;
    }
    for (int key : vect2) {
        if (hashTable[key]) return true;
    }
    return false;
}
//Find Duplicates ( ** Interview Question)
vector<int> findDuplicates(const vector<int>& nums) {
    unordered_map<int, int> hashTable; // Changed bool → int (to track occurrences)
    vector<int> duplicates;

    for (int key : nums) {
        hashTable[key]++; // Increment count

        if (hashTable[key] == 2) { // Push only on second occurrence
            duplicates.push_back(key);
        }
    }
    return duplicates;
}
//First Non-Repeating Character( ** Interview Question)
char firstNonRepeatingChar(const string& input_string) {
    unordered_map<char, int> charCounts;

    // First pass: Count occurrences of each character
    for (char ch : input_string) {
        charCounts[ch]++;
    }

    // Second pass: Find the first non-repeating character
    for (char ch : input_string) {
        if (charCounts[ch] == 1) {
            return ch;  // Return the first non-repeating character
        }
    }

    return '\0';  // Return null character if no unique character is found
}
//Group Anagrams ( ** Interview Question)
vector<vector<string>> groupAnagrams(const vector<string>& strings) {
    unordered_map<string, vector<string>> anagramGroups;

    // Iterate through each string in the input vector
    for (const string& str : strings) {
        string canonical = str;
        sort(canonical.begin(), canonical.end()); // Sort to get the anagram key
        anagramGroups[canonical].push_back(str); // Group by sorted form
    }

    // Collect the grouped anagrams into a result vector
    vector<vector<string>> result;
    for (const auto& group : anagramGroups) {
        result.push_back(group.second);
    }

    return result;
}
// inds two numbers in 'nums' that sum up to the given 'target'( ** Interview Question)
vector<int> twoSum(const vector<int>& nums, int target) {
    unordered_map<int, int> numMap;
    for (int i = 0; i < nums.size(); i++)
    {
        int complement = target - nums[i];
        if (numMap.find(complement) != numMap.end()) 
        {
            return {numMap[complement], i};
        }
        numMap[nums[i]]=i;
    }
    return {};
}
//HT: Subarray Sum ( ** Interview Question)
vector<int> subarraySum(const vector<int>& nums, int target) {
    unordered_map<int, int> sumIndex; // Stores prefix sums and their indices
    int currentSum = 0;

    for (int i = 0; i < nums.size(); i++) {
        currentSum += nums[i]; // Update running sum
        
        // If currentSum equals target, subarray starts from index 0
        if (currentSum == target) {
            return {0, i};
        }
        
        // Check if (currentSum - target) exists in the map
        if (sumIndex.find(currentSum - target) != sumIndex.end()) {
            return {sumIndex[currentSum - target] + 1, i}; // Found valid subarray
        }
        
        // Store the first occurrence of currentSum
        sumIndex[currentSum] = i;
    }
    
    return {}; // No valid subarray found
}
//Set:removeDuplicates ( ** Interview Question)
vector<int> removeDuplicates(const vector<int>& myList) {
    unordered_set<int> uniqueSet;  // Stores unique integers
    vector<int> result;  // Output vector to store unique values

    // Iterate over the input list and insert unique values
    for (int num : myList) {
        if (uniqueSet.find(num) == uniqueSet.end()) { // Check if not in set
            uniqueSet.insert(num);  // Insert into the set
            result.push_back(num);  // Add to the result vector
        }
    }

    return result;  // Return the unique numbers in the same order
}
//Set: Has Unique Chars ( ** Interview Question)
bool hasUniqueChars(const string& str) {
    unordered_set<char> charSet;  // Stores unique characters

    // Iterate through each character in the string
    for (char ch : str) {
        if (charSet.find(ch) != charSet.end()) { // If character is already in the set
            return false;  // Duplicate found, return false
        }
        charSet.insert(ch);  // Insert character into the set
    }

    return true;  // No duplicates found, return true
}
//Set: Find Pairs ( ** Interview Question)
vector<vector<int>> findPairs(const vector<int>& arr1, const vector<int>& arr2, int target) {
    unordered_set<int> mySet;  // Stores numbers from arr1 for quick lookup
    vector<vector<int>> pairs; // Stores the valid pairs

    // Populate the set with elements from arr1
    for (int num : arr1) {
        mySet.insert(num);
    }

    // Iterate through arr2 to find valid pairs
    for (int num : arr2) {
        int complement = target - num; // Find the required complement
        if (mySet.find(complement) != mySet.end()) { // Check if complement exists in arr1
            pairs.push_back({complement, num});
        }
    }

    return pairs;
}
//Set: Longest Consecutive Sequence ( ** Interview Question)
int longestConsecutiveSequence(const vector<int>& nums) {
    unordered_set<int> numSet(nums.begin(), nums.end()); // Store unique numbers
    int longestStreak = 0;

    for (int num : nums) {
        // Check if this is the start of a sequence
        if (numSet.find(num - 1) == numSet.end()) {
            int currentNum = num;
            int currentStreak = 1;

            // Expand the sequence
            while (numSet.find(currentNum + 1) != numSet.end()) {
                currentNum++;
                currentStreak++;
            }

            // Update longest sequence found
            longestStreak = max(longestStreak, currentStreak);
        }
    }

    return longestStreak;
}

// Main function to test the Hash Table
int main() {
    HashTable* my_HT = new HashTable();

    // Insert some key-value pairs
    my_HT->set("Apple", 100);
    my_HT->set("Orange", 150);
    my_HT->set("Banana", 200);
    my_HT->set("Grapes", 175);
    my_HT->set("Mango", 250);
    my_HT->set("Peach", 300);
    my_HT->set("Strawberry", 350);

    cout << "Hash Table after insertions:\n";
    my_HT->printTable();

    cout << "\nRetrieving values:\n";
    cout << "Value of Apple: " << my_HT->get("Apple") << endl;
    cout << "Value of Banana: " << my_HT->get("Banana") << endl;
    cout << "Value of Mango: " << my_HT->get("Mango") << endl;
    cout << "Value of Pear (not inserted): " << my_HT->get("Pear") << endl;

    vector<string> my_HTkeys = my_HT->keys();
    cout << "Keys in HashTable: ";
    for (const string& key : my_HTkeys) {
        cout << key << " ";
    }
    cout << endl;
    // Free memory
    delete my_HT;

    return 0;
}