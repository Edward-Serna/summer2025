//
// Created by Edward on 8/23/2025.
//

#pragma once

#include "window_base.h"
#include "imgui.h"
#include <memory>
#include <vector>
#include <unordered_map>
#include <string>

class window_manager {
public:
    window_manager() {};
    ~window_manager() {};

    template<typename T, typename... Args>
    T* AddWindow(const std::string& name, Args&&... args) {
        auto window = std::make_unique<T>(std::forward<Args>(args)...);
        T* ptr = window.get();
        _windows.emplace_back(std::move(window));
        _window_map[name] = ptr;
        return ptr;
    }

    window_base* GetWindow(const std::string& name) { // Get a window by name
        const auto found_window = _window_map.find(name); // return window_base* from the window map ("Auto" because it is not always window_base)
        return (found_window != _window_map.end()) ? found_window->second : nullptr; // return nullptr if not found
    }

    void RenderAll() const
    {
        for (auto& window : _windows) {
            window->Render();
        }
    }


private:
    std::vector<std::unique_ptr<window_base>> _windows;
    std::unordered_map<std::string, window_base*> _window_map;
};