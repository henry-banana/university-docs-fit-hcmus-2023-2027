//Viet ham tinh x mu n
.section .data
	tb1: .asciz "Nhap x: "
	tb2: .asciz "Nhap n: "
	tb3: .asciz "%d ^ %d = %d\n"
	fmt: .asciz "%d"
.section .bss
	x: .space 8
	n: .skip 8
	
.section .text
.global main
main:
	//xuat tb1
	adrp x0,tb1
	add x0,x0,:lo12:tb1
	bl printf

	//nhap x
	adrp x0,fmt
	add x0,x0,:lo12:fmt
	adrp x1,x
	add x1,x1,:lo12:x
	bl scanf

	//xuat tb2
	adrp x0,tb2
	add x0,x0,:lo12:tb2
	bl printf

	//nhap n
	adrp x0,fmt
	add x0,x0,:lo12:fmt
	adrp x1,n
	add x1,x1,:lo12:n
	bl scanf
	
	//Load x vao x19
	adrp x19,x
	add x19,x19,:lo12:x
	ldur x19,[x19]

	//Load n vao x20
	adrp x20,n
	add x20,x20,:lo12:n
	ldur x20,[x20]

	//Truyen tham so
	mov x0,x19
	mov x1,x20
	//Goi ham
	bl _TinhMu

	//Luu kq tra ve trong X0 vao x21
	mov x21,x0

	//Load x vao x19
	adrp x19,x
	add x19,x19,:lo12:x
	ldur x19,[x19]

	//Load n vao x20
	adrp x20,n
	add x20,x20,:lo12:n
	ldur x20,[x20]

	//Xuat tb3
	adrp x0,tb3
	add x0,x0,:lo12:tb3
	mov x1,x19
	mov x2,x20
	mov x3,x21
	bl printf

	//Ket thuc
	mov x0,#0
	mov x8,#93
	svc #0

// =========== Ham =============
_TinhMu:
	//backup x30
	sub x28,x28,#8
	str x30,[x28]
	//backup cac thanh ghi khac
	sub x28,x28,#8
	str x19,[x28]
	sub x28,x28,#8
	str x20,[x28]
	sub x28,x28,#8
	str x21,[x28]
	sub x28,x28,#8
	str x22,[x28]
//Than thu tuc
	//Luu x (trong x0) vao x19
	mov x19,x0
	//Luu n (trong x1) vao x20
	mov x20,x1
	//khoi tao vong lap
	mov x21,#1 // T = 1
	mov x22,#1 // i = n
_TinhMu.Loop:
	mul x21,x21,x19 // T = T * x
	add x22,x21,#1 // i++
	//Neu i <= n thi lap
	cmp x22,x20
	b.le _TinhMu.Loop

	//Luu ket qua tra ve vao x0
	mov x0,x21
//Cuoi thu tuc
	//Restor cac thanh ghi
	ldr x22,[x28]
	add x28,x28,#8
	ldr x21,[x28]
	add x28,x28,#8
	ldr x20,[x28]
	add x28,x28,#8
	ldr x19,[x28]
	add x28,x28,#8
	//restore x30
	ldr x30,[x28]
	add x28,x28,#8
	//Quay ve
	ret
