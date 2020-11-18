#include <iostream>
using namespace std;

// #include "Byte.cpp"

class Byte2 {
    private:
        Byte *higher;
        Byte *lower;
        unsigned short int value;

    public:
        Byte2();
        Byte2(Byte, Byte);
        Byte2 &operator =(const Byte2 &other);

        Byte getHigher() {return *higher;}
        Byte getLower() {return *lower;}


        friend int Byte2ToDec(Byte2);

        void calcValue();
        unsigned short int getByte2() {return value;}
        void printByte2() {printf("%X\t(%d)\n", getByte2(), Byte2ToDec(*this));}

        void setHigher(Byte h) {
            higher->setByte(h.getByte());
            calcValue();
        }
        void setLower(Byte l) {
            lower->setByte(l.getByte());
            calcValue();
        }

        void setByte2(unsigned short int n) {
            value = n;
            Byte temph(n>>8);
            Byte templ(n & 0x00FF);
        }
};

Byte2::Byte2() {
    higher = new Byte(0x00);
    lower = new Byte(0x00);
    calcValue();
}

Byte2::Byte2(Byte h, Byte l) {
    higher = &h;
    lower = &l;
    calcValue();
}

void Byte2::calcValue() {
    value = (*higher).getByte() * 256 + (*lower).getByte();
}

int Byte2ToDec(Byte2 b) {   
    int dec = (int)b.getByte2();
    return dec;
}


/*int main() {

    Byte hb(0xAB);
    Byte lb(0xCD);
    Byte zb(0xFF);

    Byte2 test(hb, lb);
    test.printByte2();
    test.getHigher().printByte();
    test.getLower().printByte();

    test.setLower(zb);
    test.printByte2();
    test.getHigher().printByte();
    test.getLower().printByte();

    test.setByte2(0b11111111);
    test.printByte2();
    test.getHigher().printByte();
    test.getLower().printByte();
    
    return 0;
}*/