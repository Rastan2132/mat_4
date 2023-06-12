#include <iostream>

// Функция для вычисления быстрого возведения в степень по модулю
int fastPowerMod(int base, int exponent, int modulo) {
    int result = 1;

    while (exponent > 0) {
        // Если текущий бит степени равен 1
        if (exponent & 1) {
            result = (result * base) % modulo;
        }

        base = (base * base) % modulo;
        exponent >>= 1;
    }

    return result;
}

int main() {
    int base, exponent, modulo;
    std::cout << "Podaj podstawę: ";
    std::cin >> base;
    std::cout << "Podaj wykładnik: ";
    std::cin >> exponent;
    std::cout << "Podaj liczbę modulo: ";
    std::cin >> modulo;

    // Проверка условий теоремы
    if (base < 1 || exponent < 0 || modulo < 1) {
        std::cout << "Podane liczby nie spełniają założeń twierdzenia." << std::endl;
        return 0;
    }

    int result = fastPowerMod(base, exponent, modulo);
    std::cout << "Wynik potęgowania modulo: " << result << std::endl;

    return 0;
}
