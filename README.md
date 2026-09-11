*This project has been created as part of the 42 curriculum by schoinsk.*

# ft_printf - @42Born2Code

## 📝 Description

**ft_printf** is a crucial project in the 42 Common Core curriculum. The goal of this project is to mimic the behavior of the standard C library's `printf` function, providing a deeper understanding of variadic functions (`va_list`) in C, structured string parsing, and low-level data formatting.

Instead of relying on high-level printing functions, this project requires building a robust, versatile formatter from scratch. The resulting custom function (`ft_printf`) will be compiled into a static library (`libftprintf.a`) and will replace standard output utilities in subsequent 42 projects. The implementation strictly complies with the school's coding standard (**The Norm**), ensuring highly optimized, clean, and readable code.


## 🛠️ Detailed Library Description

The core engine parses an input string character by character, routing formatting placeholders starting with `%` to specialized helper functions based on their specific type identifier.

### Supported Conversions
The library accurately handles the following standard format specifiers:

*   **Characters & Strings:**
    *   `%c` - Prints a single character.
    *   `%s` - Prints a character string (handles `NULL` string pointers safely).
    *   `%%` - Prints a single literal percentage sign.
*   **Pointers & Addresses:**
    *   `%p` - Prints a `void *` pointer argument in hexadecimal format, preceded by `0x`.
*   **Numbers & Integers:**
    *   `%d` - Prints a decimal (base 10) number.
    *   `%i` - Prints an integer in base 10.
    *   `%u` - Prints an unsigned decimal (base 10) number.
*   **Hexadecimals:**
    *   `%x` - Prints a number in hexadecimal (base 16) lowercase format (`0123456789abcdef`).
    *   `%X` - Prints a number in hexadecimal (base 16) uppercase format (`0123456789ABCDEF`).

## 🧠 Algorithm & Data Structure Justification

### 1. Algorithm: Single-Pass Tokenization and Stream Routing
The core engine implements a deterministic **Single-Pass Stream Parsing** algorithm. 
* **Mechanism:** The function iterates through the input string using a single loop pointer. Characters are written directly to the standard output until a `%` delimiter is encountered. 
* **Justification:** This approach achieves an optimal time complexity of **O(N)**, where N is the length of the format string. It minimizes CPU cycles and memory access by processing each byte exactly once. Memory allocation overhead is completely avoided because formatting and conversion happen on-the-fly directly to the output stream.

### 2. Data Structure: Variadic Arguments Stock (`va_list`)
The primary data structure utilized is the native **`va_list` structure**, manipulated strictly via standard macro utilities (`va_start`, `va_arg`, `va_end`).
* **Mechanism:** Since the number and types of arguments are unknown at compile time, `va_list` allows the system to traverse the execution stack frame and extract data sequentially based on the type discovered during the string parsing pass.
* **Justification:** Using `va_list` ensures low-level memory efficiency. Arguments are fetched directly from hardware registers or the stack without duplicating data structures into heap-allocated arrays. This guarantees compliance with strict memory constraints while matching the native runtime behavior of the standard C library.

---

## ⚙️ Instructions

### Compilation Requirements
*   **Compiler:** `cc` (or `gcc`/`clang`)
*   **Flags:** `-Wall -Wextra -Werror`

### Compilation Commands
All binaries and objects are built systematically via the provided `Makefile`. Open your shell environment inside the repository and run:

```bash
# Compiles all source files and creates the 'libftprintf.a' static library
make

# Removes all intermediate object files (.o) from the directory
make clean

# Deletes object files as well as the compiled 'libftprintf.a' archive file
make fclean

# Performs a full re-compilation from scratch (fclean followed by make)
make re
```

### Execution & Integration
To integrate this printing library into your other C projects:
1. Include the header file in your codebase:
   ```c
   #include "ft_printf.h"
   ```
2. Compile your source files alongside the static library binary:
   ```bash
   cc main.c -L. -lftprintf -o program_name
   ```

---

## 📚 Resources

### Classic Documentation & References
*   **Built-in System Manuals (`man` pages):** The primary source of truth during development. Accessible directly from the 42 terminal using commands such as `man 3 printf` or `man stdarg` to review variadic macro definitions (`va_start`, `va_arg`, `va_copy`, `va_end`).

### AI Usage Declaration
Artificial Intelligence (Large Language Model) was utilized as an auxiliary learning and verification tool during the development of this project for the following specific tasks:

1. **Unit Testing Framework Expansion:** AI was used to assist in scaling up project defense tests. After manually creating a base unit test for a function, the AI was prompted with specific edge cases (e.g., minimum/maximum integer limits, long hexadecimal values, `NULL` pointers, and consecutive percentage signs) to generate additional robust test cases patterned after the original code structure.
2. **Documentation Generation:** AI assisted in writing, structuring, and formatting this `README.md` file to meet structural campus layout standards established in previous repository frameworks.
3. **Behavior and Use Case Clarification:** AI was occasionally consulted to explain the exact expected return values (byte counts) and error behaviors of standard `printf` to align custom behaviors perfectly with native equivalents.

*Note: AI was strictly not used for code generation. All source files (`.c` files), structural pathways, variadic macros setups, and formatting algorithms were developed entirely from scratch by the author to protect and complete the pedagogical core of the 42 curriculum.*
