#include <iostream>
using namespace std;

#include "Byte.cpp"
#include "Byte2.cpp"
#include "Reader.cpp"

class x86 {
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
        x86() {}

        void printRegs();
        void DecodeExecute(Byte, Byte); 
};


void x86::printRegs() {
    printf("GENERAL PURPOSE REGISTERS:\n");
    printf("16 Bit:\t    8 Bit:\n");
    printf("AX: %X\tAH: %X\tAL: %X\n", this->AX->getByte2(), this->AH->getByte(), this->AL->getByte());
    printf("BX: %X\tBH: %X\tBL: %X\n", this->BX->getByte2(), this->BH->getByte(), this->BL->getByte());
    printf("CX: %X\tCH: %X\tCL: %X\n", this->CX->getByte2(), this->CH->getByte(), this->CL->getByte());
    printf("DX: %X\tDH: %X\tDL: %X\n", this->DX->getByte2(), this->DH->getByte(), this->DL->getByte());
    printf("SPECIALIZED REGISTERS:\n");
    printf("SI: %X\tDI: %X\tBP: %X\tSP: %X\n", this->SI->getByte2(), this->DI->getByte2(), this->BP->getByte2(), this->SP->getByte2());
    printf("CS: %X\tDS: %X\tSS: %X\tES: %X\n", this->CS->getByte2(), this->DS->getByte2(), this->SS->getByte2(), this->ES->getByte2());
    printf("IP: %X\n", this->IP->getByte2());
    printf("FLAGS: %X\n", this->FLAGS->getByte2());
    
    printf("\n");
}

void x86::DecodeExecute(Byte input1, Byte input2) {
    unsigned char insth = input1.getByte();
    unsigned char instl = input2.getByte();
    printf("Instruction entered: %X%x\n", insth, instl);


    // Instruction to be exeacuted

}

// int main() {
//     x86 Test;
//     Test.printRegs();
//
//     Byte *input = new Byte;
//     *input = readInputByte();
//     input->printByte();
//
//     //Test.DecodeExecute(*input);
//     return 0;
// }
