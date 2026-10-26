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


    void output() {
        for (token& t : toks) {
            std::cout << t;
        }
        std::cout<<-1<<std::endl;
    }

    bool operator==(const tokenizer&t) const {
        if (toks.size() != t.toks.size()) {
            return false;
        }
        for (int i=0;i<toks.size();i++) {
            if (toks[i] != t.toks[i]) {
                return false;
            }
        }
        return true;
    }

    [[nodiscard]] int size() const {
        return toks.size();
    }

    [[nodiscard]] const token& return_tokens(int i) const{
        return toks.at(i);
    }
};


