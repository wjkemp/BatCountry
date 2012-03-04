/******************************************************************************
    weapon.cpp
 ******************************************************************************/
#include "weapon.h"


//-----------------------------------------------------------------------------
Weapon::Weapon(double fireCooldownTimeout) :
    _itemIsSold(false),
    _ammunition(0),
    _fireCooldownTimeout(fireCooldownTimeout)
{

}


//-----------------------------------------------------------------------------
Weapon::~Weapon()
{

}


//-----------------------------------------------------------------------------
void Weapon::buyItem()
{
    _itemIsSold = true;
    _ammunition += ammunitionBundleSize();
}


//-----------------------------------------------------------------------------
void Weapon::buyAmmunitionBundle()
{
    _ammunition += ammunitionBundleSize();
}


//-----------------------------------------------------------------------------
bool Weapon::canFire() const
{
    return (_fireCooldownTimer.elapsed() > _fireCooldownTimeout);
}


//-----------------------------------------------------------------------------
void Weapon::resetCooldownTimer()
{
    _fireCooldownTimer.reset();
}

