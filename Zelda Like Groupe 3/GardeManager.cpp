#include "GardeManager.h"

void GardeManager::creerGarde(int x, int y)
{
	unique_ptr<Garde> p = make_unique<Garde>(Vector2f(x, y));
	p->loadTexture();
	p->sprite.setPosition(x, y);
}

void GardeManager::detruireGarde(unique_ptr<Garde>& enemy)
{
	auto it = std::find_if(garde.begin(), garde.end(),
		[&enemy](const std::unique_ptr<Garde>& p) { return p.get() == enemy.get(); });

	if (it != garde.end()) {
		garde.erase(it);
	}
}
