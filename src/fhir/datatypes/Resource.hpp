#pragma once

#include <iostream>
#include <future>
#include "json.hpp"
#include "common/util.hpp"
#include "common/spin_lock.hpp"
#include <async++.h>

using namespace std;
using namespace LongBall::common::util;
using json = nlohmann::json;

namespace LongBall {
  namespace fhir {
    namespace resource {

      // TODO
      class Patient;
      class DocumentReference;
      class MessageHeader;
      
      /*
      template<typename resourceType>
      class Resource {
      public:
        Resource() {}
        ~Resource() {}
      };
      */

      template<typename resourceType>
      class IResource {
      public:
        IResource(const json& j) : j_(j) {
          model = j_[modelName_];
        }
        ~IResource() {};
      protected:
        string modelName_ = "ROOT";
        json model;
        map<string, function<json()>> mapdict;
        virtual json parse() noexcept {
          json j__;
/*
          async::parallel_for(mapdict, [&j__, this](const pair<string, function<json()>>& p) {
            auto func = p.second;
            // json.hpp is not thread-safe; https://stackoverflow.com/questions/44420309/json-for-modern-c-thread-safe
            lock_.lock();
            j__[p.first] = func();
            lock_.unlock();
          });
*/
          for (const auto& p : mapdict) {
            auto func = p.second;
            j__[p.first] = func();
          }

          auto timestamp = getCurrentTimeMilliseconds();
          j__["ts"] = timestamp;
          j__["dateModified"] = {
            { "$date", timestamp }
          };

          return j__;
        }
      private:
        Spinlock lock_;
        json j_;
      };
    
    }
  }
}
