#include <iostream>
#include <string>
using namespace std;

class Pet {
private:
    string name;
    string type;
    int age;

<<<<<<< new_and_delete
public:
    Pet() {} // Default constructor for array initialization

    Pet(string name, string type, int age) {
        this->name = name;
        this->type = type;
        this->age = age;
=======
    public:
    Pet(string n, string t, int a){
        name = n;
        type = t;
        age = a;
>>>>>>> master
    }
    
    void getPetDetails(){
        cout<<"Pet Name: "<< name << ", Type: " << type << ", Age: " << age << endl;
    }

<<<<<<< new_and_delete
    int getAge() const { // Getter for age
        return age;
    }

    void updateAge(int newAge) {
        this->age = newAge;
        cout << "Updated Age: " << age << endl;
=======
    void updateAge(int newAge){
        age = newAge;
        cout<<"Updated Age: " << age << endl;
>>>>>>> master
    }
};

class Owner {
private:
    string ownerName;
    string address;

<<<<<<< new_and_delete
public:
    Owner() {} // Default constructor for array initialization

    Owner(string ownerName, string address) {
        this->ownerName = ownerName;
        this->address = address;
=======
    public:
    Owner(string oName, string addr){
        ownerName = oName;
        address = addr;
>>>>>>> master
    }

    void getOwnerDetails(){
        cout<<"Owner Name: "<< ownerName << ", Address: " << address << endl;
    }

<<<<<<< new_and_delete
    void updateAddress(string newAddress) {
        this->address = newAddress;
    }

    string getAddress() const { // Function to retrieve the current address
        return address;
=======
    void updateAddress(string newAddress){
        address = newAddress;
        cout<<"Updated Address: " << address << endl;
>>>>>>> master
    }
};

int main() {
<<<<<<< new_and_delete
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

    // Deallocate memory
    delete[] pets;
    delete[] owners;
=======
    Pet pet1("BLACKY", "Dog", 3);
    pet1.getPetDetails();  
    pet1.updateAge(4); 

    Pet pet2("DOMI", "Dog", 6);
    pet2.getPetDetails();  
    pet2.updateAge(7); 

    Owner owner1("Pranva", "1/270, Main Road");
    owner1.getOwnerDetails();  
    owner1.updateAddress("1/248, Main Road");    
>>>>>>> master

    return 0;
}
