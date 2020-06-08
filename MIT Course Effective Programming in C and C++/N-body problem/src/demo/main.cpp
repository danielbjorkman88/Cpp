#include <nbody/Simulation.h>

#include <iostream>
#include <fstream>
#include <unistd.h>
#include <GLFW/glfw3.h>


int main() {
  try {
    std::ifstream input{ "resources/nbody/binary-system-simple.txt" };
    nbody::Simulation sim{input};
    ///nbody::Body* body = sim.getfirstBody();
    ///Vector3f position = body->position();
    ///std::cout << position.x() << std::endl;
    ///chdir("/tmp");
    for( int i = 0; i < 40; ++i ) {
      std::cout << "==EVOLUTION " << i + 1 << "\n";
      sim.saveRun(i);
      sim.evolveSystem( 1e4, 0.000001 );
    }
    sim.saveRun(40);
    return 0;
  } catch( const std::exception &e ) {
    std::cerr << "Error: " << e.what() << "\n";
    return 1;
  }
}
