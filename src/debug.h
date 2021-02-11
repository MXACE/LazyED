#ifdef LED_DEBUG

#include <iostream>
#define DEBUG(x) std::cout << x << std::endl;

#else
#define DEBUG(x)
#endif