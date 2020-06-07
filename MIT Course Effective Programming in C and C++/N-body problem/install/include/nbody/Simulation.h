#ifndef _NBODY_SIMULATION_H
#define _NBODY_SIMULATION_H

#include <nbody/System.h>

#include <iosfwd>
#include <string>

namespace nbody {

  class Simulation {
    System *_system;
    std::string _name;
    Simulation( const Simulation& sim ) = delete;
    Simulation& operator=( const Simulation& sim ) = delete;
    std::string generateName();
  public:
    ~Simulation(){ }
    Simulation() : _system{nullptr}, _name{ generateName() } {}
    Simulation( std::istream &input ) : _system{new System(input)}, _name{ generateName() } {}
    std::string getName(){ return _name;};
    Body* getfirstBody() const { return _system->getBody();}
    System* getSystem() const { return _system;}
    void evolveSystem( int nSteps, float dt );
    void loadRun( std::istream &input );
    void saveRun(int i) const;
  };

} // namespace nbody

#endif // _NBODY_SIMULATION_H
