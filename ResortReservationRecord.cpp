#include "ResortReservationRecord.h"
#include <string>
#include <sstream>

using namespace std;


string ResortReservationRecord::GetCustomersName() {
  return customersName;
}

void ResortReservationRecord::SetCustomersName(string name) {
  customersName = name;
}


size_t ResortReservationRecord::GetNightsStayed() {
  return numNights;
}

void ResortReservationRecord::SetNightsStayed(size_t nights) {
  numNights = nights;
}


bool ResortReservationRecord::GetParkingNeeded() {
  return parkingNeeded;
}

void ResortReservationRecord::SetParkingNeeded(bool parking) {
  parkingNeeded = parking;
}


size_t ResortReservationRecord::GetRoomType() {
  return roomType;
}

void ResortReservationRecord::SetRoomType(size_t room) {
  if(room < 5){
    roomType = room;
  }
}

double ResortReservationRecord::CalculateCosts() {
  double total_cost = numNights * ROOM_COST[roomType];
  if (GetParkingNeeded())
    total_cost += numNights * PARKING_COST;

  return total_cost;
}

string ResortReservationRecord::CurrentChoice(){
  stringstream out;
  out << "Customer Name: " << GetCustomersName() << "\nRoom Type: " << GetRoomType() << ", (" << ROOM_COST[GetRoomType()] << ")\nNights Stayed: " << GetNightsStayed() << "\nParking Reserved: ";
  if(GetParkingNeeded())
    out << "Yes";
  else
    out << "No";

  out << "\n Total Cost: " << CalculateCosts() << "\n Thank you";
  return out.str();
}

