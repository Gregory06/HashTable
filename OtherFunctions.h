int Print(HashTable * hashTable) {

    List * current_elem = nullptr;
    int sum = 0;

    FILE * file_out = fopen(OUTPUT_FILE, "w");

    for (int i = 0; i < SOME_SIMPLE_NUM; i++) {
        fprintf(file_out, "%d,", i);
        current_elem = hashTable->hash[i];
        while (current_elem) {
            sum++;
            current_elem = current_elem->next;
        }
        fprintf(file_out, "%d\n", sum);
        sum = 0;
    }

    fclose(file_out);

}

int StRcMp(const char * a, const char * b)
{
    asm(    ".intel_syntax noprefix\n\t"

            "xor r12, r12\n\t"
            "strcmp_cond:\n\t"
            "mov rax, 1\n\t"
            "mov r13, [rdi + r12]\n\t"
            "mov r14, [rsi + r12]\n\t"
            "cmp r13, r14\n\t"
            "jne strcmp_end\n\t"
            "inc r12\n\t"
            "cmp r13, 0\n\t"
            "jne  strcmp_cond\n\t"
            "mov rax, 0\n\t"
            "strcmp_end:\n\t"
    );
}