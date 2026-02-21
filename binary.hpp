/* Copyright (c) 2026 sammy */
#include <string>
#include <random>

struct binary {
    std::string generate(int length) {
        std::string data = "";
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, 1);
        for (int i = 0; i < length; ++i) {
            data += std::to_string(dis(gen));
        }
        return data;
    }
};
