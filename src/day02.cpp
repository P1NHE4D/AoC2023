#include "day02.h"

const string colors[3] = {"red", "green", "blue"};
const int limits[3] = {12, 13, 14};

int exceedsLimit(string& line) {
    for (int ci = 0; ci < 3; ci++) {
        regex pattern("(\\d+)\\s*" + colors[ci]);
        auto startIterator = sregex_iterator(line.begin(), line.end(), pattern);
        auto endIterator = sregex_iterator();
        for (sregex_iterator i = startIterator; i != endIterator; i++) {
            const smatch& match = *i;
            if (match.length() > 1) {
                string str = match.str(1);
                int num = stoi(str);
                if (num > limits[ci]) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

void Day02::task01() {
    string line;
    ifstream TaskInput("/Users/alexander/dev/AoC2023/input/day02.txt");

    int game, result = 0;

    while (getline(TaskInput, line)) {
        game++;
        if (!exceedsLimit(line)) {
            result += game;
        }
    }

    cout << "Task 01 solution: " << result << endl;
}

void Day02::task02() {
    string line;
    ifstream TaskInput("/Users/alexander/dev/AoC2023/input/day02.txt");

    int result = 0;
    int max_ns[3] = {0, 0, 0};

    while (getline(TaskInput, line)) {
        for (int ci = 0; ci < 3; ci++) {
            regex pattern("(\\d+)\\s*" + colors[ci]);
            auto startIterator = sregex_iterator(line.begin(), line.end(), pattern);
            auto endIterator = sregex_iterator();
            for (sregex_iterator i = startIterator; i != endIterator; i++) {
                const smatch& match = *i;
                if (match.length() > 1) {
                    string str = match.str(1);
                    int num = stoi(str);
                    if (num > max_ns[ci]) {
                        max_ns[ci] = num;
                    }
                }
            }
        }
        result += max_ns[0] * max_ns[1] * max_ns[2];
        max_ns[0] = max_ns[1] = max_ns[2] = 0;
    }

    cout << "Task 02 solution: " << result << endl;
}