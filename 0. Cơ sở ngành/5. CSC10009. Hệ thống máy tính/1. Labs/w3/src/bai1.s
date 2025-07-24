.extern printf
.extern scanf

.section .data
    tb1: .asciz "Nhap n: "
    tb2: .asciz "%d la so nguyen to\n"
    tb3: .asciz "%d khong la so nguyen to\n"
    format: .asciz "%d"
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
    adrp x0, format
    add x0, x0, :lo12:format
    adrp x1, n
    add x1, x1, :lo12:n
    bl scanf

    // Load n vao x19
    adrp x19, n
    add x19, x19, :lo12:n
    ldr x19, [x19]

    mov x0, x19
    bl is_prime
    cmp x0, #1
    b.eq prime
    
not_prime:
    // Xuat tb3
    adrp x0, tb3
    add x0, x0, :lo12:tb3
    mov x1, x19
    bl printf
    b exit

prime:
    adrp x0, tb2
    add x0, x0, :lo12:tb2
    mov x1, x19
    bl printf

exit:
    // Ket thuc
    mov x0, #0
    mov x8, #93
    svc #0

is_prime:
    sub sp, sp, #40
    str x30, [sp, #32] 
    str x19, [sp, #24]    
    str x20, [sp, #16]    
    str x21, [sp, #8]   
    str x22, [sp]        
    
    mov x19, x0     
    
    cmp x19, #2           // n < 2 thi khong phai so nguyen to
    b.lt not_prime_func

    // for (int i = 2; i < n; i++)
    cmp x19, #2
    b.eq check_prime_loop // n = 2 thi la snt

    mov x20, #2           // i = 2
check_prime_loop:
    udiv x21, x19, x20
    msub x21, x21, x20, x19  // x21 = n % i
    cbz x21, not_prime_func   // nếu n % i == 0 → ko la snt
    add x20, x20, #1          // i++
    mul x22, x20, x20         // x22 = i*i
    cmp x22, x19
    b.le check_prime_loop     // i*i <= n

    mov x0, #1
    b end_is_prime

not_prime_func:
    mov x0, #0

end_is_prime:
    ldr x22, [sp]        
    ldr x21, [sp, #8]     
    ldr x20, [sp, #16]    
    ldr x19, [sp, #24]   
    ldr x30, [sp, #32]   
    add sp, sp, #40      
    
    ret
