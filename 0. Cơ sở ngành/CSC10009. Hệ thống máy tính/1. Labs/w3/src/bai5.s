.extern printf
.extern scanf

.section .data
    tb_nhap_n: .asciz "Nhap so phan tu n (0 <= n <= 100): "
    tb_nhap_ptu: .asciz "Nhap phan tu thu %ld: "
    tb_xuat_mang: .asciz "Mang vua nhap: "
    tb_so_nt: .asciz "Cac so nguyen to: "
    tb_max: .asciz "Gia tri lon nhat: %ld\n"
    tb_tb: .asciz "Trung binh mang: %.2f\n"
    fmt: .asciz "%ld"
    fmt_float: .asciz "%.2f"
    space: .asciz " "
    nexline: .asciz "\n"

.section .bss
    n: .space 8
    arr: .space 800
    temp: .space 8

.section .text
.global main

main:
    adrp x0, tb_nhap_n
    add x0, x0, :lo12:tb_nhap_n
    bl printf

    adrp x0, fmt
    add x0, x0, :lo12:fmt
    adrp x1, n
    add x1, x1, :lo12:n
    bl scanf

    adrp x19, n
    add x19, x19, :lo12:n
    ldr x19, [x19]

    mov x20, #0
    adrp x21, arr
    add x21, x21, :lo12:arr

nhap_loop:
    cmp x20, x19
    b.ge nhap_done

    adrp x0, tb_nhap_ptu
    add x0, x0, :lo12:tb_nhap_ptu
    add x1, x20, #1
    bl printf

    adrp x0, fmt
    add x0, x0, :lo12:fmt
    mov x1, x21
    bl scanf

    add x21, x21, #8
    add x20, x20, #1
    b nhap_loop

nhap_done:
    adrp x0, tb_xuat_mang
    add x0, x0, :lo12:tb_xuat_mang
    bl printf

    mov x20, #0
    adrp x21, arr
    add x21, x21, :lo12:arr

xuat_loop:
    cmp x20, x19
    b.ge xuat_done

    adrp x0, fmt
    add x0, x0, :lo12:fmt
    ldr x1, [x21]
    bl printf

    adrp x0, space
    add x0, x0, :lo12:space
    bl printf

    add x21, x21, #8
    add x20, x20, #1
    b xuat_loop

xuat_done:
    adrp x0, nexline
    add x0, x0, :lo12:nexline
    bl printf

    adrp x0, tb_so_nt
    add x0, x0, :lo12:tb_so_nt
    bl printf

    mov x20, #0
    adrp x21, arr
    add x21, x21, :lo12:arr

nguyento_loop:
    cmp x20, x19
    b.ge nguyento_done

    ldr x22, [x21]
    mov x0, x22
    bl _KiemTraNT

    cmp x0, #1
    b.ne next_nt

    adrp x0, fmt
    add x0, x0, :lo12:fmt
    mov x1, x22
    bl printf

    adrp x0, space
    add x0, x0, :lo12:space
    bl printf

next_nt:
    add x21, x21, #8
    add x20, x20, #1
    b nguyento_loop

nguyento_done:
    adrp x0, nexline
    add x0, x0, :lo12:nexline
    bl printf

    adrp x21, arr
    add x21, x21, :lo12:arr
    ldr x22, [x21]
    mov x20, #1

max_loop:
    cmp x20, x19
    b.ge max_done

    ldr x23, [x21, #8]
    add x21, x21, #8
    cmp x23, x22
    b.le skip_update_max
    mov x22, x23

skip_update_max:
    add x20, x20, #1
    b max_loop

max_done:
    adrp x0, tb_max
    add x0, x0, :lo12:tb_max
    mov x1, x22
    bl printf

    adrp x21, arr
    add x21, x21, :lo12:arr
    mov x22, #0
    mov x20, #0

sum_loop:
    cmp x20, x19
    b.ge sum_done

    ldr x23, [x21], #8
    add x22, x22, x23

    add x20, x20, #1
    b sum_loop

sum_done:
    ucvtf d0, x22
    ucvtf d1, x19
    fdiv d0, d0, d1

    adrp x0, tb_tb
    add x0, x0, :lo12:tb_tb
    bl printf

    mov x0, #0
    mov x8, #93
    svc #0

_KiemTraNT:
    sub sp, sp, #40      
    str x30, [sp, #32]   
    str x19, [sp, #24]  
    str x20, [sp, #16]   
    str x21, [sp, #8]    
    str x22, [sp, #0]    

    mov x19, x0

    cmp x19, #1          
    b.le _KiemTraNT.not_prime
    
    cmp x19, #2          
    b.eq _KiemTraNT.is_prime

    mov x20, #2        // i = 2

_KiemTraNT.check_prime_loop:
    udiv x21, x19, x20
    msub x21, x21, x20, x19 
    cbz x21, _KiemTraNT.not_prime 
    
    add x20, x20, #1        
    mul x22, x20, x20       
    cmp x22, x19
    b.le _KiemTraNT.check_prime_loop 

_KiemTraNT.is_prime:  
    mov x0, #1
    b _KiemTraNT.kt_done

_KiemTraNT.not_prime:
    mov x0, #0

_KiemTraNT.kt_done:
    ldr x22, [sp, #0]    
    ldr x21, [sp, #8]    
    ldr x20, [sp, #16]   
    ldr x19, [sp, #24]   
    ldr x30, [sp, #32]   
    add sp, sp, #40     
    ret
