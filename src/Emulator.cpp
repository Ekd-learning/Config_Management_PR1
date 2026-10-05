#define WIN32_LEAN_AND_MEAN
#define NOMINMAX

#include "Emulator.hpp"
#include <iostream>
#include <sstream>

#if defined(_WIN32)
const string fontPath = "C:\\Windows\\Fonts\\arial.ttf";
// #include <windows.h>
#else
    const string fontPath = "/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf";
#endif

using namespace std;

Emulator::Emulator()
    : window(sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "Shell Emulator"),
      displayText(font) 
{
    // if (!font.openFromFile("C:\\Windows\\Fonts\\arial.ttf"))
    if (!font.openFromFile(fontPath))
        cerr << "Could not load font: " << fontPath << endl;
    

    displayText.setCharacterSize(18);
    displayText.setFillColor(sf::Color::Green);
    displayText.setPosition({10.f, 10.f});
}

void Emulator::processCommand(const std::string& commandStr) {
    stringstream ss(commandStr);
    string cmd;
    ss >> cmd;
    vector<string> args;
    string arg;
    while (ss >> arg)
        args.push_back(arg);
    string result = "Executed: " + cmd;
    if (!args.empty()) {
        result += " with args: ";
        for (size_t i = 0; i < args.size(); ++i) {
            result += args[i] + (i + 1 < args.size() ? ", " : "");
        }
    }

    history += "> " + commandStr + "\n" + result + "\n";
    displayText.setString(history + "> " + currentInput);
}

void Emulator::run() {
    while (window.isOpen()) {
        while (const auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
            else if (const auto* textEntered = event->getIf<sf::Event::TextEntered>()) {
                if (textEntered->unicode == '\r' || textEntered->unicode == '\n') {
                    processCommand(currentInput);
                    currentInput.clear();
                } else if (textEntered->unicode == '\b') {
                    if (!currentInput.empty()) {
                        currentInput.pop_back();
                    }
                } else if (textEntered->unicode < 128) {
                    currentInput += static_cast<char>(textEntered->unicode);
                }
                displayText.setString(history + "> " + currentInput);
            }
        }

        window.clear(sf::Color::Black);
        window.draw(displayText);
        window.display();
    }
}