# Atom Sample Viewer 目录说明

本文用于快速定位 Atom Sample Viewer 项目的主要目录、组件和资源。当前工程中部分 RayTracing / CLAS 相关样例已在 `SampleComponentManager.cpp` 或 CMake 文件中注释禁用，本文会单独标注。

## 顶层目录

| 路径 | 说明 |
| --- | --- |
| `CMakeLists.txt` | 项目入口 CMake，负责查找 O3DE 引擎并初始化工程。 |
| `project.json` | O3DE 项目描述文件。 |
| `Gem` | 项目核心 Gem，包含运行时代码、工具代码、测试和 Gem 配置。 |
| `Standalone` | 独立启动程序代码与 Python 自动化测试。 |
| `Passes` | 示例渲染管线与 Pass 配置，例如 `RHISamplePipeline.pass`、`CheckerboardPipeline.pass`。 |
| `Shaders` / `ShaderLib` | 示例 shader 和共享 shader include。 |
| `Materials` | 示例材质资源，包括 PBR、Decal、SSR、DiffuseGI、XR 等材质。 |
| `Objects` | 示例模型、FBX 和 assetinfo 文件。 |
| `Textures` | 示例纹理资源。 |
| `Registry` / `Config` | 项目注册表和运行配置。 |
| `Platform` | Android、iOS、Linux、Mac、Windows 平台 CMake 配置。 |
| `scripts` | 项目辅助脚本。 |
| `Levels` | 关卡资源目录。 |
| `atomsampleviewer_asset_files.cmake` | 资产文件清单。 |
| `build` / `user` / `Cache` | 本地生成目录，不应作为源码说明重点。 |

## Gem 代码结构

| 路径 | 说明 |
| --- | --- |
| `Gem/gem.json` | Gem 元数据。 |
| `Gem/Code/CMakeLists.txt` | Gem 代码构建入口。 |
| `Gem/Code/atomsampleviewergem_private_files.cmake` | 主要运行时代码文件清单；如果文件未加入这里，通常不会参与编译。 |
| `Gem/Code/atomsampleviewergem_tests_files.cmake` | Gem 测试文件清单。 |
| `Gem/Code/Source` | 主要示例组件、系统组件和公共代码。 |
| `Gem/Code/Source/RHI` | 低层 RHI 示例。 |
| `Gem/Code/Source/Performance` | 性能测试示例。 |
| `Gem/Code/Source/Automation` | 自动化脚本、报告和图像比较支持。 |
| `Gem/Code/Source/Utils` | ImGui 工具、资产浏览器、消息框、进度列表等通用 UI 工具。 |
| `Gem/Code/Tools` | Editor / 工具侧 SystemComponent 和模块。 |
| `Gem/Code/Tests` | C++ 测试入口。 |

## 核心框架组件

#### [AtomSampleViewerSystemComponent](Gem\Code\Source\AtomSampleViewerSystemComponent.h)
项目 SystemComponent，负责 Gem 级别的系统注册和生命周期管理。

#### [AtomSampleComponent](Gem\Code\Source\AtomSampleComponent.h)
示例组件的基础入口之一，用于和 Sample Viewer 管理逻辑协作。

#### [SampleComponentManager](Gem\Code\Source\SampleComponentManager.h)
样例注册、切换、渲染管线创建、ImGui 上下文、RHI/RPI/Features/Performance 分类管理的核心组件。

#### [SampleComponentConfig](Gem\Code\Source\SampleComponentConfig.h)
样例配置数据结构。

#### [CommonSampleComponentBase](Gem\Code\Source\CommonSampleComponentBase.h)
大多数 RPI / Features 示例的公共基类，提供场景、相机、灯光、网格 FeatureProcessor 等通用能力。

#### [ExampleComponentBus](Gem\Code\Source\ExampleComponentBus.h) / [SampleComponentManagerBus](Gem\Code\Source\SampleComponentManagerBus.h)
示例组件与 Sample Manager 之间的 EBus 通信接口。

## RPI 示例组件

#### [AssetLoadTestComponent](Gem\Code\Source\AssetLoadTestComponent.h)
测试资产加载流程，验证模型、材质等资源加载状态。

#### [AuxGeomExampleComponent](Gem\Code\Source\AuxGeomExampleComponent.h)
演示 AuxGeom 调试绘制能力。

#### [BakedShaderVariantExampleComponent](Gem\Code\Source\BakedShaderVariantExampleComponent.h)
测试烘焙 shader variant，允许在根变体与优化变体之间切换，并显示相关指标。

#### [SponzaBenchmarkComponent](Gem\Code\Source\SponzaBenchmarkComponent.h)
加载 Sponza 场景并执行运行时基准测试。

#### [CullingAndLodExampleComponent](Gem\Code\Source\CullingAndLodExampleComponent.h)
剔除与 LOD 示例。

#### [DecalExampleComponent](Gem\Code\Source\DecalExampleComponent.h)
创建简单场景测试 Atom Decal 系统。

#### [DynamicDrawExampleComponent](Gem\Code\Source\DynamicDrawExampleComponent.h)
演示 `DynamicDrawInterface` 和 `DynamicDrawContext` 的基本用法。

#### [DynamicMaterialTestComponent](Gem\Code\Source\DynamicMaterialTestComponent.h)
加载可配置实体网格，为每个实体创建唯一材质实例，并逐帧修改材质属性。

#### [MeshExampleComponent](Gem\Code\Source\MeshExampleComponent.h)
演示加载和显示不同材质的 3D 模型。

#### [MSAA_RPI_ExampleComponent](Gem\Code\Source\MSAA_RPI_ExampleComponent.h)
RPI 层 MSAA 示例，在同一场景中对比启用与禁用 MSAA 的效果。

#### [MultiGPURPIExampleComponent](Gem\Code\Source\MultiGPURPIExampleComponent.h)
RPI 层多 GPU 示例。

#### [MultiRenderPipelineExampleComponent](Gem\Code\Source\MultiRenderPipelineExampleComponent.h)
在不同窗口/管线中渲染同一场景，并支持切换图形功能和第二摄像机。

#### [MultiSceneExampleComponent](Gem\Code\Source\MultiSceneExampleComponent.h)
多场景示例，内部包含第二窗口场景相关逻辑。

#### [MultiViewSingleSceneAuxGeomExampleComponent](Gem\Code\Source\MultiViewSingleSceneAuxGeomExampleComponent.h)
单场景多视图 AuxGeom 示例。

#### [ReadbackExampleComponent](Gem\Code\Source\ReadbackExampleComponent.h)
测试 RPI Pass 的 readback 流程：先生成纹理，再读回 CPU，随后重新上传用于显示。

#### [RenderTargetTextureExampleComponent](Gem\Code\Source\RenderTargetTextureExampleComponent.h)
演示将运行时创建的渲染目标作为网格材质纹理输入。

#### [RootConstantsExampleComponent](Gem\Code\Source\RootConstantsExampleComponent.h)
演示 Root Constants，用小块常量数据直接更新 GPU 命令，避免 Buffer / SRG 绑定开销。

#### [SceneReloadSoakTestComponent](Gem\Code\Source\SceneReloadSoakTestComponent.h)
反复加载和卸载模型/材质，用于暴露渲染器和资源系统的竞态问题。

#### [StreamingImageExampleComponent](Gem\Code\Source\StreamingImageExampleComponent.h)
测试 StreamingImage 的 mip 加载、性能统计和热重载流程。

#### [ShaderReloadTestComponent](Gem\Code\Source\ShaderReloadTestComponent.h)
验证 shader 热重载通知与 FullscreenTrianglePass shader 更新流程。

#### [Subpass_RPI_ExampleComponent](Gem\Code\Source\Subpass_RPI_ExampleComponent.h)
RPI 层 Subpass 示例，对比子通道管线与普通 Pass 管线。

#### [RayTracingVertexFormatExampleComponent](Gem\Code\Source\RayTracingVertexFormatExampleComponent.h)
光线追踪顶点格式测试。当前在 `SampleComponentManager.cpp` 中被注释禁用。

## Features 示例组件

#### [AreaLightExampleComponent](Gem\Code\Source\AreaLightExampleComponent.h)
区域光示例，用于展示和调试 Atom 的 area light 相关功能。

#### [BloomExampleComponent](Gem\Code\Source\BloomExampleComponent.h)
复用色调映射场景演示 Bloom 光晕效果。

#### [CheckerboardExampleComponent](Gem\Code\Source\CheckerboardExampleComponent.h)
使用棋盘渲染管线渲染带 PBR 材质的模型。

#### [DepthOfFieldExampleComponent](Gem\Code\Source\DepthOfFieldExampleComponent.h)
创建简单景深场景，演示 Depth of Field 效果。

#### [DiffuseGIExampleComponent](Gem\Code\Source\DiffuseGIExampleComponent.h)
演示基于 DiffuseProbeGrid 的漫反射全局光照。

#### [ExposureExampleComponent](Gem\Code\Source\ExposureExampleComponent.h)
演示曝光控制功能。

#### [EyeMaterialExampleComponent](Gem\Code\Source\EyeMaterialExampleComponent.h)
演示带次表面散射的眼睛材质。

#### [LightCullingExampleComponent](Gem\Code\Source\LightCullingExampleComponent.h)
测试大量灯光和贴花场景中的灯光剔除。

#### [ParallaxMappingExampleComponent](Gem\Code\Source\ParallaxMappingExampleComponent.h)
演示视差映射和像素深度偏移。

#### [RayTracingIntersectionShaderExampleComponent](Gem\Code\Source\RayTracingIntersectionShaderExampleComponent.h)
测试程序几何体的光线追踪相交着色器。当前在 `SampleComponentManager.cpp` 中被注释禁用。

#### [ShadowExampleComponent](Gem\Code\Source\ShadowExampleComponent.h)
阴影示例，包含级联阴影、PCF、ESM、圆盘光阴影等步骤。

#### [ShadowedSponzaExampleComponent](Gem\Code\Source\ShadowedSponzaExampleComponent.h)
带阴影的 Sponza 场景。

#### [SkinnedMeshExampleComponent](Gem\Code\Source\SkinnedMeshExampleComponent.h)
Atom SkinnedMesh 系统测试场景。

#### [SsaoExampleComponent](Gem\Code\Source\SsaoExampleComponent.h)
屏幕空间环境光遮蔽 SSAO 示例。

#### [SSRExampleComponent](Gem\Code\Source\SSRExampleComponent.h)
屏幕空间反射 SSR 示例。

#### [XRRPIExampleComponent](Gem\Code\Source\XRRPIExampleComponent.h)
RPI 层 OpenXR / VR 示例，使用多视图管线和 Quest 2 控制器交互。

#### [TonemappingExampleComponent](Gem\Code\Source\TonemappingExampleComponent.h)
通过全屏图像演示色调映射，DisplayMapper 输出可用于图像捕获。

#### [TransparencyExampleComponent](Gem\Code\Source\TransparencyExampleComponent.h)
透明物体深度排序测试。

## RHI 示例组件

#### [BasicRHIComponent](Gem\Code\Source\RHI\BasicRHIComponent.h)
RHI 示例的公共基类，封装窗口、Pass、缓冲区和基础几何数据。

#### [AlphaToCoverageExampleComponent](Gem\Code\Source\RHI\AlphaToCoverageExampleComponent.h)
Alpha-to-Coverage RHI 示例。

#### [AsyncComputeExampleComponent](Gem\Code\Source\RHI\AsyncComputeExampleComponent.h)
异步计算队列示例。

#### [BindlessPrototypeExampleComponent](Gem\Code\Source\RHI\BindlessPrototypeExampleComponent.h)
Bindless 资源访问原型示例。

#### [ComputeExampleComponent](Gem\Code\Source\RHI\ComputeExampleComponent.h)
基础 compute shader 示例。

#### [CopyQueueComponent](Gem\Code\Source\RHI\CopyQueueComponent.h)
Copy queue 示例。

#### [DualSourceBlendingComponent](Gem\Code\Source\RHI\DualSourceBlendingComponent.h)
Dual-source blending 示例。

#### [IndirectRenderingExampleComponent](Gem\Code\Source\RHI\IndirectRenderingExampleComponent.h)
间接绘制 / indirect command 示例。

#### [InputAssemblyExampleComponent](Gem\Code\Source\RHI\InputAssemblyExampleComponent.h)
输入装配阶段示例。

#### [MSAAExampleComponent](Gem\Code\Source\RHI\MSAAExampleComponent.h)
RHI 层 MSAA 示例。

#### [MultipleViewsComponent](Gem\Code\Source\RHI\MultipleViewsComponent.h)
多 View 渲染示例。

#### [MRTExampleComponent](Gem\Code\Source\RHI\MRTExampleComponent.h)
Multiple Render Targets 示例。

#### [MultiThreadComponent](Gem\Code\Source\RHI\MultiThreadComponent.h)
多线程 RHI 提交示例。

#### [MultiGPUExampleComponent](Gem\Code\Source\RHI\MultiGPUExampleComponent.h)
多 GPU RHI 示例。

#### [MultiViewportSwapchainComponent](Gem\Code\Source\RHI\MultiViewportSwapchainComponent.h)
多视口 swapchain 示例。

#### [QueryExampleComponent](Gem\Code\Source\RHI\QueryExampleComponent.h)
RHI Query 示例。

#### [SphericalHarmonicsExampleComponent](Gem\Code\Source\RHI\SphericalHarmonicsExampleComponent.h)
球谐相关 RHI 示例。

#### [StencilExampleComponent](Gem\Code\Source\RHI\StencilExampleComponent.h)
模板缓冲示例。

#### [SubpassExampleComponent](Gem\Code\Source\RHI\SubpassExampleComponent.h)
RHI 层 Subpass 示例。

#### [SwapchainExampleComponent](Gem\Code\Source\RHI\SwapchainExampleComponent.h)
Swapchain 示例。

#### [TextureExampleComponent](Gem\Code\Source\RHI\TextureExampleComponent.h)
基础纹理示例。

#### [Texture3dExampleComponent](Gem\Code\Source\RHI\Texture3dExampleComponent.h)
3D 纹理示例。

#### [TextureArrayExampleComponent](Gem\Code\Source\RHI\TextureArrayExampleComponent.h)
纹理数组示例。

#### [TextureMapExampleComponent](Gem\Code\Source\RHI\TextureMapExampleComponent.h)
纹理映射示例，包含多种纹理类型和采样方式。

#### [TriangleExampleComponent](Gem\Code\Source\RHI\TriangleExampleComponent.h)
最基础的三角形渲染示例。

#### [TrianglesConstantBufferExampleComponent](Gem\Code\Source\RHI\TrianglesConstantBufferExampleComponent.h)
使用 constant buffer 绘制多个三角形。

#### [XRExampleComponent](Gem\Code\Source\RHI\XRExampleComponent.h)
RHI 层 OpenXR 示例。

#### [MatrixAlignmentTestExampleComponent](Gem\Code\Source\RHI\MatrixAlignmentTestExampleComponent.h)
矩阵布局与对齐测试。

#### [VariableRateShadingExampleComponent](Gem\Code\Source\RHI\VariableRateShadingExampleComponent.h)
可变速率着色 VRS 示例。

#### [RayTracingExampleComponent](Gem\Code\Source\RHI\RayTracingExampleComponent.h)
RHI 光线追踪基础示例。当前在 `SampleComponentManager.cpp` 和 `atomsampleviewergem_private_files.cmake` 中被注释禁用。

#### [RayTracingClusterExampleComponent](Gem\Code\Source\RHI\RayTracingClusterExampleComponent.h)
RHI Cluster / CLAS 光线追踪示例。当前在 `SampleComponentManager.cpp` 和 `atomsampleviewergem_private_files.cmake` 中被注释禁用。

## Performance 示例

#### [100KDrawable_SingleView_ExampleComponent](Gem\Code\Source\Performance\100KDrawable_SingleView_ExampleComponent.h)
单视图 100K Drawable 性能测试。

#### [100KDraw_10KDrawable_MultiView_ExampleComponent](Gem\Code\Source\Performance\100KDraw_10KDrawable_MultiView_ExampleComponent.h)
多视图 100K Draw / 10K Drawable 性能测试。

#### [HighInstanceExampleComponent](Gem\Code\Source\Performance\HighInstanceExampleComponent.h)
高实例数量渲染性能示例。源码存在，但当前样例菜单中未注册。

#### [RayTracingVertexAnimationExampleComponent](Gem\Code\Source\Performance\RayTracingVertexAnimationExampleComponent.h)
光线追踪顶点动画性能测试。当前在 `SampleComponentManager.cpp` 中被注释禁用。

## 辅助类与工具

#### [ProceduralSkinnedMesh](Gem\Code\Source\ProceduralSkinnedMesh.h)
生成程序化蒙皮网格输入数据，常用于 SkinnedMesh 示例。

#### [ProceduralSkinnedMeshUtils](Gem\Code\Source\ProceduralSkinnedMeshUtils.h)
程序化蒙皮网格相关工具函数。

#### [SkinnedMeshContainer](Gem\Code\Source\SkinnedMeshContainer.h)
管理 SkinnedMesh 示例使用的蒙皮网格实例，负责生命周期释放。

#### [DecalContainer](Gem\Code\Source\DecalContainer.h)
Decal 示例使用的贴花容器。

#### [EntityUtilityFunctions](Gem\Code\Source\EntityUtilityFunctions.h)
创建实体、组件和场景对象的辅助函数。

#### [Utils](Gem\Code\Source\Utils\Utils.h)
通用工具函数，包括 RHI 设备访问、资源辅助等。

#### [ImGuiSidebar](Gem\Code\Source\Utils\ImGuiSidebar.h)
示例侧边栏 UI 封装。

#### [ImGuiAssetBrowser](Gem\Code\Source\Utils\ImGuiAssetBrowser.h)
ImGui 资产浏览器控件。

#### [ImGuiMessageBox](Gem\Code\Source\Utils\ImGuiMessageBox.h)
ImGui 消息框控件。

#### [ImGuiProgressList](Gem\Code\Source\Utils\ImGuiProgressList.h)
ImGui 进度列表控件。

#### [ImGuiHistogramQueue](Gem\Code\Source\Utils\ImGuiHistogramQueue.h)
性能统计直方图队列。

#### [ImGuiSaveFilePath](Gem\Code\Source\Utils\ImGuiSaveFilePath.h)
保存路径选择控件。

## Automation

| 文件 | 说明 |
| --- | --- |
| `ScriptManager.h/.cpp` | 自动化脚本管理器。 |
| `ScriptableImGui.h/.cpp` | 可脚本化 ImGui 操作封装。 |
| `ScriptReporter.h/.cpp` | 自动化脚本报告输出。 |
| `AssetStatusTracker.h/.cpp` | 资产状态跟踪。 |
| `ImageComparisonConfig.h/.cpp` | 图像比较测试配置。 |
| `PrecommitWizardSettings.h` | 预提交向导设置。 |
| `ScriptRunnerBus.h` / `ScriptRepeaterBus.h` | 自动化相关 EBus 接口。 |

## Standalone

| 路径 | 说明 |
| --- | --- |
| `Standalone/CMakeLists.txt` | 独立应用构建入口。 |
| `Standalone/Platform/Common` | 通用独立应用类。 |
| `Standalone/Platform/Windows` | Windows 启动入口和平台实现。 |
| `Standalone/Platform/Linux` | Linux 启动入口和平台实现。 |
| `Standalone/Platform/Mac` | Mac 平台实现。 |
| `Standalone/Platform/iOS` | iOS 平台实现。 |
| `Standalone/Platform/Android` | Android 平台实现。 |
| `Standalone/PythonTests` | Python 自动化测试，包括主测试和周期性能基准。 |

## 资源目录补充

| 路径 | 说明 |
| --- | --- |
| `Passes` | 渲染管线、Pass 模板和示例 Pass 配置。 |
| `Materials` | 示例材质，包括 `MinimalPBR`、`Decal`、`DynamicMaterialTest`、`DiffuseGIExample`、`SSRExample`、`XR` 等子目录。 |
| `Shaders` | 示例 shader 源文件。 |
| `ShaderLib` | 共享 shader include 和 shader 库。 |
| `Objects` | 示例模型和 LOD 测试模型。 |
| `Textures` | 示例纹理、流式纹理、HDR 测试图等。 |
| `Registry` | 材质管线、OpenXR、AssetProcessor、Editor 偏好等 setreg 配置。 |
| `Config` | 项目配置。 |

