#include <SFML/Graphics.hpp>
#include <vector>
#include "Animation.h"

void AnimationHandler::update(const float dt)
{
	if (currentAnim >= this->animations.size() || currentAnim < 0)
	{
		return ;
	}

	float duration = this->animations[currentAnim].duration;

	/*check animation frame*/
	if (int((time + dt) / duration) > int(time / duration))
	{
		/*Frame Number*/
		int frame = int((time + dt) / duration);

		/*Looping*/
		frame %= this->animations[currentAnim].getLength();

		/*Settting Sprite*/
		sf::IntRect rect = this->frameSize;

		rect.left = rect.width * frame;
		rect.top = rect.height * this->currentAnim;
		this->bounds = rect;
	}

	/*Time Elapsed*/
	this->time += dt;

	/*Looping*/
	if (this->time > duration * this->animations[currentAnim].getLength())
	{
		this->time = 0.0f;
	}

	return;
}

void AnimationHandler::addAnim(Animation& anim)
{
	this->animations.push_back(anim);
	
	return;
}

void AnimationHandler::changeAnim(int animID)
{
	/*Checks for Current Animation Active or non-existant*/
	if (this->currentAnim == animID || animID >= this->animations.size() || animID < 0)
	{
		return;
	}

	/*Set Animation*/
	this->currentAnim = animID;

	/*Update Animation frames*/
	sf::IntRect rect = this->frameSize;

	rect.top = rect.height *animID;
	this->bounds = rect;
	this->time = 0.0f;

	return;
}