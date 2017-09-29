#pragma once

#include <map>
#include "json.hpp"
#include "fhir/datatypes/complex/Identifier.hpp"
#include "fhir/datatypes/complex/Reference.hpp"
#include "fhir/datatypes/complex/CodeableConcept.hpp"
#include "fhir/datatypes/primitive.hpp"

using namespace std;
using json = nlohmann::json;

namespace LongBall {
  namespace fhir {
    namespace backboneelement {
      namespace encounter {
        
        struct Hospitalization {
          Identifier preAdmissionIdentifier;
          Reference origin;
          CodeableConcept admitSource;
          Reference admittingDiagnosis;
          CodeableConcept reAdmission;
          CodeableConcept dietPreference;
          CodeableConcept specialCourtesy;
          CodeableConcept specialArrangement;
          Reference destination;
          CodeableConcept dischargeDisposition;
          Reference dischargeDiagnosis;
        };

        void to_json(json& j, const Hospitalization& p) {
          j = json{
            { "preAdmissionIdentifier", p.preAdmissionIdentifier },
            { "origin", p.origin },
            { "admitSource", p.admitSource },
            { "admittingDiagnosis", p.admittingDiagnosis },
            { "reAdmission", p.reAdmission },
            { "dietPreference", p.dietPreference },
            { "specialCourtesy", p.specialCourtesy },
            { "specialArrangement", p.specialArrangement },
            { "destination", p.destination },
            { "dischargeDisposition", p.dischargeDisposition },
            { "dischargeDiagnosis", p.dischargeDiagnosis }
          };
        }

        void from_json(const json& j, Hospitalization& p) {
          p.preAdmissionIdentifier = j.value("preAdmissionIdentifier", Identifier{});
          p.origin = j.value("origin", Reference{});
          p.admitSource = j.value("admitSource", CodeableConcept{});
          p.admittingDiagnosis = j.value("admittingDiagnosis", Reference{});
          p.reAdmission = j.value("reAdmission", CodeableConcept{});
          p.dietPreference = j.value("dietPreference", CodeableConcept{});
          p.specialCourtesy = j.value("specialCourtesy", CodeableConcept{});
          p.specialArrangement = j.value("specialArrangement", CodeableConcept{});
          p.destination = j.value("destination", Reference{});
          p.dischargeDisposition = j.value("dischargeDisposition", CodeableConcept{});
          p.dischargeDiagnosis = j.value("dischargeDiagnosis", Reference{});
        }
      }
    }
  }
}
