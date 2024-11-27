#include "MultiOptionInput.h"
#include <iostream>
#include <Utils.h>

namespace UI {
    MultiOptionInput::MultiOptionInput(const std::string &prompt, const std::vector<std::string> &actions) {
        int result = -1;
        while (result < 1 || result > actions.size()) {
            result = handle_input(prompt, actions);
            std::cout << Utils::ClearScreen;
        }

        m_result = result;
    }

    MultiOptionInput::~MultiOptionInput() = default;


    int MultiOptionInput::get_result_index() const {
        return m_result - 1;
    }

    int MultiOptionInput::handle_input(const std::string &prompt, const std::vector<std::string> &actions) {
        std::cout << prompt << "\n";

        int selection;

        for (int i = 0; i < actions.size(); i++) {
            std::cout << Utils::Font::BrightRed << i + 1 << Utils::Font::Reset << ". " << actions.at(i) << "\n";
        }

        std::cout << "\n" << Utils::Font::BrightBlue << "[HeroName]" << Utils::Font::Reset << "> " << Utils::Font::BrightGreen;
        std::cin >> selection;

        std::cout << Utils::Font::Reset;
        return selection;
    }
}
