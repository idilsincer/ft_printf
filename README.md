*This project has been created as part of the 42 curriculum by idsincer.*
 
# ft_printf
 
## Description
 
`ft_printf` is a from-scratch reimplementation of the C standard library function `printf`. The goal of the project is to learn how **variadic functions** work in C (`<stdarg.h>`), how to parse a format string, and how to structure a program so that new conversions can be added without rewriting it.
 
The function is compiled into a static library, `libftprintf.a`, with the same prototype as the original:
 
```c
int ft_printf(const char *format, ...);
```
 
It writes to standard output and returns the number of characters printed, or `-1` if an error occurs (for example a failed `write`, or a format string that ends with a lone `%`).
 
### Supported conversions
 
| Conversion | Output |
|------------|--------|
| `%c` | a single character |
| `%s` | a string (`(null)` if the pointer is `NULL`) |
| `%p` | a `void *` pointer in hexadecimal, prefixed with `0x` (`(nil)` if `NULL`) |
| `%d` / `%i` | a signed decimal integer |
| `%u` | an unsigned decimal integer |
| `%x` | an unsigned integer in lowercase hexadecimal |
| `%X` | an unsigned integer in uppercase hexadecimal |
| `%%` | a literal percent sign |
 
## Instructions
 
### Compilation
 
```sh
make        # builds libftprintf.a
make clean  # removes object files
make fclean # removes object files and the library
make re     # fclean + all
```
 
The code is compiled with `cc -Wall -Wextra -Werror`.
 
## Resources
 
- `man 3 printf`: behaviour of the original function (https://man7.org/linux/man-pages/man3/printf.3.html)
- `man 3 stdarg`: `va_start`, `va_arg`, `va_end`, `va_copy` (https://man7.org/linux/man-pages/man3/stdarg.3.html)
- `man 2 write`: return value and error cases (https://man7.org/linux/man-pages/man2/write.2.html)
- ISO/IEC 9899 (the C standard), section on variable arguments `<stdarg.h>` and on the `fprintf` function
- B. Kernighan and D. Ritchie, *The C Programming Language*, 2nd edition: chapter 7 (input and output) and the section on variable-length argument lists
- The 42 Norm and the `ft_printf` subject
### Use of AI
 
AI assistants (Claude, Gemini, ChatGPT) was used for the following tasks:
 
- **Code review:** finding bugs in my first version (the `va_list` passed by value, the read past the end of the string when the format ends with `%`, missing `va_end` on early returns, unchecked `write` results).
- **Testing:** writing a test program that compares the output and the return value of `ft_printf` with the real `printf`.
- **Documentation:** drafting this README.
