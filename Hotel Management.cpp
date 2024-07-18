#include <iostream>
#include "Room.h"

int firstRoom = 101;
int lastRoom = 104;

void generateInitialFile(const std::string& filename, int roomNumber, int roomType, int year) {
    Room room(roomNumber, roomType);
    std::vector<RoomAvailability> RAv = room.initAvailability(year);
    std::string str = filename + std::to_string(roomNumber % 100) + ".txt";
    room.saveToFile(str, RAv);
}
void bookRoom(const std::string& filename, int roomType, int day, int month, int year, const std::string name, int daysWanted) {
    Room room;
    int roomnumber = 0;
    for (int i = firstRoom; i <= lastRoom; i++) {

        std::string str = filename + std::to_string(i % 100) + ".txt";
        roomnumber = room.bookRoom(roomType, day, month, year, name, str,daysWanted);

        if (roomnumber != 0) {
            std::cout << "Room " << roomnumber << " booked successfully" << std::endl;
            return;
        }
    }
    std::cout << "No room available" << std::endl;
}
void cancelReservation(std::string filename, int roomNumber,std::string reservationName)
{
	Room room;
    filename = filename + std::to_string(roomNumber % 100) + ".txt";
	room.cancelReservation(filename, reservationName);
}
void showReservation(std::string filename, int roomNumber, std::string reservationName)
{
	Room room;
	filename = filename + std::to_string(roomNumber % 100) + ".txt";
	room.showReservation(filename, reservationName);
}

int menu()
{
	int choice;
	std::cout << "1. Book a room" << std::endl;
	std::cout << "2. Cancel a reservation" << std::endl;
	std::cout << "3. Show reservation" << std::endl;
	std::cout << "4. Exit" << std::endl;
	std::cin >> choice;
	return choice;
}


int main()
{
    Room room;
    std::string filename = "Room";
    /*generateInitialFile(filename, 101, 2, 2021);
    generateInitialFile(filename, 102, 2, 2021);
    generateInitialFile(filename, 103, 2, 2021);
    generateInitialFile(filename, 104, 2, 2021);
   */

    int choice = menu();
    
    while (choice < 4)
    {
        if (choice == 1)
        {
			int roomType;
			int day;
			int month;
			int year;
			std::string name;
			int daysWanted;
			std::cout << "Enter room type: ";
			std::cin >> roomType;
			std::cout << "Enter day: ";
			std::cin >> day;
			std::cout << "Enter month: ";
			std::cin >> month;
			std::cout << "Enter year: ";
			std::cin >> year;
			std::cout << "Enter name: ";
			std::cin >> name;
			std::cout << "Enter days wanted: ";
			std::cin >> daysWanted;
			bookRoom(filename, roomType, day, month, year, name, daysWanted);
		}
        else if (choice == 2)
        {
			int roomNumber;
			std::string reservationName;
			std::cout << "Enter room number: ";
			std::cin >> roomNumber;
			std::cout << "Enter reservation name: ";
			std::cin >> reservationName;
			cancelReservation(filename, roomNumber, reservationName);
		}
		else if (choice == 3)
		{
			int roomNumber;
			std::string reservationName;
			std::cout << "Enter room number: ";
			std::cin >> roomNumber;
			std::cout << "Enter reservation name: ";
			std::cin >> reservationName;
			showReservation(filename, roomNumber, reservationName);
		}
		choice = menu();
    }

    return 0;
}

