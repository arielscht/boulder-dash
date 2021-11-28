#include "game.h"

void start_game(
    char map[MAP_HEIGHT][MAP_WIDTH],
    MAP_DATA *mapData,
    ENTITIES_QUANTITIES *entitiesQuantities,
    char *mapFile,
    ROCKFORD *player,
    BOULDER **boulders,
    DIRT **dirts,
    DIAMOND **diamonds,
    STEEL_WALL **steelWalls,
    WALL **walls,
    FIREFLY **fireflies,
    EXIT *rockfordEntrance,
    EXIT *levelExit)
{
    init_entities_count(entitiesQuantities);
    read_map(map, mapFile, entitiesQuantities, mapData);

    rockford_init_map(player, map, player->lives < 0);
    rockford_entrance_init(player, rockfordEntrance);

    alloc_entities(entitiesQuantities, boulders, diamonds, dirts, steelWalls, walls, fireflies);

    init_map(map, *boulders, *diamonds, *dirts, *steelWalls, *walls, *fireflies, levelExit);
}