#ifndef _CONFIG_H_
#define _CONFIG_H_

#ifdef _WIN32
#include <winsock2.h>
#include <windows.h>
#undef max
#undef min
#else
#define swprintf_s swprintf
#endif

#ifdef _MSC_VER
#define ATTR_PACKED()
#else
#define ATTR_PACKED() __attribute__((packed))
#endif

#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <deque>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <stdint.h>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cstdarg>

#endif // _CONFIG_H_
