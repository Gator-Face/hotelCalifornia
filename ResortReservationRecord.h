#pragma once
#include <string>

using namespace std;

class ResortReservationRecord{
  public:
    ResortReservationRecord();
    ResortReservationRecord(string name, size_t roomType, size_t nights, bool isParking);
    string GetCustomersName();
    void  SetCustomersName(string name);

    size_t GetRoomType();
    void   SetRoomType(size_t roomType);
    
    size_t GetNightsStayed();
    void   SetNightsStayed(size_t nights);

    bool GetParkingNeeded();
    void SetParkingNeeded(bool needed);

    double CalculateCosts();
    string CurrentChoice();

    size_t GetGuests();
    void   SetGuests(size_t guests);

  private:
    string customersName;
    size_t roomType;

    const size_t ROOM_COST [5] = {0, 284, 325, 290, 350};
    const double PARKING_COST = 12.75;

    size_t numNights;
    bool parkingNeeded;

    size_t numGuests;
};
