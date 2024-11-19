# KVAccess
C++ CMake Application using azure sdks to connect to Secret KV and manage secrets

## Description
Used https://learn.microsoft.com/en-in/vcpkg/get_started/get-started-vscode?pivots=shell-powershell to create a CMAKE project and added azure sdk dependency using vcpkg manager.

VCPackage manager may be cloned from here https://github.com/microsoft/vcpkg#get-started, and once the Power Shell variables are exported in the env, we're good to go:

```
$env:VCPKG_ROOT="path_to_vc_package"
$env:PATH="$env:VCPKG_ROOT;$env:PATH"
```
