#include "stdafx.h"

void LoadSpriteLib(strIngame* _Ingame) {
	_Ingame->spritelib.tile32 = LoadSprite("../Assets/tile32.png", 0);
	_Ingame->spritelib.cursor = LoadSprite("../Assets/cursor.png", 0);
}