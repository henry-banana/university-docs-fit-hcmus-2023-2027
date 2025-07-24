;Tinh tong 1 den n
%include "io.inc"
extern getch
section .data
    tb1 db "Nhap n: ",0
    tb2 db "Tong 1 den %d la: %d",0
    fmt db "%d",0
section .bss
    n resd 1
    s resd 1
section .text
global main
main:
    ;write your code here
    ;xuat tb1
    push tb1
    call printf
    add esp,4
    
    ;nhap n
    push n
    push fmt
    call scanf
    add esp,8
    
    ;khoi tao vong lap
    mov ecx,[n]
    mov eax,0 ; s = 0
Lap:
    add eax,ecx ; s = s + i
    Loop Lap ; (ecx = ecx -1; neu ecx !=0 thi lap)
    mov [s],eax
    
    ;xuat tb2
    push dword [s]
    push dword [n]
    push tb2
    call printf
    add esp,12
    
    call getch
    
    xor eax, eax
    ret