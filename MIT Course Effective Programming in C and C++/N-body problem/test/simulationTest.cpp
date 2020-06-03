#include <nbody/Simulation.h>
#include <gtest/gtest.h>
#include <string>
#include <iostream>
#include <fstream>
#include <unistd.h>

TEST( simulationTest, getName ) {

  nbody::Simulation sim{};
  std::string name = sim.getName();

  ASSERT_FLOAT_EQ( name.length() , 17 );
}




TEST( simulationTest, firstbodyEvolution ) {

    std::ifstream input{ "resources/nbody/binary-system-simple.txt" };

    nbody::Simulation sim{input};
    nbody::Body* body = sim.getfirstBody();
    Vector3f position = body->position();
    Vector3f velocity = body->velocity();
    Vector3f force = body->force();

    ASSERT_FLOAT_EQ( position.x(), -0.5 );
    ASSERT_FLOAT_EQ( position.y(), 0 );
    ASSERT_FLOAT_EQ( position.z(), 0 );
    ASSERT_FLOAT_EQ( velocity.x(), 0 );
    ASSERT_FLOAT_EQ( velocity.y(), 0.707 );
    ASSERT_FLOAT_EQ( velocity.z(), 0 );
    ASSERT_FLOAT_EQ( force.x(), 0 );
    ASSERT_FLOAT_EQ( force.y(), 0 );
    ASSERT_FLOAT_EQ( force.z(), 0 );
    ASSERT_FLOAT_EQ( body->mass() , 10 );

    sim.evolveSystem( 1e4, 0.1 );
    body = sim.getfirstBody();
    position = body->position();
    velocity = body->velocity();
    force = body->force();


    ASSERT_FLOAT_EQ( position.x(), 7308.3071 );
    ASSERT_FLOAT_EQ( position.y(), -3473.6187 );
    ASSERT_FLOAT_EQ( position.z(), 0 );
    ASSERT_FLOAT_EQ( velocity.x(), 7.3099637 );
    ASSERT_FLOAT_EQ( velocity.y(), -3.474721 );
    ASSERT_FLOAT_EQ( velocity.z(), 0 );
    ASSERT_FLOAT_EQ( force.x(), -3.4491077e-08 );
    ASSERT_FLOAT_EQ( force.y(), 1.6393516e-08 );
    ASSERT_FLOAT_EQ( force.z(), 0 );
    ASSERT_FLOAT_EQ( body->mass() , 10 );


}


