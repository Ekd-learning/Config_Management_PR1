#ifndef EMULATOR_HPP
#define EMULATOR_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

class Emulator {
private:
    sf::RenderWindow window;
    sf::Font font;
    sf::Text displayText;
    std::string currentInput;
    std::string history;

    static constexpr unsigned int WINDOW_WIDTH = 800;
    static constexpr unsigned int WINDOW_HEIGHT = 600;

    void processCommand(const std::string& commandStr);

public:
    Emulator();
    void run();
};

#endif // EMULATOR_HPP