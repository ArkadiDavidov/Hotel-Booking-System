#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cctype>
#include <sstream>
#include "HotelBookingSystem.h"
#include "StringUtils.h"
#include "HotelDatabase.h"
#include "HotelInfoDisplayer.h"
#include "PriceDatabase.h"




int main() {
    const std::string hotelsFilename = "hotels_database.txt";
    const std::string pricesFilename = "price_database.txt";

    HotelBookingSystem system(hotelsFilename, pricesFilename);
    system.run();

    return 0;
}