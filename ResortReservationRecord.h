#pragma once
#include <string>

using namespace std;

class ResortReservationRecord{
  public:
    ResortReservationRecord();
    ResortReservationRecord(string name, size_t roomType, size_t nights, bool isParking);

    //
    // Get and Setters for members of class
    //
    string GetCustomersName();
    void  SetCustomersName(string name);

    string GetStartOfStay();
    void  SetStartOfStay(string date);

    size_t GetRoomType();
    void   SetRoomType(size_t roomType);
    
    size_t GetNightsStayed();
    void   SetNightsStayed(size_t nights);

    bool GetParkingNeeded();
    void SetParkingNeeded(bool needed);

    size_t GetGuests();
    void   SetGuests(size_t guests);

    // Calculates Cost before tax
    double CalculateCosts();

    // Gets all members of class in formated string
    string CurrentChoice();

    // Costs of stuff
    // Room key: 0 - nothing, 1 - Queen STD, 2 - Queen Atrium,
    //           3 - King STD, 4 - King Atrium
    const size_t ROOM_COST [5] = {0, 284, 325, 290, 350};
    const double PARKING_COST = 12.75;
    const double RESORT_FEE = 15.00;

  private:
    //
    // Members
    //
    string customersName;
    size_t roomType;

    size_t numNights;
    bool parkingNeeded;

    size_t numGuests;

    string startOfStay;
};
