#include "game.h"

void start_game(
    char map[MAP_HEIGHT][MAP_WIDTH],
    int *diamondsToWin,
    int *levelScore,
    int *scorePerDiamond,
    ENTITIES_QUANTITIES *entitiesQuantities,
    char *mapFile,
    ROCKFORD *player,
    BOULDER **boulders,
    DIRT **dirts,
    DIAMOND **diamonds,
    STEEL_WALL **steelWalls,
    WALL **walls,
    EXIT *rockfordEntrance,
    EXIT *levelExit)
{
    init_entities_count(entitiesQuantities);
    read_map(map, mapFile, entitiesQuantities, diamondsToWin, scorePerDiamond, levelScore);

    rockford_init_map(player, map, player->lives == -1);
    rockford_entrance_init(player, rockfordEntrance);

    alloc_entities(entitiesQuantities, boulders, diamonds, dirts, steelWalls, walls);

    init_map(map, *boulders, *diamonds, *dirts, *steelWalls, *walls, levelExit);
}