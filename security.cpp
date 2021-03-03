#include "security.h"

Security::Security()
{

}

/*int main(void) {
    uint8_t encrypted[BUFF_SIZE] = {0};
    uint8_t decrypted[BUFF_SIZE] = {0};
    uint8_t buffer[BUFF_SIZE];
    uint8_t key[KEY_SIZE] = "AES_key_128_bits";

    size_t length = input_string(buffer);
    print_bytes(buffer, length);

    length = AES(encrypted, 'E', key, KEY_SIZE, buffer, length);
    print_bytes(encrypted, length);

    length = AES(decrypted, 'D', key, KEY_SIZE, encrypted, length);
    print_bytes(decrypted, length);
    return 0;
}*/


void encrypt(std::string data) {
    uint8_t encrypted[BUFF_SIZE] = {0};
    uint8_t decrypted[BUFF_SIZE] = {0};
    uint8_t buffer[BUFF_SIZE];
    uint8_t key[KEY_SIZE] = "AES_key_128_bits";

    size_t length = input_string(buffer);
    print_bytes(buffer, length);

    length = AES(encrypted, 'E', key, KEY_SIZE, buffer, length);
    print_bytes(encrypted, length);

    length = AES(decrypted, 'D', key, KEY_SIZE, encrypted, length);
    print_bytes(decrypted, length);
    return 0;
}
