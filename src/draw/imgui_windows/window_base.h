//
// Created by Edward on 8/22/2025.
//

#pragma once

#include <string>
#include "imgui.h"

class window_base {
public:
    explicit window_base(const std::string& title, bool visible = true, ImGuiWindowFlags flags = 0);
    virtual ~window_base() = default; // Possible to override but not necessary

    void Render(); // Main interface

    void Show() { _visible = true; }
    void Hide() { _visible = false; }
    void Toggle() { _visible = !_visible; }
    bool IsVisible() const { return _visible; } // returns current status

    const std::string& GetTitle()  { return _title; }
    ImGuiWindowFlags GetFlags()  { return _flags; }
    ImVec2 GetPosition() const { return _position; }
    ImVec2 GetSize() const { return _size; }

    void SetFlags(ImGuiWindowFlags flags) { _flags = flags; }
    void SetTitle(const std::string& title) { _title = title; }
    void SetPosition(const ImVec2& position) { _position = position; }
    void SetSize(const ImVec2& size) { _size = size; }

protected:
    virtual void draw_window() = 0; // NEEDS to be overwritten in child class

private:
    std::string _title;
    bool _visible = true;
    ImGuiWindowFlags _flags;

    ImVec2 _position;
    ImVec2 _size = { 200, 200 };
};
