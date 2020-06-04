#include <nbody/Simulation.h>
#include <gtest/gtest.h>
#include <string>
#include <iostream>
#include <fstream>
#include <unistd.h>

TEST( systemTest, GravityComputation ) {

    std::ifstream input{ "resources/nbody/binary-system-simple.txt" };
    nbody::Simulation sim{input};
    nbody::System *system = sim.getSystem();
    nbody::Body* body = sim.getfirstBody();
    Vector3f force = body->force();

    ASSERT_FLOAT_EQ( force.x(), 0 );
    ASSERT_FLOAT_EQ( force.y(), 0 );
    ASSERT_FLOAT_EQ( force.z(), 0 );

    system->computeGravitation();


    body = sim.getfirstBody();
    force = body->force();
    ASSERT_FLOAT_EQ( force.x(), 10 );
    ASSERT_FLOAT_EQ( force.y(), 0 );
    ASSERT_FLOAT_EQ( force.z(), 0 );


}


TEST( systemTest, GravityComputationThread ) {

    std::ifstream input{ "resources/nbody/eight-body-system.txt" };
    nbody::Simulation sim{input};
    nbody::System *system = sim.getSystem();
    nbody::Body* body = sim.getfirstBody();
    Vector3f force = body->force();

    ASSERT_FLOAT_EQ( force.x(), 0 );
    ASSERT_FLOAT_EQ( force.y(), 0 );
    ASSERT_FLOAT_EQ( force.z(), 0 );
    system->computeGravitation();

}
