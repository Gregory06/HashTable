int HashTableConstract(HashTable * elem) {

    elem->hash_counter = H4;

    return SUCCESS;
}

int AddToTable(HashTable * hash_table, char * str_to_add) {

    unsigned int new_hash = hash_table->hash_counter(str_to_add) % SOME_SIMPLE_NUM;

//    printf("%d  %s\n", new_hash, str_to_add);

    int flag = NEXT;
    List * current_elem = hash_table->hash[new_hash];

    while (flag == NEXT)  {
        if (!current_elem) {
            flag = STOP;
            unuque_words++;
        }
        else {
//            printf("%s vs %s are", current_elem->data, str_to_add);
            if (!StRcMp(current_elem->data, str_to_add)) {
                flag = FOUND;
//                printf("the same\n\n");
            }
            else {
                current_elem = current_elem->next;
//                printf("differetn\n\n");
            }
        }
    }

    if (flag == STOP) {
        List * new_elem = (List *) malloc(sizeof(List));

        if (hash_table->hash[new_hash]) {
            new_elem->next = hash_table->hash[new_hash]->next;
            hash_table->hash[new_hash]->next = new_elem;
        }
        else
            hash_table->hash[new_hash] = new_elem;
        strcpy(new_elem->data, str_to_add);
    }

}
