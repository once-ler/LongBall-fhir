#pragma once

#include <iostream>

namespace LongBall {
  namespace fhir {
    namespace datatypes {
      namespace primitive {
        using boolean = bool;
        using integer = int;
        using string = std::string;
        //Implementations SHALL handle decimal values in ways that preserve and respect the precision of the value as represented for presentation purposes
        using decimal = double;
        using uri = std::string;
        using base64Binary = std::string;
        using instant = std::string;
        using dateTime = std::string;
        using date = std::string;
        using time = std::string;
        using code = std::string;
        using oid = std::string;
        using id = std::string;
        using unsignedInt = unsigned int;
        using positiveInt = unsigned int; // >= 1
      }
    }
  }
}
