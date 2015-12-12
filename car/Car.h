#pragma once
#include <SFML/Graphics.hpp>
#include "Wheel.h"

using namespace sf;

struct Car
{
	RectangleShape * shape;
	Image * image;
	Texture * texture;

	Wheel * rearWheel;
	Wheel * frontWheel;

	float speed = 0.f;
	const float acceleration = 2.f;
};


void iniCar(Car & car);

void dispCar(Car & car);

void drawCar(Car & car, RenderWindow & window);

void updateSpeedCar(Car & car, float & time, bool isAcclrtn, bool isDirRigth);

void moveCar(Car & car, float & time);

void setPositionCar(Car & car, float x, float y);