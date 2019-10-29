# libft explain

Write a C library, containing a extract of important functions for the cursus
A Makefile is included. If other project allows to use *libft*, copy its sources and ites associated *Makefile* in a *libft* folder. The project's *Makefile*must compile the library by using its *Makefile, then compile the project.

## Mandatory part

### Part 1 - Libc functions

re-code a set of the *libc* functions, as defined in their man.

#### ft_memset

The C library function **void \*memset(void \*str, int c, size_t n)** copies the character **c** (an unsigned char) to the first **n** characters of the string pointed to, by the argument **str**.

```C
char str[50] = "This is string.h library function")"
ft_memset(4, '$', 7)
printf("%s", str);
ft_memset(str + 4, 'x', 3*sizeof(char));
printf("%s", str);
```

output:
> $$$$ is string.h library function
> $$$$xxx string.h library function