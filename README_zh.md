# gn 工具链用例

![](https://github.com/Streamlet/gn_toolchain_sample/actions/workflows/windows.yml/badge.svg) ![](https://github.com/Streamlet/gn_toolchain_sample/actions/workflows/linux.yml/badge.svg) ![](https://github.com/Streamlet/gn_toolchain_sample/actions/workflows/macos.yml/badge.svg)
---
[(Here is the English Version)](README.md)

本项目是 [gn_toolchain](../../../gn_toolchain) 的用例.

## 用法

1. 如果已安装 [srcdep](https://github.com/Streamlet/srcdep)，运行 `srcdep`，否则运行 `fetch_deps`。

2. 运行 `gn gen out` 以及 `ninja -C out`。
