#include "Game.h"

void engine::Game::init()
{
	win = new sf::RenderWindow(sf::VideoMode(HEIGHT, WIDTH), "Title", sf::Style::Close | sf::Style::Titlebar);

    validKeys["Escape"] = sf::Keyboard::Key::Escape;
    validKeys["W"] = sf::Keyboard::Key::W;
    validKeys["A"] = sf::Keyboard::Key::A;
    validKeys["S"] = sf::Keyboard::Key::S;
    validKeys["D"] = sf::Keyboard::Key::D;
    validKeys["P"] = sf::Keyboard::Key::P;

    //states.push(new statesystem::GameState(win, &validKeys, &states));
    states.push(new statesystem::MenuState(win, &validKeys, &states));
}

engine::Game::Game() 
{
	init();
}

engine::Game::~Game() 
{
	delete win;
	win = nullptr;

    while (!states.empty())
    {
        delete states.top();
        states.pop();

    }
}


void engine::Game::quitWindow()
{
    printf("Ending Program\n");
}

void engine::Game::update()
{
    // polling sfml events
    while (win->pollEvent(pollingEvnt)) {
        if (pollingEvnt.type == sf::Event::Closed) {
            win->close();
        }
    }
    if (!states.empty())
    {
        states.top()->update(dt);
        if (states.top()->getEnd())
        {
            states.top()->quit();
            delete states.top();
            states.pop();
        }
    }
    else {
        quitWindow();
        win->close();
    }
}

void engine::Game::render()
{
    // clears current buffer
    win->clear(background);

    // render items
    //win.draw(triangle);
    if (!states.empty())
        states.top()->render(win);

    // swaps buffers
    win->display();
}

void engine::Game::loop()
{
    while (win->isOpen()) {
        dt = dtClock.restart().asSeconds();
        update();
        render();
    }
}


