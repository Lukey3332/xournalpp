#include "HexObjectEncoding.h"

#include <cinttypes>
#include <cstdio>

HexObjectEncoding::HexObjectEncoding() = default;

HexObjectEncoding::~HexObjectEncoding() = default;

void HexObjectEncoding::addData(const void* data, int64_t len) {
    char* buffer = static_cast<char*>(g_malloc(len * 2));

    for (int64_t i = 0; i < len; i++) {
        uint8_t x = static_cast<uint8_t const*>(data)[i];
        sprintf(&buffer[i * 2], "%02" PRIx8, x);
    }

    g_string_append_len(this->data, buffer, len * 2);

    g_free(buffer);
}
