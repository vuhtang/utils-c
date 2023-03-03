%define PATTERN 0b_01_11_10_01

%macro shufmatrix 0
    shufps xmm3, xmm3, PATTERN
    shufps xmm4, xmm4, PATTERN
    shufps xmm5, xmm5, PATTERN
%endmacro

%macro convert2float 0
    cvtdq2ps xmm0, xmm0
    cvtdq2ps xmm1, xmm1
    cvtdq2ps xmm2, xmm2
%endmacro

%macro reverseconvert 0
    cvtps2dq xmm0, xmm0
    packssdw xmm0, xmm0
    packuswb xmm0, xmm0
%endmacro

%macro processregisters 1
    ;load pixels
    movdqu xmm0, [rdi]
    movdqu xmm1, [rdi+1]
    movdqu xmm2, [rdi+2]
    ;shuffle
    pshufb xmm0, [%1]
    pshufb xmm1, [%1]
    pshufb xmm2, [%1]
%endmacro

%macro transform 0
    mulps xmm0, xmm3
    mulps xmm1, xmm4
    mulps xmm2, xmm5

    addps xmm0, xmm1
    addps xmm0, xmm2 ;res in xmm0
%endmacro

section .rodata
align 16
blue: dd 0.131, 0.168, 0.189, 0.131
align 16
green: dd 0.534, 0.686, 0.769, 0.534
align 16
red: dd 0.272, 0.349, 0.393, 0.272
align 16
shuffle_first: db 0x7, 0xFF, 0xFF, 0xFF
               db 0x7, 0xFF, 0xFF, 0xFF
               db 0x7, 0xFF, 0xFF, 0xFF
               db 0x3, 0xFF, 0xFF, 0xFF
align 16
shuffle_second: db 0x7, 0xFF, 0xFF, 0xFF
                db 0x7, 0xFF, 0xFF, 0xFF
                db 0x3, 0xFF, 0xFF, 0xFF
                db 0x3, 0xFF, 0xFF, 0xFF
align 16
shuffle_third: db 0x7, 0xFF, 0xFF, 0xFF
               db 0x3, 0xFF, 0xFF, 0xFF
               db 0x3, 0xFF, 0xFF, 0xFF
               db 0x3, 0xFF, 0xFF, 0xFF


section .text
global sepia_asm

sepia_asm:
    ;load matrix
    movdqa xmm3, [blue]
    movdqa xmm4, [green]
    movdqa xmm5, [red]

    processregisters shuffle_first
    convert2float
    transform
    reverseconvert

    movd [rsi], xmm0 ;tadaaaaa

    ;MOVE FORWARD
    add rsi, 4
    add rdi, 3
    ;next pixels. must change matrix
    shufmatrix

    processregisters shuffle_second
    convert2float
    transform
    reverseconvert

    movd [rsi], xmm0 ;tadaaaaa

    ;MOVE FORWARD
    add rsi, 4
    add rdi, 3
    ;next pixels. must change matrix
    shufmatrix

    processregisters shuffle_third
    convert2float
    transform
    reverseconvert

    movd [rsi], xmm0 ;tadaaaaa

    ret




