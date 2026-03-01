;Kiem tra so nguyen to
%include "io.inc"
extern getch
section .data
    tb1 db "Nhap n: ",0
    tb2 db "%d la so nguyen to",0
    tb3 db "%d khong la so nguyen to",0
    fmt db "%d",0
section .bss
    n resd 1
    flag resd 1    ; Bien co: 1 la nguyen to, 0 khong la nguyen to
section .text
global main
main:
    mov ebp, esp; for correct debugging
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
    
    ;Goi ham kiem tra nguyen to
    push dword [n]
    call _KiemTraNguyenTo
    add esp,4
    
    ;Kiem tra flag de xuat ket qua
    cmp dword [flag], 1
    je LaNguyenTo
    ;Khong la nguyen to
    push dword [n]
    push tb3
    call printf
    add esp,8
    jmp KetThuc
    
LaNguyenTo:
    push dword [n]
    push tb2
    call printf
    add esp,8
    
KetThuc:
    call getch
    xor eax, eax
    ret
    
;========== Ham kiem tra nguyen to ===========
;dau thu tuc
global _KiemTraNguyenTo
_KiemTraNguyenTo:
    ;backup ebp
    push ebp
    mov ebp, esp
    ;tham so n: [ebp + 8]
    ;backup cac thanh ghi neu can
    push ebx
    push ecx
    
;Than thu tuc
    ;Khoi tao flag = 1 (gia su la nguyen to)
    mov dword [flag], 1
    
    ;Neu n <= 1 -> khong la nguyen to
    mov eax, [ebp+8]
    cmp eax, 1
    jle KhongLaNguyenTo
    
    ;Neu n == 2 -> la nguyen to
    cmp eax, 2
    je KetThucHam
    
    ;Khoi tao vong lap kiem tra tu 2 den sqrt(n)
    mov ecx, 2    ; i = 2
LapKiemTra:
    ;Tinh i*i <= n?
    mov eax, ecx
    mul eax        ; eax = i*i
    cmp eax, [ebp+8]
    jg KetThucHam   ; Neu i*i > n -> ket thuc
    
    ;Kiem tra n co chia het cho i?
    mov eax, [ebp+8]
    xor edx, edx
    div ecx         ; eax = n/i, edx = n%i
    cmp edx, 0
    je KhongLaNguyenTo  ; Neu chia het -> khong la nguyen to
    
    ;Tang i
    inc ecx
    jmp LapKiemTra
    
KhongLaNguyenTo:
    mov dword [flag], 0
    
KetThucHam:
;Cuoi thu tuc
    ;restore cac thanh ghi
    pop ecx
    pop ebx
    pop ebp
    ret