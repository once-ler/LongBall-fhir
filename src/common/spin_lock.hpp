#pragma once

#include <atomic>

namespace LongBall {
  namespace common {
    namespace util {

      class Spinlock {
        std::atomic_flag lock_;
      public:
        Spinlock() {
          lock_.clear();
        }

        inline void lock() {
          while (lock_.test_and_set(std::memory_order_acquire));
        }

        inline void unlock() {
          lock_.clear(std::memory_order_release);
        }

        inline bool try_lock() {
          return !lock_.test_and_set(std::memory_order_acquire);
        }
      };

    }
  }
}
