#include <iostream>
#include <string.h>
using namespace std;

struct Person{
    private:
        char name[80];
        char address[250];
    public:
        void set_name(char const *name_param);
        void set_address(char const *addres_param);
        void print();
};

void Person::set_name(char const *name_param){
            strncpy(name, name_param, 79);
            name[79] = 0;
}

void Person::set_address(char const *address_param){
            strncpy(address, address_param, 250);
            name[250] = 0;
}

void Person::print(){
    cout << "Name: " << name << "\n";
    cout << "Address: " << address << "\n";
}

int main(){
    Person p1;
    p1.set_name("Tolga Karahan");
    p1.set_address("World");
    p1.print();

    return 0;
}