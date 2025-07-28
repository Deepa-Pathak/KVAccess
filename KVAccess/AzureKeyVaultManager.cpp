#include "AzureKeyVaultManager.h"
#include <iostream>
AzureKeyVaultManager::AzureKeyVaultManager(std::shared_ptr<ISecretClient> client) 
  : secretClient_(client) {
}

Secret AzureKeyVaultManager::getSecret(const std::string& secretName)
{
  return secretClient_->getSecret(secretName);
}

void AzureKeyVaultManager::setSecret(const std::string& secretName, const std::string& secretValue)
{
  try {
    secretClient_->setSecret(secretName, secretValue);
  }
  catch (const Azure::Core::RequestFailedException& e) {
    std::cout << "Status Code: " << static_cast<int>(e.StatusCode)
      << ", Reason Phrase: " << e.ReasonPhrase << std::endl;
    std::cout << e.what() << std::endl;
    throw e;
  }
}

void AzureKeyVaultManager::removeSecret(const std::string& secretName)
{
  secretClient_->removeSecret(secretName);
}
