#pragma once
#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include "raylib.h"

#include <memory>

/**
 * A high level singleton resource manager to load/unload all game resources.
 */
class ResourceManager {
public:
    // ResourceManager instance is unique, thus disable copy constructor and copy assignment operator.
    ResourceManager( const ResourceManager& ) = delete;
    ResourceManager& operator=( const ResourceManager& ) = delete;

    // No need for move member functions.
    ResourceManager( ResourceManager&& ) = delete;
    ResourceManager& operator=( ResourceManager&& ) = delete;

    // The only way to create(for the first time) and retrieve the unique instance.
    static ResourceManager& getInstance();

    /**
     * Load and store all sprite sheets.
     */
    void LoadAllSpriteSheets();

    /**
     * Retrieve the pointer of bullets' sprite sheet.
     * @return A shared pointer of bullets' sprite sheet
     */
    std::shared_ptr<Texture2D> GetBulletsSpriteSheet() const;

    /**
    * Retrieve the pointer of player's sprite sheet.
    * @return A shared pointer of player's sprite sheet
    */
    std::shared_ptr<Texture2D> GetPlayerSpriteSheet() const;

    /**
     * Store the sprite sheet of bullets with a shared pointer.
     * @param bulletsSpriteSheet a reference of the sprite sheet of bullets
     */
    void SetBulletsSpriteSheet( const Texture2D& bulletsSpriteSheet );

     /**
     * Store the sprite sheet of the player with a shared pointer.
     * @param playerSpriteSheet a reference of the sprite sheet of the player
     */
    void SetPlayerSpriteSheet( const Texture2D& playerSpriteSheet );

private:
    // Hide constructor and destructor.
    ResourceManager() = default;
    ~ResourceManager() = default;

    std::shared_ptr<Texture2D> m_bulletsSpriteSheet_ptr; // Store textures for each kind of bullet.
    std::shared_ptr<Texture2D> m_playerSpriteSheet_ptr; // Store textures for the player.
};

#endif //RESOURCE_MANAGER_H
