/*
 * This source file is part of an OSTIS project. For the latest info, see http://ostis.net
 * Distributed under the MIT License
 * (See accompanying file COPYING.MIT or copy at http://opensource.org/licenses/MIT)
 */

#pragma once

#include <sc-agents-common/utils/IteratorUtils.hpp>
#include <sc-agents-common/utils/CommonUtils.hpp>

#include "src/manager/commands/sc_component_manager_command.hpp"
#include "src/manager/commands/command_init/repos_downloader/repos_downloader.hpp"
#include "src/manager/commands/command_init/repos_downloader/repos_downloader_handler.hpp"

class ScComponentManagerCommandInit : public ScComponentManagerCommand
{
public:
  explicit ScComponentManagerCommandInit(std::string specificationsPath)
    : m_specificationsPath(std::move(specificationsPath))
  {
  }

  ExecutionResult Execute(ScMemoryContext * context, CommandParameters const & commandParameters) override;

  void ProcessRepositories(
      ScMemoryContext * context,
      std::string & specificationsPath,
      std::pair<std::set<std::string>, std::set<std::string>> & repositoryItems,
      ScAddrVector & processedRepositories);

  static std::set<std::string> GetRepositoryAddresses(
      ScMemoryContext * context,
      ScAddr repository,
      ScAddr attributeRelation);

protected:
  std::string m_specificationsPath;
};
