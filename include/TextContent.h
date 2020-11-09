//
// Created by newton on 11/1/20.
//

#ifndef NCURSES_SAMPLE_TEXTCONTENT_H
#define NCURSES_SAMPLE_TEXTCONTENT_H


#include "Window.h"

class TextContent {
public:
    TextContent(Window *window);
    TextContent *withColor(int pair);
    TextContent *withInvertedText();
    TextContent *withBoldText();
    TextContent *atPosition(Position textPosition);
    void putPlainText(std::string text);
private:
    Window *parent;
    int selectedColor;
    Position position;
    bool hasPosition;
    void inverse();
    void inverseOff();
    void bold();
    void boldOff();
    void color(int pair);
    void colorOff(int pair);
    void clearFormatting();
};


#endif //NCURSES_SAMPLE_TEXTCONTENT_H
