#include "Fixed.hpp"

Fixed::Fixed() : _fixedPoint(0)
{
    std::cout << "Default constructor called" << std::endl;
}

// 8 bit kaydırıyoruz çünkü o 8 bitlik yerde ondalıklı sayı tutulacak.
Fixed::Fixed(const int i) : _fixedPoint(i << _fractionalBit) // karşılık gelen sabit nokta değerine dönüştürür. Neden 8 bit sola kaydırdık??
{
    std::cout << "Integer constructor called" << std::endl;
}

// float değeri 8 bit sola kaydırıp, tam kısım+ondalık kısmın 8 bitlik değerini integer değişkende tutuyoruz.
Fixed::Fixed(const float f) : _fixedPoint(roundf(f * (1 << _fractionalBit))) //(n*(1 << _fractionalBits))->yerine->(n<< _fractionalBits) DENE // karşılık gelen sabit nokta değerine dönüştürür.
{
    std::cout << "Float constructor called" << std::endl;
}

/*
other parametresinin türü Fixed sınıfının const referansıdır. Bu, bir kopyalama işlemi gerçekleştirileceği anlamına gelir. const anahtar kelimesi, other'ın fonksiyon içinde değiştirilemeyeceğini belirtir, bu nedenle kopyalama işlemi sırasında other'ın durumu değiştirilmez.
*/
Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other; // bu fonksiyon ile obj oluşturulduğunda=> other değişirse bu obj ye ne olur? HAYIR mış. (GPT dedi.)
}

int Fixed::toInt( void ) const
{
    return (_fixedPoint >> _fractionalBit);
}

// örn: 1.23 => 256 olarak tutmuştuk. => bu işlem sonrası => 1.2265625 return ediyoruz. Yani biraz kayıp var. o kadar olur.
float Fixed::toFloat( void ) const
{
    return ((float)_fixedPoint / (1 << _fractionalBit));
}

Fixed& Fixed::operator= (const Fixed& rhs) // şimdi biz this'in obj adresi olduğunu mu varsayıyoruz yani.
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
        this->_fixedPoint = rhs.getRawBits();
    return *this;
}

// Bir kopyalama atama operatörünü aşırı yükleme
std::ostream& operator<< (std::ostream &out, Fixed const &n) // bunu bi anla - açıkla yaa
{
    out << n.toFloat();
    return out;
}


int Fixed::getRawBits(void) const //sabit nokta değerinin ham değerini döndürür
{
    
    std::cout << "getRawBits member function called" << std::endl;
    return this->_fixedPoint;
}
/*
    getRawBits fonksiyonu const bir üye fonksiyondur. Bu, fonksiyonun sınıfın içindeki durumu değiştirmeyeceği ve sadece okuma işlemleri için kullanılacağı anlamına gelir. Sınıfın içindeki veriye dokunmayacak olması, bu fonksiyonun sınıfın const nesnelerinde çağrılmasına izin verir.
*/

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->_fixedPoint = raw;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}



bool    Fixed::operator>(const Fixed &rhs) const
{
    return (_fixedPoint > rhs.getRawBits());
}

bool    Fixed::operator<(const Fixed &rhs) const
{
    return (_fixedPoint < rhs.getRawBits());
}

bool    Fixed::operator>=(const Fixed &rhs) const
{
    return (_fixedPoint >= rhs.getRawBits());
}

bool    Fixed::operator<=(const Fixed &rhs) const
{
    return (_fixedPoint <= rhs.getRawBits());
}

bool    Fixed::operator==(const Fixed &rhs) const
{
    return (_fixedPoint == rhs.getRawBits());
}

bool    Fixed::operator!=(const Fixed &rhs) const
{
    return (_fixedPoint != rhs.getRawBits());
}

Fixed    Fixed::operator+(const Fixed &rhs) const
{
    return (Fixed(toFloat() + rhs.toFloat()));
}

Fixed    Fixed::operator-(const Fixed &rhs) const
{
    return (Fixed(toFloat() - rhs.toFloat()));
}

Fixed    Fixed::operator*(const Fixed &rhs) const
{
    return (Fixed(toFloat() * rhs.toFloat()));
}

Fixed    Fixed::operator/(const Fixed &rhs) const
{
    return (Fixed(toFloat() / rhs.toFloat()));
}

Fixed&  Fixed::operator++(void) // void: prefix
{
    _fixedPoint++;
    return (*this);
}

Fixed&  Fixed::operator--(void) // void: prefix
{
    _fixedPoint--;
    return (*this);
}

//Bu, postfix (a++ gibi) ++ operatörünün aşırı yüklenmiş bir versiyonudur. Bu işlev, sabit noktalı sayıyı artırır, ancak artırılmadan önceki değeri döndürür.
Fixed   Fixed::operator++(int) // int: postfix
{
    Fixed tmp(*this);
    operator++();
    return tmp;
}
/*Bu aşırı yüklemelerdeki int parametresi sadece sentaks kurallarını yerine getirmek içindir ve aslında kullanıcı tarafından belirli bir değer almaz veya kullanmaz. Programcı, bu parametreyi kendi uygulamalarında kullanmak zorunda değildir; ancak, dilin gereksinimlerini yerine getirmek için eklenmiştir.*/
Fixed   Fixed::operator--(int) // int: postfix
{
    Fixed tmp(*this);
    operator--();
    return tmp;
}

Fixed& min(Fixed &x, Fixed &y)
{
    return (x > y ? y: x); // "ternary conditional operator" => kısa if.
}

Fixed& max(Fixed &x, Fixed &y)
{
    return (x < y ? y: x);
}

const Fixed& min(const Fixed &x, const Fixed &y)
{
    return (x > y ? y: x);
}

const Fixed& min(const Fixed &x, const Fixed &y)
{
    return (x < y ? y: x);
}

/*
bool    Fixed::operator<(const Fixed &rhs) "const"

Bu kodda const ifadesi, operator< fonksiyonunun sınıfın durumunu değiştirmeyeceğini belirtir. Yani, bu fonksiyonun içinde _fixedPoint veya başka herhangi bir sınıf üyesini değiştirmeyeceğimizi ifade eder. Bu tür fonksiyonlar "const üye fonksiyonlar" olarak adlandırılır.

Bir üye fonksiyonun const olarak işaretlenmesi, bu fonksiyonun sınıfın const nesneleri üzerinde çağrılabileceği anlamına gelir. Eğer const olmasaydı, bu fonksiyon sadece const olmayan nesneler üzerinde çağrılabilirdi.

sondaki const u silersek => hata.
*/
