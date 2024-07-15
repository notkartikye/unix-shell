# C Command Shell: A Unix-Like Multi-threaded Shell Implementation

Welcome to the Command Shell project, a Unix-like shell implemented in C. This shell supports both internal and external commands with various options, executed via `fork/exec` or `pthread/system` function calls based on the user's preference. Commands can be run in parallel using threads, making this shell both versatile and efficient.

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

#### 5. mkdir
Creates a new directory.
  - `-v`: Display the status of directory creation.

## Instructions
1. Clone the repository:

    ```bash
    git clone https://github.com/notkartikye/unix-shell-c.git
    ```

2. Navigate to the project directory:
    ```bash
    cd unix-shell-c
    ```
3. Build the project:
    ```bash
    make build
    ```
4. Clean the build files:
    ```bash
    make clean
    ```
5. Run the shell with a command of your choice:
    ```bash
    ./shell {any-command}
    ```
