#include "SidebarLayout.h"

#include <list>

#include "SidebarPreviewBase.h"
#include "SidebarPreviewBaseEntry.h"

SidebarLayout::SidebarLayout() = default;

SidebarLayout::~SidebarLayout() = default;

class SidebarRow {
public:
    explicit SidebarRow(int64_t width) {
        this->width = width;
        this->currentWidth = 0;
    }

    ~SidebarRow() { clear(); }


    auto isSpaceFor(SidebarPreviewBaseEntry* p) -> bool {
        if (this->list.empty()) {
            return true;
        }

        if (this->currentWidth + p->getWidth() < width) {
            return true;
        }
        return false;
    }

    void add(SidebarPreviewBaseEntry* p) {
        this->list.push_back(p);
        this->currentWidth += p->getWidth();
    }

    void clear() {
        this->list.clear();
        this->currentWidth = 0;
    }

    auto getCount() -> int64_t { return this->list.size(); }

    auto getWidth() const -> int64_t { return this->currentWidth; }

    auto placeAt(int64_t y, GtkLayout* layout) -> int64_t {
        int64_t height = 0;
        int64_t x = 0;

        for (SidebarPreviewBaseEntry* p: this->list) {
            height = std::max(height, p->getHeight());
        }


        for (SidebarPreviewBaseEntry* p: this->list) {
            int64_t currentY = (height - p->getHeight()) / 2;

            gtk_layout_move(layout, p->getWidget(), x, y + currentY);

            x += p->getWidth();
        }


        return height;
    }

private:
    int64_t width;
    int64_t currentWidth;

    std::list<SidebarPreviewBaseEntry*> list;
};

void SidebarLayout::layout(SidebarPreviewBase* sidebar) {
    int64_t y = 0;
    int64_t width = 0;

    GtkAllocation alloc;

    gtk_widget_get_allocation(sidebar->scrollPreview, &alloc);

    SidebarRow row(alloc.width);

    for (SidebarPreviewBaseEntry* p: sidebar->previews) {
        if (row.isSpaceFor(p)) {
            row.add(p);
        } else {
            y += row.placeAt(y, GTK_LAYOUT(sidebar->iconViewPreview));

            width = std::max(width, row.getWidth());

            row.clear();
            row.add(p);
        }
    }

    if (row.getCount() != 0) {
        y += row.placeAt(y, GTK_LAYOUT(sidebar->iconViewPreview));

        width = std::max(width, row.getWidth());

        row.clear();
    }

    gtk_layout_set_size(GTK_LAYOUT(sidebar->iconViewPreview), width, y);
}
