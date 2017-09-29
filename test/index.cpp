#include "LongBall-fhir.hpp"
#include <fstream>

namespace test {
  int spec0_default_model() {
    Encounter encounter;
    json j = encounter;

    ofstream out("default_encounter.json");
    out << j.dump(2);
    out.close();

    Observation observation;
    json j2 = observation;

    ofstream out2("default_observation.json");
    out2 << j2.dump(2);
    out2.close();
  }
}

using namespace test;

int main() {
  cout << "Version: " << LongBall::fhir::meta::version << endl;
  spec0_default_model();
}
