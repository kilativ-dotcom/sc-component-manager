/*
 * This source file is part of an OSTIS project. For the latest info, see http://ostis.net
 * Distributed under the MIT License
 * (See accompanying file COPYING.MIT or copy at http://opensource.org/licenses/MIT)
 */

#pragma once

#include "sc-memory/sc_addr.hpp"
#include "sc-memory/sc_object.hpp"

namespace common_utils
{
class CommonUtils
{
public:
  static std::map<std::string, ScAddr> managerParametersWithAgentRelations;
  static std::vector<std::vector<ScAddr>> componentsClasses;

  static void InitParametersMap();
  static bool TransformToScStruct(
      ScMemoryContext & context,
      ScAddr const & actionAddr,
      std::map<std::string, std::vector<std::string>> const & commandParameters);
  static ScAddr GetMyselfDecompositionAddr(ScMemoryContext & context);
  static void CreateMyselfDecomposition(ScMemoryContext & context);
  static ScAddrVector GetNodesUnderParameter(
      ScMemoryContext & context,
      ScAddr const & actionAddr,
      ScAddr const & relationAddr);
  static ScAddr GetParameterNodeUnderRelation(
      ScMemoryContext & context,
      ScAddr const & actionAddr,
      ScAddr const & relation);
  static std::map<std::string, ScAddr> GetSetElements(ScMemoryContext & context, ScAddr const & setAddr);
  static std::map<std::string, ScAddr> GetElementsLinksOfSet(ScMemoryContext & context, ScAddr const & setAddr);
  static std::map<std::string, std::vector<std::string>> GetCommandParameters(
      ScMemoryContext & context,
      ScAddr const & actionAddr);
  static ScAddr GetSubsystemDecompositionAddr(ScMemoryContext & context, ScAddr const & component);
  static bool CheckIfInstalled(ScMemoryContext & context, ScAddr const & component);
  static ScAddr GetComponentBySpecification(ScMemoryContext & context, ScAddr const & specification);
};
}  // namespace common_utils
