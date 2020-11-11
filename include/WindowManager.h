
#ifndef APP_WINDOW_MANAGER_H
#define APP_WINDOW_MANAGER_H

#include "ColorManager.h"
#include "Window.h"
#include <vector>
#include <memory>
#include "AppConfig.h"

class WindowManager {
public:
   static void initializeScreen();
   static void registerWindow(std::shared_ptr<Window> &window);
   static void repaintWindows();
   static void repaintWindow(std::shared_ptr<Window> &window);
   static void terminateScreen();
private:
    inline static std::vector<std::shared_ptr<Window>> windows = {};

};


#endif //APP_WINDOW_MANAGER_H
