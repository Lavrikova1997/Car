#include <SFML/Graphics.hpp>
#include "Car.h"

using namespace sf;

int main()
{
	RenderWindow window(sf::VideoMode(700, 500), "car");
	Car car;
	iniCar(car);
	setPositionCar(car, 350, 250);
	bool isAclrtn = false;
	bool isDirRigth = false;

	Clock clock;
	float time = 0.f;

	while (window.isOpen())
	{
		time = clock.restart().asSeconds();
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			if (Keyboard::isKeyPressed(Keyboard::Left))
			{
				isAclrtn = true;
				isDirRigth = false;
			}
			else if (Keyboard::isKeyPressed(Keyboard::Right))
			{
				isAclrtn = true;
				isDirRigth = true;
			}
			else
			{
				isAclrtn = false;
				isDirRigth = false;
			}
		}

		updateSpeedCar(car, time, isAclrtn, isDirRigth);
		moveCar(car, time);

		window.clear();
		drawCar(car, window);
		window.display();
	}

	dispCar(car);
	return 0;
}