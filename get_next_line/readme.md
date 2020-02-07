# Get Next Line notes

## static variables  

In computer programming, a static variable is a variable that has been allocated "statically", meaning that its lifetime (or "extent") is the entire run of the program. This is in contrast to shorter-lived automatic variables, whose storage is stack allocated and deallocated on the call stack; and in contrast to objects, whose storage is dynamically allocated and deallocated in heap memory.  
Variable lifetime is contrasted with scope (where a variable can be used): "global" and "local" refer to scope, not lifetime, but scope often implies lifetime. In many languages, global variables are always static, but in some languages they are dynamic, while local variables are generally automatic, but may be static.  
In general, static memory allocation is the allocation of memory at compile time, before the associated program is executed, unlike dynamic memory allocation or automatic memory allocation where memory is allocated as required at run time.  
In terms of scope and extent, static variables have extent the entire run of the program, but may have more limited scope. A basic distinction is between a static global variable, which has global scope and thus is in context throughout the program, and a static local variable, which has local scope. A static local variable is different from a local variable as a static local variable is initialized only once no matter how many times the function in which it resides is called and its value is retained and accessible through many calls to the function in which it is declared, e.g. to be used as a count variable. A static variable may also have module scope or some variant, such as internal linkage in C, which is a form of file scope or module scope.  

**Prototype**

int	get_next_line(int fd, char **line);  

- fd: file descriptor for reading
- line: the value of what has been read

**Turn in files**

get_next_line.c  
get_next_line_utils.c  
get_next_line.h  

**Return value**

- 1:  a line has been read
- 0:  EOF has been reached
- -1: an error happened

**Allowed external functions**

read, malloc, free

## Mandatory part

- read the text available on a file descriptor one line at a time until the EOF
- behaves well when it reads from a file, from the standard output
- must add a **get_next_line_utils.c** file which will contain necessary functions for your get_next_line to work
- must compile with the flag **-D BUFFER_SIZE=xx**
- compilation will be done this way : **gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c**
- **read** must use the **BUFFER_SIZE** defined during compilation to read from a file or stdin

## Bonus part

- To succeed get_next_line with a single static variable
- To be able to manage multiple file descriptor
