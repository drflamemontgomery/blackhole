#include "blackhole_funcs.h"

template <typename T, std::size_t N>
std::size_t array_len(T(&)[N])
{
	return N;
}
