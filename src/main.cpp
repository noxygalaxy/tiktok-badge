#include <Geode/Geode.hpp>
#include <Geode/modify/ProfilePage.hpp>

using namespace geode::prelude;

class TikTokUserManager {
public:
    static std::vector<std::string> getTikTokUsers() {
        return { "PixelLolka", "DozyGMD", "renverw", "TEFTELKAGD", "broolboy", "NamedNoxy" };
    }

    static bool isTikTokUser(const std::string& username) {
        auto users = getTikTokUsers();
        return std::find(users.begin(), users.end(), username) != users.end();
    }
};

class $modify(ProfilePage) {
    void loadPageFromUserInfo(GJUserScore* userScore) {
        ProfilePage::loadPageFromUserInfo(userScore);
        std::string currentUsername = userScore->m_userName;
        
        if (TikTokUserManager::isTikTokUser(currentUsername)) {
            auto layer = m_mainLayer;
            CCMenu* username_menu = typeinfo_cast<CCMenu*>(layer->getChildByIDRecursive("username-menu"));
        
            CCSprite* tiktokBadge = CCSprite::create("tiktok_badge.png"_spr);

            tiktokBadge->setPosition({100, 49});
            tiktokBadge->setID("noxy.tiktok_badge-badge");
                    
            username_menu->addChild(tiktokBadge);
        }
    }
};