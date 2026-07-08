/*
 * Copyright (c) Contributors to the Open 3D Engine Project.
 * For complete copyright and license terms please see the LICENSE at the root of this distribution.
 *
 * SPDX-License-Identifier: Apache-2.0 OR MIT
 *
 */

#pragma once

#include <Atom/RPI.Reflect/Material/MaterialAsset.h>
#include <Atom/RPI.Reflect/Model/ModelAsset.h>
#include <AzCore/Component/TickBus.h>
#include <AzFramework/Asset/AssetSystemTypes.h>
#include <CommonSampleComponentBase.h>
#include <Utils/ImGuiSidebar.h>
#include <Utils/ImGuiAssetBrowser.h>
#include <Utils/ImGuiHistogramQueue.h>
#include <Atom/Utils/ImGuiMaterialDetails.h>

namespace AtomSampleViewer
{
    //! 此测试旨在收集着色器变体系统的指标，允许用户从使用根着色器变体切换到优化变体。
    //! 要生成着色器变体，请使用着色器管理控制台。
    //! 可以使用侧边栏中的“材质详情”按钮来验证材质使用的着色器选项。
    //! 侧边栏还会显示帧率 (FPS) 和根通道指标。要查看特定通道的指标，请使用 GPU 分析器。
    class BakedShaderVariantExampleComponent final
        : public CommonSampleComponentBase
        , public AZ::TickBus::Handler
        , public AZ::Data::AssetBus::Handler
    {
    public:
        AZ_COMPONENT(BakedShaderVariantExampleComponent, "{4986DD5D-347E-4E11-BBD5-E364061666A1}", CommonSampleComponentBase);
        BakedShaderVariantExampleComponent();

        static void Reflect(AZ::ReflectContext* context);

        // AZ::Component overrides...
        void Activate() override;
        void Deactivate() override;

    private:
        AZ_DISABLE_COPY_MOVE(BakedShaderVariantExampleComponent);

        // AZ::TickBus::Handler overrides...
        void OnTick(float deltaTime, AZ::ScriptTimePoint scriptTime) override;

        void MaterialChange();
        void SetRootVariantUsage(bool enabled);

        static constexpr uint32_t FrameTimeLogSize = 50;
        static constexpr uint32_t PassTimeLogSize = 50;
        ImGuiSidebar m_imguiSidebar;
        AZ::Render::ImGuiMaterialDetails m_imguiMaterialDetails;
        ImGuiAssetBrowser m_materialBrowser;
        ImGuiHistogramQueue m_imGuiFrameTimer;
        ImGuiHistogramQueue m_imGuiForwardPassTimer;

        AZ::Render::MeshFeatureProcessorInterface* m_meshFeatureProcessor = nullptr;

        AZ::Data::Asset<AZ::RPI::MaterialAsset> m_materialAsset;
        AZ::Data::Instance<AZ::RPI::Material> m_material;
        AZ::Data::Asset<AZ::RPI::ModelAsset> m_modelAsset;
        AZ::Render::MeshFeatureProcessorInterface::MeshHandle m_meshHandle;

        AZ::RHI::Ptr<AZ::RPI::Pass> m_forwardPass;

        size_t m_selectedShaderIndex = 0;
    };
} // namespace AtomSampleViewer
