#ifndef _NHANVIENKYTHUAT_H_
#define _NHANVIENKYTHUAT_H_

#include "NhanVien.h"

class NhanVienKyThuat : public NhanVien {
private:
    std::string _chungChiNganh;

public:
    NhanVienKyThuat();
    NhanVienKyThuat(const std::string& ht, const std::string& dc, const std::string& cc);
    ~NhanVienKyThuat();

    friend std::ostream& operator<<(std::ostream& os, const NhanVienKyThuat& nvkt);
};

#endif