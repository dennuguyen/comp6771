#pragma once

#include <map>
#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>
// Time: 958 ns
class OrderBook {
   public:
    OrderBook(std::vector<std::pair<std::string, unsigned long>> levels);

    unsigned long get_volume(std::string_view const price_level) {
        auto it = mVolumes.find({price_level.data(), price_level.size()});
        if (it != mVolumes.end()) {
            return it->second;
        }
        return 0;
    }

   private:
    std::map<std::string, unsigned long> mVolumes;  // Implemented as tree, log search
};

// Time: 415 ns
class OrderBook {
   public:
    OrderBook(std::vector<std::pair<std::string, unsigned long>> levels);

    unsigned long get_volume(std::string_view const price_level) {
        auto it = mVolumes.find({price_level.data(), price_level.size()});
        if (it != mVolumes.end()) {
            return it->second;
        }
        return 0;
    }

   private:
    std::unordered_map<std::string, unsigned long> mVolumes;  // O(1) lookup
};

// Time: 243 ns
class OrderBook {
   public:
    OrderBook(std::vector<std::pair<std::string, unsigned long>> levels);

    unsigned long get_volume(std::string_view const price_level) {
        auto it = mVolumes.find(price_level);
        if (it != mVolumes.end()) {
            return it->second;
        }
        return 0;
    }

   private:
    std::vector<std::string> mPrices;                              // pre-allocate memory
    std::unordered_map<std::string_view, unsigned long> mVolumes;  // O(1) lookup
};

// Time: 136 ns
class OrderBook {
   public:
    OrderBook(std::vector<std::pair<std::string, unsigned long>> levels);

    unsigned long get_volume(std::string_view const price_level) {
        auto price = static_cast<unsigned long>(std::strtod(price_level.data(), nullptr) * 100);
        return mBuffer[price % mBuffer.size()];
    }

   private:
    std::vector<unsigned long> mBuffer;
};

class OrderBook {
   public:
    OrderBook(std::vector<std::pair<std::string, unsigned long>> levels);

    unsigned long get_volume(std::string_view const price_level) {
        auto price = static_cast<unsigned long>(std::strtod(price_level.data(), nullptr) * 100);
        return mBuffer[price & (mBuffer.size() - 1)];  // If mBuffer always had size power of two.
    }

   private:
    std::vector<unsigned long> mBuffer;
};