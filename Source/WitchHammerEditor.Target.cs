// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class WitchHammerEditorTarget : TargetRules
{
	public WitchHammerEditorTarget(TargetInfo target) : base(target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V5;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_3;
		ExtraModuleNames.Add("WitchHammer");
		bUseUnityBuild = true;
	}
}
