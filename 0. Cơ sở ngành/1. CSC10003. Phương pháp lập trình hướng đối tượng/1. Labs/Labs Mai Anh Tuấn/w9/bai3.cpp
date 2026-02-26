#include <iostream>
#include <vector>
#include <string>

class PrintConsoleDevice {
private:
	std::ostream* os;
	PrintConsoleDevice() { os = &std::cout; }
public:
	void Print(const std::string& s) {
		*os << s;
	}
	static PrintConsoleDevice GetInstance() {
		static PrintConsoleDevice instance;
		return instance;
	}
};

int main() {
	PrintConsoleDevice print = PrintConsoleDevice::GetInstance();
	print.Print("Su dung in lan 1\n");
	PrintConsoleDevice print2 = PrintConsoleDevice::GetInstance();
	print2.Print("Su dung in lan 2\n");

	system("pause");
	return 0;
}