//
// Created by satvi on 17-10-2026.
//

#pragma once
#include <string>
#include <memory>
#include <vector>
#include "Tokenizer.h"
#include "token.h"
#include <cmath>

class main_tokenizer {
private:
    std::unique_ptr<std::vector<tokenizer>> subs_branch;
    tokenizer& main;
public:

    int size_of() const{
        return subs_branch->size();
    }
    tokenizer return_tokens(const int& i) const{
        return subs_branch->at(i);
    };

    main_tokenizer(tokenizer& main): main(main) {};

    bool operator==(int i) {
        if (subs_branch->at(i) == main) {}
    }

    int index(tokenizer& subs) const {
        int count = 0;
        while (count < subs_branch->size()) {
            if (subs_branch->at(count) == subs) {
                return count;
            }
            count++;
        }
    }

    /*
    double static solver(std::string& substring) {
        double result = 0.0;
        int step =0,count = 0;
        std::string local_sub = "", local_rec = "";
        while (step < substring.length()) {
            if (substring[step] == '(') {
                count += 1;
                step += 1;
                while (substring[step] != ')') {
                    local_rec += substring[step];
                    count += 1;
                    step += 1;
                    if (step == substring.length()-1) {
                        throw "Invalid input";
                    }
                }
                step += 1;
                substring.erase(step,count+step);
                result += solver(local_rec);
                local_rec = "";
            }
            local_sub += substring[step];
            step += 1;
        }
        */

    void add_token(tokenizer& subs,std::string &st) {
        std::string substring = "";
        char previous = ' ';
        int i = 0;
        while (i < st.length()) {
            switch (st[i]) {
                case '+': {
                    token t;
                    t.sign = 'a';
                    t.value = stod(substring);
                    subs.add_token(t);
                    substring = "";
                    i += 1;
                }
                case '-': {
                    token t;
                    t.sign = 'a';
                    t.value = stod('-' + substring);
                    subs.add_token(t);
                    substring = "";
                    i +=1;
                }
                case '*': {
                    if (previous != '*' && previous != '/' && previous != '^' && previous != '+' && previous != '-') {
                        token t;
                        t.sign = 'm';
                        if (st[i+1] == '-') {
                            t.value = stod('-'+substring);
                            i+=1;
                        } else {t.value = stod(substring);}
                        subs.add_token(t);
                        substring = "";
                        previous = st[i];
                        i+= 1;
                    } else {
                        throw "Invalid input format";
                    }
                }
                case '/': {
                    if (previous != '/' && previous != '*' && previous != '^' && previous != '+' && previous != '-') {
                        token t;
                        t.sign = 'd';
                        if (st[i+1] == '-') {
                            t.value = stod('-'+substring);
                            i+=1;
                        }else {t.value = stod(substring);}
                        subs.add_token(t);
                        substring = "";
                        previous = st[i];
                        i += 1;
                    } else {
                        throw "Invalid input format";
                    }
                }
                case '^': {
                    if (previous != '^' && previous != '*' && previous != '/' && previous != '+' && previous != '-') {
                        token t;
                        t.sign = 'e';
                        if (st[i+1] != '(') {
                            throw "Invalid input format";
                        }
                        if (st[i+1] == '-') {
                            t.value = stod('-'+substring);
                            i += 1;
                        }else {t.value = stod(substring);}
                        subs.add_token(t);
                        substring = "";
                        i += (k-i+1);
                        previous = st[i];
                    } else {
                        throw "Invalid input format";
                    }
                }
                case '(': {
                    if (previous == ' ') {
                        int j = i+1;
                        std::string substr = "";
                        bool close = false;
                        while (close == false) {
                            if (st[j] != ')' || j<st.length()) {
                                substr += st[j];
                                j += 1;
                            } else {
                                close = true;
                            }
                        }
                        st.erase(i,j);
                        i = j+1;
                        token t;
                        t.sign = 'g';
                        tokenizer ts;
                        add_token(ts,substr);
                        substring = "";
                        subs_branch->push_back(ts);
                        t.value = index(subs_branch->at(i));
                        subs.add_token(t);
                        i += 1;
                    }
                }
                default: { substring += st[i]; previous = st[i]; i+=1;}
            }
        }
    }
};


