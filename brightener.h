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

    // Accessor for pixel at (row, column)
    uint8_t& GetPixel(int row, int col) {
        return pixels[row * columns + col]; // This maintains the layout knowledge
    }

    const uint8_t& GetPixel(int row, int col) const {
        return pixels[row * columns + col]; // Const version for read-only access
    }

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
    const Image& GetImage() const; // Return a reference to the Image
};

