#include "engine/Window/SFMLWindow.hpp"


namespace engine {

IWindow* IWindow::create_window(const WindowProperties& props) {
    return new SFMLWindow(props);
}


SFMLWindow::SFMLWindow(const WindowProperties& props) {
    (void)props;
}


SFMLWindow::~SFMLWindow() {

}


void SFMLWindow::on_update() {

}


void SFMLWindow::enable_vsync(bool enabled) {
    (void)enabled;
}

} // namespace engine
