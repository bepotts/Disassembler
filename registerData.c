#include "registerData.h"
#include <string.h>
#include <stdlib.h>

#define TOTALAMOUNTOFREGISTERS 32
#define REGISTERBITSIZE 5
#define REGISTERNAMESIZE 5


RegisterData registerTable[TOTALAMOUNTOFREGISTERS] = {

        {"00000", 0, "zero"},
        {"00001", 1, "at"},
        {"00010", 2, "v0"},
        {"00011", 3, "v1"},
        {"00100", 4, "a0"},
        {"00101", 5, "a1"},
        {"00110", 6, "a2"},
        {"00111", 7, "a3"},
        {"01000", 8, "t0"},
        {"01001", 9, "t1"},
        {"01010", 10, "t2"},
        {"01011", 11, "t3"},
        {"01100", 12, "t4"},
        {"01101", 13, "t5"},
        {"01110", 14, "t6"},
        {"01111", 15, "t7"},
        {"10000", 16, "t8"},
        {"10001", 17, "t9"},
        {"10010", 18, "s0"},
        {"10011", 19, "s1"},
        {"10100", 20, "s2"},
        {"10101", 21, "s3"},
        {"10110", 22, "s4"},
        {"10111", 23, "s5"},
        {"11000", 24, "s6"},
        {"11001", 25, "s7"},
        {"11010", 26, "s8"},
        {"11011", 27, "k0"},
        {"11100", 28, "k1"},
        {"11101", 29, "gp"},
        {"11110", 30, "sp"},
        {"11111", 31, "ra"}
};

RegisterData* FindRegisterDataByBits(char* bits){

    for(unsigned int i = 0; i < TOTALAMOUNTOFREGISTERS; i++){

        if(strcmp(registerTable[i].bits, bits) == 0){

            RegisterData foundRegister = registerTable[i];
            RegisterData returnRegister;

            // Arrays that will hold the data
            char registerBits[REGISTERBITSIZE];
            char registerName[REGISTERNAMESIZE];

            // Pointers that will point to the data
            returnRegister.bits = &registerBits[0];
            returnRegister.registerName = &registerName[0];

            // copy the strings over
            strcpy(returnRegister.bits, foundRegister.bits);
            strcpy(returnRegister.registerName, foundRegister.registerName);

            // copies over the register field
            returnRegister.registerField = foundRegister.registerField;

            RegisterData* returnPointer = &returnRegister;
            return returnPointer;

//            char* resetPointerOne;
//            char* resetPointerTwo;
//            int bitSize = strlen(foundRegister.bits) + 1;
//            returnRegister.bits = (char *)calloc(bitSize,  sizeof(char));
//
//
//            resetPointerOne = returnRegister.bits;
//            resetPointerTwo = foundRegister.bits;
//            for(unsigned int i = 0; i < 5; i++){
//                *returnRegister.bits = *foundRegister.bits;
//                returnRegister.bits++;
//                foundRegister.bits++;
//            }
//            returnRegister.bits = resetPointerOne;
//            foundRegister.bits = resetPointerTwo;
//
//            returnRegister.registerField = foundRegister.registerField;
//
//            int nameSize = strlen(foundRegister.registerName) + 1;
//            returnRegister.registerName = (char *)calloc(nameSize , sizeof(char));
//
//            int arraySize = strlen(foundRegister.registerName);
//
//            resetPointerOne = returnRegister.registerName;
//            resetPointerTwo = foundRegister.registerName;
//
//            for(unsigned int i = 0; i < arraySize; i++){
//                *returnRegister.registerName = *foundRegister.registerName;
//                returnRegister.registerName++;
//                foundRegister.registerName++;
//            }
//
//            returnRegister.registerName = resetPointerOne;
//            foundRegister.registerName = resetPointerTwo;

//            RegisterData * returnPointer = &returnRegister;
//            return returnPointer;
        }
    }

    return NULL;
}


void freeRegisterDataStruct(RegisterData* registerData){

    free(registerData->registerName);
    free(registerData->bits);
}