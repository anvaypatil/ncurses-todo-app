//
// Created by newton on 10/31/20.
//

#ifndef NCURSES_SAMPLE_DIMENSION_H
#define NCURSES_SAMPLE_DIMENSION_H

class Dimension {
private:
    void copyContent(const Dimension &other) {
        x = other.x;
        y = other.y;
        width = other.width;
        height = other.height;
    }

    void moveContent(const Dimension &other) {
       copyContent(other);
    }
public:
    uint x;
    uint y;
    uint width;
    uint height;
//
//    // Copy constructor
//    Dimension(const Dimension &other) {
//        copyContent(other);
//    }
//
//    // Copy assignment
//    Dimension &operator=(const Dimension &other) {
//        if (this != &other) {
//            copyContent(other);
//        }
//        return *this;
//    }
//
//    // Move assignment
//    Dimension &operator=(Dimension &&other){
//        if (this != &other) {
//            moveContent(other);
//        }
//        return *this;
//    }
//
//    // Move Constructor
//    Dimension(Dimension &&other){
//        moveContent(other);
//    }

};


#endif //NCURSES_SAMPLE_DIMENSION_H
