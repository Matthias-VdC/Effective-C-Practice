struct S {
    int i; // 4 bytes
    // 4 byte padding by compiler
    double d; // 8 bytes
    char c; // 1 byte
    // 7 byte padding by compiler
}; // total is 24 bytes on 64 bit systems

int main(void) {
    // Plain byte array, no guaranteed alignment
    unsigned char bad_buff[sizeof(struct S)];

    // Aligned to struct S alignment requirements
    _Alignas(struct S) unsigned char good_buff[sizeof(struct S)];

    // bad_buff's address might not satisfy struct S's alignment reqirements (might not be 8-byte aligned)
    // Could lead to undefined behavior, crashes, performance penalty
    struct S *bad_s_ptr = (struct S *)bad_buff; // Wrong pointer alignment
    
    struct S *good_s_ptr = (struct S *)good_buff; // Correct pointer alignment
} 
