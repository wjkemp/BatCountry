/*  gamestatistics.cpp
 *
 *  Copyright (C) 2012 Willem Kemp <http://www.thenocturnaltree.com/>
 *  All rights reserved.
 *
 *  This file is part of BatCountry.
 *
 *  BatCountry is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  BatCountry is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with BatCountry. If not, see http://www.gnu.org/licenses/.
 *
 */
#include "gamestatistics.h"



//-----------------------------------------------------------------------------
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


//-----------------------------------------------------------------------------
GameStatistics::~GameStatistics()
{

}


//-----------------------------------------------------------------------------
void GameStatistics::startWave(int wave, int totalEnemies)
{
    _currentWave = wave;
    _enemiesLeftInCurrentWave = totalEnemies;
    _enemiesEscapedInCurrentWave = 0;
    _enemiesKilledInCurrentWave = 0;
}


//-----------------------------------------------------------------------------
void GameStatistics::addEnemiesKilled(int killed)
{
    _enemiesLeftInCurrentWave -= killed;
    _enemiesKilledInCurrentWave += killed;
}


//-----------------------------------------------------------------------------
void GameStatistics::addEnemiesEscaped(int escaped)
{
    _enemiesLeftInCurrentWave -= escaped;
    _enemiesEscapedInCurrentWave += escaped;
    _totalEnemiesEscaped += escaped;
}


//-----------------------------------------------------------------------------
int GameStatistics::infestationPercentage() const
{
    int percentage = ((_totalEnemiesEscaped * 100) / _infestationLimit);
    if (percentage > 100) {
        percentage = 100;
    }

    return percentage;
}
