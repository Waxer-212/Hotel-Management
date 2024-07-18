#include "RoomAvailability.h"
#include <string>
#include <vector>
RoomAvailability::RoomAvailability()
{
	day = 0;
	month = 0;
	year = 0;
	isAvailable = "free";
}
RoomAvailability::RoomAvailability(int day, int month, int year, std::string isAvailable)
{
	this->day = day;
	this->month = month;
	this->year = year;
	this->isAvailable = isAvailable;
}
RoomAvailability::~RoomAvailability()
{
}
std::string RoomAvailability::toString()
{
	std::string str = std::to_string(day) + "/" + std::to_string(month) + "/" + std::to_string(year) + " " + getIsAvailable();
	
	return str;
}
int RoomAvailability::getDay()
{
	return day;
}
int RoomAvailability::getMonth()
{
	return month;
}
int RoomAvailability::getYear()
{
	return year;
}
void RoomAvailability::setIsAvailable(std::string name)
{
	isAvailable = name;
}
std::string RoomAvailability::getIsAvailable()
{
	return isAvailable;
}