#pragma once
// TETHER1 container (real-model weights, Path A):
//   magic "TETH" + u32 version (=1) + u32 n + u32 k
//   + n*k int8 ternary weights (row-major)
//   + n fp32 gamma values (absmean scales)
// Written by tools/export_weights.py (Python) and tether::write_tether1
// (C++); constants must stay in sync on both sides.

#include <cstdint>
#include <string>
#include <vector>

namespace tether {

struct LoadedWeights {
    uint32_t n = 0; // weight rows (outputs)
    uint32_t k = 0; // reduction dim
    std::vector<int8_t> weights;
    std::vector<float> gamma;
};

bool write_tether1(const std::string& path, const int8_t* weights, uint32_t n, uint32_t k,
                   const float* gamma);
bool load_tether1(const std::string& path, LoadedWeights& out);

} // namespace tether
