/*
 * Xournal++
 *
 * Part of the customizable toolbars
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

class ToolbarItem {
public:
    ToolbarItem(string name);
    ToolbarItem();

public:
    const std::string& getName() const;

    bool operator==(ToolbarItem& other);

    int64_t getId() const;

private:
    string name;
    int64_t id;

    static int64_t sid;
};
