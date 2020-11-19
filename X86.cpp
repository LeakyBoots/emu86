#include <iostream>
#include <bitset>
using namespace std;

// #include "Byte.cpp"
// #include "Byte2.cpp"
// #include "Reader.cpp"

class X86 {
    private:
        // General Purpose Registers
        Byte *AH = new Byte;
        Byte *AL = new Byte;
        Byte *BH = new Byte;
        Byte *BL = new Byte;
        Byte *CH = new Byte;
        Byte *CL = new Byte;
        Byte *DH = new Byte;
        Byte *DL = new Byte;
        
        Byte2 *AX = new Byte2(*AH, *AL);
        Byte2 *BX = new Byte2(*BH, *BL);
        Byte2 *CX = new Byte2(*CH, *CL);
        Byte2 *DX = new Byte2(*DH, *DL);

        Byte2 *SI = new Byte2();
        Byte2 *DI = new Byte2();
        Byte2 *BP = new Byte2();
        Byte2 *SP = new Byte2();

        // Specialized Registers
        Byte2 *IP = new Byte2();
        Byte2 *FLAGS = new Byte2();
        Byte2 *CS = new Byte2();
        Byte2 *DS = new Byte2();
        Byte2 *SS = new Byte2();
        Byte2 *ES = new Byte2();

    public:
        X86() {}

        void printRegs();
        void DecodeExecute(Byte, Byte);

        Byte getAH() {return *AH;}        
        Byte getAL() {return *AL;}
        Byte getBH() {return *BH;}
        Byte getBL() {return *BL;}
        Byte getCH() {return *CH;}
        Byte getCL() {return *CL;}
        Byte getDH() {return *DH;}
        Byte getDL() {return *DL;}

        Byte2 getAX() {return *AX;}
        Byte2 getBX() {return *BX;}
        Byte2 getCX() {return *CX;}
        Byte2 getDX() {return *DX;}

        Byte2 getSI() {return *SI;}
        Byte2 getDI() {return *DI;}
        Byte2 getBP() {return *BP;}
        Byte2 getSP() {return *SP;}

        Byte2 getIP() {return *IP;}
        Byte2 getFLAGS() {return *FLAGS;}
        Byte2 getCS() {return *CS;}
        Byte2 getDS() {return *DS;}
        Byte2 getSS() {return *SS;}
        Byte2 getES() {return *ES;}

        void setAH(unsigned char n) {
            AH->setByte(n);
            AX->setHigher(n);
        }        
        void setAL(unsigned char n) {
            AL->setByte(n);
            AX->setLower(n);
        }
        void setBH(unsigned char n) {
            BH->setByte(n);
            BX->setHigher(n);    
        }
        void setBL(unsigned char n) {
            BL->setByte(n);
            BX->setLower(n);    
        }
        void setCH(unsigned char n) {
            CH->setByte(n);
            CX->setHigher(n);    
        }
        void setCL(unsigned char n) {
            CL->setByte(n);
            CX->setLower(n);    
        }
        void setDH(unsigned char n) {
            DH->setByte(n);
            DX->setHigher(n);    
        }
        void setDL(unsigned char n) {
            DL->setByte(n);
            DX->setLower(n);    
        }

        void setAX(unsigned short int n) {
            AX->setByte2(n);
            AH->setByte(n >> 8);
            AL->setByte(n & 0x00FF);
        }
        void setBX(unsigned short int n) {
            BX->setByte2(n);
            BH->setByte(n >> 8);
            BL->setByte(n & 0x00FF);
        }
        void setCX(unsigned short int n) {
            CX->setByte2(n);
            CH->setByte(n >> 8);
            CL->setByte(n & 0x00FF);
        }
        void setDX(unsigned short int n) {
            DX->setByte2(n);
            DH->setByte(n >> 8);
            DL->setByte(n & 0x00FF);
        }

        void setSI(unsigned short int n) {SI->setByte2(n);}
        void setDI(unsigned short int n) {DI->setByte2(n);}
        void setBP(unsigned short int n) {BP->setByte2(n);}
        void setSP(unsigned short int n) {SP->setByte2(n);}

        void setIP(unsigned short int n) {IP->setByte2(n);}
        void setFLAGS(unsigned short int n) {FLAGS->setByte2(n);}
        void setCS(unsigned short int n) {CS->setByte2(n);}
        void setDS(unsigned short int n) {DS->setByte2(n);}
        void setSS(unsigned short int n) {SS->setByte2(n);}
        void setES(unsigned short int n) {ES->setByte2(n);}


};


void X86::printRegs() {
    printf("GENERAL PURPOSE REGISTERS:\n");
    printf("16 Bit:\t    8 Bit:\n");
    printf("AX: %04X    AH: %02X\tAL: %02X\n", this->AX->getByte2(), this->AH->getByte(), this->AL->getByte());
    printf("BX: %04X    BH: %02X\tBL: %02X\n", this->BX->getByte2(), this->BH->getByte(), this->BL->getByte());
    printf("CX: %04X    CH: %02X\tCL: %02X\n", this->CX->getByte2(), this->CH->getByte(), this->CL->getByte());
    printf("DX: %04X    DH: %02X\tDL: %02X\n", this->DX->getByte2(), this->DH->getByte(), this->DL->getByte());
    printf("SPECIALIZED REGISTERS:\n");
    printf("SI: %04X    DI: %04X    BP: %04X    SP: %04X\n", this->SI->getByte2(), this->DI->getByte2(), this->BP->getByte2(), this->SP->getByte2());
    printf("CS: %04X    DS: %04X    SS: %04X    ES: %04X\n", this->CS->getByte2(), this->DS->getByte2(), this->SS->getByte2(), this->ES->getByte2());
    printf("IP: %04X\n", this->IP->getByte2());
    // printf("FLAGS: %X\n", this->FLAGS->getByte2());
    cout << "FLAGS: " << bitset<16>(this->FLAGS->getByte2())  << endl;
    // printf("\n");
}

// void X86::DecodeExecute(Byte input1, Byte input2) {
//     unsigned char insth = input1.getByte();
//     unsigned char instl = input2.getByte();
//     printf("Instruction entered: %X%x\n", insth, instl);


//     // Instruction to be exeacuted

// }

// int main() {
//     X86 Test;
//     Test.printRegs();
//
//     Byte *input = new Byte;
//     *input = readInputByte();
//     input->printByte();
//
//     //Test.DecodeExecute(*input);
//     return 0;
// }
