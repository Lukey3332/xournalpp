/*
 * Xournal++
 *
 * Position entry for undo / redo handling
 *
 * @author Xournal++ Team
 * https://github.com/xournalpp/xournalpp
 *
 * @license GNU GPLv2 or later
 */

#pragma once

template <class T>
class PageLayerPosEntry {
public:
    PageLayerPosEntry(Layer* layer, T* element, int64_t pos) {
        this->element = element;
        this->pos = pos;
        this->layer = layer;
    }

    ~PageLayerPosEntry() {}

private:
public:
    Layer* layer;
    T* element;
    int64_t pos;

    static int64_t cmp(PageLayerPosEntry<T>* a, PageLayerPosEntry<T>* b) { return a->pos - b->pos; }
};
