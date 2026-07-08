/*
 * Copyright (c) Contributors to the Open 3D Engine Project.
 * For complete copyright and license terms please see the LICENSE at the root of this distribution.
 *
 * SPDX-License-Identifier: Apache-2.0 OR MIT
 *
 */

#pragma once

#include <AzCore/Component/Component.h>
#include <CommonSampleComponentBase.h>
#include <Utils/Utils.h>

namespace AtomSampleViewer
{
    //! This test checks the functionality of ray tracing intersection shaders for procedural geometry by generating the following scene:
    //!  - A horizontal plane with mirror material
    //!  - A number of sphere and box shapes (from the DebugDraw gem) with enabled ray tracing setting
    //!  - A SpecularReflections level component with "Ray tracing" reflection method
    //! The DebugDraw gem supplies the intersection shaders for the sphere and box shapes and adds them to the ray tracing scene. The shapes
    //! are therefore visible as ray-traced reflections in the mirror plane.
    
    //! 此测试通过生成以下场景来检查程序几何体的光线追踪相交着色器的功能：
    //! - 一个带有镜面材质的水平面
    //! - 若干个球体和立方体（来自 DebugDraw gem），并启用了光线追踪设置
    //! - 一个带有“光线追踪”反射方法的 SpecularReflections 组件
    //! DebugDraw gem 为球体和立方体提供了相交着色器，并将它们添加到光线追踪场景中。
    //! 因此，这些形状在镜面平面上会显示为光线追踪反射。
    class RayTracingIntersectionShaderExampleComponent final : public CommonSampleComponentBase
    {
    public:
        AZ_COMPONENT(RayTracingIntersectionShaderExampleComponent, "{e231a794-4d77-4754-b2bd-c102e1fe51db}", AZ::Component);
        AZ_DISABLE_COPY_MOVE(RayTracingIntersectionShaderExampleComponent);

        static void Reflect(AZ::ReflectContext* context);

        RayTracingIntersectionShaderExampleComponent() = default;

    protected:
        // AZ::Component overrides
        void Activate() override;
        void Deactivate() override;

    private:
        AZ::Data::Asset<AZ::RPI::ModelAsset> m_mirrorplaneModelAsset;
        AZ::Data::Asset<AZ::RPI::MaterialAsset> m_mirrorMaterialAsset;
        AZ::Data::Instance<AZ::RPI::Material> m_mirrorMaterialInstance;
        AZ::Render::MeshFeatureProcessorInterface::MeshHandle m_mirrorplaneMeshHandle;
        Utils::DefaultIBL m_defaultIbl;
        AZStd::vector<AZ::Entity*> m_entities;
    };
} // namespace AtomSampleViewer
