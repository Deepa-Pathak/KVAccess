#pragma once
#include "ISecretClient.h"
#include <string>

class ISecretClientFactory {
public:
  using SecretClientFactoryPtr = std::shared_ptr<ISecretClientFactory>;
  std::shared_ptr<ISecretClient> virtual getSecretClient(const std::string& clientId = "default") = 0;
  virtual ~ISecretClientFactory() = default;
};
