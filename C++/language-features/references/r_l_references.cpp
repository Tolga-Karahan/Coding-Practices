#include <iostream>
using namespace std;

// C++'da rvalue olarak bilinen geçici değerler const & tiplerden ayırt
// edilemediği için C++'a rvalue reference olarak bilinen yeni bir referans
// eklenmiştir. rvalue referanslar typename && şeklinde tanımlanır. rvalue
// isminin kullanılması sebebi bunların atama operatörünün sağında bulunan,
// örneğin bir fonksiyondan dönen, geçici, anonim değerler olmalarıdır.
// Dolayısıyla asıl C++ referansları lvalue referanslarıdır(typename &).
// lvalue referansları isimli değerlere, rvalue referansları isimsiz değerlere
// işaret eder.

void receive(int &value){
    cout << "An int value\n";
}

// rvalue geçici bir değişken içinde tutulur
void receive(int &&value){
    cout << "An int r-value\n";
}

int get_int(){
    return 7;
}

int main(){
    int var = get_int();
    receive(var); // calls function with lvalue ref
    receive(17); // calls function with rvalue ref
    receive(get_int()); // calls function with rvalue ref
    int &&var2 = 5;
    cout << "rvalue:" << var2 << "\n";
    return 0;
}