#include "RepaintHandler.h"

#include "gui/scroll/ScrollHandling.h"
#include "widgets/XournalWidget.h"

#include "PageView.h"
#include "XournalView.h"

RepaintHandler::RepaintHandler(XournalView* xournal): xournal(xournal) {}

RepaintHandler::~RepaintHandler() { this->xournal = nullptr; }

void RepaintHandler::repaintPage(XojPageView* view) {
    int64_t x1 = view->getX();
    int64_t y1 = view->getY();
    int64_t x2 = x1 + view->getDisplayWidth();
    int64_t y2 = y1 + view->getDisplayHeight();

    gtk_xournal_repaint_area(this->xournal->getWidget(), x1, y1, x2, y2);
}

void RepaintHandler::repaintPageArea(XojPageView* view, int64_t x1, int64_t y1, int64_t x2, int64_t y2) {
    int64_t x = view->getX();
    int64_t y = view->getY();
    gtk_xournal_repaint_area(this->xournal->getWidget(), x + x1, y + y1, x + x2, y + y2);
}

void RepaintHandler::repaintPageBorder(XojPageView* view) { gtk_widget_queue_draw(this->xournal->getWidget()); }
