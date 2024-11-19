#pragma once
#include "azure/identity/default_azure_credential.hpp"
#include <string>

struct AzureSecretKeyVaultConfig {
	std::string uri;
	std::shared_ptr <Azure::Identity::DefaultAzureCredential> accessCredentials;
};

