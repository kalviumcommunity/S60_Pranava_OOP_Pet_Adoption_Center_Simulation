#include <iostream>
#include <string>
using namespace std;

class Pet {
    private:
    string name;
    string type;
    int age;

    public:
    Pet(string name, string type, int age) {
        this->name = name;
        this->type = type;
        this->age = age;
    }

    void getPetDetails() {
        cout << "Pet Name: " << name << ", Type: " << type << ", Age: " << age << endl;
    }

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
    Owner(string ownerName, string address) {
        this->ownerName = ownerName;
        this->address = address;
    }

    void getOwnerDetails() {
        cout << "Owner Name: " << ownerName << ", Address: " << address << endl;
    }

    void updateAddress(string newAddress) {
        this->address = newAddress;
        cout << "Updated Address: " << address << endl;
    }
};

int main() {
    Pet pets[3] = {
        Pet("Blacky", "Dog" , 3),
        Pet("Snowbell", "Cat", 1),
        Pet("Jimmy", "Dog" , 4),
    };

    for (int i=0; i<3;i++){
        pets[i].getPetDetails();
    };

    Owner owners[3] = {
        Owner("Pranava" , "1/270 Main Road"),
        Owner("Stuart", "4 Gramercy Park West in New York City"),
        Owner("Pranava", "1/270 Main Road"),
    };

    for (int i=0;i<3;i++){
        owners[i].getOwnerDetails();
    };

    return 0;
}