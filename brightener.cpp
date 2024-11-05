#include "brightener.h"

Image::Image(int r, int c) : rows(r), columns(c) {
    // Validate dimensions
    if (r <= 0 || c <= 0) {
        throw std::runtime_error("Invalid image dimensions.");
    }

    // Check for potential overflow
    if (static_cast<long long>(r) * static_cast<long long>(c) > std::numeric_limits<size_t>::max()) {
        throw std::runtime_error("Image size exceeds maximum allowable size.");
    }

    // Allocate memory for pixels using unique_ptr
    pixels = std::make_unique<uint8_t[]>(r * c);
}

// Move constructor
Image::Image(Image&& other) noexcept
    : rows(other.rows), columns(other.columns), pixels(std::move(other.pixels)) {
    other.rows = 0;   // Optional: reset the moved-from object's members
    other.columns = 0; // Optional: reset the moved-from object's members
}

// Move assignment operator
Image& Image::operator=(Image&& other) noexcept {
    if (this != &other) {
        rows = other.rows;
        columns = other.columns;
        pixels = std::move(other.pixels);

        other.rows = 0;   // Optional: reset the moved-from object's members
        other.columns = 0; // Optional: reset the moved-from object's members
    }
    return *this;
}

ImageBrightener::ImageBrightener(Image& inputImage) : m_inputImage(inputImage) {
}

int ImageBrightener::BrightenWholeImage() {
    int attenuatedPixelCount = 0;
    for (int x = 0; x < m_inputImage.rows; x++) {
        for (int y = 0; y < m_inputImage.columns; y++) {
            uint8_t& pixel = m_inputImage.GetPixel(x, y); // Access pixel via the Image's method

            if (pixel > (255 - 25)) {
                ++attenuatedPixelCount;
                pixel = 255;
            }
            else {
                pixel += 25;
            }
        }
    }
    return attenuatedPixelCount;
}


const Image& ImageBrightener::GetImage() const {
    return m_inputImage;
}

