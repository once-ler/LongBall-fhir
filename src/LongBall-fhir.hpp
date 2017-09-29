#pragma once

#include "fhir/resource/Encounter.hpp"
#include "fhir/resource/Observation.hpp"

using namespace std;
using namespace LongBall::common::util;
using namespace LongBall::fhir::datatypes::complex;
using namespace LongBall::fhir::resource;

using json = nlohmann::json;

namespace LongBall {
  namespace fhir {
    namespace meta {
      static const string version = "0.13.8";
    }
  }
}
