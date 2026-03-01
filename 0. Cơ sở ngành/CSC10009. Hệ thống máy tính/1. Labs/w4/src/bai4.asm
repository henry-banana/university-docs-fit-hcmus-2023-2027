; Kiem tra so doi xung (palindrome)
%include "io.inc"
extern getch
section .data
    tb1 db "Nhap n: ",0
    tb2 db "%d la so doi xung",0
    tb3 db "%d khong la so doi xung",0
    fmt db "%d",0
section .bss
    n resd 1
    original resd 1    ; Ban sao cua n
    reversed resd 1    ; So dao nguoc
    digit resd 1       ; Chu so hien tai
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
    
    ; Khoi tao reversed = 0
    mov dword [reversed], 0
    
    ; Luu ban sao cua n vao original
    mov eax, [n]
    mov [original], eax
    
    ; Kiem tra neu n < 0 -> khong phai so doi xung
    cmp eax, 0
    jl KhongDoiXung
    
    ; Vong lap dao nguoc so
DaoNguoc:
    ; Lay chu so cuoi cung cua n
    mov eax, [n]
    xor edx, edx        ; Xoa edx de chu y cho phep chia
    mov ecx, 10         ; Chia cho 10
    div ecx             ; eax = n/10, edx = n%10 (chu so cuoi)
    mov [digit], edx    ; Luu chu so vao digit
    
    ; Cap nhat reversed = reversed*10 + digit
    mov eax, [reversed]
    mov ebx, 10
    mul ebx             ; eax = reversed*10
    add eax, [digit]    ; eax = reversed*10 + digit
    mov [reversed], eax
    
    ; Cap nhat n = n/10
    mov eax, [n]
    xor edx, edx
    mov ecx, 10
    div ecx
    mov [n], eax
    
    ; Kiem tra dieu kien lap (n != 0)
    cmp dword [n], 0
    jne DaoNguoc
    
    ; So sanh original va reversed
    mov eax, [original]
    cmp eax, [reversed]
    je LaDoiXung
    
KhongDoiXung:
    push dword [original]
    push tb3
    call printf
    add esp,8
    jmp KetThuc
    
LaDoiXung:
    push dword [original]
    push tb2
    call printf
    add esp,8
    
KetThuc:
    call getch
    xor eax, eax
    ret