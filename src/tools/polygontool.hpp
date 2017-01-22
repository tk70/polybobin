#pragma once
#include "tool.hpp"
#include "../miniframes/paletteframe.hpp"

class PolygonTool : public Tool
{
public:
    PolygonTool(GLCanvas& canvas, const PaletteFrame& palette);
    void OnSelect() override;
    void OnUnselect() override;
    void OnCanvasLeftMouseButtonClick(const wxMouseEvent &event) override;
    void OnCanvasMouseMotion(const wxMouseEvent &event) override;
    void OnCanvasRightMouseButtonRelease(const wxMouseEvent &event) override;
    void OnTimerTick() override;
    void OnNewPolygonTypeSelected(wxCommandEvent &event);
    ~PolygonTool() override = default;

private:
    const PaletteFrame& m_palette;
    unsigned m_addedPolygonVerticesCount;
    PMSPolygonType m_newPolygonType;
    int m_polygonId;
};