#include "MenuState.h"
#include <stdio.h>
#include "GameState.h"

void statesystem::MenuState::initKeybinds()
{
	keybinds["CLOSE"] = validKeys->at("Escape");
}

void statesystem::MenuState::init()
{
	
	if (!background.loadFromFile("./src/Files/textures/newhaven.jpg"))
	{
		printf("ERROR::MENUSTATE - FAILED TO LOAD IMAGE");
		exit(-1);
	}
	bgd.setTexture(&background);

	float middle = win->getSize().x / 2.f;

	//button initializations
	buttons["TEST"] = new ui::Button(100, 100, 1150, 50, &font, "");
	buttons["TEST"]->setTransparent();
	buttons["EXIT"] = new ui::Button(middle, 650, 150, 50, &font, "EXIT", ui::CENTER);
	buttons["PLAY"] = new ui::Button(middle, 590, 250, 50, &font, "Enter the Game", ui::CENTER);
	
	//text initializations
	texts["TITLE"] = new ui::Text(200, 300, "New Haven", &font, ui::CENTER);
	texts["TITLE"]->setColor(sf::Color::White);
	texts["TITLE"]->setCharSize(120);
}

statesystem::MenuState::MenuState(sf::RenderWindow* _win, std::map<std::string, int>* _validKeys, std::stack<State*>* _states) : State(_win, _validKeys, _states)
{
	bgd.setSize(sf::Vector2f(win->getSize()));
	bgd.setFillColor(sf::Color::White);

	initKeybinds();
	init();
}

statesystem::MenuState::~MenuState()
{

	for (auto &i : buttons)
	{
		delete i.second;
	}
	for (auto& i : texts)
	{
		delete i.second;
	}
}

void statesystem::MenuState::updateInputs(const float& dt)
{
	checkEnd();


	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		printf("Left mouse\n");
}

void statesystem::MenuState::quit()
{
	printf("Ending Menu state\n");
}

void statesystem::MenuState::update(const float& dt)
{
	updateMousePos();
	updateInputs(dt);

	for (auto &i : buttons)
	{
		i.second->update(mousePosView);
	}

	if (buttons["EXIT"]->isPressed())
		ended = true;
		
	if (buttons["PLAY"]->isPressed())
		states->push(new statesystem::GameState(win, validKeys, states));

	printf("We In the menu\n");
	printf("We have ScreenPos (%i, %i)\nWe have WindowPos (%i, %i)\nWe have ViewPos (%i, %i)\n",
		mousePosScreen.x,
		mousePosScreen.y,
		mousePosWindow.x,
		mousePosWindow.y,
		mousePosView.x,
		mousePosView.y);
	system("cls");
}

void statesystem::MenuState::render(sf::RenderTarget* target)
{
	// render all items
	if (!target)
		target = win;
	target->draw(bgd);
	for (auto &i : buttons)
	{
		i.second->render(target);
	}
	for (auto& i : texts)
	{
		i.second->render(target);
	}
}
