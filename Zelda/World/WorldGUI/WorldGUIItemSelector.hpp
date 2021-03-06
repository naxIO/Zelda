#ifndef _WORLD_GUI_ITEM_SELECTOR_
#define _WORLD_GUI_ITEM_SELECTOR_

#include "../../Common/GUI/GUIOverlay.hpp"
#include "../../Common/Message/MessageInjector.hpp"
#include "../Items/ItemTypes.hpp"
#include "../../Common/Input/GameInputListener.hpp"

struct SItemStatus;

class CWorldGUIItemSelectorMultipleSelect;

class CWorldGUIItemSelector : public CGUIOverlay, public CGameInputListener {
private:
  EItemSlotTypes m_eCurrentItemSlot;
  CWorldGUIItemSelectorMultipleSelect *m_pMultipleSelector;
public:
  CWorldGUIItemSelector(CEntity *pParentEntity, CEGUI::Window *pParentWindow);
  ~CWorldGUIItemSelector();

  void start();
  void stop();

private:
  CEGUI::Window *createItem(int x, int y, float fButtonSize);

  CEGUI::String getItemID(int x, int y);
  CEGUI::Window *getWindowFromItem(EItemSlotTypes eItemSlotType);

  bool onSelectedItemChanged(const CEGUI::EventArgs &args);

  bool updateItemStatus(const SItemStatus &itemStatus);

  void handleMessage(const CMessage &message);
  void receiveInputCommand(const CGameInputCommand &cmd);

  void selectFirstAvailable();
  void selectNextLeft();
  void selectNextRight();
  void selectNextUp();
  void selectNextDown();
};

class CWorldGUIItemSelectorMultipleSelect {
private:
  const std::vector<EItemVariantTypes> m_vItems;
  CEGUI::Window *m_pRoot;
  int m_iSelectedItem;
public:
  CWorldGUIItemSelectorMultipleSelect(const std::vector<EItemVariantTypes> items, CEGUI::Window *pParent, const CEGUI::UVector2 &vCenter, float fSize);
  ~CWorldGUIItemSelectorMultipleSelect();

  void selectNextRight();
  void selectNextLeft();

private:
  void createButton(int iIndex);
  bool onSelectedItemChanged(const CEGUI::EventArgs &args);
};

#endif // _WORLD_GUI_ITEM_SELECTOR_HPP_
