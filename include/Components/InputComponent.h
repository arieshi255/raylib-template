#pragma once

#include <raylib.h>
#include <vector>
#include "Gravity.h"

namespace Components {
    struct InputComponent {
        public:
            std::vector<KeyboardKey> KeyList{};
    };
}