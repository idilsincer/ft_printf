*This project has been created as part of the 42 curriculum by idsincer.*

# libft

## Description

**libft** is the very first project of the 42 core curriculum. The goal is to build a personal C library, `libft.a`, by re-implementing a large set of standard C library functions (from `<string.h>`, `<ctype.h>`, `<stdlib.h>`, etc.) from scratch, without using their libc equivalents.

Beyond just recreating existing functions, the project also asks you to design and implement a few additional utility functions (string manipulation, memory allocation helpers, file-descriptor output helpers) and, as a bonus, a small **singly linked list** toolkit.

## Instructions

### Compilation

The library is compiled with a `Makefile` that respects the standard 42 rules:

| Rule       | Description                                      |
|------------|---------------------------------------------------|
| `make`     | Compiles all mandatory + bonus objects and creates `libft.a` |
| `make all` | Same as `make`                                    |
| `make clean` | Removes the `.o` object files                   |
| `make fclean` | Removes the `.o` files **and** `libft.a`       |
| `make re`  | Equivalent to `fclean` followed by `all`          |

cd libft
make
```

This produces `libft.a` at the root of the repository.

### Using the library in another project

1. Copy or add this repository (e.g. as a git submodule) to your project.
2. Include the header in your source files:

```c
#include "libft.h"
```

3. Compile and link against the archive:

```bash
cc -Wall -Wextra -Werror your_files.c -Ilibft -Llibft -lft -o your_program
```

Or, in a `Makefile`:

```makefile
LIBFT_DIR = libft
LIBFT     = $(LIBFT_DIR)/libft.a

$(LIBFT):
	make -C $(LIBFT_DIR)

your_program: your_files.o $(LIBFT)
	cc your_files.o -L$(LIBFT_DIR) -lft -o your_program
```

## Library Description

`libft.h` declares every function below. All functions are implemented in individual `.c` files (one function per file, as required by the norm).

### Part 1 — Libc function re-implementations

| Function        | Role |
|------------------|------|
| `ft_isalpha`     | Checks if a character is a letter |
| `ft_isdigit`     | Checks if a character is a digit |
| `ft_isalnum`     | Checks if a character is alphanumeric |
| `ft_isascii`     | Checks if a character belongs to the ASCII range |
| `ft_isprint`     | Checks if a character is printable |
| `ft_strlen`      | Returns the length of a string |
| `ft_memset`      | Fills a memory area with a given byte |
| `ft_bzero`       | Fills a memory area with zeros |
| `ft_memcpy`      | Copies a memory area (no overlap guarantee) |
| `ft_memmove`     | Copies a memory area, safe with overlap |
| `ft_strlcpy`     | Copies a string, size-bounded (BSD `strlcpy`) |
| `ft_strlcat`     | Concatenates strings, size-bounded (BSD `strlcat`) |
| `ft_toupper`     | Converts a character to uppercase |
| `ft_tolower`     | Converts a character to lowercase |
| `ft_strchr`      | Locates a character in a string (first occurrence) |
| `ft_strrchr`     | Locates a character in a string (last occurrence) |
| `ft_strncmp`     | Compares two strings up to `n` bytes |
| `ft_memchr`      | Locates a byte in a memory area |
| `ft_memcmp`      | Compares two memory areas |
| `ft_strnstr`     | Locates a substring within a size-bounded string |
| `ft_atoi`        | Converts a string to an `int` |

### Part 2 — Additional functions

| Function          | Role |
|-------------------|------|
| `ft_calloc`       | Allocates and zero-initializes memory |
| `ft_strdup`       | Duplicates a string on the heap |
| `ft_substr`       | Allocates and returns a substring |
| `ft_strjoin`      | Concatenates two strings into a newly allocated one |
| `ft_strtrim`      | Trims leading/trailing characters from a set |
| `ft_split`        | Splits a string into an array of strings using a delimiter |
| `ft_itoa`         | Converts an `int` to a newly allocated string |
| `ft_strmapi`      | Applies a function to each character, returning a new string |
| `ft_striteri`     | Applies a function to each character in place, with its index |
| `ft_putchar_fd`   | Writes a character to a given file descriptor |
| `ft_putstr_fd`    | Writes a string to a given file descriptor |
| `ft_putendl_fd`   | Writes a string followed by a newline to a file descriptor |
| `ft_putnbr_fd`    | Writes an `int` to a given file descriptor |

### Singly linked list

A minimal linked list toolkit, based on the `t_list` structure:

```c
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
```

| Function          | Role |
|-------------------|------|
| `ft_lstnew`       | Creates a new list node |
| `ft_lstadd_front` | Adds a node at the beginning of the list |
| `ft_lstsize`      | Counts the number of nodes in a list |
| `ft_lstlast`      | Returns the last node of a list |
| `ft_lstadd_back`  | Adds a node at the end of the list |
| `ft_lstdelone`    | Frees the content and the node of a single element |
| `ft_lstclear`     | Frees an entire list, node by node |
| `ft_lstiter`      | Applies a function to each node's content |
| `ft_lstmap`       | Creates a new list by applying a function to each node's content |

## Resources

Classic references used while working on this project:
- [The C Programming Language – Kernighan & Ritchie](https://en.wikipedia.org/wiki/The_C_Programming_Language) — foundational reference on C semantics.
- [man7.org Linux man-pages](https://man7.org/linux/man-pages/) — used to check the exact prototype and edge-case behavior of each original libc function (`man 3 <function>`).
- [BSD man pages for `strlcpy`/`strlcat`](https://man.openbsd.org/strlcpy.3) — since these functions are not part of standard glibc.
- [cppreference.com](https://en.cppreference.com/w/c) — quick reference for standard C library behavior.

### AI usage

AI assistance (Claude) was used during this project for:
- Explaining the expected edge-case behavior of certain libc functions (e.g. `NULL` handling in `ft_strlcpy`, `size` of `0` in `ft_memcpy`) before implementing them manually.
- Reviewing draft implementations for logic errors and suggesting test cases (empty strings, overlapping buffers, negative numbers for `ft_atoi`/`ft_itoa`).
- Helping structure and format this README.
All actual function implementations were written and tested by hand to comply with the 42 subject's rules (no external code generation was used for the source files themselves).