# Libft

Libft is a library of standard C functions, developed by sgabsi. This library provides custom implementations of libc functions as well as additional useful functions.

## Contents

- **libft.h:** This header file contains prototypes of functions included in the library, as well as the definition of the `t_list` structure used for bonus functions.
- **libft.a:** The compiled static library containing implementations of the functions.

## Usage

To use the libft library in your project:

1. Clone the repository: `git clone https://github.com/LeSabreDeDieu/libft-42.git`
2. Include the `libft.h` file in your source files: `#include "libft.h"`
3. Compile your files with `libft.a`: `gcc -o my_program my_program.c libft.a`

Make sure to include `libft.h` in your source files where you use functions from the library.

## Main Functions

The libft library includes functions for string manipulation, memory manipulation, type conversion, list manipulation, and more. Main functions include:

- String manipulation: `ft_strlen`, `ft_strchr`, `ft_strjoin`, `ft_substr`, etc.
- Memory manipulation: `ft_memcpy`, `ft_memset`, `ft_memmove`, etc.
- Type conversion: `ft_atoi`, `ft_itoa`, etc.
- List functions: `ft_lstnew`, `ft_lstadd_back`, `ft_lstiter`, etc.

## Bonus Functions

The libft library also provides bonus functions for handling linked lists, offering additional features for data management.

## How to Contribute

Contributions are welcome! If you'd like to add new features, fix bugs, or enhance performance, feel free to submit a pull request.

Please refer to the CONTRIBUTING.md file for detailed instructions on contributing to the project.

## Authors

- sgabsi

Feel free to reach out with any questions or suggestions!

