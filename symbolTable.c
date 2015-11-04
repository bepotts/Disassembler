//
// Created by brandon on 11/1/15.
//

#include "symbolTable.h"
#include "fileProcessing.h"
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_SIZE 150


/***
 * Creates a valid SymbolData
 */
void symbolInit(Symbol* symbol){

//    char nameArray[50];
//    char typeArray[50];
//    char valueArray[50];
//    char addressArray[50];
//
//    memset(nameArray, '\0', sizeof(nameArray));
//    memset(typeArray, '\0', sizeof(typeArray));
//    memset(valueArray, '\0', sizeof(valueArray));
//    memset(addressArray, '\0', sizeof(addressArray));

    symbol->name = (char *)calloc(100, sizeof(char *));
    symbol->type = (char *)calloc(100, sizeof(char *));
    symbol->value = (char *)calloc(100, sizeof(char *));
    symbol->address = (char *)calloc(100, sizeof(char *));

}


void symbolTableInit(SymbolTable* symbolTable){

//    Symbol symbolArray[50];
    symbolTable->table = (Symbol *)malloc(100 * sizeof(Symbol *));
    symbolTable->size = 0;
}

/***
 * Inserts a value to the table
 */
void insertValueToTable(char* value, char* address, SymbolTable* symbolTable){

    Symbol newTable;
    symbolInit(&newTable);

    // increment to the next empty value
    for(int i = 0; i < symbolTable->size; i++){
        symbolTable->table++;
    }

    // handles the naming
    char* tempNameArray = (char *)calloc(100, sizeof(char *));
    strcpy(newTable.name, "V0");
    sprintf(tempNameArray, "%d", symbolTable->size);
    strcat(newTable.name, tempNameArray);
    strcat(newTable.name, ":");

    // copies over the type
    strcpy(newTable.type, ".word");

    // copies over the value
    strcpy(newTable.value, value);

    // copies over the address
    strcpy(newTable.address, address);

    free(tempNameArray);

    symbolTable->table = &newTable;

    symbolTable->size++;

}


Symbol* getSymbolByAddress(char* address, SymbolTable* symbolTable){

    // Iterates over the entire symbol array
    for(int i = 0; i <= symbolTable->size; i++){

        // will only be true if the addresses are equal
        if(strcmp(symbolTable->table->address, address) == 0){

            return *&symbolTable->table;
        }
        symbolTable->table++;
    }

    return NULL;
}


void printSymbolTable(FILE* outputFile, SymbolTable* symbolTable){

    char line[MAX_LINE_SIZE];
    char* pLine = line;
    Symbol symbolAtIndex;

    // prints the .data text
    printToOutputFile(false, ".data\n", outputFile);

    // Iterates over the entire symbolArray
    for(unsigned int i = 0; i < symbolTable->size; i++){

        symbolAtIndex = *symbolTable->table;

        // builds and prints each line of the '.data' section
        strcat(pLine, symbolAtIndex.name);
        strcat(pLine, "\t\t");
        strcat(pLine, symbolAtIndex.type);
        strcat(pLine, " ");
        strcat(pLine, symbolAtIndex.value);
        strcat(pLine, "\n");
        printToOutputFile(false, pLine, outputFile);

        symbolTable->table++;
    }

}


void freeSymbolTable(SymbolTable* symbolTable){

    Symbol* symbol;
    // iterates over the entire array deallocating values
    for(int i = 0; i < symbolTable->size; i++){

        symbol = *&symbolTable->table;
        free(symbol->address);
        free(symbol->name);
        free(symbol->type);
        free(symbol->value);
        symbolTable->table++;
    }

    // Goes back to the beginning
    for(int i = 0; i < symbolTable->size; i++){
        symbolTable->table--;
    }

    free(symbolTable->table);
}