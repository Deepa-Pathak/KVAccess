#include "ISecretClient"

class MockSecretClient : public ISecretClient {
public:
  Azure::Response<KeyVaultSecret> GetSecret(
    std::string const& name,
    GetSecretOptions const& options = GetSecretOptions(),
    Azure::Core::Context const& context = Azure::Core::Context()) const override {

  }
};