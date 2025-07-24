%include "io.inc"
extern getch

section .data
    palindrome_msg     db "%d la so doi xung", 0
    notpalindrome_msg  db "%d khong phai la so doi xung", 0
    fmt                db "%d", 0
    tb1                db "Nhap n: ", 0
    tb2                db "a[%d]: ", 0
    tb3                db "Mang vua nhap la: ", 10, 0
    prime_msg          db "Cac so nguyen to: ", 10, 0
    max_msg            db "Gia tri lon nhat: %d", 10, 0
    avg_msg            db "Trung binh cong: %f", 10, 0
    fmt1               db "%d", 0
    fmt2               db "%d ", 0

section .bss
    n         resd 1
    temp      resd 1
    reversed  resd 1
    arr       resd 20
    sum       resd 1
    max       resd 1
    count     resd 1

section .text
global main

main:
    call input_array
    call output_array
    call list_primes
    call find_max
    call calculate_average
    call getch
    xor eax, eax
    ret

input_array:
    ; Nhap n
    push n
    push fmt1
    call scanf
    add esp, 8

    ; Load address arr vao ebx
    mov ebx, arr
    mov esi, 0        ; i = 0

Loop_in:
    push ebx
    push fmt1
    call scanf
    add esp, 8

    add ebx, 4        ; tang dia chi
    inc esi
    cmp esi, [n]
    jl Loop_in
    ret

output_array:
    push tb3
    call printf
    add esp, 4

    mov ebx, arr
    mov esi, 0

Loop_out:
    push dword [ebx]
    push fmt2
    call printf
    add esp, 8

    add ebx, 4
    inc esi
    cmp esi, [n]
    jl Loop_out

    push 10
    call putchar
    add esp, 4
    ret

list_primes:
    push prime_msg
    call printf
    add esp, 4

    mov ebx, arr
    mov esi, 0

Loop_prime:
    mov eax, [ebx]
    call is_prime
    cmp eax, 1
    jne not_prime

    push dword [ebx]
    push fmt2
    call printf
    add esp, 8

not_prime:
    add ebx, 4
    inc esi
    cmp esi, [n]
    jl Loop_prime

    push 10
    call putchar
    add esp, 4
    ret

is_prime:
    push ebx
    mov ebx, eax

    cmp ebx, 2
    jl not_prime_result

    cmp ebx, 3
    jle prime_result

    test ebx, 1
    jz not_prime_result

    mov ecx, 3

check_prime_loop_fixed:
    push edx
    mov eax, ebx
    xor edx, edx
    div ecx
    test edx, edx
    pop edx
    jz not_prime_result

    add ecx, 2

    push eax
    mov eax, ecx
    mul ecx
    cmp eax, ebx
    pop eax
    jbe check_prime_loop_fixed

    jmp prime_result

prime_result:
    mov eax, 1
    pop ebx
    ret

not_prime_result:
    mov eax, 0
    pop ebx
    ret

find_max:
    mov ebx, arr
    mov eax, [ebx]
    mov [max], eax
    mov esi, 1

Loop_max:
    add ebx, 4
    mov eax, [ebx]
    cmp eax, [max]
    jle not_new_max
    mov [max], eax

not_new_max:
    inc esi
    cmp esi, [n]
    jl Loop_max

    push dword [max]
    push max_msg
    call printf
    add esp, 8
    ret

calculate_average:
    mov ebx, arr
    mov dword [sum], 0
    xor eax, eax
    mov esi, 0

Loop_sum:
    mov eax, [ebx]
    add [sum], eax
    add ebx, 4
    inc esi
    cmp esi, [n]
    jl Loop_sum

    finit
    fild dword [sum]
    fild dword [n]
    fdivp
    sub esp, 8
    fstp qword [esp]

    push avg_msg
    call printf
    add esp, 12
    ret
