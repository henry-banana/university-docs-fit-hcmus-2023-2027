; Kiem tra so chinh phuong (khong dung sqrt)
%include "io.inc"
extern getch
section .data
    tb1 db "Nhap n: ",0
    tb2 db "%d la so chinh phuong",0
    tb3 db "%d khong la so chinh phuong",0
    fmt db "%d",0
section .bss
    n resd 1
section .text
global main
main:
    ; Xuat thong bao nhap n
    push tb1
    call printf
    add esp,4
    
    ; Nhap gia tri n
    push n
    push fmt
    call scanf
    add esp,8
    
    ; Kiem tra neu n < 0 -> khong phai so chinh phuong
    cmp dword [n], 0
    jl KhongChinhPhuong
    
    ; Khoi tao vong lap
    mov ecx, 0    ; i = 0
LapKiemTra:
    mov eax, ecx
    mul eax        ; eax = i*i
    
    ; So sanh i*i voi n
    cmp eax, [n]
    je LaChinhPhuong    ; Neu i*i == n -> la so chinh phuong
    jg KhongChinhPhuong ; Neu i*i > n -> khong phai
    
    ; Tang i va tiep tuc lap
    inc ecx
    jmp LapKiemTra
    
LaChinhPhuong:
    push dword [n]
    push tb2
    call printf
    add esp,8
    jmp KetThuc
    
KhongChinhPhuong:
    push dword [n]
    push tb3
    call printf
    add esp,8
    
KetThuc:
    call getch
    xor eax, eax
    ret