#include "GameState.h"
#include <stdio.h>
#include "EndState.h"

void statesystem::GameState::initKeybinds()
{
	keybinds["CLOSE"] = validKeys->at("Escape");
	keybinds["MOVE_UP"] = validKeys->at("W");
	keybinds["MOVE_LEFT"] = validKeys->at("A");
	keybinds["MOVE_DOWN"] = validKeys->at("S");
	keybinds["MOVE_RIGHT"] = validKeys->at("D");
	keybinds["END"] = validKeys->at("P");

}

statesystem::GameState::GameState(sf::RenderWindow* _win, std::map<std::string, int>* _validKeys, std::stack<State*>* _states) : State(_win, _validKeys, _states)
{
	initKeybinds();
}

statesystem::GameState::~GameState()
{
}

void statesystem::GameState::updateInputs(const float& dt)
{
	checkEnd();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keybinds.at("MOVE_RIGHT"))))
		player.move(dt, 1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keybinds.at("MOVE_LEFT"))))
		player.move(dt, -1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keybinds.at("MOVE_UP"))))
		player.move(dt, 0.f, -1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keybinds.at("MOVE_DOWN"))))
		player.move(dt, 0.f, 1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keybinds.at("END"))))
		states->push(new statesystem::EndState(win, validKeys, states));

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		printf("Left mouse\n");
}

void statesystem::GameState::quit()
{
	printf("Ending inGame state\n");
}

void statesystem::GameState::update(const float& dt)
{
	updateMousePos();
	updateInputs(dt);
	player.update(dt);
	//std::cout << "We In the game" << std::endl;
	//printf("We in the game with %f power\n", dt);
}

void statesystem::GameState::render(sf::RenderTarget* target)
{
	// render all items
	if (!target)
		target = win;
	player.render(target);
}
