//
// Created by satvi on 16-10-2026.
//

#pragma once
#include <vector>
#include "token.h"



class tokenizer{
    private:
    std::vector<token> toks;
    public:
    tokenizer():toks(){};
    tokenizer(const std::vector<token> &ces): toks(ces) {};
    void add_token(const token &t) {
        toks.push_back(t);
    }

    token operator[](int i) const{
        return toks[i];
    }

    bool operator==(const tokenizer&t) const {
        if (toks.size() != t.toks.size()) {
            return false;
        }
        int count = 0;
        for (int i=0;i<toks.size();i++) {
            if (toks[i] == t.toks[i]) {
                count++;
            }
            if (i > count) {
                return false;
            }
        }
        return true;
    }

    int size() const {
        return toks.size();
    }

    token return_tokens(int i) const{
        return toks.at(i);
    }
};


