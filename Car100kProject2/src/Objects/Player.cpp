#include "Player.h"
#include "../../Global.h"
#include "WingPlane.h"

Player::Player(int ID) {
	id = ID;
	position.x = SWID / 2;
	position.y = SHEIG * 4 / 5;
	CollideBox = Box(position.x, position.y, 10, 10);
	width = 32;
	height = 48;
	if (ID == 0) {
		speed.x = 4.5;
		speed.y = 4.5;
		life = 3;
	}else if (ID == 1) {
		speed.x = 5;
		speed.y = 5;
		life = 2;
	}
	else {
		life = 3;
	}
}

void Player::setWingPlane(WingPlane* wp) {
	wingplane = wp;
}

void Player::Render() {
	static int mahojinAngle = 0;
	SDL_Rect dest2;
	dest2.x = position.x - 32;
	dest2.y = position.y - 32;
	dest2.w = 64;
	dest2.h = 64;
	SDL_Point sp = { position.x,position.y };
	SDL_RenderCopyEx(renderer, etama2, &jikiMahoujin[1], &dest2, mahojinAngle, NULL, SDL_FLIP_NONE);
	SDL_RenderCopyEx(renderer, etama2, &jikiMahoujin[0], &dest2, -mahojinAngle, NULL, SDL_FLIP_NONE);
	SDL_Rect dest;
	dest.x = position.x - 16;
	dest.y = position.y - 24;
	dest.w = 32;
	dest.h = 48;
	SDL_RenderCopy(renderer, player, &playerAnimation[0][0], &dest);
	wingplane->Render();
	mahojinAngle += 6;
}

void Player::Update(double elapsedTime) {
	const Uint8* states = SDL_GetKeyboardState(NULL);
	if (states[SDL_SCANCODE_LSHIFT]) {
			if (states[SDL_SCANCODE_LEFT]) {
				position.x -= 2;
			}
			else if (states[SDL_SCANCODE_RIGHT]) {
				position.x += 2;
			}

			if (states[SDL_SCANCODE_UP]) {
				position.y -= 2;
			}
			else if (states[SDL_SCANCODE_DOWN]) {
				position.y += 2;
			}
	}
	else {
		if (states[SDL_SCANCODE_LEFT]) {
			position.x -= speed.x;
		}
		else if (states[SDL_SCANCODE_RIGHT]) {
			position.x += speed.x;
		}

		if (states[SDL_SCANCODE_UP]) {
			position.y -= speed.y;
		}
		else if (states[SDL_SCANCODE_DOWN]) {
			position.y += speed.y;
		}
	}
	if (states[SDL_SCANCODE_Z]) {
		isShoot = true;
	}else {
		isShoot = false;
	}

	if (isShoot) {
		if (wingplane->delayShootTime <= 0)wingplane->Shoot();
		wingplane->isShoot = true;
	}

	CollideBox.setX(position.x);
	CollideBox.setY(position.y);
	wingplane->Update(elapsedTime);
}

void Player::decLife() {
	if (--life == 0) {
		isAlive = false;
	}
}