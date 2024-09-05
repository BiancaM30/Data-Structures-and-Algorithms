# Data-Structures-and-Algorithms

This repository contains six C++ labs from the **Data Structures and Algorithms (DSA)** course, each focusing on implementing a specific abstract data type (ADT) using different data structures. The implementations involve the use of dynamic data structures, linked lists, hash tables, and binary search trees.

## Table of Contents

1. [Lab 1 - Frequency-Based Collection Using Dynamic Vector](#lab-1---frequency-based-collection-using-dynamic-vector)
2. [Lab 3 - Set Using Singly Linked List](#lab-3---set-using-singly-linked-list)
3. [Lab 4 - Ordered List Using Doubly Linked List](#lab-4---ordered-list-using-doubly-linked-list)
4. [Lab 6 - Ordered Multi-Dictionary Using Hash Table](#lab-6---ordered-multi-dictionary-using-hash-table)
5. [Lab 7 - Ordered Dictionary Using Binary Search Tree](#lab-7---ordered-dictionary-using-binary-search-tree)

---

## Lab 1 - Frequency-Based Collection Using Dynamic Vector

In this lab, the task is to implement a **Collection** ADT using a frequency-based representation stored in a dynamic vector.

### Problem:
- The collection of elements is represented as a vector of frequencies. For example, the collection `[5, 10, -1, 2, 3, 10, 5, 5, -5]` is stored as a frequency vector `V`:
  - First, translate the value range `[-5, 10]` to the range `[0, 16]`.
  - Store the frequency of each element in its corresponding position in the vector `V`.

### Features:
- Add, remove, and query elements in the collection.
- Efficiently store and retrieve the frequency of elements using a dynamic vector.

---

## Lab 3 - Set Using Singly Linked List (SLI)

This lab involves the implementation of a **Set** ADT using a **singly linked list** (SLI).

### Problem:
- Represent the set using a singly linked list (SLI).
- Elements are stored without duplicates, and the list is dynamically allocated.

### Features:
- Add, remove, and check for the existence of elements in the set.
- Manage the elements dynamically using a singly linked structure.

---

## Lab 4 - Ordered List Using Doubly Linked List (DLI)

In this lab, the **Ordered List** ADT is implemented using a **doubly linked list** (DLI).

### Problem:
- Implement an ordered list where elements are maintained in a specific order based on a relation `R`.
- The doubly linked list is dynamically allocated and provides an interface with indices for accessing elements.

### Features:
- Insert, delete, and traverse elements in the list while maintaining the specified order.
- Efficient access and manipulation of elements using the doubly linked structure.

---

## Lab 6 - Ordered Multi-Dictionary Using Hash Table

This lab focuses on implementing an **Ordered Multi-Dictionary** ADT using a **hash table** with collision resolution via **separate chaining**.

### Problem:
- Store pairs of (key, value) in a hash table.
- Handle collisions using independent lists for separate chaining.

### Features:
- Add and remove key-value pairs in the multi-dictionary.
- Efficiently resolve collisions using separate lists.
- Perform lookups and other dictionary operations while maintaining the order of the keys.

---

## Lab 7 - Ordered Dictionary Using Binary Search Tree

The task for this lab is to implement an **Ordered Dictionary** ADT using a **binary search tree (BST)**.

### Problem:
- Store key-value pairs in a binary search tree, maintaining the order of keys.
- The binary search tree is represented dynamically using pointers.

### Features:
- Insert, remove, and search for elements in the dictionary.
- Efficiently maintain the order of elements using a binary search tree structure.
- Perform in-order traversal to retrieve elements in sorted order.

---
