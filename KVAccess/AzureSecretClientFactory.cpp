#include "AzureSecretClientFactory.h"

#include <map>
#include <memory>

std::mutex AzureSecretClientFactory::secretsClientMutex_;

std::shared_ptr<ISecretClient> AzureSecretClientFactory::getSecretClient(const std::string& clientId)
{
  std::lock_guard<std::mutex> lock(secretsClientMutex_);
  static std::map<std::string, std::shared_ptr<ISecretClient>> secretClientMap_;
  if (secretClientMap_.find(clientId) == secretClientMap_.end()) {
    secretClientMap_[clientId] = std::make_shared<AzureSecretKeyVaultClient>(config_);
  }
  return secretClientMap_[clientId];
}

AzureSecretClientFactory::AzureSecretClientFactory(const AzureSecretKeyVaultConfig& config): config_(config)
{
}
