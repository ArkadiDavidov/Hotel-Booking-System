#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cctype>
#include <sstream>
#include "StringUtils.h"
#pragma once
class HotelDatabase
{
private:
    std::map<std::string, std::vector<std::string>> cityHotels;

public:
    void loadFromFile(const std::string& filename) {
        std::ifstream file(filename);
        cityHotels.clear();

        if (!file.is_open()) {
            std::cerr << "Error: Could not open file " << filename << std::endl;
            return;
        }

        std::string line;
        std::string currentCity;

        while (std::getline(file, line)) {
            line = StringUtils::trim(line);
            if (line.empty()) {
                currentCity.clear();
                continue;
            }

            if (currentCity.empty()) {
                currentCity = line;
            }
            else {
                cityHotels[currentCity].push_back(line);
            }
        }

        file.close();
    }

    std::vector<std::string> getCities() const {
        std::vector<std::string> cities;
        for (const auto& pair : cityHotels) {
            cities.push_back(StringUtils::removeHashTag(pair.first));
        }
        return cities;
    }

    std::vector<std::string> getHotelsForCity(const std::string& cityName) const {
        std::string lowerCity = StringUtils::toLower(cityName);
        for (const auto& pair : cityHotels) {
            std::string currentCity = StringUtils::removeHashTag(pair.first);
            if (StringUtils::toLower(currentCity) == lowerCity) {
                return pair.second;
            }
        }
        return {};
    }

    bool cityExists(const std::string& cityName) const {
        std::string lowerCity = StringUtils::toLower(cityName);
        for (const auto& pair : cityHotels) {
            std::string currentCity = StringUtils::removeHashTag(pair.first);
            if (StringUtils::toLower(currentCity) == lowerCity) {
                return true;
            }
        }
        return false;
    }
};

