#### [AreaLightExampleComponent](Gem\Code\Source\AreaLightExampleComponent.h)
    此组件使用棋盘渲染管线渲染具有 pbr 材质的模型。

#### [BakedShaderVariantExampleComponent](Gem\Code\Source\BakedShaderVariantExampleComponent.h)
    此测试旨在收集着色器变体系统的指标，允许用户从使用根着色器变体切换到优化变体。
    要生成着色器变体，请使用着色器管理控制台。
    可以使用侧边栏中的“材质详情”按钮来验证材质使用的着色器选项。
    侧边栏还会显示帧率 (FPS) 和根通道指标。要查看特定通道的指标，请使用 GPU 分析器。

#### [BloomExampleComponent](Gem\Code\Source\BloomExampleComponent.h)
    该组件重用了色调映射示例的场景来演示光晕功能。

#### [CheckerboardExampleComponent](Gem\Code\Source\CheckerboardExampleComponent.h)
    该组件重用了色调映射示例的场景来演示光晕功能。

#### [CheckerboardExampleComponent](Gem\Code\Source\CheckerboardExampleComponent.h)
    该组件重用了色调映射示例的场景来演示光晕功能

#### [CommonSampleComponentBase](Gem\Code\Source\CommonSampleComponentBase.h)
    一些场景操作的通用功能

#### [CullingAndLodExampleComponent](Gem\Code\Source\CullingAndLodExampleComponent.h)
    剔除和 LOD 示例组件

#### [DecalExampleComponent](Gem\Code\Source\DecalExampleComponent.h)
    该组件创建了一个简单的场景来测试 Atom 的贴花系统

#### [DepthOfFieldExampleComponent](Gem\Code\Source\DepthOfFieldExampleComponent.h)
    该组件创建一个简单的景深场景

#### [DiffuseGIExampleComponent](Gem\Code\Source\DiffuseGIExampleComponent.h)
    该示例演示了使用 DiffuseProbeGrid 的漫反射全局光照。

#### [DynamicDrawExampleComponent](Gem\Code\Source\DynamicDrawExampleComponent.h)
    提供了一个使用 DynamicDrawInterface 和 DynamicDrawContext 的基本示例。

#### [DynamicMaterialTestComponent](Gem\Code\Source\DynamicMaterialTestComponent.h)
    此测试加载一个可配置的实体网格，为每个实体赋予一个唯一的材质实例，并在每一帧更改材质属性值。
    测试中包含用于配置网格大小的用户界面。

#### [DynamicMaterialTestComponent](Gem\Code\Source\DynamicMaterialTestComponent.h)
    此测试加载一个可配置的实体网格，为每个实体赋予一个唯一的材质实例，并在每一帧更改材质属性值。
    测试中包含用于配置网格大小的用户界面。

#### [ExposureExampleComponent](Gem\Code\Source\ExposureExampleComponent.h)
    该组件创建了一个简单的场景来演示曝光功能。

#### [EyeMaterialExampleComponent](Gem\Code\Source\EyeMaterialExampleComponent.h)
    该示例演示了如何设置和操作具有次表面散射的眼睛材料。

#### [LightCullingExampleComponent](Gem\Code\Source\LightCullingExampleComponent.h)
    该组件创建了一个简单的场景，用于测试包含多个灯光和贴花的灯光剔除功能。

#### [MeshExampleComponent](Gem\Code\Source\MeshExampleComponent.h)
    此示例组件演示了如何加载和显示具有不同材质的 3D 模型。

#### [MSAA_RPI_ExampleComponent](Gem\Code\Source\MSAA_RPI_ExampleComponent.h)
    此组件创建一个简单的场景来测试 MSAA 管线。它可以在同一个场景中测试启用和禁用 MSAA 的情况。
    MSAA 多重采样抗锯齿

#### [MultiGPURPIExampleComponent](Gem\Code\Source\MultiGPURPIExampleComponent.h)
    多GPU

#### [MultiRenderPipelineExampleComponent](Gem\Code\Source\MultiRenderPipelineExampleComponent.h)
    多渲染管线，
    一个示例组件，它使用不同的渲染管线在不同的窗口中渲染同一场景。
    它有一个 imgui 菜单，用于打开/关闭第二个渲染管线以及打开/关闭不同的图形功能。
    还有一个选项可以让第二个渲染管线使用第二个摄像机。

#### [SecondWindowedScene](Gem\Code\Source\MultiSceneExampleComponent.h)
    多场景，
    这个类会创建一个第二个窗口场景。

#### [MultiViewSingleSceneAuxGeomExampleComponent](Gem\Code\Source\MultiViewSingleSceneAuxGeomExampleComponent.h)
    多视图单场景辅助几何示例组件。

#### [ParallaxMappingExampleComponent](Gem\Code\Source\ParallaxMappingExampleComponent.h)
    此组件演示视差映射和像素深度偏移的效果

#### [ProceduralSkinnedMesh](Gem\Code\Source\ProceduralSkinnedMesh.h)
    用于创建具有任意骨骼/顶点数量的蒙皮网格输入缓冲区的类。假定采用 z 轴向上的右手坐标系。
    该网格是由多个部分组成的垂直圆柱体，骨骼沿圆柱体的高度均匀分布。

#### [ProceduralSkinnedMesh](Gem\Code\Source\ProceduralSkinnedMesh.h)
    用于创建具有任意骨骼/顶点数量的蒙皮网格输入缓冲区的类。假定采用 z 轴向上的右手坐标系。
    该网格是由多个部分组成的垂直圆柱体，骨骼沿圆柱体的高度均匀分布。

#### [RayTracingIntersectionShaderExampleComponent](Gem\Code\Source\RayTracingIntersectionShaderExampleComponent.h)
    此测试通过生成以下场景来检查程序几何体的光线追踪相交着色器的功能：
    - 一个带有镜面材质的水平面
    - 若干个球体和立方体（来自 DebugDraw gem），并启用了光线追踪设置
    - 一个带有“光线追踪”反射方法的 SpecularReflections 组件

    DebugDraw gem 为球体和立方体提供了相交着色器，并将它们添加到光线追踪场景中。
    因此，这些形状在镜面平面上会显示为光线追踪反射。


#### [ReadbackExampleComponent](Gem\Code\Source\ReadbackExampleComponent.h)
    --- 回读测试 ---
    
    此测试旨在测试 ATOM 的回读功能。
    它由两个协同工作的自定义流程组成。
    第一个流程生成纹理并填充图案。
    然后，它利用 RPI::Pass 的回读功能（ReadbackAttachment）将结果读回主机内存。
    读回后，结果将上传到设备内存，作为第二个流程的纹理输入，用于显示结果以供操作员验证。

#### [RenderTargetTextureExampleComponent](Gem\Code\Source\RenderTargetTextureExampleComponent.h)
    此示例演示如何将渲染目标用作网格材质的纹理。
    它执行以下操作：
    1. 在运行时创建一个包含一个渲染目标的栅格通道
    2. 将渲染目标用作标准 PBR 材质的纹理输入
    3. 使用 IBL 照明将此材质的网格渲染到场景中。

#### [RootConstantsExampleComponent](Gem\Code\Source\RootConstantsExampleComponent.h)
    此示例演示了根常量的用法。
    它使用根常量来更新对象的矩阵和材质数组的索引。
    在此示例中，“材质”只是一个带有颜色的简单结构。
    初始化后不会进行 SRG 更新。
    Root Constants = 直接把一小段常量数据“塞进”GPU 命令里，不走 Buffer / SRG 绑定，延迟和开销最低。

#### [SceneReloadSoakTestComponent](Gem\Code\Source\SceneReloadSoakTestComponent.h)
    此测试会以不同的时间间隔反复加载和卸载一组模型和材质，其具体目的是暴露渲染器和资源系统中的竞争条件。
    某些时间间隔故意设置得过短，以便资源和实例在完全加载、初始化并发送到 GPU 之前就被关闭和释放。

#### [ShaderReloadTestComponent](Gem\Code\Source\ShaderReloadTestComponent.h)
    此示例组件会根据用户或脚本输入更新用于渲染 FullscreenTrianglePass 的着色器，目的是验证着色器重新加载通知事件是否正常工作。

#### [ShadowedSponzaExampleComponent](Gem\Code\Source\ShadowedSponzaExampleComponent.h)
    该组件创建了一个带有阴影效果的 Sponza 场景。

#### [ShadowExampleComponent](Gem\Code\Source\ShadowExampleComponent.h)
    此组件创建了一个简单的场景来测试阴影。
    在第二步中，为平行光实现了级联阴影贴图。
    在第三步中，使级联层数可配置。
    在第四步中，使用 PCF（百分比接近滤波）实现了阴影边缘柔化。
    在第五步中，使用 ESM（指数阴影贴图）实现了阴影边缘柔化。
    在第六步中，实现了圆盘光阴影。

#### [SkinnedMeshContainer](Gem\Code\Source\SkinnedMeshContainer.h)
    AtomSampleViewer 示例使用的辅助类。
    存储蒙皮网格列表，并在容器销毁时自动释放这些网格。
    蒙皮网格输入缓冲区使用 ProceduralSkinnedMesh 类生成，因此您可以轻松创建任意数量、任意复杂度（例如顶点数和骨骼数）的蒙皮网格。
    目前支持每个蒙皮网格 1 个 LOD，每个 LOD 1 个子网格，以及每个顶点 1-4 个影响。
    目前支持蒙皮网格输入与蒙皮网格实例的一对一映射。

#### [SkinnedMeshExampleComponent](Gem\Code\Source\SkinnedMeshExampleComponent.h)
    该组件创建了一个简单的场景来测试 Atom 的 SkinnedMesh 系统。

#### [SponzaBenchmarkComponent](Gem\Code\Source\SponzaBenchmarkComponent.h)
    该组件对 Sponza 场景运行加载和运行时基准测试。

#### [SsaoExampleComponent](Gem\Code\Source\SsaoExampleComponent.h)
    该组件创建了一个简单的场景，用于测试深度信息的原始 SSAO 输出。
    SSAO 是 Screen Space Ambient Occlusion 的缩写，中文一般叫屏幕空间环境光遮蔽

#### [SSRExampleComponent](Gem\Code\Source\SSRExampleComponent.h)
    该组件创建一个简单的场景来测试屏幕空间反射。

#### [StreamingImageExampleComponent](Gem\Code\Source\StreamingImageExampleComponent.h)

    - 此 AtomSampleViewer 示例用于测试、分析和可视化 StreamingImage 流式传输过程，以及测试 StreamingImage 的热重载功能。
    - 它首先加载 36 个 StreamingImageAssets，并在每个资源准备就绪后创建相应的 StreamingImage。
    - StreamingImage 创建完成后，将使用其所有 mipmap 将其绘制到屏幕上。
    - 未加载的 mipmap 将显示为白色方块。
    - 当所有 StreamingImage 的 mipmap 都加载完毕后，屏幕上将显示性能分析结果。
    - 为了测试 StreamingImage 的热重载，此示例将在 AtomSampleViewer 项目资源的 texture/streaming/ 文件夹中添加一个新的图像文件。
    - 该文件将被加载并显示在屏幕右上角。
    - 其下方有一个切换按钮，用于将当前图像覆盖为另一个图像。
    - 当 AP 处理更改后的图像后，新的内容将渲染到屏幕上。

#### [Subpass_RPI_ExampleComponent](Gem\Code\Source\Subpass_RPI_ExampleComponent.h)
    此示例演示如何在 RPI 级别使用子通道。
    有两个渲染管线，预期输出相同，但它们实现相同结果的方式不同。
    第一条（默认）管线由两个子通道组成：前向渲染和天空盒渲染。
    第二条管线由两个通道组成：前向渲染和天空盒渲染。
    用户可以使用“1”或“2”键在两条管线之间切换。

#### [TonemappingExampleComponent](Gem\Code\Source\TonemappingExampleComponent.h)
    此组件创建一个简单的场景，通过显示全屏图像来演示色调映射功能。
    DisplayMapper 通道的输出也可以捕获为图像。

#### [TransparencyExampleComponent](Gem\Code\Source\TransparencyExampleComponent.h)
    透明度对象的深度排序测试

#### [XRRPIExampleComponent](Gem\Code\Source\XRRPIExampleComponent.cpp)
    此组件创建一个简单的场景，使用特殊的多视图 VR 管线测试 VR。我们设置了两条管线，每只眼睛一条，并且此管线使用立体视图。
    此示例支持使用 Quest 2 控制器在场景中飞行。它还支持使用按钮按下来实现场景中的特定功能。每个控制器的示意图如下：
    左侧控制器
        摇杆 - 相机移动，X 按钮 - 相机上移（视图空间 Y 轴），Y 按钮 - 相机下移（视图空间 Y 轴），捏合 - 缩放控制器模型
    右侧控制器
        摇杆 - 如果按下扳机按钮，则调整视图方向；否则，将使用设备进行视图跟踪
    B 按钮 - 遍历光照预设，B 按钮 - 遍历地面材质，捏合 - 缩放控制器模型

#### [CheckerboardExampleComponent](Gem\Code\Source\CheckerboardExampleComponent.h)
    该组件使用棋盘渲染管线渲染具有 PBR 材质的模型。