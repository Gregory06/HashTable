#include <iostream>

#define INPUT_FILE "/Users/MyMac/CLionProjects/TopProgramming/HTable/outt.txt"
#define OUTPUT_FILE "/Users/MyMac/CLionProjects/TopProgramming/HTable/OUT.csv"

int unuque_words = 0;

enum {
    SOME_SIMPLE_NUM = 80007,
    ONE_WORD_LEN = 30,
    SUCCESS = 1,
    NEXT = 1,
    STOP = 0,
    FOUND = -1
};


struct List {

    char data[ONE_WORD_LEN] = {};
    List * next = nullptr;

};

struct HashTable {
    List * hash[SOME_SIMPLE_NUM] = {};
    unsigned int (* hash_counter) (char * str) = nullptr;
};

#include "FunctionsName.h"

int main() {

    char a[10];
    char b[10];
    scanf("%s", a);
    scanf("%s", b);

    printf("%d", StRcMp(a,b));

    return 0;

    int counter = 0;

    HashTable hash_table;

    HashTableConstract(&hash_table);

    FILE * input_file = nullptr;
    char input_data[ONE_WORD_LEN] = {};

    input_file = fopen(INPUT_FILE, "r");

    while (!feof(input_file)) {
        fscanf(input_file, "%s\n", input_data);
        AddToTable(&hash_table, input_data);
        counter++;
        for (int i = 0; i < ONE_WORD_LEN; i++)
            input_data[i] = 0;
    }
    fclose(input_file);

    printf("Total %d words and unuque %d\n", counter, unuque_words);

    Print(&hash_table);

    return 0;
}

#include "HashTableFunctions.h"
#include "HashCountFunctions.h"
#include "OtherFunctions.h"
