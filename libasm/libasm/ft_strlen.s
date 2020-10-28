; **************************************************************************** ;
;                                                                              ;
;                                                         ::::::::             ;
;    ft_strlen.s                                        :+:    :+:             ;
;                                                      +:+                     ;
;    By: hlin <hlin@student.codam.nl>                 +#+                      ;
;                                                    +#+                       ;
;    Created: 2020/10/28 22:24:36 by hlin          #+#    #+#                  ;
;    Updated: 2020/10/28 22:24:40 by hlin          ########   odam.nl          ;
;                                                                              ;
; **************************************************************************** ;

	section .text
	global _ft_strlen

_ft_strlen:
	mov	rax, -1				; i = -1

loop:
	inc	rax					; i++
	cmp	byte [rdi + rax], 0	; compare byte to NULL
	jne	loop				; loops if not reach NULL
	ret