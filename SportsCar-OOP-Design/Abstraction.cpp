git#include <iostream>
#include <string>

using namespace std;

// Abstract Base Class representing a generic Car
class Car {
public:
    // Pure virtual functions (must be implemented by derived classes)
    virtual void startEngine() = 0;
    virtual void shiftGear(int gear) = 0;
    virtual void accelerate() = 0;
    virtual void brake() = 0;
    virtual void stopEngine() = 0;

    // Virtual destructor to ensure proper cleanup of derived class objects
    virtual ~Car() {}
};

// Derived class representing a specific type of car: SportsCar
class SportsCar : public Car {
public:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;
    int currentGear;

    // Constructor to initialize the car with a brand and model
    SportsCar(string b, string m) {
        brand = b;
        model = m;
        isEngineOn = false;
        currentSpeed = 0;
        currentGear = 0;
    }

    // Start the car's engine
    void startEngine() override {
        isEngineOn = true;
        cout << brand << " " << model << ": Engine starts with a roar!" << endl;
    }

    // Shift to a specific gear
    void shiftGear(int gear) override {
        if (!isEngineOn) {
            cout << brand << " " << model << ": Engine is off. Cannot shift gear." << endl;
            return;
        }
        currentGear = gear;
        cout << brand << " " << model << ": Shifted to gear " << currentGear << endl;
    }

    // Increase the car's speed
    void accelerate() override {
        if (!isEngineOn) {
            cout << brand << " " << model << ": Engine is off. Cannot accelerate." << endl;
            return;
        }
        currentSpeed += 20;  // Increase speed by 20 km/h
        cout << brand << " " << model << ": Accelerating. Current speed is " << currentSpeed << " km/h" << endl;
    }

    // Apply brakes to slow down
    void brake() override {
        currentSpeed -= 20;  // Decrease speed by 20 km/h
        if (currentSpeed < 0) currentSpeed = 0;  // Ensure speed doesn't go negative
        cout << brand << " " << model << ": Braking. Current speed is " << currentSpeed << " km/h" << endl;
    }

    // Stop the engine and reset speed and gear
    void stopEngine() override {
        isEngineOn = false;
        currentSpeed = 0;
        currentGear = 0;
        cout << brand << " " << model << ": Engine stopped. Current speed is " << currentSpeed << " km/h" << endl;
    }
};

int main() {
    // Create a SportsCar object using a Car pointer (demonstrates polymorphism)
    Car* myCar = new SportsCar("Ferrari", "488");

    // Call car functions in sequence to simulate driving
    myCar->startEngine();      // Start the engine
    myCar->shiftGear(1);       // Shift to 1st gear
    myCar->accelerate();       // Accelerate
    myCar->shiftGear(2);       // Shift to 2nd gear
    myCar->accelerate();       // Accelerate again
    myCar->brake();            // Apply brakes
    myCar->stopEngine();       // Stop the engine

    // Clean up memory
    delete myCar;

    return 0;
}
