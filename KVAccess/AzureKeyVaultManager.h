#pragma once
#include "ISecretManager.h"
#include "AzureSecretClientFactory.h"
#include "Secret.h"

class AzureKeyVaultManager:public ISecretManager {
private:
  std::shared_ptr<ISecretClient> secretClient_;
public:
  AzureKeyVaultManager(std::shared_ptr<ISecretClient> client);

  Secret getSecret(const std::string& secretName) override;
  void setSecret(const std::string& secretName, const std::string& value) override;
  void removeSecret(const std::string& secretName) override;
};