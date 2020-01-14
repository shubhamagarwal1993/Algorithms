/*
    Simple API for controlling different types of robots
    Types of robots:
      - drone
      - animal
      - car
      - bounce
*/

#include <iostream>
#include <tuple>
#include <vector>
#include <map>

using namespace std;

class Heartbeat {
    public:
        virtual bool isAlive() const = 0;
};

class Voice {
    private:

    protected:
        string voice_str;

    public:
        Voice(string voice_str) {
            this->voice_str = voice_str;
        }

        virtual string getVoiceStr() const {
            return voice_str;
        }
        void setVoiceStr(string voice_str) {
            this->voice_str = voice_str;
        }
};

class Robot {
    private:

    protected:
        string name;

    public:

        // constructor with default values for data members
        Robot(string name) {
            this->name = name;
        }

        virtual string getRobotName() {
            return name;
        }

        // Robot location
        virtual tuple<int, int> getLocation() {
            return make_pair(-1, -2);
        }
};

class Drone : public Robot, public Voice, public Heartbeat {
    private:
    public:
        Drone(string name, string voice) : Robot(name), Voice(voice) {
        }

        bool isAlive() const {
            return true;
        }
};

class Animal: public Robot, public Voice {
    private:
    public:
        Animal(string name, string voice) : Robot(name), Voice(voice) {
        }

        virtual bool isAlive() {
            return true;
        }
};

class Car: public Robot, public Voice {
    private:
    public:
        Car(string name, string voice) : Robot(name), Voice(voice) {
        }

        virtual bool isAlive() {
            return true;
        }
};

class Bounce: public Robot, public Voice {
    private:
    public:
        Bounce(string name, string voice) : Robot(name), Voice(voice) {
        }

        virtual bool isAlive() {
            return true;
        }
};

int main() {

    std::map<std::string, vector<Robot>> robots;
    vector<Robot> drone_vec;
    vector<Robot> animal_vec;
    vector<Robot> car_vec;
    vector<Robot> bounce_vec;

    // Construct Robot instance in difference ways
    Drone* drone1 = new Drone("I am drone 1", "male");
    cout << drone1->getRobotName() << endl;
    cout << drone1->getVoiceStr() << endl;
    tuple<int, int> drone1_location = drone1->getLocation();
    cout << get<0>(drone1_location) << ", " << get<1>(drone1_location) << endl << endl;
    drone_vec.push_back(*drone1);
    robots["DRONE"] = drone_vec;

    Animal animal1 = Animal("I am animal 1", "female");
    cout << animal1.getRobotName() << endl;
    cout << animal1.getVoiceStr() << endl;
    tuple<int, int> animal1_location = animal1.getLocation();
    cout << get<0>(animal1_location) << ", " << get<1>(animal1_location) << endl << endl;
    animal_vec.push_back(animal1);
    robots["ANIMAL"] = animal_vec;

    Car car1 = Car("I am car 1", "female");
    cout << car1.getRobotName() << endl;
    cout << car1.getVoiceStr() << endl;
    tuple<int, int> car1_location = car1.getLocation();
    cout << get<0>(car1_location) << ", " << get<1>(car1_location) << endl << endl;
    car_vec.push_back(car1);
    robots["CAR"] = car_vec;

    Bounce bounce1 = Bounce("I am bounce 1", "male");
    cout << bounce1.getRobotName() << endl;
    cout << bounce1.getVoiceStr() << endl;
    tuple<int, int> bounce1_location = bounce1.getLocation();
    cout << get<0>(bounce1_location) << ", " << get<1>(bounce1_location) << endl << endl;
    bounce_vec.push_back(bounce1);
    robots["BOUNCE"] = bounce_vec;

    // Print all robot names
    for(auto& x : robots) {
        std::cout << x.first << endl;

        vector<Robot> vec = x.second;
        cout << "    ";
        for(int i = 0; i < vec.size(); i++) {
            cout << vec[i].getRobotName();
        }
        cout << endl;
    }

    // Delete Drone to clear memo
    delete drone1;

    return 0;
}

