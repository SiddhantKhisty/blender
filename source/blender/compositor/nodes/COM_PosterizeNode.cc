/*
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 * Copyright 2020, Blender Foundation.
 */

#include "COM_PosterizeNode.h"
#include "COM_PosterizeOperation.h"
#include "COM_ExecutionSystem.h"

namespace blender::compositor {

PosterizeNode::PosterizeNode(bNode *editorNode) : Node(editorNode)
{
  /* pass */
}

void PosterizeNode::convertToOperations(NodeConverter &converter,
                                        const CompositorContext & /*context*/) const
{
  PosterizeOperation *operation = new PosterizeOperation();
  converter.addOperation(operation);

  converter.mapInputSocket(getInputSocket(0), operation->getInputSocket(0));
  converter.mapInputSocket(getInputSocket(1), operation->getInputSocket(1));
  converter.mapOutputSocket(getOutputSocket(0), operation->getOutputSocket(0));
}

}  // namespace blender::compositor
