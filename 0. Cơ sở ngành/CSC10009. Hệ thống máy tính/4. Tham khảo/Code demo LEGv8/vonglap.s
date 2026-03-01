//Nhập n. Tính tổng từ 1 đến n.
.section .data
	tb1: .asciz "Nhap n: "
	tb2: .asciz "Tong 1 den %d la: %d\n"
	fmt: .asciz "%d"
.section .bss
	n: .space 8
.section .text
.global main
main:
	//xuat tb1
	adrp x0,tb1
	add x0,x0,:lo12:tb1
	bl printf


	//Nhap n
	adrp x0,fmt
	add x0,x0,:lo12:fmt
	adrp x1,n
	add x1,x1,:lo12:n
	bl scanf

	//load n vao x19
	adrp x19,n
	add x19,x19,:lo12:n
	ldur x19,[x19]

	//int s = 0;
	//for(int i = 1; i <= n; i++)
	//	s = s + i
	mov x20,#0 // s = 0
	mov x21,#1 // i = 1
Loop:
	add x20,x20,x21 // s = s + i
	add x21,x21,#1 // i++
	cmp x21,x19
	b.le Loop

	//xuat tb2
	adrp x0,tb2
	add x0,x0,:lo12:tb2
	mov x1,x19
	mov x2,x20
	bl printf

	//ket thuc
	mov x0,#0
	mov x8,#93
	svc #0

