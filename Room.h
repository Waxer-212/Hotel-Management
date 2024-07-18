#include "RoomAvailability.h"
#include <string>
#include <vector>
#include <fstream>
class Room
{
private:
	int roomNumber;
	int roomType;
	std::vector<RoomAvailability> availability;

public:
	Room();
	Room(int roomNumber, int roomType);
	~Room();
	std::vector<RoomAvailability> initAvailability(int year);
	void saveToFile(std::string filename, std::vector<RoomAvailability> RAv);
	void setRoomNumber(int roomNumber);
	void setRoomType(int roomType);
	int getDaysinMonth(int month, int year);
	int bookRoom(int roomtype,int day, int month, int year, std::string name,std::string filename, int daysWanted);
	void cancelReservation(std::string filename, std::string reservationName);
	void showReservation(std::string filename, std::string reservationName);

};
