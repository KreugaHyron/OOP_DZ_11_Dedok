#include <iostream>
using namespace std;
int simpleRandom(int& seed) {
    seed = seed * 1664525 + 1013904223;
    return (seed >> 16) & 32767;
}
class Reel {
private:
    static const int SYMBOL_COUNT = 5;
    int symbols[SYMBOL_COUNT];
    int currentPosition;

public:
    Reel(int arr[SYMBOL_COUNT]) {
        for (int i = 0; i < SYMBOL_COUNT; ++i) {
            symbols[i] = arr[i];
        }
        currentPosition = 0;
    }

    void spin(int& seed) {
        currentPosition = simpleRandom(seed) % SYMBOL_COUNT;
    }

    int getCurrentSymbol() const {
        return symbols[currentPosition];
    }
};

bool checkCombination(const Reel& reel1, const Reel& reel2, const Reel& reel3) {
    return (reel1.getCurrentSymbol() == reel2.getCurrentSymbol() &&
        reel2.getCurrentSymbol() == reel3.getCurrentSymbol());
}
int main()
{
    setlocale(LC_ALL, "RUS");
    int seed = 3121;
    int symbols1[5] = { 1, 2, 3, 4, 5 };
    int symbols2[5] = { 6, 7, 8, 9, 10 };
    int symbols3[5] = { 11, 12, 13, 14, 15 };

    Reel reel1(symbols1);
    Reel reel2(symbols2);
    Reel reel3(symbols3);

    reel1.spin(seed);
    reel2.spin(seed);
    reel3.spin(seed);

    cout << "Барабан 1: " << reel1.getCurrentSymbol() << "\n";
    cout << "Барабан 2: " << reel2.getCurrentSymbol() << "\n";
    cout << "Барабан 3: " << reel3.getCurrentSymbol() << "\n";

    if (checkCombination(reel1, reel2, reel3)) {
        cout << "Поздравляем! Вы выиграли!" << "\n";
    }
    else {
        cout << "Увы, вы проиграли. Попробуйте еще раз." << "\n";
    }
    return 0;
}
