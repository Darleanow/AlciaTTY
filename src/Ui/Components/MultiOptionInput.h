#pragma once
#include <string>
#include <vector>

namespace UI {
    class MultiOptionInput {
    public:
        MultiOptionInput(const std::string &prompt, const std::vector<std::string> &actions);

        ~MultiOptionInput();

        [[nodiscard]] int get_result_index() const;

    private:
        int m_result;

        [[nodiscard]] static int handle_input(const std::string &prompt, const std::vector<std::string> &actions);
    };
}
