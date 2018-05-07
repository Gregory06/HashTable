unsigned int H1(char * str) {

    unsigned int sum = 0;

    for (int i = 0; i < ONE_WORD_LEN; i++) {
        sum += str[i];
        printf(" %c -- %d   ", str[i], str[i]);

    }
    printf("\n\n");

//        sum++;

    return sum;
}

unsigned int H4 (char * str)
{
    unsigned int h = 5381;

    for (int i = 0; i < ONE_WORD_LEN; i++) {
        h = h * 33 + str[i];
//        printf(" %c -- %d   ", str[i], str[i]);
    }

//    printf("\n\n");

    return h;
}
