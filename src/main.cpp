#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/EditorUI.hpp>

class $modify(PolzEditorUI, EditorUI) {
	void showPopup(ColorSelectPopup* parent) {
		auto* director = CCDirector::sharedDirector();
		auto* currentScene = director->getRunningScene();

		log::info("{}", director);
	}

	void editObject(CCObject* p0) {
		for (auto obj : CCArrayExt<EffectGameObject*>(m_selectedObjects)) {
			switch (obj->m_objectID)
			{
				case 29: // 0x1d
				case 30: // 0x1e
				case 104: // 0x68 
				case 105: // 0x69
				case 744: // 0x2e8
				case 899: // 0x383
				case 900: // 0x384
				case 915: // Line trigger ??? // 0x393
					auto colorSelectPopup = ColorSelectPopup::create((EffectGameObject*)m_selectedObject, m_selectedObjects, nullptr);
					colorSelectPopup->m_colorPicker->setColorValue((EffectGameObject*)m_selectedObject->m_triggerTargetColor);
					CCDirector::sharedDirector()->getRunningScene()->addChild(colorSelectPopup, 105);
					//showPopup(colorSelectPopup);
					return;
			}
		}
		EditorUI::editObject(p0);
	}
};
