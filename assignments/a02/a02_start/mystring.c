#include <stdio.h>

int str_wc(char *s) {
    // current position in string
    int i = 0;

    // number of works
    int word_count = 0;
    
    // keep moving pointer forward if no null character
    while (*(s+i) != '\0') {
        // if we see an english character, enter a loop
        if (('A' <= *(s+i) && *(s+i) <= 'Z') || ('a' <= *(s+i) && *(s+i) <= 'z')) {
            i++;
            while (1) {
                if (
                    *(s+i) == ' ' ||
                    *(s+i) == '\t' ||
                    *(s+i) == ',' ||
                    *(s+i) == '.' ||
                    *(s+i) == '\0'
                ) {
                    word_count += 1;
                    break;
                }
                i++;
            }
        } else {
            i++;
        }
    }

    return word_count;
}

int str_lower(char *s) {
    // current position in string
    int i = 0;
    int count = 0;

    while (*(s+i) != '\0') {
        if ('A' <= *(s+i) && *(s+i) <= 'Z') {
            *(s+i) += 32;
            count++;
        }
        i++;
    }
}

void str_trim(char *s) {
    // cycle through beginning removing leading spaces
    int leadingSpaces = 0;
    int lastChar = 0;

    for (int i = 0; *(s+i) == ' '; i++) {
        leadingSpaces++;
    }
    // shift all characters up, remembering the last address of the non space character
    // the last address refers to the address of the original string's last char
    for (int i = 0; *(s+leadingSpaces+i) != '\0'; i++) {
        if (*(s+leadingSpaces+i-1) != ' ') {
            lastChar = i + 1;
        }
        *(s+i) = *(s+leadingSpaces+i);
    }

    // terminate new string with \0
    // the last char is the last character of the new string - "shift/leading spaces"
    *(s + lastChar - leadingSpaces + 1) = '\0';
}

char *str_str(char *s1, char *s2) {
    // two pointer method, one for each string
    // move p1 forward until p1 == p2
    // then move them forward together
    // if p1 != p2, reset p2 to the beginning
    char *p1 = s1;
    char *p2 = s2;
    int length = 0;

    while (*p1 != '\0') {
        if (*p2 == '\0') {
            return p1 - length;
        } else if (*p1 != *p2) {
            p1++;
            p2 = s2;
            length = 0;
        } else {
            p1++;
            p2++;
            length++;
        }
    }

    return 0;
}