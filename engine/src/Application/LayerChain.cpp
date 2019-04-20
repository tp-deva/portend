#include "engine/Application/LayerChain.hpp"


namespace engine {

LayerChain::LayerChain() {

}


LayerChain::~LayerChain() {

}


void LayerChain::push_layer(ILayer* layer) {
    (void)layer;
}


void LayerChain::push_overlay(ILayer* overlay) {
    (void)overlay;
}


void LayerChain::pop_layer(ILayer* layer) {
    (void)layer;
}


void LayerChain::pop_overlay(ILayer* overlay) {
    (void)overlay;
}


LayerChainIterator LayerChain::get_iterator() {
    return LayerChainIterator(&m_layers, &m_overlays);
}

} // namespace engine
