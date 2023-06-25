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
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<double> dis(-0.5, 0.5);
        double fluctuation = dis(gen);

        double crashChance = 0.2;
        std::uniform_real_distribution<double> crashDis(0.0, 1.0);
        if (crashDis(gen) < crashChance) {
            r = -std::abs(r) * fluctuation;
        } else {
            r += fluctuation;
        }
    }
};

int main() {
    Coin coins;
    float investment;
    int simulationDays;
    char choice;

    while (true) {
        std::cout << "Which coin would you like to invest in?" << std::endl;
        std::cout << "[1] - Fockscoin\n[2] - Bitcoin\n[3] - Ethereum\n[4] - Dogecoin\n[5] - CIC\n[6] - Robuk" << std::endl;
        std::cin >> choice;

        switch (choice) {
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
                continue;
        }

        std::cout << "How much money do you want to invest?" << std::endl;
        std::cin >> investment;
        std::cout << "How many days do you want to simulate?" << std::endl;
        std::cin >> simulationDays;

        float balance = investment;

        for (int day = 1; day <= simulationDays; day++) {
            coins.applyRandomFluctuation();
            float earned = balance * coins.r;
            balance += earned;
            std::cout << "Day " << day << " - Balance: " << balance << std::endl;
        }

        std::cout << "Do you want to invest again? (y/n)" << std::endl;
        char answer;
        std::cin >> answer;

        if (answer != 'y' && answer != 'Y')
            break;
    }

    return 0;
}
