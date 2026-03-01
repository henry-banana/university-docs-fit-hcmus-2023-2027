# 📱 Android Print Framework Demo

<div align="center">

![Android](https://img.shields.io/badge/Android-API%2019%2B-green)
![Kotlin](https://img.shields.io/badge/Kotlin-100%25-purple)
![License](https://img.shields.io/badge/License-Demo-blue)

**Ứng dụng demo đầy đủ về tính năng in ấn trên Android**

</div>

---

## 📋 Mục Lục

- [Giới Thiệu](#giới-thiệu)
- [Tính Năng](#tính-năng)
- [Yêu Cầu](#yêu-cầu)
- [Cài Đặt](#cài-đặt)
- [Sử Dụng](#sử-dụng)
- [Cấu Trúc Project](#cấu-trúc-project)
- [Tài Liệu](#tài-liệu)
- [Screenshots](#screenshots)

---

## 🎯 Giới Thiệu

Đây là một ứng dụng demo toàn diện về **Android Print Framework**, được thiết kế để minh họa tất cả các phương pháp in ấn phổ biến trên nền tảng Android (API 19+).

**Được xây dựng với:**
- ✅ 100% Kotlin
- ✅ Modern Android Development
- ✅ Clean Architecture
- ✅ Code có comment tiếng Việt đầy đủ

---

## ✨ Tính Năng

### 1. 🖼️ In Ảnh (Print Image)
- Sử dụng **PrintHelper** từ AndroidX Print Support Library
- Chế độ **SCALE_MODE_FIT** tự động co giãn ảnh
- In trực tiếp từ drawable resources

### 2. 🌐 In HTML (Print HTML)
- Render HTML động bằng **WebView**
- Hỗ trợ CSS styling đầy đủ
- Đợi WebView load xong (`onPageFinished`) trước khi in
- Phù hợp cho báo cáo, hóa đơn có format phức tạp

### 3. 📄 In Tài Liệu Tùy Chỉnh (Custom Document)
- Triển khai **PrintDocumentAdapter** từ đầu
- Sử dụng **PdfDocument** và **Canvas** để vẽ nội dung
- Demo vẽ:
  - Tiêu đề "Báo Cáo Demo"
  - Hình chữ nhật màu xanh
  - Text mô tả
- Kích thước A4 chuẩn

### 4. 📋 In PDF từ Assets
- Đọc file PDF có sẵn từ thư mục `assets/`
- Copy byte-by-byte vào **ParcelFileDescriptor**
- Hỗ trợ **CancellationSignal**
- Xử lý lỗi với Toast notification

---

## 📱 Yêu Cầu

- **Android Studio**: Arctic Fox trở lên
- **Min SDK**: API 19 (Android 4.4 KitKat)
- **Target SDK**: API 36
- **Compile SDK**: API 36
- **Kotlin**: 1.9+
- **Gradle**: 8.0+

---

## 🚀 Cài Đặt

### Bước 1: Clone hoặc Download Project

```bash
git clone <repository-url>
cd PrintDemo
```

### Bước 2: Mở trong Android Studio

1. Mở Android Studio
2. **File → Open** → Chọn thư mục project
3. Đợi Gradle sync hoàn tất

### Bước 3: Build Project

```bash
./gradlew build
```

### Bước 4: Chạy App

- Nhấn nút **Run** (Shift + F10)
- Hoặc qua terminal:
  ```bash
  ./gradlew installDebug
  ```

---

## 💡 Sử Dụng

### Giao Diện Chính

Ứng dụng hiển thị 4 nút chức năng:

1. **"In Ảnh (Print Image)"**
   - Nhấn để in ảnh mẫu từ drawable
   - Chọn máy in hoặc "Save as PDF"

2. **"In HTML (Print HTML)"**
   - Nhấn để in nội dung HTML động
   - Xem preview trước khi in

3. **"In Tài Liệu Tùy Chỉnh (Custom Document)"**
   - Nhấn để in tài liệu vẽ bằng Canvas
   - Chứa tiêu đề và hình vẽ

4. **"In PDF từ Assets (Print PDF)"**
   - Nhấn để in file sample.pdf có sẵn
   - Kiểm tra lỗi nếu file không tồn tại

### Tips

- 💾 **Save as PDF**: Chọn option này để lưu file thay vì in thật
- 🖨️ **Google Cloud Print**: Kết nối máy in qua WiFi
- 👀 **Preview**: Xem trước trước khi in để tiết kiệm giấy

---

## 📁 Cấu Trúc Project

```
app/
├── src/main/
│   ├── java/com/seminar/demoprint/
│   │   └── MainActivity.kt              # Logic chính
│   ├── res/
│   │   ├── layout/
│   │   │   └── activity_main.xml        # Giao diện XML
│   │   ├── drawable/
│   │   │   └── sample_image.png         # Ảnh mẫu
│   │   └── values/
│   │       ├── strings.xml
│   │       └── themes.xml
│   ├── assets/
│   │   └── sample.pdf                   # PDF mẫu
│   └── AndroidManifest.xml
├── build.gradle.kts                      # Dependencies
├── CODE_SUMMARY.md                       # Tài liệu kỹ thuật
├── HUONG_DAN_SU_DUNG.md                 # Hướng dẫn chi tiết
└── README.md                             # File này
```

---

## 📚 Tài Liệu

### Files Tài Liệu

1. **[CODE_SUMMARY.md](CODE_SUMMARY.md)**
   - Chi tiết kiến trúc code
   - Flow diagrams
   - Best practices
   - Testing checklist

2. **[HUONG_DAN_SU_DUNG.md](HUONG_DAN_SU_DUNG.md)**
   - Hướng dẫn sử dụng từng tính năng
   - Giải thích lifecycle của PrintDocumentAdapter
   - Lưu ý quan trọng
   - Ý tưởng mở rộng

### Code Highlights

#### MainActivity.kt

```kotlin
class MainActivity : AppCompatActivity() {
    
    // 4 chức năng chính
    private fun printImage() { ... }
    private fun printHtml() { ... }
    private fun printCustomDocument() { ... }
    private fun printPdfFromAssets() { ... }
    
    // 2 inner classes
    inner class CustomPrintDocumentAdapter { ... }
    inner class PdfPrintDocumentAdapter { ... }
}
```

#### Dependencies

```kotlin
dependencies {
    // Android Print Support
    implementation("androidx.appcompat:appcompat:1.6.1")
    implementation("androidx.print:print:1.0.0")
    implementation("com.google.android.material:material:1.11.0")
}
```

---

## 📸 Screenshots

*(Thêm screenshots của ứng dụng ở đây)*

| Màn Hình Chính | Print Dialog | PDF Output |
|----------------|--------------|------------|
| ![Main](link)  | ![Dialog](link) | ![PDF](link) |

---

## 🔧 Cấu Hình

### Thay Đổi Ảnh Mẫu

Thay thế file `res/drawable/sample_image.png` bằng ảnh của bạn.

### Thay Đổi PDF Mẫu

Thay thế file `assets/sample.pdf` bằng PDF của bạn.

### Tùy Chỉnh Custom Document

Chỉnh sửa hàm `drawPageContent()` trong [MainActivity.kt](src/main/java/com/seminar/demoprint/MainActivity.kt#L240):

```kotlin
private fun drawPageContent(canvas: Canvas) {
    // Vẽ nội dung của bạn ở đây
}
```

---

## 🎓 Học Hỏi

### Concepts Quan Trọng

1. **PrintManager**: System service quản lý in ấn
2. **PrintDocumentAdapter**: Abstract class để tạo nội dung in
3. **PrintHelper**: Utility để in ảnh nhanh
4. **PdfDocument**: Tạo PDF từ Canvas
5. **WebView Printing**: In nội dung web

### Lifecycle

```
onLayout() → onWrite() → [User changes settings] → onLayout() → onWrite()
```

### Error Handling

- ✅ Try-catch trong onWrite()
- ✅ Callback.onWriteFailed()
- ✅ CancellationSignal support
- ✅ Toast notifications

---

## 🤝 Đóng Góp

Đây là project demo cho mục đích học tập. Contributions are welcome!

### Cách Đóng Góp

1. Fork project
2. Tạo branch mới (`git checkout -b feature/AmazingFeature`)
3. Commit changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to branch (`git push origin feature/AmazingFeature`)
5. Tạo Pull Request

---

## 📝 License

Project này được tạo cho mục đích demo và học tập.

---

## 👨‍💻 Tác Giả

**Android Print Framework Demo**
- 📧 Email: [your-email]
- 🌐 GitHub: [your-github]

---

## 🙏 Tham Khảo

- [Android Print Framework Documentation](https://developer.android.com/training/printing)
- [PrintHelper API Reference](https://developer.android.com/reference/androidx/print/PrintHelper)
- [PrintDocumentAdapter Guide](https://developer.android.com/reference/android/print/PrintDocumentAdapter)
- [WebView Printing Tutorial](https://developer.android.com/training/printing/html-docs)

---

<div align="center">

**Made with ❤️ for learning Android Printing**

⭐ Đừng quên star repo nếu thấy hữu ích!

</div>
