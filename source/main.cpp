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

#include "basewidget.h"
#include "graphics/widgetstack.h"
#include "graphics/bitmapgraphicsdevice.h"
#include "input/allegroinputengine.h"
#include "fullscreenhandler.h"
#include <iostream>

#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>


int main(int argc, char* argv[])
{
	al_init();
	al_init_image_addon();


	try {

		AllegroInputEngine inputEngine;
		WidgetStack widgetStack;
		BaseWidget baseWidget(&widgetStack);
		FullscreenHandler fullscreenHandler(&widgetStack);

		inputEngine.addInputHandler(&widgetStack);
		inputEngine.addInputHandler(&fullscreenHandler);
		inputEngine.run();

	} catch (const std::exception& e) {
		std::cout << "Terminated: " << e.what() << std::endl;
	}

	return 0;
}
