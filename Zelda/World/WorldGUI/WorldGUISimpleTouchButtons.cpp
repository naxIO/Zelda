#include "WorldGUISimpleTouchButtons.hpp"
#include "../../Common/Input/GameInputManager.hpp"

using namespace CEGUI;

CWorldGUISimpleTouchButton::CWorldGUISimpleTouchButton(const std::string &id,
                                                       CEntity *pParentEntity,
                                                       CEGUI::Window *pParentWindow,
                                                       ESimpleTouchButtons eType,
                                                       float fButtonPixelSize)
  : CGUITouchButton(id, pParentEntity, pParentWindow, pParentWindow->createChild("OgreTray/StaticImage", id + "_root")) {

  setType(eType);

  m_pRoot->setSize(USize(UDim(0, fButtonPixelSize), UDim(0, fButtonPixelSize)));

  switch (m_uiType) {
  case STB_INTERACT:
    m_pRoot->setPosition(UVector2(UDim(1, -fButtonPixelSize), UDim(0, 0)));
    break;

  default:
    break;
  }
}

void CWorldGUISimpleTouchButton::handleButtonPress(bool bActive) {
  switch (m_uiType) {
  case STB_INTERACT:
    CGameInputManager::getSingleton().injectCommand(CGameInputCommand(GIC_INTERACT, bActive));
    break;

  default:
    break;
  }
}