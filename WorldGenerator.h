#pragma once
#include<iostream>
using namespace std;

class World;

class WorldGenerator
{
private:
    // Returns a Perlin Noise value between 0 and 1 based on the x and y
    float PerlinNoise(float x, float y, float seed);

public:
    // Generates the given world
    static void Generate(World* &worldToGenerate);
};