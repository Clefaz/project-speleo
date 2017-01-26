#include "stdafx.h"

#define SCRSIZEX 500
#define SCRSIZEY 500
#define TITLE "EDIT NAME IN GAME.H"

#define SIZETERX 10
#define SIZETERY 10

//------------------------------------------Structures
typedef struct UTILS {
	//Engine
	sfRenderWindow* window;
	sfEvent event;

	//deltaclock
	sfClock* deltaclock;
	float deltatime;

	sfVector2f mousepos;
}strUtils;

typedef struct INGAME {
	struct SPRITELIB {
		sfSprite* tile32;
		sfSprite* cursor;
	}spritelib;

	struct TERRAIN {
		struct TILE {
			sfVector2f position;
			bool isMovible;
		}tiles[SIZETERX][SIZETERY];
	}terrain;
}strIngame;

//------------------------------------------Prototypes de fonctions
void InitUtils(strUtils* _Utils);
void InitIngame(strIngame* _Ingame);

void Control(strUtils* _Utils, strIngame* _Ingame);

void Update(strUtils* _Utils, strIngame* _Ingame);

void Display(strUtils* _Utils, strIngame* _Ingame);
