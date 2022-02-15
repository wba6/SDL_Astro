#include "Astro/randomness.h"

static std::random_device dev;
std::default_random_engine randomness::engine{dev()};
