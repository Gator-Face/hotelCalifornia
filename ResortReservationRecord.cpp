#include "ResortReservationRecord.h"
#include <string>
#include <sstream>

using namespace std;

ResortReservationRecord::ResortReservationRecord(){
    roomType = 0;
    numNights = 1;
    numGuests = 1;
}

string ResortReservationRecord::GetCustomersName() {
  return customersName;
}

void ResortReservationRecord::SetCustomersName(string name) {
  customersName = name;
}

string ResortReservationRecord::GetStartOfStay() {
  return startOfStay;
}

void ResortReservationRecord::SetStartOfStay(string date) {
  startOfStay = date;
}

size_t ResortReservationRecord::GetNightsStayed() {
  return numNights;
}

void ResortReservationRecord::SetNightsStayed(size_t nights) {
  numNights = nights;
}

size_t ResortReservationRecord::GetGuests() {
    // Limits number of guests, King - 3, Queen - 4
    if((roomType == 1 || roomType == 2) && numGuests > 4){
        numGuests = 4;
    }else if(numGuests > 3){
        numGuests = 3;
    }

    return numGuests;
}

void ResortReservationRecord::SetGuests(size_t guests) {
    numGuests = guests;
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

