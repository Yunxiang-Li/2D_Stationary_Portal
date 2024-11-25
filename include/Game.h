#pragma once
#ifndef GAME_H
#define GAME_H

#include <memory>
#include <vector>

#include "ResourceManager.h"

/**
 * A singleton indicates the 2d bullet hell game instance.
 */
class Game
{
public:
    // Game instance is unique, thus disable copy constructor and copy assignment operator.
    Game( const Game& ) = delete;
    Game& operator=( const Game& ) = delete;

    // No need for move member functions.
    Game( Game&& ) = delete;
    Game& operator=( Game&& ) = delete;

    /**
     * The only way to create(for the first time) and retrieve the unique instance.
     * @return a reference of game singleton.
     */
    static Game& getInstance();

    /**
     * All initialization work before the game actually starts running.
     * @return A bool indicates if initialization process is successful or not.
     */

    bool init();

    /**
     * Run the main game loop.
     */
    void update();

    /**
     * Clean up all resources and shutdown the game.
     * @return A bool indicates if de-initialization process is successful or not.
     */
    bool shutdown();

private:
    // Hide constructor and destructor.
    Game()  = default;
    ~Game() = default;

    // Store the reference of Component manager, Entity manager, Resource manager, system manager and all systems.
    ResourceManager& m_resourceManagerRef = ResourceManager::getInstance();
};

#endif //GAME_H
