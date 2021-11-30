#include "game.h"

//Start/restart the game
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
    EXIT *rockfordEntrance,
    EXIT *levelExit)
{
    //initialize the entities counter
    init_entities_count(entitiesQuantities);
    //read the map file
    read_map(map, mapFile, entitiesQuantities, mapData);

    //init the Rockford
    rockford_init_map(player, map, player->lives < 0);
    rockford_entrance_init(player, rockfordEntrance);

    //Allocate the array of entities
    alloc_entities(entitiesQuantities, boulders, diamonds, dirts, steelWalls, walls);

    //Initialize the map
    init_map(map, *boulders, *diamonds, *dirts, *steelWalls, *walls, levelExit);
}