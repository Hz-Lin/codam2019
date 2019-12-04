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

### synopsis

```C
#include <stdio.h>  
int	printf(const char *restrict_format, ...);
```

### return value

Upon successful return, these functions return the number of characters printed (excluding the null byte used to end output to strings). If an output error is encountered, a negative value is returned.

### format of the format string

The format string is composed of zero or more directives:  
- ordinary characters (not %), which are copied unchanged to the output stream;
- conversion specifications, each of which results in fetching zero or more subsequent arguments. Each conversion specification is introduced by the character **%**, and ends with a **conversion specifier**. In between there may be (in this order) zero or more **flags**, an optional **minimum field width**, an optional **precision** and an optional **length modifier**.  

The arguments must correspond properly (after type promotion) with the conversion specifier. By default, the arguments are used in the order given, where each **\*** and each conversion specifier asks for the next argument (and it is an error if insufficiently many arguments are given). One can also specify explicitly which argument is taken, at each place where an argument is required, by writing %m$ instead of % and \*m$ instead of \*, where the decimal integer *m* denotes the position in the argument list of the desired argument, indexed starting from 1. Thus,  
	printf("%*d", width, num);  
and  
	printf("%2$*1$d", width, num);  
are equivalent. The second style allows repeated references to the same argument. The C99 standard does not include the style using '$', which comes from the Single UNIX Specification. If the style using '$' is used, it must be used throughout for all conversions taking an argument and all width and precision arguments, but it may be mixed with "%%" formats which do not consume an argument. There may be no gaps in the numbers of arguments specified using '$'; for example, if arguments 1 and 3 are specified, argument 2 must also be specified somewhere in the format string.  
For some numeric conversions a radix character ("decimal point") or thousands' grouping character is used. The actual character used depends on the LC_NUMERIC part of the locale. The POSIX locale uses '.' as radix character, and does not have a grouping character. Thus,  
	printf("%'.2f", 1234567.89);  
results in "1234567.89" in the POSIX locale, in "1234567,89" in the nl_NL locale, and in "1.234.567,89" in the da_DK locale.

### the flag characters

The character **%** is followed by zero or more of the following flags:  

**-**  
The converted value is to be left adjusted on the field boundary. (The default is right justification.) Except for n conversions, the converted value is padded on the right with blanks, rather than on the left with blanks or zeros. A - overrides a 0 if both are given.

**0**  
The value should be zero padded. For d, i, o, u, x, X, a, A, e, E, f, F, g, and G conversions, the converted value is padded on the left with zeros rather than blanks. If the 0 and - flags both appear, the 0 flag is ignored. If a precision is given with a numeric conversion (d, i, o, u, x, and X), the 0 flag is ignored. For other conversions, the behavior is undefined.  

The five flag characters above are defined in the C standard. The SUSv2 specifies one further flag character.  
**'**  
For decimal conversion (i, d, u, f, F, g, G) the output is to be grouped with thousands' grouping characters if the locale information indicates any. Note that many versions of gcc(1) cannot parse this option and will issue a warning. SUSv2 does not include %'F.  

**\#**  
The value should be converted to an "alternate form". For o conversions, the first character of the output string is made zero (by prefixing a 0 if it was not zero already). For x and X conversions, a nonzero result has the string "0x" (or "0X" for X conversions) prepended to it. For a, A, e, E, f, F, g, and G conversions, the result will always contain a decimal point, even if no digits follow it (normally, a decimal point appears in the results of those conversions only if a digit follows). For g and G conversions, trailing zeros are not removed from the result as they would otherwise be. For other conversions, the result is undefined.  

**' '**  
(a space) A blank should be left before a positive number (or empty string) produced by a signed conversion.  

**+**  
A sign (+ or -) should always be placed before a number produced by a signed conversion. By default a sign is used only for negative numbers. A + overrides a space if both are used.   

### The field width

An optional decimal digit string (with nonzero first digit) specifying a minimum field width. If the converted value has fewer characters than the field width, it will be padded with spaces on the left (or right, if the left-adjustment flag has been given). Instead of a decimal digit string one may write "\*" or "\*m$" (for some decimal integer m) to specify that the field width is given in the next argument, or in the m-th argument, respectively, which must be of type *int*. A negative field width is taken as a '-' flag followed by a positive field width. In no case does a nonexistent or small field width cause truncation of a field; if the result of a conversion is wider than the field width, the field is expanded to contain the conversion result.

### The precision

An optional precision, in the form of a period ('.') followed by an optional decimal digit string. Instead of a decimal digit string one may write "\*" or "\*m$" (for some decimal integer m) to specify that the precision is given in the next argument, or in the m-th argument, respectively, which must be of type int. If the precision is given as just '.', or the precision is negative, the precision is taken to be zero. This gives the minimum number of digits to appear for d, i, o, u, x, and X conversions, the number of digits to appear after the radix character for a, A, e, E, f, and F conversions, the maximum number of significant digits for g and G conversions, or the maximum number of characters to be printed from a string for s and S conversions.

### The length modifier

Here, "integer conversion" stands for **d**, **i**, **o**, **u**, **x**, or **X** conversion.

**hh**  
A following integer conversion corresponds to a signed char or unsigned char argument, or a following n conversion corresponds to a pointer to a signed char argument.

**h**  
A following integer conversion corresponds to a short int or unsigned short int argument, or a following n conversion corresponds to a pointer to a short int argument.

**l**  
(ell) A following integer conversion corresponds to a long int or unsigned long int argument, or a following n conversion corresponds to a pointer to a long int argument, or a following c conversion corresponds to a wint_t argument, or a following s conversion corresponds to a pointer to wchar_t argument.

**ll**  
(ell-ell). A following integer conversion corresponds to a long long int or unsigned long long int argument, or a following n conversion corresponds to a pointer to a long long int argument.

### The conversion specifier

A character that specifies the type of conversion to be applied. The conversion specifiers and their meanings are:  

**c**  
If no l modifier is present, the int argument is converted to an unsigned char, and the resulting character is written. If an l modifier is present, the wint_t (wide character) argument is converted to a multibyte sequence by a call to the wcrtomb(3) function, with a conversion state starting in the initial state, and the resulting multibyte string is written.

**s**  
If no l modifier is present: The const char * argument is expected to be a pointer to an array of character type (pointer to a string). Characters from the array are written up to (but not including) a terminating null byte ('\0'); if a precision is specified, no more than the number specified are written. If a precision is given, no null byte need be present; if the precision is not specified, or is greater than the size of the array, the array must contain a terminating null byte.  
If an l modifier is present: The const wchar_t * argument is expected to be a pointer to an array of wide characters. Wide characters from the array are converted to multibyte characters (each by a call to the wcrtomb(3) function, with a conversion state starting in the initial state before the first wide character), up to and including a terminating null wide character. The resulting multibyte characters are written up to (but not including) the terminating null byte. If a precision is specified, no more bytes than the number specified are written, but no partial multibyte characters are written. Note that the precision determines the number of bytes written, not the number of wide characters or screen positions. The array must contain a terminating null wide character, unless a precision is given and it is so small that the number of bytes written exceeds it before the end of the array is reached.

**p**  
The void * pointer argument is printed in hexadecimal (as if by %#x or %#lx).

**d, i**  
The int argument is converted to signed decimal notation. The precision, if any, gives the minimum number of digits that must appear; if the converted value requires fewer digits, it is padded on the left with zeros. The default precision is 1. When 0 is printed with an explicit precision 0, the output is empty.

**o, u, x, X**  
The unsigned int argument is converted to unsigned octal (o), unsigned decimal (u), or unsigned hexadecimal (x and X) notation. The letters abcdef are used for x conversions; the letters ABCDEF are used for X conversions. The precision, if any, gives the minimum number of digits that must appear; if the converted value requires fewer digits, it is padded on the left with zeros. The default precision is 1. When 0 is printed with an explicit precision 0, the output is empty.

**%**  
A '%' is written. No argument is converted. The complete conversion specification is '%%'.

**n**  
The number of characters written so far is stored into the integer indicated by the int * (or variant) pointer argument. No argument is converted.

**f, F**  
The double argument is rounded and converted to decimal notation in the style [-]ddd.ddd, where the number of digits after the decimal-point character is equal to the precision specification. If the precision is missing, it is taken as 6; if the precision is explicitly zero, no decimal-point character appears. If a decimal point appears, at least one digit appears before it.  
(The SUSv2 does not know about F and says that character string representations for infinity and NaN may be made available. The C99 standard specifies "[-]inf" or "[-]infinity" for infinity, and a string starting with "nan" for NaN, in the case of f conversion, and "[-]INF" or "[-]INFINITY" or "NAN*" in the case of F conversion.)

**g, G**  
The double argument is converted in style f or e (or F or E for G conversions). The precision specifies the number of significant digits. If the precision is missing, 6 digits are given; if the precision is zero, it is treated as 1. Style e is used if the exponent from its conversion is less than -4 or greater than or equal to the precision. Trailing zeros are removed from the fractional part of the result; a decimal point appears only if it is followed by at least one digit.

**e, E**  
The double argument is rounded and converted in the style [-]d.dddeÂ±dd where there is one digit before the decimal-point character and the number of digits after it is equal to the precision; if the precision is missing, it is taken as 6; if the precision is zero, no decimal-point character appears. An E conversion uses the letter E (rather than e) to introduce the exponent. The exponent always contains at least two digits; if the value is zero, the exponent is 00.




