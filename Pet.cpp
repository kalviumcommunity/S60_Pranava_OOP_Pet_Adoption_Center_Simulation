#include <iostream>
#include <string>
using namespace std;

// Class to represent a Pet with attributes for name, type, and age
class Pet {
private:
    // Private attributes for encapsulation
    string name; // Name of the pet
    string type; // Type of the pet (e.g., Dog, Cat)
    int age;     // Age of the pet

public:
    static int totalPets; // Static variable to keep count of Pet objects

    // Default constructor for array initialization
    Pet() { totalPets++; }

    // Function to set pet details (abstracting direct attribute manipulation)
    void setPetDetails(string petName, string petType, int petAge) {
        name = petName;
        type = petType;
        age = petAge;
    }

    // Getter function to access the private attribute 'age'
    int getAge() const { 
        return age;
    }

    // Function to display the details of a pet
    void getPetDetails() const {
        cout << "Pet Name: " << name << ", Type: " << type << ", Age: " << age << endl;
    }

    // Function to update the private attribute 'age'
    void updateAge(int newAge) {
        age = newAge;
        cout << "Updated Age: " << age << endl;
    }

    // Static function to display the total number of Pet objects created
    static void displayTotalPets() { 
        cout << "Total Pets: " << totalPets << endl;
    }
};

// Initialize static variable
int Pet::totalPets = 0;

// Class to represent an Owner with attributes for name and address
class Owner {
private:
    // Private attributes for encapsulation
    string ownerName; // Name of the owner
    string address;   // Address of the owner

public:
    static int totalOwners; // Static variable to keep count of Owner objects

    // Default constructor for array initialization
    Owner() { totalOwners++; }

    // Function to set owner details (abstracting direct attribute manipulation)
    void setOwnerDetails(string name, string addr) {
        ownerName = name;
        address = addr;
    }

    // Function to display the details of an owner
    void getOwnerDetails() const {
        cout << "Owner Name: " << ownerName << ", Address: " << address << endl;
    }

    // Function to update the private attribute 'address'
    void updateAddress(string newAddress) {
        address = newAddress;
    }

    // Getter function to access the private attribute 'address'
    string getAddress() const {
        return address;
    }

    // Static function to display the total number of Owner objects created
    static void displayTotalOwners() {
        cout << "Total Owners: " << totalOwners << endl;
    }
};

// Initialize static variable
int Owner::totalOwners = 0;

int main() {
    // Create an array of 2 Pet objects and set their details
    Pet pets[2];
    pets[0].setPetDetails("BLACKY", "Dog", 3);
    pets[1].setPetDetails("DOMI", "Dog", 6);

    // Display pet details and update age for each pet
    for (int i = 0; i < 2; i++) {
        pets[i].getPetDetails(); // Show details of the current pet
        pets[i].updateAge(pets[i].getAge() + 1); // Increment pet's age by 1
    }

    // Display total number of pets
    Pet::displayTotalPets();

    // Create an array of 2 Owner objects and set their details
    Owner owners[2];
    owners[0].setOwnerDetails("Pranva", "1/270, Main Road");
    owners[1].setOwnerDetails("Rahul", "2/305, Second Street");

    // Display owner details and update address with specific new addresses
    string updatedAddresses[2] = {"1/270, First Street", "2/305, First Street"};
    for (int i = 0; i < 2; i++) {
        owners[i].getOwnerDetails(); // Show details of the current owner
        owners[i].updateAddress(updatedAddresses[i]); // Update the owner's address
        cout << "Changed Address: " << owners[i].getAddress() << endl; // Print updated address
    }

    // Display total number of owners
    Owner::displayTotalOwners();

    return 0;
}