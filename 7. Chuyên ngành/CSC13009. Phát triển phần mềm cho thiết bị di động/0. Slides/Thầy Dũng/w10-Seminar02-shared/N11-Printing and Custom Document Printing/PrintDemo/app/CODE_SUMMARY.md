# Code Summary - MainActivity.kt

## Tổng Quan Kiến Trúc

### Imports Chính
```kotlin
import android.print.PrintManager
import android.print.PrintDocumentAdapter
import android.print.PrintAttributes
import android.graphics.pdf.PdfDocument
import androidx.print.PrintHelper
import android.webkit.WebView
```

## Chi Tiết Các Class

### 1. MainActivity (AppCompatActivity)
**Vai trò**: Activity chính, điều phối các tính năng in

**Các phương thức chính**:
- `onCreate()`: Khởi tạo UI
- `setupButtons()`: Gắn sự kiện cho 4 nút
- `printImage()`: In ảnh từ drawable
- `printHtml()`: In nội dung HTML
- `printCustomDocument()`: In tài liệu vẽ bằng Canvas
- `printPdfFromAssets()`: In PDF từ assets

---

### 2. CustomPrintDocumentAdapter (Inner class)
**Extends**: `PrintDocumentAdapter`
**Mục đích**: Tạo PDF tùy chỉnh bằng cách vẽ lên Canvas

#### Phương thức onLayout()
**Tham số**:
- `oldAttributes`: Thuộc tính in trước đó
- `newAttributes`: Thuộc tính in mới
- `cancellationSignal`: Signal để hủy bỏ
- `callback`: Callback để thông báo kết quả
- `extras`: Bundle dữ liệu phụ

**Nhiệm vụ**:
1. Kiểm tra nếu bị hủy → gọi `callback.onLayoutCancelled()`
2. Tạo `PrintDocumentInfo` với:
   - Tên file: "custom_document.pdf"
   - Content type: DOCUMENT
   - Số trang: 1
3. Gọi `callback.onLayoutFinished(info, hasChanged)`

#### Phương thức onWrite()
**Tham số**:
- `pages`: Mảng các PageRange cần in
- `destination`: ParcelFileDescriptor để ghi PDF
- `cancellationSignal`: Signal để hủy
- `callback`: Callback thông báo kết quả

**Nhiệm vụ**:
1. Tạo `PdfDocument()`
2. Tạo trang mới với kích thước A4 (595x842)
3. Gọi `drawPageContent()` để vẽ nội dung
4. `finishPage()` để hoàn tất trang
5. Ghi PDF ra `destination.fileDescriptor`
6. Gọi `callback.onWriteFinished()`

**Error handling**: Try-catch với `callback.onWriteFailed()`

#### Phương thức drawPageContent()
**Tham số**: `canvas: Canvas`

**Vẽ các thành phần**:
1. **Tiêu đề "Báo Cáo Demo"**:
   - Font: 40f, đậm, căn giữa
   - Vị trí: (canvas.width/2, 100)
   
2. **Hình chữ nhật xanh**:
   - Màu: Color.BLUE
   - Tọa độ: (100, 200, 495, 400)
   - Style: FILL
   
3. **Text mô tả**:
   - Font: 24f
   - 2 dòng text giải thích

---

### 3. PdfPrintDocumentAdapter (Inner class)
**Extends**: `PrintDocumentAdapter`
**Mục đích**: In file PDF từ assets

**Constructor**:
```kotlin
PdfPrintDocumentAdapter(
    context: Context,
    fileName: String  // Tên file trong assets
)
```

#### Phương thức onLayout()
**Khác biệt với CustomPrintDocumentAdapter**:
- `pageCount`: Sử dụng `PAGE_COUNT_UNKNOWN` vì không biết trước số trang của PDF

#### Phương thức onWrite()
**Luồng xử lý**:
1. Mở file từ assets: `context.assets.open(fileName)`
2. Tạo buffer 8KB để đọc/ghi
3. Vòng lặp đọc và ghi:
   ```kotlin
   while (inputStream.read(buffer).also { bytesRead = it } != -1) {
       // Kiểm tra cancellation
       if (cancellationSignal?.isCanceled == true) {
           callback.onWriteCancelled()
           return
       }
       output.write(buffer, 0, bytesRead)
   }
   ```
4. Đóng streams và gọi callback

**Error handling**:
- Catch Exception → hiển thị Toast
- Gọi `callback.onWriteFailed()`

---

## Flow Diagram

### Print Image Flow
```
User nhấn nút → printImage()
    ↓
Decode bitmap từ R.drawable.sample_image
    ↓
Tạo PrintHelper với SCALE_MODE_FIT
    ↓
printHelper.printBitmap()
    ↓
Hệ thống hiển thị Print Dialog
```

### Print HTML Flow
```
User nhấn nút → printHtml()
    ↓
Tạo WebView + WebViewClient
    ↓
Load HTML content vào WebView
    ↓
WebViewClient.onPageFinished() → createWebPrintJob()
    ↓
webView.createPrintDocumentAdapter()
    ↓
PrintManager.print()
```

### Print Custom Document Flow
```
User nhấn nút → printCustomDocument()
    ↓
Tạo CustomPrintDocumentAdapter
    ↓
PrintManager.print()
    ↓
System calls: onLayout() → onWrite()
    ↓
onWrite(): PdfDocument → drawPageContent() → writeTo()
    ↓
callback.onWriteFinished()
```

### Print PDF from Assets Flow
```
User nhấn nút → printPdfFromAssets()
    ↓
Tạo PdfPrintDocumentAdapter(fileName="sample.pdf")
    ↓
PrintManager.print()
    ↓
System calls: onLayout() → onWrite()
    ↓
onWrite(): Đọc từ assets → Copy byte-by-byte → destination
    ↓
callback.onWriteFinished()
```

---

## Key Concepts

### 1. PrintManager
- System service để quản lý in ấn
- Lấy qua: `getSystemService(Context.PRINT_SERVICE)`
- Method chính: `print(jobName, adapter, attributes)`

### 2. PrintDocumentAdapter
- Abstract class để tạo nội dung in
- **Phải override**: `onLayout()` và `onWrite()`
- Lifecycle: onLayout → onWrite (có thể lặp lại nhiều lần)

### 3. PrintHelper (Support Library)
- Tiện ích để in ảnh đơn giản
- Tự động xử lý scaling và layout
- Modes: SCALE_MODE_FIT, SCALE_MODE_FILL

### 4. WebView Printing
- WebView tự tạo PrintDocumentAdapter
- Phải đợi `onPageFinished()` mới in được
- Hỗ trợ CSS styling đầy đủ

### 5. PdfDocument
- Class để tạo PDF từ Canvas
- API: startPage() → vẽ lên canvas → finishPage()
- writeTo() để xuất ra OutputStream

---

## Best Practices Đã Áp Dụng

### 1. Error Handling
✅ Try-catch trong onWrite()
✅ Callback.onWriteFailed() khi lỗi
✅ Toast thông báo lỗi cho user

### 2. Cancellation Support
✅ Kiểm tra `cancellationSignal?.isCanceled`
✅ Gọi `callback.onWriteCancelled()` khi cần
✅ Return ngay lập tức khi bị cancel

### 3. Resource Management
✅ Use FileOutputStream.use {} để tự động đóng
✅ Close PdfDocument trong finally block
✅ Close InputStream sau khi đọc xong

### 4. Code Organization
✅ Comment tiếng Việt giải thích logic
✅ Phân chia rõ ràng các section
✅ Inner classes cho adapter tùy chỉnh
✅ Tên biến/hàm rõ ràng, dễ hiểu

---

## Testing Checklist

- [ ] Test in ảnh: Kiểm tra scaling đúng
- [ ] Test in HTML: Kiểm tra CSS render
- [ ] Test custom document: Kiểm tra text và hình vẽ
- [ ] Test PDF từ assets: Kiểm tra file có mở được
- [ ] Test cancel trong quá trình in
- [ ] Test trên các kích thước giấy khác nhau
- [ ] Test chế độ landscape/portrait
- [ ] Test trên Android versions khác nhau (API 19+)

---

## Extensibility Points

### Dễ mở rộng thêm:
1. **Thêm loại in khác**: Tạo PrintDocumentAdapter mới
2. **Tùy chỉnh PrintAttributes**: Thêm tham số trong print()
3. **In nhiều trang**: Tăng pageCount và loop trong onWrite()
4. **Preview trước khi in**: Tạo PdfDocument riêng để hiển thị
5. **In từ URL**: Kết hợp WebView + network request
