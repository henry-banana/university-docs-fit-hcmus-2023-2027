; Kiem tra so nguyen hoan thien (so hoan hao)
%include "io.inc"
extern getch
section .data
    tb1 db "Nhap n: ",0
    tb2 db "%d la so hoan hao",0
    tb3 db "%d khong la so hoan hao",0
    fmt db "%d",0
section .bss
    n resd 1
    sum resd 1    ; Tong cac uoc so
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
    
    ; Khoi tao sum = 0
    mov dword [sum], 0
    
    ; Kiem tra neu n <= 0 -> khong phai so hoan hao
    cmp dword [n], 0
    jle KhongHoanHao
    
    ; Khoi tao vong lap tinh tong uoc so (tu 1 den n/2)
    mov ecx, 1    ; i = 1
LapTinhTong:
    ; Kiem tra dieu kien i <= n/2
    mov eax, [n]
    shr eax, 1    ; eax = n/2
    cmp ecx, eax
    jg KiemTraHoanHao
    
    ; Kiem tra n co chia het cho i khong
    mov eax, [n]
    xor edx, edx
    div ecx        ; eax = n/i, edx = n%i
    cmp edx, 0
    jne TangI
    
    ; Neu chia het, cong i vao sum
    add [sum], ecx
    
TangI:
    inc ecx        ; i++
    jmp LapTinhTong
    
KiemTraHoanHao:
    ; So sanh sum voi n
    mov eax, [sum]
    cmp eax, [n]
    je LaHoanHao
    
KhongHoanHao:
    push dword [n]
    push tb3
    call printf
    add esp,8
    jmp KetThuc
    
LaHoanHao:
    push dword [n]
    push tb2
    call printf
    add esp,8
    
KetThuc:
    call getch
    xor eax, eax
    ret