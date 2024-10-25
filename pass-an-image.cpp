#include <iostream>
#include "brightener.h"

int main() {
    try {
        Image image(512, 512); // Create image with 512x512 size
        std::cout << "Brightening a 512 x 512 image\n";
        ImageBrightener brightener(image);
        int attenuatedCount = brightener.BrightenWholeImage();
        std::cout << "Attenuated " << attenuatedCount << " pixels\n";
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
    }
}
