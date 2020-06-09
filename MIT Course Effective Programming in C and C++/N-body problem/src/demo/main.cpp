#include <nbody/Simulation.h>

#include <iostream>
#include <fstream>
#include <unistd.h>
#include <GLFW/glfw3.h>


int main() {
  try {
    std::ifstream input{ "resources/nbody/collision-scenario.txt" };
    nbody::Simulation sim{input};
    ///nbody::Body* body = sim.getfirstBody();
    ///Vector3f position = body->position();
    ///std::cout << position.x() << std::endl;
    ///chdir("/tmp");
    int nSimulations = 80;
    for( int i = 0; i < nSimulations; ++i ) {
      std::cout << "==EVOLUTION " << i + 1 << "\n";
      sim.saveRun(i);
      sim.evolveSystem( 1e4, 0.0000005 );
    }
    sim.saveRun(nSimulations);
    return 0;
  } catch( const std::exception &e ) {
    std::cerr << "Error: " << e.what() << "\n";
    return 1;
  }
}
