#pragma once
#include <string>
#include "Secret.h"
#include <memory>


class ISecretManager {
public:
  using ManagerPtr = std::shared_ptr<ISecretManager>;

  virtual void setSecret(const std::string& secretName, const std::string& secretValue) = 0;
  virtual Secret getSecret(const std::string& secretName) = 0;
  virtual void removeSecret(const std::string& secretName) = 0;
  virtual ~ISecretManager() = default;
};