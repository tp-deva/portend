#include "engine/Application/Application.hpp"


namespace engine {

Application::Application() {

}


Application::~Application() {

}


void Application::push_layer(ILayer* layer) {
    (void)layer;
}


void Application::push_overlay(ILayer* overlay) {
    (void)overlay;
}


void Application::on_event(IEvent& event) {
    (void)event;
}


void Application::run() {

}

} // namespace engine
