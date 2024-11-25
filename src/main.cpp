// Main entrance of the 2D Bullet Hell game.

#include <cassert>

#include "Game.h"

int main()
{
    // Initialize the game instance.
    Game& gameRef = Game::getInstance();
    bool isSuccess = gameRef.init();
    assert( isSuccess && "Game initialization failed!" );

    // Main game loop.
    gameRef.run();

	// Clean up all resources and shutdown the game safely.
	isSuccess = gameRef.shutdown();
	assert( isSuccess && "Game shutdown failed!" );

	return 0;
}
