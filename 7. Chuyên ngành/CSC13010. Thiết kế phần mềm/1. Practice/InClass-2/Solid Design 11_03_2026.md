# **TƯ DUY PHẢN BIỆN VỀ SOFTWARE DESIGN**

**Chủ đề:** Coupling, Cohesion, SOLID, DRY, KISS, YAGNI trong thiết kế phần mềm  
**Thời gian:** 60 phút  
**Hình thức:** Cá nhân, tự luận  
**Tài liệu:** Slide D02 và `SolidPrinciples.pptx`

## **Yêu cầu chung**

Trong toàn bài, sinh viên phải tuân thủ các nguyên tắc:

1. **Chỉ nên sử dụng AI để hiểu các từ khóa định nghĩa**, không nên dùng để trả lời các câu hỏi, quan trọng nhất là bản thân đã học và cảm nhận như thế nào  
2. Trả lời theo cách hiểu của cá nhân, không cần bài làm quá hoàn hảo  
3. Không được chỉ nêu định nghĩa.

4. Mỗi câu trả lời phải có **kết luận**, **lập luận**, và **ít nhất 1 phản biện ngược**.

5. Nếu đề xuất refactor, phải giải thích rõ **vì sao tốt hơn**, **đổi lại mất gì**.

6. Những câu trả lời kiểu “áp dụng SOLID để code sạch hơn” nhưng không chỉ ra tác động cụ thể sẽ không được điểm cao.

## **Phần I. Bóc tách ngộ nhận trong thiết kế phần mềm**

Chọn **2 trong 4 nhận định** sau và phân tích vì sao nhận định đó **đúng một phần nhưng nguy hiểm nếu tin tuyệt đối**.

### **Nhận định**

a) “Càng tách nhiều class càng đúng SRP.”  
 b) “Cứ dùng interface là sẽ giảm coupling.”  
 c) “Muốn dễ mở rộng thì nên thiết kế sẵn mọi abstraction từ đầu.”  
 d) “Code không lặp là code tốt, nên DRY luôn ưu tiên hơn KISS.”

### **Yêu cầu cho mỗi nhận định**

* Chỉ ra phần **đúng**.

* Chỉ ra phần **sai hoặc bị tuyệt đối hóa**.

* Nêu **1 tình huống phản ví dụ**.

* Viết lại nhận định đó thành một phiên bản **chính xác hơn** trong 3–4 câu.

## **Phần II. Chẩn đoán một thiết kế có vấn đề**

### **Tình huống**

Một nhóm sinh viên viết hệ thống quản lý đơn hàng với class sau:

class OrderManager {  
   public void createOrder(Order order) { ... }  
   public void validateOrder(Order order) { ... }  
   public void saveToDatabase(Order order) { ... }  
   public void sendConfirmationEmail(Order order) { ... }  
   public void printInvoice(Order order) { ... }  
   public double calculateShippingFee(Order order) { ... }  
   public void exportExcelReport() { ... }  
}

### **Câu hỏi**

Hãy đánh giá class trên dưới góc nhìn của **cohesion, coupling, SRP, testability, maintainability**.

### **Yêu cầu bắt buộc**

1. Phân tích vì sao class này có thể bị xem là **low cohesion**.

2. Chỉ ra **ít nhất 4 lý do thay đổi khác nhau** của class này.

3. Chọn **2 vấn đề nghiêm trọng nhất** và giải thích vì sao chúng nguy hiểm hơn các vấn đề còn lại.

4. Đề xuất refactor ở mức thiết kế:

   * tách thành những thành phần nào,

   * thành phần nào nên giữ ở domain,

   * thành phần nào là infrastructure/service.

5. Nêu **1 phản biện ngược** với chính phương án refactor của anh/chị, ví dụ: “tách quá mức sẽ gây phân mảnh code”.

## **Phần III. Không phải cứ “đúng SOLID” là tốt hơn** 

### **Tình huống**

Một giảng viên phản biện hệ thống thanh toán của sinh viên:

class PaymentProcessor {  
   public void processPayment(String type, double amount) {  
       if (type.equals("CREDIT\_CARD")) { ... }  
       else if (type.equals("PAYPAL")) { ... }  
       else if (type.equals("MOMO")) { ... }  
   }  
}

Một sinh viên đề xuất sửa ngay thành:

* `PaymentMethod` interface,

* `CreditCardPayment`, `PayPalPayment`, `MomoPayment`,

* thêm `PaymentFactory`,

* thêm `PaymentRegistry`,

* thêm `PaymentStrategyResolver`,

* thêm `AbstractPaymentHandler`,

* thêm `BasePaymentAuditDecorator`.

### **Câu hỏi**

Anh/chị hãy đánh giá xem đề xuất này là:

* **refactor hợp lý**,

* **over-engineering**,

* hay **đúng ý nhưng làm quá tay**.

### **Yêu cầu bắt buộc**

Bài làm phải trả lời đủ các ý sau:

1. Đoạn code ban đầu vi phạm nguyên lý nào? Giải thích rõ.

2. Trong đề xuất mới, thành phần nào là **thực sự cần thiết**, thành phần nào có dấu hiệu **YAGNI**.

3. Phân tích xung đột giữa:

   * **OCP/DIP**  
      và

   * **KISS/YAGNI**

4. Nếu hệ thống hiện tại chỉ có đúng **2 phương thức thanh toán** và 6 tháng qua không đổi, anh/chị có refactor ngay không? Vì sao?

5. Nếu công ty chuẩn bị tích hợp thêm 8 cổng thanh toán mới trong 3 tháng tới, câu trả lời của anh/chị có thay đổi không?

6. Kết luận cuối cùng của anh/chị phải nêu:

   * **phiên bản thiết kế nào nên áp dụng ngay bây giờ**,

   * **phiên bản nào để dành cho giai đoạn sau**.

## **Phần IV. Phản biện các “đề xuất cải tiến nghe có vẻ đúng”** 

Đọc 3 đề xuất sau và chọn **2 đề xuất** để phản biện.

### **Đề xuất 1**

“Để đúng DIP, mọi class trong hệ thống đều nên phụ thuộc vào interface, kể cả các class rất nhỏ chỉ có một implementation.”

### **Đề xuất 2**

“Để đúng ISP, interface càng nhỏ càng tốt, mỗi method nên tách thành một interface riêng.”

### **Đề xuất 3**

“Để tránh vi phạm LSP, tốt nhất là hạn chế kế thừa, hầu như chỉ nên dùng composition.”

### **Yêu cầu cho mỗi đề xuất**

* Nêu vì sao đề xuất đó **nghe có vẻ hợp lý**.

* Nêu rủi ro nếu áp dụng cực đoan.

* Cho **1 ví dụ thực tế** khi đề xuất đó là đúng.

* Cho **1 ví dụ thực tế** khi đề xuất đó trở thành sai hoặc lãng phí.

* Kết luận bằng một nguyên tắc cân bằng ngắn gọn của riêng anh/chị.