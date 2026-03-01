.extern printf
.extern scanf

.section .data
    tb1: .asciz "Nhap n: "
    tb2: .asciz "%d la so doi xung\n"
    tb3: .asciz "%d khong la so doi xung\n"
    fmt: .asciz "%d"
    
.section .bss
    n: .space 8

.section .text
.global main

main:
    // Xuat tb1
    adrp x0, tb1
    add x0, x0, :lo12:tb1
    bl printf

    // Nhap n
    adrp x0, fmt
    add x0, x0, :lo12:fmt
    adrp x1, n
    add x1, x1, :lo12:n
    bl scanf

    // Load n vao x19
    adrp x19, n
    add x19, x19, :lo12:n
    ldr x19, [x19]

    // Kiem tra n < 0
    cmp x19, #0
    b.lt not_rev_num

    bl check_palindrome
    cbnz x0, is_rev_number

not_rev_num:
    // Xuat tb3
    adrp x0, tb3
    add x0, x0, :lo12:tb3
    mov x1, x19
    bl printf
    b exit

is_rev_number:
    // Xuat tb2
    adrp x0, tb2
    add x0, x0, :lo12:tb2
    mov x1, x19
    bl printf

exit:
    // Thoat chuong trinh
    mov x0, #0
    mov x8, #93
    svc #0

check_palindrome:
    mov x20, x19    // x20 = n
    mov x21, #0    // x21(n_rev) = 0 (so dao nguoc)

rev_loop:
    // Kiem tra n > 0
    cmp x20, #0
    b.eq check_rev

    // Dao lai : x21 = x21 * 10 + n % 10
    mov x22, #10
    udiv x23, x20, x22   // x23 = n / 10
    msub x24, x23, x22, x20  // x24 = n % 10

    mul x21, x21, x22  // x21(n_rev) *= 10
    add x21, x21, x24  // x21(n_rev) += (n % 10)
    
    mov x20, x23     // x20(n) /= 10
    b rev_loop

check_rev:
    cmp x19, x21 // So sanh n va n_rev
    b.eq is_palindrome
    mov x0, #0
    ret

is_palindrome:
    mov x0, #1
    ret
    