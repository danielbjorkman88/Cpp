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


TEST( systemTest, EightBody ) {

    std::ifstream input{ "resources/nbody/eight-body-system.txt" };
    nbody::Simulation sim{input};
    nbody::System *system = sim.getSystem();
    nbody::Body* body = sim.getfirstBody();
    Vector3f force = body->force();

    ASSERT_FLOAT_EQ( force.x(), 0 );
    ASSERT_FLOAT_EQ( force.y(), 0 );
    ASSERT_FLOAT_EQ( force.z(), 0 );

    system->update( 100 );
    body = sim.getfirstBody();
    force = body->force();
    ASSERT_FLOAT_EQ( force.x(), 56.540859 );
    ASSERT_FLOAT_EQ( force.y(), -143.56454 );
    ASSERT_FLOAT_EQ( force.z(), 0 );

}


TEST( systemTest, ThreeBody ) {

    std::ifstream input{ "resources/nbody/three-body-system.txt" };
    nbody::Simulation sim{input};
    nbody::System *system = sim.getSystem();
    nbody::Body* body = sim.getfirstBody();
    Vector3f force = body->force();

    ASSERT_FLOAT_EQ( force.x(), 0 );
    ASSERT_FLOAT_EQ( force.y(), 0 );
    ASSERT_FLOAT_EQ( force.z(), 0 );

    system->update( 100 );
    body = sim.getfirstBody();
    force = body->force();
    ASSERT_FLOAT_EQ( force.x(), 18.608322 );
    ASSERT_FLOAT_EQ( force.y(), -7.1847086 );
    ASSERT_FLOAT_EQ( force.z(), 0 );

}


TEST( systemTest, fourBody ) {

    std::ifstream input{ "resources/nbody/four-body-system.txt" };
    nbody::Simulation sim{input};
    nbody::System *system = sim.getSystem();
    nbody::Body* body = sim.getfirstBody();
    Vector3f force = body->force();

    ASSERT_FLOAT_EQ( force.x(), 0 );
    ASSERT_FLOAT_EQ( force.y(), 0 );
    ASSERT_FLOAT_EQ( force.z(), 0 );

    system->update( 100 );
    body = sim.getfirstBody();
    force = body->force();
    ASSERT_FLOAT_EQ( force.x(), 40.969002 );
    ASSERT_FLOAT_EQ( force.y(), 37.536652 );
    ASSERT_FLOAT_EQ( force.z(), 0 );

}


TEST( systemTest, fiveBody ) {

    std::ifstream input{ "resources/nbody/five-body-system.txt" };
    nbody::Simulation sim{input};
    nbody::System *system = sim.getSystem();
    nbody::Body* body = sim.getfirstBody();
    Vector3f force = body->force();

    ASSERT_FLOAT_EQ( force.x(), 0 );
    ASSERT_FLOAT_EQ( force.y(), 0 );
    ASSERT_FLOAT_EQ( force.z(), 0 );

    system->update( 100 );
    body = sim.getfirstBody();
    force = body->force();
    ASSERT_FLOAT_EQ( force.x(), 40.969002 );
    ASSERT_FLOAT_EQ( force.y(), -162.46335 );
    ASSERT_FLOAT_EQ( force.z(), 0 );

}



TEST( systemTest, sixBody ) {

    std::ifstream input{ "resources/nbody/six-body-system.txt" };
    nbody::Simulation sim{input};
    nbody::System *system = sim.getSystem();
    nbody::Body* body = sim.getfirstBody();
    Vector3f force = body->force();

    ASSERT_FLOAT_EQ( force.x(), 0 );
    ASSERT_FLOAT_EQ( force.y(), 0 );
    ASSERT_FLOAT_EQ( force.z(), 0 );

    system->update( 100 );
    body = sim.getfirstBody();
    force = body->force();
    ASSERT_FLOAT_EQ( force.x(), 55.279839 );
    ASSERT_FLOAT_EQ( force.y(), -155.30794 );
    ASSERT_FLOAT_EQ( force.z(), 0 );

}



TEST( systemTest, sevenBody ) {

    std::ifstream input{ "resources/nbody/seven-body-system.txt" };
    nbody::Simulation sim{input};
    nbody::System *system = sim.getSystem();
    nbody::Body* body = sim.getfirstBody();
    Vector3f force = body->force();

    ASSERT_FLOAT_EQ( force.x(), 0 );
    ASSERT_FLOAT_EQ( force.y(), 0 );
    ASSERT_FLOAT_EQ( force.z(), 0 );

    system->update( 100 );
    body = sim.getfirstBody();
    force = body->force();
    ASSERT_FLOAT_EQ( force.x(), 56.540859 );
    ASSERT_FLOAT_EQ( force.y(), -156.06454 );
    ASSERT_FLOAT_EQ( force.z(), 0 );

}



TEST( systemTest, nineBody ) {

    std::ifstream input{ "resources/nbody/nine-body-system.txt" };
    nbody::Simulation sim{input};
    nbody::System *system = sim.getSystem();
    nbody::Body* body = sim.getfirstBody();
    Vector3f force = body->force();

    ASSERT_FLOAT_EQ( force.x(), 0 );
    ASSERT_FLOAT_EQ( force.y(), 0 );
    ASSERT_FLOAT_EQ( force.z(), 0 );

    system->update( 100 );
    body = sim.getfirstBody();
    force = body->force();
    ASSERT_FLOAT_EQ( force.x(), 72.388191 );
    ASSERT_FLOAT_EQ( force.y(), -150.35626 );
    ASSERT_FLOAT_EQ( force.z(), 0 );

}



TEST( systemTest, seventeenBody ) {

    std::ifstream input{ "resources/nbody/seventeen-body-system.txt" };
    nbody::Simulation sim{input};
    nbody::System *system = sim.getSystem();
    nbody::Body* body = sim.getfirstBody();
    Vector3f force = body->force();

    ASSERT_FLOAT_EQ( force.x(), 0 );
    ASSERT_FLOAT_EQ( force.y(), 0 );
    ASSERT_FLOAT_EQ( force.z(), 0 );

    system->update( 100 );
    body = sim.getfirstBody();
    force = body->force();
    ASSERT_FLOAT_EQ( force.x(),  30.417852 );
    ASSERT_FLOAT_EQ( force.y(), -117.938 );
    ASSERT_FLOAT_EQ( force.z(), 0 );

}

TEST( systemTest, 100Body ) {

    std::ifstream input{ "resources/nbody/100-body-system.txt" };
    nbody::Simulation sim{input};
    nbody::System *system = sim.getSystem();
    nbody::Body* body = sim.getfirstBody();
    Vector3f force = body->force();

    ASSERT_FLOAT_EQ( force.x(), 0 );
    ASSERT_FLOAT_EQ( force.y(), 0 );
    ASSERT_FLOAT_EQ( force.z(), 0 );

    system->update( 100 );
    body = sim.getfirstBody();
    force = body->force();
    ASSERT_FLOAT_EQ( force.x(),  2359.7883 );
    ASSERT_FLOAT_EQ( force.y(), 3977.7556 );
    ASSERT_FLOAT_EQ( force.z(), 0 );

}
