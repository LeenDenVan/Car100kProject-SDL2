#ifndef BULLETMANAGER_H_
#define BULLETMANAGER_H_

#include "../Objects/Bullet.h"
#include <vector>

class BulletManager {
public:
	BulletManager();
	void addBullet(Bullet bl);
	void renderBullets();
	void updateBullets(double elapsedTime);

	void shot01SilentSenena();
	void shot02();
	void HorizonOfWaveAndParticles();
	void shot03();

private:
	int counter = 0;
	double BaseAngle;
	std::vector<Bullet> gb;
	//std::vector<BulletManager> bms;
};

#endif
