#include "PdfElementView.h"

#include <utility>

#include "pdf/base/XojPdfPage.h"

#include "PdfPagesDialog.h"


PdfElementView::PdfElementView(int64_t id, XojPdfPageSPtr page, PdfPagesDialog* dlg):
        BaseElementView(id, dlg), page(std::move(page)) {}

PdfElementView::~PdfElementView() = default;

auto PdfElementView::isUsed() const -> bool { return this->used; }

void PdfElementView::setUsed(bool used) { this->used = used; }

void PdfElementView::setHideUnused() { gtk_widget_set_visible(getWidget(), !isUsed()); }

void PdfElementView::paintContents(cairo_t* cr) {
    double zoom = PdfPagesDialog::getZoom();
    cairo_scale(cr, zoom, zoom);
    page->render(cr);
}

auto PdfElementView::getContentWidth() -> int64_t { return page->getWidth() * PdfPagesDialog::getZoom(); }

auto PdfElementView::getContentHeight() -> int64_t { return page->getHeight() * PdfPagesDialog::getZoom(); }
