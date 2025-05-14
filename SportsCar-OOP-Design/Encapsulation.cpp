#include <iostream>
#include <string>

using namespace std;

/*
Encapsulation says 2 things:
1. An Object's Characteristics and its behaviour are encapsulated together within that Object.
2. All the characteristics or behaviours are not for everyone to access. Object should provide data security.

We follow the above two principles in programming by:
1. Creating a class that acts as a blueprint for object creation. Class contains all characteristics (variables)
   and behaviours (methods) in one block — encapsulating them together.
2. Using access modifiers (public, private, protected) to provide data security and restrict direct access to class members.
*/

class SportsCar {
private:
    // Encapsulated characteristics (data members)
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;
    int currentGear;
    
    // Private member to demonstrate use of setters and encapsulation
    string tyreCompany;

public:
    // Constructor to initialize the SportsCar object
    SportsCar(string b, string m) {
        this->brand = b;
        this->model = m;
        isEngineOn = false;
        currentSpeed = 0;
        currentGear = 0;
        tyreCompany = "MRF"; // Default tyre company
    }

    // Getter for speed (provides read-only access)
    int getSpeed() {
        return currentSpeed;
    }

    // Getter for tyre company
    string getTyreCompany() {
        return tyreCompany;
    }

    // Setter for tyre company (controlled access to modify private variable)
    void setTyreCompany(string tyreCompany) {
        this->tyreCompany = tyreCompany;
    }

    // Method to start the car's engine
    void startEngine() {
        isEngineOn = true;
        cout << brand << " " << model << " : Engine starts with a roar!" << endl;
    }

    // Method to shift the gear
    void shiftGear(int gear) {
        if (!isEngineOn) {
            cout << brand << " " << model << " : Engine is off! Cannot Shift Gear." << endl;
            return;
        }
        currentGear = gear;
        cout << brand << " " << model << " : Shifted to gear " << currentGear << endl;
    }

    // Method to accelerate the car
    void accelerate() {
        if (!isEngineOn) {
            cout << brand << " " << model << " : Engine is off! Cannot accelerate." << endl;
            return;
        }
        currentSpeed += 20;
        cout << brand << " " << model << " : Accelerating to " << currentSpeed << " km/h" << endl;
    }

    // Method to apply brakes
    void brake() {
        currentSpeed -= 20;
        if (currentSpeed < 0) currentSpeed = 0;
        cout << brand << " " << model << " : Braking! Speed is now " << currentSpeed << " km/h" << endl;
    }

    // Method to stop the engine
    void stopEngine() {
        isEngineOn = false;
        currentGear = 0;
        currentSpeed = 0;
        cout << brand << " " << model << " : Engine turned off." << endl;
    }

    // Destructor
    ~SportsCar() {}
};

// Main Method
int main() {
    // Creating a SportsCar object dynamically
    SportsCar* mySportsCar = new SportsCar("Ferrari", "488");

    // Demonstrating behaviour of the car through method calls
    mySportsCar->startEngine();
    mySportsCar->shiftGear(1);
    mySportsCar->accelerate();
    mySportsCar->shiftGear(2);
    mySportsCar->accelerate();
    mySportsCar->brake();
    mySportsCar->stopEngine();

    /*
    // This would throw an error if uncommented — accessing private member directly
    mySportsCar->currentSpeed = 500;
    cout << "Current Speed of My Sports Car is set to " << mySportsCar->currentSpeed << endl;
    */

    // Using the getter instead (good encapsulation practice)
    cout << "Current Speed of My Sports Car is " << mySportsCar->getSpeed() << " km/h" << endl;

    // Free the dynamically allocated memory
    delete mySportsCar;

    return 0;
}
