#include <iostream>
#include <cmath>
#include <random>
#include <ctime>

class Coin {
public:
    float r;

    void setFocksCoin() {
        r = 0.05;
    }
    void setBitcoin() {
        r = 0.06;
    }
    void setEth() {
        r = 0.09;
    }
    void applyRandomFluctuation() {
        std::srand(static_cast<unsigned int>(std::time(nullptr)));
        double fluctuation = (std::rand() % 101 - 50) / 100.0;
        r += fluctuation;
    }
};

int main() {
    Coin coins;
    float a;
    int dinput;
    float c;
    char escolha;

    std::cout << "Which coin would you like to invest in?" << std::endl;
    std::cout << "[1] - Fockscoin\n[2] - Bitcoin\n[3] - Ethereum" << std::endl;
    std::cin >> escolha;

    if (escolha == '1') {
        coins.setFocksCoin();
    }
    else if (escolha == '2') {
        coins.setBitcoin();
    }
    else if (escolha == '3') {
        coins.setEth();
    }
    else {
        std::cout << "Invalid choice!" << std::endl;
        return 0;
    }
    std::cout << "How much money do u want to invest?" << std::endl;
    std::cin >> c;
    std::cout << "How many days do you want to simulate?" << std::endl;
    std::cin >> dinput;

    for (int day = 1; day <= dinput; day++) {
        a = c * pow(1 + coins.r, day);
        a = c * std::pow(1 + coins.r, day);
        std::cout << "Day " << day << " - Balance: " << a << std::endl;
    }

    return 0;
}
