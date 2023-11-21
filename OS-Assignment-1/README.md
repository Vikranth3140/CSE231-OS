# Process and Shell Commands in C

This project includes several C programs that demonstrate various concepts related to processes, custom shell commands, and a Bash script for performing operations based on input values.

## 1. Process Demonstrations

### 1.1. q1.1.c

This program creates a parent process that forks a child process. Both processes print their respective process IDs and parent process IDs. It showcases the use of the `fork()` system call.

**Makefile Targets**
- `q1.1`: Compiles q1.1.c into an executable.
- `run`: Runs the q1.1 program.
- `clean`: Removes the compiled executable.

### 1.2. q1.2.c

This program demonstrates a child process waiting for its parent process to complete. It utilizes the `fork()` system call and showcases process synchronization.

**Makefile Targets**
- `p1`: Compiles the first program, p1.c, into an executable.
- `p2`: Compiles the second program, p2.c, into an executable.
- `run`: Runs the q1.2 program.
- `clean`: Removes the compiled executables (p1 and p2).

## 2. Custom Shell Commands

### 2.1. source.c

This program implements custom shell commands (word, dir, and date) along with command-line options. It provides functionalities such as word counting, directory creation, and retrieving file information.

**Supported Commands**
1. `word`: Calculate the number of words in a text file.
2. `dir`: Create a directory and change the shell's working directory.
3. `date`: Retrieve the last modified date and time of a file.

**Makefile Targets**
- `build`: Compiles the source.c program into an executable.
- `clean`: Removes the compiled executable.

## 3. Interactive Calculator (Bash Script)

### calculator.sh

This Bash script creates an interactive calculator that performs three different operations (xor, product, compare) based on input values read from an input file. It stores the results in an output file.

**Operations**
1. `xor`: Perform a bitwise XOR operation on two numbers.
2. `product`: Calculate the product of two numbers.
3. `compare`: Compare two numbers.

**Usage**
```bash
./calculator.sh input.txt output.txt
```

## How to Use

1. Compile the C programs using the provided Makefiles.
2. Run the desired C programs as explained in their respective sections.
3. Execute the Bash script by providing an input file (`input.txt`) and an output file (`output.txt`) as arguments.

Feel free to explore and use these programs for learning and experimentation.

**Note**: Make sure you have GCC (for C programs) and Bash installed on your system to run these programs.
