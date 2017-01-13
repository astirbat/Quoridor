#pragma once
ref class GameInstance sealed
{
public:
	GameInstance(int players);
private:
	int _WALL = 99;

	int _winner;
	int _players;
	int _currentPlayerTurn;
	int _playerI[4];
	int _playerJ[4];
	int _score[4];
	int _walls[4];
	int _board[19][19];
public:
	int GetPlayerScore(int player);
	int GetCurrentPlayer();
	bool Move(int i, int j);
	bool MoveInternal(int i, int j);
	bool AddWall(int i, int j,int i2,int j2);
	bool AddWallInternal(int i, int j, int i2, int j2);
	void NextPlayer();
	int GetWinner();
	bool Win();
	void NewGame();
	int Players();
};

