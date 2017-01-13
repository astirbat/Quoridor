#include "pch.h"
#include "GameInstance.h"


GameInstance::GameInstance(int players)
{
	_players = players;
	for (int i = 0; i < 4; i++) {
		_score[i] = 0;
	}
}

void GameInstance::NewGame()
{
	_currentPlayerTurn = 0;
	for (int i = 0; i < 4; i++) {
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
	_winner = -1;
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
	if (_winner != -1)
		return false;

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

	if (_playerI[_currentPlayerTurn] == i) {
		if ((_playerJ[_currentPlayerTurn] + 4 == j) && (_board[i][j - 2] != 0) && (_board[i][j - 1] != _WALL) && (_board[i][j - 3] != _WALL))
			return true;
		if ((_playerJ[_currentPlayerTurn] - 4 == j) && (_board[i][j + 2] != 0) && (_board[i][j + 1] != _WALL) && (_board[i][j + 3] != _WALL))
			return true;
	}
	if (_playerJ[_currentPlayerTurn] == j) {
		if ((_playerI[_currentPlayerTurn] + 4 == i) && (_board[i - 2][j] != 0) && (_board[i - 1][j] != _WALL) && (_board[i - 3][j] != _WALL))
			return true;
		if ((_playerI[_currentPlayerTurn] - 4 == i) && (_board[i + 2][j] != 0) && (_board[i + 1][j] != _WALL) && (_board[i + 3][j] != _WALL))
			return true;
	}

	if ((_playerI[_currentPlayerTurn] + 2 == i) && (_board[i - 1][_playerJ[_currentPlayerTurn]] == _WALL)) {
		if ((_playerJ[_currentPlayerTurn] + 2 == j) && (_board[i - 1][j - 1] != _WALL))
			return true;
		if ((_playerJ[_currentPlayerTurn] - 2 == j) && (_board[i - 1][j + 1] != _WALL))
			return true;
	}
	if ((_playerI[_currentPlayerTurn] - 2 == i) && (_board[i + 1][_playerJ[_currentPlayerTurn]] == _WALL)) {
		if ((_playerJ[_currentPlayerTurn] + 2 == j) && (_board[i + 1][j - 1] != _WALL))
			return true;
		if ((_playerJ[_currentPlayerTurn] - 2 == j) && (_board[i + 1][j + 1] != _WALL))
			return true;
	}

	if ((_playerJ[_currentPlayerTurn] + 2 == j) && (_board[_playerI[_currentPlayerTurn]][j - 1] == _WALL)) {
		if ((_playerI[_currentPlayerTurn] + 2 == i) && (_board[i - 1][j - 1] != _WALL))
			return true;
		if ((_playerI[_currentPlayerTurn] - 2 == i) && (_board[i + 1][j - 1] != _WALL))
			return true;
	}
	if ((_playerJ[_currentPlayerTurn] - 2 == j) && (_board[_playerI[_currentPlayerTurn]][j + 1] == _WALL)) {
		if ((_playerI[_currentPlayerTurn] + 2 == i) && (_board[i - 1][j + 1] != _WALL))
			return true;
		if ((_playerI[_currentPlayerTurn] - 2 == i) && (_board[i + 1][j + 1] != _WALL))
			return true;
	}

	return false;
}

bool GameInstance::AddWall(int i, int j)
{
	if (_winner != -1)
		return false;

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
	Win();

	_currentPlayerTurn++;
	if (_currentPlayerTurn == _players)
		_currentPlayerTurn = 0;
}

bool GameInstance::Win()
{
	if (_winner != -1)
		return true;
	if (_playerJ[0] == 17) {
		_winner = 0;
		_score[0]++;
		return true;
	}
	if (_playerJ[1] == 1) {
		_winner = 1;
		_score[1]++;
		return true;
	}
	if (_playerI[2] == 17) {
		_winner = 2;
		_score[2]++;
		return true;
	}
	if (_playerI[3] == 1) {
		_winner = 3;
		_score[3]++;
		return true;
	}
	return false;
}

int GameInstance::GetWinner()
{
	return _winner;
}

int GameInstance::Players()
{
	return _players;
}
