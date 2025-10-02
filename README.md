# Arbitrary Precision Calculator (APC Project) 🚀

**Author:** T. Simhadri  
**Date:** 07/09/2025  
**Technology:** C Programming (Console-based Application)  

---

## 📔 Project Overview

The **Arbitrary Precision Calculator (APC)** is a C-based console application that allows performing **arithmetic operations on arbitrarily large integers**, which are beyond the limits of standard C data types. It uses a **Doubly Linked List (Dlist)** to store each digit of the numbers individually, enabling operations like addition, subtraction, multiplication, and division on very large numbers.

---

## 🔐 Key Features

- Supports **Addition (+), Subtraction (-), Multiplication (×), Division (÷)**
- Handles **positive and negative numbers** with proper sign handling
- Removes **leading zeros** to ensure accurate results
- Modular structure: each operation is implemented in separate files (`addition.c`, `subtraction.c`, `multiplication.c`, `division.c`, `validate.c`, etc.)
- **Robust error handling**: detects invalid input and division by zero
- **Command-line interface** with step-by-step results

---

## 🛠 Technologies & Concepts Used

- **C Programming**
- **Doubly Linked List** for storing large integers
- Dynamic memory allocation (`malloc` / `free`)
- Modular programming with separate files for each operation
- Input validation and operator handling
- Terminal-based user interaction
- Arithmetic algorithms for big integers

---

## 📝 How to Use

### Compile the Project:
```bash
gcc *.c -o apc
