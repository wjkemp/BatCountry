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

#include "bitmapgraphicsdevice.h"


BitmapGraphicsDevice::BitmapGraphicsDevice(int width, int height, bool fullscreen) :
	GraphicsDevice(width, height),
	_characterWidth(8),
	_characterHeight(12),
	_closed(false)
{

	if (fullscreen) {
		al_set_new_display_flags(ALLEGRO_FULLSCREEN);
	} else {
		al_set_new_display_flags(ALLEGRO_WINDOWED);
	}

	_display = al_create_display(_width * _characterWidth, _height * _characterHeight);

	// Create an event queue
	_eventQueue = al_create_event_queue();
	al_register_event_source(_eventQueue, al_get_display_event_source(_display));


	// Load the font
	_font = al_load_bitmap("./resources/bitmaps/font_8x12.png");
	al_convert_mask_to_alpha(_font, al_map_rgb(0, 0, 0));


	// Map the foreground colors
	_foregroundColors[0] = al_map_rgb(0, 0, 0);
	_foregroundColors[1] = al_map_rgb(0, 0, 128);
	_foregroundColors[2] = al_map_rgb(0, 128, 0);
	_foregroundColors[3] = al_map_rgb(0, 128, 128);
	_foregroundColors[4] = al_map_rgb(128, 0, 0);
	_foregroundColors[5] = al_map_rgb(128, 0, 128);
	_foregroundColors[6] = al_map_rgb(128, 128, 0);
	_foregroundColors[7] = al_map_rgb(192, 192, 192);
	_foregroundColors[8] = al_map_rgb(128, 128, 128);
	_foregroundColors[9] = al_map_rgb(0, 0, 255);
	_foregroundColors[10] = al_map_rgb(0, 255, 0);
	_foregroundColors[11] = al_map_rgb(0, 255, 255);
	_foregroundColors[12] = al_map_rgb(255, 0, 0);
	_foregroundColors[13] = al_map_rgb(255, 0, 255);
	_foregroundColors[14] = al_map_rgb(255, 255, 0);
	_foregroundColors[15] = al_map_rgb(255, 255, 255);

}

BitmapGraphicsDevice::~BitmapGraphicsDevice()
{
	al_destroy_event_queue(_eventQueue);
	al_destroy_display(_display);
}

bool BitmapGraphicsDevice::closed()
{
	ALLEGRO_EVENT event;

	if (!al_is_event_queue_empty(_eventQueue)) {

		al_get_next_event(_eventQueue, &event);

		// Quit Event
		if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			_closed = true;
		}
	}

	return _closed;
}

void BitmapGraphicsDevice::render(Canvas& canvas)
{
	al_clear_to_color(al_map_rgb(0, 0, 0));
	unsigned long* buffer = canvas.buffer();


	for (int h=0; h < _height; ++h) {
		for (int w=0; w < _width; ++w) {

			int characterIndex = buffer[(w + (h * _width))] & 0xFF;
			int foregroundColorIndex = (buffer[(w + (h * _width))] >> 8) & 0xF;

			int srcX = (characterIndex & 0xF) * _characterWidth;
			int srcY = ((characterIndex >> 4) & 0xF) * _characterHeight;

			int destX = (w * _characterWidth);
			int destY = (h * _characterHeight);

			if (characterIndex) {
			  al_draw_tinted_bitmap_region(
				  _font,
				  _foregroundColors[foregroundColorIndex],
				  srcX,
				  srcY,
				  _characterWidth,
				  _characterHeight,
				  destX,
				  destY,
				  0);
			}
		}
	}

	al_flip_display();
}
