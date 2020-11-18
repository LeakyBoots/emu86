#include <iostream>
using namespace std;

class Byte {
    private:
        unsigned char hexValue;

    public:
        Byte();
        Byte(unsigned char);
        // Byte &operator =(const Byte &other);

        unsigned char getByte() {return hexValue;}
        void setByte(unsigned char n) {hexValue = n;}

        friend int ByteToDec(Byte);

        void printByte() {printf("%X\t(%d)\n", getByte(), ByteToDec(*this));}

};

Byte::Byte() { hexValue = 0x00;}

Byte::Byte(unsigned char n) { hexValue = n;}

int ByteToDec(Byte b) {   
    int dec = (int)b.getByte();
    return dec;
}

/*int main()
{   
    // Testing Byte Constructor and Print
    // Byte test;
    // Byte test(0x1);
    Byte test(0xF);
    test.printByte();

    // Testing Byte Equalization
    Byte test2 = test;
    test2.printByte();

    // Testing Byte Setting
    test.setByte(0x00);
    test.printByte();
    test2.setByte(0xFF);
    test2.printByte();

    return 0;
}*/