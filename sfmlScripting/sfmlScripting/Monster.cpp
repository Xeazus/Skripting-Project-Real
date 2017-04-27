#include "Monster.h"

Monster::Monster()
{
	this->monsterSize = { 128, 128 };
	this->monster = sf::RectangleShape(monsterSize);
	this->monster.setPosition(128, 512);
	this->monster.setFillColor(sf::Color::Black);
	
	//middlepoint
	this->middlePoint = this->monster.getPosition();
	this->middlePoint.x += this->monsterSize.x * 0.5;
	this->middlePoint.y += this->monsterSize.y * 0.5;

	//hitboxs
	//Samma som monstret
	this->hitbox.setPosition(this->monster.getPosition());
	this->hitbox.setOrigin(sf::Vector2f(this->monster.getPosition()));
	this->hitbox.setSize(sf::Vector2f(128, 128));

	//debug
	this->debugMidPoint.setRadius(10);
	this->debugMidPoint.setFillColor(sf::Color::Red);
}

Monster::~Monster()
{

}

void Monster::update(Character& character)
{
	if (character.getMoved() == true)
	{
		this->move(character);
		character.setMoved(false);
	}
}

void Monster::move(Character& character)
{
	velocity = { 0, 0 };

	//sf::Vector2f 

	int moveNumber = rand() % 4 + 1;

	switch (moveNumber)
	{
	case 1: 
		velocity.y -= 128;
		break;
	case 2:
		velocity.y += 128;
		break;
	case 3:
		velocity.x -= 128;
		break;
	case 4:
		velocity.x += 128;
		break;
	}

	//S�tter monstrets nya position
	this->monster.move(velocity);

	//hitbox
	this->hitbox.move(velocity);
	this->hitbox.setPosition(hitbox.getPosition());
	this->hitbox.updateHitboxDrawable();

	this->updateMiddlePoint();
}

void checkIfCanAttack()
{
	//position - charact�r position vector kolla dens l�ngd
}

void Monster::draw(sf::RenderTarget &target, sf::RenderStates states)const
{
	target.draw(this->hitbox);
	target.draw(this->monster);
	target.draw(this->debugMidPoint);
}

void Monster::updateMiddlePoint()
{
	this->middlePoint = this->monster.getPosition();
	this->middlePoint.x += this->monsterSize.x * 0.5;
	this->middlePoint.y += this->monsterSize.y * 0.5;

	this->debugMidPoint.setPosition(this->middlePoint - sf::Vector2f(this->debugMidPoint.getRadius(), this->debugMidPoint.getRadius()));
}


sf::RectangleShape Monster::getMonster()
{
	return this->monster;
}

Hitbox Monster::getHitbox()
{
	return this->hitbox;
}

sf::FloatRect Monster::getBoundingBox()
{
	return monster.getGlobalBounds();
}
