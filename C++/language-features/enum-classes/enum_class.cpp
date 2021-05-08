#include <iostream>
using namespace std;

// Klasik enumları kullandığımız zaman enumerator isimleri enum ile aynı scope da
// tanımlıdır ve değerleri implicit olarak başka değerlere(örneğin int) dönüşebilir.
// Örneğin iki farklı enumun ilk enumerator değerleri aynı int değerlerini alabilir
// ve farklı şeyler olmalarına rağmen aralarında karşılaştırma yapılabilir. Bu ise
// buglara yol açabilir. Klasik enumların yerine enum classlar kullanmalıyız.

enum Color { black, yellow, red };
enum Animal { cat, dog, bird };
enum class Color2 { black, yellow, red };
enum class Animal2 {cat, dog, bird};

int main(){
    Color color = Color::yellow;
    Animal animal = Animal::dog;

    // Atamaya izin veriliyor, kötü davranış
    int int_var = color;

    // Karşılaştırmaya izin veriyor, kötü davranış
    if(color == animal){
        cout << "Kötü davranış!\n";
    }

    // Enum class kullandığımızda bu davranışlar hata verir
    Color2 color2 = Color2::yellow;
    Animal2 animal2 = Animal2::dog;

    // Hata
    // int_var = color2;

    // Hata
    // if(color2 == animal2)
}