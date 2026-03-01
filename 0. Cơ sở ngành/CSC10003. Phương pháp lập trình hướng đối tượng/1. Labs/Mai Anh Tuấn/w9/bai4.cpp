#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

class ChiTietMay;

class ChiTietMay {
protected:
    std::string maSo;

public:
    ChiTietMay(const std::string& ms) : maSo(ms) {}
    virtual ~ChiTietMay() {}

    virtual double TrongLuong() const = 0;
    virtual double GiaThanh() const = 0;
    virtual void Xuat(std::ostream& os, int depth = 0) const = 0;

    std::string getMaSo() const { return maSo; }
};

class ChiTietDon : public ChiTietMay {
private:
    double trongLuong_rieng;
    double giaThanh_rieng;

public:
    ChiTietDon(const std::string& ms, double tl, double gt)
        : ChiTietMay(ms), trongLuong_rieng(tl), giaThanh_rieng(gt) {}

    double TrongLuong() const override {
        return trongLuong_rieng;
    }

    double GiaThanh() const override {
        return giaThanh_rieng;
    }    void Xuat(std::ostream& os, int depth = 0) const override {
        for (int i = 0; i < depth; ++i) os << "  ";
        os << "Chi tiet don: " << maSo
           << ", Trong luong: " << trongLuong_rieng
           << ", Gia thanh: " << static_cast<long long>(giaThanh_rieng) << "\n";
    }
};

class ChiTietPhuc : public ChiTietMay {
private:
    std::vector<ChiTietMay*> dsChiTietCon;

public:
    ChiTietPhuc(const std::string& ms) : ChiTietMay(ms) {}

    ~ChiTietPhuc() override {
        for (ChiTietMay* ct : dsChiTietCon) {
            delete ct;
        }
        dsChiTietCon.clear();
    }

    void ThemChiTiet(ChiTietMay* ct) {
        dsChiTietCon.push_back(ct);
    }

    double TrongLuong() const override {
        double sum_tl_con = 0;
        for (const ChiTietMay* ct_con : dsChiTietCon) {
            sum_tl_con += ct_con->TrongLuong();
        }
        return sum_tl_con * 1.10;
    }

    double GiaThanh() const override {
        double sum_gt_con = 0;
        for (const ChiTietMay* ct_con : dsChiTietCon) {
            sum_gt_con += ct_con->GiaThanh();
        }
        return sum_gt_con * 1.20;
    }

    void Xuat(std::ostream& os, int depth = 0) const override {
        for (int i = 0; i < depth; ++i) os << "  ";
        os << "Chi tiet phuc: " << maSo 
           << " (TL: " << static_cast<long long>(TrongLuong()) 
           << ", GT: " << static_cast<long long>(GiaThanh()) 
           << "). Gom cac chi tiet con:" << "\n";
        for (const ChiTietMay* ct_con : dsChiTietCon) {
            ct_con->Xuat(os, depth + 1);
        }
    }
};

class CoMay {
private:
    std::vector<ChiTietMay*> dsChiTietChinh;

public:
    CoMay() {}

    ~CoMay() {
        for (ChiTietMay* ct : dsChiTietChinh) {
            delete ct;
        }
        dsChiTietChinh.clear();
    }

    void ThemChiTietMay(ChiTietMay* ct) {
        dsChiTietChinh.push_back(ct);
    }

    double TrongLuong() const {
        double total_tl = 0;
        for (const ChiTietMay* ct : dsChiTietChinh) {
            total_tl += ct->TrongLuong();
        }
        return total_tl;
    }

    double GiaThanh() const {
        double total_gt = 0;
        for (const ChiTietMay* ct : dsChiTietChinh) {
            total_gt += ct->GiaThanh();
        }
        return total_gt;
    }

    friend std::ostream& operator<<(std::ostream& os, const CoMay& cm) {
        os << "Danh sach cac chi tiet cua co may:" << "\n";
        if (cm.dsChiTietChinh.empty()) {
            os << "(Khong co chi tiet nao)" << "\n";
        } else {
            for (const ChiTietMay* ct : cm.dsChiTietChinh) {
                ct->Xuat(os, 0); 
            }
        }
        return os;
    }
};

int main() {
    CoMay* pcm = new CoMay();
    pcm->ThemChiTietMay(new ChiTietDon("CTD001", 120, 350000));    
    
    ChiTietMay* pctm = new ChiTietPhuc("CTP001");
    ((ChiTietPhuc*)pctm)->ThemChiTiet(new ChiTietDon("CTD002", 50, 1280000));
    ((ChiTietPhuc*)pctm)->ThemChiTiet(new ChiTietDon("CTD003", 20, 10000));

    ChiTietMay* pctm1 = new ChiTietPhuc("CTP002");
    ((ChiTietPhuc*)pctm1)->ThemChiTiet(new ChiTietDon("CTD004", 80, 170000));
    
    ((ChiTietPhuc*)pctm)->ThemChiTiet(pctm1); 

    pcm->ThemChiTietMay(pctm); 
    pcm->ThemChiTietMay(new ChiTietDon("CTD005", 210, 2350000));
    pcm->ThemChiTietMay(new ChiTietDon("CTD006", 40, 50000));    

    std::cout << "Thong tin co may: " << "\n" << *pcm << "\n";    
    std::cout << "Trong luong: " << pcm->TrongLuong() << "\n";
    std::cout << "Gia thanh: " << pcm->GiaThanh() << "\n";

    std::cout << "\n\n";
    delete pcm;
    
    return 0;
}