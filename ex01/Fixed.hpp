#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath> // roundf()

class Fixed
{
    private:
        int _fixedPoint;
        static const int _fractionalBit = 8;
    public:
        Fixed();
        Fixed(const int i);
        Fixed(const float f);
        Fixed(const Fixed& other); // zaten olan 1 nesnenin kopyasından oluşturulacak.
        ~Fixed();

        int getRawBits(void) const; //sabit nokta değerinin ham değerini döndürür
        void setRawBits(int const raw); //sabit noktalı sayının ham değerini ayarlar

        float toFloat( void ) const; // sabit noktalı değeri kayan noktalı bir değere dönüştürür.
        int toInt( void ) const; // Sabit nokta değerini bir tamsayı değerine dönüştüren 

        // operators overloading -> rhs: right-hand-side
        bool    operator>(const Fixed &rhs) const;
        bool    operator<(const Fixed &rhs) const;
        bool    operator>=(const Fixed &rhs) const;
        bool    operator<=(const Fixed &rhs) const;
        bool    operator==(const Fixed &rhs) const;
        bool    operator!=(const Fixed &rhs) const;

        Fixed   operator+(const Fixed &rhs) const;
        Fixed   operator-(const Fixed &rhs) const;
        Fixed   operator*(const Fixed &rhs) const;
        Fixed   operator/(const Fixed &rhs) const;

        Fixed   operator++(int);
        Fixed   operator--(int);
        Fixed&  operator++(void);
        Fixed&  operator--(void);
        Fixed&  operator= (const Fixed& rhs);

        static Fixed&   min(Fixed &a, Fixed &b);
        static Fixed&   max(Fixed &a, Fixed &b);
        static Fixed const&   min(Fixed const &a, Fixed const &b);
        static Fixed const&   max(Fixed const &a, Fixed const &b);
};

std::ostream& operator<<(std::ostream &out, Fixed const &n); 

/*
std::ostream sınıfı ve çıkış akışı nasıl çalışır?
ChatGPT
std::ostream sınıfı, C++'ta çıkış işlemleri için kullanılan temel bir sınıftır. Bu sınıf, standart çıkış akışını temsil eder ve ostream sınıfının örnekleri, verileri standart çıkışa yazmak için kullanılır.

C++ dilinde çıkış akışı, genellikle std::cout gibi nesnelerle temsil edilir. Bu nesneler, ostream sınıfından türetilir ve çeşitli aşırı yüklenmiş operatörlerle kullanılarak veri çıkışı sağlanır.

std::ostream sınıfının temel özellikleri şunlardır:

<< Operatörü:
<< operatörü, verileri std::ostream sınıfına yazmak için kullanılır. Bu operatör aşırı yüklenmiştir ve farklı veri türleri için uygun şekilde davranır. Örneğin, std::cout << "Hello, World!" ifadesinde << operatörü, bir const char* türünden yazıyı std::ostream sınıfına ekler.

cpp
Copy code
std::cout << "Hello, World!";
Formatlama:
std::ostream sınıfı, çeşitli manipülatörleri (std::endl, std::setw, vb.) kullanarak çıkışı biçimlendirmek için olanak sağlar. Manipülatörler, çıkış akışını kontrol etmek ve biçimlendirmek için kullanılır.

cpp
Copy code
std::cout << std::setw(10) << std::left << "Name:" << "John" << std::endl;
Çeşitli Veri Türleri:
std::ostream sınıfı, bir dizi aşırı yüklenmiş operatör kullanarak çeşitli veri türlerini destekler. Bu sayede, farklı veri türlerini kolayca çıkış akışına ekleyebilirsiniz.

cpp
Copy code
int number = 42;
double pi = 3.14;
std::cout << "Number: " << number << ", Pi: " << pi << std::endl;
Bu özellikler sayesinde std::ostream sınıfı, kullanıcıların çıkış akışını yönetmelerine ve çeşitli veri türlerini düzenli bir şekilde çıkarmalarına olanak tanır.
*/


#endif
/*
std::ostream C++ dilinde standart çıkış akışını temsil eden bir sınıftır. operator<< fonksiyonu genellikle bu sınıfın nesneleri üzerinde aşırı yüklenir ve bir nesneyi standart çıkışa yazdırmak için kullanılır.

Yani, std::ostream& operator<<(std::ostream &o, Fixed const &rhs); fonksiyonu, Fixed sınıfının bir nesnesini bir çıkış akışına (std::ostream) yazdırmak için aşırı yüklenmiş bir operatördür. Bu, nesnenin içeriğini standart çıkışa yazdırmak için kullanılır. Örneğin:

cpp
Copy code
Fixed myFixed(42.42);
std::cout << myFixed;
Bu durumda, operator<< fonksiyonu, myFixed nesnesinin içeriğini standart çıkışa (std::cout) yazdıracaktır.
*/





//Sabit noktalı sayının kayan noktalı gösterimini parametre olarak iletilen çıkış akışı nesnesine ekleyen ekleme («) operatörünün aşırı yüklenmesi.
 

/*
Ortodoks Kanonik Formu genellikle şu özellikleri içerir:

İşaret Biti (Sign Bit): Sayının pozitif mi negatif mi olduğunu belirten bir bit.

Mantissa (Kesirli Kısım): Sayının kesirli kısmını temsil eden bir dizi bit.

Üs (Exponent): Sayının büyüklüğünü belirten bir üs değeri.
*/


