#include "raylib.h"
#include "Player.h"
#include "Enemy.h"
#include <vector>

struct GameState {
    int width{800};
    int height{600};
    int enemyCount{7};
    bool isGameOver{false};
    std::vector<Enemy> enemies;
    Player Player1{15, height / 2, 15, 5};
} game;

// Game Functions
void SpawnEnemies(GameState& gameState, int count);
void DrawEnemyObjects(GameState& gameState);
void CheckPlayerCollision(GameState& gameState);
void DrawPlayerObjects(GameState& gameState);
bool IsOverlapping(const Enemy& enemy, const Player& player);

int main()
{

    InitWindow(game.width, game.height, "raylib improved collision"); // Initialize window
    SetTargetFPS(60); // Set the target frames-per-second
    SpawnEnemies(game, game.enemyCount); // Spawn enemies

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        CheckPlayerCollision(game);

        if (game.isGameOver)
        {
            DrawText("Game Over!", game.width / 2, game.height / 2, 20, RED);
        }
        else
        {
            // Draw Player Object
            DrawPlayerObjects(game);

            // Draw Enemy Objects
            DrawEnemyObjects(game);
            
        }
        
        DrawText(TextFormat("Enemy Count: %i", Enemy::GetEnemyCount()), 10, 10, 20, BLACK);
        EndDrawing();
    }
}

bool IsOverlapping(const Enemy& enemy, const Player& player)
{
    int enemy_top = enemy.GetRectTop();
    int enemy_bottom = enemy.GetRectBottom();
    int enemy_left = enemy.GetRectLeft();
    int enemy_right = enemy.GetRectRight();

    int player_top = player.GetCircleTop();
    int player_bottom = player.GetCircleBottom();
    int player_left = player.GetCircleLeft();
    int player_right = player.GetCircleRight();

    return 
    (enemy_top < player_bottom) && 
    (enemy_bottom > player_top) &&
    (enemy_left < player_right) && 
    (enemy_right > player_left);
}

// Updated SpawnEnemies function to use the GameState struct
void SpawnEnemies(GameState& gameState, int count)
{
    gameState.enemies.clear(); // Clear existing enemies

    for (int i = 0; i < count; i++)
    {
        // Initialize enemy properties dynamically
        int speed = 5 * i + 1;
        int rect_x = 100 + (i * 100);
        int rect_y = gameState.height / 2;
        int rect_width = 30;
        int rect_height = 50;

        // Create and add enemy to the vector
        gameState.enemies.emplace_back(rect_x, rect_y, rect_width, rect_height, speed);
    }
}

// Updated CheckPlayerCollision function to use the GameState struct
void CheckPlayerCollision(GameState& gameState)
{
    for (Enemy& enemy : gameState.enemies)
    {
        if (IsOverlapping(enemy, gameState.Player1))
        {
            gameState.isGameOver = true;
            return; // Exit early if a collision is detected
        }
    }
}

// Updated DrawEnemyObjects function to use the GameState struct
void DrawEnemyObjects(GameState& gameState)
{
    for (Enemy& enemy : gameState.enemies)
    {
        enemy.Draw();
        enemy.UpdateMovement(gameState.width, gameState.height);
    }
}

// Updated DrawPlayerObjects function to use the GameState struct
void DrawPlayerObjects(GameState& gameState)
{
    gameState.Player1.Draw();
    gameState.Player1.UpdateMovement(gameState.width, gameState.height);
}