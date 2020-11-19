#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

// #include "Byte.cpp"


Byte readInputByte() {
    unsigned int value;
    scanf("%X", &value);
    Byte temp(value); 
    return temp;
}

vector<Byte> readFileByteArray(string file_name) {
    vector<Byte> storeBytes;

    FILE *file = fopen(file_name.c_str(),"rb");
    unsigned char buffer;

    if(file) {
        while (fread(&buffer, sizeof(buffer), 1, file)) {
            //printf("READ: %X\n",buffer);
            Byte temp(buffer);
            storeBytes.push_back(temp);
        }
        fclose(file);
    }

    return storeBytes;
}

/*int main(){

    // Read Byte from user input:
    cout<<"START"<<endl;
    vector<Byte> ByteArray;
    Byte *test = new Byte;
    *test = readInputByte();
    test->printByte();
    ByteArray.push_back(*test);
    ByteArray[0].printByte();
    cout<<"END"<<endl;
    

    // Read Byte from binary file:
    vector<Byte> ByteArray;
    ByteArray = readFileByteArray("SAMPLE.COM");
    
    for (int i = 0; i < ByteArray.size(); i++) 
        ByteArray[i].printByte();
    

    return 0;
}*/
