# Hash Table Implementation & Interview Questions

## Overview
This repository contains an implementation of a **Hash Table** using **separate chaining** for collision handling. The implementation includes essential operations such as inserting, retrieving, and printing key-value pairs. Additionally, the repository provides solutions to several **coding interview questions** that leverage hash tables and sets for efficient problem-solving.

## Features
### Hash Table Implementation
- **Custom Hash Table** with:
  - Insert (`set`)
  - Retrieve (`get`)
  - Retrieve all keys (`keys`)
  - Print table (`printTable`)
- Uses **separate chaining** with linked lists to handle collisions.

### Coding Interview Questions
- **Checking Common Elements**: Determine if two arrays share at least one common element.
- **Finding Duplicates**: Identify repeated elements in an array.
- **First Non-Repeating Character**: Locate the first character in a string that does not repeat.
- **Grouping Anagrams**: Group words that are anagrams of each other.
- **Two Sum Problem**: Find two numbers in an array that add up to a target.
- **Subarray with Given Sum**: Locate a contiguous subarray that sums to a target value.
- **Removing Duplicates**: Eliminate duplicate elements while maintaining order.
- **Unique Character Check**: Determine if a string consists of unique characters.
- **Finding Pairs for Target Sum**: Identify pairs from two arrays whose sum matches a target.
- **Longest Consecutive Sequence**: Compute the longest sequence of consecutive numbers in an array.

## Getting Started
### Prerequisites
- **C++ Compiler** (e.g., g++, Clang, or MSVC)
- **C++ Standard Library** (for STL usage)

### Installation
1. Clone this repository:
   ```sh
   git clone https://github.com/yourusername/hash-table.git
   cd hash-table
   ```
2. Compile the code:
   ```sh
   g++ -o main main.cpp
   ```
3. Run the executable:
   ```sh
   ./main
   ```

## Usage
- The program inserts predefined key-value pairs into the hash table.
- It retrieves values using keys and prints the entire hash table.
- Solutions for coding interview problems can be tested by modifying the `main.cpp` file.

## Performance Considerations
- **Hash Table Operations**:
  - **Insertion & Lookup**: Average-case **O(1)** using an unordered set/map.
  - **Worst-case Complexity**: **O(n)** in case of excessive collisions.
- **Interview Questions**:
  - Solutions use **hash tables and sets** for optimized search and retrieval operations.
  - Efficient implementations with average-case **O(n)** or **O(n log n)** complexity.

## Contributing
Contributions are welcome! Feel free to **add more interview questions**, **optimize algorithms**, or **enhance documentation**.

1. Fork the repository.
2. Create a new branch (`feature/new-feature`).
3. Commit changes (`git commit -m 'Added new feature'`).
4. Push to the branch (`git push origin feature/new-feature`).
5. Open a Pull Request.
