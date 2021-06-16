/*
 * Xournal++
 *
 * The about dialog
 *
 * @author Xournal++ Team
 * https://github.com/xournalpp/xournalpp
 *
 * @license GNU GPLv2 or later
 */

#pragma once

#include "gui/GladeGui.h"

class FillOpacityDialog: public GladeGui {
public:
    FillOpacityDialog(GladeSearchpath* gladeSearchPath, int64_t alpha);
    virtual ~FillOpacityDialog();

public:
    virtual void show(GtkWindow* parent);

    int64_t getResultAlpha() const;

private:
    void setPreviewImage(int64_t alpha);

private:
    int64_t resultAlpha = -1;
};
