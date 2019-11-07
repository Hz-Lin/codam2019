# libft explain

Write a C library, containing a extract of important functions for the cursus
A Makefile is included. If other project allows to use *libft*, copy its sources and ites associated *Makefile* in a *libft* folder. The project's *Makefile*must compile the library by using its *Makefile*, then compile the project.

## Mandatory part

### Part 1 - Libc functions

re-code a set of the *libc* functions, as defined in their man.

#### ft_memset

The function **void \*memset(void \*b, int c, size_t len)** copies the character **c** (an unsigned char) to the first **len** characters of the string pointed to, by the argument **b**.

```C
char str[50] = "This is string.h library function";
ft_memset(str, '$', 7);
printf("%s\n", str);
ft_memset(str + 4, 'x', 3*sizeof(char));
printf("%s\n", str);
```

output:  
`$$$$ is string.h library function`  
`$$$$xxx string.h library function`

#### ft_bzero

The fuction **void	ft_bzero(void \*s, size_t n)** writes **n** zeroed bytes to the string **s**.  If n is zero, ft_bzero() does nothing.

#### ft_memcpy

The function **void	\*ft_memcpy(void \*dst, const void \*src, size_t n)** copies n bytes from memory area src to memory area dst.  If dst and src overlap, behavior is undefined. It returns the original value of dst.

#### ft_memccpy

The function **void \*ft_memccpy(void \*dst, const void \*src, int c, size_t n)** copies bytes from string **src** to string **dst**.  If the character **c** (as converted to an unsigned char) occurs in the string **src**, the copy stops and a pointer to the byte after the copy of **c** in the string **dst** is returned.  Otherwise, n bytes are copied, and a NULL pointer is returned. The source and destination strings should not overlap, as the behavior is undefined.

#### ft_memmove

The function **void \*ft_memmove(void *dst, const void \*src, size_t len)** opies len bytes from string **src** to string **dst**.  The two strings may overlap; the copy is always done in a non-destructive manner.It returns the original value of **dst**.

#### ft_memchr

The function **void \*ft_memchr(const void \*s, int c, size_t n)** locates the first occurrence of **c** (converted to an unsigned char) in string **s**. It returns a pointer to the byte located, or NULL if no such byte exists within n bytes.

#### ft_memcmp

The fuction **int ft_memcmp(const void \*s1, const void \*s2, size_t n)** compares byte string **s1** against byte string **s2**.  Both strings are assumed to be **n** bytes long. It returns zero if the two strings are identical, otherwise returns the difference between the first two differing bytes (treated as unsigned char values). Zero-length strings are always identical.

#### ft_strlen

The function **size_t  ft_strlen(const char \*s)** computes the length of the string **s** up to, but not including the terminating null character.

#### ft_strlcpy

The function **ft_strlcpy(char \*dst, const char \*src, size_t dstsize)** takes the destination's size **dstsize** as a parameter and will not write more than that many bytes, to prevent buffer overflow (assuming size is correct). But, unlike *strncpy*, ft_strlcpy always writes a single NUL byte to the **dst** (if size is not zero). The resulting string is guaranteed to be NUL-terminated even if truncated. Also it does not waste time writing multiple NUL bytes to fill the rest of the buffer, unlike *strncpy*. In addition, it counts and returns the length of the entire source string. This length can be compared to the destination buffer's size to check if it was truncated, and to work around truncation.

#### ft_strlcat

The function **ft_strlcat(char \*dst, const char \*src, size_t dstsize)** appends the NUL-terminated string **src** to the end of **dst**. It will append at most **dsize - strlen(dst) - 1 bytes**, NUL-terminating the result. Returns **length of src + min(dstsize,length of orgin dst)**;

#### ft_strchr

The function **char \*ft_strchr(const char \*str, int c)** searches for the first occurrence of the character **c** (an unsigned char) in the string pointed to by the argument **str**. This returns a pointer to the first occurrence of the character c in the string str, or NULL if the character is not found.

#### ft_strrchr

The **ft_strrchr()** function is identical to **ft_strchr()**, except it locates the last occurrence of **c**. It return a pointer to the located character, or NULL if the character does not appear in the string.

#### ft_strnstr

The function **char \*strnstr(const char \*str, const char \*needle, size_t len)** locates the first occurrence of the null-terminated string **needle** in the string **str**, where not more than **len** characters are searched. Characters thar appeat after a '\0' character are not searched. It returns a pointer to the first character of the first occurrence of **needle**. If **needle** is an empty string, **str** is returned. If **needle** occurs nowhere in **str**, NULL is returnede.

#### ft_strncmp

The function **int	ft_strncmp(const char \*s1, const char \*s2, size_t n)** compares not more than **n** characters, characters that appear after a '\0' character are not compared. It returns an integer greater than, equal to, or less than 0, according as the string **s1** is greater than, equal to, or less than the string **s2**.  The comparison is done using unsigned characters, so that '\200'is greater than '\0'.

#### ft_atoi

The function **int ft_atoi(const char \*str)** converts the string argument **str** to an integer. This function returns the converted integral number as an int value. If no valid conversion could be performed, it returns zero.

#### ft_isalpha

The function **int ft_isalpha(int c)** returns zero if the character tests false and returns non-zero if the character tests true.

#### ft_isdigit

The function **int	ft_isdigit(int c)** tests for a decimal digit character. It returns zero if the character tests false and return non-zero if the character tests true.

#### ft_isalnum

The function **int ft_isalnum(int c)** tests for any character for which *isalpha(3)* or *isdigit(3)* is true. It returns zero if the character tests false and returns non-zero if the character tests true.

#### ft_isascii

The function **int	ft_isascii(int c)** tests for an ASCII character, which is any character between 0 and octal 0177 inclusive.

#### ft_isprint

The function **int ft_isprint(int c)** tests for any printing character, including space. It returns zero if the character tests false and returns non-zero if the character tests true.

#### ft_toupper

The function **int ft_toupper(int c)** converts a lower-case letter to the corresponding upper-case letter. If the argument is a lower-case letter, the returns the corresponding upper-case letter if there is one; otherwise, the argument is returned unchanged.

#### ft_tolower

The function **int ft_tolower(int c)** converts an upper-case letter to the corresponding lower-case letter. If the argument is an upper-case letter, the function returns the corresponding lower-case letter if there is one; otherwise, the argument is returned unchanged.

#### ft_calloc

The function **void \*ft_calloc(size_t count, size_t size)** contiguously allocates enough space for **count** objects that are **size** bytes of memory each and returns a pointer to the allocated memory.  The allocated memory is filled with bytes of value *zero*. It returns a pointer to allocated memory. If there is an error, it qreturn a NULL pointer.

#### ft_strdup

The function **char \*ft_strdup(const char \*str)** allocates sufficient memory for a copy of the string **str**, does the copy, and returns a pointer to it.

### Part 2 - Additional functions
