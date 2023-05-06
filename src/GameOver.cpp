
#include "GameOver.hpp"
#include "KeyboardInput.hpp"
#include "TextureManager.hpp"
#include "Engine.hpp"

GameOver* GameOver::s_Instance = nullptr;

void GameOver::init()
{
    m_GameOver = false;
    m_PlayAgain = false;
}

void GameOver::update()
{
    if ((m_GameOver == true) && (KeyboardInput::getInstance()->getKeyDown(SDL_SCANCODE_O)))
    {
        m_GameOver = false;
        m_PlayAgain = true;

    }
}

void GameOver::updateDeath()
{
    m_GameOver = true;
}

void GameOver::render()
{
    if (m_GameOver) TextureManager::getInstance()->drawBG("GameOver", 0, 0, 1344, 768);

    TextureManager::getInstance()->drawText("GameOverPlayAgain", "Play Again", 570, 350, colorPlayAgain, Engine::GetInstance()->m_MenuStartGameFont );
    int w, h;
    w = TextureManager::getInstance()->m_getTextureWidth["GameOverPlayAgain"];
    h = TextureManager::getInstance()->m_getTextureHeight["GameOverPlayAgain"];
    PlayAgiain = {570, 350, w, h};
}

void GameOver::exit()
{

}