//
// Created by Edward on 8/22/2025.
//

#include "window_base.h"

window_base::window_base(const std::string& title, const bool visible, const ImGuiWindowFlags flags)
    : _title(title), _visible(visible), _flags(flags) {}

void window_base::Render() {
    if (!_visible) return;

    if (ImGui::Begin(_title.c_str(), &_visible, _flags)) {
        draw_window();
    }
    ImGui::End();
}