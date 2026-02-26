#include "2DShapeManager.h"
#include <iostream>

int main() {
    ShapeManager manager;
    manager.addShapeFromFile("hhp.txt");
    
    // std::cout << manager << "\n";

    for (const auto& shape : manager) {
        std::cout << *shape << "\n";
    }

    manager.displayAllShapeInfo();

    return 0;
}