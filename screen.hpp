#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include <string>
#include <vector>
#include <Windows.h> //koristenje HANDLE
using namespace std;

class Screen {
protected:
    HANDLE consoleHandle;

    void clearScreen() const {
        system("cls");
    }

    void printCentered(const string& text) const;

public:
    Screen();
    virtual void Draw() = 0; // Èista virtualna funkcija za ispis
};

#endif // !SCREEN_H
