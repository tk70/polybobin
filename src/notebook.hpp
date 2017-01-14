#ifndef NOTEBOOK_HPP
#define NOTEBOOK_HPP

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif
#include <wx/notebook.h>
#include "gl/glcanvas.hpp"
#include "gl/displaysettings.hpp"
#include "map/map.hpp"
#include "settings.hpp"
#include "workspace.hpp"

/**
 * \brief Represents a notebook with multiple pages/tabs. In our notebook, pages
 *  are instances of Workspace class.
 */
class Notebook: public wxNotebook
{
    public:
        Notebook(wxWindow *parent);
        void AddWorkspace(Settings settings, wxString mapPath);

        DisplaySettings GetCurrentDisplaySettings();
        void SetCurrentDisplaySetting(int setting, bool display);

        GLCanvas *GetCurrentGLCanvas();
        Map *GetCurrentMap();
        wxPoint GetCurrentMousePositionOnMap();

        void HandleCurrentGLCanvasLeftMouseButtonClick(wxPoint mousePositionOnCanvas, int selectedToolId,
                                                       wxColor selectedColor);
        void HandleCurrentGLCanvasMouseMotion(wxMouseEvent &event, wxColor selectedColor);
        void HandleCurrentGLCanvasRightMouseButtonRelease(int selectedToolId);

        void SaveCurrentMapAsPMS(wxString destinationPath);

        void SelectAll();

        void SetBackgroundColors(wxColor backgroundBottomColor, wxColor backgroundTopColor);
        void SetPolygonsTexture(wxString textureFilename);

    private:
        Workspace *GetCurrentWorkspace();
        void OnPageChanged(wxBookCtrlEvent &event);
};

#endif
