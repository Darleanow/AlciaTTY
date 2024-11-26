#include "MultiOptionInput.h"
#include <iostream>

namespace UI {
    MultiOptionInput::MultiOptionInput(const std::string &prompt, const std::vector<std::string> &actions) {
        std::cout << prompt;
        std::cout << "\n";

        int selection;

        for (int i = 0; i < actions.size(); i++) {
            std::cout << i << ". " << actions.at(i) << "\n";
        }

        std::cout << "\n" << "Your Choice: ";

        std::cin >> selection;

        m_result = selection;
    }

    MultiOptionInput::~MultiOptionInput() = default;


    int MultiOptionInput::get_result() const {
        return m_result;
    }
}
