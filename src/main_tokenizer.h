//
// Created by satvi on 17-10-2026.
//

#pragma once
#include <string>
#include <memory>
#include <vector>
#include "Tokenizer.h"
#include "token.h"


class main_tokenizer {
private:
    std::unique_ptr<std::vector<tokenizer>> subs_branch;
    tokenizer main;
public:

    [[nodiscard]] int size_of() const{
        return subs_branch->size();
    }
    [[nodiscard]] const tokenizer& return_tokens(const int& i) const{
        return subs_branch->at(i);
    };

    main_tokenizer(const tokenizer& main): main(main), subs_branch(std::make_unique<std::vector<tokenizer>>()) {};

    [[nodiscard]] bool matching(int i) const{
        if (subs_branch->at(i) == main) {
            return true;
        }
        return false;
    }

    [[nodiscard]] int index(const tokenizer& subs) const {
        int count = 0;
        while (count < subs_branch->size()) {
            if (subs_branch->at(count) == subs) {
                return count;
            }
            count++;
        }
        return -1;
    }

    void output_tokens() const{
        for (auto & i : *subs_branch) {
            i.output();
        }
    }

    void add_token(tokenizer& subs,std::string& st) {
        std::string substring ;
        char previous = ' ';
        int i = 0;
        while (i < st.length()) {
            switch (st[i]) {
                case '+': {
                    token t{};
                    t.sign = '+';
                    if (substring.empty()) {
                        t.value = 0.00;
                    } else {
                        t.value = stod(substring);
                    }
                    subs.add_token(t);
                    substring = "";
                    previous = st[i];
                    i++;
                    break;
                }
                case '-': {
                    token t{};
                    t.sign = '-';
                    if (substring.empty()) {
                        t.value = 0.00;
                    } else {
                        t.value = stod(substring);
                    }
                    subs.add_token(t);
                    substring = "";
                    previous = st[i];
                    i++;
                    break;
                }
                case '*': {
                    if (previous != '*' && previous != '/' && previous != '^' && previous != '+' && previous != '-') {
                        token t{};
                        t.sign = '*';
                        if (substring.empty()) {
                            throw std::invalid_argument("Invalid input format for multiplication");
                        } else {
                            t.value = stod(substring);
                        }
                        subs.add_token(t);
                        substring = "";
                        previous = st[i];
                        i++;
                    } else {
                        throw std::invalid_argument("Invalid input format for multiplication");
                    }
                    break;
                }
                case '/': {
                    if (previous != '/' && previous != '*' && previous != '^' && previous != '+' && previous != '-') {
                        token t{};
                        t.sign = '/';
                        if (substring.empty()) {
                            throw std::invalid_argument("Invalid input format for division");
                        } else {
                            t.value = stod(substring);
                        }
                        subs.add_token(t);
                        substring = "";
                        previous = st[i];
                        i += 1;
                    } else {
                        throw std::invalid_argument("Invalid input format for divison");
                    }
                    break;
                }
                case '^': {
                    if (previous != '^' && previous != '*' && previous != '/' && previous != '+' && previous != '-') {
                        token t{};
                        t.sign = '^';
                        if (substring.empty()) {
                            throw std::invalid_argument("Invalid input format for exponent");
                        } else {
                            t.value = stod(substring);
                        }

                        subs.add_token(t);
                        substring = "";
                        previous = st[i];
                        i++;
                    } else {
                        throw std::invalid_argument("Invalid input format for exponent");
                    }
                    break;
                }
                case '(': {
                    int depth = 1;
                    int j = i + 1;
                    std::string substr;
                    bool close = false;
                    while (close == false) {
                        if (j < st.length() && depth != 0) {
                            if (st[j] == '(') {
                                depth++;
                            }
                            if (st[j] == ')') {
                                depth--;
                                if (depth == 0){break;}
                            }
                            substr += st[j];
                            j += 1;
                        }
                        else {
                            close = true;
                        }
                    }
                    if (j<st.length()) {
                        if (st[j] != ')' || depth != 0) {
                            throw std::invalid_argument("Invalid input format for parenthesis");
                        }
                    } else {
                        throw std::invalid_argument("Unclosed parathesis");
                    }
                    i = j + 1;
                    token t{};
                    t.sign = 'p';
                    tokenizer ts;
                    add_token(ts, substr);
                    substring = "";
                    subs_branch->push_back(ts);
                    t.value = index(ts);
                    subs.add_token(t);
                    break;
                }
                default: {
                    substring += st[i];
                    previous = st[i];
                    i++;
                    if (i == st.length()) {
                        token t{};
                        t.sign = 'n';
                        if (substring.empty()) {
                            t.value = 0.00;
                        }else {
                            t.value = stod(substring);
                        }
                        subs.add_token(t);
                        break;
                    }
                }
            }
        }
    }
};


