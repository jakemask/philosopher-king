#pragma once

#include <set>
#include <map>
#include <chrono>

#include "Building.h"
#include "Ship.h"
#include "Laser.h"

class RandomTrench
{
private:
	int start;
	int depth;

	float size;

	std::map<int,Building*> buildings;
	std::set<Laser*> lasers;

	bool above;
#ifdef WIN32
	std::chrono::time_point<std::chrono::system_clock> above_t;
#else
    std::chrono::time_point<std::chrono::steady_clock> above_t;
#endif

	float ticks;

public:
	RandomTrench(float size);
	~RandomTrench();
	void update(float, const Vector4&, int);
	void render();

	bool collision(const Ship&);
};

