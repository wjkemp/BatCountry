/*
	Copyright (c) 2017 Willem Kemp (https://github.com/wjkemp)

	Permission is hereby granted, free of charge, to any person obtaining a copy
	of this software and associated documentation files (the "Software"), to deal
	in the Software without restriction, including without limitation the rights
	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the Software is
	furnished to do so, subject to the following conditions:

	The above copyright notice and this permission notice shall be included in all
	copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
	SOFTWARE.
*/

#include "gamestatistics.h"


GameStatistics::GameStatistics(int infestationLimit) :
	_money(0),
	_infestationLimit(infestationLimit),
	_totalEnemiesEscaped(0),
	_currentWave(0),
	_enemiesLeftInCurrentWave(0),
	_enemiesEscapedInCurrentWave(0),
	_enemiesKilledInCurrentWave(0)
{

}

GameStatistics::~GameStatistics()
{

}

void GameStatistics::startWave(int wave, int totalEnemies)
{
	_currentWave = wave;
	_enemiesLeftInCurrentWave = totalEnemies;
	_enemiesEscapedInCurrentWave = 0;
	_enemiesKilledInCurrentWave = 0;
}

void GameStatistics::addEnemiesKilled(int killed)
{
	_enemiesLeftInCurrentWave -= killed;
	_enemiesKilledInCurrentWave += killed;
}

void GameStatistics::addEnemiesEscaped(int escaped)
{
	_enemiesLeftInCurrentWave -= escaped;
	_enemiesEscapedInCurrentWave += escaped;
	_totalEnemiesEscaped += escaped;
}

int GameStatistics::infestationPercentage() const
{
	int percentage = ((_totalEnemiesEscaped * 100) / _infestationLimit);
	if (percentage > 100) {
		percentage = 100;
	}

	return percentage;
}
