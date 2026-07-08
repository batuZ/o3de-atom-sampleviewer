# Repository Guidelines


## Project Structure & Module Organization

本仓库是 O3DE Atom Sample Viewer 项目。核心 C++ Gem 位于 `Gem/Code`：示例组件在 `Gem/Code/Source`，工具模块在 `Gem/Code/Tools`，单元测试在 `Gem/Code/Tests`。独立运行入口位于 `Standalone`，按平台拆分到 `Standalone/Platform/<Platform>`。渲染与素材资源分布在 `Materials`、`Objects`、`Passes`、`ShaderLib`、`Shaders`、`Textures`。项目级配置在 `project.json`、`Registry`、`Config` 和 `Platform`。新增源码时同步更新对应的 `*_files.cmake` 文件；新增资产后视需要更新 `atomsampleviewer_asset_files.cmake`。

## 背景资料
所有o3de相关的问题，优先查询本地知识库索引文件：C:\O3DE\AIContext\ai-context.md

## 目标
通过示例理解atom工作原理

## Build, Test, and Development Commands

常用命令示例：

```powershell
cmake -S . -B build -G "Visual Studio 17 2022"
cmake --build build --config profile --target AtomSampleViewerStandalone
ctest --test-dir build -C profile --output-on-failure
```