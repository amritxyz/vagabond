/* See LICENSE file for copyright and license details. */
#ifndef CONFIG_H
#define CONFIG_H

/* Main window */
#define WINDOW_W		1200		/* Window width */
#define WINDOW_H		800		/* Window height */
#define TITLE			"vagabond"	/* Window title */
#define CURRENT_FPS		60		/* FPS */
#define BG_COLOR		WHITE		/* Main bg color */

/* Debug info */
#define DEBUG_FONT_SIZE		20		/* Debug font size // TODO Make flexible */
#define DEBUG_INFO		1		/* 1 to enable, 0 to disbale */
#define DEBUG_FG_COLOR_PLAYER	GRAY		/* Debug fg color */
#define DEBUG_FG_COLOR_MONSTER	RED		/* Debug fg color */

/* Key input */
#define ENABLE_VIM_KEYS		1		/* 1 to enable, 0 to disbale */

/* Player physics */
#define PLAYER_ACCEL		600.0f		/* Acceleration for player */
#define PLAYER_FRICTION		2.0f		/* Friction for plyaer */
#define PLAYER_MAX_SPEED	300.0f		/* Max speed for player */
#define PLAYER_ROT_SPEED	180.0f		/* Rotation speed for player */

/* Player [Entity] customizations stuffs */
#define PLAYER_ENTITY_COLOR	GRAY		/* Player Color [Entity] */
#define PLAYER_ENTITY_SIZE	20.0f		/* Player Size [Entity] */
#define PLAYER_ENTITY_SHAPE	3.0f		/* Shape as Number [Angles], eg: 3 = Triangle & this_value !< 3 */

/* Monster [Entity] */
#define MONSTERS_LIMIT		5		/* Total number of monsters */
#define MONSTERS_COLOR		RED		/* Monster Color [Entity] TODO `Entities` */
#define MONSTERS_SPEED
#define MONSTERS_ACCELERATION	20		/* Acceleration for monster */

#endif	/* CONFIG_H */
