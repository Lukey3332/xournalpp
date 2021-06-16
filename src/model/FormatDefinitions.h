/*
 * Xournal++
 *
 * Abstract gui class, which loads the glade objcts
 *
 * @author Xournal++ Team
 * https://github.com/xournalpp/xournalpp
 *
 * @license GNU GPLv2 or later
 */

#include <cstdint>

#pragma once

typedef struct {
    const char* name;
    const double scale;
} FormatUnits;

extern const FormatUnits XOJ_UNITS[];
extern const int64_t XOJ_UNIT_COUNT;
