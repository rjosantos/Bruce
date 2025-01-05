#ifndef __POWER_OFF_MENU_H__
#define __POWER_OFF_MENU_H__

#include <MenuItemInterface.h>


class PowerOffMenu : public MenuItemInterface {
public:
    PowerOffMenu() : MenuItemInterface("Power OFF") {}

    void optionsMenu(void);
    void drawIcon(float scale);
};

#endif
