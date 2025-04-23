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
#include "HotelInfoDisplayer.h"
#include "PriceDatabase.h"

#pragma once
class HotelBookingSystem
{
private:
    HotelDatabase hotelDb;
    PriceDatabase priceDb;
    const std::string exitCmd = "exit";

public:
    HotelBookingSystem(const std::string& hotelsFile, const std::string& pricesFile) {
        hotelDb.loadFromFile(hotelsFile);
        priceDb.loadFromFile(pricesFile);
    }

    void run() {
        displayAvailableCities();

        while (true) {
            std::string cityInput = promptForCity();
            if (shouldExit(cityInput)) break;

            if (!hotelDb.cityExists(cityInput)) {
                std::cout << "City not found in database!\n";
                continue;
            }

            processCityHotels(cityInput);
        }
    }

private:
    void displayAvailableCities() const {
        std::cout << "Available cities:\n";
        for (const auto& city : hotelDb.getCities()) {
            std::cout << "- " << city << "\n";
        }
    }

    std::string promptForCity() const {
        std::cout << "\nEnter city name (or '" << exitCmd << "' to quit): ";
        std::string cityInput;
        std::getline(std::cin, cityInput);
        return StringUtils::trim(cityInput);
    }

    bool shouldExit(const std::string& input) const {
        return StringUtils::toLower(input) == StringUtils::toLower(exitCmd);
    }

    void processCityHotels(const std::string& cityName) {
        std::vector<std::string> hotels = hotelDb.getHotelsForCity(cityName);
        displayHotelsInCity(cityName, hotels);

        std::string hotelsInput = promptForHotels();
        std::vector<std::string> selectedHotels = getSelectedHotels(hotelsInput, hotels);

        displayPricesForHotels(cityName, selectedHotels);
    }

    void displayHotelsInCity(const std::string& cityName, const std::vector<std::string>& hotels) const {
        std::cout << "\nAvailable hotels in " << cityName << ":\n";
        for (const auto& hotel : hotels) {
            std::cout << "- " << hotel << "\n";
        }
    }

    std::string promptForHotels() const {
        std::cout << "\nEnter hotel names separated by commas (or 'all' to show all): ";
        std::string hotelsInput;
        std::getline(std::cin, hotelsInput);
        return StringUtils::trim(hotelsInput);
    }

    std::vector<std::string> getSelectedHotels(const std::string& hotelsInput, const std::vector<std::string>& availableHotels) const {
        if (StringUtils::toLower(hotelsInput) == "all") {
            return availableHotels;
        }
        return StringUtils::splitString(hotelsInput, ',');
    }

    void displayPricesForHotels(const std::string& cityName, const std::vector<std::string>& hotels) const {
        std::cout << "\nPrice information for selected hotels in " << cityName << ":\n";
        bool anyFound = false;

        for (const auto& hotel : hotels) {
            std::string trimmedHotel = StringUtils::trim(hotel);
            if (std::find(hotels.begin(), hotels.end(), trimmedHotel) != hotels.end()) {
                HotelInfoDisplayer::displayHotelInfo(trimmedHotel, priceDb);
                anyFound = true;
            }
            else {
                std::cout << "\nHotel '" << trimmedHotel << "' not found in " << cityName << "\n";
            }
        }

        if (!anyFound) {
            std::cout << "No matching hotels found.\n";
        }
    }
};

