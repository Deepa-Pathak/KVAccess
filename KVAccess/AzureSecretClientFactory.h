#pragma once
#include <string>
#include <mutex>
#include "AzureSecretKeyVaultClient.h"
#include "AzureSecretKeyVaultConfig.h"
#include "ISecretClient.h"
#include "ISecretClientFactory.h"


class AzureSecretClientFactory :public ISecretClientFactory {
public:
  AzureSecretClientFactory(const AzureSecretKeyVaultConfig& config);
  std::shared_ptr<ISecretClient> getSecretClient(const std::string& clientId = "default") override;
private:
  AzureSecretKeyVaultConfig config_;
  static std::mutex secretsClientMutex_;
};
