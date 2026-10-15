//
// Created by satvi on 10-10-2026.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>

/*
template <typename t>
class Map {
    private:
    struct nodeconec {
        int conec_elem;
        double distance;
    };
    struct node {
        nodeconec* Vec;
        t* element;
        int size;
    };
    node* graph;
    public:
    Map(): graph{new node[0]} {};
    
};
*/

struct token {
    char sign;
    double value;
};

class tokenizer{
    private:
    std::vector<token> toks;
    public:
    tokenizer():toks(){};
    tokenizer(const std::vector<token> &ces): toks(ces) {};
    void add_token(const token &t) {
        toks.push_back(t);
    }
    std::istream input_tokens(std::istream &is) {
        token t;
        t.sign = is.get();
        t.value = is.get();
        add_token(t);
    }

    void generate_tokens(const std::string & st) {
        std::string substring = "";
        char previous =' ';
        for (int i = 0; i < st.length(); i++) {
            switch (st[i]) {
                case '+' : {if (previous == ' ') {
                    token t;
                    t.sign = 'a';
                    t.value = stod(substring);
                    add_token(t);
                    substring = "";
                    previous = st[i];
                }else {
                    throw "Invalid input format";
                    break;
                }}
                case '-': {
                    if (previous == ' ') {
                        token t;
                        t.sign = 'a';
                        t.value = stod(substring);
                        add_token(t);
                        substring = "";
                        previous = st[i];
                    }else {
                        throw "Invalid input format";
                        break;
                    }
                }
                case '*': {if (previous == ' ') {
                    token t;
                    t.sign = 'm';
                    t.value = stod(substring);
                    add_token(t);
                    substring = "";
                    previous = st[i];
                }else {
                    throw "Invalid input format";
                    break;
                }}
                case '/': {if (previous == ' ') {
                    token t;
                    t.sign = 'd';
                    t.value = stod(substring);
                    add_token(t);
                    substring = "";
                    previous = st[i];
                }else {
                    throw "Invalid input format";
                    break;
                }}
                case '^': {if (previous == ' ') {
                    token t;
                    t.sign = 'e';
                    t.value = stod(substring);
                    add_token(t);
                    substring = "";
                    previous = st[i];
                }}
                case '(': {if (previous == ' ') {
                    int j = i;
                    std::string sub = "";
                    bool close = false;
                    while (close == false) {
                        if (st[j] != ')') {
                            sub += st[j];
                            j += 1;
                        } else {
                            close = true;
                        }
                    }
                    token t;
                    t.sign = 'g';
                    add_token(t);
                    generate_tokens(sub);
                }}
                default: {substring += st[i];}
            }
        }
    }
};

class calculator {
private:
    tokenizer toks;
    public:
    calculator(const tokenizer &t):toks(t){};
    double calculate() {
        for (auto& tk : toks) {

        }
    }
};

int main() {

}