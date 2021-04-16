#include "WingPlane.h"'

WingPlane::WingPlane(int type) {
	maxCount = 8;
	angleSpeed = 1;
	delayTime = 12;
	currentCount = 5;
}

void WingPlane::Render() {
	for (int i = 0; i < currentCount; i++) {
		SDL_Rect dest;
		dest.x = position[i].x - 8;
		dest.y = position[i].y - 7;
		dest.w = 16;
		dest.h = 15;

		SDL_Rect src;
		src.x = 64;
		src.y = 145;
		src.w = 16;
		src.h = 15;
		SDL_RenderCopy(renderer,player,&src, &dest/* angle, NULL, SDL_FLIP_NONE*/);
	}
	bm.renderBullets();
}

void WingPlane::Update(double elapsedTime) {
	for (int i = 0; i < currentCount; i++) {
		position[i].x = pl.position.x + 50*math.Fcos(angle + i * 360 / currentCount);
		position[i].y = pl.position.y + 50*math.Fsin(angle + i * 360 / currentCount);
		angle += angleSpeed;
	}
	if (isShoot) {
		if (delayShootTime > 0) {
			delayShootTime --;
		}
	}
	bm.updateBullets(elapsedTime);
}

void WingPlane::Shoot() {
	delayShootTime = delayTime;
	for (int i = 0; i < currentCount; i++) {
		bm.addBullet(Bullet(BULLET_TYPE_KOTAMA, BULLET_COLOR_SCARLET, position[i], Vector2(0,-8.5), Vector2(0, 0), 0,true));
	}
}