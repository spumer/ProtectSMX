# ProtectSMX
Protect your plugins against decompilation! (Linux only)

ProtectSMX prevent decompilation of **stolen** plugins. This will be usefull to protect your plugins when using remote hosting.

## What is this?
ProtectSMX encrypt any loaded plugin and save encrypted version on disk. Decrypted version passed to Sourcemod core.
If plugin already encrypted, then it will be decrypted on the fly.



This repo contains sources, examples and tests. "decrypted" file contains original plugin, when "charger_clipbrush_fix.smx" was encrypted. When this modification works - all loaded plugins will be encrypted like this. 

## Not so easy! It's a not Extension!

## Step1: Compile Sourcemod

First of all you should compile Sourcemod by yourself! Just follow the official instruction: https://wiki.alliedmods.net/Building_SourceMod

## Step2: Edit sourcepawn LoadPlugin code

* Of course you should add #include <protectsmx.h> to top of file. And add protectsmx.c to build script.

### Sourcemod 1.8 (sourcemod/sourcepawn/vm/api.cpp)
 
  In function **SourcePawnEngine2::LoadBinaryFromFile** replace

    FILE *fp = fopen(file, "rb");

  to

    FILE *fp = protect_read_smx(file, "rb");

  Example: https://github.com/alliedmodders/sourcepawn/blob/d584d55f2ad60b58070134fd1645cda27e8cf232/vm/api.cpp#L240
  
### Sourcemod 1.7 (sourcemod/sourcepawn/jit/engine2.cpp)

 In function **SourcePawnEngine2::LoadPlugin** replace

    FILE *fp = fopen(file, "rb");

  to

    FILE *fp = protect_read_smx(file, "rb");

  Example: https://github.com/alliedmodders/sourcemod/blob/sourcemod-1.7.0/sourcepawn/jit/engine2.cpp#L29

## Step3: Change KEY in **protectsmx.c** to you own


# Credits
Blowfish for C++: https://github.com/h2so5/Blowfish
