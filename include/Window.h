//
// Created by newton on 10/31/20.
//

#ifndef NCURSES_SAMPLE_WINDOW_H
#define NCURSES_SAMPLE_WINDOW_H


#include <ncurses.h>
#include <string>
#include "Dimension.h"
#include "Position.h"

class Window {
private:
    WINDOW *innerWindow;
    WINDOW *borderWindow;
    uint x;
    uint y;
    uint width;
    uint height;
    std::string windowName;
public:
    Window(Dimension dimension, const std::string windowName);
    ~Window();
    //Copy constructor
    Window(const Window& other);
    //Copy assignment operator
    Window &operator=(const Window &other);
    //Move Constructor
    Window(Window &&other);
    // Move Assignment Operator for std::move cases
    Window &operator=(Window &&other);

    WINDOW *getFrameWindow();

    std::string getWindowName() { return windowName; }
    uint getWidth();
    uint getHeight();
    void setWindowName(std::string name);
    void erase();
    void draw();
    void moveTo(Position position);
    void refreshDisplay() const;
private:
    void copyContent(const Window &other);
    void moveContent(const Window &other);
};


#endif //NCURSES_SAMPLE_WINDOW_H
