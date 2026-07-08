/*
 * Copyright (c) Contributors to the Open 3D Engine Project.
 * For complete copyright and license terms please see the LICENSE at the root of this distribution.
 *
 * SPDX-License-Identifier: Apache-2.0 OR MIT
 *
 */

#pragma once

#include <AzCore/Component/Component.h>

namespace AtomSampleViewer
{
    class AtomSampleComponent
        : public AZ::Component
    {
    public:
        AZ_RTTI(AtomSampleComponent, "{2318DFD6-BC6B-4335-9F25-8E270A10CA81}", AZ::Component);

        AtomSampleComponent() = default;
        ~AtomSampleComponent() override = default;

        // 在示例组件子类中重新定义此字符串，以提供特定于示例的警告消息。
        // 任何非空字符串都会在打开示例之前自动显示警告消息。
        static constexpr const char* ContentWarning = "";

        // 如果上述 ContentWarning 被重写并赋予非空值，则此字符串将用作消息框的标题。
        // 在示例组件子类中重新定义此字符串以提供自定义标题。
        static constexpr const char* ContentWarningTitle = "Content Warning";
        
        // 这是常见的photosensitive/seizure警告，可以根据需要在特定示例中用于上述 ContentWarning。
        static constexpr const char CommonPhotosensitiveWarning[] = "This sample includes flashing images that could cause seizures or other adverse effects in photosensitive individuals.";
        static constexpr const char CommonPhotosensitiveWarningTitle[] = "Photosensitive Seizure Warning";
    };
} // namespace AtomSampleViewer
