#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

struct Wheel
{
	RectangleShape * shape;
	Image * image;
	Texture * texture;

	float radius = 1.f;
	float rotarySpeed = 0.f;
};

void iniWheel(Wheel * wheel);

void dispWheel(Wheel * wheel);

void drawWheel(Wheel * wheel, RenderWindow & window);

void updateSpeedWheel(Wheel * wheel, float & speed, float & time);

void rotaryWheel(Wheel * wheel, float & time);


