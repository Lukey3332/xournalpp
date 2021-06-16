/*
 * Xournal++
 *
 * Settings Dialog
 *
 * @author Xournal++ Team
 * https://github.com/xournalpp/xournalpp
 *
 * @license GNU GPLv2 or later
 */

#pragma once

#include <gtk/gtk.h>

class Shadow {
private:
    Shadow();
    virtual ~Shadow();

    static void drawShadowEdge(cairo_t* cr, int64_t x, int64_t y, int64_t width, int64_t height, const unsigned char* edge, double r,
                               double g, double b);
    void drawShadowImpl(cairo_t* cr, int64_t x, int64_t y, int64_t width, int64_t height);

    static void paintEdge(cairo_t* cr, cairo_surface_t* image, int64_t x, int64_t y, int64_t width, int64_t height);

    void drawShadowTop(cairo_t* cr, int64_t x, int64_t y, int64_t width, double r, double g, double b);
    void drawShadowLeft(cairo_t* cr, int64_t x, int64_t y, int64_t height, double r, double g, double b);
    void drawShadowRight(cairo_t* cr, int64_t x, int64_t y, int64_t height, double r, double g, double b);
    void drawShadowBottom(cairo_t* cr, int64_t x, int64_t y, int64_t width, double r, double g, double b);

public:
    /**
     * This is the public interface of this class
     */
    static void drawShadow(cairo_t* cr, int64_t x, int64_t y, int64_t width, int64_t height);
    static int64_t getShadowBottomRightSize();
    static int64_t getShadowTopLeftSize();

private:
    static Shadow* instance;

    cairo_surface_t* edgeTopLeft = nullptr;
    cairo_surface_t* edgeTopRight = nullptr;
    cairo_surface_t* edgeBottomLeft = nullptr;
    cairo_surface_t* edgeBottomRight = nullptr;

    cairo_surface_t* top = nullptr;
    cairo_surface_t* right = nullptr;
    cairo_surface_t* bottom = nullptr;
    cairo_surface_t* left = nullptr;
};
