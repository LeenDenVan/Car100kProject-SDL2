#include "BulletManager.h"
#include "../MathHelper.h"
#include "../../Global.h"

BulletManager::BulletManager(){}

void BulletManager::addBullet(Bullet bt) {
	gb.push_back(bt);
}

void BulletManager::renderBullets() {
	for (int i = 0; i < gb.size(); i++) {
		gb[i].Render();
	}
}

void BulletManager::updateBullets(double elapsedTime) {
	for (int i = 0; i < gb.size(); i++) {
		gb[i].Update();
		if (!gb[i].isAlive) { 
			gb.erase(gb.begin() + i); 
			i--;
			continue;
		}

		if (gb[i].collideBox.isCollided(pl.CollideBox)&&!gb[i].isOwn) {
			printf("Biu`+%d\n",i);
			gb.erase(gb.begin() + i);
			i--;
			continue;
		}
	}
	counter++;
}

void BulletManager::shot01SilentSenena() {
#define TM001 60
	int i, k, t = counter % TM001, t2 = counter;
	printf("%d\n", counter);
	static int cnum=0;
	double angle;
	static Vector2 bP;
	if(cnum==0)Vector2 bP = Vector2(SWID / 2, SHEIG / 4);
	if (t == 0) {
		BaseAngle = pl.position.Angle(bP)*PI2RAD;
		if (cnum % 4 == 3) {
			if (bP.x <= SWID / 2 + 355 && bP.y <= SHEIG / 2 + 642) {
				bP.x+=55;
				bP.y+=55;
			}
		}
	}
	if (t == TM001 / 2 - 1) {
		BaseAngle += 360 * 2 / 20 / 2;
	}
	if (t % (TM001 / 10) == 0) {
		angle = pl.position.Angle(Vector2(SWID / 2, SHEIG / 4));
		for (int i = 0; i < 20; i++) {
			addBullet(Bullet(BULLET_TYPE_HARI, BULLET_COLOR_PINK, bP, math.GetSpeedWithAngle(BaseAngle+360*2/20*i, 250), Vector2(0, 0), 0,false));
		}
	}
	if (t % 2 == 0) {
			addBullet(Bullet(BULLET_TYPE_STAR, BULLET_COLOR_WHITE, math.GetRandomPosition(0, SWID, 0, 200),math.GetSpeedWithAngle(90,math.GetRandomInt(100,300)), Vector2(0, 0), 0,false));
	}
	if (t == TM001 - 1)
		cnum++;
	printf("%d\n", t);
}

void BulletManager::shot02() {
#define TM002 150
	static int cnum;
	int t = counter % TM002, t2 = counter;
	if (t >= 0 && t <= 150 && t % 10 == 0) {
		for (int i = 0; i < 20; i++) {
			addBullet(Bullet(BULLET_TYPE_RINTAMA, BULLET_COLOR_BLUE, Vector2(SWID / 4 + math.Fsin(360 / 2 + 360 / 150 * t) * 100, SHEIG / 4 + math.Fcos(360 / 2 + 360 / 150 * t) * 100), math.GetSpeedWithAngle(360 * 2 / 20 * i, 2.5),Vector2(0,0),0,false));
		}
		for (int i = 0; i < 20; i++) {
			addBullet(Bullet(BULLET_TYPE_RINTAMA, BULLET_COLOR_YELLOW, Vector2(SWID / 4 + math.Fsin(360 / 2 - 360 / 150 * t) * 100, SHEIG / 4 + math.Fcos(360 / 2 - 360 / 150 * t) * 100), math.GetSpeedWithAngle(360 * 2 / 20 * i, 2.5), Vector2(0, 0), 0,false));
		}
	}
	
}

void BulletManager::HorizonOfWaveAndParticles() {
	static int i = 0;
	if (i < 100000&&i%2==0) {

		for (int j = 0; j < 5; j++) {
			double angle = i * i / 2600.0 + j *0.4* 180 - 0.5 * 180;
			addBullet(Bullet(BULLET_TYPE_KOTAMA, BULLET_COLOR_PURPLE, Vector2(halfXInGamePlaySpace, SHEIG / 2), math.GetSpeedWithAngle(angle, 4.0), Vector2(0, 0), angle, false));
		}
	}
	i++;
}

void BulletManager::shot03() {
	static int frames = 0;
	static int r = 0;
	static int b = 250;
	static int a = r;
	static int bb = b;
	if (frames <= 210 && frames>= 60) {
		
		if (frames % 2 == 0) {
			a = r;
			bb = b;
			for (int i = 0; i < 8; i++) {
				addBullet(Bullet(BULLET_TYPE_SATSU, BULLET_COLOR_BLUE, Vector2(halfXInGamePlaySpace +b * math.Fcos(a),SHEIG/4+ b * math.Fsin(a)), math.GetSpeedWithAngle(a - 60, 2), Vector2(0, 0), a-60,false));
				addBullet(Bullet(BULLET_TYPE_SATSU, BULLET_COLOR_RED, Vector2(halfXInGamePlaySpace +b * math.Fcos(a), SHEIG / 4 + b * math.Fsin(a)), math.GetSpeedWithAngle(a+60,2), Vector2(0, 0), a+60,false));
				a += 45;
			}
			r += 6;
			b--;
		}
	}
	else if (frames == 210) {
		r = 0;
		b = 175;
	}else if (frames > 210 && (frames - 210) % 3 == 0) {
		a = r;
		for (int i = 0; i < 8; i++) {
			addBullet(Bullet(BULLET_TYPE_SATSU, BULLET_COLOR_BLUE, Vector2(halfXInGamePlaySpace + b * math.Fcos(a), SHEIG / 4 + b * math.Fsin(a)), math.GetSpeedWithAngle(a - 60, 2), Vector2(0, 0), a - 60,false));
			addBullet(Bullet(BULLET_TYPE_SATSU, BULLET_COLOR_RED, Vector2(halfXInGamePlaySpace+ b * math.Fcos(a), SHEIG / 4 + b * math.Fsin(a)), math.GetSpeedWithAngle(a + 60, 2), Vector2(0, 0), a + 60,false));
			a += 45;
		}
		r += 6;
	}
	static int t = 0;
	if (frames >= 60) {
		if (frames % 120 > 60) {
			if (frames % 10 == 0 && t < 5) {
				for (int i = 0, ah = -64; i < 17; i++, ah += 8) {
					Bullet tmp = Bullet(BULLET_TYPE_UROKO, BULLET_COLOR_SCARLET, Vector2(halfXInGamePlaySpace, SHEIG / 4), math.GetSpeedWithAngle(math.GetAngleWithPlayer(Vector2(SWID / 2, SHEIG / 4)) + ah + 180, 3), Vector2(0, 0),270+(int)math.GetAngleWithPlayer(Vector2(SWID / 2, SHEIG / 4)) + ah,false);
					//printf("%f\n",math.GetAngleWithPlayer(Vector2(halfXInGamePlaySpace, SHEIG / 4)));
					tmp.setEventGroup([ah](int f, Bullet* bt)->bool {
						if (f == 45) {
							bt->speed.x = 0;
							bt->speed.y = 0;
							bt->angle = 270 + (int)math.GetAngleWithPlayer(Vector2(halfXInGamePlaySpace, SHEIG / 4)) + ah;
							bt->type = BULLET_TYPE_CHAIN;
							bt->color = BULLET_COLOR_BLUE;
							return true;
						}else if (f == 90) {
							bt->speed = math.GetSpeedWithAngle(math.GetAngleWithPlayer(Vector2(halfXInGamePlaySpace, SHEIG / 4)) + ah + 180, 1.5);
							bt->angle = 270 + (int)math.GetAngleWithPlayer(Vector2(halfXInGamePlaySpace, SHEIG / 4)) + ah;
							return true;
						}
						else {
							return false;
						}
						});
					addBullet(tmp);
				}
			}
			t++;
			if (t == 5)t = 0;
		}
	}
	frames++;
}