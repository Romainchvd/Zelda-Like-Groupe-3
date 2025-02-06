#include "Enemy2Manager.h"

void Enemy2Manager::creerEnemy2(int x, int y)
{
	unique_ptr<Enemy2> p = make_unique<Enemy2>(Vector2f(x, y));
	p->loadTexture();
	p->sprite.setPosition(x, y);
}

void Enemy2Manager::detruireEnemy2(unique_ptr<Enemy2>& enemy)
{
	auto it = std::find_if(enemy2.begin(), enemy2.end(),
		[&enemy](const std::unique_ptr<Enemy2>& p) { return p.get() == enemy.get(); });

	if (it != enemy2.end()) {
		enemy2.erase(it);
	}
}
