#pragma once

#include <vector>
#include <map>
#include "json.hpp"
#include "fhir/datatypes/complex/Period.hpp"
#include "fhir/datatypes/complex/Quantity.hpp"
#include "fhir/datatypes/complex/CodeableConcept.hpp"
#include "fhir/datatypes/complex/Range.hpp"
#include "fhir/datatypes/primitive.hpp"

using namespace std;
using json = nlohmann::json;
namespace primitive = LongBall::fhir::datatypes::primitive;
namespace complex = LongBall::fhir::datatypes::complex;

namespace LongBall {
  namespace fhir {
    namespace datatypes {

      enum class UnitOfTime {
        Second, Minute, Hour, Day, Week, Month, Annual
      };

      map<UnitOfTime, string> unitOfTime{
        { UnitOfTime::Second, "s" },
        { UnitOfTime::Minute, "min" },
        { UnitOfTime::Hour, "h" },
        { UnitOfTime::Day, "d" },
        { UnitOfTime::Week, "wk" },
        { UnitOfTime::Month, "mo" },
        { UnitOfTime::Annual, "a" }
      };

      enum class EventTiming {
        BeforeSleep, Wake, Meal, Breakfast, Lunch, Dinner, BeforeMeal, BeforeBreakfast, BeforeLunch, BeforeDinner, AfterMeal, AfterBreakfast, AfterLunch, AfterDinner
      };

      map<EventTiming, string> eventTiming{
        { EventTiming::BeforeSleep, "HS" },
        { EventTiming::Wake, "WAKE" },
        { EventTiming::Meal, "C" },
        { EventTiming::Breakfast, "CM" },
        { EventTiming::Lunch, "CD" },
        { EventTiming::Dinner, "CV" },
        { EventTiming::BeforeMeal, "AC" },
        { EventTiming::BeforeBreakfast, "ACM" },
        { EventTiming::BeforeLunch, "ACD" },
        { EventTiming::BeforeDinner, "ACV" },
        { EventTiming::AfterMeal, "PC" },
        { EventTiming::AfterBreakfast, "PCM" },
        { EventTiming::AfterLunch, "PCD" },
        { EventTiming::AfterDinner, "PCV" }
      };

      enum class TimingAbbreviation {
        Everyday, EveryOtherDay, Every4Hours, Every6Hours, TwoTimesADay, ThreeTimesADay, FourTimesADay, EveryMorning, EveryAfternoon
      };

      map<TimingAbbreviation, string> timingAbbreviation{
        { TimingAbbreviation::Everyday, "QD" },
        { TimingAbbreviation::EveryOtherDay, "QOD" },
        { TimingAbbreviation::Every4Hours, "Q4H" },
        { TimingAbbreviation::Every4Hours, "Q6H" },
        { TimingAbbreviation::TwoTimesADay, "BID" },
        { TimingAbbreviation::ThreeTimesADay, "TID" },
        { TimingAbbreviation::EveryMorning, "AM" },
        { TimingAbbreviation::EveryAfternoon, "PM" }
      };

      namespace complex {
        struct TimingRepeat {
          complex::Quantity boundsQuantity;
          complex::Range boundsRange;
          complex::Period boundsPeriod;
          primitive::integer count;
          primitive::decimal duration;
          primitive::decimal durationMax;
          primitive::code durationUnits; // s | min | h | d | wk | mo | a - unit of time (UCUM)
          primitive::integer frequency;
          primitive::integer frequencyMax;
          primitive::decimal period; // s | min | h | d | wk | mo | a - unit of time (UCUM)
          primitive::decimal periodMax;
          primitive::code periodUnits;
          primitive::code when; // https://www.hl7.org/fhir/DSTU2/valueset-event-timing.html HS|WAKE|C|CM|CD|CV|AC|ACM|ACD|ACV|PC|PCM|PCD|PCV
        };

        void to_json(json& j, const TimingRepeat& p) {
          j = json{
            { "boundsQuantity", p.boundsQuantity },
            { "boundsRange", p.boundsRange },
            { "boundsPeriod", p.boundsPeriod },
            { "count", p.count },
            { "duration", p.duration },
            { "durationMax", p.durationMax },
            { "durationUnits", p.durationUnits },
            { "frequency", p.frequency },
            { "frequencyMax", p.frequencyMax },
            { "period", p.period },
            { "periodMax", p.periodMax },
            { "periodUnits", p.periodUnits },
            { "when", p.when }
          };
        }

        void from_json(const json& j, TimingRepeat& p) {
          p.boundsQuantity = j.value("boundsQuantity", Quantity{});
          p.boundsRange = j.value("boundsRange", Range{});
          p.boundsPeriod = j.value("boundsPeriod", Period{});
          p.count = j.value("count", 0);
          p.duration = j.value("duration", 0);
          p.durationMax = j.value("durationMax", 0);
          p.durationUnits = j.value("durationUnits", "");
          p.frequency = j.value("frequency", 0);
          p.frequencyMax = j.value("frequencyMax", 0);
          p.period = j.value("period", 0);
          p.periodMax = j.value("periodMax", 0);
          p.when = j.value("when", nullptr);
        }

        struct Timing {
          vector<primitive::dateTime> event;
          complex::TimingRepeat repeat;
          complex::CodeableConcept code; // QD | QOD | Q4H | Q6H | BID | TID | QID | AM | PM +
        };

        void to_json(json& j, const Timing& p) {
          j = json{
            { "event", p.event }, // home | work | temp | old - purpose of this addres
            { "repeat", p.repeat }, // postal | physical | both
            { "code", p.code }
          };
        }

        void from_json(const json& j, Timing& p) {
          p.repeat = j.value("repeat", TimingRepeat{});
          p.code = j.value("code", CodeableConcept{});

          for (const auto& e : j.value("event", json::array({}))) {
            p.event.emplace_back(e.get<std::string>());
          }
        }
      }
    }
  }
}
