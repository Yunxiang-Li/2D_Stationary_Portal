#include "Game.h"

#include <raylib.h>

// Game screen size(after game size is updated according to factor.
static constexpr unsigned int GAME_SCREEN_WIDTH   { 672 };
static constexpr unsigned int GAME_SCREEN_HEIGHT  { 864 };

static constexpr unsigned int GAME_FPS            { 60  };

Game& Game::getInstance()
{
    static Game instance;
    return instance;
}

bool Game::init()
{
    // Intialize game window and set game frame rate.
    InitWindow(  GAME_SCREEN_WIDTH,  GAME_SCREEN_HEIGHT, "Bullet Hell" );
    SetTargetFPS( GAME_FPS );

    // Load all art resources.
    m_resourceManagerRef.LoadAllSpriteSheets();

    return true;
}

void Game::update()
{
    // Main game loop
    while( !WindowShouldClose() )
    {
        // Retrieve time between last frame.
        const float deltaTime = GetFrameTime();
    }
}

bool Game::shutdown()
{
    // Close the game window safely.
    CloseWindow();

    return true;
}