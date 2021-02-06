# ProtectSMX
Protect your plugins against decompilation! (Linux only)

ProtectSMX prevent decompilation of **stolen** plugins. This will be usefull to protect your plugins when using remote hosting.

## What is this?
ProtectSMX encrypt any loaded plugin and save encrypted version on disk. Decrypted version passed to Sourcemod core.
If plugin already encrypted, then it will be decrypted on the fly.



This repo contains sources, examples and tests. "decrypted" file contains original plugin, when "charger_clipbrush_fix.smx" was encrypted. When this modification works - all loaded plugins will be encrypted like this. 

## Not so easy! It's a not Extension!

## Step 1: Compile Sourcemod

First of all you should compile Sourcemod by yourself! Just follow the official instruction: https://wiki.alliedmods.net/Building_SourceMod


## Step 2: Inject protectsmx

## Step 2.1: Edit sourcepawn LoadPlugin code

* Add #include <protectsmx.h> to top of file

### Sourcemod 1.8+ (sourcemod/sourcepawn/vm/api.cpp)
 
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


## Step 2.2: Prepare to build

Target folder depend on your SM version `sourcepawn/jit` or `sourcepawn/vm` (Step 2.1)

* Copy protectsmx.h and protectsmx.cpp
* Add protectsmx.c to build script (AMBuilder)

Examples:

https://github.com/alliedmodders/sourcepawn/blob/d584d55f2ad60b58070134fd1645cda27e8cf232/vm/AMBuilder#L34
https://github.com/alliedmodders/sourcemod/blob/sourcemod-1.7.0/sourcepawn/jit/AMBuilder#L32


## Step 3: Change KEY in **protectsmx.c** to you own

## Step 4: Compile sourcemod again!

 * After that you will have sourcepawn.jit.x86.so which will encrypt all .smx files. You can use only it or whole self-compiled SM.
 

# Credits
Blowfish for C++: https://github.com/h2so5/Blowfish
