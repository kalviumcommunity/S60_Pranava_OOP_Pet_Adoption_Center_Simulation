#include <iostream>
#include <string>
using namespace std;

// Abstract class to represent a general person
class Person {
protected:
    string name;  // Name of the person

public:
    // Constructor for Person
    Person(string personName = "Unknown") : name(personName) {}


    // Virtual function to display the person's details
    virtual void displayDetails() const {
        cout << "Name: " << name << endl;

    // Pure virtual function to display person's details
    virtual void displayDetails() const = 0;

    // Virtual destructor for the Person class
    virtual ~Person() {
        cout << "Person destructor called for " << name << endl;

    }

    // Virtual destructor for the Person class
    virtual ~Person() {
        cout << "Person destructor called for " << name << endl;
    }
};

// Separate display class for Owner
class OwnerDisplay {
public:
    static void display(class Owner &owner);
};

// Separate display class for Pet
class PetDisplay {
public:
    static void display(const class Pet &pet);  // Use 'const' reference
};

// Class to represent a Pet with attributes for name, type, and age
class Pet {
private:
    string name;  // Name of the pet
    string type;  // Type of the pet (e.g., Dog, Cat)
    int age;      // Age of the pet

public:
    static int totalPets;  // Static variable to keep count of Pet objects

    // Default constructor
    Pet() : name("Unknown"), type("Unknown"), age(0) {
        totalPets++;
    }

    // Parameterized constructor
    Pet(string petName, string petType, int petAge) : name(petName), type(petType), age(petAge) {
        totalPets++;
    }

    // Destructor
    ~Pet() {
        cout << "Goodbye Pet: " << name << endl;
        totalPets--;
    }



    // Getter function to access the private attribute 'age'
    int getAge() const {
        return age;
   

    // Function to display the details of a pet
    void getPetDetails() const {
        cout << "Pet Name: " << name << ", Type: " << type << ", Age: " << age << endl;
    }

    // Getter functions for private attributes
    string getName() const { return name; }
    string getType() const { return type; }
    int getAge() const { return age; }


    // Function to update the private attribute 'age'
    void updateAge(int newAge) {
        age = newAge;
        cout << "Updated Age: " << age << endl;
    }

    // Static function to display the total number of Pet objects created
    static void displayTotalPets() {
        cout << "Total Pets: " << totalPets << endl;
    }

    // Friend function to display details (SRP compliant)
    friend void PetDisplay::display(const Pet &pet);
};

int Pet::totalPets = 0;

// Derived class to represent a pet owner, inheriting from Person
class Owner : public Person {
private:
    string address;  // Address of the pet owner

public:
    static int totalOwners;  // Static variable to keep count of Owner objects

    // Default constructor
    Owner() : Person(), address("Not Provided") {
        totalOwners++;
    }

    // Parameterized constructor
    Owner(string ownerName, string addr) : Person(ownerName), address(addr) {
        totalOwners++;
    }

    // Destructor
    ~Owner() {
        cout << "Goodbye Owner: " << name << endl;
        totalOwners--;
    }


    

    // Function to display the details of a pet owner
    void getOwnerDetails() const {
        cout << "Owner Name: " << name << ", Address: " << address << endl;
    }


    // Function to update the private attribute 'address'
    void updateAddress(string newAddress) {
        address = newAddress;
    }

    // Getter functions for private attributes
    string getName() const { return name; }
    string getAddress() const { return address; }

    // Static function to display the total number of Owner objects created
    static void displayTotalOwners() {
        cout << "Total Owners: " << totalOwners << endl;
    }

    // Implementation of pure virtual function from Person class
    void displayDetails() const override {
        cout << "Owner Name: " << name << ", Address: " << address << endl;
    }
};

int Owner::totalOwners = 0;


// Separate display function for Pet
void PetDisplay::display(const Pet &pet) {  // Now taking 'const Pet&'
    cout << "Pet Name: " << pet.getName() << ", Type: " << pet.getType() << ", Age: " << pet.getAge() << endl;
}


// Derived class to represent a Trainer, inheriting from Person
class Trainer : public Person {
private:
    string specialty;  // Specialty of the trainer (e.g., dog trainer)


public:
    // Parameterized constructor for Trainer
    Trainer(string trainerName, string trainerSpecialty) : Person(trainerName), specialty(trainerSpecialty) {}

    // Overridden function to display trainer details
    void displayDetails() const override {
        cout << "Trainer Name: " << name << ", Specialty: " << specialty << endl;


public:
    // Parameterized constructor for Trainer
    Trainer(string trainerName, string trainerSpecialty) : Person(trainerName), specialty(trainerSpecialty) {}

    // Function to display trainer details (overrides pure virtual function)
    void displayDetails() const override {
        cout << "Trainer Name: " << name << ", Specialty: " << specialty << endl;
    }

    // Destructor
    ~Trainer() {
        cout << "Trainer destructor called for " << name << endl;
    }
};

int main() {
    // Create individual Owner objects
    Owner owner1("Pranava", "1/270, Main Road");
    Owner owner2("Rahul", "2/305, Second Street");

    // Store them in an array
    Owner owners[2] = { owner1, owner2 };

    // Display owner details and update address with specific new addresses
    string updatedAddresses[2] = {"1/270, First Street", "2/305, First Street"};
    for (int i = 0; i < 2; i++) {
        owners[i].displayDetails();  // Show details of the current owner
        owners[i].updateAddress(updatedAddresses[i]);  // Update the owner's address
        cout << "Changed Address: " << owners[i].getAddress() << endl;  // Print updated address
    }

    // Display total number of owners
    Owner::displayTotalOwners();

    // Create a Trainer object and use polymorphism
    Person* person1 = new Trainer("Nithish", "Dog Trainer");
    person1->displayDetails();  // Polymorphic call to display trainer details

    // Create an array of 2 Pet objects using parameterized constructor
    Pet pets[2] = {
        Pet("BLACKY", "Dog", 3),
        Pet("DOMI", "Dog", 6)
    };

    // Display pet details and update age for each pet
    for (int i = 0; i < 2; i++) {
        PetDisplay::display(pets[i]);  // Show details of the current pet
        pets[i].updateAge(pets[i].getAge() + 1);  // Increment pet's age by 1
    }

    // Destructor
    ~Trainer() {
        cout << "Person destructor called for " << name << endl;
    }
};

int main() {
    // Create an array of 2 Owner objects using parameterized constructor
    Owner owners[2] = {
        Owner("Pranava", "1/270, Main Road"),
        Owner("Rahul", "2/305, Second Street")
    };

    // Display owner details and update address with specific new addresses
    string updatedAddresses[2] = {"1/270, First Street", "2/305, First Street"};
    for (int i = 0; i < 2; i++) {
        owners[i].getOwnerDetails();  // Show details of the current owner
        owners[i].updateAddress(updatedAddresses[i]);  // Update the owner's address
        cout << "Changed Address: " << owners[i].getAddress() << endl;  // Print updated address
    }

    // Display total number of owners
    Owner::displayTotalOwners();

    // Clean up
    delete person1;


    // Create a Trainer object
    Trainer trainer("Nithish", "Dog Trainer");

    // Demonstrating polymorphism: Use the base class pointer to point to a derived class object
    Person* personPtr = &trainer;
    personPtr->displayDetails();  // This will call Trainer's version of displayDetails()

    // Create an array of 2 Pet objects using parameterized constructor
    Pet pets[2] = {
        Pet("BLACKY", "Dog", 3),
        Pet("DOMI", "Dog", 6)
    };

    // Display pet details and update age for each pet
    for (int i = 0; i < 2; i++) {
        pets[i].getPetDetails();  // Show details of the current pet
        pets[i].updateAge(pets[i].getAge() + 1);  // Increment pet's age by 1
    }

    // Display total number of pets
    Pet::displayTotalPets();

    return 0;
}