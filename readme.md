# IPC144 - C Programming Projects

This repository contains two major software development projects completed for the **IPC144 (Introduction to Programming Using C)** course. These projects demonstrate proficiency in structured programming, memory management, and algorithm design.

## 📂 Project 1: Contact Management System
A modular application designed to manage personal and business contact information. The system focuses on data validation and structural organization of related data types.

### Key Features
* **CRUD Operations**: Create, read, update, and display contact details (Name, Address, Numbers).
* **Input Validation**: Robust helper functions to ensure data integrity (e.g., checking for valid phone numbers, enforcing mandatory fields).
* **Search Functionality**: Algorithms to traverse arrays and retrieve specific records.

### Technical Implementation
* **Structs**: Utilized nested C structures to model complex entities.
* **Modularization**: Code split across multiple source files (`contacts.c`, `core.c`) with header guards to manage dependencies.

---

## 📂 Project 2: Veterinary Clinic / Inventory System
*Note: Rename this section based on your specific final assignment (e.g., Grocery Store, Veterinary Clinic).*

A comprehensive management system built to handle inventory tracking, appointment scheduling, or patient records. This project extends the concepts of Project 1 by introducing persistent storage and advanced logic.

### Key Features
* **File Persistence**: Reads from and writes to external `.txt` or `.csv` files to ensure data is saved between sessions.
* **Dynamic Reporting**: Generates formatted reports of current inventory or patient lists.
* **Advanced Logic**: Implements sorting and filtering algorithms to organize large datasets.

### Technical Implementation
* **File I/O**: Usage of `fopen`, `fprintf`, and `fscanf` for data serialization.
* **Pointer Arithmetic**: Efficient data manipulation and passing by reference.
* **Macros & Constants**: rigorous use of `#define` for maintainable code configuration.

---

## Core Learnings & Competencies

### 1. Low-Level Memory Management
* Mastered the difference between **Pass-by-Value** and **Pass-by-Address**.
* Direct memory manipulation using pointers to optimize performance and modify data in place.

### 2. Modular Programming
* Moving away from "spaghetti code" by decoupling logic into reusable modules.
* Understanding the compilation process: Pre-processing → Compiling → Linking.

### 3. Data Structures & Algorithms
* Designing custom data types (`struct`) to represent real-world objects.
* Implementing linear search algorithms and efficient array traversal loops.

### 4. Input/Output Hygiene
* Cleaning the input buffer (`stdin`) to prevent infinite loops during user input errors.
* Formatting complex output using `printf` flags for professional console UI.

## 🛠️ Build & Run

**Prerequisites:** GCC Compiler

**Compilation:**
```bash
gcc -Wall -o project1 core.c contacts.c main.c
./project1