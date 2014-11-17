#pragma once

enum KEY_ARROWS {UP, DOWN, LEFT, RIGHT};
extern bool key_arrows[4];
	
enum MOUSEBUTTONS {LMB, RMB};
extern bool mouse[2];

extern float mouseX;
extern float mouseY;


enum MOUSEACTION { DEFAULT, HOVER, CLICKED };