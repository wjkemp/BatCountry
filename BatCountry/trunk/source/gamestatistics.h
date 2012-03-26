/*  gamestatistics.h
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
#ifndef __GAMESTATISTICS_H__
#define __GAMESTATISTICS_H__


//-----------------------------------------------------------------------------
//  Class Definition
//-----------------------------------------------------------------------------
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
