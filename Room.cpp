#include "Room.h"
#include <iostream>
Room::Room()
{
	roomNumber = 0;
	roomType = 0;
}
Room::Room(int roomNumber, int roomType)
{
	this->roomNumber = roomNumber;
	this->roomType = roomType;
}
Room::~Room()
{
	//std::cout<<"Room "<<roomNumber<<" is destroyed"<<std::endl;
}
int Room::getDaysinMonth(int month, int year)
{
	switch(month) {
		case 2:
			if (year % 4 == 0)
				return 29;
			else
				return 28;
			break;
		case 4 : case 6 : case 9 : case 11:
			return 30;
			break;
		default:
			return 31;
	}
}
int Room::bookRoom(int roomtype, int day, int month, int year, std::string name, std::string filename, int daysWanted)
{
	std::ifstream file;
	file.open(filename);
	if (!file)
	{
		std::cout<<"Error opening file"<<std::endl;
		return 0;
	}
	int room_number = 0;
	int daysAvailable = 0;
	std::string line;
	std::vector<RoomAvailability> Availability;
	while (std::getline(file, line))
	{
		if (line.find("RoomNumber = ") != std::string::npos)
		{
			roomNumber = std::stoi(line.substr(line.find("=") + 1));
		}
		else if (line.find("RoomType = ") != std::string::npos)
		{
			roomType = std::stoi(line.substr(line.find("=") + 1));
		}
		else
		{
			int Day = std::stoi(line.substr(0, line.find("/")));
			int Month = std::stoi(line.substr(line.find("/") + 1, line.find_last_of("/")));
			int Year = std::stoi(line.substr(line.find_last_of("/") + 1, line.find(" ")));
			std::string is_Available = line.substr(line.find(" ") + 1);
			if (day == Day && month == Month && year == Year && is_Available == "free" && daysAvailable < daysWanted)
			{
				is_Available = name;
				RoomAvailability ra(Day, Month, Year, is_Available);
				Availability.push_back(ra);
				room_number = roomNumber;
				daysAvailable++;
				day++;
				if (month == 2 && day > 28 && year % 4 == 1)
				{
					day = 1;
					month++;
				}
				else if(month == 2 && day > 29 && year % 4 == 0)
				{
					day = 1;
					month++;
				}
				else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
				{
					day = 1;
					month++;
				}
				else if (day > 31)
				{
					day = 1;
					month++;
				}
			}
			else
			{
				RoomAvailability ra(Day, Month, Year, is_Available);
				Availability.push_back(ra);
			}
		}
	}
	if (daysAvailable != daysWanted)
	{			
		return 0;
	}
	saveToFile(filename,Availability);
	file.close();
	return room_number;
}
std::vector<RoomAvailability>  Room  :: initAvailability(int year)
{
	for (int month = 1; month <= 12; month++)
	{
		int days = getDaysinMonth(month, year);
		for (int day = 1; day <= days; day++)
		{
			RoomAvailability ra(day, month, year, "free");
			availability.push_back(ra);
		}
	}
	return availability;
}
void Room::saveToFile(std::string filename, std::vector<RoomAvailability> RAv )
{
	std::ofstream file;
	file.open(filename);
	if (!file)
	{
		std::cout<<"Error opening file"<<std::endl;
		return;
	}
	file<<"RoomNumber = " << roomNumber << std::endl;
	file<<"RoomType = " << roomType << std::endl;
	for (RoomAvailability ra : RAv)
	{
		
		file<<ra.toString()<<std::endl;
	}
	file.close();
}
void Room::setRoomNumber(int roomNumber)
{
	this->roomNumber = roomNumber;
}
void Room::setRoomType(int roomType)
{
	this->roomType = roomType;
}
void Room::cancelReservation(std::string filename, std::string reservationName)
{
	std::ifstream file;
	file.open(filename);
	if (!file)
	{
		std::cout<<"Error opening file"<<std::endl;
		return;
	}
	std::vector<RoomAvailability> availability;
	std::string line;
	while (std::getline(file, line))
	{
		if (line.find("RoomNumber = ") != std::string::npos)
		{
			roomNumber = std::stoi(line.substr(line.find("=") + 1));
		}
		else if (line.find("RoomType = ") != std::string::npos)
		{
			roomType = std::stoi(line.substr(line.find("=") + 1));
		}
		else
		{
			int Day = std::stoi(line.substr(0, line.find("/")));
			int Month = std::stoi(line.substr(line.find("/") + 1, line.find_last_of("/")));
			int Year = std::stoi(line.substr(line.find_last_of("/") + 1, line.find(" ")));
			std::string is_Available = line.substr(line.find(" ") + 1);
			if ( is_Available == reservationName)
			{
				is_Available = "free";
			}
			RoomAvailability ra(Day, Month, Year, is_Available);
			availability.push_back(ra);
		}
	}	
	saveToFile(filename,availability);
	file.close();

}
void Room::showReservation(std::string filename, std::string reservationName)
{
	std::ifstream file;
	file.open(filename);
	if (!file)
	{
		std::cout<<"Error opening file"<<std::endl;
		return;
	}
	std::string line;
	while (std::getline(file, line))
	{	if(line.find(reservationName) != std::string::npos)
			std::cout<<line<<std::endl;
	}
	file.close();
}