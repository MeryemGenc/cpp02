#include "Fixed.hpp"

Fixed::Fixed() : _fixedPoint(0)
{
    std::cout << "Default constructor called" << std::endl;
}

/*
other parametresinin türü Fixed sınıfının const referansıdır. Bu, bir kopyalama işlemi gerçekleştirileceği anlamına gelir. const anahtar kelimesi, other'ın fonksiyon içinde değiştirilemeyeceğini belirtir, bu nedenle kopyalama işlemi sırasında other'ın durumu değiştirilmez.
*/
Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other; // bu fonksiyon ile obj oluşturulduğunda=> other değişirse bu obj ye ne olur? HAYIR mış. (GPT dedi.)
}

// Bir kopyalama atama operatörünü aşırı yükleme


int Fixed::getRawBits(void) const //sabit nokta değerinin ham değerini döndürür
{
    
    std::cout << "getRawBits member function called" << std::endl;
    return this->_fixedPoint;
}

Fixed& Fixed::operator= (const Fixed& other) // şimdi biz this'in obj adresi olduğunu mu varsayıyoruz yani.
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->_fixedPoint = other.getRawBits();
    return *this;
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->_fixedPoint = raw;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}





/*
    getRawBits fonksiyonu const bir üye fonksiyondur. Bu, fonksiyonun sınıfın içindeki durumu değiştirmeyeceği ve sadece okuma işlemleri için kullanılacağı anlamına gelir. Sınıfın içindeki veriye dokunmayacak olması, bu fonksiyonun sınıfın const nesnelerinde çağrılmasına izin verir.
*/
