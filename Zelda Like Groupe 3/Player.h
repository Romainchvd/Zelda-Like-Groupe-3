#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

using namespace sf;
using namespace std;

class Player {
private :
	static unique_ptr<Player>player;
    Player(); 
public:
    static unique_ptr<Player> & getInstance() {
        if (!player) {
            player = make_unique<Player>();
        }
        return player;
    }
};
unique_ptr<Player> Player::player = nullptr;


#endif