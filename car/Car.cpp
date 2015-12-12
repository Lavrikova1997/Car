#include "Car.h"
#include "Const.h"

void iniCar(Car & car)
{
	car.image = new Image;
	car.image->loadFromFile("car.png");

	car.texture = new Texture;
	car.texture->loadFromImage(*(car.image));
	car.texture->setSmooth(true);

	Vector2f size = Vector2f(car.texture->getSize());

	car.shape = new RectangleShape;
	car.shape->setTexture(car.texture);
	car.shape->setSize(size);

	car.shape->setScale(SCALE_CAR, SCALE_CAR);

	car.rearWheel = new Wheel;
	iniWheel(car.rearWheel);
	car.frontWheel = new Wheel;
	iniWheel(car.frontWheel);

	car.rearWheel->shape->setScale(SCALE_CAR, SCALE_CAR);
	car.frontWheel->shape->setScale(SCALE_CAR, SCALE_CAR);

	car.rearWheel->shape->setPosition(505 * SCALE_CAR, 170 * SCALE_CAR);
	car.frontWheel->shape->setPosition(115 * SCALE_CAR, 170 * SCALE_CAR);

}

void dispCar(Car & car)
{
	dispWheel(car.rearWheel);
	dispWheel(car.frontWheel);

	delete car.shape;
	delete car.texture;
	delete car.image;
}

void drawCar(Car & car, RenderWindow & window)
{
	window.draw(*(car.shape));
	drawWheel(car.rearWheel, window);
	drawWheel(car.frontWheel, window);
}

void updateSpeedCar(Car & car, float & time, bool isAcclrtn = false, bool isDirRigth = false)
{
	if (isAcclrtn && isDirRigth)
	{
		car.speed += car.acceleration * time;
	}
	else if (isAcclrtn && !isDirRigth)
	{
		car.speed -= car.acceleration * time;
	}
	else if (!isAcclrtn)
	{
		if (car.speed > 0)
		{
			car.speed -= car.acceleration * time;
			if (car.speed < 0)
			{
				car.speed = 0;
			}
		}
		else if (car.speed < 0)
		{
			car.speed += car.acceleration * time;
			if (car.speed > 0)
			{
				car.speed = 0;
			}
		}
	}

	updateSpeedWheel(car.frontWheel, car.speed, time);
	updateSpeedWheel(car.rearWheel, car.speed, time);

}

void moveCar(Car & car, float & time)
{
	car.shape->move(car.speed * time, 0 * time);
	car.frontWheel->shape->move(car.speed * time, 0 * time);
	car.rearWheel->shape->move(car.speed * time, 0 * time);

	rotaryWheel(car.frontWheel, time);
	rotaryWheel(car.rearWheel, time);
}

void setPositionCar(Car & car, float x, float y)
{
	car.shape->setPosition(x, y);
	Vector2f pos = car.rearWheel->shape->getPosition();
	car.rearWheel->shape->setPosition(x + pos.x, y + pos.y);
	pos = car.frontWheel->shape->getPosition();
	car.frontWheel->shape->setPosition(x + pos.x, y + pos.y);
}