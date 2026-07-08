# Repository Guidelines


## Project Structure & Module Organization

本仓库是 O3DE Atom Sample Viewer 项目。核心 C++ Gem 位于 `Gem/Code`：示例组件在 `Gem/Code/Source`，工具模块在 `Gem/Code/Tools`，单元测试在 `Gem/Code/Tests`。独立运行入口位于 `Standalone`，按平台拆分到 `Standalone/Platform/<Platform>`。渲染与素材资源分布在 `Materials`、`Objects`、`Passes`、`ShaderLib`、`Shaders`、`Textures`。项目级配置在 `project.json`、`Registry`、`Config` 和 `Platform`。新增源码时同步更新对应的 `*_files.cmake` 文件；新增资产后视需要更新 `atomsampleviewer_asset_files.cmake`。

## 背景资料
所有o3de相关的问题，优先查询本地知识库索引文件：C:\O3DE\AIContext\ai-context.md

## 目标
通过示例，理解atom工作原理

## Build, Test, and Development Commands

常用命令示例：

```powershell
cmake -S . -B build -G "Visual Studio 17 2022"
cmake --build build --config profile --target AtomSampleViewerStandalone
ctest --test-dir build -C profile --output-on-failure
```

`cmake -S` 配置项目并通过 `cmake/EngineFinder.cmake` 查找 O3DE；如使用本地引擎覆盖路径，优先检查 `project.json` 或 `user/project.json` 中的 `engine_finder_cmake_path`。`cmake --build` 编译目标；`ctest` 运行已注册测试。Python GPU 自动化测试定义在 `Standalone/PythonTests`，需要主机工具、测试支持和相关运行时依赖。

## Coding Style & Naming Conventions

C++ 使用仓库根目录 `.clang-format`：4 空格缩进、禁用 tab、`ColumnLimit: 140`、C++17、左对齐指针、保留 include 分组并排序 include。类和组件沿用 O3DE 风格，例如 `BloomExampleComponent`、`AtomSampleViewerSystemComponent`；平台专用文件使用后缀或目录区分，例如 `AtomSampleViewerOptions_Windows.cpp`、`Platform/Linux`。代码注释保持简体中文，API、类型、变量和文件名保持英文。

## Testing Guidelines

新增 C++ 测试放在 `Gem/Code/Tests`，并加入 `Gem/Code/atomsampleviewergem_tests_files.cmake` 或相关 CMake 列表。自动化 Python 测试放在 `Standalone/PythonTests/Automated`，文件名采用 `test_<area>_suite.py`。涉及渲染、GPU 或性能样例时，说明所需硬件和运行配置；提交前至少运行受影响目标的 build，并在可用环境中运行对应 `ctest`。

## Commit & Pull Request Guidelines

近期提交多使用简短祈使句或说明句，例如 `Fix MSVC compile errors after O3DE fast math changes`，也可引用 PR 号如 `Add RT vertex animation benchmark sample (#716)`。提交应聚焦单一问题，避免混入格式化或无关重构。PR 需说明改动目的、受影响样例或平台、验证命令与结果；渲染输出变化请附截图或图像对比，关联 issue 时在描述中注明。

## Asset & Configuration Notes

仓库使用 Git LFS 保存大型二进制资产，克隆后确认 LFS 文件已拉取完整。不要提交本地生成目录和用户状态，例如 `build`、`user` 或临时日志。修改 `Registry`、`Config`、shader、pass 或 material pipeline 时，写明兼容性影响并尽量限制到相关样例。
