# CMakeList.txt : CMake project for KVAccess, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (KVAccess "KVAccess.cpp" "KVAccess.h"  "AzureSecretClientFactory.cpp" "AzureKeyVaultManager.h" "AzureKeyVaultManager.cpp" "MockSecretManager.h" "ISecretClient.h" "AzureSecretKeyVaultClient.h" "AzureSecretKeyVaultClient.cpp")


set(CMAKE_PREFIX_PATH 
"C:/Users/Deepa_Kumari/Documents/OSDU/SourceCodes/vcpkg/packages/curl_x64-windows/share/curl"
"C:/Users/Deepa_Kumari/Documents/OSDU/SourceCodes/vcpkg/packages/azure-core-cpp_x64-windows/share/azure-core-cpp"
"C:/Users/Deepa_Kumari/Documents/OSDU/SourceCodes/vcpkg/packages/wil_x64-windows/share/wil"
"C:/Users/Deepa_Kumari/Documents/OSDU/SourceCodes/vcpkg/packages/azure-identity-cpp_x64-windows/share/azure-identity-cpp"
"C:/Users/Deepa_Kumari/Documents/OSDU/SourceCodes/vcpkg/packages/azure-security-keyvault-secrets-cpp_x64-windows/share/azure-security-keyvault-secrets-cpp"
)
set( CURL_LIBRARY "C:/Users/Deepa_Kumari/Documents/OSDU/SourceCodes/vcpkg/installed/x64-windows/lib/libcurl.lib")
set( CURL_INCLUDE_DIR "C:/Users/Deepa_Kumari/Documents/OSDU/SourceCodes/vcpkg/installed/x64-windows/include/curl")

find_package(azure-identity-cpp CONFIG REQUIRED)
find_package(azure-security-keyvault-secrets-cpp CONFIG REQUIRED)
target_link_libraries(KVAccess PRIVATE Azure::azure-security-keyvault-secrets)
target_link_libraries(KVAccess PRIVATE Azure::azure-identity)