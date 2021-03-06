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

#include "EmitterCreator.hpp"
#include "EmitterTypes.hpp"
#include "../../../Util/XMLHelper.hpp"
#include <OgreException.h>

#include "EmitOnCollision.hpp"
#include "EmitOnInteraction.hpp"
#include "EmitOnReceivedDamage.hpp"

using namespace XMLHelper;

namespace events {
  CEmitter *createEmitter(const tinyxml2::XMLElement *pElem, const CEvent &owner) {
    EEmitterTypes type(EMITTER_TYPES_MAP.parseString(Attribute(pElem, "type")));

    switch (type) {
    case EMIT_ON_CREATE:
      return new CEmitter(EMIT_ON_CREATE, owner);
    case EMIT_ON_COLLISION:
      return new CEmitOnCollision(pElem, owner);
    case EMIT_ON_INTERACTION:
      return new CEmitOnInteraction(pElem, owner);
    case EMIT_ON_RECEIVED_DAMAGE:
      return new CEmitOnReceivedDamage(pElem, owner);
    }

    throw Ogre::Exception(0, "New emitter type not added in createEmitter", __FILE__);
  }
};
