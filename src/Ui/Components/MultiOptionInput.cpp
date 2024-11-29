#include "MultiOptionInput.h"

namespace UI {
    MultiOptionInput::~MultiOptionInput() = default;

    int MultiOptionInput::get_result_index() const {
        return m_result - 1;
    }
}
