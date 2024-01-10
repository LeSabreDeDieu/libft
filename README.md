# Libft - A Custom C Library

## Table of Contents

- [Introduction](#introduction)
- [Project Structure](#project-structure)
- [Header File - libft.h](#header-file-libfth)
- [Functions Overview](#functions-overview)
  - [Mandatory Functions](#mandatory-functions)
  - [Bonus Functions](#bonus-functions)
- [Compilation](#compilation)
- [Usage](#usage)
- [Author](#author)

## Introduction

Libft is a custom C library that provides a collection of functions for various tasks, including string and memory manipulation, linked list operations, and more. It is designed to be a useful toolkit for C programming.

## Project Structure

The project is organized into directories, each containing functions related to a specific category. Here's an overview of the project structure:

```
.
├── ft_is
├── ft_lst
├── ft_mem
├── ft_put
├── ft_str
├── ft_to
├── gnl
├── includes
├── Makefile
└── README.md
```

- `ft_is`: Functions for character type checks.
- `ft_lst`: Functions for linked list manipulation.
- `ft_mem`: Functions for memory manipulation.
- `ft_put`: Functions for outputting characters and strings.
- `ft_str`: Functions for string manipulation.
- `ft_to`: Functions for character case conversions.
- `gnl`: Functions related to the `get_next_line` feature.
- `includes`: Header files directory.
- `Makefile`: Makefile for project compilation.
- `README.md`: Project documentation.

## Header File - libft.h

The `libft.h` header file contains declarations for all the functions provided by the Libft library. It includes necessary standard libraries, defines `BUFFER_SIZE` for `get_next_line`, and defines a linked list structure (`t_list`) for the bonus part.

## Functions Overview

### Mandatory Functions

- `ft_strchr`
- `ft_strrchr`
- `ft_strnstr`
- `ft_substr`
- `ft_strjoin`
- `ft_strtrim`
- `ft_strmapi`
- `ft_split`
- `ft_itoa`
- `ft_atoi`
- `ft_isalnum`
- `ft_isalpha`
- `ft_isascii`
- `ft_isdigit`
- `ft_isprint`
- `ft_toupper`
- `ft_tolower`
- `ft_memcmp`
- `ft_strncmp`
- `ft_strlcpy`
- `ft_strlcat`
- `ft_strlen`
- `ft_memset`
- `ft_memchr`
- `ft_memcpy`
- `ft_memmove`
- `ft_bzero`
- `ft_striteri`
- `ft_calloc`
- `ft_strdup`
- `ft_putchar_fd`
- `ft_putstr_fd`
- `ft_putendl_fd`
- `ft_putnbr_fd`

### Bonus Functions
- `ft_lstnew`
- `ft_lstlast`
- `ft_lstmap`
- `ft_lstadd_front`
- `ft_lstadd_back`
- `ft_lstdelone`
- `ft_lstclear`
- `ft_lstiter`
- `ft_lstsize`

### ADDITION FUNCTION

- get_next_line

## Compilation

To compile the project, use the provided `Makefile` with the command:

```bash
make all
```

This will generate the `libft.a` library in the project's root directory.

## Usage

To use Libft in your project, include the `libft.h` header file in your source files and compile your project by linking with `libft.a`.

Example compilation command:

```bash
gcc -o my_program my_sources.c libft.a -I.
```

## Author

sgabsi
