# Hotel Booking System

A C++ console application that allows users to browse hotels in different cities and view pricing information. The system loads data from text files and provides an interactive interface for searching and displaying hotel details.

## Features
✔ City-Based Hotel Search – Browse available hotels by city.
✔ Price Information – View detailed pricing for selected hotels.
✔ Text Database Integration – Loads hotel and price data from .txt files.
✔ Case-Insensitive Search – Finds hotels regardless of input case.
✔ Multiple Selection – View details for one or all hotels at once.

## How It Works

### Data Loading

HotelDatabase reads hotels_database.txt (structured by city).

PriceDatabase reads price_database.txt (maps hotels to prices).

### User Interaction

Users select a city to view available hotels.

They can then:

Enter specific hotel names (comma-separated).

Type all to display all hotels in the city.

### Price Display

The system retrieves and formats pricing data for selected hotels.

## Code Structure

1. Core Classes

Class	Purpose	Key Methods

StringUtils	String manipulation helpers	trim(), toLower(), splitString()

HotelDatabase	Manages city-hotel mappings	loadFromFile(), getCities(), getHotelsForCity()

PriceDatabase	Stores hotel pricing data	loadFromFile(), getPricesForHotel()

HotelInfoDisplayer	Formats hotel/price output	displayHotelInfo()

HotelBookingSystem	Main logic and user flow	run(), processCityHotels(), displayPricesForHotels()

## Possible Improvements

🔹 Booking functionality (reserve rooms, date selection).

🔹 User accounts (save preferences/history).

🔹 Advanced filtering (by price range, ratings).

🔹 Error handling (invalid file formats, malformed inputs).
