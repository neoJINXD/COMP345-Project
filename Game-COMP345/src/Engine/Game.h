#pragma once

#ifdef _DEBUG
#define new new( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/OpenGL.hpp>

#include <stack>
#include <map>

#include "GameStateSystem/GameState.h"
#include "GameStateSystem/MenuState.h"

namespace engine
{
    class Game {
    private:
          const int HEIGHT = 1280;
          const int WIDTH = 720;
          const sf::Color background = sf::Color::Black;

          sf::RenderWindow *win;
          sf::Event pollingEvnt;

          // time elapsed for framerate independance
          sf::Clock dtClock;
          float dt;

          std::stack<statesystem::State*> states;

          std::map<std::string, int> validKeys;

          void init();
 

    public:

          Game();
          ~Game();


          void quitWindow();

          void update();
          void render();

          void loop();
    };

}
