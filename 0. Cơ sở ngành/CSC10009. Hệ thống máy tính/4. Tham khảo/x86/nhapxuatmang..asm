; Bài tập 5. Sử dụng kỹ thuật hàm.
; Nhập xuất mảng 1 chiều, liệt kê số nguyên tố, tìm max, tính trung bình.
%include "io.inc"

extern getch

section .data
    tb1 db "Nhap n: ", 0
    tb2 db "a[%d]: ", 0
    tb3 db "Mang vua nhap la: ", 0
    tb4 db "Cac so nguyen to trong mang la: ", 0
    tb5 db "Gia tri lon nhat trong mang la: ", 0
    tb6 db "Trung binh mang la: ", 0
    fmt1 db "%d", 0
    fmt2 db "%d ", 0
    fmt3 db "%f ", 0
    newline db 10, 0

section .bss
    n resd 1
    arr resd 20
    max resd 1
    sum resd 1
    avg resd 1

section .text
global main

; Hàm nhập mảng
nhap_mang:
    push ebp
    mov ebp, esp
    mov esi, 0 ; i = 0
    mov ebx, [ebp + 8] ; ebx = địa chỉ mảng
loop_nhap:
    push esi
    push tb2
    call printf
    add esp, 8
    push ebx
    push fmt1
    call scanf
    add esp, 8
    add ebx, 4
    inc esi
    cmp esi, [n]
    jl loop_nhap
    pop ebp
    ret

; Hàm xuất mảng
xuat_mang:
    push ebp
    mov ebp, esp
    mov esi, 0 ; i = 0
    mov ebx, [ebp + 8] ; ebx = địa chỉ mảng
loop_xuat:
    push dword [ebx]
    push fmt2
    call printf
    add esp, 8
    add ebx, 4
    inc esi
    cmp esi, [n]
    jl loop_xuat
    push newline
    call printf
    add esp, 4
    pop ebp
    ret

; Hàm kiểm tra số nguyên tố
is_prime:
    push ebp
    mov ebp, esp
    mov eax, [ebp + 8] ; eax = số cần kiểm tra
    cmp eax, 2
    jl khong_nguyen_to
    mov ecx, 2
loop_prime:
    cmp ecx, eax
    jge la_nguyen_to
    mov edx, 0
    mov ebx, eax
    div ebx ; eax = eax / ebx, edx = eax % ebx
    cmp edx, 0
    je khong_nguyen_to
    inc ecx
    jmp loop_prime
la_nguyen_to:
    mov eax, 1 ; trả về 1 nếu là số nguyên tố
    jmp ket_thuc_prime
khong_nguyen_to:
    mov eax, 0 ; trả về 0 nếu không là số nguyên tố
ket_thuc_prime:
    pop ebp
    ret

; Hàm liệt kê số nguyên tố
liet_ke_nguyen_to:
    push ebp
    mov ebp, esp
    mov esi, 0 ; i = 0
    mov ebx, [ebp + 8] ; ebx = địa chỉ mảng
    push tb4
    call printf
    add esp, 4

loop_liet_ke:
    push dword [ebx]
    call is_prime
    add esp, 4
    cmp eax, 1
    jne khong_in
    push dword [ebx]
    push fmt2
    call printf
    add esp, 8
khong_in:
    add ebx, 4
    inc esi
    cmp esi, [n]
    jl loop_liet_ke
    push newline
    call printf
    add esp, 4
    pop ebp
    ret

; Hàm tìm max
tim_max:
    push ebp
    mov ebp, esp
    mov esi, 0
    mov ebx, [ebp + 8]
    mov eax, [ebx]
    mov [max], eax
loop_max:
    add ebx, 4
    inc esi
    cmp esi, [n]
    jge ket_thuc_max
    mov ecx, [ebx]
    cmp ecx, [max]
    jle loop_max
    mov [max], ecx
    jmp loop_max
ket_thuc_max:
    push tb5
    call printf
    add esp, 4
    push dword [max]
    push fmt1
    call printf
    add esp, 8
    push newline
    call printf
    add esp, 4
    pop ebp
    ret

; Hàm tính trung bình
tinh_trung_binh:
    push ebp
    mov ebp, esp
    mov esi, 0
    mov ebx, [ebp + 8]
    mov [sum], dword 0
loop_sum:
    add eax, [ebx]
    add [sum], eax
    add ebx, 4
    inc esi
    cmp esi, [n]
    jl loop_sum
    mov eax, [sum]
    cdq ; mở rộng dấu của eax vào edx
    fild dword [n]
    fdiv dword [sum]
    fstp [avg]
    push tb6
    call printf
    add esp, 4
    push dword [avg]
    push fmt3
    call printf
    add esp, 8
    push newline
    call printf
    add esp, 4
    pop ebp
    ret

; Hàm main
main:
    ; Nhập n
    push tb1
    call printf
    add esp, 4
    push n
    push fmt1
    call scanf
    add esp, 8

    ; Nhập mảng
    push arr
    call nhap_mang
    add esp, 4

    ; Xuất mảng
    push arr
    call xuat_mang
    add esp, 4

    ; Liệt kê số nguyên tố
    push arr
    call liet_ke_nguyen_to
    add esp, 4

    ; Tìm max
    push arr
    call tim_max
    add esp, 4

    ; Tính trung bình
    push arr
    call tinh_trung_binh
    add esp, 4

    call getch
    xor eax, eax
    ret