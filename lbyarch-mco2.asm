
section .data
    divisor dq 255.0
section .text
bits 64
default rel
global imgCvtGrayInttoFloat

imgCvtGrayInttoFloat:
    mov rbx, r9
    cvtsi2ss xmm1, rbx
    L1:
        
        
        mov eax, dword [rdx]
        
        cvtsi2ss xmm0, eax
        divss xmm0, xmm1
        
        movss dword [r8], xmm0
        
        add rdx, 4
        add r8, 4
        loop L1
    ret