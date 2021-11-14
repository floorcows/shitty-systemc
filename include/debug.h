#ifndef DEBUG_H
#define DEBUG_H
#define IS_DEBUG_ON 0
#define DEBUG(x) do { \
  if (IS_DEBUG_ON) { std::cerr << x << std::endl; } \
} while (0)
#endif
