;Viet ham tinh x mu n
%include "io.inc"
extern getch
section .data
    tb1 db "Nhap x: ",0
    tb2 db "Nhap n: ",0
    tb3 db "%d ^ %d = %d",0
    fmt db "%d",0
section .bss
    x resd 1
    n resd 1
    t resd 1
section .text
global main
main:
    ;write your code here
    ;xuat tb1
    push tb1
    call printf
    add esp,4
    
    ;nhap x
    push x
    push fmt
    call scanf
    add esp,8
    
    ;xuat tb2
    push tb2
    call printf
    add esp,4
    
    ;nhap n
    push n
    push fmt
    call scanf
    add esp,8
    
    ;Goi ham Tinh mu
    push dword [n]
    push dword [x]
    call _TinhMu
    add esp,8
    
    ;Luu ket qua (eax) vao t
    mov [t],eax
    ;xuat tb3
    push dword[t]
    push dword [n]
    push dword [x]
    push tb3
    call printf
    add esp,16
    
    call getch
    
    xor eax, eax
    ret
    
    
;========== Ham ===========
;dau thu tuc
global _TinhMu
_TinhMu:
    ;backup ebp
    push ebp
    mov ebp, esp
    ;--> tham so thu nhat (x): [ebp + 8]
    ;--> tham so thu hai (n): [ebp + 12]
    ;backup cac thanh ghi neu can
    push ecx
;Than thu tuc
    ;khoi tao vong lap
    mov ecx,[ebp+12]
    mov eax,1; t = 1
_TinhMu.Lap:
    mul dword[ebp + 8]; t = t * x
    Loop _TinhMu.Lap
    
;Cuoi thu tuc
    ;restore cac thanh ghi
    pop ecx
    pop ebp 
    ret
     
    