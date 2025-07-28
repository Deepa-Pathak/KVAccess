#include "AzureSecretKeyVaultClient.h"

AzureSecretKeyVaultClient::AzureSecretKeyVaultClient(const AzureSecretKeyVaultConfig& config) :
  secretClient_(std::make_shared<Azure::Security::KeyVault::Secrets::SecretClient>(config.uri,
    config.accessCredentials))
{
}

void AzureSecretKeyVaultClient::setSecret(const std::string& secretName, const std::string& secretValue)
{
  secretClient_->SetSecret(secretName, secretValue);
}

Secret AzureSecretKeyVaultClient::getSecret(const std::string& secretName)
{
  auto secretVal = secretClient_->GetSecret(secretName).Value;
  return { secretVal.Name, secretVal.Value.Value() };
}

void AzureSecretKeyVaultClient::removeSecret(const std::string& secretName)
{
  secretClient_->StartDeleteSecret(secretName);
}
