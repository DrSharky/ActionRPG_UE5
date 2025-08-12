// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class VampRPGEditorTarget : TargetRules
{
	public VampRPGEditorTarget(TargetInfo Target)
		: base(Target)
	{
		Type = TargetType.Editor;
		ExtraModuleNames.AddRange(new string[] { "VampRPG" });

		DefaultBuildSettings = BuildSettingsVersion.V5;
	}
}
