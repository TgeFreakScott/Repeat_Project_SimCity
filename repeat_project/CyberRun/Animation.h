#ifndef ANIMATION
#define ANIMATION

#include <SFML/Graphics.hpp>
#include <vector>

class Animation
{

public:

	int startFrame;
	int endFrame;

	float duration;

	Animation(int startFrame, int endFrame, float duration)
	{
		this->startFrame = startFrame;
		this->endFrame = endFrame;
		this->duration = duration;
	}

	int getLength() 
	{ 
		return endFrame - startFrame + 1;
	}

};

class AnimationHandler
{
private:

	/* Array of animations */
	std::vector<Animation> animations;

	/* Current time since the animation loop started */
	float time;
	int currentAnim;

public:


	void update(const float dt);

	/* Add a new animation */
	void addAnim(Animation& anim);

	/* Change the animation */
	void changeAnim(int animNum);

	/* Displayed section of texture */
	sf::IntRect bounds;

	/* Frame Size*/
	sf::IntRect frameSize;

	AnimationHandler()
	{
		this->time = 0.0f;
		this->currentAnim = -1;
	}

	AnimationHandler(const sf::IntRect& frameSize)
	{
		this->frameSize = frameSize;

		this->time = 0.0f;
		this->currentAnim = -1;
	}
};

#endif /* ANIMATION */