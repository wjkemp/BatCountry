/******************************************************************************
   gamestatistics.h
 ******************************************************************************/
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
