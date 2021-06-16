/*
 * Xournal++
 *
 * A page range for PDF export etc. (e.g. 1-2,5,7)
 *
 * @author Xournal++ Team
 * https://github.com/xournalpp/xournalpp
 *
 * @license GNU GPLv2 or later
 */

#pragma once

#include <string>
#include <vector>

#include "XournalType.h"

class PageRangeEntry {
public:
    PageRangeEntry(int64_t first, int64_t last);
    virtual ~PageRangeEntry();

public:
    int64_t getLast() const;
    int64_t getFirst() const;

private:
    int64_t first;
    int64_t last;
};

typedef vector<PageRangeEntry*> PageRangeVector;

class PageRange {
private:
    PageRange();
    virtual ~PageRange();

public:
    static bool isSeparator(char c);
    static PageRangeVector parse(const char* str, int64_t pageCount);
};
