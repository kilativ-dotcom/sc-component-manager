/*
 * This source file is part of an OSTIS project. For the latest info, see http://ostis.net
 * Distributed under the MIT License
 * (See accompanying file COPYING.MIT or copy at http://opensource.org/licenses/MIT)
 */

#pragma once

#include "sc-memory/kpm/sc_agent.hpp"
#include "sc-agents-common/keynodes/coreKeynodes.hpp"

#include "sc_component_manager_agent_search.generated.hpp"

namespace searchModule
{
class ScComponentManagerSearchAgent : public ScAgent
{
public:
  SC_CLASS(Agent, Event(scAgentsCommon::CoreKeynodes::action_initiated, ScEvent::Type::AddOutputEdge))
  SC_GENERATED_BODY()
  using ScAddrUnorderedSet = std::unordered_set<ScAddr, ScAddrHashFunc<sc_uint32>>;

private:
  static bool CheckAction(ScMemoryContext & m_memoryCtx, ScAddr const & actionAddr, ScAddr const & actionAddrClass);
};
}  // namespace searchModule
