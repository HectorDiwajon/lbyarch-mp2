
section .data
    divisor dq 255.0
section .text
bits 64
default rel
global imgCvtGrayInttoFloat

imgCvtGrayInttoFloat:
    mov rbx, r9                 ; rbx has 255
    cvtsi2ss xmm1, rbx          ; make rbx to float
    L1:
        mov eax, dword [rdx]    ; intialize array value
        cvtsi2ss xmm0, eax      ; make it to float
        divss xmm0, xmm1        ; divide it by 255
        movss dword [r8], xmm0  ; put the value to the float array
        
        add rdx, 4              ; move by 1 index
        add r8, 4
        loop L1
    ret