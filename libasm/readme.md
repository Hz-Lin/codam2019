# x64 NASM notes

## Registers

"Scratch" registers any function is allowed to overwrite, and use for anything you want without asking anybody.
"Preserved" registers have to be put back ("save" the register) if you use them.

| 64 bit | 32 bit | 16 bit | 8 bit | type              | note                                                                              |
|--------|--------|--------|-------|-------------------|-----------------------------------------------------------------------------------|
| rax    | eax    | ax     | al    | scratch           | accumulator                                                                       |
| rbx    | ebx    | bx     | bl    | preserved         | base, addressing                                                                  |
| rcx    | ecx    | cx     | cl    | scratch           | counter, iterations                                                               |
| rdx    | edx    | dx     | dl    | scratch           | data                                                                              |
| rsp    | esp    | sp     | spl   | preserved         | stack pointer (points to the top of the stack)                                    |
| rbp    | ebp    | bp     | bpl   | preserved         | frame pointer (sometimes store the old value of the stack pointer, or the "base") |
| rsi    | esi    | si     | sil   | scratch/preserved | scratch and used to pass function argument #2 in Linux, preserved in Windows      |
| rdi    | edi    | di     | dil   | scratch/preserved | scratch and used to pass function argument #1 in Linux, preserved in Windows      |
| r8     | r8d    | r8w    | r8b   | scratch           |                                                                                   |
| r9     | r9d    | r9w    | r9b   | scratch           |                                                                                   |
| r10    | r10d   | r10w   | r10b  | scratch           |                                                                                   |
| r11    | r11d   | r11w   | r11b  | scratch           |                                                                                   |
| r12    | r12d   | r12w   | r12b  | preserved         |                                                                                   |
| r13    | r13d   | r13w   | r13b  | preserved         |                                                                                   |
| r14    | r14d   | r14w   | r14b  | preserved         |                                                                                   |
| r15    | r15d   | r15w   | r15b  | preserved         |                                                                                   |