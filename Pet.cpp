#include <iostream>
#include <string>
using namespace std;

class Pet {
private:
    string name;
    string type;
    int age;

public:
    // Default constructor for array initialization
    Pet() {}

    // Parameterized constructor
    Pet(string name, string type, int age) {
        this->name = name;
        this->type = type;
        this->age = age;
    }

    // Getter for pet details
    void getPetDetails() const {
        cout << "Pet Name: " << name << ", Type: " << type << ", Age: " << age << endl;
    }

    // Update age method
    void updateAge(int newAge) {
        this->age = newAge;
        cout << "Updated Age: " << age << endl;
    }
};

class Owner {
private:
    string ownerName;
    string address;

public:
    // Default constructor for array initialization
    Owner() {}

    // Parameterized constructor
    Owner(string ownerName, string address) {
        this->ownerName = ownerName;
        this->address = address;
    }

    // Getter for owner details
    void getOwnerDetails() const {
        cout << "Owner Name: " << ownerName << ", Address: " << address << endl;
    }

    // Update address method
    void updateAddress(string newAddress) {
        this->address = newAddress;
        cout << "Updated Address: " << address << endl;
    }
};

int main() {
    // Dynamically allocated array of 2 Pet objects
    Pet* pets = new Pet[2] {
        Pet("BLACKY", "Dog", 3),
        Pet("DOMI", "Dog", 6)
    };

    // Display pet details and update age for each pet
    for (int i = 0; i < 2; i++) {
        pets[i].getPetDetails();
        pets[i].updateAge(pets[i].getAge() + 1); // Increment age by 1
    }

    // Dynamically allocated array of 2 Owner objects
    Owner* owners = new Owner[2] {
        Owner("Pranva", "1/270, Main Road"),
        Owner("Rahul", "2/305, Second Street")
    };

    // Display owner details and update address with specific new addresses
    string updatedAddresses[2] = {"1/270, First Street", "2/305, First Street"};
    for (int i = 0; i < 2; i++) {
        owners[i].getOwnerDetails();
        owners[i].updateAddress(updatedAddresses[i]);
        cout << "Changed Address: " << owners[i].getAddress() << endl;
    }

    // Deallocate memory for pets and owners
    delete[] pets;
    delete[] owners;

    return 0;
}
