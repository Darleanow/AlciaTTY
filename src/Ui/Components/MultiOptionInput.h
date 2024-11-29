#pragma once
#include <string>
#include <ranges>
#include <iostream>
#include <Components/Utils/Utils.h>
#include <string>

namespace UI {
    class MultiOptionInput {
    public:
        template<std::ranges::range Range>
        MultiOptionInput(const std::string &prompt, const Range &actions) {
            do {
                m_result = handle_input(prompt, actions);
            } while (m_result < 1 || m_result > static_cast<int>(std::ranges::distance(actions)));
        }

        ~MultiOptionInput();

        [[nodiscard]] int get_result_index() const;

    private:
        int m_result;

        template<std::ranges::range Range>
        int handle_input(const std::string &prompt, const Range &actions) {
            auto render_prompt = [&] {
                std::cout << prompt << "\n";

                int index = 1;
                for (const auto &action : actions) {
                    std::cout << Utils::Font::BrightRed
                              << index++
                              << Utils::Font::Reset
                              << ". "
                              << action
                              << "\n";
                }

                std::cout << "\n" << Utils::Font::BrightBlue
                          << "[HeroName]"
                          << Utils::Font::Reset
                          << "> "
                          << Utils::Font::BrightGreen;
            };

            auto clear_prompt = [&] {
                Utils::clear_last_lines(static_cast<int>(std::ranges::distance(actions)) + 1);
            };

            int selection = -1;

            while (true) {
                render_prompt();

                // Handle repeated empty input and invalid input
                if (!(std::cin >> selection)) {
                    std::cin.clear();
                    std::cin.ignore(5000, '\n');
                    clear_prompt();
                    std::cout << "Invalid selection, please try again.\n";
                } else if (selection < 1 || selection > static_cast<int>(std::ranges::distance(actions))) {
                    clear_prompt();
                    std::cout << "Invalid selection, please try again.\n";
                } else {
                    break;
                }

                clear_prompt();
            }

            clear_prompt();

            std::cout << Utils::Font::Reset;
            return selection;
        }
    };
}
