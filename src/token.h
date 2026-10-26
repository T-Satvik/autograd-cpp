//
// Created by satvi on 16-10-2026.
//

#pragma once

struct token {
    char sign;
    double value;
};

bool inline operator==(const token& a, const token& b) {
    return (a.sign == b.sign && a.value == b.value);
};

bool inline operator!=(const token& a, const token& b) {
    return (a.sign != b.sign || a.value != b.value);
}

std::ostream& operator<<(std::ostream& out,const token& tk) {
    out<< tk.sign<< tk.value<<std::endl;
    return out;
}