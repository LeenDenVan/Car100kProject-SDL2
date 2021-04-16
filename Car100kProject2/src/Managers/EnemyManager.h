#ifndef ENEMY_MAN_H_
#define ENEMY_MAN_H_

#include <vector>
#include "../Objects/Enemy.h"

class EnemyManager {
public:
	EnemyManager() {}
	void addEnemy(Enemy em);
	void Update(double elapsedTime);
	void Render();

private:
	std::vector<Enemy> ens;
};

#endif