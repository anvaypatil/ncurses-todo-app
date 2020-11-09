//
// Created by newton on 11/1/20.
//

#include "TextContent.h"

TextContent::TextContent(Window *window) : parent(window) {

}

void TextContent::inverseOff() {
    wattroff(parent->getFrameWindow(), A_STANDOUT);
}

void TextContent::inverse() {
    wattron(parent->getFrameWindow(), A_STANDOUT);
}


void TextContent::boldOff() {
    wattroff(parent->getFrameWindow(), A_BOLD);
}

void TextContent::bold() {
    wattron(parent->getFrameWindow(), A_BOLD);
}

void TextContent::color(int pair) {
    wattron(parent->getFrameWindow(), COLOR_PAIR(pair));
}

void TextContent::colorOff(int pair) {
    wattroff(parent->getFrameWindow(), COLOR_PAIR(pair));
}

void TextContent::putPlainText(std::string text) {
    if (hasPosition) {
        mvwprintw(parent->getFrameWindow(), position.y, position.x, text.c_str());
    } else {
        mvwprintw(parent->getFrameWindow(), 0, 0, text.c_str());
    }
    clearFormatting();
}

TextContent *TextContent::withColor(int pair) {
    this->selectedColor = pair;
    color(pair);
    return this;
}

TextContent *TextContent::withInvertedText() {
    inverse();
    return this;
}

TextContent *TextContent::withBoldText() {
    bold();
    return this;
}

TextContent *TextContent::atPosition(Position textPosition) {
    this->position = textPosition;
    this->hasPosition = true;
    return this;
}

void TextContent::clearFormatting() {
    this->inverseOff();
    this->colorOff(selectedColor);
    this->boldOff();
    this->hasPosition = false;
}
