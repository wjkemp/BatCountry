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

#ifndef __GAMESTATISTICS_H__
#define __GAMESTATISTICS_H__

class GameStatistics
{

public:
	GameStatistics(int infestationLimit);
	~GameStatistics();

	void startWave(int wave, int totalEnemies);
	void addEnemiesKilled(int killed);
	void addEnemiesEscaped(int escaped);
	int infestationPercentage() const;

	int money() const                               { return _money; }
	bool hasMoney(int amount) const                 { return _money >= amount; }
	void giveMoney(int amount)                      { _money += amount; }
	void takeMoney(int amount)                      { _money -= amount; }

	int currentWave() const                         { return _currentWave; }
	int enemiesLeftInCurrentWave() const            { return _enemiesLeftInCurrentWave; }
	int enemiesEscapedInCurrentWave() const         { return _enemiesEscapedInCurrentWave; }
	int enemiesKilledInCurrentWave() const          { return _enemiesKilledInCurrentWave; }

private:

	// Money
	int _money;

	// Infestation
	int _infestationLimit;
	int _totalEnemiesEscaped;

	// Current Wave Statistics
	int _currentWave;
	int _enemiesLeftInCurrentWave;
	int _enemiesEscapedInCurrentWave;
	int _enemiesKilledInCurrentWave;
};

#endif
