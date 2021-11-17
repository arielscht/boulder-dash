#include "maps.h"

void read_map(char map[MAP_HEIGHT][MAP_WIDTH], char *mapFileName, ENTITIES_QUANTITIES *entities)
{
    FILE *mapFile = fopen(mapFileName, "r");

    if (!mapFile)
        fprintf(stderr, "Error reading map file: %s", mapFileName);

    for (int i = 0; i < MAP_HEIGHT; i++)
    {
        for (int j = 0; j < MAP_WIDTH; j++)
        {
            fscanf(mapFile, "%c", &map[i][j]);
        }
        fgetc(mapFile);
    }

    for (int i = 0; i < MAP_HEIGHT; i++)
    {
        for (int j = 0; j < MAP_WIDTH; j++)
        {
            switch (map[i][j])
            {
            case MAP_DIRT:
                entities->dirt++;
                break;
            case MAP_BOULDER:
                entities->boulder++;
                break;
            case MAP_DIAMOND:
                entities->diamond++;
                break;
            case MAP_STEEL_WALL:
                entities->steelWall++;
                break;
            case MAP_WALL:
                entities->wall++;
                break;
            }
        }
    }

    fclose(mapFile);
}

void init_map(char map[MAP_HEIGHT][MAP_WIDTH], BOULDER *boulders,
              DIAMOND *diamonds,
              DIRT *dirts,
              STEEL_WALL *steelWalls,
              WALL *walls)
{
    int boulderIndex = 0;
    int diamondIndex = 0;
    int dirtIndex = 0;
    int steelWallIndex = 0;
    int wallIndex = 0;

    for (int i = 0; i < MAP_HEIGHT; i++)
    {
        for (int j = 0; j < MAP_WIDTH; j++)
        {
            switch (map[i][j])
            {
            case MAP_DIRT:
            {
                dirts[dirtIndex].x = SPRITE_WIDTH * j;
                dirts[dirtIndex].y = SPRITE_HEIGHT * (i + 1);
                dirts[dirtIndex].shown = true;
                dirtIndex++;
                break;
            }
            case MAP_BOULDER:
                boulders[boulderIndex].x = SPRITE_WIDTH * j;
                boulders[boulderIndex].y = SPRITE_HEIGHT * (i + 1);
                boulderIndex++;
                break;
            case MAP_DIAMOND:
                diamonds[diamondIndex].x = SPRITE_WIDTH * j;
                diamonds[diamondIndex].y = SPRITE_HEIGHT * (i + 1);
                diamonds[diamondIndex].shown = true;
                diamonds[diamondIndex].sourceX = 0;
                diamonds[diamondIndex].sourceY = 0;
                diamonds[diamondIndex].delay = 0;
                diamondIndex++;
                break;
            case MAP_STEEL_WALL:
                steelWalls[steelWallIndex].x = SPRITE_WIDTH * j;
                steelWalls[steelWallIndex].y = SPRITE_HEIGHT * (i + 1);
                steelWallIndex++;
                break;
            case MAP_WALL:
                walls[wallIndex].x = SPRITE_WIDTH * j;
                walls[wallIndex].y = SPRITE_HEIGHT * (i + 1);
                walls[wallIndex].shown = true;
                wallIndex++;
                break;
            }
        }
    }
}

void print_map(char map[MAP_HEIGHT][MAP_WIDTH])
{
    printf("\e[1;1H\e[2J");
    for (int i = 0; i < MAP_HEIGHT; i++)
    {
        for (int j = 0; j < MAP_WIDTH; j++)
        {
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }
}