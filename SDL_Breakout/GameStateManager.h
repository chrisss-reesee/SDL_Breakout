#pragma once

enum class GameState { PLAY = 1, LAUNCH_PHASE, EXIT };

class GameStateManager
{
public:
	GameStateManager();
	~GameStateManager();
};

