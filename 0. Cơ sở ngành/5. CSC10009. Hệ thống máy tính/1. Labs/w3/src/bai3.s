.extern printf
.extern scanf

.section .data
    tb1: .asciz "Nhap n: "
    tb2: .asciz "%d la so chinh phuong\n"
    tb3: .asciz "%d khong la so chinh phuong\n"
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

    // Load n vào x19
    adrp x19, n
    add x19, x19, :lo12:n
    ldr x19, [x19]

    // Kiểm tra n < 0
    cmp x19, #0
    b.lt not_num_sqrt

    bl check_num_sqrt
    cbnz x0, num_sqrt

not_num_sqrt:
    // Xuat tb3
    adrp x0, tb3
    add x0, x0, :lo12:tb3
    mov x1, x19
    bl printf
    b exit

num_sqrt:
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

check_num_sqrt:
    // for (int i = 0; i * i <= n; i++)
    mov x20, #0             // i = 0
check_loop:
    mul x21, x20, x20    
    cmp x21, x19        
    b.gt not_num_sqrt_fn      
    beq num_sqrt_fn     

    add x20, x20, #1        
    b check_loop            

not_num_sqrt_fn:
    mov x0, #0
    ret

num_sqrt_fn:
    mov x0, #1
    ret
    