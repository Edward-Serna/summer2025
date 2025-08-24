//
// Created by Edward on 8/23/2025.
//

#pragma once
#include "window_base.h"

class settings_window : public window_base {
public:
    settings_window();

    float GetVolume() const { return _volume; }
    bool IsFullscreen() const { return _fullscreen; }
    const char* GetSelectedTheme() const { return _themes[_selected_theme]; }

    ~settings_window() override = default;

protected:
    void draw_window() override;

private:
    float _volume = 0.5f;
    bool _fullscreen = false;
    int _selected_theme = 0;
    const char* _themes[3] = { "Dark", "Light", "Classic" };

    bool _show_advanced = false;
};
