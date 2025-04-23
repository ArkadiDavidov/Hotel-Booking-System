#pragma once
#include <iostream>
#include <string>
#include <random>
#include <regex>
class Reservation
{
private:
	std::string city, hotel, hotel_class;
	int price, room, adults, children;
public:
	Reservation(std::string city1, std::string hotel1, std::string hotel_class1, int price1, int room1, int adults1, int children1) {
		city = city1;
		hotel = hotel1;
		hotel_class = hotel_class1;
		price = price1;
		room = room1;
		adults = adults1;
		children = children1;
	}


	


};

