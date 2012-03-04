/******************************************************************************
    gamestatistics.cpp
 ******************************************************************************/
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
