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
    void setDoge() {
        r = 0.10;
    }
    void setCIC() {
        r = 0.05;
    }

    void applyRandomFluctuation() {
        std::srand(static_cast<unsigned int>(std::time(nullptr)));
        double fluctuation = (std::rand() % 101 - 50) / 100.0;

        double crashChance = 0.2;
        if (std::rand() / static_cast<double>(RAND_MAX) < crashChance) {
            r = -std::abs(r) * fluctuation;
        } else {
            r += fluctuation;
        }
    }
};

int main() {
    Coin coins;
    float a;
    int dinput;
    float c;
    char escolha;

    std::cout << "Which coin would you like to invest in?" << std::endl;
    std::cout << "[1] - Fockscoin\n[2] - Bitcoin\n[3] - Ethereum\n[4] - Dogecoin\n[5] - CIC\n[6] - Robuk" << std::endl;
    std::cin >> escolha;

    switch (escolha) {
        case '1':
            coins.setFocksCoin();
            break;
        case '2':
            coins.setBitcoin();
            break;
        case '3':
            coins.setEth();
            break;
        case '4':
            coins.setDoge();
            break;
        case '5':
            coins.setCIC();
            break;
        default:
            std::cout << "Invalid choice!" << std::endl;
            return 0;
    }

    std::cout << "How much money do you want to invest?" << std::endl;
    std::cin >> c;
    std::cout << "How many days do you want to simulate?" << std::endl;
    std::cin >> dinput;

    for (int day = 1; day <= dinput; day++) {
        coins.applyRandomFluctuation();
        a = c * std::pow(1 + coins.r, day);
        std::cout << "Day " << day << " - Balance: " << a << std::endl;
    }

    return 0;
}
