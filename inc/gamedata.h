#include "includes.h"

#ifndef GAMEDATA_H
#define GAMEDATA_H

#define MAP_EMPTY 0
#define MAP_SOLID 1
#define MAP_CIELING 2

// Index is tile number * 32
#define BG_BASE_VRAM_INDEX (512) * 32
#define BG_NUM_TILES 128
#define FG_BASE_VRAM_INDEX ((BG_BASE_VRAM_INDEX/32) + BG_NUM_TILES) * 32
#define FG_NUM_TILES 128

u8 mode;

u8 map_collision(u16 x, u16 y);
void load_font(u16 plan, u8 pal);
void bg_dma_tiles(void);

#endif
