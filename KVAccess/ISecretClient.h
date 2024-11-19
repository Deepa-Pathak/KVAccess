#pragma once
#include <string>
#include "Secret.h"

class ISecretClient {
public:
  virtual void setSecret(const std::string& secretName, const std::string& secretValue) = 0;
  virtual Secret getSecret(const std::string& secretName) = 0;
  virtual void removeSecret(const std::string& secretName) = 0;

  virtual ~ISecretClient() = default;
};