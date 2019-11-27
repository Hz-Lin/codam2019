# printf project notes

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
