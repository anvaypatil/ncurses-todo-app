
#ifndef APP_TEXT_CONTENT_H
#define APP_TEXT_CONTENT_H


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


#endif //APP_TEXT_CONTENT_H
