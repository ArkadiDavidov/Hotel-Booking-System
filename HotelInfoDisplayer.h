#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cctype>
#include <sstream>
#include "PriceDatabase.h"
#include "HotelDatabase.h"
#include "StringUtils.h"
#pragma once
class HotelInfoDisplayer
{
public:
    static void displayHotelInfo(const std::string& hotel, const PriceDatabase& priceDb) {
        std::cout << "\nHotel: " << hotel << "\n";

        auto prices = priceDb.getPricesForHotel(hotel);
        if (!prices.empty()) {
            std::cout << "Price information:\n";
            for (const auto& priceLine : prices) {
                std::cout << "  - " << priceLine << "\n";
            }
        }
        else {
            std::cout << "Price information not available\n";
        }
    }
};

