#ifndef DEBUG_H
#define DEBUG_H
#define DEBUG(x) do { \
  if (IS_DEBUG_ON) { std::cerr << x << std::endl; } \
} while (0)
#endif
