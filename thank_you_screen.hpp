#ifndef  THANK_YOU_SCREEN_H
#define THANK_YOU_SCREEN_H

#include "screen.hpp"

class ThankYouScreen : public Screen {
public:
	ThankYouScreen() = default;
	void Draw() override;
};

#endif // ! THANK_YOU_SCREEN_H
