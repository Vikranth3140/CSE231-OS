# CSE 231 : Operating System

[Course Description](https://techtree.iiitd.edu.in/viewDescription/filename?=CSE231)
This repository comprises 4 operating system assignments completed during Semester 4 at <a href="https://iiitd.ac.in/">Indraprastha Institute of Information Technology</a>.
\
Each assignment folder contains a detailed README providing specific information about the assignment, contributions, and related files.

## Assignments Overview

- *Assignment 1:*
  - Folder: OS-Assignment-1
  - Topics: Fork, Custom Linux Shell, Bash Script.
  - Description: 

    - q1.1.c

      This program creates a parent process that forks a child process. Both processes print their respective process IDs and parent process IDs. It showcases the use of the `fork()` system call.

    - q1.2.c

      This program demonstrates a child process waiting for its parent process to complete. It utilizes the `fork()` system call and showcases process synchronization.

    - q2 - source.c

      This program implements custom shell commands (word, dir, and date) along with command-line options. It provides functionalities such as word counting, directory creation, and retrieving file information.

    - q3 - calculator.sh

      This Bash script creates an interactive calculator that performs three different operations (xor, product, compare) based on input values read from an input file. It stores the results in an output file.

- *Assignment 2:*
  - Folder: OS-Assignment-2
  - Topics: Artix Linux configuration, Process Scheduling, Module Programming.
  - Description: 

    - q1: Setting up Artix Linux

    - q2: main.c
      
      This program explores different scheduling policies (SCHED_OTHER, SCHED_RR, SCHED_FIFO) by executing three processes with distinct scheduling policies: <code>process1</code>, <code>process2</code>, and <code>process3</code>. The execution times of these processes under each scheduling policy are measured and plotted to compare their performance.</p>

    - q3: process_count.c

      This is a simple kernel module for the Linux kernel that counts the processes running currently and prints the count to the kernel log. The module is written in C and utilizes the Linux Kernel API to access process information.


- *Assignment 3:*
  - Folder: OS-Assignment-3
  - Topics: Memory allocation, Deallocation, System calls-mmap &  munmap.

  - Description:
    
    - MeMS is a custom memory management system that allows for efficient allocation and deallocation of memory using a doubly linked list data structure. It also provides the capability to map virtual memory to physical memory.

  - Link to Repository: [Memory-Management-System](https://github.com/Vikranth3140/Memory-Management-System.git)


- *Assignment 4:*
  - Folder: OS-Assignment-4
  - Description: Threads, Locks, Deadlocks, Semaphores, Mutexes
  - Description: 

    - Dining Philosophers problem

      The dining philosophers problem is a classic synchronization problem. It is a model for concurrent processes that compete for a limited number of resources.

    - Ride Sharing Problem 

      This problem contains a solution to a ride-sharing scenario with a car and multiple passengers using threads and semaphores in C. The ride-sharing system consists of a car and a queue for passengers to board and unboard.

    - Bridge Crossing Simulation

      Simulates cars crossing a thin bridge between two sides of a river. The bridge allows only one car to travel from the left side to the right and vice versa at any given time. Additionally, a maximum of five cars is allowed to travel on the bridge simultaneously. If two cars from opposite sides attempt to cross simultaneously, they will be unable to cross, and travel will halt.

## Getting Started

To explore a specific assignment:
- Click on the respective folder link above.
- Access the README.md file within each assignment folder for comprehensive details, contributions, and instructions.

## Contributors

- [Vikranth Udandarao](https://github.com/Vikranth3140/)
- [Anushka Korlapati](https://github.com/anushka-korlapati/)
