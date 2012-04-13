/*  buywidget.cpp
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
#include "buywidget.h"
#include "graphics/widgetstack.h"
#include "graphics/images.h"
#include <stdio.h>


//-----------------------------------------------------------------------------
BuyWidget::BuyWidget(WidgetStack* widgetStack, std::vector<Weapon*> weapons, GameStatistics& statistics) :
    Widget(widgetStack),
    _weapons(weapons),
    _statistics(statistics),
    _background(IMG_BUY)
{
}


//-----------------------------------------------------------------------------
BuyWidget::~BuyWidget()
{
}


//-----------------------------------------------------------------------------
void BuyWidget::keyEvent(int key, int flags)
{
    if (flags & InputHandler::fKeyDown) {

        int buyIndex = -1;

        switch (key) {
            case InputHandler::KEY_1: buyIndex = 0; break;
            case InputHandler::KEY_2: buyIndex = 1; break;
            case InputHandler::KEY_3: buyIndex = 2; break;
            case InputHandler::KEY_4: buyIndex = 3; break;
            case InputHandler::KEY_5: buyIndex = 4; break;
            case InputHandler::KEY_6: buyIndex = 5; break;
            case InputHandler::KEY_ENTER: notify(N_REQUEST_CLOSE); break;
        }

        if ((buyIndex >= 0) && (buyIndex < _weapons.size())) {
            Weapon* weapon = _weapons[buyIndex];
            if (weapon->itemIsSold()) {
                if (_statistics.hasMoney(weapon->ammunitionBundlePrice())) {
                    _statistics.takeMoney(weapon->ammunitionBundlePrice());
                    weapon->buyAmmunitionBundle();
                }
            } else {
                if (_statistics.hasMoney(weapon->itemPrice())) {
                    _statistics.takeMoney(weapon->itemPrice());
                    weapon->buyItem();
                }
            }
        }


    } else {

    }

}


//-----------------------------------------------------------------------------
void BuyWidget::updateEvent()
{

}


//-----------------------------------------------------------------------------
void BuyWidget::paintEvent(Canvas& canvas)
{

    canvas.drawBitmap(_background, 20, 2);
    canvas.drawText("Gunz and Ammo!!!", 32, 3, COLOR_LIGHTYELLOW);
    canvas.drawText("Press enter when done", 29, 15, COLOR_WHITE);


    int index = 6;
    int count = 1;
    std::vector<Weapon*>::const_iterator i;
    for (i = _weapons.begin(); i != _weapons.end(); ++i) {
        Weapon* weapon = *i;
        char name[80];
        char price[80];

        if (weapon->itemIsSold()) {

            sprintf_s(
                name,
                sizeof(name),
                "%d: %s ammo (%d)",
                count, 
                weapon->fullName().c_str(),
                weapon->ammunitionBundleSize());

            sprintf_s(
                price,
                sizeof(price),
                ": %d$",
                weapon->ammunitionBundlePrice());

        } else {

            sprintf_s(
                name,
                sizeof(name),
                "%d: %s",
                count, 
                weapon->fullName().c_str());

            sprintf_s(
                price,
                sizeof(price),
                ": %d$",
                weapon->itemPrice());
        }

        canvas.drawText(name, 22, index, COLOR_WHITE);
        canvas.drawText(price, 50, index, COLOR_WHITE);
        count++;
        index++;
    }
}


//-----------------------------------------------------------------------------
void BuyWidget::notification(Notification notification, Widget* sender)
{

}
