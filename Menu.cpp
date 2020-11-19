#include <iostream>
using namespace std;

#include "Byte.cpp"
#include "Byte2.cpp"
#include "Reader.cpp"
#include "X86.cpp"


int main() {
    cout << "Hello, World!" << endl;

    // Initialize X86
    printf("Initializing X86 Processor . . .\n");
    X86 proc;
    printf("Processor Ready\n");

    // Show menu and prompt for an option
    int choice = 0;
    while (choice != 4) {

        Byte *input1 = new Byte();
        Byte *input2 = new Byte();

        vector<Byte> ByteArray;

        printf("\nSelect one of the following choices:\n");
        printf("%2s1. Print Registers\n","");
        printf("%2s2. Take User Instruction\n","");
        printf("%2s3. Read & Run from File\n","");
        printf("%2s4. Exit\n","");
        printf("Choose (1-4): ");

        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("\nPrinting Registers . . .\n\n");
                proc.printRegs();

                break;
            case 2:
                printf("\nTaking User Instruction . . .\n");
                
                printf("Enter your instruction's first BYTE (HEX): ");
                *input1 = readInputByte();
                input1->printByte();
                printf("Enter your instruction's second BYTE (HEX): ");
                *input2 = readInputByte();
                input2->printByte();
                //proc.DecodeExecute(*input1, *input2);

                break;
            case 3:
                printf("\nEnter the name of the file to be read (Must be binary!): ");
                
                char file[50];
                scanf("%49s", file);
                // cout << file <<endl;
                printf("Reading & Running from File \"%s\". . .\n", file);
                ByteArray = readFileByteArray(file);
                printf("Done Reading File. . .\n");
                // for (int i = 0; i < ByteArray.size(); i++) 
                //     ByteArray[i].printByte();

                break;
            case 4:
                break;
            default:
                printf("\n\"%d\" is not an valid option. Try Again!\n\n", choice);
                break;
        }
    }

    printf("\nProgram terminated.\nGood Bye :)\n");

    return 0;
}