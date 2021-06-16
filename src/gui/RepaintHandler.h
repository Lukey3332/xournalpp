/*
 * Xournal++
 *
 * Class for render and repaint pages
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

class XojPageView;
class XournalView;

class RepaintHandler {
public:
    RepaintHandler(XournalView* xournal);
    virtual ~RepaintHandler();

public:
    /**
     * Repaint a page
     */
    void repaintPage(XojPageView* view);

    /**
     * Repaint a page area, coordinates are in view coordinates
     */
    void repaintPageArea(XojPageView* view, int64_t x1, int64_t y1, int64_t x2, int64_t y2);

    /**
     * Repaints the page border (at least)
     */
    void repaintPageBorder(XojPageView* view);

private:
    XournalView* xournal;
};
