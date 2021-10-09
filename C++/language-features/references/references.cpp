#include <iostream>
using namespace std;

void ref_example(int &ref_int);

int main(){
    // C++'da C'ye ek olarak referanslar tanımlayabiliyoruz.
    // Bu referansları bir alias gibi kullanabiliriz. 
    //Asıl değişken ile aynı bellek bölgesine işaret ederler.
    // Dolayısıyla bir fonksiyona argüman olarak verdiğimizde 
    // işaret ettikleri değişkenin de değişmesini sağlarlar.
    // Fonksiyon parametresini referans olarak tanımladığımızda
    // asıl değişkeni ererek de değişmesini sağlayabiliriz.
    // Arkaplanda referanslar da pointerları kullanır.
    int my_int = 5;
    int &ref_int = my_int;

    cout << "Value of the original variable before call:" << my_int << "\n";
    ref_example(ref_int);
    cout << "Value of the original variable after call:" << my_int << "\n";

    return 0;
}

void ref_example(int &ref_int){
    ref_int = 10;
}