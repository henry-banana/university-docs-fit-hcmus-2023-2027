.extern printf
.extern scanf

.section .data
    tb1: .asciz "Nhap n: "
    tb2: .asciz "%d la so hoan hao\n"
    tb3: .asciz "%d khong la so hoan hao\n"
    fmt: .asciz "%d"
    
.section .bss
    n: .space 8
    sum: .space 8

.section .text
.global main

main:
    adrp x0, tb1
    add x0, x0, :lo12:tb1
    bl printf

    adrp x0, fmt
    add x0, x0, :lo12:fmt
    adrp x1, n
    add x1, x1, :lo12:n
    bl scanf

    adrp x19, n
    add x19, x19, :lo12:n
    ldr x19, [x19]

    mov x0, x19
    bl is_perfect_number
    cmp x0, #1
    b.eq is_perfect

not_perfect:
    adrp x0, tb3
    add x0, x0, :lo12:tb3
    mov x1, x19
    bl printf
    b exit

is_perfect:
    adrp x0, tb2
    add x0, x0, :lo12:tb2
    mov x1, x19
    bl printf

exit:
    mov x0, #0
    mov x8, #93
    svc #0

is_perfect_number:
    sub sp, sp, #48
    str x30, [sp, #40]
    str x19, [sp, #32]
    str x20, [sp, #24]
    str x21, [sp, #16]
    str x22, [sp, #8]
    str x23, [sp]

    mov x19, x0
    mov x20, #0
    adrp x23, sum
    add x23, x23, :lo12:sum
    str x20, [x23]

    cmp x19, #1
    b.lt not_perfect_func

    cmp x19, #1
    b.le not_perfect_func

    mov x21, #1

check_perfect_loop:
    udiv x22, x19, x21
    msub x22, x22, x21, x19
    cbnz x22, skip_add
    add x20, x20, x21
    skip_add:

    add x21, x21, #1
    cmp x21, x19
    b.lt check_perfect_loop

    cmp x20, x19
    b.eq perfect_func
    mov x0, #0
    b end_is_perfect

not_perfect_func:
    mov x0, #0
    b end_is_perfect

perfect_func:
    mov x0, #1

end_is_perfect:
    ldr x23, [sp]
    ldr x22, [sp, #8]
    ldr x21, [sp, #16]
    ldr x20, [sp, #24]
    ldr x19, [sp, #32]
    ldr x30, [sp, #40]
    add sp, sp, #48
    ret
    