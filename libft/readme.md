# libft explain

Write a C library, containing a extract of important functions for the cursus
A Makefile is included. If other project allows to use *libft*, copy its sources and ites associated *Makefile* in a *libft* folder. The project's *Makefile*must compile the library by using its *Makefile*, then compile the project.

## Mandatory part

### Part 1 - Libc functions

re-code a set of the *libc* functions, as defined in their man.

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

#### ft_memset

The function **void \*memset(void \*b, int c, size_t len)** copies the character **c** (an unsigned char) to the first **len** characters of the string pointed to, by the argument **b**.

```C
char str[50] = "This is string.h library function";
ft_memset(4, '$', 7);
printf("%s", str);
ft_memset(str + 4, 'x', 3*sizeof(char));
printf("%s", str);
```

output:  
`$$$$ is string.h library function`  
`$$$$xxx string.h library function`