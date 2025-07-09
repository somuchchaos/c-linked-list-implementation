# Singly Linked List in C

* **Author:** Akshita Rawat
* **Intern ID:** CT04DN682
* **Company:** CODTECH IT SOLUTIONS
* **Mentor:** Neela Santosh
* **Domain:** C Programming
* **Duration:** 4 Weeks

---

## 📌 Overview

This C program implements a **menu-driven singly linked list** with dynamic memory allocation. It supports all fundamental operations like inserting, deleting, and traversing a linked list using pointers.

The goal of this project is to understand how dynamic data structures work in C and how to manage memory efficiently using `malloc()` and `free()`.

---

## ✅ Features

* Insert a node at the beginning
* Insert a node at the end
* Insert a node after a specific value
* Delete a node by value
* Traverse and display the list
* Free all memory before exiting
* Input validation and error handling

---

## 🛠️ Technologies Used

* **C Programming Language**
* Standard Libraries:

  * `stdio.h` – for input/output
  * `stdlib.h` – for memory and exit handling

---

## 📂 File Structure

```
singly_linked_list.c      # Main source code
README.md                 # Project documentation
```

---

## ▶️ How to Compile and Run

```bash
gcc linked_list.c -o linkedlist
./linkedlist
```

---

## 🧪 Sample Menu Output
![output](output.png)

---

## 🔍 Example Use

* Add 10 → beginning → list: `10 -> NULL`
* Add 20 → end → list: `10 -> 20 -> NULL`
* Add 15 after 10 → list: `10 -> 15 -> 20 -> NULL`
* Delete 15 → list: `10 -> 20 -> NULL`

---

## 📚 What I Learned

* Implementing linked lists with dynamic memory allocation
* Creating and linking nodes using pointers
* Writing modular C code with separate functions
* Using input validation and flushing input buffers
* Avoiding memory leaks by freeing nodes before exit