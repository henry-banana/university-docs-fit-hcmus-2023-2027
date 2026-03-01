# Android Print Framework Demo - Hướng Dẫn Sử Dụng

## Tổng Quan
Ứng dụng demo này minh họa các tính năng in ấn trên Android sử dụng **Android Print Framework** (API 19+).

## Các Chức Năng Đã Triển Khai

### 1. **In Ảnh (Print Image)** 📸
- **Công nghệ**: `PrintHelper` từ AndroidX Print Support Library
- **Chế độ**: `SCALE_MODE_FIT` - Ảnh sẽ tự động co giãn vừa với khổ giấy
- **Source**: Ảnh từ `R.drawable.sample_image`
- **Cách hoạt động**:
  - Tải bitmap từ drawable resources
  - Sử dụng PrintHelper để tạo công việc in
  - Hệ thống tự động hiển thị hộp thoại in

### 2. **In HTML (Print HTML)** 🌐
- **Công nghệ**: `WebView` + `PrintDocumentAdapter`
- **Nội dung**: HTML động được tạo trong code
- **Đặc điểm**:
  - Tạo nội dung HTML với CSS styling
  - Sử dụng WebViewClient để đợi trang load xong (`onPageFinished`)
  - Gọi `createPrintDocumentAdapter()` từ WebView
  - Phù hợp cho in báo cáo, hóa đơn có định dạng phức tạp

### 3. **In Tài Liệu Tùy Chỉnh (Custom Document)** 📄
- **Công nghệ**: `PrintDocumentAdapter` + `PdfDocument` + `Canvas`
- **Triển khai**:
  - Kế thừa `PrintDocumentAdapter`
  - Override `onLayout()`: Tính toán số trang và thuộc tính
  - Override `onWrite()`: Vẽ nội dung lên Canvas và ghi ra PDF
- **Nội dung demo**:
  - Tiêu đề "Báo Cáo Demo" (text màu đen, in đậm)
  - Hình chữ nhật màu xanh
  - Text mô tả về tài liệu
- **Kích thước trang**: A4 (595 x 842 points)

### 4. **In PDF từ Assets (Print PDF from Assets)** 📋
- **Công nghệ**: Custom `PrintDocumentAdapter` + Asset Manager
- **Nguồn**: File `sample.pdf` trong thư mục `assets/`
- **Cách hoạt động**:
  - Đọc file PDF từ assets bằng `AssetManager`
  - Copy byte-by-byte vào `ParcelFileDescriptor`
  - Hỗ trợ kiểm tra `CancellationSignal` trong quá trình copy
- **Ứng dụng**: In các tài liệu PDF có sẵn trong ứng dụng

## Cấu Trúc Code

### MainActivity.kt
```
MainActivity
├── onCreate() - Khởi tạo và thiết lập UI
├── setupButtons() - Gắn sự kiện click cho các nút
├── printImage() - Chức năng 1
├── printHtml() - Chức năng 2
│   └── createWebPrintJob()
├── printCustomDocument() - Chức năng 3
│   └── CustomPrintDocumentAdapter
│       ├── onLayout()
│       ├── onWrite()
│       └── drawPageContent()
└── printPdfFromAssets() - Chức năng 4
    └── PdfPrintDocumentAdapter
        ├── onLayout()
        └── onWrite()
```

## Dependencies Đã Thêm

```kotlin
// AppCompat cho Activity cơ bản
implementation("androidx.appcompat:appcompat:1.6.1")

// Print Support Library
implementation("androidx.print:print:1.0.0")

// Material Design Components
implementation("com.google.android.material:material:1.11.0")
```

## Files Đã Tạo

### 1. Layout
- `res/layout/activity_main.xml` - Giao diện chính với 4 nút

### 2. MainActivity
- `java/com/seminar/demoprint/MainActivity.kt` - Logic chính

### 3. Resources
- `res/drawable/sample_image.png` - Ảnh mẫu để in
- `assets/sample.pdf` - File PDF mẫu

## Cách Sử Dụng

1. **Build và chạy ứng dụng** trên thiết bị Android (API 19+)
2. **Nhấn vào nút tương ứng** với tính năng muốn test
3. **Hộp thoại in** sẽ xuất hiện:
   - Chọn máy in (hoặc "Save as PDF")
   - Điều chỉnh cài đặt (số trang, màu sắc, kích thước giấy)
   - Nhấn nút "Print" hoặc "Save"

## Lưu Ý Quan Trọng

### PrintDocumentAdapter Lifecycle
```
onLayout() → onWrite() → [User interacts] → onLayout() → onWrite() → ...
```

- `onLayout()`: Được gọi khi:
  - Lần đầu khởi tạo in
  - User thay đổi cài đặt (hướng giấy, kích thước, v.v.)
  
- `onWrite()`: Được gọi khi:
  - Sau onLayout() hoàn thành
  - Cần ghi nội dung PDF ra file

### Cancellation Support
- Luôn kiểm tra `cancellationSignal?.isCanceled` trong các vòng lặp dài
- Gọi `callback.onWriteCancelled()` khi bị hủy
- Giải phóng resources ngay lập tức

### Error Handling
- Bao bọc logic trong try-catch
- Gọi `callback.onWriteFailed()` khi có lỗi
- Hiển thị thông báo lỗi cho user

## Testing

### Test trên Emulator
- Chọn "Save as PDF" để lưu file PDF và kiểm tra
- File sẽ được lưu vào Downloads hoặc thư mục do user chọn

### Test trên Thiết Bị Thật
- Kết nối với máy in qua WiFi/Bluetooth
- Sử dụng Google Cloud Print (nếu có)
- In trực tiếp ra giấy để kiểm tra chất lượng

## Tham Khảo
- [Android Print Framework Documentation](https://developer.android.com/training/printing)
- [PrintHelper Guide](https://developer.android.com/reference/androidx/print/PrintHelper)
- [PrintDocumentAdapter API](https://developer.android.com/reference/android/print/PrintDocumentAdapter)

## Mở Rộng

Có thể thêm:
- In từ nhiều nguồn khác (SD card, cloud storage)
- Preview trước khi in
- Tùy chỉnh layout phức tạp hơn
- Thêm watermark, header/footer
- Hỗ trợ in batch nhiều tài liệu
