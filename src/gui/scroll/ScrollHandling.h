/*
 * Xournal++
 *
 * Scroll handling for different scroll implementations
 *
 * @author Xournal++ Team
 * https://github.com/xournalpp/xournalpp
 *
 * @license GNU GPLv2 or later
 */

#pragma once

#include <string>
#include <vector>

#include <gtk/gtk.h>

#include "XournalType.h"

class Layout;

class ScrollHandling {
public:
    ScrollHandling(GtkAdjustment* adjHorizontal, GtkAdjustment* adjVertical);
    ScrollHandling(GtkScrollable* scrollable);
    ~ScrollHandling();

public:
    GtkAdjustment* getHorizontal();
    GtkAdjustment* getVertical();

    void init(GtkWidget* xournal, Layout* layout);

    void setLayoutSize(int64_t width, int64_t height);

    int64_t getPreferredWidth();
    int64_t getPreferredHeight();

private:
protected:
    GtkAdjustment* adjHorizontal = nullptr;
    GtkAdjustment* adjVertical = nullptr;

    GtkWidget* xournal = nullptr;
    Layout* layout = nullptr;
};
