#include "stdafx.h"

//------------------------------------------Initialisation
void InitUtils(strUtils* _Utils)
{
	//Window
	sfVideoMode mode = { SCRSIZEX, SCRSIZEY, 32 };
	_Utils->window = sfRenderWindow_create(mode, TITLE, sfResize | sfClose, NULL);
	sfRenderWindow_setMouseCursorVisible(_Utils->window, sfFalse);

	//Deltaclock   
	_Utils->deltaclock = sfClock_create();
}
void InitIngame(strIngame* _Ingame)
{
	LoadSpriteLib(_Ingame);

	InitTiles(_Ingame);

}

//------------------------------------------Update
void Control(strUtils* _Utils, strIngame* _Ingame)
{
	if (_Utils->event.type == sfEvtClosed)
		sfRenderWindow_close(_Utils->window);
}

void Update(strUtils* _Utils, strIngame* _Ingame)
{
	sfVector2i tempmp = sfMouse_getPositionRenderWindow(_Utils->window);
	_Utils->mousepos = (sfVector2f){ tempmp.x,tempmp.y };



	UpdateTiles(_Ingame, _Utils);
}

//------------------------------------------Affichage
void Display(strUtils* _Utils, strIngame* _Ingame)
{
	sfRenderWindow_clear(_Utils->window, sfBlack);


	for (int x = 0; x < SIZETERX; x++)
		for (int y = 0; y < SIZETERY; y++)
			BlitSprite(_Ingame->spritelib.tile32, (sfVector2f) { _Ingame->terrain.tiles[x][y].position.x * 32, _Ingame->terrain.tiles[x][y].position.y * 32 }, 0, _Utils->window);

	BlitSprite(_Ingame->spritelib.cursor, _Utils->mousepos, 0, _Utils->window);
	
	
	sfRenderWindow_display(_Utils->window);
}