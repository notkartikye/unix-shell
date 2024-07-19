# Unix Shell Implementation using C Multithreading

This is a Linux/Unix-like shell implemented in C. This shell supports 3 internal and 5 external commands with various options, executed via `fork/exec` or `pthread/system` function calls based on the user's preference. Commands can be run in parallel using threads, making this shell very efficient.

## Features

### Internal Commands

#### 1. echo (prints the arguments provided)
  - `-n`: No newline after execution.
  - `-E`: Suppress backslash interpretation.

#### 2. pwd (prints the current directory)
- `-L`: Do not ignore symbolic links.
- `-P`: Avoid symbolic links.

#### 3. cd (changes the current directory of the process)

### External Commands

#### 1. ls (lists the directories in the current directory)
- `-1`: Print directories on new lines.
- `-Q`: Print directories in quotation marks.

#### 2. date (prints the current date)

#### 3. cat (displays the content of a file)
- `-n`: Display line numbers.
- `-e`: Display `$` at the end of each line.

#### 4. rm (removes a file)
- `-i`: Ask for confirmation before removal.
- `-v`: Display the status of removal.

#### 5. mkdir (creates a new directory)
  - `-v`: Display the status of directory creation.

## Instructions
1. Clone the repository:

    ```bash
    git clone https://github.com/notkartikye/unix-shell.git
    cd unix-shell
    ```
    
2. Build the project:
    ```bash
    make build
    ```
3. Clean the build files:
    ```bash
    make clean
    ```
4. Run the shell:
    ```bash
    ./shell
    ```

###### Example:
```
./shell

> echo Hello, World!
Hello, World!

> ls -l
directory1
file1.txt
file2.txt

> date
Mon Apr 20 00:04:20 UTC 2022

> cat -n example.txt
1    This is an example file.
2    It has multiple lines.
```
