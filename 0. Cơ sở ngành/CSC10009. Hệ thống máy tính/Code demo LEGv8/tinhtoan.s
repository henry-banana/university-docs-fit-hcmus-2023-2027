//Nhập vào 2 số a,b. Tính tổng, hiệu, tích, thương (dư), a,b.
.section .data
	tb1: .asciz "Nhap a: "
	tb2: .asciz "Nhap b: "
	tb3: .asciz "%d %c %d = %d\n"
	fmt: .asciz "%d"
.section .bss
	a: .space 8
	b: .space 8
.section .text
.global main
main:
	//xuat tb1
	adrp x0,tb1
	add x0,x0,:lo12:tb1
	bl printf

	//Nhap a
	adrp x0,fmt
	add x0,x0,:lo12:fmt
	adrp x1,a
	add x1,x1,:lo12:a
	bl scanf

	//xuat tb2
	adrp x0,tb2
	add x0,x0,:lo12:tb2
	bl printf

	//Nhap b
	adrp x0,fmt
	add x0,x0,:lo12:fmt
	adrp x1,b
	add x1,x1,:lo12:b
	bl scanf

	//Load a vao x19
	adrp x19,a
	add x19,x19,:lo12:a
	ldur x19,[x19]

	//Load b vao x20
	adrp x20,b
	add x20,x20,:lo12:b
	ldur x20,[x20]

	//Tinh tong
	add x21,x19,x20
	//Xuat tb3
	adrp x0,tb3
	add x0,x0,:lo12:tb3
	mov x1,x19
	mov x2,'+'
	mov x3,x20
	mov x4,x21
	bl printf


	//Tinh hieu
	sub x21,x19,x20
	//Xuat tb3
	adrp x0,tb3
	add x0,x0,:lo12:tb3
	mov x1,x19
	mov x2,'-'
	mov x3,x20
	mov x4,x21
	bl printf

	//Tinh tich
	mul x21,x19,x20
	//Xuat tb3
	adrp x0,tb3
	add x0,x0,:lo12:tb3
	mov x1,x19
	mov x2,'*'
	mov x3,x20
	mov x4,x21
	bl printf

	
	//Tinh thuong
	sdiv x21,x19,x20
	//Xuat tb3
	adrp x0,tb3
	add x0,x0,:lo12:tb3
	mov x1,x19
	mov x2,'/'
	mov x3,x20
	mov x4,x21
	bl printf

	//Tinh du
	mul x22,x21,x20
	sub x21,x19,x22 
	//Xuat tb3
	adrp x0,tb3
	add x0,x0,:lo12:tb3
	mov x1,x19
	mov x2,'%'
	mov x3,x20
	mov x4,x21
	bl printf

	
	//ket thuc
	mov x0,#0
	mov x8,#93
	svc #0


	
