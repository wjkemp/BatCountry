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
