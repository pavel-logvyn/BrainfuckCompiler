#include "Compiler.h"
class Compiler {
private:
    string input;
    Storage* storage_;
    queue<Operator> compiledProgram;
public:
    Compiler(string input_, Storage& storage) : input(input_), storage_(&storage) {}
    void compile() {
        for (int i = 0; i < input.length(); i++) {
            if (input[i] == '+')
                compiledProgram.push(IncreaseValue(storage_));
            else if (input[i] == '-')
                compiledProgram.push(DecreaseValue(storage_));
            else if (input[i] == '>')
                compiledProgram.push(IncreaseIndex(storage_));
            else if (input[i] == '<')
                compiledProgram.push(DecreaseIndex(storage_));
            else if (input[i] == '.')
                compiledProgram.push(ShowCharacter(storage_));
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
};