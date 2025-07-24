.extern printf
.extern scanf
.extern gets
.section .data
    	tb1: .asciz "Nhap ho ten: "
    	tb2: .asciz "Nhap nam sinh: "
    	tb3: .asciz "Xin chao %s, tuoi: %d\n"
    	fmt: .asciz "%d"
.section .bss
		hoten: .space 30
		ns: .space 8
		tuoi: .space 8

.section .text
.global main
main:
   	// Đưa con trỏ đến chuỗi vào x0
   	adrp x0, tb1   				// Đưa địa chỉ cơ sở của biến tb1 vào thanh ghi x0
	add x0, x0, :lo12:tb1   	// Cộng offset của biến tb vào thanh ghi x0
  	bl printf			 		// Gọi hàm printf

  	//Nhap ho ten
  	adrp x0, hoten   				// Đưa địa chỉ cơ sở của biến tb1 vào thanh ghi x0
	add x0, x0, :lo12:hoten   	// Cộng offset của biến tb vào thanh ghi x0
	bl gets

	//xuat tb2
   	adrp x0, tb2   				// Đưa địa chỉ cơ sở của biến tb1 vào thanh ghi x0
	add x0, x0, :lo12:tb2   	// Cộng offset của biến tb vào thanh ghi x0
  	bl printf			 		// Gọi hàm printf

  	//nhap nam sinh
  	adrp x0,fmt
  	add x0,x0,:lo12:fmt
  	adrp x1,ns
  	add x1,x1,:lo12:ns
  	bl scanf

  	//Load nam sinh x19
  	adrp x19,ns
  	add x19,x19,:lo12:ns
  	ldur x19,[x19]

  	//Tinh tuoi
  	mov x20,2025
  	sub x19,x20,x19 // x19 = x20 - x19

  	//Luu x19 vao bien tuoi
  	adrp x20,tuoi
  	add x20,x20,:lo12:tuoi
  	stur x19,[x20]


  	//xuat tb3
  	adrp x0,tb3
  	add x0,x0,:lo12:tb3

  	adrp x1,hoten
  	add x1,x1,:lo12:hoten

  	adrp x2,tuoi
  	add x2,x2,:lo12:tuoi
  	ldur x2,[x2]
  	bl printf

	// Thoát chương trình
	mov x0, #0	 // Giá trị trả về của hàm là 0
	mov x8, #93	// khởi tạo x8 = syscall exit	
	svc #0		// gọi syscall


