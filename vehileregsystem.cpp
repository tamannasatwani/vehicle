#include <iostream>
#include <string>
using namespace std;

// Base Class: Vehicle
class Vehicle {
protected:
    int id;
    string owner;
    string licensePlate;

public:
    Vehicle() : id(0), owner(""), licensePlate("") {} // Default Constructor
    Vehicle(int id, string owner, string licensePlate) 
        : id(id), owner(owner), licensePlate(licensePlate) {} // Parameterized Constructor
    
    virtual void display() const {
        cout << "ID: " << id << ", Owner: " << owner << ", License Plate: " << licensePlate << endl;
    }

    int getId() const { return id; } // Getter for ID

    virtual ~Vehicle() {} // Virtual Destructor
};

// Derived Class 1: Car
class Car : public Vehicle {
private:
    int doors;

public:
    Car() : Vehicle(), doors(0) {} // Default Constructor
    Car(int id, string owner, string licensePlate, int doors) 
        : Vehicle(id, owner, licensePlate), doors(doors) {} // Parameterized Constructor
    
    void display() const override {
        cout << "[Car] ";
        Vehicle::display();
        cout << "Number of Doors: " << doors << endl;
    }
};

// Derived Class 2: Motorcycle
class Motorcycle : public Vehicle {
private:
    string type;

public:
    Motorcycle() : Vehicle(), type("") {} // Default Constructor
    Motorcycle(int id, string owner, string licensePlate, string type) 
        : Vehicle(id, owner, licensePlate), type(type) {} // Parameterized Constructor
    
    void display() const override {
        cout << "[Motorcycle] ";
        Vehicle::display();
        cout << "Type: " << type << endl;
    }
};

// Derived Class 3: Truck
class Truck : public Vehicle {
private:
    float capacity;

public:
    Truck() : Vehicle(), capacity(0.0) {} // Default Constructor
    Truck(int id, string owner, string licensePlate, float capacity) 
        : Vehicle(id, owner, licensePlate), capacity(capacity) {} // Parameterized Constructor
    
    void display() const override {
        cout << "[Truck] ";
        Vehicle::display();
        cout << "Capacity: " << capacity << " tons" << endl;
    }
};

// Main Function: Menu-Driven System
int main() {
    Vehicle* vehicles[100]; // Array of pointers to store different types of vehicles
    int vehicleCount = 0;   // Counter for the number of vehicles

    int choice;

    do {
        cout << "\n=== Vehicle Registry System ===\n";
        cout << "1. Add Vehicle\n";
        cout << "2. View All Vehicles\n";
        cout << "3. Search Vehicle by ID\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int id, doors;
            string owner, licensePlate, type;
            float capacity;

            cout << "\nSelect Vehicle Type:\n";
            cout << "1. Car\n2. Motorcycle\n3. Truck\n";
            cout << "Enter choice: ";
            int typeChoice;
            cin >> typeChoice;

            cout << "Enter Vehicle ID: ";
            cin >> id;
            cin.ignore(); // Clear input buffer
            cout << "Enter Owner Name: ";
            getline(cin, owner);
            cout << "Enter License Plate: ";
            cin >> licensePlate;

            switch (typeChoice) {
                case 1: // Add Car
                    cout << "Enter Number of Doors: ";
                    cin >> doors;
                    vehicles[vehicleCount++] = new Car(id, owner, licensePlate, doors);
                    break;
                case 2: // Add Motorcycle
                    cout << "Enter Motorcycle Type: ";
                    cin >> type;
                    vehicles[vehicleCount++] = new Motorcycle(id, owner, licensePlate, type);
                    break;
                case 3: // Add Truck
                    cout << "Enter Truck Capacity (in tons): ";
                    cin >> capacity;
                    vehicles[vehicleCount++] = new Truck(id, owner, licensePlate, capacity);
                    break;
                default:
                    cout << "Invalid vehicle type!\n";
            }

        } else if (choice == 2) {
            if (vehicleCount == 0) {
                cout << "No vehicles registered.\n";
            } else {
                cout << "\nRegistered Vehicles:\n";
                for (int i = 0; i < vehicleCount; i++) {
                    vehicles[i]->display();
                    cout << endl;
                }
            }

        } else if (choice == 3) {
            int searchId;
            cout << "Enter Vehicle ID to search: ";
            cin >> searchId;

            bool found = false;
            for (int i = 0; i < vehicleCount; i++) {
                if (vehicles[i]->getId() == searchId) {
                    cout << "\nVehicle Found:\n";
                    vehicles[i]->display();
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Vehicle with ID " << searchId << " not found.\n";
            }

        } else if (choice != 4) {
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 4);

    // Clean up dynamically allocated memory
    for (int i = 0; i < vehicleCount; i++) {
        delete vehicles[i];
    }

    cout << "Exiting Vehicle Registry System. Goodbye!\n";
    return 0;
}



