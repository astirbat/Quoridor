#include "pch.h"
#include "GameInstance.h"


GameInstance::GameInstance(int players)
{
	_players = players;
	_currentPlayerTurn = 0;
	for (int i = 0; i < 4; i++) {
		_score[i] = 0;
		_playerI[i] = 0;
		_playerJ[i] = 0;
	}
	int nrW = 20 / _players;
	for (int i = 0; i < _players; i++)
		_walls[i] = nrW;
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			_board[i][j] = 0;
		}
	}

	_playerI[0] = 9;
	_playerJ[0] = 1;
	_board[9][0] = 1;
	_playerI[1] = 9;
	_playerJ[1] = 17;
	_board[9][17] = 2;

	if (_players > 2) {
		_playerI[2] = 1;
		_playerJ[2] = 9;
		_board[0][9] = 3;
	}	
	if (_players > 3) {
		_playerI[3] = 17;
		_playerJ[3] = 9;
		_board[17][9] = 4;
	}

}


int GameInstance::GetPlayerScore(int player)
{
	if (player >= _players)
		return -1;
	return _score[player];
}


int GameInstance::GetCurrentPlayer()
{
	return _currentPlayerTurn;
}


bool GameInstance::Move(int i, int j)
{
	bool rez = MoveInternal(i, j);
	if (rez) {
		_board[_playerI[_currentPlayerTurn]][_playerJ[_currentPlayerTurn]] = 0;
		_playerI[_currentPlayerTurn] = i;
		_playerJ[_currentPlayerTurn] = j;
		_board[i][j] = _currentPlayerTurn + 1;

		NextPlayer();
	}
	return rez;
}

bool GameInstance::MoveInternal(int i, int j)
{
	if (i % 2 != 1 || j % 2 != 1)
		return false;
	if (_board[i][j] != 0)
		return false;

	if (_playerI[_currentPlayerTurn] == i) {
		if ((_playerJ[_currentPlayerTurn] + 2 == j) && (_board[i][j - 1] != _WALL))
			return true;
		if ((_playerJ[_currentPlayerTurn] - 2 == j) && (_board[i][j + 1] != _WALL))
			return true;
	}
	if (_playerJ[_currentPlayerTurn] == j) {
		if ((_playerI[_currentPlayerTurn] + 2 == i) && (_board[i - 1][j] != _WALL))
			return true;
		if ((_playerI[_currentPlayerTurn] - 2 == i) && (_board[i + 1][j] != _WALL))
			return true;
	}

	return false;
}

bool GameInstance::AddWall(int i, int j)
{
	if ((i + j) % 2 != 1)
		return false;
	if (_board[i][j] == _WALL)
		return false;
	if (_walls[_currentPlayerTurn] == 0)
		return false;
	_walls[_currentPlayerTurn]--;
	_board[i][j] = _WALL;
	NextPlayer();
	return true;
}

void GameInstance::NextPlayer()
{
	_currentPlayerTurn++;
	if (_currentPlayerTurn == _players)
		_currentPlayerTurn = 0;
}
