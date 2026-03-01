.extern printf
.section .data
    	tb1:  .asciz "Hello, world!\n"
.section .text
.global main
main:
   	// Đưa con trỏ đến chuỗi vào x0
   	adrp x0, tb1   				// Đưa địa chỉ cơ sở của biến tb1 vào thanh ghi x0
	add x0, x0, :lo12:tb1   	// Cộng offset của biến tb vào thanh ghi x0
  	bl printf			 		// Gọi hàm printf

	// Thoát chương trình
	mov x0, #0	 // Giá trị trả về của hàm là 0
	mov x8, #93	// khởi tạo x8 = syscall exit	
	svc #0		// gọi syscall

