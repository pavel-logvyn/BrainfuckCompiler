#include "Compiler.h"
class Compiler {
private:
    string input;
    Storage* storage_;
    list<Operator> *compiledProgram;
public:
    ~Compiler() {
        delete storage_;
        delete compiledProgram;
    }
    Compiler(string input_, Storage& storage, list<Operator>& listOfOperations) : input(input_), storage_(&storage), compiledProgram(&listOfOperations) {}
    bool compile() {
        Storage temp;
        try {
            for (int i = 0; i < input.length(); i++) {
                if (input[i] == '+') {
                    if ((temp.bfstorage[temp.bfindex] + 1) > 127)
                        throw out_of_range("Value of cell is out of bounds (more than 127).");
                    temp.bfstorage[temp.bfindex]++;
                    compiledProgram->push(IncreaseValue(storage_));
                }
                else if (input[i] == '-')
                {
                    if ((temp.bfstorage[temp.bfindex] - 1) < 0)
                        throw out_of_range("Value of cell is out of bounds (less than 0).");
                    temp.bfstorage[temp.bfindex]++;
                    compiledProgram->push(DecreaseValue(storage_));
                }
                else if (input[i] == '>') {
                    if ((temp.bfindex + 1) > sizeof(temp.bfstorage)/sizeof(char))
                        throw out_of_range("Index is out of bounds (more then 30000).");
                    temp.bfindex++;
                    compiledProgram->push(IncreaseIndex(storage_));
                }
                else if (input[i] == '<') {
                    if ((temp.bfindex - 1) < 0)
                        throw out_of_range("Index is out of bounds (less then 0).");
                    temp.bfindex--;
                    compiledProgram->push(DecreaseIndex(storage_));
                }
                else if (input[i] == '.')
                    compiledProgram->push(ShowCharacter(storage_));
                else if (input[i] == '[') {
                    if (!temp.bfstorage[temp.bfindex]) {
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
                    if (!temp.bfstorage[temp.bfindex])
                        continue;
                    else {
                        if (temp.bfstorage[temp.bfindex]) {
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
        catch (out_of_range ex) {
#ifdef _DEBUG
            cout <<"Error: "<<  ex.what() << endl;
#endif
            return false;
        }
        return true;
    }
};