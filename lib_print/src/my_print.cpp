#include "my_print.h"
#include "my_math.h"
#include <iostream>
namespace libB{
    void my_print(uint64_t a, uint64_t b) {
        auto ret = ns::add(a,b);
	ret = ns::add(ret, ns::counter);
        std::cout<<"result:"<<ret<<"\n";
    }
}
