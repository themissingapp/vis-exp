#include "my_math.h"
#include "my_math_export.h"
namespace ns{
    extern const int counter = 0;
    std::uint64_t add(std::uint64_t a, std::uint64_t b) {
        return a + b;
    }
}
