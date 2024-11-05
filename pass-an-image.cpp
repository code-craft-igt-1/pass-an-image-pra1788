#include <iostream>
#include "brightener.h"

// Custom exception for image-related errors
class ImageException : public std::runtime_error {
public:
    using std::runtime_error::runtime_error;
};

int main() {
    try {
        Image image(512, 512); // Create image with 512x512 size
        std::cout << "Brightening a 512 x 512 image\n";
        ImageBrightener brightener(image);
        int attenuatedCount = brightener.BrightenWholeImage();
        std::cout << "Attenuated " << attenuatedCount << " pixels\n";
    }
    catch (const ImageException& e) {
        std::cerr << "Image Error: " << e.what() << '\n';
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Runtime Error: " << e.what() << '\n';
    }
    catch (const std::exception& e) {
        std::cerr << "General Error: " << e.what() << '\n';
    }
}
