*This project has been created as part of the 42 curriculum by schoinsk.*

# Libft - @42Born2Code

## 📝 Description

**Libft** is the foundational project of the 42 Common Core curriculum. The goal of this project is to build a deeper, low-level understanding of memory management, data structures, and standard C behaviors by recreating a subset of the standard C library (`libc`). 

Instead of relying on pre-built system functions, this custom static library (`libft.a`) serves as a personal toolkit. It will be integrated and reused in almost all subsequent C programming projects throughout the curriculum. Every function is written from scratch, strictly complying with the school's coding standard (**The Norm**), which enforces limits on function length, variable declarations, and loops to encourage clean, readable code.


## 🛠️ Detailed Library Description

The library consists of several standalone functions categorized into three logical parts, tracking from memory manipulation to abstract data structures.

### Part 1 - Libc Functions
These functions mirror the behavior of original functions found in standard headers like `<ctype.h>`, `<string.h>`, and `<stdlib.h>`.

*   **Character Checks (`ft_is*`):** `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`. These analyze individual characters to verify if they fit specific ASCII criteria.
*   **Case Conversion:** `ft_toupper`, `ft_tolower`. Convert character casing.
*   **String Manipulation:** 
    *   `ft_strlen` - Calculates string length.
    *   `ft_strchr`, `ft_strrchr` - Locate characters within strings.
    *   `ft_strncmp` - Compares two strings up to a specific number of bytes.
    *   `ft_strnstr` - Locates a substring within a size-bounded string.
    *   `ft_strlcpy`, `ft_strlcat` - Size-bounded, safe string copying and concatenation.
*   **Memory Management:** 
    *   `ft_memset`, `ft_bzero` - Fill memory buffers with specific values or zeroes.
    *   `ft_memcpy`, `ft_memmove` - Copy byte blocks safely, even if memory regions overlap.
    *   `ft_memchr`, `ft_memcmp` - Locate bytes and compare memory chunks.
*   **Dynamic Allocation:**
    *   `ft_atoi` - Converts an ASCII string to an integer.
    *   `ft_calloc` - Allocates zero-initialized heap memory.
    *   `ft_strdup` - Duplicates an existing string into dynamically allocated memory.

### Part 2 - Additional Functions
These functions are utility tools missing from the standard library or tailored for typical string and file descriptor manipulation.

*   **Advanced Strings:**
    *   `ft_substr` - Safely extracts a designated substring from a string.
    *   `ft_strjoin` - Allocates and concatenates two strings together.
    *   `ft_strtrim` - Strips a custom set of characters from the beginning and end of a string.
    *   `ft_split` - Tokenizes a string into an array of strings based on a single character delimiter.
    *   `ft_itoa` - Converts an integer into its representative ASCII string.
*   **Functional Helpers:**
    *   `ft_strmapi`, `ft_striteri` - Iterate over string characters, applying a mapping function via index pointer.
*   **File Descriptor Output:**
    *   `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd` - Standard printing utilities mapped to send output directly to targeted file descriptors (e.g., standard output, error streams, or files).

### Part 3 - Linked List Management
These functions allow for the creation, allocation, traversing, and systematic freeing of a custom singly-linked list structure (`t_list`).

*   `ft_lstnew` - Initializes a new node component containing arbitrary content.
*   `ft_lstadd_front`, `ft_lstadd_back` - Appends a node safely to either the head or tail of a list.
*   `ft_lstsize` - Iterates down a list to compute total node length.
*   `ft_lstlast` - Traverses to retrieve the final element of a list structure.
*   `ft_lstdelone`, `ft_lstclear` - Safely drops one node or purges an entire list structure using custom memory freeing pointers.
*   `ft_lstiter`, `ft_lstmap` - Applies targeted function iterations to list contents sequentially.

---

## ⚙️ Instructions

### Compilation Requirements
*   **Compiler:** `cc` (or `gcc`/`clang`)
*   **Flags:** `-Wall -Wextra -Werror`

### Compilation Commands
All binaries and objects are built systematically via the provided `Makefile`. Open your shell environment inside the repository and run:

```bash
# Compiles all mandatory files (Parts 1, 2, and 3) and creates 'libft.a'
make

# Removes all intermediate object files (.o) from the directory
make clean

# Deletes object files as well as the compiled 'libft.a' archive file
make fclean

# Performs a full re-compilation from scratch (fclean followed by make)
make re
```

### Execution & Integration
To integrate this library into your other C projects:
1. Include the header file in your codebase:
   ```c
   #include "libft.h"
   ```
2. Compile your source files alongside the static library binary:
   ```bash
   cc main.c -L. -lft -o program_name
   ```

---

## 📚 Resources

### Classic Documentation & References
*   **Built-in System Manuals (`man` pages):** The primary source of truth during development. Accessible directly from the 42 terminal using commands such as `man strlen` or `man 3 memset` to review standard behaviors, return values, and expected types.
*   [C Programming Language (K&R)](https://archive.org) - For classic explanations of data representation and pointer manipulation.
*   [Singly Linked Lists Explained](https://geeksforgeeks.org) - Visualizations regarding node traversal, creation, and pointer reassignment.

### AI Usage Declaration
Artificial Intelligence (Large Language Model) was utilized as an auxiliary learning and verification tool during the development of this project for the following specific tasks:

1. **Unit Testing Framework Expansion:** AI was used to assist in scaling up project defense tests. After manually creating a base unit test for a function, the AI was prompted with specific edge cases (e.g., null pointers, empty strings, buffer overflows, maximum/minimum integer limits) to generate additional robust test cases patterned after the original code structure.
2. **Documentation Generation:** AI assisted in writing, structuring, and formatting this `README.md` file to meet structural campus layout standards.
3. **Behavior and Use Case Clarification:** AI was occasionally consulted to explain the exact expected behaviors, hidden pitfalls, and practical application scenarios of specific standard library functions to align custom behaviors perfectly with native equivalents.

*Note: AI was strictly not used for code generation. All source files (`.c` files), standard structures, core logical pathways, and final algorithms were developed entirely from scratch by the author to protect and complete the pedagogical core of the 42 curriculum.*