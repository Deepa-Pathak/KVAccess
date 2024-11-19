#pragma once
#include "azure/keyvault/secrets/secret_client.hpp"
#include "ISecretClient.h"
#include <string>
#include "AzureSecretKeyVaultConfig.h"

class AzureSecretKeyVaultClient : public ISecretClient {
public:
  using AzSecretClientPtr = std::shared_ptr <Azure::Security::KeyVault::Secrets::SecretClient>;
  AzureSecretKeyVaultClient(const AzureSecretKeyVaultConfig& keyVaultConfig);

  void setSecret(const std::string& secretName, const std::string& secretValue) override;
  Secret getSecret(const std::string& secretName) override;
  void removeSecret(const std::string& secretName) override;

private:
  AzSecretClientPtr secretClient_;
};