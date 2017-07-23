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

#include "gamewidget.h"
#include "graphics/widgetstack.h"
#include "sound/audioengine.h"
#include "weapons/pistol.h"
#include "weapons/machinegun.h"
#include "weapons/rifle.h"
#include "weapons/shotgun.h"
#include "weapons/rocketlauncher.h"
#include "weapons/grenadelauncher.h"
#include "enemies/bat.h"
#include "enemies/demonbat.h"
#include "utilities/random.h"
#include "graphics/images.h"


GameWidget::GameWidget(WidgetStack* widgetStack) :
	Widget(widgetStack),
	_statistics(200),
	_gameState(sWaveIntro),
	_spawnTimer("spawn_timer"),
	_waveIntroTimer("wave_intro_timer"),
	_enemyArea(-2, 10, 84, 12),
	_worldRect(0, 0, 80, 40),
	_keystate(0),
	_actor(&_modifiers, _worldRect, _keystate),
	_spawnCount(0),
	_spawnTimeoutBase(3000),
	_spawnTimeout(3000),
	_enemyVelocityBase(4.0),
	_overlay(IMG_OVERLAY)
{

   _sndBatHit = AudioEngine::instance()->createSource(L"./resources/audio/hit.wav");
   _sndExplode = AudioEngine::instance()->createSource(L"./resources/audio/explosion.wav");
   _sndPickup = AudioEngine::instance()->createSource(L"./resources/audio/pickup.wav");
   _sndNuke = AudioEngine::instance()->createSource(L"./resources/audio/nuke.wav");

   _weapons.push_back(new Pistol(&_modifiers));
   _weapons.push_back(new Machinegun(&_modifiers));
   _weapons.push_back(new Rifle(&_modifiers));
   _weapons.push_back(new Shotgun(&_modifiers));
   _weapons.push_back(new RocketLauncher(&_modifiers));
   _weapons.push_back(new GrenadeLauncher(&_modifiers));
   _activeWeapon = _weapons[WEAPON_PISTOL];
   _activeWeapon->buyItem();


   //_weapons[WEAPON_MACHINEGUN]->buyItem();
   //_weapons[WEAPON_RIFLE]->buyItem();
   //_weapons[WEAPON_SHOTGUN]->buyItem();
   //_weapons[WEAPON_ROCKET_LAUNCHER]->buyItem();
   //_weapons[WEAPON_GRENADE_LAUNCHER]->buyItem();


	_buyWidget = new BuyWidget(widgetStack, _weapons, _statistics);
	_buyWidget->addNotificationListener(this);

	_gameOverWidget = new GameOverWidget(widgetStack);
	_gameOverWidget->addNotificationListener(this);

	_optionsWidget = new OptionsWidget(widgetStack);
	_optionsWidget->addNotificationListener(this);

	_itemDropFactory = new ItemDropFactory();


   _renderList.push_back(&_actor);

   setNextWave();
}

GameWidget::~GameWidget()
{
	delete _itemDropFactory;
}

void GameWidget::keyEvent(int key, int flags)
{
	if (flags & InputHandler::fKeyDown) {

		// State-based keys
		switch (key) {
			case InputHandler::KEY_LEFT: {
				_keystate |= KEYSTATE_LEFT;
			} break;

			case InputHandler::KEY_RIGHT: {
				_keystate |= KEYSTATE_RIGHT;
			} break;

			case InputHandler::KEY_X: {
				_keystate |= KEYSTATE_FIRE_UP;
			} break;

			case InputHandler::KEY_Z: {
				_keystate |= KEYSTATE_FIRE_LEFT;
			} break;

			case InputHandler::KEY_C: {
				_keystate |= KEYSTATE_FIRE_RIGHT;
			} break;
		}


		switch (key) {

			case InputHandler::KEY_1: {
				if (_weapons[WEAPON_PISTOL]->itemIsSold()) {
					_activeWeapon = _weapons[WEAPON_PISTOL];
				}
			} break;

			case InputHandler::KEY_2: {
				if (_weapons[WEAPON_MACHINEGUN]->itemIsSold()) {
					_activeWeapon = _weapons[WEAPON_MACHINEGUN];
				}
			} break;

			case InputHandler::KEY_3: {
				if (_weapons[WEAPON_RIFLE]->itemIsSold()) {
					_activeWeapon = _weapons[WEAPON_RIFLE];
				}
			} break;

			case InputHandler::KEY_4: {
				if (_weapons[WEAPON_SHOTGUN]->itemIsSold()) {
					_activeWeapon = _weapons[WEAPON_SHOTGUN];
				}
			} break;

			case InputHandler::KEY_5: {
				if (_weapons[WEAPON_ROCKET_LAUNCHER]->itemIsSold()) {
					_activeWeapon = _weapons[WEAPON_ROCKET_LAUNCHER];
				}
			} break;

			case InputHandler::KEY_6: {
				if (_weapons[WEAPON_GRENADE_LAUNCHER]->itemIsSold()) {
					_activeWeapon = _weapons[WEAPON_GRENADE_LAUNCHER];
				}
			} break;

			case InputHandler::KEY_ESCAPE: {

				/* Clear the keystate */
				_keystate = 0;

				Timer::pauseAll();
				_gameStateStack.push_back(_gameState);
				_gameState = sOptions;
				_widgetStack->pushWidget(_optionsWidget);
				_optionsWidget->setActive();

			} break;
		}

	} else {

		switch (key) {
			case InputHandler::KEY_LEFT: {
				_keystate &= ~KEYSTATE_LEFT;
			} break;

			case InputHandler::KEY_RIGHT: {
				_keystate &= ~KEYSTATE_RIGHT;
			} break;

			case InputHandler::KEY_X: {
				_keystate &= ~KEYSTATE_FIRE_UP;
			} break;

			case InputHandler::KEY_Z: {
				_keystate &= ~KEYSTATE_FIRE_LEFT;
			} break;

			case InputHandler::KEY_C: {
				_keystate &= ~KEYSTATE_FIRE_RIGHT;
			} break;
		}
	}
}

void GameWidget::updateEvent()
{
	switch (_gameState) {

		case sWaveIntro: {
			runWaveIntro();
		} break;

		case sWaveActive: {
			spawnEnemies();
			updateEnemies();

			if (_statistics.enemiesLeftInCurrentWave() == 0) {
				_keystate = 0;
				setNextWave();
				_widgetStack->pushWidget(_buyWidget);
				_gameState = sBuyWeapons;
			}

			if (_statistics.infestationPercentage() >= 100) {
				_keystate = 0;
				_gameState = sGameOver;
				_widgetStack->pushWidget(_gameOverWidget);
			}

		} break;


		case sBuyWeapons: {

		}


		case sGameOver: {
			updateEnemies();
		} break;

	}

	if (_gameState != sOptions) {
		spawnBullets();
		updateActor();
		updateBullets();
		updateParticles();
		updateItemDrops();
		_modifiers.update();
	}
}

void GameWidget::notification(Notification notification, Widget* sender)
{
	if (notification == N_REQUEST_CLOSE) {

		if (sender == _gameOverWidget) {
			_widgetStack->popWidget(_gameOverWidget);
			notify(N_REQUEST_CLOSE);
		}

		if (sender == _buyWidget) {
			_keystate = 0;
			_widgetStack->popWidget(_buyWidget);
			_gameState = sWaveIntro;
			_waveIntroTimer.reset();
		}

		if (sender == _optionsWidget) {
			_keystate = 0;
			_widgetStack->popWidget(_optionsWidget);
			_gameState = _gameStateStack.back();
			_gameStateStack.pop_back();
			Timer::resumeAll();
		}
	}
}

void GameWidget::runWaveIntro()
{
	if (_waveIntroTimer.elapsed() > 5.0) {
		_gameState = sWaveActive;
	}
}

void GameWidget::spawnEnemies()
{
	if (_enemiesToSpawn) {

		if ((_spawnTimer.elapsed() * 1000) > _spawnTimeout) {

			if ((Random::random() > 0.9) && (_statistics.currentWave() >= 8)) {
				DemonBat* bat;
				bat = new DemonBat(_enemyArea, _enemyVelocityBase);

				_enemies.push_back(bat);
				_renderList.push_back(bat);
				_enemiesToSpawn--;

			} else {
				Bat* bat;
				bat = new Bat(_enemyArea, _enemyVelocityBase);

				_enemies.push_back(bat);
				_renderList.push_back(bat);
				_enemiesToSpawn--;
			}

			_spawnTimeout = _spawnTimeoutBase + Random::random(200);
			_spawnTimer.reset();
		}
	}
}

void GameWidget::spawnBullets()
{

	if (_keystate & KEYSTATE_FIRE_UP) {

		if (_activeWeapon->ammunition()) {
			std::vector<Bullet*> bullets(
				_activeWeapon->fire(
					Point(_actor.position().x(), _actor.position().y() - 1),
					Weapon::Center,
					_worldRect));

			if (bullets.size()) {
				_bullets.insert(_bullets.end(), bullets.begin(), bullets.end());
				_renderList.insert(_renderList.end(), bullets.begin(), bullets.end());
			}
		}
	}

	if (_keystate & KEYSTATE_FIRE_LEFT) {

		if (_activeWeapon->ammunition()) {
			std::vector<Bullet*> bullets(
				_activeWeapon->fire(
					Point(_actor.position().x(), _actor.position().y() - 1),
					Weapon::Left,
					_worldRect));

			if (bullets.size()) {
				_bullets.insert(_bullets.end(), bullets.begin(), bullets.end());
				_renderList.insert(_renderList.end(), bullets.begin(), bullets.end());
			}
		}
	}


	if (_keystate & KEYSTATE_FIRE_RIGHT) {

		if (_activeWeapon->ammunition()) {
			std::vector<Bullet*> bullets(
				_activeWeapon->fire(
					Point(_actor.position().x(), _actor.position().y() - 1),
					Weapon::Right,
					_worldRect));

			if (bullets.size()) {
				_bullets.insert(_bullets.end(), bullets.begin(), bullets.end());
				_renderList.insert(_renderList.end(), bullets.begin(), bullets.end());
			}
		}
	}
}

void GameWidget::updateActor()
{
	_actor.update();
}

void GameWidget::updateBullets()
{

	// Update bullet list
	std::list<Bullet*>::const_iterator i = _bullets.begin();
	while (i != _bullets.end()) {

		Bullet* bullet = *i;

		// Update the bullet
		bullet->update();
		bool bulletHasHit = false;
		bool removeBullet = false;
		int enemiesKilled = 0;


		if (bullet->state() == Bullet::sExpired) {
			removeBullet = true;

		} else {

			// Have we hit an enemy
			std::list<Enemy*>::const_iterator j = _enemies.begin();

			while (j != _enemies.end()) {
				Enemy* enemy = *j;

				// Check if the enemy is hit by either direct or radius damage
				if (
					(bulletHasHit && bullet->hasRadiusDamage() && (bullet->position().distanceTo(enemy->position()) < bullet->damageRadius())) ||
					(enemy->boundingRect().contains(bullet->position()) || bullet->intersects(enemy->boundingRect()))
					) {

					// Damage the enemy
					enemy->damage(bullet->damage());

					// Play the hit sound
					_sndBatHit->play();

					// Spawn explosion residue
					if (bullet->hasRadiusDamage()) {

						// Spawn residue
						std::list<Particle*> particles(bullet->spawnResidue());
						_particles.insert(_particles.end(), particles.begin(), particles.end());
						_renderList.insert(_renderList.end(), particles.begin(), particles.end());

					}

					// Check if the enemy is killed
					if (enemy->state() == Enemy::sKilled) {

						// Spawn particles
						std::list<Particle*> particles(enemy->spawnParticles());
						_particles.insert(_particles.end(), particles.begin(), particles.end());
						_renderList.insert(_renderList.end(), particles.begin(), particles.end());

						// Spawn item drop
						ItemDrop* itemDrop = _itemDropFactory->createDrop(enemy->position().x(), enemy->position().y());
						if (itemDrop) {
							_itemDrops.push_back(itemDrop);
							_renderList.push_back(itemDrop);
						}

						// Add money
						_statistics.giveMoney(enemy->reward());

						// Kill the enemy
						j = _enemies.erase(j);
						_renderList.remove(enemy);
						_statistics.addEnemiesKilled(1);
						enemiesKilled++;
						delete enemy;
					} else {
						++j;
					}


					// Remove the bullet
					if (!bullet->isPenetrating()) {
						removeBullet = true;
					}

					// If the bullet does not do radius damage, break
					if (!bullet->hasRadiusDamage()) {
						break;
					} else {
						if (!bulletHasHit) {
							bulletHasHit = true;
							j = _enemies.begin();
						}
					}

				} else {
					++j;
				}
			}
		}


		// Play the explosion sound
		if (bulletHasHit && bullet->hasRadiusDamage()) {
			_sndExplode->play();
		}


		if (removeBullet) {

			i = _bullets.erase(i);
			_renderList.remove(bullet);
			delete bullet;
		} else {
			++i;
		}
	}
}

void GameWidget::updateEnemies()
{
	// Move the bats
	std::list<Enemy*>::const_iterator i = _enemies.begin();
	while (i != _enemies.end()) {
		Enemy* enemy = *i;
		enemy->update();
		if (enemy->state() == Bat::sEscaped) {
			i = _enemies.erase(i);
			_renderList.remove(enemy);
			delete enemy;
			_statistics.addEnemiesEscaped(1);
		} else {
			++i;
		}
	}
}

void GameWidget::updateParticles()
{
	// Move the particles
	std::list<Particle*>::const_iterator l = _particles.begin();
	while (l != _particles.end()) {
		Particle* particle = *l;
		particle->update();
		if (particle->state() == Particle::sExpired) {
			l = _particles.erase(l);
			_renderList.remove(particle);
			delete particle;
		} else {
			++l;
		}
	}
}

void GameWidget::updateItemDrops()
{
	// Update the item drops
	std::list<ItemDrop*>::const_iterator l = _itemDrops.begin();
	while (l != _itemDrops.end()) {
		ItemDrop* itemDrop = *l;
		itemDrop->update();

		// Check for an expired item
		if (itemDrop->state() == ItemDrop::sExpired) {
			l = _itemDrops.erase(l);
			_renderList.remove(itemDrop);
			delete itemDrop;

		// Check for a pickup
		} else if (itemDrop->boundingRect().contains(_actor.position())) {

			// Special case for nuke
			if (itemDrop->modifier().id() == Modifier::mNuke) {
				_sndNuke->play();
				nukeEverything();

			} else {
				_sndPickup->play();
				_modifiers.addModifier(itemDrop->modifier());
			}

			l = _itemDrops.erase(l);
			_renderList.remove(itemDrop);
			delete itemDrop;

		} else {
			++l;
		}
	}
}

void GameWidget::paintEvent(Canvas& canvas)
{
	canvas.clear();

	canvas.drawBitmap(_overlay, 0, 28);


	if (_gameState == sWaveIntro) {
		canvas.drawText("Get Ready!!!", 34, 12, COLOR_LIGHTYELLOW);
	}


	std::list<WorldObject*>::const_iterator k;
	for (k = _renderList.begin(); k != _renderList.end(); ++k) {
		WorldObject* obj = *k;
		obj->render(canvas);
	}

	_modifiers.drawModifierList(canvas);
	displayStatistics(canvas);

}

void GameWidget::setNextWave()
{
	// Spawn more enemies
	_spawnCount += 5;
	_enemiesToSpawn = _spawnCount;
	_statistics.startWave(_statistics.currentWave() + 1, _enemiesToSpawn);

	// Update the spawn timeout
	_spawnTimeoutBase = (3400 - (log10((double)(_statistics.currentWave() * 5)) * 1500));
	_spawnTimeout = _spawnTimeoutBase;

	// Speed up the enemies
	_enemyVelocityBase += 0.6;

	// Reset the intro timer
	_waveIntroTimer.reset();
}

void GameWidget::nukeEverything()
{
	std::list<Enemy*>::const_iterator i = _enemies.begin();
	while (i != _enemies.end()) {
		Enemy* enemy = *i;

		// Do some serious damage (for velocity on the particles)
		enemy->damage(7);

		// Spawn particles
		std::list<Particle*> particles(enemy->spawnParticles());
		_particles.insert(_particles.end(), particles.begin(), particles.end());
		_renderList.insert(_renderList.end(), particles.begin(), particles.end());

		// No item drops spawned on nukes

		// Add money
		_statistics.giveMoney(enemy->reward());

		// Kill the enemy
		i = _enemies.erase(i);
		_renderList.remove(enemy);
		_statistics.addEnemiesKilled(1);
		delete enemy;
	}
}

void GameWidget::displayStatistics(Canvas& canvas)
{
	char formatBuffer[256];

	// Money
	snprintf(formatBuffer, sizeof(formatBuffer), "%d", _statistics.money());
	canvas.drawText("Money:", 2, 36, COLOR_WHITE);
	canvas.drawText(formatBuffer, 12, 36, COLOR_WHITE);

	// Current Wave
	snprintf(formatBuffer, sizeof(formatBuffer), "%d", _statistics.currentWave());
	canvas.drawText("Wave:", 2, 37, COLOR_WHITE);
	canvas.drawText(formatBuffer, 12, 37, COLOR_WHITE);

	// Infestation
	snprintf(formatBuffer, sizeof(formatBuffer), "%d%%", _statistics.infestationPercentage());
	canvas.drawText("Infested:", 2, 38, COLOR_WHITE);
	canvas.drawText(formatBuffer, 12, 38, COLOR_WHITE);


	// Remaining
	snprintf(formatBuffer, sizeof(formatBuffer), "%d", _statistics.enemiesLeftInCurrentWave());
	canvas.drawText("Remaining:", 20, 36, COLOR_WHITE);
	canvas.drawText(formatBuffer, 32, 36, COLOR_WHITE);

	// Killed
	snprintf(formatBuffer, sizeof(formatBuffer), "%d", _statistics.enemiesKilledInCurrentWave());
	canvas.drawText("Killed:", 20, 37, COLOR_WHITE);
	canvas.drawText(formatBuffer, 32, 37, COLOR_WHITE);

	// Escaped
	snprintf(formatBuffer, sizeof(formatBuffer), "%d", _statistics.enemiesEscapedInCurrentWave());
	canvas.drawText("Escaped:", 20, 38, COLOR_WHITE);
	canvas.drawText(formatBuffer, 32, 38, COLOR_WHITE);



	const int weaponGrid[][3] =
	{
		{ 36, 40, 55 },
		{ 37, 40, 55 },
		{ 38, 40, 55 },
		{ 36, 60, 73 },
		{ 37, 60, 73 },
		{ 38, 60, 73 }
	};


	for (int i=0; i < WEAPON_COUNT; ++i) {
		Weapon* weapon = _weapons[i];
		if (weapon->itemIsSold()) {
			Color color = (weapon == _activeWeapon) ? COLOR_LIGHTBLUE : COLOR_WHITE;
			snprintf(formatBuffer, sizeof(formatBuffer), "%d: %s:", (i + 1), weapon->shortName().c_str());
			canvas.drawText(formatBuffer, weaponGrid[i][1], weaponGrid[i][0], color);
			snprintf(formatBuffer, sizeof(formatBuffer), "%d", weapon->ammunition());
			canvas.drawText(formatBuffer, weaponGrid[i][2], weaponGrid[i][0], color);
		}
	}
}
