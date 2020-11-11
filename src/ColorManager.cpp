//
// Created by newton on 11/3/20.
//

#include "ColorManager.h"

void ColorManager::initializeColors() {
    for (const auto color : Colors::All) {
        init_pair(color, color, -1);
    }
}
