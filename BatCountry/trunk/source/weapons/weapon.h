/******************************************************************************
   weapon.h
 ******************************************************************************/
#ifndef __WEAPON_H__
#define __WEAPON_H__

#include "bullet.h"
#include "sound/audiosource.h"
#include <vector>


//-----------------------------------------------------------------------------
//  Class Definition
//-----------------------------------------------------------------------------
class Weapon
{

public:

    enum Direction
    {
        Left,
        Center,
        Right
    };


public:
    Weapon(double fireCooldownTimeout);
    ~Weapon();
    bool itemIsSold() const { return _itemIsSold; }
    int ammunition() const { return _ammunition; }

    virtual std::string fullName() const = 0;
    virtual std::string shortName() const = 0;
    virtual int itemPrice() const = 0;
    virtual int ammunitionBundlePrice() const = 0;
    virtual int ammunitionBundleSize() const = 0;
    virtual std::vector<Bullet*> fire(Point position, Direction direction, Rect boundingArea) = 0;

    void buyItem();
    void buyAmmunitionBundle();


protected:
    bool canFire() const;
    void resetCooldownTimer();


protected:
    AudioSource* _fireSound;
    bool _itemIsSold;
    int _ammunition;
    double _fireCooldownTimeout;
    Timer _fireCooldownTimer;

};



#endif
