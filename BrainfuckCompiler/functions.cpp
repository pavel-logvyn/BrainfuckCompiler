#include "functions.h"
void build(const string input, char bfstorage[], size_t& bfindex, size_t i = 0) {
    for (; i < input.length(); i++) {
        if (input[i] == '+')
            bfstorage[bfindex]++;
        else if (input[i] == '-')
            bfstorage[bfindex]--;
        else if (input[i] == '>')
            bfindex++;
        else if (input[i] == '<')
            bfindex--;
        else if (input[i] == '.')
            cout << bfstorage[bfindex];
        else if (input[i] == '[') {
            if (!bfstorage[bfindex]) {
                size_t depth = 1;
                while (depth) {
                    i++;
                    if (input[i] == '[')
                        depth++;
                    if (input[i] == ']')
                        depth--;
                }
            }
            else
                continue;
        }
        else if (input[i] == ']') {
            if (!bfstorage[bfindex])
                continue;
            else {
                if (bfstorage[bfindex]) {
                    size_t depth = 1;
                    while (depth) {
                        --i;
                        if (input[i] == '[')
                            depth--;
                        if (input[i] == ']')
                            depth++;
                    }
                    --i;
                }
            }
        }
    }
}