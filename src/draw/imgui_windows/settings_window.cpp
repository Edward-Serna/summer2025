//
// Created by Edward on 8/23/2025.
//

#include "settings_window.h"

settings_window::settings_window()
    : window_base("Settings", false, ImGuiWindowFlags_AlwaysAutoResize)
{
    SetFlags(ImGuiWindowFlags_NoCollapse);
    ImGui::SetWindowSize(ImVec2(200, 400));
}

void settings_window::draw_window()
{
    ImGui::Text("Application Settings");
    ImGui::Separator();

    // Volume slider
    ImGui::SliderFloat("Volume", &_volume, 0.0f, 1.0f, "%.2f");

    // Fullscreen checkbox
    ImGui::Checkbox("Fullscreen", &_fullscreen);

    // Theme selection
    ImGui::Text("Theme:");
    ImGui::SameLine();
    if (ImGui::BeginCombo("##theme", _themes[_selected_theme])) {
        for (int i = 0; i < 3; i++) {
            bool is_selected = (_selected_theme == i);
            if (ImGui::Selectable(_themes[i], is_selected)) {
                _selected_theme = i;
            }
            if (is_selected) {
                ImGui::SetItemDefaultFocus();
            }
        }
        ImGui::EndCombo();
    }

    ImGui::Separator();

    // Advanced settings toggle
    if (ImGui::Checkbox("Show Advanced", &_show_advanced)) {
        // Could trigger window resize
    }

    if (_show_advanced) {
        ImGui::Indent();
        ImGui::Text("Advanced Options");
        static bool vsync = true;
        static int msaa = 4;
        ImGui::Checkbox("VSync", &vsync);
        ImGui::SliderInt("MSAA", &msaa, 0, 16, "%dx");
        ImGui::Unindent();
    }

    ImGui::Separator();

    // Action buttons
    if (ImGui::Button("Apply")) {
        // Apply settings logic here
    }
    ImGui::SameLine();
    if (ImGui::Button("Cancel")) {
        Hide();
    }
}
