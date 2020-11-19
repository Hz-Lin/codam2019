; **************************************************************************** ;
;                                                                              ;
;                                                         ::::::::             ;
;    ft_strcmp.s                                        :+:    :+:             ;
;                                                      +:+                     ;
;    By: hlin <hlin@student.codam.nl>                 +#+                      ;
;                                                    +#+                       ;
;    Created: 2020/10/28 23:09:20 by hlin          #+#    #+#                  ;
;    Updated: 2020/11/19 11:51:29 by hlin          ########   odam.nl          ;
;                                                                              ;
; **************************************************************************** ;

	section .text
	global	_ft_strcmp

; int strcmp(const char *s1, const char *s2), return (s1 - s2)
; s1->rdi, s2->rsi

_ft_strcmp:
	mov		rdx, 0					; i = 0

compare:
	mov		r8b, byte [rdi + rdx]	; retrieve character s1[i]
	mov		r9b, byte [rsi + rdx]	; retrieve character s2[i]
	inc		rdx						; i++
	cmp		r8b, 0					; check if s1[i] is NULL
	je		substrac				; exit if s1[i] == 0
	cmp		r8b, r9b				; check if s1[i] == s2[i]
	jne		substrac				; exit if s1[i] != s2[i]
	je		compare					; if s1[i] == s2[i], loop

substrac:
    xor     rax, rax
    mov     al, r8b
    sub		al, r9b			    	; calculate s1[i] - s2[i]
    jnc     exit                    ; return the result if on substraction overflow
    neg     al                      ; negate all to cancle overflow
    neg     eax                     ; negate the whole int so the function return the right type

exit:
	ret
