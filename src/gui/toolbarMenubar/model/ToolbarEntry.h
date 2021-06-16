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

#include "ToolbarItem.h"

typedef vector<ToolbarItem*> ToolbarItemVector;

class ToolbarEntry {
public:
    ToolbarEntry();
    ToolbarEntry(const ToolbarEntry& e);
    ToolbarEntry(ToolbarEntry&& e);
    ~ToolbarEntry();

    ToolbarEntry& operator=(const ToolbarEntry& e);
    ToolbarEntry& operator=(ToolbarEntry&& e);

public:
    void clearList();

    string getName();
    void setName(string name);

    /**
     * Adds a new item and return the ID of the item
     */
    int64_t addItem(string item);
    bool removeItemById(int64_t id);

    /**
     * Insert a new item and return the ID of the item
     */
    int64_t insertItem(string item, int64_t position);

    const ToolbarItemVector& getItems() const;

private:
    string name;
    ToolbarItemVector entries;
};
