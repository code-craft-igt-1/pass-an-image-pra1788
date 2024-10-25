#pragma once
#include <cstdint>
#include <vector>
#include <memory>    // For std::unique_ptr
#include <stdexcept> // For std::runtime_error
#include <limits>    // For std::numeric_limits

struct Image {
    int rows;
    int columns;
    std::unique_ptr<uint8_t[]> pixels; // Use unique_ptr for automatic memory management

    Image(int r, int c);

    // Move constructor
    Image(Image&& other) noexcept;

    // Move assignment operator
    Image& operator=(Image&& other) noexcept;

    // Delete copy constructor and copy assignment operator
    Image(const Image&) = delete;
    Image& operator=(const Image&) = delete;
};

class ImageBrightener {
private:
    Image& m_inputImage; // Reference to input image
public:
    ImageBrightener(Image& inputImage);
    int BrightenWholeImage();
    Image& GetImage(); // Return a reference to the Image
};

