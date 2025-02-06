#include "Enemy1Manager.h"

void Enemy1Manager::creerEnemy1(int x, int y)
{
	unique_ptr<Enemy1> p = make_unique<Enemy1>(Vector2f(x, y));
	p->loadTexture();
	p->sprite.setPosition(x, y);
}

void Enemy1Manager::detruireEnemy1(unique_ptr<Enemy1>& enemy)
{
	auto it = std::find_if(enemy1.begin(), enemy1.end(),
		[&enemy](const std::unique_ptr<Enemy1>& p) { return p.get() == enemy.get(); });

	if (it != enemy1.end()) {
		enemy1.erase(it);
	}
}
