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
#define DEBUG_FG_COLOR		BLUE		/* Debug fg color */

/* Key input */
#define ENABLE_VIM_KEYS		1		/* 1 to enable, 0 to disbale */

/* Player physics */
#define PLAYER_ACCEL		600.0f		/* Acceleration */
#define PLAYER_FRICTION		4.0f		/* Friction */
#define PLAYER_MAX_SPEED	300.0f		/* Max speed */
#define PLAYER_ROT_SPEED	180.0f		/* Rotation speed */

/* Player [Entity] customizations stuffs */
#define PLAYER_ENTITY_COLOR	GRAY		/* Player Color [Entity] */
#define PLAYER_ENTITY_SIZE	20.0f		/* Player Size [Entity] */
#define PLAYER_ENTITY_SHAPE	3.0f		/* Shape as Number [Angles], eg: 3 = Triangle & != 0,1,2 */

/* Monster [Entity] */
#define MONSTER_MAX_COUNT	5		/* Max monster count */
#define MONSTER_COLOR		GRAY		/* Monster color */
#define MONSTER_SPEED		10		/* Monster color */
#define MONSTER_RADIUS		20		/* Monster radius (circle) */

#endif	/* CONFIG_H */
