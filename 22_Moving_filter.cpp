#include <iostream>
#include <vector>
#include <iomanip>

class MovingFilter {
public:
    explicit MovingFilter(std::size_t size)
        : size_(size), buffer_(size, 0.0f), index_(0), count_(0) {}

    // Add a new sample and return the current moving average
    float addSample(float sample) {
        buffer_[index_] = sample;
        index_ = (index_ + 1) % size_; // wrap index
        if (count_ < size_) ++count_;

        float sum = 0.0f;
        for (std::size_t i = 0; i < count_; ++i) sum += buffer_[i];
        return sum / static_cast<float>(count_);
    }

private:
    std::size_t size_;
    std::vector<float> buffer_;
    std::size_t index_;
    std::size_t count_;
};

int main() {
    MovingFilter filter(3); // same filter size as original

    std::vector<float> samples = {1, 5, 6, 7, 3, 5, 2, 6, 8, 9, 4, 3};
    for (float s : samples) {
        float avg = filter.addSample(s);
        std::cout << "Input: " << std::fixed << std::setprecision(2) << s
                  << "\tMoving ave: " << std::fixed << std::setprecision(2) << avg << '\n';
    }

    return 0;
}