#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
#include "Vector.h"
#include "Color.h"
#include "Dimension.h"

// Weights for birds to fly properly
#define ALLIGNMENT_WEIGHT 1.0 
#define COHESION_WEIGHT 1.0 
#define SEPARATION_WEIGHT 1.5 

// Other constants
#define SEPARATION_DISTANCE 25.0 
#define ALLIGNMENT_DISTANCE 50.0 
#define COHESION_DISTANCE 50.0 


class Bird
{
public:
	float MAX_SPEED = 2.0 / 15;
	float MAX_FORCE = 0.03 / 10;
	float BIRD_RADIUS = 5.0f;  // Radius of the bird (I have choose MAX point of bird triangle points)

	// Properties
	Vector position;
	Vector velocity;
	Vector acceleration;
	float rotation;
	Color color;
	Dimension window_dimensions;

	Bird(Dimension);
	~Bird();

	// General
	void report();
	void rotate();
	void update();
	void applyForce(Vector);
	void run(Bird ***grid, int *bird_counts, Dimension grid_size, int cell_size);
	Vector seek(Vector);
	void borders();

	// Main calculation
	void calculate(Bird ***grid, int *bird_counts, Dimension grid_size, int cell_size);
};

