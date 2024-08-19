

---

# 📊 Data Structures Warzone: Frequency Counter Implementations

Welcome to the **Data Structures Warzone**! In this repository, you'll find four different implementations of a frequency counter problem using popular data structures:

1. **Singly Linked List**
2. **Binary Search Tree (BST)**
3. **Min-Heap**
4. **Hash Map**

Each solution is designed to handle the same task: generating random numbers, counting their occurrences, and displaying them in a structured, user-friendly format. The aim is to showcase how different data structures can be leveraged to solve the same problem, each with its own strengths and trade-offs.

## 💡 Problem Overview

Given 40 randomly generated numbers, the goal is to:
- Insert each number into the data structure.
- Keep track of each number's frequency of occurrence.
- Display the unique numbers and their frequencies in sorted order.
- Identify the most frequent element, the smallest element, and the largest element.
- Support quick searches for any given number, displaying its frequency if found.

## 🚀 Implementations

1. **🔗 Singly Linked List**:
    - Implements sorted insertion without explicit sorting algorithms.
    - Checks for duplicates while maintaining frequency counts.
    - Outputs the list in sorted order, following linked list traversal logic.

2. **🌳 Binary Search Tree (BST)**:
    - Utilizes a balanced approach to maintain order while tracking frequencies.
    - Provides efficient searching and sorted traversal for element display.

3. **📦 Min-Heap**:
    - Focuses on maintaining the smallest element at the root.
    - Combined with a hash map for frequency counting.
    - Elements are displayed in sorted order by post-processing the heap.

4. **🔍 Hash Map**:
    - Offers the most efficient solution for insertion and frequency counting.
    - Ensures quick lookups and uses a vector for sorted output.
    - Displays numbers with neat formatting and aligned frequency counts.

## 🧠 Why This Repository?

This project demonstrates how different data structures handle:
- Insertion and searching.
- Sorting and traversal.
- Frequency counting.
- Performance trade-offs.

Each implementation has been crafted to produce the same output format, allowing for easy comparison of the pros and cons of each data structure.

## 📂 Repository Structure

```
data-structure-showdown/
├── linked_list.cpp      # Singly Linked List Implementation
├── bst.cpp              # Binary Search Tree (BST) Implementation
├── heap.cpp             # Min-Heap Implementation
├── hash_map.cpp         # Hash Map Implementation
└── README.md            # You're here!
```

## ⚙️ How to Run

Each file is standalone and can be compiled and run using your preferred C++ compiler. For example, to run the Linked List implementation:

```bash
g++ linked_list.cpp -o linked_list
./linked_list
```

Repeat the above for the other implementations to see each data structure in action.

## 📊 Time Complexity Analysis

Here’s a brief comparison of the time complexities for each implementation:

## 📊 Output Example

All implementations will produce output in this format:

```
Number of nodes (unique numbers) in the list = 31
Total number of elements in the list (including duplicates) = 40
---------------------------------------------------------
    3(1)   12(2)   16(1)   22(1)   23(1)
   24(1)   27(2)   28(1)   30(2)   31(1)
   36(2)   37(1)   41(1)   43(1)   50(1)
   57(1)   59(1)   60(1)   63(2)   64(1)
   68(3)   69(1)   70(1)   73(1)   78(1)
   83(1)   84(1)   87(2)   91(1)   93(1)
   94(2)
---------------------------------------------------------
Most frequent element is 68 and the count is 3
The smallest number is 3 and its count is 1.
The largest number is 94 and its count is 2.
---------------------------------------------------------
Enter a number to search for (or -1 to quit): 12
I found the Number: 12; it occurred 2 times
---------------------------------------------------------
Enter a number to search for (or -1 to quit): 50
I found the Number: 50; it occurred 1 time
---------------------------------------------------------
Enter a number to search for (or -1 to quit): 7
Sorry, I couldn't find the Number: 7
---------------------------------------------------------
Enter a number to search for (or -1 to quit): -1
Exiting search. Thank you!
```

## 🏆 Conclusion

This project highlights the power of choosing the right data structure for the task at hand. Whether we prioritize performance, simplicity, or memory efficiency, these implementations offer a clear comparison.

Feel free to explore the code, run the implementations, and contribute further!

---

