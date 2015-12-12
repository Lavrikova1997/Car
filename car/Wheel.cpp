#include "Wheel.h"
#include "Const.h"

void iniWheel(Wheel * wheel)
{
	wheel->image = new Image;
	wheel->image->loadFromFile("wheel.png");

	wheel->texture = new Texture;
	wheel->texture->loadFromImage(*(wheel->image));
	wheel->texture->setSmooth(true);

	Vector2f size = Vector2f(wheel->texture->getSize());
	wheel->radius = size.x / 2.f;

	wheel->shape = new RectangleShape;
	wheel->shape->setTexture(wheel->texture);
	wheel->shape->setSize(size);
	wheel->shape->setOrigin(wheel->radius, wheel->radius);
}

void dispWheel(Wheel * wheel)
{
	delete wheel->shape;
	delete wheel->texture;
	delete wheel->image;

	delete wheel;
}

void drawWheel(Wheel * wheel, RenderWindow & window)
{
	window.draw(*(wheel->shape));
}

void updateSpeedWheel(Wheel * wheel, float & speed, float & time)
{
	wheel->rotarySpeed = speed / (wheel->radius * PROPORTION_RADIUS);
}

void rotaryWheel(Wheel * wheel, float & time)
{
	wheel->shape->rotate(wheel->rotarySpeed * time);
}
