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

#include "allegroengine.h"
#include "allegrosource.h"
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>


AllegroEngine::AllegroEngine() :
	_gain(0.5)
{
	al_install_audio();
	al_init_acodec_addon();
	al_reserve_samples(12);
}

void AllegroEngine::setVolume(int volume)
{
	_gain = (float)volume / 100.0f;
}

AudioSource* AllegroEngine::createSource(const std::wstring& filename)
{
	std::string tmp;
	tmp.assign(filename.begin(), filename.end());
	ALLEGRO_SAMPLE* sample = al_load_sample(tmp.c_str());
	return new AllegroSource(this, sample);
}
