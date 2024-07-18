#pragma once
#include <string>
class RoomAvailability
{
private:
	int day;
	int month;
	int year;
	std::string isAvailable;
public:
	RoomAvailability();
	RoomAvailability(int day, int month, int year, std::string isAvailable);
	~RoomAvailability();
	std::string toString();
	int getDay();
	int	getMonth();
	int getYear();
	void setIsAvailable(std::string name);
	std::string getIsAvailable();

};

