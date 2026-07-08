/*
 * Copyright (c) Contributors to the Open 3D Engine Project.
 * For complete copyright and license terms please see the LICENSE at the root of this distribution.
 *
 * SPDX-License-Identifier: Apache-2.0 OR MIT
 *
 */

#pragma once

#include <EntityLatticeTestComponent.h>
#include <Utils/ImGuiSidebar.h>
#include <Utils/ImGuiAssetBrowser.h>
#include <AzCore/Component/TickBus.h>

namespace AtomSampleViewer
{
    /*
        此测试加载一个可配置的实体网格，并在给定的时间步长内替换每个实体的模型和材质。每个实体的资源都可以快速替换（十分之一秒）。

        应用于实体的资源选自一个可配置的模型和材质“允许列表”。
        允许列表保存在缓存的用户文件夹中，并在启动时加载。
        这使得在测试中可以轻松选择“可用”的资源，而不是可能存在问题的开发资源。
        此外，它还允许您构建一些需要测试实例化而非加载的用例。
        用于修改允许列表的用户界面是此组件的核心部分。
    */
    class AssetLoadTestComponent final
        : public EntityLatticeTestComponent
        , public AZ::TickBus::Handler
    {
        using Base = EntityLatticeTestComponent;

    public:
        AZ_COMPONENT(AssetLoadTestComponent, "{30E6EE46-2CD5-4903-801F-56AE70A33656}", EntityLatticeTestComponent);

        static void Reflect(AZ::ReflectContext* context);

        AssetLoadTestComponent();
        
        //! AZ::Component overrides...
        void Activate() override;
        void Deactivate() override;

    private:
        AZ_DISABLE_COPY_MOVE(AssetLoadTestComponent);

        // CommonSampleComponentBase overrides...
        void OnAllAssetsReadyActivate() override;

        //! EntityLatticeTestComponent overrides...
        void PrepareCreateLatticeInstances(uint32_t instanceCount) override;
        void CreateLatticeInstance(const AZ::Transform& transform) override;
        void FinalizeLatticeInstances() override;
        void DestroyLatticeInstances() override;

        void DestroyHandles();

        AZ::Data::AssetId GetRandomModelId() const;
        AZ::Data::AssetId GetRandomMaterialId() const;

        void OnTick(float deltaTime, AZ::ScriptTimePoint scriptTime) override;

        struct ModelInstanceData
        {
            AZ::Transform m_transform;
            AZ::Data::AssetId m_modelAssetId;
            AZ::Data::AssetId m_materialAssetId;
            AZ::Render::MeshFeatureProcessorInterface::MeshHandle m_meshHandle;
        };

        ImGuiSidebar m_imguiSidebar;
        ImGuiAssetBrowser m_materialBrowser;
        ImGuiAssetBrowser m_modelBrowser;
        
        AZStd::vector<ModelInstanceData> m_modelInstanceData;

        struct Compare
        {
            bool operator()(const AZ::Data::Asset<AZ::RPI::MaterialAsset>& lhs, const AZ::Data::Asset<AZ::RPI::MaterialAsset>& rhs) const
            {
                if (lhs.GetId().m_guid == rhs.GetId().m_guid)
                {
                    return lhs.GetId().m_subId > rhs.GetId().m_subId;
                }
                return lhs.GetId().m_guid > rhs.GetId().m_guid;
            }
        };

        using MaterialAssetSet = AZStd::set<AZ::Data::Asset<AZ::RPI::MaterialAsset>, Compare>;
        MaterialAssetSet m_cachedMaterials;
        uint32_t m_pinnedMaterialCount = 0;
        
        size_t m_lastPinnedModelCount = 0;
        float m_lastMaterialSwitchInSeconds = 0;
        float m_lastModelSwitchInSeconds = 0;
        float m_materialSwitchTimeInSeconds = 5.0f;
        float m_modelSwitchTimeInSeconds = 3.0f;
        bool m_materialSwitchEnabled = true;
        bool m_modelSwitchEnabled = true;
        bool m_updateTransformEnabled = false;
    };
} // namespace AtomSampleViewer
