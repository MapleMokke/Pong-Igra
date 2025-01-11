#ifndef START_SCREEN_H
#define START_SCREEN_H

#include "screen.hpp"

class StartScreen : public Screen {
public:
    StartScreen() = default;
    void Draw() override;
};


#endif // !START_SCREEN_H
