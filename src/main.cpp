//
// Created by satvi on 10-10-2026.
//

#include <iostream>
#include "Tokenizer.h"
#include "token.h"
#include "main_tokenizer.h"

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

/*
class calculator_tokenwise {
private:
    main_tokenizer& branchs;
    public:
    calculator_tokenwise(main_tokenizer& bran):branchs(bran) {};

    double solve(tokenizer& subs) {
        double sum = 0;
        int i,j = 0;
        token t = subs[0];
        sum = t.value;
        for (i < subs.size(); i++;) {
            if (i<subs.size()-1) {j = i+1;}
            token t = subs[i];
            switch (t.sign) {
                case 'm' : {sum *= t.value;}
                case 'd' : {sum /= t.value;}
            }
        }
    }

    void placeback() {
        for (int i = 0; i < branchs.size_of(); i++) {
            tokenizer sub = branchs.return_tokens(i);
            for (int j = 0; j < sub.size(); j++) {

            }
        }
    }
};
*/

int main() {

    try {
        tokenizer subs;
        main_tokenizer main(subs);
        std::string st = "256-89";
        main.add_token(subs, st);
        main.output_tokens();
    }catch (std::string& e) {
        std::cerr << e << std::endl;
    }catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

}