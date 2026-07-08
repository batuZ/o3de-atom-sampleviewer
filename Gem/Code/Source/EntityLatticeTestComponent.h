/*
 * Copyright (c) Contributors to the Open 3D Engine Project.
 * For complete copyright and license terms please see the LICENSE at the root of this distribution.
 *
 * SPDX-License-Identifier: Apache-2.0 OR MIT
 *
 */

#pragma once

#include <CommonSampleComponentBase.h>
#include <Utils/Utils.h>
#include <EntityLatticeTestComponent_Traits_Platform.h>

#include <AzCore/Math/Aabb.h>

struct ImGuiContext;

namespace AtomSampleViewer
{
    //! 用于显示实体格的测试组件的通用基类。
    class EntityLatticeTestComponent
        : public CommonSampleComponentBase
    {
    public:
        AZ_RTTI(EntityLatticeTestComponent, "{73C13F66-6F5B-43D3-B1F0-CB4F7BEA1334}", CommonSampleComponentBase)

        static void Reflect(AZ::ReflectContext* context);

        // AZ::Component overrides...
        void Activate() override;
        void Deactivate() override;

    protected:

        //! 返回实例总数（宽度 * 高度 * 深度）
        uint32_t GetInstanceCount() const;
        
        //! 返回晶格的世界空间 Aabb。
        //! 返回的 Aabb 包含所有实体晶格位置。它不包含每个位置的网格 Aabb。
        AZ::Aabb GetLatticeAabb() const;

        //! 调用此函数来渲染 ImGui 控件，以控制晶格的大小。
        void RenderImGuiLatticeControls();
        
        //! 破坏并重建格子。
        virtual void RebuildLattice();
        
        void SetLatticeMaxDimension(uint32_t max);
        void SetLatticeDimensions(uint32_t width, uint32_t depth, uint32_t height);
        void SetLatticeSpacing(float spaceX, float spaceY, float spaceZ);
        void SetLatticeEntityScale(float scale);

        void SetIBLExposure(float exposure);

    private:

        //! 在为每个实例调用 CreateLatticeInstance() 之前调用一次，以便子类可以为实例总数做好准备。
        virtual void PrepareCreateLatticeInstances(uint32_t instanceCount) = 0;

        //! 当构建晶格时，会对晶格中的每个实体调用此方法。子类应附加实现所需结果所需的任何组件。
        virtual void CreateLatticeInstance(const AZ::Transform& transform) = 0;

        //! This is called after all the instances are created to any final work. Not required.
        virtual void FinalizeLatticeInstances() {};

        //! Called when the subclass should destroy all of its instances, either because of shutdown or recreation.
        virtual void DestroyLatticeInstances() = 0;

        void BuildLattice();

    protected:
        //! Contains the world space Aabb of the lattice positions. Doesn't include the mesh Aabb at each position.
        AZ::Aabb m_worldAabb;

    private:
        // These are signed to avoid casting with imgui controls.
        int32_t m_latticeWidth = ENTITY_LATTICE_TEST_COMPONENT_WIDTH;
        int32_t m_latticeHeight = ENTITY_LATTICE_TEST_COMPONENT_HEIGHT;
        int32_t m_latticeDepth = ENTITY_LATTICE_TEST_COMPONENT_DEPTH;
        int32_t m_latticeSizeMax = ENTITY_LATTEST_TEST_COMPONENT_MAX;

        float m_spacingX = 5.0f;
        float m_spacingY = 5.0f;
        float m_spacingZ = 5.0f;

        float m_entityScale = 1.0f;
        
        Utils::DefaultIBL m_defaultIbl;
    };
} // namespace AtomSampleViewer
