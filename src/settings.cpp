#include <BetterSMS/module.hxx>
#include "settings.hxx"

GamePlusSetting sGamePlusMode = GamePlusSetting();
WinConditionFlag sWinCondition = WinConditionFlag();
Settings::SettingsGroup gSettingsGroup(1, 0, Settings::Priority::GAME);

bool GamePlusSetting::sIsUnlocked = false;

void initializeSettings(Settings::SettingsGroup &group) {
    group.addSetting(&sGamePlusMode);
    group.addSetting(&sWinCondition);
    auto *setting           = BetterSMS::getBugFixesSetting();
    setting->lock();
}

bool isGamePlusMode() { return sGamePlusMode.getBool(); }
WinConditionFlag::Condition getWinCondition() {
    return static_cast<WinConditionFlag::Condition>(sWinCondition.getInt());
}

const u8 gSaveBnr[] = {
    0x09, 0x00, 0x00, 0x60, 0x00, 0x20, 0x00, 0x00, 0x01, 0x02, 0x00, 0x52, 0x00, 0x00, 0x0c, 0x20,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x02, 0x03, 0x03, 0x03, 0x00, 0x00, 0x00, 0x01, 0x03, 0x03, 0x03, 0x03, 0x03,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
    0x04, 0x05, 0x06, 0x03, 0x03, 0x01, 0x00, 0x00, 0x05, 0x03, 0x03, 0x03, 0x03, 0x03, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x05, 0x00, 0x04,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x03, 0x03, 0x07, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x03, 0x06, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x03, 0x05, 0x04, 0x00, 0x04, 0x07,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x05, 0x07, 0x00, 0x00, 0x00, 0x06, 0x03, 0x03, 0x03, 0x05, 0x04, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x02, 0x04, 0x00, 0x00, 0x00, 0x00, 0x07,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x02, 0x03, 0x03, 0x03, 0x03, 0x03, 0x00, 0x01, 0x03, 0x03, 0x05, 0x00, 0x02, 0x03,
    0x00, 0x07, 0x03, 0x03, 0x02, 0x00, 0x00, 0x00, 0x00, 0x04, 0x02, 0x03, 0x03, 0x03, 0x01, 0x00,
    0x04, 0x03, 0x05, 0x03, 0x00, 0x00, 0x00, 0x00, 0x04, 0x03, 0x03, 0x03, 0x00, 0x06, 0x03, 0x03,
    0x04, 0x03, 0x03, 0x03, 0x00, 0x06, 0x03, 0x03, 0x04, 0x03, 0x03, 0x03, 0x00, 0x06, 0x03, 0x03,
    0x06, 0x03, 0x03, 0x03, 0x03, 0x03, 0x06, 0x00, 0x01, 0x03, 0x05, 0x00, 0x02, 0x03, 0x07, 0x07,
    0x01, 0x03, 0x02, 0x00, 0x07, 0x03, 0x06, 0x04, 0x01, 0x03, 0x02, 0x00, 0x02, 0x03, 0x07, 0x04,
    0x04, 0x07, 0x03, 0x03, 0x03, 0x03, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x00, 0x03,
    0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x00, 0x03, 0x03, 0x03, 0x03, 0x04, 0x00, 0x00, 0x00, 0x03,
    0x03, 0x03, 0x03, 0x03, 0x03, 0x04, 0x00, 0x00, 0x03, 0x07, 0x03, 0x03, 0x03, 0x07, 0x00, 0x00,
    0x03, 0x04, 0x00, 0x03, 0x03, 0x07, 0x00, 0x00, 0x03, 0x04, 0x00, 0x03, 0x03, 0x04, 0x00, 0x00,
    0x00, 0x00, 0x03, 0x03, 0x01, 0x00, 0x03, 0x07, 0x00, 0x00, 0x03, 0x03, 0x03, 0x06, 0x03, 0x02,
    0x00, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03, 0x05, 0x00, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03, 0x05,
    0x00, 0x00, 0x00, 0x00, 0x05, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x03, 0x03, 0x02, 0x00,
    0x04, 0x00, 0x04, 0x05, 0x03, 0x03, 0x02, 0x04, 0x04, 0x00, 0x01, 0x03, 0x03, 0x03, 0x03, 0x07,
    0x05, 0x03, 0x03, 0x03, 0x03, 0x03, 0x06, 0x00, 0x05, 0x03, 0x05, 0x05, 0x03, 0x03, 0x03, 0x01,
    0x02, 0x03, 0x05, 0x04, 0x05, 0x03, 0x03, 0x01, 0x06, 0x03, 0x05, 0x04, 0x07, 0x03, 0x03, 0x01,
    0x03, 0x03, 0x03, 0x03, 0x00, 0x00, 0x06, 0x03, 0x03, 0x03, 0x03, 0x05, 0x00, 0x01, 0x03, 0x03,
    0x03, 0x03, 0x03, 0x06, 0x00, 0x02, 0x03, 0x02, 0x03, 0x03, 0x03, 0x04, 0x00, 0x03, 0x03, 0x04,
    0x03, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x03, 0x03, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x03, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0a,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x09, 0x0a, 0x0b, 0x09, 0x09, 0x00, 0x00, 0x00, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0a, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x06, 0x03, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x02, 0x03, 0x05,
    0x00, 0x00, 0x02, 0x03, 0x00, 0x07, 0x03, 0x03, 0x00, 0x07, 0x03, 0x03, 0x03, 0x02, 0x03, 0x03,
    0x04, 0x03, 0x03, 0x03, 0x00, 0x06, 0x03, 0x03, 0x04, 0x03, 0x03, 0x03, 0x00, 0x06, 0x03, 0x03,
    0x0c, 0x0d, 0x0e, 0x03, 0x07, 0x05, 0x03, 0x03, 0x0f, 0x10, 0x11, 0x03, 0x03, 0x03, 0x03, 0x06,
    0x01, 0x03, 0x03, 0x07, 0x03, 0x03, 0x00, 0x04, 0x01, 0x03, 0x03, 0x03, 0x03, 0x01, 0x00, 0x04,
    0x01, 0x03, 0x03, 0x03, 0x05, 0x04, 0x00, 0x04, 0x01, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x04,
    0x03, 0x03, 0x03, 0x06, 0x07, 0x00, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03, 0x07, 0x00, 0x00, 0x03,
    0x03, 0x03, 0x03, 0x07, 0x00, 0x00, 0x00, 0x03, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03,
    0x03, 0x04, 0x00, 0x03, 0x02, 0x00, 0x00, 0x00, 0x03, 0x05, 0x05, 0x03, 0x01, 0x00, 0x00, 0x00,
    0x03, 0x03, 0x03, 0x02, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x03, 0x03, 0x07, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x00, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
    0x00, 0x00, 0x03, 0x06, 0x02, 0x03, 0x04, 0x03, 0x00, 0x00, 0x03, 0x06, 0x02, 0x00, 0x04, 0x03,
    0x04, 0x00, 0x01, 0x03, 0x02, 0x07, 0x03, 0x07, 0x04, 0x00, 0x03, 0x03, 0x04, 0x00, 0x03, 0x07,
    0x04, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03, 0x07, 0x04, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03, 0x07,
    0x07, 0x03, 0x05, 0x04, 0x05, 0x03, 0x06, 0x00, 0x07, 0x03, 0x03, 0x03, 0x03, 0x05, 0x00, 0x00,
    0x01, 0x03, 0x03, 0x03, 0x03, 0x00, 0x00, 0x00, 0x01, 0x03, 0x03, 0x03, 0x03, 0x05, 0x00, 0x00,
    0x03, 0x03, 0x03, 0x04, 0x05, 0x03, 0x07, 0x00, 0x03, 0x03, 0x03, 0x04, 0x03, 0x03, 0x05, 0x04,
    0x03, 0x03, 0x05, 0x04, 0x03, 0x03, 0x03, 0x01, 0x03, 0x03, 0x02, 0x00, 0x00, 0x03, 0x03, 0x03,
    0x00, 0x03, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x03, 0x03, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 0x0b,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 0x0b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0a,
    0x0b, 0x09, 0x00, 0x09, 0x0b, 0x0a, 0x00, 0x00, 0x0a, 0x00, 0x00, 0x00, 0x09, 0x0b, 0x0a, 0x00,
    0x0a, 0x00, 0x00, 0x00, 0x09, 0x0b, 0x0a, 0x00, 0x0b, 0x08, 0x00, 0x08, 0x0a, 0x0a, 0x00, 0x00,
    0x00, 0x00, 0x02, 0x03, 0x03, 0x03, 0x03, 0x04, 0x00, 0x00, 0x13, 0x14, 0x03, 0x03, 0x03, 0x00,
    0x00, 0x00, 0x18, 0x19, 0x1a, 0x01, 0x00, 0x00, 0x00, 0x1f, 0x1d, 0x19, 0x20, 0x00, 0x00, 0x00,
    0x0f, 0x12, 0x0e, 0x03, 0x03, 0x03, 0x03, 0x00, 0x15, 0x16, 0x07, 0x03, 0x03, 0x03, 0x04, 0x17,
    0x1b, 0x10, 0x1c, 0x07, 0x07, 0x04, 0x1d, 0x19, 0x21, 0x22, 0x0f, 0x00, 0x00, 0x23, 0x24, 0x19,
    0x01, 0x03, 0x03, 0x01, 0x00, 0x00, 0x00, 0x04, 0x01, 0x03, 0x03, 0x01, 0x00, 0x00, 0x00, 0x04,
    0x1e, 0x01, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x25, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x03, 0x03, 0x03, 0x03, 0x03, 0x06, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x06, 0x00, 0x03,
    0x01, 0x07, 0x07, 0x07, 0x07, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x03, 0x03, 0x03, 0x03, 0x03, 0x04, 0x00, 0x00, 0x03, 0x04, 0x07, 0x03, 0x03, 0x04, 0x00, 0x00,
    0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x01, 0x03, 0x06, 0x00, 0x00, 0x07, 0x03, 0x00, 0x02, 0x03, 0x06, 0x00, 0x00, 0x07, 0x03,
    0x00, 0x00, 0x01, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x04, 0x01, 0x03, 0x03, 0x05, 0x03, 0x03, 0x07, 0x04, 0x05, 0x03, 0x03, 0x04, 0x03, 0x03, 0x07,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x01, 0x03, 0x03, 0x03, 0x03, 0x03, 0x05, 0x04, 0x00, 0x03, 0x05, 0x04, 0x03, 0x03, 0x03, 0x04,
    0x00, 0x07, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x03, 0x03, 0x07, 0x00, 0x00, 0x05, 0x03, 0x03, 0x03, 0x03, 0x07, 0x00, 0x00, 0x01, 0x03, 0x03,
    0x06, 0x07, 0x04, 0x00, 0x00, 0x00, 0x04, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x03, 0x05, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x02, 0x00, 0x00, 0x00, 0x00, 0x09, 0x0a,
    0x07, 0x00, 0x00, 0x00, 0x00, 0x09, 0x0b, 0x0b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 0x0b, 0x0b,
    0x00, 0x0a, 0x0a, 0x0a, 0x00, 0x00, 0x00, 0x0a, 0x09, 0x0b, 0x0b, 0x0b, 0x09, 0x0a, 0x09, 0x08,
    0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x09, 0x0b, 0x09, 0x09, 0x0a, 0x0b, 0x0b, 0x0b, 0x09,
    0x0b, 0x0b, 0x0a, 0x0b, 0x0b, 0x0a, 0x00, 0x00, 0x09, 0x0a, 0x0b, 0x0a, 0x09, 0x08, 0x00, 0x00,
    0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x1f, 0x26, 0x27, 0x28, 0x29, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x2f, 0x22, 0x10, 0x2d,
    0x00, 0x00, 0x00, 0x00, 0x0f, 0x0d, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x32, 0x2e, 0x0f, 0x31,
    0x10, 0x10, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x00, 0x10, 0x30, 0x31, 0x2a, 0x22, 0x19, 0x32, 0x00,
    0x30, 0x33, 0x2a, 0x34, 0x28, 0x10, 0x1f, 0x00, 0x35, 0x2d, 0x19, 0x35, 0x34, 0x30, 0x36, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x03, 0x03, 0x01, 0x00, 0x00,
    0x00, 0x06, 0x03, 0x03, 0x03, 0x03, 0x00, 0x00, 0x01, 0x03, 0x03, 0x03, 0x03, 0x03, 0x06, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x04, 0x06, 0x00, 0x00, 0x04,
    0x02, 0x00, 0x00, 0x01, 0x03, 0x04, 0x00, 0x05, 0x03, 0x04, 0x00, 0x01, 0x03, 0x04, 0x00, 0x05,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x03, 0x05, 0x03, 0x06, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0x05, 0x03, 0x04, 0x00, 0x05, 0x03,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x02, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x04, 0x00, 0x00, 0x04, 0x00,
    0x03, 0x03, 0x03, 0x06, 0x00, 0x00, 0x06, 0x02, 0x03, 0x03, 0x03, 0x03, 0x00, 0x04, 0x03, 0x03,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x06, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 0x0b, 0x0b, 0x00, 0x00, 0x00, 0x00, 0x0a, 0x0b, 0x0b, 0x0a,
    0x00, 0x00, 0x00, 0x00, 0x0a, 0x0b, 0x0b, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x09, 0x0b, 0x0b, 0x0a,
    0x08, 0x00, 0x00, 0x00, 0x09, 0x0b, 0x0b, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0a, 0x0b, 0x0b,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x0a, 0x0b, 0x0b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0a, 0x0b, 0x0b,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x0f, 0x37, 0x38, 0x14, 0x00, 0x00, 0x00, 0x17, 0x2e, 0x37, 0x3b, 0x3c,
    0x00, 0x1f, 0x41, 0x2d, 0x40, 0x42, 0x3b, 0x3f, 0x00, 0x00, 0x36, 0x26, 0x2e, 0x17, 0x45, 0x23,
    0x2f, 0x39, 0x3a, 0x2d, 0x27, 0x34, 0x1f, 0x00, 0x3d, 0x3e, 0x3f, 0x19, 0x2a, 0x34, 0x40, 0x2b,
    0x15, 0x14, 0x43, 0x19, 0x2a, 0x34, 0x40, 0x19, 0x46, 0x14, 0x3c, 0x2d, 0x12, 0x34, 0x47, 0x29,
    0x01, 0x03, 0x03, 0x05, 0x07, 0x03, 0x01, 0x04, 0x03, 0x03, 0x03, 0x00, 0x00, 0x04, 0x00, 0x07,
    0x44, 0x03, 0x03, 0x02, 0x01, 0x00, 0x00, 0x07, 0x00, 0x06, 0x03, 0x03, 0x03, 0x01, 0x00, 0x07,
    0x03, 0x03, 0x03, 0x00, 0x07, 0x06, 0x00, 0x03, 0x03, 0x03, 0x05, 0x04, 0x03, 0x03, 0x00, 0x03,
    0x03, 0x03, 0x03, 0x04, 0x03, 0x03, 0x00, 0x03, 0x03, 0x03, 0x03, 0x04, 0x03, 0x03, 0x00, 0x03,
    0x03, 0x03, 0x00, 0x01, 0x03, 0x04, 0x00, 0x05, 0x03, 0x03, 0x05, 0x01, 0x03, 0x04, 0x00, 0x05,
    0x03, 0x03, 0x03, 0x05, 0x03, 0x04, 0x00, 0x03, 0x03, 0x05, 0x03, 0x03, 0x03, 0x04, 0x04, 0x03,
    0x01, 0x00, 0x02, 0x03, 0x01, 0x00, 0x03, 0x03, 0x01, 0x01, 0x05, 0x03, 0x04, 0x00, 0x03, 0x03,
    0x03, 0x05, 0x03, 0x02, 0x00, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03, 0x02, 0x00, 0x00, 0x03, 0x03,
    0x03, 0x00, 0x01, 0x03, 0x03, 0x00, 0x03, 0x03, 0x03, 0x00, 0x01, 0x03, 0x03, 0x00, 0x03, 0x03,
    0x03, 0x00, 0x01, 0x03, 0x03, 0x00, 0x05, 0x03, 0x03, 0x00, 0x01, 0x03, 0x03, 0x00, 0x02, 0x03,
    0x06, 0x03, 0x03, 0x03, 0x03, 0x04, 0x03, 0x03, 0x07, 0x00, 0x03, 0x03, 0x03, 0x04, 0x03, 0x03,
    0x07, 0x00, 0x02, 0x03, 0x03, 0x04, 0x03, 0x03, 0x07, 0x00, 0x03, 0x03, 0x00, 0x04, 0x03, 0x03,
    0x03, 0x00, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00, 0x03, 0x02, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00,
    0x03, 0x03, 0x05, 0x03, 0x00, 0x00, 0x00, 0x00, 0x02, 0x03, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x0b, 0x0b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 0x0b, 0x0b,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x0b, 0x0b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x08,
    0x0a, 0x00, 0x00, 0x00, 0x0a, 0x0b, 0x0b, 0x08, 0x0b, 0x0b, 0x0a, 0x0b, 0x0b, 0x0b, 0x0b, 0x09,
    0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0a, 0x00, 0x08, 0x0b, 0x0b, 0x0b, 0x08, 0x08, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x16, 0x48, 0x49, 0x2a, 0x00, 0x00, 0x00, 0x00, 0x09, 0x4a, 0x4b, 0x34,
    0x00, 0x00, 0x00, 0x00, 0x36, 0x4d, 0x4e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x50, 0x40, 0x10, 0x28,
    0x31, 0x31, 0x27, 0x35, 0x47, 0x34, 0x36, 0x00, 0x31, 0x12, 0x2a, 0x34, 0x49, 0x4c, 0x08, 0x00,
    0x13, 0x25, 0x13, 0x25, 0x30, 0x4f, 0x08, 0x00, 0x51, 0x20, 0x31, 0x47, 0x30, 0x22, 0x09, 0x00,
    0x00, 0x00, 0x00, 0x03, 0x03, 0x05, 0x00, 0x07, 0x01, 0x03, 0x04, 0x04, 0x03, 0x03, 0x00, 0x04,
    0x03, 0x03, 0x03, 0x04, 0x03, 0x03, 0x07, 0x04, 0x06, 0x03, 0x03, 0x05, 0x05, 0x05, 0x00, 0x00,
    0x03, 0x03, 0x03, 0x04, 0x03, 0x03, 0x00, 0x03, 0x03, 0x03, 0x05, 0x04, 0x03, 0x03, 0x00, 0x03,
    0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x00, 0x03, 0x07, 0x03, 0x05, 0x05, 0x03, 0x06, 0x00, 0x05,
    0x03, 0x04, 0x03, 0x03, 0x03, 0x04, 0x00, 0x03, 0x03, 0x04, 0x03, 0x03, 0x03, 0x04, 0x00, 0x05,
    0x03, 0x04, 0x07, 0x03, 0x03, 0x04, 0x00, 0x03, 0x05, 0x04, 0x00, 0x03, 0x02, 0x00, 0x04, 0x03,
    0x01, 0x07, 0x05, 0x03, 0x06, 0x00, 0x03, 0x03, 0x01, 0x00, 0x07, 0x03, 0x03, 0x00, 0x03, 0x03,
    0x01, 0x04, 0x02, 0x03, 0x03, 0x00, 0x05, 0x03, 0x03, 0x05, 0x03, 0x03, 0x07, 0x00, 0x04, 0x03,
    0x03, 0x00, 0x01, 0x03, 0x03, 0x00, 0x02, 0x03, 0x03, 0x01, 0x05, 0x03, 0x03, 0x00, 0x06, 0x03,
    0x03, 0x03, 0x03, 0x03, 0x02, 0x00, 0x06, 0x03, 0x03, 0x03, 0x03, 0x03, 0x04, 0x00, 0x06, 0x03,
    0x03, 0x05, 0x03, 0x01, 0x00, 0x04, 0x03, 0x03, 0x03, 0x03, 0x06, 0x00, 0x00, 0x04, 0x03, 0x03,
    0x03, 0x03, 0x03, 0x01, 0x00, 0x04, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x02, 0x04, 0x05, 0x05,
    0x00, 0x03, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x06, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x03, 0x06, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x09, 0x09, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x31, 0x0f, 0x00, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x40, 0x28, 0x28, 0x36, 0x36, 0x21, 0x50, 0x00, 0x26, 0x27, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x0a, 0x4f, 0x36, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x04, 0x02, 0x02, 0x02, 0x05, 0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0x07, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x06, 0x02, 0x02, 0x02, 0x04, 0x00, 0x02, 0x00, 0x00, 0x07, 0x07, 0x04, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x05, 0x04, 0x00, 0x06, 0x01, 0x00, 0x04, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x03, 0x03, 0x03, 0x06, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x05, 0x03, 0x03, 0x07, 0x00, 0x00, 0x01, 0x03, 0x01, 0x07, 0x04, 0x00, 0x00, 0x00, 0x04, 0x07,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x07, 0x04, 0x03, 0x03, 0x05, 0x04, 0x05, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x06, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x80, 0x00, 0xa4, 0x00, 0xd4, 0x00, 0xf8, 0x00, 0x94, 0x00, 0xe8, 0x00, 0xc4, 0x00, 0xb4, 0x00,
    0x88, 0x42, 0x90, 0x84, 0x98, 0xc6, 0xa1, 0x08, 0xb5, 0x43, 0xea, 0xca, 0xf4, 0x81, 0xda, 0x06,
    0xff, 0xb1, 0xf0, 0xc3, 0xfb, 0x4b, 0xb9, 0x00, 0xd2, 0x4a, 0xa5, 0x47, 0xd6, 0x2c, 0xd5, 0xe5,
    0xde, 0xcb, 0xff, 0xfd, 0xb4, 0xa0, 0xb9, 0x88, 0x9c, 0xc3, 0xe2, 0x68, 0xcd, 0xe6, 0x94, 0x82,
    0xc9, 0xa4, 0xe2, 0x88, 0xff, 0xf5, 0xa8, 0xe2, 0xf7, 0x99, 0xcd, 0x82, 0xc9, 0x62, 0xfb, 0x6e,
    0xf7, 0x2d, 0xb4, 0xe0, 0xff, 0x8d, 0xb9, 0x45, 0xde, 0xcd, 0xff, 0xf9, 0xf7, 0x71, 0xde, 0xae,
    0xf6, 0xc7, 0xf6, 0xe9, 0xad, 0x25, 0xff, 0xcf, 0xf2, 0x85, 0xff, 0xf1, 0x94, 0x60, 0xf3, 0x11,
    0xee, 0x65, 0xdb, 0x19, 0xb6, 0x13, 0xf2, 0xa8, 0x8c, 0x85, 0xad, 0xab, 0xca, 0x49, 0x88, 0x45,
    0xfb, 0x95, 0xe7, 0x12, 0xda, 0x28, 0x94, 0xa9, 0xf9, 0xe6, 0xf3, 0x0a, 0xb9, 0xa6, 0xff, 0x06,
    0xd6, 0x4d, 0xd9, 0xe3, 0xde, 0xd0, 0xac, 0x61, 0xde, 0x03, 0xee, 0xf0, 0xb1, 0xcf, 0xea, 0xec,
    0xc1, 0xe9, 0xca, 0x0a};

const u8 gSaveIcon[] = {
    0x09, 0x00, 0x00, 0x20, 0x00, 0x40, 0x00, 0x00, 0x01, 0x02, 0x00, 0x59, 0x00, 0x00, 0x08, 0x20,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x09, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03,
    0x00, 0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 0x03, 0x06, 0x07, 0x07, 0x00, 0x03, 0x00, 0x03, 0x03,
    0x0a, 0x07, 0x07, 0x03, 0x03, 0x00, 0x03, 0x00, 0x0b, 0x07, 0x02, 0x03, 0x03, 0x03, 0x03, 0x03,
    0x03, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03, 0x00, 0x00, 0x00,
    0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x00, 0x00, 0x03, 0x03, 0x00, 0x03, 0x03, 0x03, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x09, 0x05, 0x04, 0x01, 0x00, 0x00,
    0x09, 0x09, 0x0c, 0x00, 0x00, 0x00, 0x03, 0x03, 0x0e, 0x09, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x08, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x12, 0x08, 0x13, 0x00,
    0x0d, 0x07, 0x0d, 0x03, 0x00, 0x03, 0x03, 0x03, 0x0d, 0x07, 0x0a, 0x00, 0x03, 0x00, 0x03, 0x03,
    0x0a, 0x02, 0x06, 0x00, 0x03, 0x03, 0x03, 0x03, 0x00, 0x03, 0x00, 0x00, 0x03, 0x03, 0x03, 0x01,
    0x03, 0x00, 0x00, 0x03, 0x03, 0x03, 0x03, 0x00, 0x03, 0x03, 0x0f, 0x03, 0x03, 0x03, 0x03, 0x00,
    0x03, 0x11, 0x09, 0x08, 0x03, 0x03, 0x00, 0x00, 0x08, 0x09, 0x09, 0x04, 0x03, 0x03, 0x03, 0x00,
    0x00, 0x00, 0x12, 0x09, 0x09, 0x05, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x09, 0x09, 0x09, 0x0c,
    0x00, 0x00, 0x00, 0x00, 0x01, 0x04, 0x05, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x08, 0x09, 0x09, 0x08, 0x00, 0x00, 0x01, 0x09, 0x09, 0x09, 0x09, 0x04, 0x00,
    0x00, 0x05, 0x09, 0x09, 0x09, 0x08, 0x01, 0x08, 0x04, 0x09, 0x09, 0x09, 0x04, 0x01, 0x05, 0x09,
    0x00, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x05, 0x13, 0x08, 0x05, 0x05, 0x0e, 0x03, 0x01, 0x09,
    0x09, 0x09, 0x09, 0x09, 0x09, 0x05, 0x01, 0x00, 0x09, 0x09, 0x05, 0x05, 0x09, 0x09, 0x09, 0x00,
    0x09, 0x09, 0x04, 0x00, 0x00, 0x03, 0x00, 0x03, 0x09, 0x13, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
    0x03, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x00, 0x00, 0x03, 0x03,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04,
    0x0a, 0x02, 0x07, 0x07, 0x02, 0x0d, 0x06, 0x05, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x21, 0x05,
    0x09, 0x09, 0x09, 0x08, 0x00, 0x08, 0x09, 0x09, 0x09, 0x09, 0x09, 0x00, 0x11, 0x09, 0x09, 0x01,
    0x09, 0x09, 0x04, 0x00, 0x08, 0x09, 0x05, 0x0f, 0x09, 0x09, 0x11, 0x00, 0x05, 0x09, 0x09, 0x13,
    0x11, 0x00, 0x03, 0x03, 0x12, 0x09, 0x09, 0x12, 0x01, 0x14, 0x01, 0x03, 0x15, 0x08, 0x09, 0x08,
    0x09, 0x09, 0x09, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x09, 0x09, 0x09, 0x22, 0x23, 0x24, 0x24, 0x25,
    0x00, 0x00, 0x03, 0x03, 0x00, 0x00, 0x03, 0x03, 0x03, 0x00, 0x15, 0x03, 0x00, 0x16, 0x16, 0x17,
    0x1d, 0x1e, 0x1f, 0x20, 0x07, 0x07, 0x07, 0x07, 0x26, 0x27, 0x27, 0x28, 0x29, 0x07, 0x02, 0x0a,
    0x00, 0x16, 0x0a, 0x0b, 0x0a, 0x16, 0x2a, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04,
    0x09, 0x09, 0x10, 0x00, 0x04, 0x09, 0x09, 0x05, 0x09, 0x09, 0x11, 0x00, 0x11, 0x09, 0x09, 0x09,
    0x09, 0x09, 0x04, 0x00, 0x00, 0x08, 0x09, 0x09, 0x09, 0x09, 0x09, 0x01, 0x00, 0x01, 0x04, 0x31,
    0x09, 0x09, 0x2b, 0x24, 0x2c, 0x2c, 0x2c, 0x24, 0x2b, 0x2e, 0x1b, 0x24, 0x2c, 0x2c, 0x2c, 0x2c,
    0x1b, 0x2f, 0x24, 0x2c, 0x2c, 0x24, 0x24, 0x24, 0x24, 0x2c, 0x2c, 0x2c, 0x24, 0x2f, 0x1b, 0x26,
    0x23, 0x2c, 0x2c, 0x2c, 0x2d, 0x19, 0x03, 0x00, 0x2c, 0x2c, 0x2c, 0x2c, 0x23, 0x1d, 0x19, 0x1d,
    0x2c, 0x2c, 0x2c, 0x2c, 0x2c, 0x23, 0x30, 0x26, 0x1a, 0x32, 0x2c, 0x2c, 0x2c, 0x2c, 0x2c, 0x33,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x08, 0x05, 0x01,
    0x00, 0x00, 0x00, 0x13, 0x09, 0x09, 0x08, 0x00, 0x00, 0x00, 0x01, 0x09, 0x09, 0x04, 0x00, 0x00,
    0x05, 0x09, 0x09, 0x09, 0x01, 0x00, 0x15, 0x30, 0x11, 0x09, 0x09, 0x09, 0x09, 0x05, 0x08, 0x38,
    0x00, 0x12, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x00, 0x00, 0x01, 0x04, 0x05, 0x09, 0x09, 0x1b,
    0x2c, 0x2c, 0x2c, 0x24, 0x34, 0x2e, 0x35, 0x36, 0x24, 0x2c, 0x2c, 0x39, 0x2e, 0x11, 0x03, 0x03,
    0x34, 0x2c, 0x2c, 0x39, 0x19, 0x03, 0x03, 0x03, 0x24, 0x2c, 0x2c, 0x33, 0x3a, 0x0a, 0x03, 0x03,
    0x09, 0x2b, 0x37, 0x2c, 0x2c, 0x2c, 0x2c, 0x23, 0x0c, 0x05, 0x2b, 0x2f, 0x2c, 0x2c, 0x2c, 0x23,
    0x03, 0x03, 0x08, 0x25, 0x2c, 0x2c, 0x2c, 0x30, 0x03, 0x03, 0x3b, 0x2d, 0x2c, 0x2c, 0x23, 0x26,
    0x00, 0x00, 0x00, 0x12, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x03, 0x03, 0x03, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03,
    0x00, 0x00, 0x06, 0x16, 0x00, 0x2a, 0x3c, 0x33, 0x00, 0x03, 0x02, 0x07, 0x03, 0x00, 0x1d, 0x30,
    0x03, 0x0a, 0x07, 0x07, 0x00, 0x03, 0x03, 0x41, 0x03, 0x07, 0x07, 0x0b, 0x00, 0x03, 0x03, 0x31,
    0x2c, 0x2c, 0x2c, 0x23, 0x3d, 0x07, 0x0a, 0x03, 0x2c, 0x2c, 0x2c, 0x2c, 0x3e, 0x3f, 0x07, 0x15,
    0x24, 0x2c, 0x2c, 0x2c, 0x2c, 0x3e, 0x29, 0x42, 0x25, 0x43, 0x23, 0x2c, 0x2c, 0x2c, 0x2c, 0x27,
    0x00, 0x00, 0x19, 0x33, 0x2c, 0x2c, 0x2c, 0x30, 0x00, 0x1d, 0x40, 0x2c, 0x2c, 0x2c, 0x2c, 0x23,
    0x26, 0x30, 0x23, 0x2c, 0x2c, 0x2c, 0x2c, 0x33, 0x23, 0x2c, 0x2c, 0x2c, 0x2c, 0x2c, 0x23, 0x40,
    0x00, 0x00, 0x00, 0x03, 0x03, 0x00, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00,
    0x16, 0x07, 0x07, 0x03, 0x00, 0x03, 0x03, 0x04, 0x0a, 0x07, 0x0a, 0x00, 0x03, 0x03, 0x03, 0x04,
    0x16, 0x0a, 0x00, 0x03, 0x03, 0x03, 0x03, 0x04, 0x03, 0x03, 0x00, 0x03, 0x03, 0x03, 0x03, 0x11,
    0x09, 0x44, 0x30, 0x2c, 0x2c, 0x2c, 0x2c, 0x2c, 0x09, 0x12, 0x40, 0x2c, 0x2c, 0x2c, 0x2c, 0x24,
    0x09, 0x0c, 0x19, 0x30, 0x23, 0x2c, 0x33, 0x45, 0x09, 0x03, 0x03, 0x19, 0x26, 0x40, 0x19, 0x19,
    0x2c, 0x2c, 0x2c, 0x2c, 0x33, 0x40, 0x26, 0x1d, 0x2c, 0x2c, 0x2c, 0x2c, 0x40, 0x1d, 0x1d, 0x15,
    0x2c, 0x2c, 0x2c, 0x33, 0x26, 0x1d, 0x00, 0x00, 0x40, 0x30, 0x40, 0x26, 0x1d, 0x03, 0x03, 0x03,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x0b,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x0d, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0b,
    0x03, 0x00, 0x00, 0x03, 0x03, 0x03, 0x03, 0x00, 0x02, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
    0x07, 0x0b, 0x1d, 0x1d, 0x15, 0x1d, 0x15, 0x15, 0x07, 0x07, 0x1d, 0x1d, 0x15, 0x1d, 0x15, 0x15,
    0x03, 0x05, 0x05, 0x1d, 0x03, 0x15, 0x1d, 0x1d, 0x01, 0x09, 0x09, 0x03, 0x03, 0x03, 0x03, 0x03,
    0x12, 0x09, 0x09, 0x1d, 0x15, 0x1d, 0x15, 0x15, 0x04, 0x09, 0x05, 0x1d, 0x1d, 0x1d, 0x15, 0x15,
    0x1d, 0x19, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x00, 0x00, 0x03, 0x00, 0x03, 0x03, 0x03,
    0x1d, 0x15, 0x1d, 0x1d, 0x15, 0x15, 0x15, 0x15, 0x1d, 0x1d, 0x1d, 0x1d, 0x03, 0x03, 0x03, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03,
    0x00, 0x00, 0x46, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x46, 0x07, 0x02, 0x0b, 0x06, 0x00, 0x03,
    0x07, 0x07, 0x16, 0x15, 0x1d, 0x1d, 0x15, 0x15, 0x0a, 0x07, 0x0d, 0x1d, 0x1d, 0x1d, 0x15, 0x1d,
    0x03, 0x0d, 0x02, 0x15, 0x03, 0x15, 0x1d, 0x1d, 0x03, 0x03, 0x47, 0x1d, 0x0a, 0x0d, 0x16, 0x15,
    0x08, 0x09, 0x08, 0x1d, 0x15, 0x15, 0x1d, 0x1d, 0x08, 0x09, 0x12, 0x15, 0x15, 0x15, 0x15, 0x15,
    0x12, 0x05, 0x01, 0x03, 0x15, 0x03, 0x03, 0x03, 0x1d, 0x15, 0x00, 0x00, 0x03, 0x03, 0x03, 0x06,
    0x15, 0x15, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x46, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x03, 0x16, 0x07, 0x0d, 0x00, 0x00, 0x00, 0x00, 0x0d, 0x07, 0x07, 0x0b, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x0a, 0x07, 0x07, 0x02, 0x16, 0x00, 0x00, 0x00, 0x00, 0x16, 0x07, 0x07, 0x07, 0x16,
    0x00, 0x00, 0x00, 0x00, 0x06, 0x0b, 0x02, 0x16, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x03, 0x03, 0x03, 0x0d, 0x07, 0x07, 0x0d, 0x03, 0x03, 0x06, 0x07, 0x07, 0x07, 0x07, 0x0b, 0x03,
    0x00, 0x02, 0x07, 0x07, 0x07, 0x0d, 0x06, 0x0d, 0x0b, 0x07, 0x07, 0x07, 0x0b, 0x06, 0x02, 0x07,
    0x00, 0x03, 0x03, 0x03, 0x00, 0x03, 0x03, 0x02, 0x17, 0x0d, 0x02, 0x02, 0x0a, 0x00, 0x06, 0x07,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x02, 0x46, 0x00, 0x07, 0x07, 0x02, 0x02, 0x07, 0x07, 0x07, 0x00,
    0x07, 0x07, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x16, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x00, 0x1d, 0x3b, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0b,
    0x12, 0x05, 0x09, 0x09, 0x05, 0x08, 0x01, 0x02, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x0e, 0x02,
    0x07, 0x07, 0x07, 0x0d, 0x00, 0x0d, 0x07, 0x02, 0x07, 0x07, 0x07, 0x03, 0x16, 0x07, 0x07, 0x06,
    0x07, 0x07, 0x0b, 0x00, 0x0d, 0x07, 0x02, 0x46, 0x07, 0x07, 0x16, 0x03, 0x02, 0x07, 0x07, 0x17,
    0x16, 0x00, 0x03, 0x03, 0x0a, 0x07, 0x07, 0x0a, 0x06, 0x0a, 0x06, 0x03, 0x00, 0x0d, 0x07, 0x0d,
    0x07, 0x07, 0x07, 0x16, 0x1d, 0x48, 0x28, 0x3e, 0x07, 0x07, 0x07, 0x0d, 0x19, 0x27, 0x2c, 0x2c,
    0x00, 0x00, 0x03, 0x1d, 0x1d, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x03, 0x1d, 0x0c, 0x11, 0x13,
    0x30, 0x49, 0x08, 0x09, 0x09, 0x09, 0x09, 0x09, 0x2c, 0x2f, 0x09, 0x09, 0x09, 0x09, 0x05, 0x12,
    0x00, 0x0c, 0x12, 0x04, 0x12, 0x0c, 0x47, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0b,
    0x07, 0x07, 0x46, 0x03, 0x0b, 0x07, 0x07, 0x02, 0x07, 0x07, 0x16, 0x03, 0x16, 0x07, 0x07, 0x07,
    0x07, 0x07, 0x0b, 0x03, 0x03, 0x0d, 0x07, 0x07, 0x07, 0x07, 0x07, 0x06, 0x03, 0x06, 0x0b, 0x0b,
    0x07, 0x4a, 0x24, 0x2f, 0x30, 0x24, 0x2c, 0x2c, 0x4a, 0x24, 0x2c, 0x2c, 0x2c, 0x2c, 0x2c, 0x2c,
    0x24, 0x2c, 0x2c, 0x2c, 0x2c, 0x2c, 0x2c, 0x2c, 0x4c, 0x2c, 0x2c, 0x2c, 0x24, 0x4d, 0x4e, 0x40,
    0x2c, 0x2c, 0x4b, 0x24, 0x2d, 0x1d, 0x00, 0x00, 0x2c, 0x2c, 0x2c, 0x2c, 0x2c, 0x30, 0x3b, 0x00,
    0x2c, 0x2c, 0x2c, 0x2c, 0x2c, 0x2c, 0x26, 0x00, 0x4f, 0x50, 0x2c, 0x2c, 0x2c, 0x23, 0x19, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x16, 0x0d, 0x02, 0x06,
    0x00, 0x00, 0x00, 0x16, 0x07, 0x07, 0x0d, 0x00, 0x00, 0x00, 0x06, 0x07, 0x07, 0x0b, 0x00, 0x00,
    0x02, 0x07, 0x07, 0x07, 0x46, 0x03, 0x1d, 0x19, 0x16, 0x07, 0x07, 0x07, 0x07, 0x02, 0x52, 0x2c,
    0x00, 0x0a, 0x07, 0x07, 0x07, 0x07, 0x28, 0x2c, 0x00, 0x00, 0x46, 0x0b, 0x02, 0x07, 0x28, 0x2c,
    0x30, 0x2c, 0x2c, 0x2c, 0x4a, 0x07, 0x16, 0x46, 0x2c, 0x2c, 0x2c, 0x51, 0x02, 0x16, 0x03, 0x00,
    0x2c, 0x2c, 0x2c, 0x54, 0x03, 0x03, 0x03, 0x03, 0x2c, 0x2c, 0x2c, 0x40, 0x0c, 0x12, 0x03, 0x03,
    0x07, 0x20, 0x51, 0x2c, 0x2c, 0x23, 0x26, 0x1d, 0x16, 0x02, 0x53, 0x27, 0x2c, 0x2c, 0x2c, 0x33,
    0x03, 0x03, 0x55, 0x51, 0x2c, 0x2c, 0x2c, 0x23, 0x03, 0x03, 0x1d, 0x23, 0x2c, 0x2c, 0x2c, 0x23,
    0x00, 0x00, 0x00, 0x0a, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x01, 0x11, 0x03, 0x06, 0x56, 0x2c, 0x00, 0x00, 0x05, 0x09, 0x03, 0x03, 0x1d, 0x40,
    0x00, 0x12, 0x09, 0x09, 0x03, 0x03, 0x00, 0x16, 0x00, 0x09, 0x09, 0x04, 0x03, 0x00, 0x03, 0x57,
    0x2c, 0x2c, 0x2c, 0x33, 0x09, 0x09, 0x12, 0x03, 0x50, 0x2c, 0x2c, 0x2c, 0x1b, 0x09, 0x09, 0x03,
    0x28, 0x2c, 0x2c, 0x2c, 0x24, 0x25, 0x2b, 0x44, 0x24, 0x2c, 0x2c, 0x2c, 0x2c, 0x2c, 0x2c, 0x2c,
    0x03, 0x03, 0x19, 0x23, 0x2c, 0x2c, 0x2c, 0x33, 0x03, 0x1d, 0x33, 0x2c, 0x2c, 0x23, 0x30, 0x19,
    0x26, 0x33, 0x2c, 0x2c, 0x2c, 0x23, 0x1d, 0x03, 0x2c, 0x2c, 0x2c, 0x2c, 0x2c, 0x2c, 0x26, 0x03,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x0c, 0x09, 0x09, 0x03, 0x00, 0x00, 0x03, 0x0b, 0x12, 0x09, 0x12, 0x00, 0x03, 0x03, 0x03, 0x0b,
    0x11, 0x12, 0x00, 0x00, 0x03, 0x03, 0x03, 0x0b, 0x00, 0x00, 0x03, 0x03, 0x00, 0x00, 0x03, 0x16,
    0x51, 0x2c, 0x2c, 0x2c, 0x2c, 0x2c, 0x2c, 0x2c, 0x20, 0x32, 0x2c, 0x2c, 0x23, 0x2c, 0x2c, 0x2c,
    0x07, 0x58, 0x40, 0x26, 0x26, 0x2c, 0x2c, 0x2c, 0x07, 0x03, 0x03, 0x03, 0x3b, 0x30, 0x23, 0x23,
    0x2c, 0x2c, 0x2c, 0x2c, 0x2c, 0x23, 0x19, 0x00, 0x2c, 0x2c, 0x23, 0x2c, 0x2c, 0x19, 0x03, 0x03,
    0x2c, 0x23, 0x1d, 0x26, 0x19, 0x00, 0x00, 0x03, 0x23, 0x26, 0x03, 0x03, 0x00, 0x03, 0x03, 0x00,
    0x00, 0x00, 0x1f, 0x92, 0x6f, 0xd0, 0x08, 0x88, 0x4f, 0x81, 0x6f, 0x80, 0x1f, 0xd2, 0xff, 0x60,
    0x5f, 0x81, 0xfe, 0x00, 0x3f, 0xd1, 0x4f, 0xd0, 0x2f, 0x91, 0x5f, 0xd0, 0x3f, 0x91, 0x1f, 0x91,
    0x1f, 0x80, 0x2f, 0x81, 0x3f, 0x81, 0x2f, 0x92, 0x3f, 0x92, 0x05, 0x55, 0x2f, 0xd1, 0x2f, 0xd2,
    0x2d, 0x71, 0x14, 0x44, 0x59, 0x62, 0x7a, 0x61, 0x6e, 0x70, 0x04, 0x44, 0x27, 0x73, 0x6c, 0xa1,
    0xf7, 0x20, 0x3f, 0xc1, 0x69, 0x52, 0x64, 0x44, 0x75, 0x43, 0x79, 0x62, 0x24, 0x44, 0x75, 0x53,
    0xca, 0x04, 0xe2, 0xa2, 0x1f, 0xa3, 0xf1, 0xe1, 0x74, 0x44, 0x55, 0x43, 0x7d, 0x70, 0x76, 0x53,
    0x44, 0x44, 0x5c, 0x71, 0x66, 0x53, 0x54, 0x44, 0xc5, 0x64, 0x2d, 0x81, 0x1d, 0x71, 0xd1, 0x84,
    0x69, 0x62, 0x76, 0x43, 0x39, 0x82, 0x03, 0x33, 0x28, 0x64, 0xda, 0x83, 0x78, 0x72, 0xef, 0x01,
    0x34, 0x44, 0x47, 0x53, 0x4a, 0x92, 0x65, 0x43, 0x3d, 0x71, 0x55, 0x54, 0x1f, 0xd1, 0x1f, 0xc2,
    0x5b, 0x91, 0x28, 0x62, 0xd6, 0x63, 0x58, 0x53, 0x66, 0x63, 0xbd, 0xc5, 0xd2, 0x44, 0x57, 0x63,
    0x65, 0x53, 0xb9, 0xa6, 0x69, 0x82, 0xea, 0xc2, 0x68, 0x72, 0x5e, 0xc0, 0x45, 0x53, 0x4e, 0xc0,
    0x2c, 0xa2};