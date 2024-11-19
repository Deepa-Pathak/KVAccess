// KVAccess.cpp : Defines the entry point for the application.
//

#include "KVAccess.h"
#include "ISecretClientFactory.h"
#include "AzureKeyVaultManager.h"
#include "AzureSecretClientFactory.h"

using namespace std;

AzureSecretKeyVaultConfig getDefaultConstructed() {
  return { "https://kv-rg-nov18-us-kv.vault.azure.net/" , std::make_shared <Azure::Identity::DefaultAzureCredential>(Azure::Core::Credentials::TokenCredentialOptions{}) };
}

int main()
{
	cout << "Hello CMake." << endl;
  try {
    std::string secretName("secret3");
    std::string secretValue("my secret value2");
    ISecretClientFactory::SecretClientFactoryPtr secretClientFactoryPtr = std::make_shared<AzureSecretClientFactory>(getDefaultConstructed());
    ISecretManager::ManagerPtr managerPtr = std::make_shared<AzureKeyVaultManager>(secretClientFactoryPtr->getSecretClient());
    managerPtr->setSecret(secretName, secretValue);

    // get secret
    Secret secret = managerPtr->getSecret(secretName);

    std::cout << "Secret is returned with name " << secret.name_ << " and value "
      << secret.value_ << std::endl;

    //deleting secret
    managerPtr->removeSecret(secretName);
    std::cout << "done, deleted the secret" << endl;
  }
  catch (const std::exception& ex) {
    std::cerr << "Exception: " << ex.what() << std::endl;
  }
	return 0;
}
