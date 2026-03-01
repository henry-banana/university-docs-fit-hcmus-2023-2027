#ifndef _INHANVIEN_H_
#define _INHANVIEN_H_

class INhanVien {
public:
    virtual ~INhanVien();
    virtual const char* hoTen() const = 0;
    virtual const char* diaChi() const = 0;
    virtual bool isXuatSac() const = 0;
};

#endif