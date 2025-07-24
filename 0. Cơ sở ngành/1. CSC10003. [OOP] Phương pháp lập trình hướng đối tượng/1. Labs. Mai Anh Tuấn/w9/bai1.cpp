#include <iostream>
#include <vector>

class Base {
public:
	virtual void Print(std::ostream& os) = 0;
	friend std::ostream& operator<<(std::ostream& os, Base& base) {
		base.Print(os);
		return os;
	}
};

class Derived1 :public Base {
private:
	int _ofD1;
public:
	Derived1(const int& v) {
		_ofD1 = v;
	}

	void Print(std::ostream& os) {
		os << "D1 - " << _ofD1;
	}
};

class Derived2 :public Base {
private:
	int _ofD2;
public:
	Derived2(const int& v) {
		_ofD2 = v;
	}

	void Print(std::ostream& os) {
		os << "D2 - " << _ofD2;
	}
};

int main() {
	std::vector<Base*> ds;
	ds.push_back(new Derived1(13));
	ds.push_back(new Derived1(17));
	ds.push_back(new Derived2(24));
	ds.push_back(new Derived2(28));
	for (int i = 0; i < ds.size(); i++) {
		std::cout << *ds[i] << "\n";
	}

	std::cout << "\n\n";
	system("pause");
	return 0;
}