#include "ResourceManager.h"

ResourceManager& ResourceManager::getInstance()
{
    static ResourceManager instance;
    return instance;
}

void ResourceManager::LoadAllSpriteSheets()
{
    // Load images in CPU memory (RAM)
    Image playerImage = LoadImage( ASSETS_PATH"/SpriteSheets/Characters/bllm.png" );
    Image bulletsImage = LoadImage( ASSETS_PATH"/SpriteSheets/Bullets/bulletNew1.png" );

    // Convert images into textures, GPU memory (VRAM)
    Texture2D playerTexture = LoadTextureFromImage( playerImage );
    Texture2D bulletsTexture = LoadTextureFromImage( bulletsImage );

    // Store related textures
    SetPlayerSpriteSheet( playerTexture );
    SetBulletsSpriteSheet( bulletsTexture );

    // Once image has been converted to texture and uploaded to VRAM, it can be unloaded
    UnloadImage( playerImage );
    UnloadImage( bulletsImage );
}

std::shared_ptr<Texture2D> ResourceManager::GetBulletsSpriteSheet() const
{
    return m_bulletsSpriteSheet_ptr;
}

std::shared_ptr<Texture2D> ResourceManager::GetPlayerSpriteSheet() const
{
    return m_playerSpriteSheet_ptr;
}

void ResourceManager::SetBulletsSpriteSheet( const Texture2D& bulletsSpriteSheet )
{
    m_bulletsSpriteSheet_ptr = std::make_shared<Texture2D>( bulletsSpriteSheet );
}

void ResourceManager::SetPlayerSpriteSheet( const Texture2D& playerSpriteSheet )
{
    m_playerSpriteSheet_ptr = std::make_shared<Texture2D>( playerSpriteSheet );
}

