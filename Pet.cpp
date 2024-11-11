#include <iostream>
#include <string>
using namespace std;

class Pet {
private:
    string name;
    string type;
    int age;

public:
    static int totalPets; // Static variable to keep count of Pet objects

    Pet() {} // Default constructor for array initialization

    Pet(string name, string type, int age) {
        totalPets++;
        this->name = name;
        this->type = type;
        this->age = age;
    }

    void getPetDetails() const {
        cout << "Pet Name: " << name << ", Type: " << type << ", Age: " << age << endl;
    }

    int getAge() const { // Getter for age
        return age;
    }

    void updateAge(int newAge) {
        this->age = newAge;
        cout << "Updated Age: " << age << endl;
    }
};

// Initialize static variable
int Pet::totalPets = 0;

class Owner {
private:
    string ownerName;
    string address;

public:
    static int totalOwners; // Static variable to keep count of Owner objects

    Owner() {} // Default constructor for array initialization

    Owner(string ownerName, string address) {
        totalOwners++;
        this->ownerName = ownerName;
        this->address = address;
    }

    void getOwnerDetails() const {
        cout << "Owner Name: " << ownerName << ", Address: " << address << endl;
    }

    void updateAddress(string newAddress) {
        this->address = newAddress;
    }

    string getAddress() const { // Function to retrieve the current address
        return address;
    }
};

// Initialize static variable
int Owner::totalOwners = 0;

int main() {
    // Creating an array of 2 Pet objects using new
    Pet* pets = new Pet[2] {
        Pet("BLACKY", "Dog", 3),
        Pet("DOMI", "Dog", 6)
    };

    // Display pet details and update age for each pet
    for (int i = 0; i < 2; i++) {
        pets[i].getPetDetails();
        pets[i].updateAge(pets[i].getAge() + 1); // Increment age by 1
    }

    // Display total number of pets
    cout << "Total Pets: " << Pet::totalPets << endl;

    // Creating an array of 2 Owner objects using new
    Owner* owners = new Owner[2] {
        Owner("Pranva", "1/270, Main Road"),
        Owner("Rahul", "2/305, Second Street")
    };

    // Display owner details and update address with specific new addresses
    string updatedAddresses[2] = {"1/270, First Street", "2/305, First Street"};
    for (int i = 0; i < 2; i++) {
        owners[i].getOwnerDetails();

        // Update the address with the specific new address and print it immediately
        owners[i].updateAddress(updatedAddresses[i]);
        cout << "Changed Address: " << owners[i].getAddress() << endl;
    }

    // Display total number of owners
    cout << "Total Owners: " << Owner::totalOwners << endl;

    // Deallocate memory
    delete[] pets;
    delete[] owners;

    return 0;
}
