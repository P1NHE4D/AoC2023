#include "day01.h"

void Day01::task01() {
    std::string line;
    std::ifstream TaskInput("/Users/alexander/dev/AoC2023/input/day01.txt");

    uint32_t sum = 0;

    while (std::getline(TaskInput, line)) {
        uint32_t i = 0;
        uint32_t j = line.length();
        while (!isdigit(line[i])) {
            i++;
        }
        while (!isdigit(line[j])) {
            j--;
        }

        std::string str;
        str += line[i];
        str += line[j];
        sum += std::stoi(str);
    }

    std::cout << "Task 01 solution: " << sum << "\n";
}

static const std::string numbers[] = {
        "zero",
        "one",
        "two",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine"
};

void Day01::task02() {
    std::string line;
    std::ifstream TaskInput("/Users/alexander/dev/AoC2023/input/day01.txt");

    uint32_t sum = 0;

    while (std::getline(TaskInput, line)) {
        uint32_t i = 0;
        uint32_t j = line.length();
        while (!isdigit(line[i]) && i < line.length()) {
            i++;
        }
        while (!isdigit(line[j]) && j > 0) {
            j--;
        }

        char a = line[i];
        char b = line[j];

        for (int n = 0; n < 10; n++) {
            size_t pos = line.find(numbers[n], 0);
            while (pos != std::string::npos) {
                if (pos < i) {
                    a = '0' + n;
                    i = pos;
                }
                if (pos > j) {
                    b = '0' + n;
                    j = pos;
                }
                pos = line.find(numbers[n],pos+1);
            }
        }


        std::string str;
        str += a;
        str += b;
        sum += std::stoi(str);
    }

    std::cout << "Task 02 solution: " << sum << "\n";
}