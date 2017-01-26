#include "stdafx.h"
#include "terrain.h"

void InitTiles(strIngame* _Ingame) {
	for (int x = 0; x < SIZETERX; x++)
	{
		for (int y = 0; y < SIZETERY; y++)
		{
			_Ingame->terrain.tiles[x][y].isMovible == false;
			_Ingame->terrain.tiles[x][y].position = (sfVector2f) { x, y };
		}
	}
}

void UpdateTiles(strIngame* _Ingame, strUtils* _Utils) {

}