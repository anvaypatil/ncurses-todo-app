//
// Created by newton on 11/3/20.
//

#ifndef MONITOR_COLORS_H
#define MONITOR_COLORS_H

namespace Colors {
    enum Type {
        BLACK = 0,
        RED = 1,
        GREEN = 2,
        YELLOW = 3,
        BLUE = 4,
        MAGENTA = 5,
        CYAN = 6,
        WHITE = 7
    };
    static const Type All[] = {
            BLACK, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE
    };
}
#endif //MONITOR_COLORS_H
