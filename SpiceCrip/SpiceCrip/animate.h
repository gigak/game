//#ifndef ANIM_H
#define ANIM_H

#include <SFML/Graphics.hpp>
using namespace sf;

class Animation

{
public:
	std::vector<IntRect> frames, frames_flip;
	float currentFrame, speed;
	bool flip, isPlaying;
	Sprite sprite;

	Animation(Texture &t, int x, int y, int w, int
