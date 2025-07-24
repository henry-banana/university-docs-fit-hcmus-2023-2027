#include <iostream>

// Bài 1: Cài đặt lại ví dụ về các phương thức khởi tạo và hủy được gọi
// ================== PROTOTYPE ===================
static int count = 0;

class Hero {
private:
    int hero_id;
    std::string hero_name;
public:
    Hero();
    Hero(std::string name);
    ~Hero();
};
void CreateHero();

//  ================== MAIN ===================
Hero heroGlobal; // Hero toan cuc

int main() {

    /*
    NHẬN XÉT:
    - Khi chạy chương trình, hàm main sẽ được gọi đầu tiên, sau đó tạo ra một đối tượng Hero toàn cục
    - Sau đó, hàm CreateHero() được gọi, tạo ra 2 đối tượng Hero trong hàm này
    - Khi kết thúc hàm CreateHero(), 2 đối tượng Hero trong hàm này sẽ bị hủy
    - Khi kết thúc hàm main(), đối tượng hero1 bị hủy trước rồi đến Hero toàn cục sẽ bị hủy
    - Kết quả: 2 đối tượng Hero trong hàm CreateHero() sẽ bị hủy trước, sau đó đến đối tượng hero1 trong 
    hàm main() và cuối cùng là đối tượng heroGlobal
    */

    Hero hero1; // Hero trong main
    CreateHero(); // Hero trong ham
    return 0;
}

// ================== FUNCTION ===================

Hero::Hero() {
    hero_id = ++count;
    hero_name = "Hero " + std::to_string(hero_id);
    std::cout << "Hero thu " << hero_id << " - Ten la << " << hero_name << " da duoc tao (mac dinh)\n";
}

Hero::Hero(std::string name) {
    hero_id = ++count;
    hero_name = name;
    std::cout << "Hero thu " << hero_id << " - Ten la << " << hero_name << " da duoc tao (co doi so)\n";
}

Hero::~Hero() {
    std::cout << "Hero thu " << hero_id << " - Ten la << " << hero_name << " da bi huy\n";
}

void CreateHero() {
    Hero h1("Superman");
    Hero h2;
}