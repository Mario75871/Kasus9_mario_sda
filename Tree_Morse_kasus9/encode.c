#include <stdio.h>
#include <ctype.h>
#include <string.h>

typedef struct {
    char letter;
    const char* code;
} MorseCode;

static MorseCode morse_table[] = {
    {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."},
    {'E', "."}, {'F', "..-."}, {'G', "--."}, {'H', "...."},
    {'I', ".."}, {'J', ".---"}, {'K', "-.-"}, {'L', ".-.."},
    {'M', "--"}, {'N', "-."}, {'O', "---"}, {'P', ".--."},
    {'Q', "--.-"}, {'R', ".-."}, {'S', "..."}, {'T', "-"},
    {'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"},
    {'Y', "-.--"}, {'Z', "--.."}, {'1', ".----"}, {'2', "..---"},
    {'3', "...--"}, {'4', "....-"}, {'5', "....."}, {'6', "-...."},
    {'7', "--..."}, {'8', "---.."}, {'9', "----."}, {'0', "-----"},
    {' ', "|"}
};

void encode_text(const char* text) {
    for (int i = 0; text[i]; i++) {
        char c = toupper(text[i]);
        for (int j = 0; j < sizeof(morse_table)/sizeof(MorseCode); j++) {
            if (morse_table[j].letter == c) {
                printf("%s  ", morse_table[j].code);
                break;
            }
        }
    }
    printf("\n");
}
