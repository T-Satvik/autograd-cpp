//
// Created by satvi on 16-10-2026.
//

#pragma once

struct token {
    char sign;
    double value;
};

bool operator==(token a, token b) {
    return a.value == b.value;
};