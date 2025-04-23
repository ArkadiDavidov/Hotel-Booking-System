#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cctype>
#include <sstream>
#include "StringUtils.h"
#include "HotelDatabase.h"
#pragma once
class PriceDatabase
{
private:
    std::map<std::string, std::vector<std::string>> hotelPrices;

public:
    void loadFromFile(const std::string& filename) {
        std::ifstream file(filename);
        hotelPrices.clear();

        if (!file.is_open()) {
            std::cerr << "Error: Could not open file " << filename << std::endl;
            return;
        }

        std::string line;
        std::string currentHotel;

        while (std::getline(file, line)) {
            line = StringUtils::trim(line);

            if (line.empty()) {
                currentHotel.clear();
                continue;
            }

            if (line.empty() || !isdigit(line[0])) {
                currentHotel = line;
            }
            else {
                if (!currentHotel.empty()) {
                    hotelPrices[currentHotel].push_back(line);
                }
            }
        }

        file.close();
    }

    std::vector<std::string> getPricesForHotel(const std::string& hotelName) const {
        auto it = hotelPrices.find(hotelName);
        if (it != hotelPrices.end()) {
            return it->second;
        }
        return {};
    }
};

