;Viet chuong trinh "hello world"
%include "io.inc"
extern getch
section .data
    tb db "Hello world",0
section .text
global main
main:
    ;write your code here
    ;xuat tb printf("hello world");
    push tb
    call printf
    add esp,4
    
    
    ;scanf("%d",&n)
    
    call getch
    xor eax, eax
    ret