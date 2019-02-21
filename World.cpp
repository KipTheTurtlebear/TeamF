#include "World.h"

/*Tile * World::GetTileAtLoc(int x, int y)
{




}
*/

World * World::GenerateWorld(int szX, int szY, int seed, Program * program)
{
  referenceToProgram = program;
  map = new Tile[szX][szY];
  for (int x = 0; x < szX; x++)
  {
    for (int y = 0; y < szY; y++)
    {
    //  map[x][y]
    }
  }
}
