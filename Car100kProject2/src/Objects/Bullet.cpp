#include "Bullet.h"
#include "../../Global.h"

Bullet::Bullet(int type, int color, Vector2 position, Vector2 speed, Vector2 acceleration,int angle,bool isOwn) {
	this->type = type;
	this->color = color;
	this->position = position;
	this->speed = speed;
	this->acceleration = acceleration;
	counter = 0;
	this->angle = angle;
	this->isOwn = isOwn;
	if (type <= BULLET_TYPE_TAMA) {
		HEI = WID = 16;
		halfH = halfW = WID / 2;
		collideBox = Box(position.x, position.y, 4, 4);
	}
	else if (type == BULLET_TYPE_HEART) {
		HEI = WID = 64;
		halfH = halfW = WID / 2;
		collideBox = Box(position.x, position.y, 10, 10);
	}
	else if (type == BULLET_TYPE_BAREI) {
		HEI = WID = 128;
		halfH = halfW = WID / 2;
		collideBox = Box(position.x, position.y, 28, 28);
	}
	
}

/*Bullet:: ~Bullet() {
	delete this;
	printf("A Instance has been deleted");
}*/

void Bullet::Render() {
	SDL_Rect dest;
	dest.x = position.x - halfW;
	dest.y = position.y - halfH;
	dest.w = WID;
	dest.h = HEI;
	static double i = 0;
	if (type == BULLET_TYPE_STAR) {
		SDL_RenderCopyEx(renderer, bullet01, &bulletSprites01[type][color], &dest, i, NULL, SDL_FLIP_NONE);
		i += 2;
	}
	else if(type <= BULLET_TYPE_TAMA){
		SDL_RenderCopyEx(renderer, bullet01, &bulletSprites01[type][color], &dest, angle, NULL, SDL_FLIP_NONE);
	}
	else if (type == BULLET_TYPE_HEART) {
		SDL_RenderCopyEx(renderer, bullet02, &heartBullets[color], &dest, angle, NULL, SDL_FLIP_NONE);
	}
	else if (type == BULLET_TYPE_BAREI) {
		SDL_RenderCopyEx(renderer, bullet02, &bareiBullets[color], &dest, angle, NULL, SDL_FLIP_NONE);
	}
}

void Bullet::Update() {
	int p = 0;
	if(bulletEvents!=NULL)bulletEvents(counter,this);
	position.x += speed.x;
	position.y += speed.y;
	speed.x += acceleration.x;
	speed.y += acceleration.y;

	if (position.x < -50 || position.y < -50 || position.x>1330 || position.y>1050)isAlive = false;
	collideBox.setX(position.x);
	collideBox.setY(position.y);
	counter++;
}

void Bullet::setEventGroup(std::function<bool(int,Bullet*)> bulletEvent) {
	this->bulletEvents = bulletEvent;
}

/*
void PlayerAimedBullet01::Update() {

	if (counter == 45) {
		angle = math.GetAngleWithPlayer(position);
		speed = math.GetSpeedWithAngle(angle, 0);
	}
	else if (counter == 90) {
		angle = math.GetAngleWithPlayer(position);
		speed = math.GetSpeedWithAngle(angle, 1.5);
	}

	position.x += speed.x;
	position.y += speed.y;
	speed.x += acceleration.x;
	speed.y += acceleration.y;
	if (position.x < -50 || position.y < -50 || position.x>1330 || position.y>770)isAlive = false;
	collideBox.setX(position.x);
	collideBox.setY(position.y);
	counter++;
}
*/