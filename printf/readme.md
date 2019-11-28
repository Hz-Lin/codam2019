# printf project notes

## Project Introduction

This project is to write a lib with ft_printf function that will mimic the real printf.  
External functions allowed are: malloc, free, write, va_start, va_arg, va_copy, va_end  

**Mandatory part**

- The prototype of ft_printf should be int ft_printf(const char *, ...);
- You have to recode the libc’s printf function
- It must not do the buffer management like the real printf
- It will manage the following conversions: cspdiuxX%
- It will manage any combination of the following flags: ’-0.*’ and minimum field witdh
- It will be compared with the real printf

**Bonus part**

- If the Mandatory part is not perfect don’t even think about bonuses
- You don’t need to do all the bonuses
- Manage one or more of the following conversions: nfge
- Manage one or more of the following flags: l ll h hh
- Manage all the following flags: ’# +


## stdarg Funtions

**stdarg** -- variable argument lists: contains funtions va_start, va_arg, va_copy and va_end.  
The include file <**stdarg.h**> declares a type (**va_list**) and defines three macros for stepping through a list of arguments whose number and types are not known to the called function. The called function must declare an object of type va_list which is used by the macros.

### va_start

**synopsis**	void	va_start(va_list ap, last);  
This macro must be called first, and it initializes **ap**, which can be passed to **va_arg()** for each argument to be processed. Note that each call to **va_start()** must be matched by a call to **va_end()**, from within the same function.  
The parameter **last** is the name of the last parameter before the variable argument list, i.e., the last parameter of which the calling function knows the type. Because the address of this parameter is used in the **va_start()** macro, it should not be declared as a register variable, or as a function or an array type.

### va_arg

**synopsis**	type	va_arg(va_list ap, type);  
The **va_arg()** macro expands to an expression that has the type and value of the next argument in the call. The parameter **ap** is the **va_list ap** initialized by **va_start()**.  Each call to **va_arg()** modifies **ap** so that the next call returns the next argument. The parameter type is a type name specified so that the type of a pointer to an object that has the specified type can be obtained simply by adding a * to **type**.  
If there is no next argument, or if **type** is not compatible with the type of the actual next argument (as promoted according to the default argument promotions), random errors will occur.  
The first use of the **va_arg()** macro after that of the **va_start()** macro returns the argument after **last**. Successive invocations return the values of the remaining arguments.

### va_copy

**synopsis**	void	va_copy(va_list dest, va_list src);  
The **va_copy()** macro copies the state of the variable argument list, **src**, previously initialized by **va_start()**, to the variable argument list, **dest**, which must not have been previously initialized by **va_start()**, without an intervening call to **va_end()**. The state preserved in **dest** is equivalent to calling **va_start()** and **va_arg()** on dest in the same way as was used on **src**. The copied variable argument list can subsequently be passed to **va_arg()**, and must finally be passed to **va_end()** when through with it.

### va_end

**synopsis**	void	va_end(va_list ap);  
Calling **va_end()** signals that there are no further arguments, and causes ap to be invalidated. After a variable argument list is invalidated by **va_end()**, it can be reinitialized with **va_start()** or made a copy of another variable argument list with **va_copy()**.

### example

```C
/* The function foo takes a string of format characters and 
   prints out the argument associated with each format character based on the type.
*/

void foo(char *fmt, ...)
{
    va_list ap, ap2;
    int d;
    char c, *s;

    va_start(ap, fmt);
    va_copy(ap2, ap);
    while (*fmt)
        switch(*fmt++)
		{
        	case 's':                       /* string */
            	s = va_arg(ap, char *);
            	printf("string %s\n", s);
            	break;
        	case 'd':                       /* int */
            	d = va_arg(ap, int);
            	printf("int %d\n", d);
            	break;
        	case 'c':                       /* char */
            	/* Note: char is promoted to int. */
            	c = va_arg(ap, int);
            	printf("char %c\n", c);
            	break;
        }
        va_end(ap);
        ...
        /* use ap2 to iterate over the arguments again */
        ...
        va_end(ap2);
}
```
## libc's printf funtion

The printf() function write output to stdout, the standard output stream; It write the output under the control of a **format** string that specifies how subsequent arguments (or arguments accessed via the variable-length argument facilities of stdarg(3)) are converted for output.  
The format string is composed of zero or more directives:  
- ordinary characters (not %), which are copied unchanged to the output stream;
- conversion specifications, each of which results in fetching zero or more subsequent arguments. Each conversion specification is introduced by the % character.

### synopsis
\#include \<stdio.h\>
int	printf(const char *restrict_format, ...);

### conversions flags and minimum field width

The arguments must correspond properly (after type promotion) with the conversion specifier. After the %, the following appear in sequence:

1. An optional field, consisting of a decimal digit string followed by a $, specifying the next argument to access.  If this field is not provided, the argument following the last argument accessed will be used.  Arguments are numbered starting at 1.  If unaccessed arguments in the format string are interspersed with ones that are accessed the results will be indeterminate.

2. Zero or more of the following flags:
- **#**  