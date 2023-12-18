#include <Geode/Geode.hpp>
#include <Geode/modify/CreatorLayer.hpp>

using namespace geode::prelude;

class $modify(CreatorLayer) {

	// creates a button and adds it to the scene
	CCMenuItemSpriteExtra* makeBaseButton(std::string btnName, float x, float y, float scale, cocos2d::SEL_MenuHandler buttonEffect) {
		auto newSprite = CCSprite::createWithSpriteFrameName(btnName.c_str());
		newSprite->setScale(scale);

		auto createdBtn = CCMenuItemSpriteExtra::create(newSprite, this, buttonEffect);
	    createdBtn->setPosition({x, y});
		return createdBtn;
	}

	// creates a new large button (create, saved, etc)
	CCMenuItemSpriteExtra* makeLargeButton(std::string btnName, float x, float y, cocos2d::SEL_MenuHandler buttonEffect) {
		auto fullName = ("GJ_" + btnName + "Btn_001.png").c_str();
		return makeBaseButton(fullName, x + 12, y - 12, 0.275f, buttonEffect);
	}

	// clones a sprite (used for doors and locks)
	CCMenuItemSpriteExtra* copyMenuItem(CCMenuItemSpriteExtra* btn) {
		return CCMenuItemSpriteExtra::create(
			btn->getNormalImage(), btn->m_pListener, btn->m_pfnSelector
		);
	}

	// clones a sprite and places it in a new position
	CCMenuItemSpriteExtra* cloneBtn(float x, float y, CCMenuItemSpriteExtra* btn, CCPoint offset) {
		CCMenuItemSpriteExtra* clone = copyMenuItem(btn);
		clone->setPosition({x + offset.x, y + offset.y});
		return clone;
	}
	
    bool init() {
		if(!CreatorLayer::init()) return false;

		auto oldMenu = this->getChildByID("creator-buttons-menu");
		auto vaultMenu = this->getChildByID("top-right-menu");
		auto doorMenu = this->getChildByID("bottom-right-menu");

		auto vaultButton = static_cast<CCMenuItemSpriteExtra*>(vaultMenu->getChildByID("vault-button"));
		auto doorButton = static_cast<CCMenuItemSpriteExtra*>(doorMenu->getChildByID("treasure-room-button"));

		// hide the true button menu (can't delete since some other mods rely on it)
		oldMenu->setVisible(false);

		// creates a new ccmenu to put all the buttons in
        auto buttonList = CCMenu::create();
		buttonList->setPosition(0, 0);
		addChild(buttonList);

		// overlay reference image to line up the buttons correctly
			// auto winSize = CCDirector::sharedDirector()->getWinSize();
			// auto refImage = CCSprite::create("reference.png"_spr);
			// refImage->setScale(1.775f);
			// refImage->setPosition({0,0});
			// refImage->setOpacity(100);
			// refImage->setAnchorPoint({0, 0});
			// addChild(refImage, 999);

		// offsets for the lock and door buttons
		CCPoint vaultOffset = {8, -11};
		CCPoint doorOffset = {22, -21};

		/*
		THIS PART IS AUTOMATICALLY GENERATED!!!!
		yes i know it's messy but fuck you it works
		see buttonCoordinates/getButtonPositions.js for info on how this part is made 
		*/
		buttonList->addChild(makeLargeButton("create", 96.908f, 296.889f, menu_selector(CreatorLayer::onMyLevels)));
		buttonList->addChild(makeLargeButton("saved", 131.285f, 296.889f, menu_selector(CreatorLayer::onSavedLevels)));
		buttonList->addChild(makeLargeButton("highscore", 165.662f, 296.889f, menu_selector(CreatorLayer::onLeaderboards)));
		buttonList->addChild(makeLargeButton("challenge", 79.719f, 266.667f, menu_selector(CreatorLayer::onChallenge)));
		buttonList->addChild(makeLargeButton("daily", 114.096f, 266.667f, menu_selector(CreatorLayer::onDailyLevel)));
		buttonList->addChild(makeLargeButton("mapPacks", 148.473f, 266.667f, menu_selector(CreatorLayer::onMapPacks)));
		buttonList->addChild(makeLargeButton("featured", 96.908f, 236.444f, menu_selector(CreatorLayer::onFeaturedLevels)));
		buttonList->addChild(makeLargeButton("fame", 131.285f, 236.444f, menu_selector(CreatorLayer::onFameLevels)));
		buttonList->addChild(makeLargeButton("search", 165.662f, 236.444f, menu_selector(CreatorLayer::onOnlineLevels)));
		buttonList->addChild(makeLargeButton("create", 200.039f, 296.889f, menu_selector(CreatorLayer::onMyLevels)));
		buttonList->addChild(makeLargeButton("saved", 234.416f, 296.889f, menu_selector(CreatorLayer::onSavedLevels)));
		buttonList->addChild(makeLargeButton("highscore", 268.793f, 296.889f, menu_selector(CreatorLayer::onLeaderboards)));
		buttonList->addChild(makeLargeButton("challenge", 182.851f, 266.667f, menu_selector(CreatorLayer::onChallenge)));
		buttonList->addChild(makeLargeButton("daily", 217.228f, 266.667f, menu_selector(CreatorLayer::onDailyLevel)));
		buttonList->addChild(makeLargeButton("mapPacks", 251.605f, 266.667f, menu_selector(CreatorLayer::onMapPacks)));
		buttonList->addChild(makeLargeButton("featured", 200.039f, 236.444f, menu_selector(CreatorLayer::onFeaturedLevels)));
		buttonList->addChild(makeLargeButton("fame", 234.416f, 236.444f, menu_selector(CreatorLayer::onFameLevels)));
		buttonList->addChild(makeLargeButton("search", 268.793f, 236.444f, menu_selector(CreatorLayer::onOnlineLevels)));
		buttonList->addChild(makeLargeButton("create", 303.170f, 296.889f, menu_selector(CreatorLayer::onMyLevels)));
		buttonList->addChild(makeLargeButton("saved", 337.547f, 296.889f, menu_selector(CreatorLayer::onSavedLevels)));
		buttonList->addChild(makeLargeButton("highscore", 371.924f, 296.889f, menu_selector(CreatorLayer::onLeaderboards)));
		buttonList->addChild(makeLargeButton("challenge", 285.982f, 266.667f, menu_selector(CreatorLayer::onChallenge)));
		buttonList->addChild(makeLargeButton("daily", 320.359f, 266.667f, menu_selector(CreatorLayer::onDailyLevel)));
		buttonList->addChild(makeLargeButton("mapPacks", 354.736f, 266.667f, menu_selector(CreatorLayer::onMapPacks)));
		buttonList->addChild(makeLargeButton("gauntlets", 389.113f, 266.667f, menu_selector(CreatorLayer::onGauntlets)));
		buttonList->addChild(makeLargeButton("featured", 303.170f, 236.444f, menu_selector(CreatorLayer::onFeaturedLevels)));
		buttonList->addChild(makeLargeButton("fame", 337.547f, 236.444f, menu_selector(CreatorLayer::onFameLevels)));
		buttonList->addChild(makeLargeButton("search", 371.924f, 236.444f, menu_selector(CreatorLayer::onOnlineLevels)));
		buttonList->addChild(makeLargeButton("challenge", 79.719f, 206.222f, menu_selector(CreatorLayer::onChallenge)));
		buttonList->addChild(makeLargeButton("weekly", 114.096f, 206.222f, menu_selector(CreatorLayer::onWeeklyLevel)));
		buttonList->addChild(makeLargeButton("mapPacks", 148.473f, 206.222f, menu_selector(CreatorLayer::onMapPacks)));
		buttonList->addChild(makeLargeButton("challenge", 182.851f, 206.222f, menu_selector(CreatorLayer::onChallenge)));
		buttonList->addChild(makeLargeButton("weekly", 217.228f, 206.222f, menu_selector(CreatorLayer::onWeeklyLevel)));
		buttonList->addChild(makeLargeButton("mapPacks", 251.605f, 206.222f, menu_selector(CreatorLayer::onMapPacks)));
		buttonList->addChild(makeLargeButton("challenge", 285.982f, 206.222f, menu_selector(CreatorLayer::onChallenge)));
		buttonList->addChild(makeLargeButton("weekly", 320.359f, 206.222f, menu_selector(CreatorLayer::onWeeklyLevel)));
		buttonList->addChild(makeLargeButton("mapPacks", 354.736f, 206.222f, menu_selector(CreatorLayer::onMapPacks)));
		buttonList->addChild(makeLargeButton("gauntlets", 389.113f, 206.222f, menu_selector(CreatorLayer::onGauntlets)));
		buttonList->addChild(makeLargeButton("create", 96.908f, 176.000f, menu_selector(CreatorLayer::onMyLevels)));
		buttonList->addChild(makeLargeButton("saved", 131.285f, 176.000f, menu_selector(CreatorLayer::onSavedLevels)));
		buttonList->addChild(makeLargeButton("highscore", 165.662f, 176.000f, menu_selector(CreatorLayer::onLeaderboards)));
		buttonList->addChild(makeLargeButton("challenge", 79.719f, 145.778f, menu_selector(CreatorLayer::onChallenge)));
		buttonList->addChild(makeLargeButton("daily", 114.096f, 145.778f, menu_selector(CreatorLayer::onDailyLevel)));
		buttonList->addChild(makeLargeButton("mapPacks", 148.473f, 145.778f, menu_selector(CreatorLayer::onMapPacks)));
		buttonList->addChild(makeLargeButton("featured", 96.908f, 115.556f, menu_selector(CreatorLayer::onFeaturedLevels)));
		buttonList->addChild(makeLargeButton("fame", 131.285f, 115.556f, menu_selector(CreatorLayer::onFameLevels)));
		buttonList->addChild(makeLargeButton("search", 165.662f, 115.556f, menu_selector(CreatorLayer::onOnlineLevels)));
		buttonList->addChild(makeLargeButton("create", 200.039f, 176.000f, menu_selector(CreatorLayer::onMyLevels)));
		buttonList->addChild(makeLargeButton("saved", 234.416f, 176.000f, menu_selector(CreatorLayer::onSavedLevels)));
		buttonList->addChild(makeLargeButton("highscore", 268.793f, 176.000f, menu_selector(CreatorLayer::onLeaderboards)));
		buttonList->addChild(makeLargeButton("challenge", 182.851f, 145.778f, menu_selector(CreatorLayer::onChallenge)));
		buttonList->addChild(makeLargeButton("daily", 217.228f, 145.778f, menu_selector(CreatorLayer::onDailyLevel)));
		buttonList->addChild(makeLargeButton("mapPacks", 251.605f, 145.778f, menu_selector(CreatorLayer::onMapPacks)));
		buttonList->addChild(makeLargeButton("featured", 200.039f, 115.556f, menu_selector(CreatorLayer::onFeaturedLevels)));
		buttonList->addChild(makeLargeButton("fame", 234.416f, 115.556f, menu_selector(CreatorLayer::onFameLevels)));
		buttonList->addChild(makeLargeButton("search", 268.793f, 115.556f, menu_selector(CreatorLayer::onOnlineLevels)));
		buttonList->addChild(makeLargeButton("create", 303.170f, 176.000f, menu_selector(CreatorLayer::onMyLevels)));
		buttonList->addChild(makeLargeButton("saved", 337.547f, 176.000f, menu_selector(CreatorLayer::onSavedLevels)));
		buttonList->addChild(makeLargeButton("highscore", 371.924f, 176.000f, menu_selector(CreatorLayer::onLeaderboards)));
		buttonList->addChild(makeLargeButton("challenge", 285.982f, 145.778f, menu_selector(CreatorLayer::onChallenge)));
		buttonList->addChild(makeLargeButton("daily", 320.359f, 145.778f, menu_selector(CreatorLayer::onDailyLevel)));
		buttonList->addChild(makeLargeButton("mapPacks", 354.736f, 145.778f, menu_selector(CreatorLayer::onMapPacks)));
		buttonList->addChild(makeLargeButton("gauntlets", 389.113f, 145.778f, menu_selector(CreatorLayer::onGauntlets)));
		buttonList->addChild(makeLargeButton("featured", 303.170f, 115.556f, menu_selector(CreatorLayer::onFeaturedLevels)));
		buttonList->addChild(makeLargeButton("fame", 337.547f, 115.556f, menu_selector(CreatorLayer::onFameLevels)));
		buttonList->addChild(makeLargeButton("search", 371.924f, 115.556f, menu_selector(CreatorLayer::onOnlineLevels)));
		buttonList->addChild(makeLargeButton("challenge", 79.719f, 85.333f, menu_selector(CreatorLayer::onChallenge)));
		buttonList->addChild(makeLargeButton("weekly", 114.096f, 85.333f, menu_selector(CreatorLayer::onWeeklyLevel)));
		buttonList->addChild(makeLargeButton("mapPacks", 148.473f, 85.333f, menu_selector(CreatorLayer::onMapPacks)));
		buttonList->addChild(makeLargeButton("featured", 96.908f, 55.111f, menu_selector(CreatorLayer::onFeaturedLevels)));
		buttonList->addChild(makeLargeButton("fame", 131.285f, 55.111f, menu_selector(CreatorLayer::onFameLevels)));
		buttonList->addChild(makeLargeButton("search", 165.662f, 55.111f, menu_selector(CreatorLayer::onOnlineLevels)));
		buttonList->addChild(makeLargeButton("challenge", 182.851f, 85.333f, menu_selector(CreatorLayer::onChallenge)));
		buttonList->addChild(makeLargeButton("weekly", 217.228f, 85.333f, menu_selector(CreatorLayer::onWeeklyLevel)));
		buttonList->addChild(makeLargeButton("mapPacks", 251.605f, 85.333f, menu_selector(CreatorLayer::onMapPacks)));
		buttonList->addChild(makeLargeButton("featured", 200.039f, 55.111f, menu_selector(CreatorLayer::onFeaturedLevels)));
		buttonList->addChild(makeLargeButton("fame", 234.416f, 55.111f, menu_selector(CreatorLayer::onFameLevels)));
		buttonList->addChild(makeLargeButton("search", 268.793f, 55.111f, menu_selector(CreatorLayer::onOnlineLevels)));
		buttonList->addChild(makeLargeButton("challenge", 285.982f, 85.333f, menu_selector(CreatorLayer::onChallenge)));
		buttonList->addChild(makeLargeButton("weekly", 320.359f, 85.333f, menu_selector(CreatorLayer::onWeeklyLevel)));
		buttonList->addChild(makeLargeButton("mapPacks", 354.736f, 85.333f, menu_selector(CreatorLayer::onMapPacks)));
		buttonList->addChild(makeLargeButton("gauntlets", 389.113f, 85.333f, menu_selector(CreatorLayer::onGauntlets)));
		buttonList->addChild(makeLargeButton("featured", 303.170f, 55.111f, menu_selector(CreatorLayer::onFeaturedLevels)));
		buttonList->addChild(makeLargeButton("fame", 337.547f, 55.111f, menu_selector(CreatorLayer::onFameLevels)));
		buttonList->addChild(makeLargeButton("search", 371.924f, 55.111f, menu_selector(CreatorLayer::onOnlineLevels)));

		buttonList->addChild(cloneBtn(532.845f, 313.481f, vaultButton, vaultOffset));
		buttonList->addChild(cloneBtn(495.208f, 313.481f, vaultButton, vaultOffset));
		buttonList->addChild(cloneBtn(459.645f, 278.222f, vaultButton, vaultOffset));
		buttonList->addChild(cloneBtn(495.504f, 278.222f, vaultButton, vaultOffset));
		buttonList->addChild(cloneBtn(533.438f, 277.926f, vaultButton, vaultOffset));
		buttonList->addChild(cloneBtn(460.238f, 242.370f, vaultButton, vaultOffset));
		buttonList->addChild(cloneBtn(497.282f, 242.370f, vaultButton, vaultOffset));

		buttonList->addChild(cloneBtn(519.805f, 45.630f, doorButton, doorOffset));
		buttonList->addChild(cloneBtn(476.241f, 36.444f, doorButton, doorOffset));
		buttonList->addChild(cloneBtn(429.714f, 101.926f, doorButton, doorOffset));
		buttonList->addChild(cloneBtn(491.652f, 85.926f, doorButton, doorOffset));
		buttonList->addChild(cloneBtn(539.068f, 95.704f, doorButton, doorOffset));
		buttonList->addChild(cloneBtn(492.541f, 161.481f, doorButton, doorOffset));
		buttonList->addChild(cloneBtn(434.455f, 151.111f, doorButton, doorOffset));
		buttonList->addChild(cloneBtn(470.610f, 80.593f, doorButton, doorOffset));

		// hide the original vault and door buttons
		vaultButton->setVisible(false);
		doorButton->setVisible(false);

		return true;
    }
};

