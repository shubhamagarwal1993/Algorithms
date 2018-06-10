#include <iostream>
#include <vector>

using namespace std;

enum ParkingType {
    REGULAR,
    HANDICAPPED,
    COMPACT,
    MAX_PARKING_TYPE,
};

enum VehicleType {
    MOTORBIKE,
    CAR,
    BUS
};

class Vehicle {
    private:
        string licensePlate;
        VehicleType vehicleType;

    public:
        Vehicle(VehicleType vehicleType) {
            this->vehicleType = vehicleType;
        }
};

class ParkingSpace {
    private:
        bool isVacant;
        ParkingType parkingType;

    public:
        ParkingSpace(ParkingType parkingType) {
            this->parkingType = parkingType;
        }

        ParkingType getParkingType() { return parkingType; }
};

class ParkingLot {
    private:
        vector<ParkingSpace> vacantParkingSpaces;
        vector<ParkingSpace> fullParkingSpaces;

    public:
        ParkingLot(int capacity) {
            for(int i = 0; i < capacity; i++) {
                ParkingSpace newSpace(COMPACT);
                vacantParkingSpaces.push_back(newSpace);
            }
        }

        ParkingSpace findNearestVacant(ParkingType type) {
            for(int i = 0; i < vacantParkingSpaces.size(); i++) {
                if(vacantParkingSpaces[i].getParkingType() == type) {
                    return vacantParkingSpaces[i];
                }
            }

            // This should return error
            ParkingSpace newSpace(REGULAR);
            return newSpace;
        }
};

int main() {
    return 0;
}
