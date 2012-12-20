/*  gamewidget.h
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
#ifndef __GAMEWIDGET_H__
#define __GAMEWIDGET_H__

#include "graphics/widgetstack.h"
#include "buywidget.h"
#include "gameoverwidget.h"
#include "utilities/timer.h"
#include "enemies/enemy.h"
#include "particle.h"
#include "actor.h"
#include "gamestatistics.h"
#include "input/keystate.h"
#include "sound/audiosource.h"
#include "weapons/weapon.h"
#include "options/optionswidget.h"
#include "itemdrops/itemdropfactory.h"
#include "modifiers/modifiermanager.h"
#include <list>
#include <vector>


//-----------------------------------------------------------------------------
//  Class Definition
//-----------------------------------------------------------------------------
class GameWidget : public Widget
{
public:

    enum
    {
        WEAPON_PISTOL,
        WEAPON_MACHINEGUN,
        WEAPON_RIFLE,
        WEAPON_SHOTGUN,
        WEAPON_ROCKET_LAUNCHER,
        WEAPON_GRENADE_LAUNCHER,
        WEAPON_COUNT
    };

public:
    GameWidget(WidgetStack* widgetStack);
    ~GameWidget();

    void keyEvent(int key, int flags);
    void updateEvent();
    void paintEvent(Canvas& canvas);
    void notification(Notification notification, Widget* sender);

    void runWaveIntro();
    void updateActor();
    void spawnEnemies();
    void spawnBullets();
    void updateBullets();
    void updateEnemies();
    void updateParticles();
    void updateItemDrops();
    void setNextWave();
    void nukeEverything();
    void displayStatistics(Canvas& canvas);

private:

    enum GameState
    {
        sWaveIntro,
        sWaveActive,
        sBuyWeapons,
        sOptions,
        sGameOver
    };

private:
    GameStatistics _statistics;
    ModifierManager _modifiers;
    Rect _worldRect;
    Rect _enemyArea;
    std::vector<Weapon*> _weapons;
    Weapon* _activeWeapon;
    std::list<Bullet*> _bullets;
    std::list<Enemy*> _enemies;
    std::list<Particle*> _particles;
    std::list<ItemDrop*> _itemDrops;
    std::list<WorldObject*> _renderList;
    Actor _actor;
    BuyWidget* _buyWidget;
    GameOverWidget* _gameOverWidget;
    OptionsWidget* _optionsWidget;

    ItemDropFactory* _itemDropFactory;

    int _enemiesToSpawn;
    int _spawnCount;
    unsigned long _spawnTimeoutBase;
    unsigned long _spawnTimeout;
    double _enemyVelocityBase;

    GameState _gameState;
    std::list<GameState> _gameStateStack;
    Timer _spawnTimer;
    Timer _waveIntroTimer;
    unsigned long _keystate;
    Bitmap _overlay;

    AudioSource* _sndBatHit;
    AudioSource* _sndExplode;
    AudioSource* _sndPickup;
    AudioSource* _sndNuke;

};



#endif
