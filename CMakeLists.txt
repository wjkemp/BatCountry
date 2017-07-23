project(BatCountry)
cmake_minimum_required(VERSION 2.8)

set (CMAKE_CXX_STANDARD 11)

find_package(Git REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

execute_process(
	COMMAND ${GIT_EXECUTABLE} describe
	OUTPUT_VARIABLE GIT_DESCRIBE
	OUTPUT_STRIP_TRAILING_WHITESPACE
)
execute_process(
	COMMAND date -Is
	OUTPUT_VARIABLE BUILD_DATE
	OUTPUT_STRIP_TRAILING_WHITESPACE
)
set(VERSION ${GIT_DESCRIBE})
configure_file(source/version.h.in version.h)


set(
	SRCS
	source/actor.cpp
	source/basewidget.cpp
	source/buywidget.cpp
	source/enemies/bat.cpp
	source/enemies/demonbat.cpp
	source/enemies/enemy.cpp
	source/fullscreenhandler.cpp
	source/gameoverwidget.cpp
	source/gamestatistics.cpp
	source/gamewidget.cpp
	source/graphics/bitmap.cpp
	source/graphics/bitmapgraphicsdevice.cpp
	source/graphics/canvas.cpp
	source/graphics/element.cpp
	source/graphics/graphicsdevice.cpp
	source/graphics/images.cpp
	source/graphics/widget.cpp
	source/graphics/widgetstack.cpp
	source/input/allegroinputengine.cpp
	source/input/inputengine.cpp
	source/input/inputhandler.cpp
	source/introwidget.cpp
	source/itemdrops/itemdrop.cpp
	source/itemdrops/itemdropfactory.cpp
	source/main.cpp
	source/modifiers/modifier.cpp
	source/modifiers/modifierlistitem.cpp
	source/modifiers/modifiermanager.cpp
	source/options/optionswidget.cpp
	source/particle.cpp
	source/sound/allegroengine.cpp
	source/sound/allegrosource.cpp
	source/sound/audioengine.cpp
	source/utilities/point.cpp
	source/utilities/pointf.cpp
	source/utilities/random.cpp
	source/utilities/rect.cpp
	source/utilities/rectf.cpp
	source/utilities/timer.cpp
	source/weapons/bullet.cpp
	source/weapons/genericbullet.cpp
	source/weapons/grenade.cpp
	source/weapons/grenadelauncher.cpp
	source/weapons/machinegun.cpp
	source/weapons/pistol.cpp
	source/weapons/rifle.cpp
	source/weapons/rocket.cpp
	source/weapons/rocketlauncher.cpp
	source/weapons/shotgun.cpp
	source/weapons/weapon.cpp
	source/worldobject.cpp

)

include_directories(source)

add_executable(batcountry ${SRCS})
target_link_libraries(batcountry PRIVATE allegro allegro_audio allegro_image allegro_acodec)
