#include "UI.h"
#include "../../Global.h"

UI::UI() {

}

void UI::render() {
	SDL_RenderCopy(renderer, userInterface, NULL, NULL);
}
void UI::update() {

}