#include <iostream>
#include <string>
using namespace std;

class Pet {
    private:
    string name;
    string type;
    int age;

    public:
    Pet(string n, string t, int a){
        name = n;
        type = t;
        age = a;
    }
    
    void getPetDetails(){
        cout<<"Pet Name: "<< name << ", Type: " << type << ", Age: " << age << endl;
    }

    void updateAge(int newAge){
        age = newAge;
        cout<<"Updated Age: " << age << endl;
    }
};

class Owner {
    private:
    string ownerName;
    string address;

    public:
    Owner(string oName, string addr){
        ownerName = oName;
        address = addr;
    }

    void getOwnerDetails(){
        cout<<"Owner Name: "<< ownerName << ", Address: " << address << endl;
    }

    void updateAddress(string newAddress){
        address = newAddress;
        cout<<"Updated Address: " << address << endl;
    }
};

int main() {
    Pet pet1("BLACKY", "Dog", 3);
    pet1.getPetDetails();  
    pet1.updateAge(4); 

    Pet pet2("DOMI", "Dog", 6);
    pet1.getPetDetails();  
    pet1.updateAge(7); 

    Owner owner1("Pranva" "1/270, Main Road");
    owner1.getOwnerDetails();  
    owner1.updateAddress("1/248, Main Road");    

    return 0;
}
