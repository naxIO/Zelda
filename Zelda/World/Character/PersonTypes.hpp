/*****************************************************************************
 * Copyright 2014 Christoph Wick
 *
 * This file is part of Zelda.
 *
 * Zelda is free software: you can redistribute it and/or modify it under the
 * terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option) any later
 * version.
 *
 * Zelda is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * Zelda. If not, see http://www.gnu.org/licenses/.
 *****************************************************************************/

#ifndef _PERSON_TYPES_HPP_
#define _PERSON_TYPES_HPP_

#include "../../Common/Util/EnumIdMap.hpp"
#include <OgreVector3.h>
#include "FriendOrEnemyStates.hpp"
#include "../Hitpoints.hpp"

enum EPersonTypes {
  PERSON_LINK,

  PERSON_LINKS_FATHER,

  PERSON_SOLDIER_BLOCK,
  PERSON_SOLDIER_BLUE,
  PERSON_SOLDIER_GREEN_SWORD
};

struct SPersonData {
  EPersonTypes eType;
  std::string sMeshName;
  std::string sMaterialName;
  Ogre::Vector3 vScale;
  EFriendOrEnemyStates eFriendOrEnemyState;
  Hitpoints hitpoints;
};

class CPersonTypeIdMap : public CEnumIdMap<EPersonTypes> {
public:
  void init();
};

class CPersonDataIdMap : public CEnumIdMap<EPersonTypes, SPersonData> {
public:
  void init();
};

extern CPersonTypeIdMap PERSON_TYPE_ID_MAP;
extern CPersonDataIdMap PERSON_DATA_ID_MAP;

#endif // _PERSON_TYPES_HPP_
