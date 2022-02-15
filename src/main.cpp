#include <TGUI/TGUI.hpp>

int main()
{
    sf::RenderWindow window{{800, 600}, "TGUI window with SFML", sf::Style::None}; // <- Important!! Style=None removes title

    sf::Vector2i grabbedOffset;
    bool grabbedWindow = false;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Escape)
                    window.close();
            }
            else if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    grabbedOffset = window.getPosition() - sf::Mouse::getPosition();
                    grabbedWindow = true;
                }
            }
            else if (event.type == sf::Event::MouseButtonReleased)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                    grabbedWindow = false;
            }
            else if (event.type == sf::Event::MouseMoved)
            {
                if (grabbedWindow)
                    window.setPosition(sf::Mouse::getPosition() + grabbedOffset);
            }
        }
        window.clear(sf::Color::Red);
        window.display();
    }

    tgui::GuiSFML gui{window};
    gui.mainLoop();
}