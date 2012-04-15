/*  allegroinputengine.cpp
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
#include "allegroinputengine.h"



//-----------------------------------------------------------------------------
AllegroInputEngine::AllegroInputEngine()
{
    al_install_keyboard();

    _eventQueue = al_create_event_queue();
    al_register_event_source(_eventQueue, al_get_keyboard_event_source());

    // Map keys
    _keymap[ALLEGRO_KEY_UP] = InputHandler::KEY_UP;
    _keymap[ALLEGRO_KEY_DOWN] = InputHandler::KEY_DOWN;
    _keymap[ALLEGRO_KEY_LEFT] = InputHandler::KEY_LEFT;
    _keymap[ALLEGRO_KEY_RIGHT] = InputHandler::KEY_RIGHT;
    _keymap[ALLEGRO_KEY_SPACE] = InputHandler::KEY_SPACE;
    _keymap[ALLEGRO_KEY_ENTER] = InputHandler::KEY_ENTER;
    _keymap[ALLEGRO_KEY_ESCAPE] = InputHandler::KEY_ESCAPE;
    _keymap[ALLEGRO_KEY_1] = InputHandler::KEY_1;
    _keymap[ALLEGRO_KEY_2] = InputHandler::KEY_2;
    _keymap[ALLEGRO_KEY_3] = InputHandler::KEY_3;
    _keymap[ALLEGRO_KEY_4] = InputHandler::KEY_4;
    _keymap[ALLEGRO_KEY_5] = InputHandler::KEY_5;
    _keymap[ALLEGRO_KEY_6] = InputHandler::KEY_6;
    _keymap[ALLEGRO_KEY_7] = InputHandler::KEY_7;
    _keymap[ALLEGRO_KEY_8] = InputHandler::KEY_8;
    _keymap[ALLEGRO_KEY_9] = InputHandler::KEY_9;
    _keymap[ALLEGRO_KEY_Z] = InputHandler::KEY_Z;
    _keymap[ALLEGRO_KEY_X] = InputHandler::KEY_X;
    _keymap[ALLEGRO_KEY_C] = InputHandler::KEY_C;
    _keymap[ALLEGRO_KEY_F11] = InputHandler::KEY_F11;

}


//-----------------------------------------------------------------------------
AllegroInputEngine::~AllegroInputEngine()
{

}


//-----------------------------------------------------------------------------
void AllegroInputEngine::run()
{
    ALLEGRO_EVENT event;
    bool quit = false;


    do {
        if (!al_is_event_queue_empty(_eventQueue)) {

            al_get_next_event(_eventQueue, &event);

            switch (event.type) {



                // Keydown event
                case ALLEGRO_EVENT_KEY_DOWN: {
                    keyEvent(_keymap[event.keyboard.keycode], InputHandler::fKeyDown);
                } break;

                // Keyup event
                case ALLEGRO_EVENT_KEY_UP: {
                    keyEvent(_keymap[event.keyboard.keycode], InputHandler::fKeyUp);
                } break;
            }
        }

        updateEvent();

        if (closeRequested()) {
            quit = true;
        }

    } while (!quit);


}
