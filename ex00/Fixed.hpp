#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
        int _fixedPoint;
        static const int _fractionalBit = 8;
    public:
        Fixed();
        ~Fixed();
        Fixed(const Fixed& other); // zaten olan 1 nesnenin kopyasından oluşturulacak.
        Fixed& operator= (const Fixed& other);

        int getRawBits(void) const; //sabit nokta değerinin ham değerini döndürür
        void setRawBits(int const raw); //sabit noktalı sayının ham değerini ayarlar
};

/*
Ortodoks Kanonik Formu genellikle şu özellikleri içerir:

İşaret Biti (Sign Bit): Sayının pozitif mi negatif mi olduğunu belirten bir bit.

Mantissa (Kesirli Kısım): Sayının kesirli kısmını temsil eden bir dizi bit.

Üs (Exponent): Sayının büyüklüğünü belirten bir üs değeri.
*/


#endif
