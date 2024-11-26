#include "Utils.h"
#include <iostream>

int main() {
    std::cout << Utils::Font::BrightRed << Utils::Background::BrightYellow
              << "Bright Red Text on Bright Yellow Background" << Utils::Font::Reset << std::endl;

    // std::cout << Utils::ClearScreen;

    return 0;
}
